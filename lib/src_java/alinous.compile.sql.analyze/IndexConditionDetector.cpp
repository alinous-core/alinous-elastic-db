#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.compile/IAlinousElementVisitor.h"
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
#include "alinous.compile.sql.analyze/ScanTableMetadata.h"
#include "alinous.compile.sql.analyze/SQLAnalyseContext.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.db.trx.scan/ScanResultRecord.h"
#include "alinous.compile.sql.expression/ISQLExpression.h"
#include "alinous.compile.sql.expression/AbstractSQLExpression.h"
#include "alinous.compile.sql.expression/SQLParenthesisExpression.h"
#include "alinous.compile.sql.analyze/IndexColumnMatchCondition.h"
#include "alinous.compile.sql.expression.blexp/ISQLBoolExpression.h"
#include "alinous.compile.sql.expression.blexp/AbstractSQLBooleanExpression.h"
#include "alinous.compile.sql.expression.blexp/SQLBoolSubExpression.h"
#include "alinous.compile.sql.expression.blexp/AbstractSQLBooleanCollectionExpression.h"
#include "alinous.compile.sql.expression.blexp/SQLAndExpression.h"
#include "alinous.compile.sql.analyze/IndexScanStrategy.h"
#include "alinous.compile.sql.analyze/IndexConditionDetector.h"

namespace alinous {namespace compile {namespace sql {namespace analyze {





bool IndexConditionDetector::__init_done = __init_static_variables();
bool IndexConditionDetector::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"IndexConditionDetector", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 IndexConditionDetector::IndexConditionDetector(ThreadContext* ctx) throw()  : IObject(ctx)
{
}
void IndexConditionDetector::__construct_impl(ThreadContext* ctx) throw() 
{
}
 IndexConditionDetector::~IndexConditionDetector() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void IndexConditionDetector::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
IndexScanStrategy* IndexConditionDetector::detect(ISQLExpression* boolExpression, ScanTableMetadata* tableMetadata, bool debug, ThreadContext* ctx)
{
	IndexScanStrategy* indexes = (new(ctx) IndexScanStrategy(tableMetadata, ctx));
	if(boolExpression->hasSubExp(ctx) && (static_cast<AbstractSQLBooleanCollectionExpression*>(boolExpression))->getContainerType(ctx) == AbstractSQLBooleanCollectionExpression::AND_EXP)
	{
		andExpression(static_cast<SQLAndExpression*>(boolExpression), indexes, tableMetadata, debug, ctx);
	}
	if(boolExpression->hasSubExp(ctx) && (static_cast<AbstractSQLBooleanCollectionExpression*>(boolExpression))->getContainerType(ctx) == AbstractSQLBooleanCollectionExpression::OR_EXP)
	{
	}
		else 
	{
		if((dynamic_cast<SQLParenthesisExpression*>(boolExpression) != 0))
		{
			SQLParenthesisExpression* pexp = static_cast<SQLParenthesisExpression*>(boolExpression);
			handleExpression(pexp->getExp(ctx), indexes, tableMetadata, debug, ctx);
		}
				else 
		{
			if(boolExpression->hasTable(tableMetadata->getFirstTableId(ctx), ctx) && !boolExpression->isJoinCondition(ctx))
			{
				indexes->addExpression(boolExpression, tableMetadata, debug, ctx);
			}
		}
	}
	return indexes;
}
void IndexConditionDetector::andExpression(SQLAndExpression* expression, IndexScanStrategy* indexes, ScanTableMetadata* tableMetadata, bool debug, ThreadContext* ctx)
{
	ISQLExpression* exp = expression->getFirst(ctx);
	handleExpression(exp, indexes, tableMetadata, debug, ctx);
	ArrayList<SQLBoolSubExpression>* subs = expression->getExpressions(ctx);
	int maxLoop = subs->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		SQLBoolSubExpression* subExp = subs->get(i, ctx);
		handleExpression(subExp->getExp(ctx), indexes, tableMetadata, debug, ctx);
	}
}
void IndexConditionDetector::handleExpression(ISQLExpression* expression, IndexScanStrategy* indexes, ScanTableMetadata* tableMetadata, bool debug, ThreadContext* ctx)
{
	if(expression->hasSubExp(ctx) && (static_cast<AbstractSQLBooleanCollectionExpression*>(expression))->getContainerType(ctx) == AbstractSQLBooleanCollectionExpression::AND_EXP)
	{
		andExpression(static_cast<SQLAndExpression*>(expression), indexes, tableMetadata, debug, ctx);
	}
	if(expression->hasSubExp(ctx) && (static_cast<AbstractSQLBooleanCollectionExpression*>(expression))->getContainerType(ctx) == AbstractSQLBooleanCollectionExpression::OR_EXP)
	{
	}
		else 
	{
		if((dynamic_cast<SQLParenthesisExpression*>(expression) != 0))
		{
			SQLParenthesisExpression* pexp = static_cast<SQLParenthesisExpression*>(expression);
			handleExpression(pexp->getExp(ctx), indexes, tableMetadata, debug, ctx);
		}
				else 
		{
			indexes->addExpression(expression, tableMetadata, debug, ctx);
		}
	}
}
void IndexConditionDetector::__cleanUp(ThreadContext* ctx){
}
}}}}

