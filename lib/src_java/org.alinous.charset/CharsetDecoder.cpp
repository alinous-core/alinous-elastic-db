#include "include/global.h"


#include "org.alinous.charset/CharsetDecoder.h"

namespace org {namespace alinous {namespace charset {




bool CharsetDecoder::__init_done = __init_static_variables();
bool CharsetDecoder::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"CharsetDecoder", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 CharsetDecoder::CharsetDecoder(ThreadContext* ctx) throw()  : IObject(ctx)
{
}
void CharsetDecoder::__construct_impl(ThreadContext* ctx) throw() 
{
}
 CharsetDecoder::~CharsetDecoder() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void CharsetDecoder::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
void CharsetDecoder::__cleanUp(ThreadContext* ctx){
}
}}}

