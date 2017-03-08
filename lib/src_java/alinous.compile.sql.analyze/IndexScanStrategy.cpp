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
#include "alinous.system/AlinousException.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.variant/VariantValue.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile.sql.analyze/ScanTableIdentifier.h"
#include "alinous.compile.sql.analyze/ScanTableColumnIdentifier.h"
#include "alinous.compile.sql.analyze/ScanTableIndexMetadata.h"
#include "alinous.compile.sql.analyze/ScanTableMetadata.h"
#include "alinous.compile.sql.analyze/SQLAnalyseContext.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.db.trx.scan/ScanResultRecord.h"
#include "alinous.compile.sql.expression/ISQLExpression.h"
#include "alinous.compile.sql.analyze/IndexSelectionUtils.h"
#include "alinous.compile.sql.analyze/IndexColumnMatchCondition.h"
#include "alinous.compile.sql.expression.blexp/ISQLBoolExpression.h"
#include "alinous.compile.sql.expression.blexp/AbstractSQLBooleanExpression.h"
#include "alinous.compile.sql.analyze/IndexScanStrategyPlan.h"
#include "alinous.compile.sql.analyze/IndexScanStrategy.h"

namespace alinous {namespace compile {namespace sql {namespace analyze {





bool IndexScanStrategy::__init_done = __init_static_variables();
bool IndexScanStrategy::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"IndexScanStrategy", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 IndexScanStrategy::IndexScanStrategy(ScanTableMetadata* metadata, ThreadContext* ctx) throw()  : IObject(ctx), list(GCUtils<ArrayList<IndexScanStrategyPlan> >::ins(this, (new(ctx) ArrayList<IndexScanStrategyPlan>(ctx)), ctx, __FILEW__, __LINE__, L"")), metadata(nullptr), alwaysEmpty(0), bestplan(nullptr)
{
	__GC_MV(this, &(this->metadata), metadata, ScanTableMetadata);
	this->alwaysEmpty = false;
}
void IndexScanStrategy::__construct_impl(ScanTableMetadata* metadata, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->metadata), metadata, ScanTableMetadata);
	this->alwaysEmpty = false;
}
 IndexScanStrategy::~IndexScanStrategy() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void IndexScanStrategy::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"IndexScanStrategy", L"~IndexScanStrategy");
	__e_obj1.add(this->list, this);
	list = nullptr;
	__e_obj1.add(this->metadata, this);
	metadata = nullptr;
	__e_obj1.add(this->bestplan, this);
	bestplan = nullptr;
	if(!prepare){
		return;
	}
}
bool IndexScanStrategy::calcBestIndexPlan(ArrayList<ScanTableColumnIdentifier>* joinRequest, ThreadContext* ctx) throw() 
{
	int bestscore = 0;
	__GC_MV(this, &(this->bestplan), nullptr, IndexScanStrategyPlan);
	int maxLoop = this->list->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IndexScanStrategyPlan* plan = this->list->get(i, ctx);
		int score = plan->calcEfficience(ctx);
		if(joinRequest != nullptr && plan->indexIncludesColumns(joinRequest, ctx))
		{
			score = score + 1000000;
		}
		if(score > bestscore)
		{
			bestscore = score;
			__GC_MV(this, &(this->bestplan), plan, IndexScanStrategyPlan);
		}
	}
	return false;
}
IndexScanStrategyPlan* IndexScanStrategy::getBestPlan(ArrayList<ScanTableColumnIdentifier>* joinRequest, ThreadContext* ctx) throw() 
{
	if(joinRequest == nullptr)
	{
		return this->bestplan;
	}
	int maxLoop = this->list->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IndexScanStrategyPlan* plan = this->list->get(i, ctx);
		int scanMode = plan->getScanMode(ctx);
		if(scanMode == IndexScanStrategyPlan::SCAN_EQ && plan->indexIncludesColumns(joinRequest, ctx))
		{
			return plan;
		}
	}
	return this->bestplan;
}
void IndexScanStrategy::addExpression(ISQLExpression* boolExpression, ScanTableMetadata* tableMetadata, bool debug, ThreadContext* ctx)
{
	if(!((dynamic_cast<AbstractSQLBooleanExpression*>(boolExpression) != 0)))
	{
		return;
	}
	AbstractSQLBooleanExpression* absBoolExp = static_cast<AbstractSQLBooleanExpression*>(boolExpression);
	IndexColumnMatchCondition* matchingCondition = absBoolExp->getIndexScanPart(ctx);
	if(matchingCondition == nullptr || !matchingCondition->validateStrategy(this->metadata, ctx))
	{
		return;
	}
	int matchMode = matchingCondition->getMatchMode(ctx);
	switch(matchMode) {
	case IndexColumnMatchCondition::INDEX_EQUALS:
		joinEqIndex(matchingCondition, debug, ctx);
		break ;
	case IndexColumnMatchCondition::INDEX_BEFORE:
		joinIntoRangeWithAfter(matchingCondition, ctx);
		break ;
	case IndexColumnMatchCondition::INDEX_AFTER:
		joinIntoRangeWithBefore(matchingCondition, ctx);
		break ;
	case IndexColumnMatchCondition::INDEX_RANGE:
	case IndexColumnMatchCondition::INDEX_IN:
		this->list->add((new(ctx) IndexScanStrategyPlan(matchingCondition, this, ctx)), ctx);
		break ;
	case IndexColumnMatchCondition::FULL_SCAN:
	default:
		break ;
	}
}
bool IndexScanStrategy::isAlwaysEmpty(ThreadContext* ctx) throw() 
{
	return alwaysEmpty;
}
void IndexScanStrategy::setAlwaysEmpty(bool alwaysEmpty, ThreadContext* ctx) throw() 
{
	this->alwaysEmpty = alwaysEmpty;
}
void IndexScanStrategy::copy(ThreadContext* ctx) throw() 
{
}
void IndexScanStrategy::joinEqIndex(IndexColumnMatchCondition* matchingCondition, bool debug, ThreadContext* ctx)
{
	ArrayList<ScanTableColumnIdentifier>* colsList = (new(ctx) ArrayList<ScanTableColumnIdentifier>(ctx));
	int matchCount = 0;
	int maxLoop = this->list->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IndexScanStrategyPlan* otherPart = this->list->get(i, ctx);
		if(otherPart->getMatchMode(ctx) != IndexColumnMatchCondition::INDEX_EQUALS)
		{
			continue;
		}
		colsList->clear(ctx);
		colsList->addAll(otherPart->getColumns(ctx), ctx);
		if(!colsList->contains(matchingCondition->getColumnIdentifier(ctx), ctx))
		{
			colsList->add(matchingCondition->getColumnIdentifier(ctx), ctx);
		}
				else 
		{
			continue;
		}
		ArrayList<ScanTableIndexMetadata>* abindexes = this->metadata->getAbailableIndexes(matchingCondition->getColumnIdentifier(ctx)->getTable(ctx), colsList, ctx);
		if(!abindexes->isEmpty(ctx))
		{
			matchCount ++ ;
			ScanTableIndexMetadata* minIdx = IndexSelectionUtils::getMinimumColumnIndexMetadata(abindexes, ctx);
			otherPart->addEqColumn(matchingCondition, minIdx, debug, ctx);
		}
	}
	if(matchCount == 0)
	{
		this->list->add((new(ctx) IndexScanStrategyPlan(matchingCondition, this, ctx)), ctx);
	}
}
void IndexScanStrategy::joinIntoRangeWithAfter(IndexColumnMatchCondition* matchingCondition, ThreadContext* ctx) throw() 
{
	int maxLoop = this->list->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IndexScanStrategyPlan* otherPart = this->list->get(i, ctx);
		IndexColumnMatchCondition* cond = otherPart->getFirstMatchCondition(ctx);
		if(otherPart->getMatchMode(ctx) == IndexColumnMatchCondition::INDEX_AFTER && cond != nullptr && cond->getColumnIdentifier(ctx)->equals(matchingCondition->getColumnIdentifier(ctx), ctx))
		{
			otherPart->setMatchMode(IndexColumnMatchCondition::INDEX_RANGE, ctx);
			cond->setMatchMode(IndexColumnMatchCondition::INDEX_RANGE, ctx);
			cond->setEnd(matchingCondition->getEnd(ctx), ctx);
			cond->setStartEq(matchingCondition->isStartEq(ctx), ctx);
			return;
		}
	}
	this->list->add((new(ctx) IndexScanStrategyPlan(matchingCondition, this, ctx)), ctx);
}
void IndexScanStrategy::joinIntoRangeWithBefore(IndexColumnMatchCondition* matchingCondition, ThreadContext* ctx) throw() 
{
	int maxLoop = this->list->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IndexScanStrategyPlan* otherPart = this->list->get(i, ctx);
		IndexColumnMatchCondition* cond = otherPart->getFirstMatchCondition(ctx);
		if(otherPart->getMatchMode(ctx) == IndexColumnMatchCondition::INDEX_BEFORE && cond != nullptr && cond->getColumnIdentifier(ctx)->equals(matchingCondition->getColumnIdentifier(ctx), ctx))
		{
			otherPart->setMatchMode(IndexColumnMatchCondition::INDEX_RANGE, ctx);
			cond->setMatchMode(IndexColumnMatchCondition::INDEX_RANGE, ctx);
			cond->setStart(matchingCondition->getStart(ctx), ctx);
			cond->setStartEq(matchingCondition->isStartEq(ctx), ctx);
			return;
		}
	}
	this->list->add((new(ctx) IndexScanStrategyPlan(matchingCondition, this, ctx)), ctx);
}
void IndexScanStrategy::includes(IndexSelectionUtils* arg0, ThreadContext* ctx) throw() 
{
}
void IndexScanStrategy::__cleanUp(ThreadContext* ctx){
}
}}}}

