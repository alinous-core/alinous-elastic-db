#include "includes.h"


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
	__GC_MV(this, &(this->fullName), this->schema->clone(ctx)->append(ConstStr::getCNST_STR_950(), ctx)->append(this->name, ctx), String);
	__GC_MV(this, &(this->regionAccessPool), regionAccessPool, SocketConnectionPool);
}
void DatabaseTableClient::__construct_impl(String* schema, String* name, TableMetadata* metadata, SocketConnectionPool* regionAccessPool, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->tableId), (new(ctx) Integer(DatabaseTableIdPublisher::getId(name, ctx), ctx)), Integer);
	__GC_MV(this, &(this->schema), schema, String);
	__GC_MV(this, &(this->name), name, String);
	__GC_MV(this, &(this->metadata), metadata, TableMetadata);
	__GC_MV(this, &(this->fullName), this->schema->clone(ctx)->append(ConstStr::getCNST_STR_950(), ctx)->append(this->name, ctx), String);
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
void DatabaseTableClient::insertData(CachedRecord* record, long long newCommitId, IArrayObject<SequentialBackgroundJob>* jobs, ISystemLog* logger, ThreadContext* ctx)
{
}
void DatabaseTableClient::updateData(CachedRecord* record, long long newCommitId, IArrayObject<SequentialBackgroundJob>* jobs, ISystemLog* logger, ThreadContext* ctx)
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
}}}}

