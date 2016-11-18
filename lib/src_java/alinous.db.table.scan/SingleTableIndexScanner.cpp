#include "includes.h"


namespace alinous {namespace db {namespace table {namespace scan {





bool SingleTableIndexScanner::__init_done = __init_static_variables();
bool SingleTableIndexScanner::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"SingleTableIndexScanner", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 SingleTableIndexScanner::~SingleTableIndexScanner() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void SingleTableIndexScanner::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"SingleTableIndexScanner", L"~SingleTableIndexScanner");
	__e_obj1.add(this->trx, this);
	trx = nullptr;
	__e_obj1.add(this->scanner, this);
	scanner = nullptr;
	__e_obj1.add(this->insertScanner, this);
	insertScanner = nullptr;
	__e_obj1.add(this->updateScanner, this);
	updateScanner = nullptr;
	__e_obj1.add(this->result, this);
	result = nullptr;
	if(!prepare){
		return;
	}
}
SingleTableIndexScanner* SingleTableIndexScanner::init(ScanTableIdentifier* tableId, DbTransaction* trx, TableIndex* index, IDatabaseTable* tableStore, TrxRecordCacheIndex* insertCacheindex, TrxRecordCacheIndex* updateCacheindex, int lockMode, ThreadContext* ctx)
{
	__GC_MV(this, &(this->trx), trx, DbTransaction);
	TableMetadata* tableMeta = tableStore->getMetadata(ctx);
	TrxRecordsCache* insertCache = this->trx->getTrxStorageManager(ctx)->getInsertCache(tableMeta->getSchema(ctx), tableMeta->getTableName(ctx), ctx);
	TrxRecordsCache* updateCache = this->trx->getTrxStorageManager(ctx)->getUpdateCache(tableMeta->getSchema(ctx), tableMeta->getTableName(ctx), ctx);
	__GC_MV(this, &(this->scanner), (new(ctx) TableIndexScanner(ctx))->init(tableId, trx, index, tableStore, lockMode, ctx), TableIndexScanner);
	if(insertCacheindex != nullptr && insertCache != nullptr)
	{
		__GC_MV(this, &(this->insertScanner), (new(ctx) TrxRecordCacheIndexScanner(tableId, trx, insertCacheindex, insertCache, IDatabaseRecord::TRX_CACHE, ctx)), TrxRecordCacheIndexScanner);
	}
	if(updateCacheindex != nullptr && updateCache != nullptr)
	{
		__GC_MV(this, &(this->updateScanner), (new(ctx) TrxRecordCacheIndexScanner(tableId, trx, updateCacheindex, updateCache, IDatabaseRecord::TRX_CACHE, ctx)), TrxRecordCacheIndexScanner);
	}
	return this;
}
bool SingleTableIndexScanner::hasNext(bool debug, ThreadContext* ctx)
{
	if(this->result != nullptr)
	{
		return true;
	}
	if(this->updateScanner != nullptr && this->updateScanner->hasNext(debug, ctx))
	{
		return true;
	}
	if(this->insertScanner != nullptr && this->insertScanner->hasNext(debug, ctx))
	{
		__GC_MV(this, &(this->result), this->insertScanner->next(debug, ctx), ScanResultRecord);
		return true;
	}
	if(this->scanner->hasNext(debug, ctx))
	{
		__GC_MV(this, &(this->result), this->scanner->next(debug, ctx), ScanResultRecord);
		return true;
	}
	return false;
}
ScanResultRecord* SingleTableIndexScanner::next(bool debug, ThreadContext* ctx)
{
	ScanResultRecord* retresult = this->result;
	__GC_MV(this, &(this->result), nullptr, ScanResultRecord);
	return retresult;
}
void SingleTableIndexScanner::startScan(ScanResultIndexKey* indexKeyValue, ThreadContext* ctx)
{
	__GC_MV(this, &(this->result), nullptr, ScanResultRecord);
	if(indexKeyValue != nullptr)
	{
		startsWithKey(indexKeyValue, ctx);
		return;
	}
	this->scanner->startScan(nullptr, ctx);
	if(this->insertScanner != nullptr)
	{
		this->insertScanner->startScan(nullptr, ctx);
	}
	if(this->updateScanner != nullptr)
	{
		this->updateScanner->startScan(nullptr, ctx);
	}
}
void SingleTableIndexScanner::endScan(ThreadContext* ctx)
{
	this->scanner->endScan(ctx);
	if(this->insertScanner != nullptr)
	{
		this->insertScanner->endScan(ctx);
	}
	if(this->updateScanner != nullptr)
	{
		this->updateScanner->endScan(ctx);
	}
}
void SingleTableIndexScanner::dispose(ISystemLog* logger, ThreadContext* ctx)
{
	this->scanner->dispose(logger, ctx);
	if(this->insertScanner != nullptr)
	{
		this->insertScanner->dispose(logger, ctx);
	}
	if(this->updateScanner != nullptr)
	{
		this->updateScanner->dispose(logger, ctx);
	}
}
void SingleTableIndexScanner::startsWithKey(ScanResultIndexKey* indexKeyValue, ThreadContext* ctx)
{
	ScanResultIndexKey* key = (new(ctx) ScanResultIndexKey(ctx));
	int maxLoop = indexKeyValue->getNumCols(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		key->addKeyValue(indexKeyValue->get(i, ctx), ctx);
	}
	this->scanner->startScan(key, ctx);
	if(this->insertScanner != nullptr)
	{
		this->insertScanner->startScan(key, ctx);
	}
	if(this->updateScanner != nullptr)
	{
		this->updateScanner->startScan(key, ctx);
	}
}
}}}}

