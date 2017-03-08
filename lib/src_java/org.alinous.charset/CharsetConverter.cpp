#include "include/global.h"


#include "org.alinous.charset/CharsetDecoder.h"
#include "org.alinous.charset/CharsetEncoder.h"
#include "org.alinous.charset/CharsetConverter.h"

namespace org {namespace alinous {namespace charset {




bool CharsetConverter::__init_done = __init_static_variables();
bool CharsetConverter::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"CharsetConverter", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 CharsetConverter::CharsetConverter(ThreadContext* ctx) throw()  : IObject(ctx)
{
}
void CharsetConverter::__construct_impl(ThreadContext* ctx) throw() 
{
}
 CharsetConverter::~CharsetConverter() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void CharsetConverter::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
void CharsetConverter::__cleanUp(ThreadContext* ctx){
}
}}}

