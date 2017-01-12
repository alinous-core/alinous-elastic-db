#include "includes.h"


namespace alinous {namespace compile {namespace expression {





bool ShiftExpression::__init_done = __init_static_variables();
bool ShiftExpression::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ShiftExpression", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ShiftExpression::~ShiftExpression() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ShiftExpression::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	AbstractCollectionExpression::__releaseRegerences(true, ctx);
}
IAlinousVariable* ShiftExpression::resolveExpression(ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	IAlinousVariable* variable = machine->resolveExpression(this->first, debug, ctx);
	if(variable == nullptr || variable->isArray(ctx))
	{
		throw (new(ctx) VariableException(ConstStr::getCNST_STR_999(), ctx));
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
		case AbstractExpression::SHIFT_LEFT:
			variable = variable->shiftLeft(operand, ctx);
			break ;
		case AbstractExpression::SHIFT_RIGHT:
			variable = variable->shiftRight(operand, ctx);
			break ;
		case AbstractExpression::SHIFT_RIGHT_UNSIGNED:
		default:
			variable = variable->shiftRightUnsigned(operand, ctx);
			break ;
		}
	}
	return variable;
}
bool ShiftExpression::isSQLExp(ThreadContext* ctx) throw() 
{
	return false;
}
int ShiftExpression::getExpressionType(ThreadContext* ctx) throw() 
{
	return IExpression::shiftExpression;
}
void ShiftExpression::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	__readData(buff, ctx);
}
void ShiftExpression::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putInt(ICommandData::__ShiftExpression, ctx);
	__writeData(buff, ctx);
}
}}}

