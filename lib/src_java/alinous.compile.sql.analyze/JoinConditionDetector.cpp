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
#include "alinous.db.table/DatabaseException.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.variant/VariantValue.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile.analyse/AlinousType.h"
#include "alinous.compile/ExpressionSourceId.h"
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
#include "alinous.compile.sql.expression.blexp/SQLEqualityExpression.h"
#include "alinous.compile.sql.expression.blexp/SQLOrExpression.h"
#include "alinous.compile.sql.analyze/JoinMatchExpression.h"
#include "alinous.compile.sql.analyze/JoinStrategyPart.h"
#include "alinous.compile.sql.analyze/JoinConditionDetector.h"

namespace alinous {namespace compile {namespace sql {namespace analyze {





bool JoinConditionDetector::__init_done = __init_static_variables();
bool JoinConditionDetector::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"JoinConditionDetector", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 JoinConditionDetector::JoinConditionDetector(ThreadContext* ctx) throw()  : IObject(ctx)
{
}
void JoinConditionDetector::__construct_impl(ThreadContext* ctx) throw() 
{
}
 JoinConditionDetector::~JoinConditionDetector() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void JoinConditionDetector::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
ArrayList<JoinStrategyPart>* JoinConditionDetector::getJoinPart(SQLAnalyseContext* context, ScanTableMetadata* leftMetadata, ScanTableMetadata* rightMetadata, ISQLExpression* joinCondition, ThreadContext* ctx) throw() 
{
	ArrayList<JoinStrategyPart>* list = (new(ctx) ArrayList<JoinStrategyPart>(ctx));
	if(joinCondition->hasSubExp(ctx) && (static_cast<AbstractSQLBooleanCollectionExpression*>(joinCondition))->getContainerType(ctx) == AbstractSQLBooleanCollectionExpression::AND_EXP)
	{
		SQLAndExpression* andExp = static_cast<SQLAndExpression*>(joinCondition);
		JoinStrategyPart* part = (new(ctx) JoinStrategyPart(ctx));
		handleStrategyPart(context, andExp->getFirst(ctx), list, leftMetadata, rightMetadata, part, ctx);
		ArrayList<SQLBoolSubExpression>* subs = andExp->getExpressions(ctx);
		int maxLoop = subs->size(ctx);
		for(int i = 0; i != maxLoop; ++i)
		{
			SQLBoolSubExpression* subExp = subs->get(i, ctx);
			handleStrategyPart(context, subExp->getExp(ctx), list, leftMetadata, rightMetadata, part, ctx);
		}
		list->add(part, ctx);
	}
		else 
	{
		if(joinCondition->hasSubExp(ctx) && (static_cast<AbstractSQLBooleanCollectionExpression*>(joinCondition))->getContainerType(ctx) == AbstractSQLBooleanCollectionExpression::OR_EXP)
		{
			SQLOrExpression* orExp = static_cast<SQLOrExpression*>(joinCondition);
			JoinStrategyPart* part = (new(ctx) JoinStrategyPart(ctx));
			handleStrategyPart(context, orExp->getFirst(ctx), list, leftMetadata, rightMetadata, part, ctx);
			list->add(part, ctx);
			ArrayList<SQLBoolSubExpression>* subs = orExp->getExpressions(ctx);
			int maxLoop = subs->size(ctx);
			for(int i = 0; i != maxLoop; ++i)
			{
				SQLBoolSubExpression* subExp = subs->get(i, ctx);
				part = (new(ctx) JoinStrategyPart(ctx));
				handleStrategyPart(context, subExp->getExp(ctx), list, leftMetadata, rightMetadata, part, ctx);
				list->add(part, ctx);
			}
		}
				else 
		{
			if((dynamic_cast<SQLParenthesisExpression*>(joinCondition) != 0))
			{
				SQLParenthesisExpression* pexp = static_cast<SQLParenthesisExpression*>(joinCondition);
				handleStrategyPart(context, pexp->getExp(ctx), list, leftMetadata, rightMetadata, nullptr, ctx);
			}
						else 
			{
				JoinMatchExpression* matchExp = checkExpression(context, leftMetadata, rightMetadata, joinCondition, ctx);
				if(matchExp != nullptr)
				{
					JoinStrategyPart* part = (new(ctx) JoinStrategyPart(ctx));
					part->addExpression(matchExp, ctx);
					list->add(part, ctx);
				}
			}
		}
	}
	return list;
}
JoinMatchExpression* JoinConditionDetector::checkExpression(SQLAnalyseContext* context, ScanTableMetadata* leftMetadata, ScanTableMetadata* rightMetadata, ISQLExpression* joinCondition, ThreadContext* ctx) throw() 
{
	if(!joinCondition->isJoinCondition(ctx) || !leftMetadata->hasTable(joinCondition, ctx) || !rightMetadata->hasTable(joinCondition, ctx))
	{
		return nullptr;
	}
	if((dynamic_cast<SQLEqualityExpression*>(joinCondition) != 0))
	{
		JoinMatchExpression* jm = (new(ctx) JoinMatchExpression(static_cast<SQLEqualityExpression*>(joinCondition), leftMetadata, rightMetadata, ctx));
		if(jm->validate(ctx))
		{
			return jm;
		}
	}
	return nullptr;
}
void JoinConditionDetector::handleStrategyPart(SQLAnalyseContext* context, ISQLExpression* joinCondition, ArrayList<JoinStrategyPart>* list, ScanTableMetadata* leftMetadata, ScanTableMetadata* rightMetadata, JoinStrategyPart* current, ThreadContext* ctx) throw() 
{
	if(joinCondition->hasSubExp(ctx) && (static_cast<AbstractSQLBooleanCollectionExpression*>(joinCondition))->getContainerType(ctx) == AbstractSQLBooleanCollectionExpression::AND_EXP)
	{
		SQLAndExpression* andExp = static_cast<SQLAndExpression*>(joinCondition);
		handleStrategyPart(context, andExp->getFirst(ctx), list, leftMetadata, rightMetadata, current, ctx);
		ArrayList<SQLBoolSubExpression>* subs = andExp->getExpressions(ctx);
		int maxLoop = subs->size(ctx);
		for(int i = 0; i != maxLoop; ++i)
		{
			SQLBoolSubExpression* subExp = subs->get(i, ctx);
			handleStrategyPart(context, subExp->getExp(ctx), list, leftMetadata, rightMetadata, current, ctx);
		}
	}
		else 
	{
		if(joinCondition->hasSubExp(ctx) && (static_cast<AbstractSQLBooleanCollectionExpression*>(joinCondition))->getContainerType(ctx) == AbstractSQLBooleanCollectionExpression::OR_EXP)
		{
			if(current != nullptr)
			{
				return;
			}
			SQLOrExpression* orExp = static_cast<SQLOrExpression*>(joinCondition);
			handleStrategyPart(context, orExp->getFirst(ctx), list, leftMetadata, rightMetadata, nullptr, ctx);
			ArrayList<SQLBoolSubExpression>* subs = orExp->getExpressions(ctx);
			int maxLoop = subs->size(ctx);
			for(int i = 0; i != maxLoop; ++i)
			{
				SQLBoolSubExpression* subExp = subs->get(i, ctx);
				JoinStrategyPart* part = (new(ctx) JoinStrategyPart(ctx));
				handleStrategyPart(context, subExp->getExp(ctx), list, leftMetadata, rightMetadata, part, ctx);
				list->add(part, ctx);
			}
		}
				else 
		{
			if((dynamic_cast<SQLParenthesisExpression*>(joinCondition) != 0))
			{
				SQLParenthesisExpression* pexp = static_cast<SQLParenthesisExpression*>(joinCondition);
				handleStrategyPart(context, pexp->getExp(ctx), list, leftMetadata, rightMetadata, nullptr, ctx);
			}
						else 
			{
				JoinMatchExpression* matchExp = checkExpression(context, leftMetadata, rightMetadata, joinCondition, ctx);
				if(matchExp != nullptr)
				{
					JoinStrategyPart* part = current;
					if(part == nullptr)
					{
						(new(ctx) JoinStrategyPart(ctx));
					}
					part->addExpression(matchExp, ctx);
					list->add(part, ctx);
				}
			}
		}
	}
}
void JoinConditionDetector::__cleanUp(ThreadContext* ctx){
}
}}}}

