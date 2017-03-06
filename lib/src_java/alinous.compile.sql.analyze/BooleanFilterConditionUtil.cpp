#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/IAlinousElementVisitor.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile/Token.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.variant/VariantValue.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile.analyse/AlinousType.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.compile.expression/IExpression.h"
#include "java.lang/Comparable.h"
#include "alinous.btree/IBTreeKey.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.system/ISystemLog.h"
#include "alinous.db/AlinousDatabase.h"
#include "alinous.db.table/TableColumnMetadata.h"
#include "alinous.compile.sql.analyze/ScanTableIdentifier.h"
#include "alinous.compile.sql.analyze/ScanTableColumnIdentifier.h"
#include "alinous.compile.sql.analyze/ScanTableColumnMetadata.h"
#include "alinous.compile.sql.analyze/ScanTableIndexMetadata.h"
#include "alinous.compile.sql.analyze/ScanTableMetadata.h"
#include "alinous.compile.sql.analyze/SQLAnalyseContext.h"
#include "alinous.compile.sql.select/SQLWhere.h"
#include "alinous.db.trx.scan/ScanResultIndexKey.h"
#include "alinous.db.trx.scan/ITableTargetScanner.h"
#include "alinous.db.trx/DbTransaction.h"
#include "alinous.db.trx.scan/ScanResultRecord.h"
#include "alinous.compile.sql.expression/ISQLExpression.h"
#include "alinous.compile.sql.analyze/IndexColumnMatchCondition.h"
#include "alinous.compile.sql.expression/AbstractSQLExpression.h"
#include "alinous.compile.sql.expression/SQLParenthesisExpression.h"
#include "alinous.compile.sql.expression.blexp/ISQLBoolExpression.h"
#include "alinous.compile.sql.expression.blexp/AbstractSQLBooleanExpression.h"
#include "alinous.compile.sql.expression.blexp/SQLBoolSubExpression.h"
#include "alinous.compile.sql.expression.blexp/AbstractSQLBooleanCollectionExpression.h"
#include "alinous.compile.sql.expression.blexp/SQLAndExpression.h"
#include "alinous.compile.sql.expression.blexp/SQLOrExpression.h"
#include "alinous.compile.sql.analyze/IndexScanStrategyPlan.h"
#include "alinous.compile.sql.analyze/IndexScanStrategy.h"
#include "alinous.compile.sql.analyze/InnerNecessaryCondition.h"
#include "alinous.compile.sql.analyze/BooleanFilterConditionUtil.h"
#include "alinous.db.table/TableMetadataUnique.h"
#include "alinous.db.table/TablePartitionKey.h"
#include "alinous.compile.sql.analyze/ScanUnique.h"
#include "alinous.compile.sql.analyze/JoinMatchExpression.h"
#include "alinous.compile.sql.analyze/JoinStrategyPart.h"
#include "alinous.db.table/TablePartitionKeyCollection.h"
#include "alinous.compile.sql.analyze/TableMetadataUniqueCollection.h"
#include "alinous.compile.sql.analyze/IndexConditionDetector.h"
#include "alinous.compile.sql.analyze/IndexSelectionUtils.h"
#include "alinous.compile.sql.analyze/IScanStrategy.h"
#include "alinous.db.trx.scan/IFilterScanner.h"
#include "alinous.db.table.scan/SingleTableIndexScanner.h"
#include "alinous.db.trx.scan/ScannedResultIndexScanner.h"
#include "alinous.compile.sql.analyze/ScanSingleStrategy.h"
#include "alinous.compile.sql.analyze/JoinConditionDetector.h"
#include "alinous.compile.sql.analyze/JoinStrategy.h"

