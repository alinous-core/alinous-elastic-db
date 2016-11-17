#include "includes.h"


namespace alinous {namespace btree {





constexpr const long long BTreeException::serialVersionUID;
bool BTreeException::__init_done = __init_static_variables();
bool BTreeException::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"BTreeException", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 BTreeException::BTreeException(String* msg, ThreadContext* ctx) throw()  : IObject(ctx), Throwable(msg, ctx)
{
}
void BTreeException::__construct_impl(String* msg, ThreadContext* ctx) throw() 
{
}
 BTreeException::BTreeException(String* string, Throwable* e, ThreadContext* ctx) throw()  : IObject(ctx), Throwable(string, e, ctx)
{
}
void BTreeException::__construct_impl(String* string, Throwable* e, ThreadContext* ctx) throw() 
{
}
 BTreeException::~BTreeException() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void BTreeException::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	Throwable::__releaseRegerences(true, ctx);
}
}}

