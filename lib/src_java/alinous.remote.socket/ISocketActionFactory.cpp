#include "include/global.h"


#include "alinous.runtime.parallel/IThreadAction.h"
#include "alinous.remote.socket/SocketServer.h"
#include "alinous.remote.socket/ISocketActionFactory.h"

namespace alinous {namespace remote {namespace socket {




bool ISocketActionFactory::__init_done = __init_static_variables();
bool ISocketActionFactory::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ISocketActionFactory", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ISocketActionFactory::ISocketActionFactory(ThreadContext* ctx) throw()  : IObject(ctx)
{
}
void ISocketActionFactory::__construct_impl(ThreadContext* ctx) throw() 
{
}
 ISocketActionFactory::~ISocketActionFactory() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ISocketActionFactory::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
void ISocketActionFactory::__cleanUp(ThreadContext* ctx){
}
}}}

