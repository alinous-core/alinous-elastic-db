#include "includes.h"


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
 DatabaseTable::DatabaseTable(RecordCacheEngine* cacheEngine, String* schema, String* name, String* baseDir, DBThreadMonitor* monitor, ThreadContext* ctx) throw()  : IObject(ctx), DatatableUpdateSupport(schema, name, baseDir, ctx), monitor(nullptr)
{
	__GC_MV(this, &(this->cacheEngine), cacheEngine, RecordCacheEngine);
	__GC_MV(this, &(this->monitor), monitor, DBThreadMonitor);
}
void DatabaseTable::__construct_impl(RecordCacheEngine* cacheEngine, String* schema, String* name, String* baseDir, DBThreadMonitor* monitor, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->cacheEngine), cacheEngine, RecordCacheEngine);
	__GC_MV(this, &(this->monitor), monitor, DBThreadMonitor);
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
TableIndex* DatabaseTable::getTableIndexByColIds(ArrayList<ScanTableColumnIdentifier>* columns, ThreadContext* ctx) throw() 
{
	int maxLoop = this->indexes->size(ctx);
	TableIndex* matchedindex = nullptr;
	if(matchIndexByIdList(this->primaryIndex->getColumns(ctx), columns, ctx))
	{
		return this->primaryIndex;
	}
	for(int i = 0; i != maxLoop; ++i)
	{
		TableIndex* index = this->indexes->get(i, ctx);
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
TableIndex* DatabaseTable::getAbailableIndex(ArrayList<String>* columns, ThreadContext* ctx) throw() 
{
	if(this->primaryIndex->isAvailable(columns, ctx))
	{
		return this->primaryIndex;
	}
	int maxLoop = this->indexes->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		TableIndex* index = this->indexes->get(i, ctx);
		if(index->isAvailable(columns, ctx))
		{
			return index;
		}
	}
	return nullptr;
}
TableIndex* DatabaseTable::getAbailableIndexByScanColId(ArrayList<ScanTableColumnIdentifier>* columns, ThreadContext* ctx) throw() 
{
	if(this->primaryIndex->isAvailableByScanId(columns, ctx))
	{
		return this->primaryIndex;
	}
	int maxLoop = this->indexes->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		TableIndex* index = this->indexes->get(i, ctx);
		if(index->isAvailableByScanId(columns, ctx))
		{
			return index;
		}
	}
	return nullptr;
}
TableIndex* DatabaseTable::getTableIndex(ArrayList<String>* columns, ThreadContext* ctx) throw() 
{
	int maxLoop = this->indexes->size(ctx);
	TableIndex* matchedindex = nullptr;
	for(int i = 0; i != maxLoop; ++i)
	{
		TableIndex* index = this->indexes->get(i, ctx);
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
void DatabaseTable::updateLockTable(IDatabaseTable* table, ThreadLocker* locker, ThreadContext* ctx)
{
	this->monitor->lockTable(table, locker, true, ctx);
}
void DatabaseTable::updateUnlockTable(IDatabaseTable* table, ThreadLocker* locker, ThreadContext* ctx)
{
	this->monitor->unlockTable(table, locker, ctx);
}
void DatabaseTable::shareLockTable(IDatabaseTable* table, ThreadLocker* locker, ThreadContext* ctx)
{
	this->monitor->lockTable(table, locker, false, ctx);
}
void DatabaseTable::shareUnlockTable(IDatabaseTable* table, ThreadLocker* locker, ThreadContext* ctx)
{
	this->monitor->unlockTable(table, locker, ctx);
}
void DatabaseTable::shareLockRow(IDatabaseTable* table, long long oid, ThreadLocker* locker, ThreadContext* ctx)
{
	this->monitor->lockRow(table, oid, locker, false, ctx);
}
void DatabaseTable::shareUnlockRow(IDatabaseTable* table, long long oid, ThreadLocker* locker, ThreadContext* ctx)
{
	this->monitor->unlockRow(table, oid, locker, ctx);
}
void DatabaseTable::updateLockRow(IDatabaseTable* table, long long oid, ThreadLocker* locker, ThreadContext* ctx)
{
	this->monitor->lockRow(table, oid, locker, true, ctx);
}
void DatabaseTable::updateUnlockRow(IDatabaseTable* table, long long oid, ThreadLocker* locker, ThreadContext* ctx)
{
	this->monitor->unlockRow(table, oid, locker, ctx);
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
}}}

