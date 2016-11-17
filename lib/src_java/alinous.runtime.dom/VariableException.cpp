#include "includes.h"


namespace alinous {namespace runtime {namespace dom {





constexpr const long long VariableException::serialVersionUID;
bool VariableException::__init_done = __init_static_variables();
bool VariableException::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"VariableException", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 VariableException::VariableException(ThreadContext* ctx) throw()  : IObject(ctx), ExecutionException(ConstStr::getCNST_STR_1051(), ctx)
{
}
void VariableException::__construct_impl(ThreadContext* ctx) throw() 
{
}
 VariableException::VariableException(Throwable* e, ThreadContext* ctx) throw()  : IObject(ctx), ExecutionException(e, ctx)
{
}
void VariableException::__construct_impl(Throwable* e, ThreadContext* ctx) throw() 
{
}
 VariableException::VariableException(String* msg, AbstractSrcElement* element, ThreadContext* ctx) throw()  : IObject(ctx), ExecutionException(msg, element, ctx)
{
}
void VariableException::__construct_impl(String* msg, AbstractSrcElement* element, ThreadContext* ctx) throw() 
{
}
 VariableException::VariableException(String* msg, Throwable* e, ThreadContext* ctx) throw()  : IObject(ctx), ExecutionException(msg, e, ctx)
{
}
void VariableException::__construct_impl(String* msg, Throwable* e, ThreadContext* ctx) throw() 
{
}
 VariableException::VariableException(String* msg, ThreadContext* ctx) throw()  : IObject(ctx), ExecutionException(msg, ctx)
{
}
void VariableException::__construct_impl(String* msg, ThreadContext* ctx) throw() 
{
}
 VariableException::~VariableException() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void VariableException::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	ExecutionException::__releaseRegerences(true, ctx);
}
}}}

