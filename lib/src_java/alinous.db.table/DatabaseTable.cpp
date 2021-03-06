#include "include/global.h"


#include "alinous.compile.sql.analyze/ScanTableColumnIdentifier.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.db/AlinousDbException.h"
#include "alinous.lock/LockObject.h"
#include "alinous.lock/ConcurrentGate.h"
#include "alinous.buffer.storage/IFileStorage.h"
#include "alinous.buffer.storage/FileStorage.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.btree/BTreeGlobalCache.h"
#include "alinous.db.table/DatabaseException.h"
#include "alinous.db.table.lockmonitor/DatabaseLockException.h"
#include "alinous.db.table.lockmonitor/IThreadLocker.h"
#include "alinous.btree/IBTree.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.db.table/TableColumnMetadata.h"
#include "alinous.db.table/TableMetadata.h"
#include "alinous.runtime.parallel/ThreadPool.h"
#include "alinous.system/ISystemLog.h"
#include "alinous.system/AlinousCore.h"
#include "alinous.db.trx/DbTransaction.h"
#include "alinous.remote.region.client.command/AbstractNodeRegionCommand.h"
#include "alinous.runtime.parallel/IThreadAction.h"
#include "alinous.runtime.parallel/SequentialBackgroundJob.h"
#include "java.lang/Number.h"
#include "java.lang/Comparable.h"
#include "java.lang/Integer.h"
#include "alinous.btree/BTree.h"
#include "alinous.db.table/IScannableIndex.h"
#include "alinous.db.table/IDatabaseTable.h"
#include "alinous.db.table/DatabaseRecord.h"
#include "alinous.numeric/InternalDate.h"
#include "java.sql/Timestamp.h"
#include "alinous.db.table/DatabaseTableIdPublisher.h"
#include "alinous.db.table/IBtreeTableIndex.h"
#include "alinous.db.table/TableIndex.h"
#include "alinous.db.table/DatatableConstants.h"
#include "alinous.db.table/DatatableUpdateCache.h"
#include "alinous.db.table/AbstractDatabaseTable.h"
#include "alinous.db.table/DataTableStorageSupport.h"
#include "alinous.db.table/DatatableLockSupport.h"
#include "alinous.db.table/DatatableDDLSupport.h"
#include "alinous.db.table/DatatableUpdateSupport.h"
#include "alinous.db.table.cache/RecordCacheEngine.h"
#include "alinous.db.table.lockmonitor/DBThreadMonitor.h"
#include "alinous.db.table/DatabaseTable.h"

namespace alinous {namespace db {namespace table {





bool DatabaseTable::__init_done = __init_static_variables();
bool DatabaseTable::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DatabaseTable", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 DatabaseTable::DatabaseTable(String* schema, String* name, String* baseDir, ThreadPool* threadPool, ThreadContext* ctx) : IObject(ctx), DatatableUpdateSupport(schema, name, baseDir, ctx), monitor(nullptr)
{
	__GC_MV(this, &(this->cacheEngine), (new(ctx) RecordCacheEngine(ctx))->init(1024, ctx), RecordCacheEngine);
	__GC_MV(this, &(this->monitor), (new(ctx) DBThreadMonitor(threadPool, ctx)), DBThreadMonitor);
}
void DatabaseTable::__construct_impl(String* schema, String* name, String* baseDir, ThreadPool* threadPool, ThreadContext* ctx)
{
	__GC_MV(this, &(this->cacheEngine), (new(ctx) RecordCacheEngine(ctx))->init(1024, ctx), RecordCacheEngine);
	__GC_MV(this, &(this->monitor), (new(ctx) DBThreadMonitor(threadPool, ctx)), DBThreadMonitor);
}
 DatabaseTable::~DatabaseTable() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void DatabaseTable::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"DatabaseTable", L"~DatabaseTable");
	__e_obj1.add(this->monitor, this);
	monitor = nullptr;
	if(!prepare){
		return;
	}
	DatatableUpdateSupport::__releaseRegerences(true, ctx);
}
IScannableIndex* DatabaseTable::getTableUniqueIndexByCols(List<TableColumnMetadata>* columns, ThreadContext* ctx) throw() 
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
IScannableIndex* DatabaseTable::getTableIndexByColIds(ArrayList<ScanTableColumnIdentifier>* columns, ThreadContext* ctx) throw() 
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
IScannableIndex* DatabaseTable::getAbailableIndex(ArrayList<String>* columns, ThreadContext* ctx) throw() 
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
IScannableIndex* DatabaseTable::getAbailableIndexByScanColId(ArrayList<ScanTableColumnIdentifier>* columns, ThreadContext* ctx) throw() 
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
IScannableIndex* DatabaseTable::getTableIndex(ArrayList<String>* columns, ThreadContext* ctx) throw() 
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
IThreadLocker* DatabaseTable::newThreadLocker(String* fullName, ThreadContext* ctx) throw() 
{
	return this->monitor->newThread(fullName, ctx);
}
void DatabaseTable::updateLockTable(IThreadLocker* locker, ThreadContext* ctx)
{
	this->monitor->lockTable(this, locker, true, ctx);
}
void DatabaseTable::updateUnlockTable(IThreadLocker* locker, ThreadContext* ctx)
{
	this->monitor->unlockTable(this, locker, ctx);
}
void DatabaseTable::shareLockTable(IThreadLocker* locker, ThreadContext* ctx)
{
	this->monitor->lockTable(this, locker, false, ctx);
}
void DatabaseTable::shareUnlockTable(IThreadLocker* locker, ThreadContext* ctx)
{
	this->monitor->unlockTable(this, locker, ctx);
}
void DatabaseTable::shareLockRow(long long oid, IThreadLocker* locker, ThreadContext* ctx)
{
	this->monitor->lockRow(this, oid, locker, false, ctx);
}
void DatabaseTable::shareUnlockRow(long long oid, IThreadLocker* locker, ThreadContext* ctx)
{
	this->monitor->unlockRow(this, oid, locker, ctx);
}
void DatabaseTable::updateLockRow(long long oid, IThreadLocker* locker, ThreadContext* ctx)
{
	this->monitor->lockRow(this, oid, locker, true, ctx);
}
void DatabaseTable::updateUnlockRow(long long oid, IThreadLocker* locker, ThreadContext* ctx)
{
	this->monitor->unlockRow(this, oid, locker, ctx);
}
void DatabaseTable::finishCommitSession(DbTransaction* trx, long long newCommitId, ThreadContext* ctx)
{
}
AbstractNodeRegionCommand* DatabaseTable::sendCommand(AbstractNodeRegionCommand* cmd, ThreadContext* ctx)
{
	return nullptr;
}
void DatabaseTable::cleanSelectLocks(DbTransaction* trx, long long newCommitId, ThreadContext* ctx)
{
}
bool DatabaseTable::matchUniqueIndexByIdList(ArrayList<TableColumnMetadata>* columnsMetadataList, List<TableColumnMetadata>* columns, ThreadContext* ctx) throw() 
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
bool DatabaseTable::matchIndexByIdList(ArrayList<TableColumnMetadata>* columnsMetadataList, ArrayList<ScanTableColumnIdentifier>* columns, ThreadContext* ctx) throw() 
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
bool DatabaseTable::matchIndexByStrList(ArrayList<TableColumnMetadata>* columnsMetadataList, ArrayList<String>* columns, ThreadContext* ctx) throw() 
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
void DatabaseTable::__cleanUp(ThreadContext* ctx){
}
}}}

