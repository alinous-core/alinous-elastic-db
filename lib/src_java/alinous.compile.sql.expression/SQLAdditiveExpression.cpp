#include "includes.h"


namespace alinous {namespace compile {namespace sql {namespace expression {





bool SQLAdditiveExpression::__init_done = __init_static_variables();
bool SQLAdditiveExpression::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"SQLAdditiveExpression", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 SQLAdditiveExpression::~SQLAdditiveExpression() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void SQLAdditiveExpression::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	AbstractSQLCollectionExpression::__releaseRegerences(true, ctx);
}
IAlinousVariable* SQLAdditiveExpression::resolveExpression(ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	IAlinousVariable* val = this->first->resolveExpression(machine, debug, ctx);
	int maxLoop = this->expressions->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		SQLSubExpression* sub = this->expressions->get(i, ctx);
		IAlinousVariable* operand = sub->getExp(ctx)->resolveExpression(machine, debug, ctx);
		if(sub->getOp(ctx) == AbstractBooleanExpression::MINUS)
		{
			val = val->minus(operand, ctx);
		}
				else 
		{
			val = val->add(operand, ctx);
		}
	}
	return val;
}
VariantValue* SQLAdditiveExpression::resolveSQLExpression(ScanResultRecord* record, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	VariantValue* val = this->first->resolveSQLExpression(record, machine, debug, ctx);
	int maxLoop = this->expressions->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		SQLSubExpression* sub = this->expressions->get(i, ctx);
		VariantValue* operand = sub->getExp(ctx)->resolveSQLExpression(record, machine, debug, ctx);
		if(sub->getOp(ctx) == AbstractBooleanExpression::MINUS)
		{
			val = static_cast<VariantValue*>(val->minus(operand, ctx));
		}
				else 
		{
			val = static_cast<VariantValue*>(val->add(operand, ctx));
		}
	}
	return val;
}
ExpressionSourceId* SQLAdditiveExpression::getSourceId(ThreadContext* ctx) throw() 
{
	return (new(ctx) ExpressionSourceId(nullptr, this, nullptr, ctx));
}
bool SQLAdditiveExpression::hasSubExp(ThreadContext* ctx) throw() 
{
	return false;
}
bool SQLAdditiveExpression::isJoinCondition(ThreadContext* ctx) throw() 
{
	return false;
}
void SQLAdditiveExpression::collectJoinCondition(ArrayList<ISQLExpression>* list, ThreadContext* ctx) throw() 
{
}
bool SQLAdditiveExpression::isColumnIdentifier(ThreadContext* ctx) throw() 
{
	return false;
}
ScanTableColumnIdentifier* SQLAdditiveExpression::toColumnIdentifier(ThreadContext* ctx) throw() 
{
	return nullptr;
}
bool SQLAdditiveExpression::hasArrayResult(ThreadContext* ctx) throw() 
{
	return false;
}
ArrayList<VariantValue>* SQLAdditiveExpression::resolveSQLExpressionAsArray(ScanResultRecord* record, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1036(), ctx));
}
int SQLAdditiveExpression::getExpressionType(ThreadContext* ctx) throw() 
{
	return IExpression::sQLAdditiveExpression;
}
void SQLAdditiveExpression::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	__readData(buff, ctx);
}
void SQLAdditiveExpression::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putInt(ICommandData::__SQLAdditiveExpression, ctx);
	__writeData(buff, ctx);
}
void SQLAdditiveExpression::toFileEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	builder->putInt(IExpressionFactory::__SQLMultiplicativeExpression, ctx);
	__toFileEntry(builder, ctx);
}
}}}}

