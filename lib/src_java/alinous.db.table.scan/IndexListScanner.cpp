#include "includes.h"


namespace alinous {namespace db {namespace table {namespace scan {





bool IndexListScanner::__init_done = __init_static_variables();
bool IndexListScanner::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"IndexListScanner", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 IndexListScanner::~IndexListScanner() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void IndexListScanner::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"IndexListScanner", L"~IndexListScanner");
	__e_obj1.add(this->trx, this);
	trx = nullptr;
	__e_obj1.add(this->machine, this);
	machine = nullptr;
	__e_obj1.add(this->scanner, this);
	scanner = nullptr;
	__e_obj1.add(this->insertScanner, this);
	insertScanner = nullptr;
	__e_obj1.add(this->updateScanner, this);
	updateScanner = nullptr;
	__e_obj1.add(this->param, this);
	param = nullptr;
	__e_obj1.add(this->meta, this);
	meta = nullptr;
	__e_obj1.add(this->result, this);
	result = nullptr;
	__e_obj1.add(this->necessaryCondition, this);
	necessaryCondition = nullptr;
	__e_obj1.add(this->currentKey, this);
	currentKey = nullptr;
	if(!prepare){
		return;
	}
}
IndexListScanner* IndexListScanner::init(ScanTableIdentifier* tableId, DbTransaction* trx, IScannableIndex* index, IDatabaseTable* tableStore, TrxRecordCacheIndex* insertCacheindex, TrxRecordCacheIndex* updateCacheindex, int lockMode, IndexListScannerParam* param, int effectiveKeyLength, InnerNecessaryCondition* necessaryCondition, ScriptMachine* machine, ThreadContext* ctx)
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
	__GC_MV(this, &(this->param), param, IndexListScannerParam);
	this->effectiveKeyLength = effectiveKeyLength;
	GCUtils<ArrayList<TableColumnMetadata> >::mv(this, &(this->meta), index->getColumns(ctx), ctx);
	__GC_MV(this, &(this->necessaryCondition), necessaryCondition, InnerNecessaryCondition);
	__GC_MV(this, &(this->machine), machine, ScriptMachine);
	return this;
}
void IndexListScanner::startScan(ScanResultIndexKey* indexKeyValue, ThreadContext* ctx)
{
	this->param->reset(ctx);
	startNextKey(ctx);
}
bool IndexListScanner::hasNext(bool debug, ThreadContext* ctx)
{
	if(this->result != nullptr)
	{
		return true;
	}
	while(true)
	{
		if(hasNext4CurrentKey(debug, ctx))
		{
			return true;
		}
		if(this->param->hasNext(ctx))
		{
			onceCloseScan(ctx);
			startNextKey(ctx);
		}
				else 
		{
			break ;
		}
	}
	return false;
}
void IndexListScanner::endScan(ThreadContext* ctx)
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
ScanResultRecord* IndexListScanner::next(bool debug, ThreadContext* ctx)
{
	ScanResultRecord* retresult = this->result;
	__GC_MV(this, &(this->result), nullptr, ScanResultRecord);
	return retresult;
}
void IndexListScanner::dispose(ISystemLog* logger, ThreadContext* ctx)
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
void IndexListScanner::startNextKey(ThreadContext* ctx)
{
	__GC_MV(this, &(this->currentKey), this->param->nextKey(ctx), ScanResultIndexKey);
	this->scanner->startScan(this->currentKey, ctx);
	if(this->insertScanner != nullptr)
	{
		this->insertScanner->startScan(this->currentKey, ctx);
	}
	if(this->updateScanner != nullptr)
	{
		this->updateScanner->startScan(this->currentKey, ctx);
	}
}
void IndexListScanner::onceCloseScan(ThreadContext* ctx)
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
bool IndexListScanner::hasNext4CurrentKey(bool debug, ThreadContext* ctx)
{
	if(this->updateScanner != nullptr && this->updateScanner->hasNext(debug, ctx))
	{
		bool isContinue = true;
		do
		{
			__GC_MV(this, &(this->result), this->updateScanner->next(debug, ctx), ScanResultRecord);
			isContinue = checkEquals(ctx);
			if(isContinue && satisfyNececity(debug, ctx))
			{
				return true;
			}
			this->result->unlock(trx, ctx);
		}
		while(isContinue && this->updateScanner->hasNext(debug, ctx));
	}
	if(this->insertScanner != nullptr && this->insertScanner->hasNext(debug, ctx))
	{
		bool isContinue = true;
		do
		{
			__GC_MV(this, &(this->result), this->insertScanner->next(debug, ctx), ScanResultRecord);
			isContinue = checkEquals(ctx);
			if(isContinue && satisfyNececity(debug, ctx))
			{
				return true;
			}
		}
		while(isContinue && this->insertScanner->hasNext(debug, ctx));
	}
	if(this->scanner->hasNext(debug, ctx))
	{
		bool isContinue = true;
		do
		{
			__GC_MV(this, &(this->result), this->scanner->next(debug, ctx), ScanResultRecord);
			isContinue = checkEquals(ctx);
			if(isContinue && satisfyNececity(debug, ctx))
			{
				return true;
			}
			this->result->unlock(trx, ctx);
		}
		while(isContinue && this->scanner->hasNext(debug, ctx));
	}
	return false;
}
bool IndexListScanner::checkEquals(ThreadContext* ctx) throw() 
{
	int maxLoop = this->effectiveKeyLength;
	for(int i = 0; i != maxLoop; ++i)
	{
		TableColumnMetadata* m = this->meta->get(i, ctx);
		VariantValue* vv = this->result->get(m->columnOrder, ctx);
		VariantValue* v0 = this->currentKey->get(i, ctx);
		if(vv->compareTo(v0, ctx) != 0)
		{
			return false;
		}
	}
	return true;
}
bool IndexListScanner::satisfyNececity(bool debug, ThreadContext* ctx)
{
	return this->necessaryCondition == nullptr || this->necessaryCondition->getExp(ctx)->resolveSQLExpression(this->result, this->machine, debug, ctx)->isTrue(ctx);
}
}}}}

