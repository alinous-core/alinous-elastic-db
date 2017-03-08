#include "include/global.h"


#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime.engine/AlinousNullPointerException.h"

namespace alinous {namespace runtime {namespace engine {





constexpr const long long AlinousNullPointerException::serialVersionUID;
bool AlinousNullPointerException::__init_done = __init_static_variables();
bool AlinousNullPointerException::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AlinousNullPointerException", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AlinousNullPointerException::AlinousNullPointerException(ThreadContext* ctx) throw()  : IObject(ctx), AlinousException(ctx)
{
}
void AlinousNullPointerException::__construct_impl(ThreadContext* ctx) throw() 
{
}
 AlinousNullPointerException::AlinousNullPointerException(String* msg, ThreadContext* ctx) throw()  : IObject(ctx), AlinousException(msg, ctx)
{
}
void AlinousNullPointerException::__construct_impl(String* msg, ThreadContext* ctx) throw() 
{
}
 AlinousNullPointerException::AlinousNullPointerException(String* msg, Throwable* e, ThreadContext* ctx) throw()  : IObject(ctx), AlinousException(msg, e, ctx)
{
}
void AlinousNullPointerException::__construct_impl(String* msg, Throwable* e, ThreadContext* ctx) throw() 
{
}
 AlinousNullPointerException::~AlinousNullPointerException() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AlinousNullPointerException::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	AlinousException::__releaseRegerences(true, ctx);
}
void AlinousNullPointerException::__cleanUp(ThreadContext* ctx){
}
}}}

