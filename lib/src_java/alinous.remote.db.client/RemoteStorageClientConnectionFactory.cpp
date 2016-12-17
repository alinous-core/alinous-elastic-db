#include "includes.h"


namespace alinous {namespace remote {namespace db {namespace client {





bool RemoteStorageClientConnectionFactory::__init_done = __init_static_variables();
bool RemoteStorageClientConnectionFactory::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"RemoteStorageClientConnectionFactory", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 RemoteStorageClientConnectionFactory::RemoteStorageClientConnectionFactory(RemoteStorageConnectionInfo* info, ThreadContext* ctx) throw()  : IObject(ctx), ISocketConnectionFactory(ctx), info(nullptr)
{
	__GC_MV(this, &(this->info), info, RemoteStorageConnectionInfo);
}
void RemoteStorageClientConnectionFactory::__construct_impl(RemoteStorageConnectionInfo* info, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->info), info, RemoteStorageConnectionInfo);
}
 RemoteStorageClientConnectionFactory::~RemoteStorageClientConnectionFactory() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void RemoteStorageClientConnectionFactory::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"RemoteStorageClientConnectionFactory", L"~RemoteStorageClientConnectionFactory");
	__e_obj1.add(this->info, this);
	info = nullptr;
	if(!prepare){
		return;
	}
}
ISocketConnection* RemoteStorageClientConnectionFactory::newConnection(SocketConnectionPool* pool, ThreadContext* ctx)
{
	RemoteStorageConnection* con = (new(ctx) RemoteStorageConnection(pool, this->info, ctx));
	con->connect(ctx);
	return con;
}
}}}}

