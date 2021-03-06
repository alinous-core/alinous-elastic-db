#include "include/global.h"


#include "alinous.runtime.parallel/IThreadAction.h"
#include "alinous.remote.socket/SocketServer.h"
#include "alinous.remote.socket/ISocketActionFactory.h"
#include "alinous.remote.region.server/NodeRegionServer.h"
#include "alinous.remote.region.server/NodeRegionResponceAction.h"
#include "alinous.remote.region.server/NodeRegionResponceActionFactory.h"

namespace alinous {namespace remote {namespace region {namespace server {





bool NodeRegionResponceActionFactory::__init_done = __init_static_variables();
bool NodeRegionResponceActionFactory::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"NodeRegionResponceActionFactory", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 NodeRegionResponceActionFactory::NodeRegionResponceActionFactory(NodeRegionServer* storageNodeRegionServer, ThreadContext* ctx) throw()  : IObject(ctx), ISocketActionFactory(ctx), storageNodeRegionServer(nullptr)
{
	__GC_MV(this, &(this->storageNodeRegionServer), storageNodeRegionServer, NodeRegionServer);
}
void NodeRegionResponceActionFactory::__construct_impl(NodeRegionServer* storageNodeRegionServer, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->storageNodeRegionServer), storageNodeRegionServer, NodeRegionServer);
}
 NodeRegionResponceActionFactory::~NodeRegionResponceActionFactory() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void NodeRegionResponceActionFactory::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"NodeRegionResponceActionFactory", L"~NodeRegionResponceActionFactory");
	__e_obj1.add(this->storageNodeRegionServer, this);
	storageNodeRegionServer = nullptr;
	if(!prepare){
		return;
	}
}
NodeRegionServer* NodeRegionResponceActionFactory::getStorageNodeRegionServer(ThreadContext* ctx) throw() 
{
	return storageNodeRegionServer;
}
IThreadAction* NodeRegionResponceActionFactory::getAction(Socket* socket, SocketServer* server, ThreadContext* ctx) throw() 
{
	return (new(ctx) NodeRegionResponceAction(this->storageNodeRegionServer, socket, server, ctx));
}
void NodeRegionResponceActionFactory::__cleanUp(ThreadContext* ctx){
}
}}}}

