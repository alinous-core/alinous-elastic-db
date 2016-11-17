#include "includes.h"


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
}}}}

