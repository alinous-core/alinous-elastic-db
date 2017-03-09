#include "include/global.h"


#include "alinous.remote.region.server.schema.strategy/UniqueCheckOperation.h"

namespace alinous {namespace remote {namespace region {namespace server {namespace schema {namespace strategy {





bool UniqueCheckOperation::__init_done = __init_static_variables();
bool UniqueCheckOperation::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"UniqueCheckOperation", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 UniqueCheckOperation::UniqueCheckOperation(ThreadContext* ctx) throw()  : IObject(ctx)
{
}
void UniqueCheckOperation::__construct_impl(ThreadContext* ctx) throw() 
{
}
 UniqueCheckOperation::~UniqueCheckOperation() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void UniqueCheckOperation::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
void UniqueCheckOperation::__cleanUp(ThreadContext* ctx){
}
}}}}}}

