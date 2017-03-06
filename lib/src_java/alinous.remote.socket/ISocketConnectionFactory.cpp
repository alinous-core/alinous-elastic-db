#include "include/global.h"


#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.lock/LockObject.h"
#include "alinous.runtime.parallel/ThreadPool.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.system/ISystemLog.h"
#include "alinous.remote.socket/ISocketActionFactory.h"
#include "alinous.remote.socket/SocketServer.h"
#include "alinous.remote.socket/ISocketConnection.h"
#include "alinous.remote.socket/ISocketConnectionFactory.h"
#include "alinous.remote.socket/SocketConnectionPool.h"
#include "alinous.remote.socket/NetworkBinalyUtils.h"
#include "alinous.remote.socket/ICommandData.h"

namespace alinous {namespace remote {namespace socket {




bool ISocketConnectionFactory::__init_done = __init_static_variables();
bool ISocketConnectionFactory::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ISocketConnectionFactory", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ISocketConnectionFactory::ISocketConnectionFactory(ThreadContext* ctx) throw()  : IObject(ctx)
{
}
void ISocketConnectionFactory::__construct_impl(ThreadContext* ctx) throw() 
{
}
 ISocketConnectionFactory::~ISocketConnectionFactory() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ISocketConnectionFactory::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
void ISocketConnectionFactory::__cleanUp(ThreadContext* ctx){
}
}}}

