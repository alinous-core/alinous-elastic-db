#include "includes.h"


namespace alinous {namespace compile {namespace expression {





bool UnaryExpression::__init_done = __init_static_variables();
bool UnaryExpression::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"UnaryExpression", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 UnaryExpression::~UnaryExpression() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void UnaryExpression::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	AbstractExpression::__releaseRegerences(true, ctx);
}
bool UnaryExpression::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	return true;
}
bool UnaryExpression::isConstant(ThreadContext* ctx) throw() 
{
	return false;
}
bool UnaryExpression::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	return true;
}
IAlinousVariable* UnaryExpression::resolveExpression(ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	return machine->resolveExpression(this, debug, ctx);
}
ExpressionSourceId* UnaryExpression::getSourceId(ThreadContext* ctx) throw() 
{
	return (new(ctx) ExpressionSourceId(nullptr, this, nullptr, ctx));
}
bool UnaryExpression::isSQLExp(ThreadContext* ctx) throw() 
{
	return false;
}
int UnaryExpression::getExpressionType(ThreadContext* ctx) throw() 
{
	return IExpression::unaryExpression;
}
void UnaryExpression::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
}
void UnaryExpression::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putInt(ICommandData::__UnaryExpression, ctx);
}
}}}

