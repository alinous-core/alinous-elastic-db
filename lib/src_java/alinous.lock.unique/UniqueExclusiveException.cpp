#include "include/global.h"


#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.db/AlinousDbException.h"
#include "alinous.lock.unique/UniqueExclusiveException.h"

namespace alinous {namespace lock {namespace unique {





constexpr const long long UniqueExclusiveException::serialVersionUID;
bool UniqueExclusiveException::__init_done = __init_static_variables();
bool UniqueExclusiveException::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"UniqueExclusiveException", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 UniqueExclusiveException::UniqueExclusiveException(String* msg, Throwable* e, ThreadContext* ctx) throw()  : IObject(ctx), AlinousDbException(msg, e, ctx)
{
}
void UniqueExclusiveException::__construct_impl(String* msg, Throwable* e, ThreadContext* ctx) throw() 
{
}
 UniqueExclusiveException::UniqueExclusiveException(String* msg, ThreadContext* ctx) throw()  : IObject(ctx), AlinousDbException(msg, ctx)
{
}
void UniqueExclusiveException::__construct_impl(String* msg, ThreadContext* ctx) throw() 
{
}
 UniqueExclusiveException::~UniqueExclusiveException() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void UniqueExclusiveException::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	AlinousDbException::__releaseRegerences(true, ctx);
}
void UniqueExclusiveException::__cleanUp(ThreadContext* ctx){
}
}}}

