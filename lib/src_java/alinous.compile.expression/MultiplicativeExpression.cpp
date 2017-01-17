#include "includes.h"


namespace alinous {namespace compile {namespace expression {





bool MultiplicativeExpression::__init_done = __init_static_variables();
bool MultiplicativeExpression::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"MultiplicativeExpression", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 MultiplicativeExpression::~MultiplicativeExpression() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void MultiplicativeExpression::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	AbstractCollectionExpression::__releaseRegerences(true, ctx);
}
IAlinousVariable* MultiplicativeExpression::resolveExpression(ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	IAlinousVariable* variable = machine->resolveExpression(this->first, debug, ctx);
	if(variable == nullptr || variable->isArray(ctx))
	{
		throw (new(ctx) VariableException(ConstStr::getCNST_STR_1001(), ctx));
	}
	if(variable->isNull(ctx))
	{
		throw (new(ctx) AlinousNullPointerException(ctx));
	}
	variable = variable->copy(ctx);
	int maxLoop = this->expressions->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		SubExpression* subexp = this->expressions->get(i, ctx);
		IAlinousVariable* operand = machine->resolveExpression(subexp->getExp(ctx), debug, ctx)->copy(ctx);
		switch(subexp->getOp(ctx)) {
		case AbstractExpression::DIV:
			variable = variable->div(operand, ctx);
			break ;
		default:
			variable = variable->multiply(operand, ctx);
			break ;
		}
	}
	return variable;
}
bool MultiplicativeExpression::isSQLExp(ThreadContext* ctx) throw() 
{
	return false;
}
int MultiplicativeExpression::getExpressionType(ThreadContext* ctx) throw() 
{
	return IExpression::multiplicativeExpression;
}
void MultiplicativeExpression::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	__readData(buff, ctx);
}
void MultiplicativeExpression::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putInt(ICommandData::__MultiplicativeExpression, ctx);
	__writeData(buff, ctx);
}
void MultiplicativeExpression::toFileEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	builder->putInt(IExpressionFactory::__MultiplicativeExpression, ctx);
	__toFileEntry(builder, ctx);
}
}}}

