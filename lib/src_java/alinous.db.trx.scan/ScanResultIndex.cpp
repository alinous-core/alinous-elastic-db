#include "includes.h"


namespace alinous {namespace db {namespace trx {namespace scan {





bool ScanResultIndex::__init_done = __init_static_variables();
bool ScanResultIndex::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ScanResultIndex", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ScanResultIndex::ScanResultIndex(ScanTableMetadata* metadata, ArrayList<ScanTableColumnIdentifier>* columns, String* trxDir, int indexSerial, ThreadContext* ctx) : IObject(ctx), metadata(nullptr), colsOrders(nullptr), columns(nullptr), btree(nullptr), storagePath(nullptr), trxDir(nullptr), indexSerial(0)
{
	__GC_MV(this, &(this->trxDir), trxDir, String);
	__GC_MV(this, &(this->metadata), metadata, ScanTableMetadata);
	GCUtils<ArrayList<ScanTableColumnIdentifier> >::mv(this, &(this->columns), columns, ctx);
	int maxLoop = columns->size(ctx);
	__GC_MV(this, &(this->colsOrders), ArrayAllocatorPrimitive<int>::allocatep(ctx, maxLoop), IArrayObjectPrimitive<int>);
	for(int i = 0; i != maxLoop; ++i)
	{
		ScanTableColumnIdentifier* colId = columns->get(i, ctx);
		this->colsOrders->set(this->metadata->getColumnOrder(colId, ctx),i, ctx);
	}
	__GC_MV(this, &(this->btree), (new(ctx) BTreeOnMemory(4, ctx)), IBTree);
}
void ScanResultIndex::__construct_impl(ScanTableMetadata* metadata, ArrayList<ScanTableColumnIdentifier>* columns, String* trxDir, int indexSerial, ThreadContext* ctx)
{
	__GC_MV(this, &(this->trxDir), trxDir, String);
	__GC_MV(this, &(this->metadata), metadata, ScanTableMetadata);
	GCUtils<ArrayList<ScanTableColumnIdentifier> >::mv(this, &(this->columns), columns, ctx);
	int maxLoop = columns->size(ctx);
	__GC_MV(this, &(this->colsOrders), ArrayAllocatorPrimitive<int>::allocatep(ctx, maxLoop), IArrayObjectPrimitive<int>);
	for(int i = 0; i != maxLoop; ++i)
	{
		ScanTableColumnIdentifier* colId = columns->get(i, ctx);
		this->colsOrders->set(this->metadata->getColumnOrder(colId, ctx),i, ctx);
	}
	__GC_MV(this, &(this->btree), (new(ctx) BTreeOnMemory(4, ctx)), IBTree);
}
 ScanResultIndex::~ScanResultIndex() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ScanResultIndex::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ScanResultIndex", L"~ScanResultIndex");
	__e_obj1.add(this->metadata, this);
	metadata = nullptr;
	__e_obj1.add(this->colsOrders, this);
	colsOrders = nullptr;
	__e_obj1.add(this->columns, this);
	columns = nullptr;
	__e_obj1.add(this->btree, this);
	btree = nullptr;
	__e_obj1.add(this->storagePath, this);
	storagePath = nullptr;
	__e_obj1.add(this->trxDir, this);
	trxDir = nullptr;
	if(!prepare){
		return;
	}
}
void ScanResultIndex::switchToDisk(AlinousDatabase* database, ThreadContext* ctx)
{
	{
		try
		{
			__GC_MV(this, &(this->storagePath), getOidIndexName(ctx), String);
			File* file = (new(ctx) File(this->storagePath, ctx));
			if(file->exists(ctx))
			{
				file->_delete(ctx);
			}
			__GC_MV(this, &(this->btree), (new(ctx) BTree(ctx))->init((new(ctx) File(this->storagePath, ctx)), database->getBtreeCache(ctx), database->getCore(ctx)->diskCache, ctx), IBTree);
			this->btree->initTreeStorage(32, IBTreeValue::TYPE_LONG, IBTreeValue::TYPE_LONG, (long long)DatatableConstants::capacity, (long long)64, ctx);
			this->btree->open(ctx);
		}
		catch(IOException* e)
		{
			throw (new(ctx) AlinousException(ConstStr::getCNST_STR_1724(), e, ctx));
		}
		catch(InterruptedException* e)
		{
			throw (new(ctx) AlinousException(ConstStr::getCNST_STR_1724(), e, ctx));
		}
		catch(BTreeException* e)
		{
			throw (new(ctx) AlinousException(ConstStr::getCNST_STR_1724(), e, ctx));
		}
	}
}
bool ScanResultIndex::hasColumns(ArrayList<ScanTableColumnIdentifier>* indexColumns, ThreadContext* ctx) throw() 
{
	int maxLoop = indexColumns->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ScanTableColumnIdentifier* colId = indexColumns->get(i, ctx);
		ScanTableColumnIdentifier* colId2 = this->columns->get(i, ctx);
		if(!colId->equals(colId2, ctx))
		{
			return false;
		}
	}
	return true;
}
void ScanResultIndex::addIndex(ScanResultRecord* scanedRecord, ThreadContext* ctx)
{
	LongValue* soid = (new(ctx) LongValue(scanedRecord->getSoid(ctx), ctx));
	ScanResultIndexKey* key = (new(ctx) ScanResultIndexKey(ctx));
	int maxLoop = this->colsOrders->length;
	for(int i = 0; i != maxLoop; ++i)
	{
		int colOrder = this->colsOrders->get(i);
		VariantValue* vv = scanedRecord->get(colOrder, ctx);
		key->addKeyValue(vv, ctx);
	}
	btree->putKeyValue(key, soid, ctx);
}
IBTree* ScanResultIndex::getBtree(ThreadContext* ctx) throw() 
{
	return btree;
}
void ScanResultIndex::dispose(ISystemLog* logger, ThreadContext* ctx) throw() 
{
	{
		try
		{
			this->btree->close(ctx);
		}
		catch(Throwable* e)
		{
			logger->logError(e, ctx);
		}
	}
}
String* ScanResultIndex::getOidIndexName(ThreadContext* ctx) throw() 
{
	if(this->storagePath == nullptr)
	{
		StringBuilder* buff = (new(ctx) StringBuilder(ctx));
		buff->append(this->trxDir, ctx);
		if(!this->trxDir->endsWith(ConstStr::getCNST_STR_1007(), ctx))
		{
			buff->append(ConstStr::getCNST_STR_1007(), ctx);
		}
		buff->append(ConstStr::getCNST_STR_1725(), ctx)->append(this->indexSerial, ctx)->append(ConstStr::getCNST_STR_1728(), ctx);
		__GC_MV(this, &(this->storagePath), buff->toString(ctx), String);
	}
	return this->storagePath;
}
}}}}

