#include "include/global.h"


#include "org.alinous.charset/CharsetEncoder.h"

namespace org {namespace alinous {namespace charset {




bool CharsetEncoder::__init_done = __init_static_variables();
bool CharsetEncoder::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"CharsetEncoder", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 CharsetEncoder::CharsetEncoder(ThreadContext* ctx) throw()  : IObject(ctx)
{
}
void CharsetEncoder::__construct_impl(ThreadContext* ctx) throw() 
{
}
 CharsetEncoder::~CharsetEncoder() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void CharsetEncoder::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
void CharsetEncoder::__cleanUp(ThreadContext* ctx){
}
}}}

