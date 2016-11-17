#include "includes.h"


namespace alinous {namespace system {





constexpr const long long AlinousNotSupportedException::serialVersionUID;
bool AlinousNotSupportedException::__init_done = __init_static_variables();
bool AlinousNotSupportedException::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AlinousNotSupportedException", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AlinousNotSupportedException::AlinousNotSupportedException(ThreadContext* ctx) throw()  : IObject(ctx), AlinousException(ctx)
{
}
void AlinousNotSupportedException::__construct_impl(ThreadContext* ctx) throw() 
{
}
 AlinousNotSupportedException::AlinousNotSupportedException(String* msg, ThreadContext* ctx) throw()  : IObject(ctx), AlinousException(msg, ctx)
{
}
void AlinousNotSupportedException::__construct_impl(String* msg, ThreadContext* ctx) throw() 
{
}
 AlinousNotSupportedException::AlinousNotSupportedException(String* msg, Throwable* e, ThreadContext* ctx) throw()  : IObject(ctx), AlinousException(msg, e, ctx)
{
}
void AlinousNotSupportedException::__construct_impl(String* msg, Throwable* e, ThreadContext* ctx) throw() 
{
}
 AlinousNotSupportedException::~AlinousNotSupportedException() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AlinousNotSupportedException::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	AlinousException::__releaseRegerences(true, ctx);
}
}}

