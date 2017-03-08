#include "include/global.h"


#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime.engine.debugger/AlinousServerDebugHttpResponse.h"
#include "alinous.runtime.engine.debugger/IHttpAccessMethod.h"

namespace alinous {namespace runtime {namespace engine {namespace debugger {




bool IHttpAccessMethod::__init_done = __init_static_variables();
bool IHttpAccessMethod::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"IHttpAccessMethod", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 IHttpAccessMethod::IHttpAccessMethod(ThreadContext* ctx) throw()  : IObject(ctx)
{
}
void IHttpAccessMethod::__construct_impl(ThreadContext* ctx) throw() 
{
}
 IHttpAccessMethod::~IHttpAccessMethod() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void IHttpAccessMethod::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
void IHttpAccessMethod::__cleanUp(ThreadContext* ctx){
}
}}}}

