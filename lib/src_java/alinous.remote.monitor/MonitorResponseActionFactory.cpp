#include "include/global.h"


#include "alinous.runtime.parallel/IThreadAction.h"
#include "alinous.lock/LockObject.h"
#include "alinous.remote.socket/SocketServer.h"
#include "alinous.remote.socket/ISocketActionFactory.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.remote.monitor/NodeInfo.h"
#include "alinous.remote.monitor/RegionNodeInfo.h"
#include "alinous.remote.monitor.client.command.data/RegionInfoData.h"
#include "alinous.system.config.remote/Monitor.h"
#include "alinous.remote.monitor/RegionNodeInfoManager.h"
#include "alinous.remote.monitor/TransactionMonitorServer.h"
#include "java.io/FilterInputStream.h"
#include "java.io/BufferedInputStream.h"
#include "java.io/FilterOutputStream.h"
#include "java.io/BufferedOutputStream.h"
#include "alinous.remote.monitor.client.command/AbstractMonitorCommand.h"
#include "alinous.remote.monitor/MonitorResponceAction.h"
#include "alinous.remote.monitor/MonitorResponseActionFactory.h"

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
	return (new(ctx) MonitorResponceAction(this->monitorServer, socket, server, ctx));
}
TransactionMonitorServer* MonitorResponseActionFactory::getMonitorServer(ThreadContext* ctx) throw() 
{
	return monitorServer;
}
void MonitorResponseActionFactory::__cleanUp(ThreadContext* ctx){
}
}}}