namespace alinous {namespace compile {namespace sql {namespace analyze {





bool BooleanFilterConditionUtil::__init_done = __init_static_variables();
bool BooleanFilterConditionUtil::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"BooleanFilterConditionUtil", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 BooleanFilterConditionUtil::BooleanFilterConditionUtil(ThreadContext* ctx) throw()  : IObject(ctx)
{
}
void BooleanFilterConditionUtil::__construct_impl(ThreadContext* ctx) throw() 
{
}
 BooleanFilterConditionUtil::~BooleanFilterConditionUtil() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void BooleanFilterConditionUtil::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
ArrayList<InnerNecessaryCondition>* BooleanFilterConditionUtil::fetchCondition(ISQLExpression* boolExpression, ScanTableIdentifier* table, ThreadContext* ctx) throw() 
{
	ArrayList<InnerNecessaryCondition>* result = (new(ctx) ArrayList<InnerNecessaryCondition>(ctx));
	if(boolExpression->hasSubExp(ctx) && (static_cast<AbstractSQLBooleanCollectionExpression*>(boolExpression))->getContainerType(ctx) == AbstractSQLBooleanCollectionExpression::AND_EXP)
	{
		ISQLExpression* exp = handleExpression(boolExpression, table, ctx);
		if(exp != nullptr)
		{
			result->add((new(ctx) InnerNecessaryCondition(exp, ctx)), ctx);
		}
	}
		else 
	{
		if(boolExpression->hasSubExp(ctx) && (static_cast<AbstractSQLBooleanCollectionExpression*>(boolExpression))->getContainerType(ctx) == AbstractSQLBooleanCollectionExpression::OR_EXP)
		{
			SQLOrExpression* orExp = static_cast<SQLOrExpression*>(boolExpression);
			ISQLExpression* first = handleExpression(orExp->getFirst(ctx), table, ctx);
			if(first != nullptr)
			{
				result->add((new(ctx) InnerNecessaryCondition(first, ctx)), ctx);
			}
			ArrayList<SQLBoolSubExpression>* list = orExp->getExpressions(ctx);
			int maxLoop = list->size(ctx);
			for(int i = 0; i != maxLoop; ++i)
			{
				SQLBoolSubExpression* subExp = list->get(i, ctx);
				ISQLExpression* exp = handleExpression(subExp->getExp(ctx), table, ctx);
				if(exp != nullptr)
				{
					result->add((new(ctx) InnerNecessaryCondition(exp, ctx)), ctx);
				}
			}
		}
				else 
		{
			if((dynamic_cast<SQLParenthesisExpression*>(boolExpression) != 0))
			{
				SQLParenthesisExpression* pexp = static_cast<SQLParenthesisExpression*>(boolExpression);
				ISQLExpression* exp = handleExpression(pexp->getExp(ctx), table, ctx);
				if(exp != nullptr)
				{
					result->add((new(ctx) InnerNecessaryCondition(exp, ctx)), ctx);
				}
			}
						else 
			{
				if(boolExpression->hasTable(table, ctx) && !boolExpression->isJoinCondition(ctx))
				{
					result->add((new(ctx) InnerNecessaryCondition(boolExpression, ctx)), ctx);
				}
			}
		}
	}
	return result;
}
ISQLExpression* BooleanFilterConditionUtil::handleExpression(ISQLExpression* currentExpression, ScanTableIdentifier* table, ThreadContext* ctx) throw() 
{
	if((dynamic_cast<SQLParenthesisExpression*>(currentExpression) != 0))
	{
		SQLParenthesisExpression* pexp = static_cast<SQLParenthesisExpression*>(currentExpression);
		return handleExpression(pexp->getExp(ctx), table, ctx);
	}
		else 
	{
		if(currentExpression->hasSubExp(ctx))
		{
			return handleContainerExpression(static_cast<AbstractSQLBooleanCollectionExpression*>(currentExpression), table, ctx);
		}
	}
	if(currentExpression->hasTable(table, ctx) && !currentExpression->isJoinCondition(ctx))
	{
		return currentExpression;
	}
	return nullptr;
}
ISQLExpression* BooleanFilterConditionUtil::handleContainerExpression(AbstractSQLBooleanCollectionExpression* currentExpression, ScanTableIdentifier* table, ThreadContext* ctx) throw() 
{
	ArrayList<ISQLExpression>* result = (new(ctx) ArrayList<ISQLExpression>(ctx));
	if(currentExpression->getContainerType(ctx) == AbstractSQLBooleanCollectionExpression::AND_EXP)
	{
		SQLAndExpression* andExp = static_cast<SQLAndExpression*>(currentExpression);
		ISQLExpression* first = handleExpression(andExp->getFirst(ctx), table, ctx);
		if(first != nullptr)
		{
			result->add(first, ctx);
		}
		ArrayList<SQLBoolSubExpression>* list = andExp->getExpressions(ctx);
		int maxLoop = list->size(ctx);
		for(int i = 0; i != maxLoop; ++i)
		{
			SQLBoolSubExpression* subExp = list->get(i, ctx);
			ISQLExpression* exp = handleExpression(subExp->getExp(ctx), table, ctx);
			if(exp != nullptr)
			{
				result->add(exp, ctx);
			}
		}
		maxLoop = result->size(ctx);
		switch(maxLoop) {
		case 0:
			return nullptr;
		case 1:
			return result->get(0, ctx);
		default:
			return (new(ctx) SQLAndExpression(result, ctx));
			break;
		}
	}
		else 
	{
		if(currentExpression->getContainerType(ctx) == AbstractSQLBooleanCollectionExpression::OR_EXP)
		{
			SQLOrExpression* orExp = static_cast<SQLOrExpression*>(currentExpression);
			ISQLExpression* first = handleExpression(orExp->getFirst(ctx), table, ctx);
			if(first != nullptr)
			{
				result->add(first, ctx);
			}
			ArrayList<SQLBoolSubExpression>* list = orExp->getExpressions(ctx);
			int maxLoop = list->size(ctx);
			for(int i = 0; i != maxLoop; ++i)
			{
				SQLBoolSubExpression* subExp = list->get(i, ctx);
				ISQLExpression* exp = handleExpression(subExp->getExp(ctx), table, ctx);
				if(exp != nullptr)
				{
					result->add(exp, ctx);
				}
			}
			maxLoop = result->size(ctx);
			switch(maxLoop) {
			case 0:
				return nullptr;
			case 1:
				return result->get(0, ctx);
			default:
				return (new(ctx) SQLOrExpression(result, ctx));
				break;
			}
		}
	}
	return nullptr;
}
void BooleanFilterConditionUtil::__cleanUp(ThreadContext* ctx){
}
}}}}

