#include "include/global.h"


#include "alinous.remote.region.server.scan/IScanWorker.h"
#include "alinous.remote.region.server.scan/FullScanWorker.h"

namespace alinous {namespace remote {namespace region {namespace server {namespace scan {





bool FullScanWorker::__init_done = __init_static_variables();
bool FullScanWorker::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"FullScanWorker", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 FullScanWorker::FullScanWorker(ThreadContext* ctx) throw()  : IObject(ctx), IScanWorker(ctx)
{
}
void FullScanWorker::__construct_impl(ThreadContext* ctx) throw() 
{
}
 FullScanWorker::~FullScanWorker() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void FullScanWorker::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
void FullScanWorker::__cleanUp(ThreadContext* ctx){
}
}}}}}

