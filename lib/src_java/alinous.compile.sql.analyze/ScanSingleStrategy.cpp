#include "includes.h"


namespace alinous {namespace compile {namespace sql {namespace analyze {





bool ScanSingleStrategy::__init_done = __init_static_variables();
bool ScanSingleStrategy::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ScanSingleStrategy", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ScanSingleStrategy::ScanSingleStrategy(ScanTableMetadata* table, ScanTableIdentifier* tableId, AlinousDatabase* database, ThreadContext* ctx) throw()  : IObject(ctx), filterConditions(GCUtils<ArrayList<InnerNecessaryCondition> >::ins(this, (new(ctx) ArrayList<InnerNecessaryCondition>(ctx)), ctx, __FILEW__, __LINE__, L"")), table(nullptr), database(nullptr), tableId(nullptr), joinRequest(nullptr)
{
	__GC_MV(this, &(this->table), table, ScanTableMetadata);
	__GC_MV(this, &(this->tableId), tableId, ScanTableIdentifier);
	__GC_MV(this, &(this->database), database, AlinousDatabase);
}
void ScanSingleStrategy::__construct_impl(ScanTableMetadata* table, ScanTableIdentifier* tableId, AlinousDatabase* database, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->table), table, ScanTableMetadata);
	__GC_MV(this, &(this->tableId), tableId, ScanTableIdentifier);
	__GC_MV(this, &(this->database), database, AlinousDatabase);
}
 ScanSingleStrategy::~ScanSingleStrategy() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ScanSingleStrategy::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ScanSingleStrategy", L"~ScanSingleStrategy");
	__e_obj1.add(this->filterConditions, this);
	filterConditions = nullptr;
	__e_obj1.add(this->table, this);
	table = nullptr;
	__e_obj1.add(this->database, this);
	database = nullptr;
	__e_obj1.add(this->tableId, this);
	tableId = nullptr;
	__e_obj1.add(this->joinRequest, this);
	joinRequest = nullptr;
	if(!prepare){
		return;
	}
}
ITableTargetScanner* ScanSingleStrategy::getScanner(ScriptMachine* machine, DbTransaction* trx, ArrayList<ScanTableColumnIdentifier>* joinRequest, bool debug, ThreadContext* ctx)
{
	if(this->filterConditions->isEmpty(ctx))
	{
		{
			try
			{
				return getNoWhereConditionScanner(machine, trx, joinRequest, debug, ctx);
			}
			catch(IOException* e)
			{
				throw (new(ctx) DatabaseException(e, ctx));
			}
			catch(InterruptedException* e)
			{
				throw (new(ctx) DatabaseException(e, ctx));
			}
		}
	}
	ITableTargetScanner* scanner = necessaryCollectionScanner(machine, trx, joinRequest, debug, ctx);
	return scanner;
}
void ScanSingleStrategy::optimize(ThreadContext* ctx) throw() 
{
	int maxLoop = this->filterConditions->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		InnerNecessaryCondition* cnd = this->filterConditions->get(i, ctx);
		cnd->optimizeIndexStrategy(database, this->joinRequest, ctx);
	}
}
void ScanSingleStrategy::analyzeFilterCondition(SQLWhere* where, ThreadContext* ctx) throw() 
{
	ArrayList<InnerNecessaryCondition>* result = nullptr;
	if(where != nullptr && where->getCondition(ctx) != nullptr)
	{
		ISQLExpression* whereExp = where->getCondition(ctx);
		result = BooleanFilterConditionUtil::fetchCondition(whereExp, this->table->getFirstTableId(ctx), ctx);
		if(result != nullptr)
		{
			this->filterConditions->addAll(result, ctx);
		}
	}
}
void ScanSingleStrategy::analyzeIndex(SQLWhere* where, ScanTableMetadata* tableMetadata, bool debug, ThreadContext* ctx)
{
	int maxloop = this->filterConditions->size(ctx);
	for(int i = 0; i != maxloop; ++i)
	{
		InnerNecessaryCondition* cond = this->filterConditions->get(i, ctx);
		cond->analyze(tableMetadata, debug, ctx);
	}
}
ITableTargetScanner* ScanSingleStrategy::getNoWhereConditionScanner(ScriptMachine* machine, DbTransaction* trx, ArrayList<ScanTableColumnIdentifier>* joinRequest, bool debug, ThreadContext* ctx)
{
	ArrayList<ScanTableIndexMetadata>* indexes = this->table->getAbailableIndexes(tableId, joinRequest, ctx);
	if(indexes != nullptr && !indexes->isEmpty(ctx))
	{
		ScanTableIndexMetadata* indexMeta = indexes->get(0, ctx);
		return getIndexScanner(trx, indexMeta, ctx);
	}
	if(joinRequest == nullptr)
	{
		return getFullScanScanner(trx, ctx);
	}
	{
		try
		{
			return getCachedFullScanScanner(trx, joinRequest, debug, ctx);
		}
		catch(AlinousException* e)
		{
			throw (new(ctx) DatabaseException(e, ctx));
		}
		catch(BTreeException* e)
		{
			throw (new(ctx) DatabaseException(e, ctx));
		}
	}
}
SingleTableIndexScanner* ScanSingleStrategy::getIndexScanner(DbTransaction* trx, ScanTableIndexMetadata* indexMeta, ThreadContext* ctx)
{
	ScanTableMetadata* metadata = this->table;
	IDatabaseTable* tableStore = this->database->getTable(metadata->getSchemaName(ctx), metadata->getTableName(ctx), ctx);
	TrxStorageManager* trxStorageManager = trx->getTrxStorageManager(ctx);
	IScannableIndex* index = tableStore->getAbailableIndex(indexMeta->getColumnsStr(ctx), ctx);
	TrxRecordCacheIndex* insertCacheindex = nullptr;
	TrxRecordCacheIndex* updateCacheindex = nullptr;
	{
		try
		{
			TrxRecordsCache* inserCache = trxStorageManager->getInsertCache(metadata->getSchemaName(ctx), metadata->getTableName(ctx), ctx);
			TrxRecordsCache* updateCache = trxStorageManager->getUpdateCache(metadata->getSchemaName(ctx), metadata->getTableName(ctx), ctx);
			if(inserCache != nullptr)
			{
				insertCacheindex = inserCache->getCachedIndex(indexMeta->getColumnIds(ctx), ctx);
			}
			if(updateCache != nullptr)
			{
				updateCacheindex = updateCache->getCachedIndex(indexMeta->getColumnIds(ctx), ctx);
			}
		}
		catch(AlinousDbException* e)
		{
			throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1049(), e, ctx));
		}
	}
	SingleTableIndexScanner* scanner = (new(ctx) SingleTableIndexScanner(ctx))->init(this->tableId, trx, index, tableStore, insertCacheindex, updateCacheindex, trx->lockMode, ctx);
	return scanner;
}
ITableTargetScanner* ScanSingleStrategy::getFullScanScanner(DbTransaction* trx, ThreadContext* ctx)
{
	ScanTableMetadata* metadata = this->table;
	IDatabaseTable* tableStore = this->database->getTable(metadata->getSchemaName(ctx), metadata->getTableName(ctx), ctx);
	IScannableIndex* index = tableStore->getPrimaryIndex(ctx);
	TrxStorageManager* trxStorageManager = trx->getTrxStorageManager(ctx);
	TrxRecordCacheIndex* insertCacheindex = nullptr;
	TrxRecordCacheIndex* updateCacheindex = nullptr;
	{
		try
		{
			ArrayList<ScanTableColumnIdentifier>* colIdList = (new(ctx) ArrayList<ScanTableColumnIdentifier>(ctx));
			ArrayList<TableColumnMetadata>* list = index->getColumns(ctx);
			int maxLoop = list->size(ctx);
			for(int i = 0; i != maxLoop; ++i)
			{
				TableColumnMetadata* metaCol = list->get(i, ctx);
				ScanTableColumnIdentifier* colId = (new(ctx) ScanTableColumnIdentifier(this->tableId, metaCol->name, ctx));
				colIdList->add(colId, ctx);
			}
			TrxRecordsCache* inserCache = trxStorageManager->getInsertCache(metadata->getSchemaName(ctx), metadata->getTableName(ctx), ctx);
			TrxRecordsCache* updateCache = trxStorageManager->getUpdateCache(metadata->getSchemaName(ctx), metadata->getTableName(ctx), ctx);
			if(inserCache != nullptr)
			{
				insertCacheindex = inserCache->getCachedIndex(colIdList, ctx);
			}
			if(updateCache != nullptr)
			{
				updateCacheindex = updateCache->getCachedIndex(colIdList, ctx);
			}
		}
		catch(AlinousDbException* e)
		{
			throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1049(), e, ctx));
		}
	}
	SingleTableIndexScanner* scanner = (new(ctx) SingleTableIndexScanner(ctx))->init(this->tableId, trx, index, tableStore, insertCacheindex, updateCacheindex, trx->lockMode, ctx);
	return scanner;
}
ITableTargetScanner* ScanSingleStrategy::getCachedFullScanScanner(DbTransaction* trx, ArrayList<ScanTableColumnIdentifier>* joinRequest, bool debug, ThreadContext* ctx)
{
	ITableTargetScanner* scanner = getFullScanScanner(trx, ctx);
	return toCachedScanner(trx, joinRequest, scanner, debug, ctx);
}
ScannedResultIndexScanner* ScanSingleStrategy::toCachedScanner(DbTransaction* trx, ArrayList<ScanTableColumnIdentifier>* joinRequest, ITableTargetScanner* scanner, bool debug, ThreadContext* ctx)
{
	ScanResult* result = trx->newResult(this->table, ctx);
	result->addIndex(joinRequest, ctx);
	{
		try
		{
			scanner->startScan(nullptr, ctx);
			while(scanner->hasNext(debug, ctx))
			{
				ScanResultRecord* record = scanner->next(debug, ctx);
				result->addRecord(record, trx, ctx);
			}
			scanner->endScan(ctx);
		}
		catch(Throwable* e)
		{
			scanner->dispose(trx->getLogger(ctx), ctx);
			throw e;
		}
	}
	scanner->dispose(trx->getLogger(ctx), ctx);
	ScannedResultIndexScanner* resultScanner = (new(ctx) ScannedResultIndexScanner(result, joinRequest, ctx));
	return resultScanner;
}
ITableTargetScanner* ScanSingleStrategy::necessaryCollectionScanner(ScriptMachine* machine, DbTransaction* trx, ArrayList<ScanTableColumnIdentifier>* joinRequest, bool debug, ThreadContext* ctx)
{
	int maxLoop = this->filterConditions->size(ctx);
	ArrayList<ITableTargetScanner>* list = (new(ctx) ArrayList<ITableTargetScanner>(ctx));
	for(int i = 0; i != maxLoop; ++i)
	{
		InnerNecessaryCondition* ncd = this->filterConditions->get(i, ctx);
		IndexScanStrategyPlan* plan = ncd->getStrategy(ctx)->getBestPlan(joinRequest, ctx);
		ITableTargetScanner* nscan = 0;
		{
			try
			{
				nscan = initOnTheFlyScanner(machine, plan, trx, joinRequest, ncd, debug, ctx);
				if(nscan == nullptr)
				{
					throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1050(), ctx));
				}
				list->add(nscan, ctx);
			}
			catch(IOException* e)
			{
				throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1051(), e, ctx));
			}
			catch(InterruptedException* e)
			{
				throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1051(), e, ctx));
			}
			catch(AlinousDbException* e)
			{
				throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1051(), e, ctx));
			}
		}
	}
	if(maxLoop == 1)
	{
		return list->get(0, ctx);
	}
	return nullptr;
}
ITableTargetScanner* ScanSingleStrategy::initOnTheFlyScanner(ScriptMachine* machine, IndexScanStrategyPlan* plan, DbTransaction* trx, ArrayList<ScanTableColumnIdentifier>* joinRequest, InnerNecessaryCondition* necessaryCnd, bool debug, ThreadContext* ctx)
{
	if(joinRequest != nullptr)
	{
		return initOnTheFlyScanner4Join(machine, plan, trx, joinRequest, necessaryCnd, ctx);
	}
	ScanTableMetadata* metadata = this->table;
	IDatabaseTable* tableStore = this->database->getTable(metadata->getSchemaName(ctx), metadata->getTableName(ctx), ctx);
	IScannableIndex* index = plan->getIndex(tableStore, ctx);
	TrxStorageManager* trxStorageManager = trx->getTrxStorageManager(ctx);
	TrxRecordCacheIndex* insertCacheindex = nullptr;
	TrxRecordCacheIndex* updateCacheindex = nullptr;
	ArrayList<ScanTableColumnIdentifier>* colIdList = nullptr;
	{
		try
		{
			colIdList = plan->getColumns(ctx);
			TrxRecordsCache* inserCache = trxStorageManager->getInsertCache(metadata->getSchemaName(ctx), metadata->getTableName(ctx), ctx);
			TrxRecordsCache* updateCache = trxStorageManager->getUpdateCache(metadata->getSchemaName(ctx), metadata->getTableName(ctx), ctx);
			if(inserCache != nullptr)
			{
				insertCacheindex = inserCache->getCachedIndex(colIdList, ctx);
			}
			if(updateCache != nullptr)
			{
				updateCacheindex = updateCache->getCachedIndex(colIdList, ctx);
			}
		}
		catch(AlinousDbException* e)
		{
			throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1049(), e, ctx));
		}
	}
	int matchMode = plan->getScanMode(ctx);
	switch(matchMode) {
	case IndexScanStrategyPlan::SCAN_ALWAYS_FALSE:
		return (new(ctx) VoidScanner(ctx));
	case IndexScanStrategyPlan::SCAN_EQ:
		{
			ScanResultIndexKey* eqKey = plan->getEqIndexKey(machine, index->getColumns(ctx), debug, ctx);
			int effectiveKeyLength = plan->getEqKeyLength(ctx);
			IndexEqScanner* intnlScanner = (new(ctx) IndexEqScanner(ctx))->init(this->tableId, trx, index, tableStore, insertCacheindex, updateCacheindex, trx->lockMode, eqKey, effectiveKeyLength, necessaryCnd, machine, ctx);
			return intnlScanner;
		}
	case IndexScanStrategyPlan::SCAN_RANGE:
		{
			IndexRangeScannerParam* param = plan->getRamgeIndexKeyParam(machine, index->getColumns(ctx), debug, ctx);
			int effectiveKeyLength = 1;
			IndexRangeScanner* rangeScanner = (new(ctx) IndexRangeScanner(ctx))->init(this->tableId, trx, index, tableStore, insertCacheindex, updateCacheindex, trx->lockMode, param, effectiveKeyLength, necessaryCnd, machine, ctx);
			return rangeScanner;
		}
	case IndexScanStrategyPlan::SCAN_LIST:
		{
			IndexListScannerParam* param = plan->getListIndexKey(machine, index->getColumns(ctx), debug, ctx);
			int effectiveKeyLength = 1;
			IndexListScanner* listScanner = (new(ctx) IndexListScanner(ctx))->init(this->tableId, trx, index, tableStore, insertCacheindex, updateCacheindex, trx->lockMode, param, effectiveKeyLength, necessaryCnd, machine, ctx);
			return listScanner;
		}
	default:
		throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1052(), ctx));
		break;
	}
}
ITableTargetScanner* ScanSingleStrategy::initOnTheFlyScanner4Join(ScriptMachine* machine, IndexScanStrategyPlan* plan, DbTransaction* trx, ArrayList<ScanTableColumnIdentifier>* joinRequest, InnerNecessaryCondition* necessaryCnd, ThreadContext* ctx)
{
	ScanTableMetadata* metadata = this->table;
	IDatabaseTable* tableStore = this->database->getTable(metadata->getSchemaName(ctx), metadata->getTableName(ctx), ctx);
	IScannableIndex* index = tableStore->getAbailableIndexByScanColId(joinRequest, ctx);
	if(index == nullptr)
	{
		TableIndexScanner* indexScanner = (new(ctx) TableIndexScanner(ctx))->init(this->tableId, trx, index, tableStore, trx->lockMode, ctx);
		return indexScanner;
	}
	TableFullScanner* scanner = (new(ctx) TableFullScanner(ctx))->init(this->tableId, trx, tableStore, trx->lockMode, ctx);
	return scanner;
}
}}}}

