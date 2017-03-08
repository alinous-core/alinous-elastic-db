#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile/Token.h"
#include "alinous.db.table/DatabaseException.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime.engine/AlinousNullPointerException.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.variant/VariantValue.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile.sql.analyze/ScanTableColumnIdentifier.h"
#include "alinous.compile.sql.expression/ISQLExpression.h"
#include "alinous.db.table/TableColumnMetadata.h"
#include "alinous.db.table/IScannableIndex.h"
#include "alinous.db.table/IDatabaseTable.h"
#include "java.lang/Comparable.h"
#include "alinous.btree/IBTreeKey.h"
#include "alinous.db.trx.scan/ScanResultIndexKey.h"
#include "alinous.db.table.scan/IndexListScannerParam.h"
#include "alinous.db.table.scan/IndexRangeScannerParam.h"
#include "alinous.compile.sql.analyze/ScanTableColumnMetadata.h"
#include "alinous.compile.sql.analyze/ScanTableIndexMetadata.h"
#include "alinous.compile.sql.analyze/IndexColumnMatchCondition.h"
#include "alinous.compile.sql.analyze/IndexScanStrategy.h"
#include "alinous.compile.sql.analyze/IndexScanStrategyPlan.h"

namespace alinous {namespace compile {namespace sql {namespace analyze {





constexpr const int IndexScanStrategyPlan::SCAN_ALWAYS_FALSE;
constexpr const int IndexScanStrategyPlan::SCAN_EQ;
constexpr const int IndexScanStrategyPlan::SCAN_RANGE;
constexpr const int IndexScanStrategyPlan::SCAN_LIST;
bool IndexScanStrategyPlan::__init_done = __init_static_variables();
bool IndexScanStrategyPlan::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"IndexScanStrategyPlan", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 IndexScanStrategyPlan::IndexScanStrategyPlan(IndexColumnMatchCondition* matchingCondition, IndexScanStrategy* parentStrategy, ThreadContext* ctx) throw()  : IObject(ctx), parentStrategy(nullptr), matchConditions(GCUtils<ArrayList<IndexColumnMatchCondition> >::ins(this, (new(ctx) ArrayList<IndexColumnMatchCondition>(ctx)), ctx, __FILEW__, __LINE__, L"")), indexType(0), matchMode(0), scanMode(-1)
{
	__GC_MV(this, &(this->parentStrategy), parentStrategy, IndexScanStrategy);
	this->indexType = matchingCondition->getIndexType(ctx);
	this->matchMode = matchingCondition->getMatchMode(ctx);
	this->matchConditions->add(matchingCondition, ctx);
	switch(matchingCondition->getMatchMode(ctx)) {
	case IndexColumnMatchCondition::INDEX_EQUALS:
		this->scanMode = SCAN_EQ;
		break ;
	case IndexColumnMatchCondition::INDEX_IN:
		this->scanMode = SCAN_LIST;
		break ;
	case IndexColumnMatchCondition::INDEX_BEFORE:
	case IndexColumnMatchCondition::INDEX_AFTER:
	case IndexColumnMatchCondition::INDEX_RANGE:
		this->scanMode = SCAN_RANGE;
		break ;
	case IndexColumnMatchCondition::FULL_SCAN:
	default:
		this->scanMode = SCAN_RANGE;
		break ;
	}
}
void IndexScanStrategyPlan::__construct_impl(IndexColumnMatchCondition* matchingCondition, IndexScanStrategy* parentStrategy, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->parentStrategy), parentStrategy, IndexScanStrategy);
	this->indexType = matchingCondition->getIndexType(ctx);
	this->matchMode = matchingCondition->getMatchMode(ctx);
	this->matchConditions->add(matchingCondition, ctx);
	switch(matchingCondition->getMatchMode(ctx)) {
	case IndexColumnMatchCondition::INDEX_EQUALS:
		this->scanMode = SCAN_EQ;
		break ;
	case IndexColumnMatchCondition::INDEX_IN:
		this->scanMode = SCAN_LIST;
		break ;
	case IndexColumnMatchCondition::INDEX_BEFORE:
	case IndexColumnMatchCondition::INDEX_AFTER:
	case IndexColumnMatchCondition::INDEX_RANGE:
		this->scanMode = SCAN_RANGE;
		break ;
	case IndexColumnMatchCondition::FULL_SCAN:
	default:
		this->scanMode = SCAN_RANGE;
		break ;
	}
}
 IndexScanStrategyPlan::~IndexScanStrategyPlan() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void IndexScanStrategyPlan::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"IndexScanStrategyPlan", L"~IndexScanStrategyPlan");
	__e_obj1.add(this->parentStrategy, this);
	parentStrategy = nullptr;
	__e_obj1.add(this->matchConditions, this);
	matchConditions = nullptr;
	if(!prepare){
		return;
	}
}
ScanResultIndexKey* IndexScanStrategyPlan::getEqIndexKey(ScriptMachine* machine, ArrayList<TableColumnMetadata>* cols, bool debug, ThreadContext* ctx)
{
	ScanResultIndexKey* key = (new(ctx) ScanResultIndexKey(ctx));
	int maxLoop = cols->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		if(i < this->matchConditions->size(ctx))
		{
			IndexColumnMatchCondition* cond = this->matchConditions->get(i, ctx);
			ISQLExpression* exp = cond->getStart(ctx);
			IAlinousVariable* val = exp->resolveExpression(machine, debug, ctx);
			key->addKeyValue(val->toVariantValue(ctx), ctx);
		}
				else 
		{
			key->addKeyValue((new(ctx) VariantValue(ctx)), ctx);
		}
	}
	return key;
}
IndexRangeScannerParam* IndexScanStrategyPlan::getRamgeIndexKeyParam(ScriptMachine* machine, ArrayList<TableColumnMetadata>* cols, bool debug, ThreadContext* ctx)
{
	int maxLoop = cols->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IndexColumnMatchCondition* cond = this->matchConditions->get(i, ctx);
		if(cond->getMatchMode(ctx) != IndexColumnMatchCondition::INDEX_RANGE && cond->getMatchMode(ctx) != IndexColumnMatchCondition::INDEX_AFTER && cond->getMatchMode(ctx) != IndexColumnMatchCondition::INDEX_BEFORE)
		{
			continue;
		}
		IndexRangeScannerParam* param = (new(ctx) IndexRangeScannerParam(ctx));
		ISQLExpression* exp = cond->getStart(ctx);
		if(exp != nullptr)
		{
			IAlinousVariable* val = exp->resolveExpression(machine, debug, ctx);
			ScanResultIndexKey* key = (new(ctx) ScanResultIndexKey(ctx));
			key->addKeyValue(val->toVariantValue(ctx), ctx);
			param->setStart(key, ctx);
			param->setStartEq(cond->isStartEq(ctx), ctx);
		}
		exp = cond->getEnd(ctx);
		if(exp != nullptr)
		{
			IAlinousVariable* val = exp->resolveExpression(machine, debug, ctx);
			ScanResultIndexKey* key = (new(ctx) ScanResultIndexKey(ctx));
			key->addKeyValue(val->toVariantValue(ctx), ctx);
			__GC_MV(param, &(param->end), key, ScanResultIndexKey);
			param->endEq = cond->isEndEq(ctx);
		}
		return param;
	}
	return nullptr;
}
IndexListScannerParam* IndexScanStrategyPlan::getListIndexKey(ScriptMachine* machine, ArrayList<TableColumnMetadata>* cols, bool debug, ThreadContext* ctx)
{
	int maxLoop = cols->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IndexColumnMatchCondition* cond = this->matchConditions->get(i, ctx);
		if(cond->getMatchMode(ctx) != IndexColumnMatchCondition::INDEX_IN)
		{
			continue;
		}
		IndexListScannerParam* param = (new(ctx) IndexListScannerParam(ctx));
		ArrayList<ISQLExpression>* explist = cond->getExplist(ctx);
		int numexp = explist->size(ctx);
		for(int j = 0; j != numexp; ++j)
		{
			ISQLExpression* exp = explist->get(j, ctx);
			IAlinousVariable* val = exp->resolveExpression(machine, debug, ctx);
			ScanResultIndexKey* key = (new(ctx) ScanResultIndexKey(ctx));
			key->addKeyValue(val->toVariantValue(ctx), ctx);
			param->addIndexKey(key, ctx);
		}
		return param;
	}
	return nullptr;
}
int IndexScanStrategyPlan::getEqKeyLength(ThreadContext* ctx) throw() 
{
	return this->matchConditions->size(ctx);
}
IScannableIndex* IndexScanStrategyPlan::getIndex(IDatabaseTable* tableStore, ThreadContext* ctx) throw() 
{
	ArrayList<ScanTableColumnIdentifier>* colIdList = getColumns(ctx);
	IScannableIndex* tableindex = tableStore->getTableIndexByColIds(colIdList, ctx);
	return tableindex;
}
int IndexScanStrategyPlan::calcEfficience(ThreadContext* ctx) throw() 
{
	int score = 1;
	int maxLoop = this->matchConditions->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IndexColumnMatchCondition* cond = this->matchConditions->get(i, ctx);
		score = score * cond->indexEficience(ctx);
	}
	return score;
}
bool IndexScanStrategyPlan::indexIncludesColumns(ArrayList<ScanTableColumnIdentifier>* colOrder, ThreadContext* ctx) throw() 
{
	int maxLoop = colOrder->size(ctx);
	if(maxLoop < this->matchConditions->size(ctx))
	{
		return false;
	}
	for(int i = 0; i != maxLoop; ++i)
	{
		ScanTableColumnIdentifier* targetColId = colOrder->get(i, ctx);
		IndexColumnMatchCondition* idxCond = this->matchConditions->get(i, ctx);
		if(!targetColId->equals(idxCond->getColumnIdentifier(ctx), ctx))
		{
			return false;
		}
	}
	return true;
}
void IndexScanStrategyPlan::addEqColumn(IndexColumnMatchCondition* matchingCondition, ScanTableIndexMetadata* indexMetadata, bool debug, ThreadContext* ctx)
{
	if(checkIsVoid(matchingCondition, debug, ctx))
	{
		return;
	}
	this->matchConditions->add(matchingCondition, ctx);
	ArrayList<IndexColumnMatchCondition>* newOrderList = (new(ctx) ArrayList<IndexColumnMatchCondition>(ctx));
	ArrayList<ScanTableColumnMetadata>* list = indexMetadata->getColumns(ctx);
	int maxLoop = list->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ScanTableColumnMetadata* columnMeta = list->get(i, ctx);
		IndexColumnMatchCondition* cnd = findColumnMatchingConditionByColumnMetadta(columnMeta, ctx);
		if(cnd == nullptr)
		{
			throw (new(ctx) AlinousNullPointerException(ctx));
		}
		newOrderList->add(cnd, ctx);
	}
	this->matchConditions->clear(ctx);
	GCUtils<ArrayList<IndexColumnMatchCondition> >::mv(this, &(this->matchConditions), newOrderList, ctx);
}
IndexColumnMatchCondition* IndexScanStrategyPlan::getFirstMatchCondition(ThreadContext* ctx) throw() 
{
	return this->matchConditions->isEmpty(ctx) ? nullptr : this->matchConditions->get(0, ctx);
}
bool IndexScanStrategyPlan::sameColumns(IndexScanStrategyPlan* part, ThreadContext* ctx) throw() 
{
	ArrayList<ScanTableColumnIdentifier>* list = part->getColumns(ctx);
	int maxLoop = list->size(ctx);
	if(this->matchConditions->size(ctx) != maxLoop)
	{
		return false;
	}
	for(int i = 0; i != maxLoop; ++i)
	{
		ScanTableColumnIdentifier* colId = list->get(i, ctx);
		if(!hasColumn(colId, ctx))
		{
			return false;
		}
	}
	return true;
}
bool IndexScanStrategyPlan::hasColumn(ScanTableColumnIdentifier* colId, ThreadContext* ctx) throw() 
{
	ArrayList<ScanTableColumnIdentifier>* list = getColumns(ctx);
	int maxLoop = list->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ScanTableColumnIdentifier* myColId = list->get(i, ctx);
		if(myColId->equals(colId, ctx))
		{
			return true;
		}
	}
	return false;
}
ArrayList<IndexColumnMatchCondition>* IndexScanStrategyPlan::getMatchConditions(ThreadContext* ctx) throw() 
{
	return matchConditions;
}
ArrayList<ScanTableColumnIdentifier>* IndexScanStrategyPlan::getColumns(ThreadContext* ctx) throw() 
{
	ArrayList<ScanTableColumnIdentifier>* list = (new(ctx) ArrayList<ScanTableColumnIdentifier>(ctx));
	int maxLoop = this->matchConditions->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IndexColumnMatchCondition* cond = this->matchConditions->get(i, ctx);
		ScanTableColumnIdentifier* colId = cond->getColumnIdentifier(ctx);
		if(!list->contains(colId, ctx))
		{
			list->add(cond->getColumnIdentifier(ctx), ctx);
		}
	}
	return list;
}
int IndexScanStrategyPlan::getScanMode(ThreadContext* ctx) throw() 
{
	return scanMode;
}
int IndexScanStrategyPlan::getMatchMode(ThreadContext* ctx) throw() 
{
	return matchMode;
}
void IndexScanStrategyPlan::setMatchMode(int indexMode, ThreadContext* ctx) throw() 
{
	this->matchMode = indexMode;
}
int IndexScanStrategyPlan::getIndexType(ThreadContext* ctx) throw() 
{
	return indexType;
}
IndexColumnMatchCondition* IndexScanStrategyPlan::findColumnMatchingConditionByColumnMetadta(ScanTableColumnMetadata* columnMeta, ThreadContext* ctx) throw() 
{
	int maxLoop = this->matchConditions->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IndexColumnMatchCondition* idxCnd = this->matchConditions->get(i, ctx);
		ScanTableColumnIdentifier* colId = idxCnd->getColumnIdentifier(ctx);
		if(columnMeta->getColumnIdentifier(ctx)->equals(colId, ctx))
		{
			return idxCnd;
		}
	}
	return nullptr;
}
bool IndexScanStrategyPlan::checkIsVoid(IndexColumnMatchCondition* matchingCondition, bool debug, ThreadContext* ctx) throw() 
{
	int maxLoop = this->matchConditions->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IndexColumnMatchCondition* cnd = this->matchConditions->get(i, ctx);
		ScanTableColumnIdentifier* colId = cnd->getColumnIdentifier(ctx);
		ISQLExpression* exp = cnd->getStart(ctx);
		if(colId->equals(matchingCondition->getColumnIdentifier(ctx), ctx) && !expressionValueIsNotAlwaysSame(exp, matchingCondition->getStart(ctx), debug, ctx))
		{
			this->scanMode = SCAN_ALWAYS_FALSE;
			this->parentStrategy->setAlwaysEmpty(true, ctx);
			return true;
		}
				else 
		{
			if(colId->equals(matchingCondition->getColumnIdentifier(ctx), ctx) && expressionValueIsNotAlwaysSame(exp, matchingCondition->getStart(ctx), debug, ctx))
			{
				return true;
			}
		}
	}
	return true;
}
bool IndexScanStrategyPlan::expressionValueIsNotAlwaysSame(IExpression* exp1, IExpression* exp2, bool debug, ThreadContext* ctx) throw() 
{
	if(exp1->isConstant(ctx) && exp2->isConstant(ctx))
	{
		{
			try
			{
				IAlinousVariable* val1 = exp1->resolveExpression(nullptr, debug, ctx);
				IAlinousVariable* val2 = exp2->resolveExpression(nullptr, debug, ctx);
				return val1->compareTo(val2, ctx) != 0;
			}
			catch(AlinousException* e)
			{
				return false;
			}
			catch(DatabaseException* e)
			{
				return false;
			}
		}
	}
	return false;
}
void IndexScanStrategyPlan::__cleanUp(ThreadContext* ctx){
}
}}}}

