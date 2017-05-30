#include "include/global.h"


#include "alinous.db.trx.scan/ITableTargetScanner.h"
#include "alinous.remote.region.client.scan/AbstractRemoteScanner.h"

namespace alinous {namespace remote {namespace region {namespace client {namespace scan {





bool AbstractRemoteScanner::__init_done = __init_static_variables();
bool AbstractRemoteScanner::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AbstractRemoteScanner", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AbstractRemoteScanner::AbstractRemoteScanner(ThreadContext* ctx) throw()  : IObject(ctx), ITableTargetScanner(ctx)
{
}
void AbstractRemoteScanner::__construct_impl(ThreadContext* ctx) throw() 
{
}
 AbstractRemoteScanner::~AbstractRemoteScanner() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AbstractRemoteScanner::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
void AbstractRemoteScanner::__cleanUp(ThreadContext* ctx){
}
}}}}}

