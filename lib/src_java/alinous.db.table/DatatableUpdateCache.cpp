#include "includes.h"


namespace alinous {namespace db {namespace table {





bool DatatableUpdateCache::__init_done = __init_static_variables();
bool DatatableUpdateCache::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DatatableUpdateCache", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 DatatableUpdateCache::DatatableUpdateCache(AbstractDatabaseTable* tableStore, ThreadContext* ctx) throw()  : IObject(ctx), store(nullptr), name(nullptr), baseDir(nullptr), oidIndexPath(nullptr)
{
	__GC_MV(this, &(this->baseDir), tableStore->getBaseDir(ctx), String);
	__GC_MV(this, &(this->store), nullptr, IBTree);
	__GC_MV(this, &(this->name), tableStore->getName(ctx), String);
}
void DatatableUpdateCache::__construct_impl(AbstractDatabaseTable* tableStore, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->baseDir), tableStore->getBaseDir(ctx), String);
	__GC_MV(this, &(this->store), nullptr, IBTree);
	__GC_MV(this, &(this->name), tableStore->getName(ctx), String);
}
 DatatableUpdateCache::~DatatableUpdateCache() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void DatatableUpdateCache::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"DatatableUpdateCache", L"~DatatableUpdateCache");
	__e_obj1.add(this->store, this);
	store = nullptr;
	__e_obj1.add(this->name, this);
	name = nullptr;
	__e_obj1.add(this->baseDir, this);
	baseDir = nullptr;
	__e_obj1.add(this->oidIndexPath, this);
	oidIndexPath = nullptr;
	if(!prepare){
		return;
	}
}
void DatatableUpdateCache::execCreateTable(AlinousCore* core, BTreeGlobalCache* cache, ThreadContext* ctx)
{
	getOidIndexName(ctx);
	__GC_MV(this, &(this->store), (new(ctx) BTree(ctx))->init((new(ctx) File(this->oidIndexPath, ctx)), cache, core->diskCache, ctx), IBTree);
	this->store->initTreeStorage(32, IBTreeValue::TYPE_LONG, IBTreeValue::TYPE_LONG, (long long)DatatableConstants::capacity, (long long)64, ctx);
}
void DatatableUpdateCache::open(AlinousCore* core, BTreeGlobalCache* cache, ThreadContext* ctx)
{
	{
		try
		{
			__GC_MV(this, &(this->store), (new(ctx) BTree(ctx))->init((new(ctx) File(getOidIndexName(ctx), ctx)), cache, core->diskCache, ctx), IBTree);
		}
		catch(Throwable* e)
		{
			throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1609(), e, ctx));
		}
	}
}
ITableTargetScanner* DatatableUpdateCache::getScanner(ScanTableIdentifier* tableId, long long commitId, DbTransaction* trx, ThreadContext* ctx)
{
	return (new(ctx) UpdateHistoryBTreeIndexScanner(ctx))->init(tableId, trx, this->store, commitId, ctx);
}
void DatatableUpdateCache::addHistory(DatabaseRecord* oldRecord, ThreadContext* ctx)
{
	LongKey* key = (new(ctx) LongKey(oldRecord->getOid(ctx), ctx));
	this->store->appendKeyValue(key, oldRecord, ctx);
}
void DatatableUpdateCache::close(ThreadContext* ctx) throw() 
{
	if(this->store != nullptr && this->store->isOpened(ctx))
	{
		{
			try
			{
				this->store->close(ctx);
			}
			catch(IOException* e)
			{
				e->printStackTrace(ctx);
			}
			catch(InterruptedException* e)
			{
				e->printStackTrace(ctx);
			}
		}
	}
}
String* DatatableUpdateCache::getOidIndexName(ThreadContext* ctx) throw() 
{
	if(this->oidIndexPath == nullptr)
	{
		StringBuilder* buff = (new(ctx) StringBuilder(ctx));
		buff->append(this->baseDir, ctx);
		if(!this->baseDir->endsWith(ConstStr::getCNST_STR_984(), ctx))
		{
			buff->append(ConstStr::getCNST_STR_984(), ctx);
		}
		buff->append(ConstStr::getCNST_STR_1610(), ctx)->append(this->name, ctx)->append(ConstStr::getCNST_STR_1611(), ctx);
		__GC_MV(this, &(this->oidIndexPath), buff->toString(ctx), String);
	}
	return this->oidIndexPath;
}
}}}

