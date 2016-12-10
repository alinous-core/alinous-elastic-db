#include "includes.h"


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
ISocketConnection* MonitorClientConnectionFactory::newConnection(SocketConnectionPool* pool, ThreadContext* ctx) throw() 
{
	return (new(ctx) MonitorConnection(pool, this->info, ctx));
}
}}}}

