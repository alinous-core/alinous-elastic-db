#include "includes.h"


namespace alinous {namespace runtime {





constexpr const long long CompileErrorException::serialVersionUID;
bool CompileErrorException::__init_done = __init_static_variables();
bool CompileErrorException::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"CompileErrorException", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 CompileErrorException::CompileErrorException(String* msg, Throwable* e, ThreadContext* ctx) throw()  : IObject(ctx), AlinousException(msg, e, ctx)
{
}
void CompileErrorException::__construct_impl(String* msg, Throwable* e, ThreadContext* ctx) throw() 
{
}
 CompileErrorException::~CompileErrorException() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void CompileErrorException::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	AlinousException::__releaseRegerences(true, ctx);
}
}}

