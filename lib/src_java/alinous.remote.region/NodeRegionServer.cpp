#include "includes.h"


namespace alinous {namespace remote {namespace region {





String* NodeRegionServer::THREAD_NAME = ConstStr::getCNST_STR_3495();
bool NodeRegionServer::__init_done = __init_static_variables();
bool NodeRegionServer::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"NodeRegionServer", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 NodeRegionServer::NodeRegionServer(int port, int maxthread, ThreadContext* ctx) throw()  : IObject(ctx), port(0), maxthread(0), refs(nullptr), socketServer(nullptr), monitorConnectionPool(nullptr)
{
	this->port = port;
	this->maxthread = maxthread;
	__GC_MV(this, &(this->refs), (new(ctx) NodeReferenceManager(ctx)), NodeReferenceManager);
}
void NodeRegionServer::__construct_impl(int port, int maxthread, ThreadContext* ctx) throw() 
{
	this->port = port;
	this->maxthread = maxthread;
	__GC_MV(this, &(this->refs), (new(ctx) NodeReferenceManager(ctx)), NodeReferenceManager);
}
 NodeRegionServer::~NodeRegionServer() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void NodeRegionServer::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"NodeRegionServer", L"~NodeRegionServer");
	__e_obj1.add(this->refs, this);
	refs = nullptr;
	__e_obj1.add(this->socketServer, this);
	socketServer = nullptr;
	__e_obj1.add(this->monitorConnectionPool, this);
	monitorConnectionPool = nullptr;
	if(!prepare){
		return;
	}
}
void NodeRegionServer::initNodes(RegionsServer* srvconf, ThreadContext* ctx)
{
	MonitorRef* monRef = srvconf->getMonitorRef(ctx);
	initMonitorRef(monRef, ctx);
	syncNodes(ctx);
}
void NodeRegionServer::syncNodes(ThreadContext* ctx)
{
	GetRegionNodeInfoCommand* cmd = (new(ctx) GetRegionNodeInfoCommand(ctx));
	ISocketConnection* con = nullptr;
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			this->monitorConnectionPool->returnConnection(con, ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			con = this->monitorConnectionPool->getConnection(ctx);
			AlinousSocket* socket = con->getSocket(ctx);
			cmd->sendCommand(socket, ctx);
		}
		catch(...){throw;}
	}
}
void NodeRegionServer::start(ISystemLog* logger, ThreadContext* ctx) throw() 
{
	NodeRegionResponceActionFactory* factory = (new(ctx) NodeRegionResponceActionFactory(this, ctx));
	__GC_MV(this, &(this->socketServer), (new(ctx) SocketServer(this->port, logger, factory, ctx)), SocketServer);
	this->socketServer->start(this->maxthread, NodeRegionServer::THREAD_NAME, ctx);
}
void NodeRegionServer::dispose(ThreadContext* ctx) throw() 
{
	this->socketServer->dispose(ctx);
	if(this->monitorConnectionPool != nullptr)
	{
		this->monitorConnectionPool->dispose(ctx);
	}
}
NodeReferenceManager* NodeRegionServer::getRefs(ThreadContext* ctx) throw() 
{
	return refs;
}
void NodeRegionServer::initMonitorRef(MonitorRef* monRef, ThreadContext* ctx) throw() 
{
	MonitorConnectionInfo* monInfo = (new(ctx) MonitorConnectionInfo(monRef->getHost(ctx), monRef->getPort(ctx), ctx));
	MonitorClientConnectionFactory* factory = (new(ctx) MonitorClientConnectionFactory(monInfo, ctx));
	__GC_MV(this, &(this->monitorConnectionPool), (new(ctx) SocketConnectionPool(factory, ctx)), SocketConnectionPool);
}
}}}

