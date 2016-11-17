#include "includes.h"


namespace alinous {namespace compile {namespace expression {





bool NullLiteral::__init_done = __init_static_variables();
bool NullLiteral::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"NullLiteral", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 NullLiteral::NullLiteral(ThreadContext* ctx) throw()  : IObject(ctx), Literal(Literal::literalTypes::NULL_LITERAL, ctx)
{
}
void NullLiteral::__construct_impl(ThreadContext* ctx) throw() 
{
}
 NullLiteral::~NullLiteral() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void NullLiteral::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	Literal::__releaseRegerences(true, ctx);
}
int NullLiteral::getExpressionType(ThreadContext* ctx) throw() 
{
	return IExpression::nullLiteral;
}
}}}

