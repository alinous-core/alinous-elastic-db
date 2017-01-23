#include "includes.h"


namespace alinous {namespace compile {namespace sql {namespace expression {





bool SQLMultiplicativeExpression::__init_done = __init_static_variables();
bool SQLMultiplicativeExpression::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"SQLMultiplicativeExpression", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 SQLMultiplicativeExpression::~SQLMultiplicativeExpression() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void SQLMultiplicativeExpression::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	AbstractSQLCollectionExpression::__releaseRegerences(true, ctx);
}
IAlinousVariable* SQLMultiplicativeExpression::resolveExpression(ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	IAlinousVariable* val = this->first->resolveExpression(machine, debug, ctx);
	int maxLoop = this->expressions->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		SQLSubExpression* sub = this->expressions->get(i, ctx);
		IAlinousVariable* operand = sub->getExp(ctx)->resolveExpression(machine, debug, ctx);
		if(sub->getOp(ctx) == AbstractBooleanExpression::DIV)
		{
			if(operand->toIntVariable(ctx)->getIntValue(ctx) == 0)
			{
				throw (new(ctx) AlinousException(ConstStr::getCNST_STR_1066(), ctx));
			}
			val = val->div(operand, ctx);
		}
				else 
		{
			val = val->multiply(operand, ctx);
		}
	}
	return val;
}
VariantValue* SQLMultiplicativeExpression::resolveSQLExpression(ScanResultRecord* record, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	VariantValue* val = this->first->resolveSQLExpression(record, machine, debug, ctx);
	int maxLoop = this->expressions->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		SQLSubExpression* sub = this->expressions->get(i, ctx);
		VariantValue* operand = sub->getExp(ctx)->resolveSQLExpression(record, machine, debug, ctx);
		if(sub->getOp(ctx) == AbstractBooleanExpression::DIV)
		{
			if(operand->toIntVariable(ctx)->getIntValue(ctx) == 0)
			{
				throw (new(ctx) AlinousException(ConstStr::getCNST_STR_1066(), ctx));
			}
			val = val->div(operand, ctx)->toVariantValue(ctx);
		}
				else 
		{
			val = val->multiply(operand, ctx)->toVariantValue(ctx);
		}
	}
	return val;
}
ExpressionSourceId* SQLMultiplicativeExpression::getSourceId(ThreadContext* ctx) throw() 
{
	return (new(ctx) ExpressionSourceId(nullptr, this, nullptr, ctx));
}
bool SQLMultiplicativeExpression::hasSubExp(ThreadContext* ctx) throw() 
{
	return false;
}
bool SQLMultiplicativeExpression::isJoinCondition(ThreadContext* ctx) throw() 
{
	return false;
}
void SQLMultiplicativeExpression::collectJoinCondition(ArrayList<ISQLExpression>* list, ThreadContext* ctx) throw() 
{
}
bool SQLMultiplicativeExpression::isColumnIdentifier(ThreadContext* ctx) throw() 
{
	return false;
}
ScanTableColumnIdentifier* SQLMultiplicativeExpression::toColumnIdentifier(ThreadContext* ctx) throw() 
{
	return nullptr;
}
bool SQLMultiplicativeExpression::hasArrayResult(ThreadContext* ctx) throw() 
{
	return false;
}
ArrayList<VariantValue>* SQLMultiplicativeExpression::resolveSQLExpressionAsArray(ScanResultRecord* record, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1036(), ctx));
}
int SQLMultiplicativeExpression::getExpressionType(ThreadContext* ctx) throw() 
{
	return IExpression::sQLMultiplicativeExpression;
}
void SQLMultiplicativeExpression::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	__readData(buff, ctx);
}
void SQLMultiplicativeExpression::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putInt(ICommandData::__SQLMultiplicativeExpression, ctx);
	__writeData(buff, ctx);
}
void SQLMultiplicativeExpression::toFileEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	builder->putInt(IExpressionFactory::__SQLMultiplicativeExpression, ctx);
	__toFileEntry(builder, ctx);
}
}}}}

