#include "includes.h"


namespace alinous {namespace remote {namespace monitor {





String* TransactionMonitorServer::THREAD_NAME = ConstStr::getCNST_STR_3470();
bool TransactionMonitorServer::__init_done = __init_static_variables();
bool TransactionMonitorServer::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"TransactionMonitorServer", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 TransactionMonitorServer::TransactionMonitorServer(int port, int maxthread, ThreadContext* ctx) throw()  : IObject(ctx), port(0), lastCommitId(0), lastOid(0), maxthread(0), socketServer(nullptr)
{
	this->port = port;
	this->maxthread = maxthread;
}
void TransactionMonitorServer::__construct_impl(int port, int maxthread, ThreadContext* ctx) throw() 
{
	this->port = port;
	this->maxthread = maxthread;
}
 TransactionMonitorServer::~TransactionMonitorServer() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void TransactionMonitorServer::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"TransactionMonitorServer", L"~TransactionMonitorServer");
	__e_obj1.add(this->socketServer, this);
	socketServer = nullptr;
	if(!prepare){
		return;
	}
}
void TransactionMonitorServer::start(ISystemLog* logger, ThreadContext* ctx) throw() 
{
	MonitorResponseActionFactory* factory = (new(ctx) MonitorResponseActionFactory(this, ctx));
	__GC_MV(this, &(this->socketServer), (new(ctx) SocketServer(this->port, logger, factory, ctx)), SocketServer);
	this->socketServer->start(this->maxthread, TransactionMonitorServer::THREAD_NAME, ctx);
}
void TransactionMonitorServer::dispose(ThreadContext* ctx) throw() 
{
	this->socketServer->dispose(ctx);
}
int TransactionMonitorServer::getPort(ThreadContext* ctx) throw() 
{
	return port;
}
long long TransactionMonitorServer::getNextCommitId(ThreadContext* ctx) throw() 
{
	this->lastCommitId ++ ;
	return lastCommitId;
}
long long TransactionMonitorServer::getNextOid(ThreadContext* ctx) throw() 
{
	this->lastOid ++ ;
	return lastOid;
}
}}}

