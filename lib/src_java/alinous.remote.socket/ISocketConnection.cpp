#include "include/global.h"


#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.remote.socket/ISocketConnection.h"

namespace alinous {namespace remote {namespace socket {




bool ISocketConnection::__init_done = __init_static_variables();
bool ISocketConnection::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ISocketConnection", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ISocketConnection::ISocketConnection(ThreadContext* ctx) throw()  : IObject(ctx)
{
}
void ISocketConnection::__construct_impl(ThreadContext* ctx) throw() 
{
}
 ISocketConnection::~ISocketConnection() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ISocketConnection::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
void ISocketConnection::__cleanUp(ThreadContext* ctx){
}
}}}

