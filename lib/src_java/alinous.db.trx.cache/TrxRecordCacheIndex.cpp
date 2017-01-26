#include "includes.h"


namespace alinous {namespace db {namespace trx {namespace cache {





constexpr const int TrxRecordCacheIndex::capacity;
constexpr const int TrxRecordCacheIndex::BLOCK_SIZE;
constexpr const int TrxRecordCacheIndex::maxCache;
bool TrxRecordCacheIndex::__init_done = __init_static_variables();
bool TrxRecordCacheIndex::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"TrxRecordCacheIndex", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 TrxRecordCacheIndex::TrxRecordCacheIndex(String* name, String* baseDir, ArrayList<TableColumnMetadata>* metadata, ThreadContext* ctx) throw()  : IObject(ctx), IBtreeTableIndex(ctx), name(nullptr), baseDir(nullptr), columns(GCUtils<ArrayList<TableColumnMetadata> >::ins(this, (new(ctx) ArrayList<TableColumnMetadata>(ctx)), ctx, __FILEW__, __LINE__, L"")), filePath(nullptr), storage(nullptr)
{
	__GC_MV(this, &(this->name), name, String);
	__GC_MV(this, &(this->baseDir), baseDir, String);
	GCUtils<ArrayList<TableColumnMetadata> >::mv(this, &(this->columns), metadata, ctx);
	setPath(ctx);
}
void TrxRecordCacheIndex::__construct_impl(String* name, String* baseDir, ArrayList<TableColumnMetadata>* metadata, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->name), name, String);
	__GC_MV(this, &(this->baseDir), baseDir, String);
	GCUtils<ArrayList<TableColumnMetadata> >::mv(this, &(this->columns), metadata, ctx);
	setPath(ctx);
}
 TrxRecordCacheIndex::~TrxRecordCacheIndex() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void TrxRecordCacheIndex::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"TrxRecordCacheIndex", L"~TrxRecordCacheIndex");
	__e_obj1.add(this->name, this);
	name = nullptr;
	__e_obj1.add(this->baseDir, this);
	baseDir = nullptr;
	__e_obj1.add(this->columns, this);
	columns = nullptr;
	__e_obj1.add(this->filePath, this);
	filePath = nullptr;
	__e_obj1.add(this->storage, this);
	storage = nullptr;
	if(!prepare){
		return;
	}
}
void TrxRecordCacheIndex::createIndex(ThreadContext* ctx)
{
	__GC_MV(this, &(this->storage), (new(ctx) BTreeOnMemory(4, ctx)), IBTree);
}
void TrxRecordCacheIndex::switchToDisk(AlinousDatabase* database, ThreadContext* ctx)
{
	File* file = (new(ctx) File(this->filePath, ctx));
	if(file->exists(ctx))
	{
		file->_delete(ctx);
	}
	{
		try
		{
			__GC_MV(this, &(this->storage), (new(ctx) BTree(ctx))->init(file, database->getBtreeCache(ctx), database->getCore(ctx)->diskCache, ctx), IBTree);
			this->storage->initTreeStorage(32, IBTreeValue::TYPE_LONG, IBTreeValue::TYPE_LONG, (long long)capacity, (long long)64, ctx);
		}
		catch(IOException* e)
		{
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1680(), e, ctx));
		}
		catch(InterruptedException* e)
		{
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1680(), e, ctx));
		}
		catch(BTreeException* e)
		{
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1680(), e, ctx));
		}
	}
}
bool TrxRecordCacheIndex::isOpened(ThreadContext* ctx) throw() 
{
	return this->storage->isOpened(ctx);
}
void TrxRecordCacheIndex::addIndexValue(IDatabaseRecord* record, long long oid, ThreadContext* ctx)
{
	BTreeIndexKey* indexKey = (new(ctx) BTreeIndexKey(this, record, ctx));
	LongValue* oidValue = (new(ctx) LongValue(oid, ctx));
	this->storage->putKeyValue(indexKey, oidValue, ctx);
}
void TrxRecordCacheIndex::open(AlinousDatabase* database, ThreadContext* ctx)
{
	if(this->storage == nullptr)
	{
		File* file = (new(ctx) File(this->filePath, ctx));
		__GC_MV(this, &(this->storage), (new(ctx) BTree(ctx))->init(file, database->getBtreeCache(ctx), database->getCore(ctx)->diskCache, ctx), IBTree);
	}
	if(!this->storage->isOpened(ctx))
	{
		this->storage->open(ctx);
	}
}
void TrxRecordCacheIndex::close(ThreadContext* ctx)
{
	if(this->storage != nullptr && this->storage->isOpened(ctx))
	{
		this->storage->close(ctx);
	}
}
void TrxRecordCacheIndex::dispose(ThreadContext* ctx) throw() 
{
	{
		try
		{
			close(ctx);
		}
		catch(IOException* e)
		{
		}
		catch(InterruptedException* e)
		{
		}
	}
	File* file = (new(ctx) File(this->filePath, ctx));
	if(file->exists(ctx))
	{
		file->_delete(ctx);
	}
}
ArrayList<TableColumnMetadata>* TrxRecordCacheIndex::getColumns(ThreadContext* ctx) throw() 
{
	return this->columns;
}
IBTree* TrxRecordCacheIndex::getStorage(ThreadContext* ctx) throw() 
{
	return storage;
}
void TrxRecordCacheIndex::setPath(ThreadContext* ctx) throw() 
{
	StringBuilder* buff = (new(ctx) StringBuilder(ctx));
	buff->append(this->baseDir, ctx)->append(name, ctx)->append(ConstStr::getCNST_STR_1681(), ctx);
	__GC_MV(this, &(this->filePath), buff->toString(ctx), String);
}
}}}}

