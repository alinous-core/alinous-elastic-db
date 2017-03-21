#include "include/global.h"


#include "alinous.btree/BTreeException.h"
#include "alinous.btree/BTreeGlobalCache.h"
#include "alinous.compile.sql.analyze/ScanTableColumnIdentifier.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.db/AlinousDbException.h"
#include "alinous.db.table/DatabaseException.h"
#include "java.lang/Number.h"
#include "java.lang/Comparable.h"
#include "java.lang/Integer.h"
#include "alinous.db.table/DatabaseTableIdPublisher.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.db.table.lockmonitor/DatabaseLockException.h"
#include "alinous.db.table.lockmonitor/IThreadLocker.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.db.table/TableColumnMetadata.h"
#include "alinous.db.table/TableMetadata.h"
#include "alinous.runtime.parallel/ThreadPool.h"
#include "alinous.db.trx/DbVersionContext.h"
#include "alinous.remote.region.client.command.data/ClientNetworkRecord.h"
#include "alinous.remote.socket/ISocketConnection.h"
#include "alinous.remote.socket/SocketConnectionPool.h"
#include "alinous.system/ISystemLog.h"
#include "alinous.remote.region.server/NodeRegionServer.h"
#include "alinous.system/AlinousCore.h"
#include "alinous.db.trx/DbTransaction.h"
#include "alinous.runtime.parallel/IThreadAction.h"
#include "alinous.runtime.parallel/SequentialBackgroundJob.h"
#include "alinous.db.table/IScannableIndex.h"
#include "alinous.db.table/IDatabaseTable.h"
#include "alinous.db.table.lockmonitor/ThreadLocker.h"
#include "java.io/FilterOutputStream.h"
#include "java.io/BufferedOutputStream.h"
#include "alinous.remote.region.client.command/AbstractNodeRegionCommand.h"
#include "alinous.remote.region.client.command.dml/ClientInsertDataCommand.h"
#include "alinous.remote.region.client.command.dml/ClientTpcCommitSessionCommand.h"
#include "alinous.remote.region.client/DatabaseTableClient.h"

