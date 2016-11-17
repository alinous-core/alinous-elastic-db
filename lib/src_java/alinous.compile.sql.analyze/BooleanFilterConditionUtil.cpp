#include "includes.h"


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
}}}}

