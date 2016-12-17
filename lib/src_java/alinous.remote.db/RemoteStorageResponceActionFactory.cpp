#include "includes.h"


namespace alinous {namespace remote {namespace db {





bool RemoteStorageResponceActionFactory::__init_done = __init_static_variables();
bool RemoteStorageResponceActionFactory::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"RemoteStorageResponceActionFactory", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 RemoteStorageResponceActionFactory::RemoteStorageResponceActionFactory(RemoteTableStorageServer* remoteTableStorageServer, ThreadContext* ctx) throw()  : IObject(ctx), ISocketActionFactory(ctx), remoteTableStorageServer(nullptr)
{
	__GC_MV(this, &(this->remoteTableStorageServer), remoteTableStorageServer, RemoteTableStorageServer);
}
void RemoteStorageResponceActionFactory::__construct_impl(RemoteTableStorageServer* remoteTableStorageServer, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->remoteTableStorageServer), remoteTableStorageServer, RemoteTableStorageServer);
}
 RemoteStorageResponceActionFactory::~RemoteStorageResponceActionFactory() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void RemoteStorageResponceActionFactory::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"RemoteStorageResponceActionFactory", L"~RemoteStorageResponceActionFactory");
	__e_obj1.add(this->remoteTableStorageServer, this);
	remoteTableStorageServer = nullptr;
	if(!prepare){
		return;
	}
}
RemoteTableStorageServer* RemoteStorageResponceActionFactory::getRemoteTableStorageServer(ThreadContext* ctx) throw() 
{
	return remoteTableStorageServer;
}
IThreadAction* RemoteStorageResponceActionFactory::getAction(Socket* socket, SocketServer* server, ThreadContext* ctx) throw() 
{
	return (new(ctx) RemoteStorageResponceAction(this->remoteTableStorageServer, socket, server, ctx));
}
}}}

