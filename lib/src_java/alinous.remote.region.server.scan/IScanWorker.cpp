#include "include/global.h"


#include "alinous.remote.region.server.scan/IScanWorker.h"

namespace alinous {namespace remote {namespace region {namespace server {namespace scan {




bool IScanWorker::__init_done = __init_static_variables();
bool IScanWorker::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"IScanWorker", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 IScanWorker::IScanWorker(ThreadContext* ctx) throw()  : IObject(ctx)
{
}
void IScanWorker::__construct_impl(ThreadContext* ctx) throw() 
{
}
 IScanWorker::~IScanWorker() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void IScanWorker::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
void IScanWorker::__cleanUp(ThreadContext* ctx){
}
}}}}}

