#include "includes.h"


namespace alinous {namespace remote {namespace db {





String* RemoteTableStorageServer::THREAD_NAME = ConstStr::getCNST_STR_3474();
bool RemoteTableStorageServer::__init_done = __init_static_variables();
bool RemoteTableStorageServer::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"RemoteTableStorageServer", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 RemoteTableStorageServer::RemoteTableStorageServer(int port, int maxthread, ThreadContext* ctx) throw()  : IObject(ctx), port(0), maxthread(0), socketServer(nullptr)
{
	this->port = port;
	this->maxthread = maxthread;
}
void RemoteTableStorageServer::__construct_impl(int port, int maxthread, ThreadContext* ctx) throw() 
{
	this->port = port;
	this->maxthread = maxthread;
}
 RemoteTableStorageServer::~RemoteTableStorageServer() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void RemoteTableStorageServer::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"RemoteTableStorageServer", L"~RemoteTableStorageServer");
	__e_obj1.add(this->socketServer, this);
	socketServer = nullptr;
	if(!prepare){
		return;
	}
}
void RemoteTableStorageServer::start(ISystemLog* logger, ThreadContext* ctx) throw() 
{
	RemoteStorageResponceActionFactory* factory = (new(ctx) RemoteStorageResponceActionFactory(this, ctx));
	__GC_MV(this, &(this->socketServer), (new(ctx) SocketServer(this->port, logger, factory, ctx)), SocketServer);
	this->socketServer->start(this->maxthread, RemoteTableStorageServer::THREAD_NAME, ctx);
}
void RemoteTableStorageServer::dispose(ThreadContext* ctx) throw() 
{
	this->socketServer->dispose(ctx);
}
}}}

