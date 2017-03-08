#include "include/global.h"


#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.remote.socket/ISocketConnection.h"
#include "alinous.remote.socket/SocketConnectionPool.h"
#include "alinous.remote.socket/ISocketConnectionFactory.h"
#include "alinous.remote.monitor.client/MonitorConnectionInfo.h"
#include "alinous.remote.monitor.client/MonitorConnection.h"
#include "alinous.remote.monitor.client/MonitorClientConnectionFactory.h"

namespace alinous {namespace remote {namespace monitor {namespace client {





bool MonitorClientConnectionFactory::__init_done = __init_static_variables();
bool MonitorClientConnectionFactory::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"MonitorClientConnectionFactory", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 MonitorClientConnectionFactory::MonitorClientConnectionFactory(MonitorConnectionInfo* info, ThreadContext* ctx) throw()  : IObject(ctx), ISocketConnectionFactory(ctx), info(nullptr)
{
	__GC_MV(this, &(this->info), info, MonitorConnectionInfo);
}
void MonitorClientConnectionFactory::__construct_impl(MonitorConnectionInfo* info, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->info), info, MonitorConnectionInfo);
}
 MonitorClientConnectionFactory::~MonitorClientConnectionFactory() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void MonitorClientConnectionFactory::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"MonitorClientConnectionFactory", L"~MonitorClientConnectionFactory");
	__e_obj1.add(this->info, this);
	info = nullptr;
	if(!prepare){
		return;
	}
}
ISocketConnection* MonitorClientConnectionFactory::newConnection(SocketConnectionPool* pool, ThreadContext* ctx)
{
	MonitorConnection* con = (new(ctx) MonitorConnection(pool, this->info, ctx));
	con->connect(ctx);
	return con;
}
void MonitorClientConnectionFactory::__cleanUp(ThreadContext* ctx){
}
}}}}

