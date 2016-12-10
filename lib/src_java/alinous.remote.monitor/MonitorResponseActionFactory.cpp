#include "includes.h"


namespace alinous {namespace remote {namespace monitor {





bool MonitorResponseActionFactory::__init_done = __init_static_variables();
bool MonitorResponseActionFactory::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"MonitorResponseActionFactory", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 MonitorResponseActionFactory::MonitorResponseActionFactory(TransactionMonitorServer* monitorServer, ThreadContext* ctx) throw()  : IObject(ctx), ISocketActionFactory(ctx), monitorServer(nullptr)
{
	__GC_MV(this, &(this->monitorServer), monitorServer, TransactionMonitorServer);
}
void MonitorResponseActionFactory::__construct_impl(TransactionMonitorServer* monitorServer, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->monitorServer), monitorServer, TransactionMonitorServer);
}
 MonitorResponseActionFactory::~MonitorResponseActionFactory() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void MonitorResponseActionFactory::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"MonitorResponseActionFactory", L"~MonitorResponseActionFactory");
	__e_obj1.add(this->monitorServer, this);
	monitorServer = nullptr;
	if(!prepare){
		return;
	}
}
IThreadAction* MonitorResponseActionFactory::getAction(Socket* socket, SocketServer* server, ThreadContext* ctx) throw() 
{
	return (new(ctx) MonitorResponceAction(socket, server, ctx));
}
TransactionMonitorServer* MonitorResponseActionFactory::getMonitorServer(ThreadContext* ctx) throw() 
{
	return monitorServer;
}
}}}