namespace alinous {namespace remote {namespace region {namespace client {





bool DatabaseTableClient::__init_done = __init_static_variables();
bool DatabaseTableClient::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DatabaseTableClient", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 DatabaseTableClient::DatabaseTableClient(String* schema, String* name, TableMetadata* metadata, SocketConnectionPool* regionAccessPool, ThreadContext* ctx) throw()  : IObject(ctx), IDatabaseTable(ctx), tableId(nullptr), regionAccessPool(nullptr), metadata(nullptr), schema(nullptr), name(nullptr), fullName(nullptr), indexes(GCUtils<ArrayList<IScannableIndex> >::ins(this, (new(ctx) ArrayList<IScannableIndex>(ctx)), ctx, __FILEW__, __LINE__, L"")), primaryIndex(nullptr)
{
	__GC_MV(this, &(this->tableId), (new(ctx) Integer(DatabaseTableIdPublisher::getId(name, ctx), ctx)), Integer);
	__GC_MV(this, &(this->schema), schema, String);
	__GC_MV(this, &(this->name), name, String);
	__GC_MV(this, &(this->metadata), metadata, TableMetadata);
	__GC_MV(this, &(this->fullName), this->schema->clone(ctx)->append(ConstStr::getCNST_STR_953(), ctx)->append(this->name, ctx), String);
	__GC_MV(this, &(this->regionAccessPool), regionAccessPool, SocketConnectionPool);
}
void DatabaseTableClient::__construct_impl(String* schema, String* name, TableMetadata* metadata, SocketConnectionPool* regionAccessPool, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->tableId), (new(ctx) Integer(DatabaseTableIdPublisher::getId(name, ctx), ctx)), Integer);
	__GC_MV(this, &(this->schema), schema, String);
	__GC_MV(this, &(this->name), name, String);
	__GC_MV(this, &(this->metadata), metadata, TableMetadata);
	__GC_MV(this, &(this->fullName), this->schema->clone(ctx)->append(ConstStr::getCNST_STR_953(), ctx)->append(this->name, ctx), String);
	__GC_MV(this, &(this->regionAccessPool), regionAccessPool, SocketConnectionPool);
}
 DatabaseTableClient::~DatabaseTableClient() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void DatabaseTableClient::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"DatabaseTableClient", L"~DatabaseTableClient");
	__e_obj1.add(this->tableId, this);
	tableId = nullptr;
	__e_obj1.add(this->regionAccessPool, this);
	regionAccessPool = nullptr;
	__e_obj1.add(this->metadata, this);
	metadata = nullptr;
	__e_obj1.add(this->schema, this);
	schema = nullptr;
	__e_obj1.add(this->name, this);
	name = nullptr;
	__e_obj1.add(this->fullName, this);
	fullName = nullptr;
	__e_obj1.add(this->indexes, this);
	indexes = nullptr;
	__e_obj1.add(this->primaryIndex, this);
	primaryIndex = nullptr;
	if(!prepare){
		return;
	}
}
void DatabaseTableClient::updateMetadata(TableMetadata* metadata, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->metadata), metadata, TableMetadata);
}
Integer* DatabaseTableClient::getTableId(ThreadContext* ctx) throw() 
{
	return this->tableId;
}
int DatabaseTableClient::getColumnCount(ThreadContext* ctx) throw() 
{
	return this->metadata->getColumnCount(ctx);
}
IScannableIndex* DatabaseTableClient::getTableUniqueIndexByCols(List<TableColumnMetadata>* columns, ThreadContext* ctx) throw() 
{
	int maxLoop = this->indexes->size(ctx);
	IScannableIndex* matchedindex = nullptr;
	if(matchUniqueIndexByIdList(this->primaryIndex->getColumns(ctx), columns, ctx))
	{
		return this->primaryIndex;
	}
	for(int i = 0; i != maxLoop; ++i)
	{
		IScannableIndex* index = this->indexes->get(i, ctx);
		ArrayList<TableColumnMetadata>* columnsMetadataList = index->getColumns(ctx);
		bool match = matchUniqueIndexByIdList(columnsMetadataList, columns, ctx);
		if(columnsMetadataList->size(ctx) == columns->size(ctx) && match)
		{
			return index;
		}
				else 
		{
			if(match)
			{
				matchedindex = index;
			}
		}
	}
	return matchedindex;
}
IScannableIndex* DatabaseTableClient::getTableIndexByColIds(ArrayList<ScanTableColumnIdentifier>* columns, ThreadContext* ctx) throw() 
{
	int maxLoop = this->indexes->size(ctx);
	IScannableIndex* matchedindex = nullptr;
	if(matchIndexByIdList(this->primaryIndex->getColumns(ctx), columns, ctx))
	{
		return this->primaryIndex;
	}
	for(int i = 0; i != maxLoop; ++i)
	{
		IScannableIndex* index = this->indexes->get(i, ctx);
		ArrayList<TableColumnMetadata>* columnsMetadataList = index->getColumns(ctx);
		bool match = matchIndexByIdList(columnsMetadataList, columns, ctx);
		if(columnsMetadataList->size(ctx) == columns->size(ctx) && match)
		{
			return index;
		}
				else 
		{
			if(match)
			{
				matchedindex = index;
			}
		}
	}
	return matchedindex;
}
IScannableIndex* DatabaseTableClient::getPrimaryIndex(ThreadContext* ctx) throw() 
{
	return this->primaryIndex;
}
TableMetadata* DatabaseTableClient::getMetadata(ThreadContext* ctx) throw() 
{
	return this->metadata;
}
IDatabaseRecord* DatabaseTableClient::loadRecord(long long position, ThreadContext* ctx)
{
	return nullptr;
}
IScannableIndex* DatabaseTableClient::getAbailableIndex(ArrayList<String>* columns, ThreadContext* ctx) throw() 
{
	if(this->primaryIndex->isAvailable(columns, ctx))
	{
		return this->primaryIndex;
	}
	int maxLoop = this->indexes->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IScannableIndex* index = this->indexes->get(i, ctx);
		if(index->isAvailable(columns, ctx))
		{
			return index;
		}
	}
	return nullptr;
}
IScannableIndex* DatabaseTableClient::getAbailableIndexByScanColId(ArrayList<ScanTableColumnIdentifier>* columns, ThreadContext* ctx) throw() 
{
	if(this->primaryIndex->isAvailableByScanId(columns, ctx))
	{
		return this->primaryIndex;
	}
	int maxLoop = this->indexes->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IScannableIndex* index = this->indexes->get(i, ctx);
		if(index->isAvailableByScanId(columns, ctx))
		{
			return index;
		}
	}
	return nullptr;
}
IScannableIndex* DatabaseTableClient::getTableIndex(ArrayList<String>* columns, ThreadContext* ctx) throw() 
{
	int maxLoop = this->indexes->size(ctx);
	IScannableIndex* matchedindex = nullptr;
	for(int i = 0; i != maxLoop; ++i)
	{
		IScannableIndex* index = this->indexes->get(i, ctx);
		ArrayList<TableColumnMetadata>* columnsMetadataList = index->getColumns(ctx);
		bool matched = matchIndexByStrList(columnsMetadataList, columns, ctx);
		if(columnsMetadataList->size(ctx) == columns->size(ctx) && matched)
		{
			return index;
		}
				else 
		{
			if(matched)
			{
				matchedindex = index;
			}
		}
	}
	return matchedindex;
}
IThreadLocker* DatabaseTableClient::newThreadLocker(String* fullName, ThreadContext* ctx) throw() 
{
	return (new(ctx) ThreadLocker(fullName, ctx));
}
void DatabaseTableClient::updateUnlockRow(long long oid, IThreadLocker* locker, ThreadContext* ctx)
{
}
void DatabaseTableClient::updateLockRow(long long oid, IThreadLocker* locker, ThreadContext* ctx)
{
}
void DatabaseTableClient::shareUnlockRow(long long oid, IThreadLocker* locker, ThreadContext* ctx)
{
}
void DatabaseTableClient::shareLockRow(long long oid, IThreadLocker* locker, ThreadContext* ctx)
{
}
void DatabaseTableClient::shareUnlockTable(IThreadLocker* locker, ThreadContext* ctx)
{
}
void DatabaseTableClient::shareLockTable(IThreadLocker* locker, ThreadContext* ctx)
{
}
void DatabaseTableClient::updateUnlockTable(IThreadLocker* locker, ThreadContext* ctx)
{
}
void DatabaseTableClient::updateLockTable(IThreadLocker* locker, ThreadContext* ctx)
{
}
bool DatabaseTableClient::hasLaterVersion(long long oid, long long currentId, ThreadContext* ctx)
{
	return false;
}
bool DatabaseTableClient::hasLaterVersionBefore(long long oid, long long maxCommitId, long long currentCommitId, ThreadContext* ctx)
{
	return false;
}
String* DatabaseTableClient::getName(ThreadContext* ctx) throw() 
{
	return this->name;
}
void DatabaseTableClient::open(AlinousCore* core, BTreeGlobalCache* cache, ThreadContext* ctx)
{
}
void DatabaseTableClient::createTable(TableMetadata* metadata, ThreadPool* threadPool, AlinousCore* core, BTreeGlobalCache* cache, ThreadContext* ctx)
{
}
void DatabaseTableClient::lockStorage(ThreadContext* ctx)
{
}
void DatabaseTableClient::unlockStorage(ThreadContext* ctx)
{
}
ArrayList<IScannableIndex>* DatabaseTableClient::getIndexes(ThreadContext* ctx) throw() 
{
	return indexes;
}
void DatabaseTableClient::insertData(DbTransaction* trx, IDatabaseRecord* record, long long newCommitId, IArrayObject<SequentialBackgroundJob>* jobs, ISystemLog* logger, ThreadContext* ctx)
{
}
void DatabaseTableClient::insertData(DbTransaction* trx, List<IDatabaseRecord>* records, long long newCommitId, IArrayObject<SequentialBackgroundJob>* jobs, ISystemLog* logger, ThreadContext* ctx)
{
	ArrayList<IDatabaseRecord>* list = (new(ctx) ArrayList<IDatabaseRecord>(ctx));
	int maxLoop = records->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IDatabaseRecord* rec = records->get(i, ctx);
		list->add(rec, ctx);
		int num = i + 1;
		if(num % 200 == 0)
		{
			doInsertData(trx, records, newCommitId, ctx);
			list->clear(ctx);
		}
	}
	if(!list->isEmpty(ctx))
	{
		doInsertData(trx, list, newCommitId, ctx);
	}
}
void DatabaseTableClient::finishCommitSession(DbTransaction* trx, long long newCommitId, ThreadContext* ctx)
{
	ClientTpcCommitSessionCommand* cmd = (new(ctx) ClientTpcCommitSessionCommand(ctx));
	cmd->setCommitId(newCommitId, ctx);
	DbVersionContext* vctx = trx->getVersionContext(ctx);
	cmd->setTrxId(vctx->getTrxId(ctx), ctx);
	ISocketConnection* con = nullptr;
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			this->regionAccessPool->returnConnection(con, ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			con = this->regionAccessPool->getConnection(ctx);
			AlinousSocket* socket = con->getSocket(ctx);
			cmd->sendCommand(socket, ctx);
		}
		catch(UnknownHostException* e)
		{
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_3595(), e, ctx));
		}
		catch(IOException* e)
		{
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_3595(), e, ctx));
		}
		catch(AlinousException* e)
		{
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_3595(), e, ctx));
		}
	}
}
void DatabaseTableClient::updateData(IDatabaseRecord* record, long long newCommitId, IArrayObject<SequentialBackgroundJob>* jobs, ISystemLog* logger, ThreadContext* ctx)
{
}
void DatabaseTableClient::createIndex(String* getindexName, ArrayList<String>* columns, AlinousCore* core, BTreeGlobalCache* cache, ThreadContext* ctx)
{
}
void DatabaseTableClient::close(ThreadContext* ctx) throw() 
{
}
String* DatabaseTableClient::getFullName(ThreadContext* ctx) throw() 
{
	return this->fullName;
}
bool DatabaseTableClient::matchUniqueIndexByIdList(ArrayList<TableColumnMetadata>* columnsMetadataList, List<TableColumnMetadata>* columns, ThreadContext* ctx) throw() 
{
	int maxLoop = columns->size(ctx);
	if(maxLoop > columnsMetadataList->size(ctx))
	{
		return false;
	}
	for(int i = 0; i != maxLoop; ++i)
	{
		TableColumnMetadata* requiredColumn = columns->get(i, ctx);
		TableColumnMetadata* metadata = columnsMetadataList->get(i, ctx);
		if(!metadata->name->equals(requiredColumn->name, ctx))
		{
			return false;
		}
	}
	return true;
}
bool DatabaseTableClient::matchIndexByIdList(ArrayList<TableColumnMetadata>* columnsMetadataList, ArrayList<ScanTableColumnIdentifier>* columns, ThreadContext* ctx) throw() 
{
	int maxLoop = columns->size(ctx);
	if(maxLoop > columnsMetadataList->size(ctx))
	{
		return false;
	}
	for(int i = 0; i != maxLoop; ++i)
	{
		ScanTableColumnIdentifier* requiredColumn = columns->get(i, ctx);
		TableColumnMetadata* metadata = columnsMetadataList->get(i, ctx);
		if(!metadata->name->equals(requiredColumn->getColumn(ctx), ctx))
		{
			return false;
		}
	}
	return true;
}
bool DatabaseTableClient::matchIndexByStrList(ArrayList<TableColumnMetadata>* columnsMetadataList, ArrayList<String>* columns, ThreadContext* ctx) throw() 
{
	int maxLoop = columns->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		String* requiredColumn = columns->get(i, ctx);
		TableColumnMetadata* metadata = columnsMetadataList->get(i, ctx);
		if(!metadata->name->equals(requiredColumn, ctx))
		{
			return false;
		}
	}
	return true;
}
void DatabaseTableClient::doInsertData(DbTransaction* trx, List<IDatabaseRecord>* records, long long newCommitId, ThreadContext* ctx)
{
	ClientInsertDataCommand* cmd = (new(ctx) ClientInsertDataCommand(ctx));
	cmd->setCommitId(newCommitId, ctx);
	cmd->setTable(this->name, ctx);
	cmd->setSchema(this->schema, ctx);
	cmd->setVctx(trx->getVersionContext(ctx), ctx);
	cmd->setIsolationLevel(trx->getIsolationLevel(ctx), ctx);
	ArrayList<ClientNetworkRecord>* list = cmd->getList(ctx);
	int maxLoop = records->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IDatabaseRecord* rec = records->get(i, ctx);
		ClientNetworkRecord* netRec = 0;
		{
			try
			{
				netRec = (new(ctx) ClientNetworkRecord(rec, ctx));
			}
			catch(VariableException* e)
			{
				throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_3596(), e, ctx));
			}
		}
		list->add(netRec, ctx);
	}
	ISocketConnection* con = nullptr;
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			this->regionAccessPool->returnConnection(con, ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			con = this->regionAccessPool->getConnection(ctx);
			AlinousSocket* socket = con->getSocket(ctx);
			cmd->sendCommand(socket, ctx);
		}
		catch(UnknownHostException* e)
		{
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_3597(), e, ctx));
		}
		catch(IOException* e)
		{
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_3597(), e, ctx));
		}
		catch(AlinousException* e)
		{
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_3597(), e, ctx));
		}
	}
}
void DatabaseTableClient::__cleanUp(ThreadContext* ctx){
}
}}}}

