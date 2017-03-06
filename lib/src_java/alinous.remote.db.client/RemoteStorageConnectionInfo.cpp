#include "include/global.h"


#include "alinous.remote.socket/ISocketConnection.h"
#include "alinous.remote.socket/ISocketConnectionFactory.h"
#include "alinous.remote.socket/SocketConnectionPool.h"
#include "alinous.remote.db.client/RemoteStorageConnectionInfo.h"
#include "alinous.remote.db.client/RemoteStorageConnection.h"
#include "alinous.remote.db.client/RemoteStorageClientConnectionFactory.h"
#include "alinous.remote.db.client/RemoteTableStorageClient.h"

namespace alinous {namespace remote {namespace db {namespace client {





bool RemoteStorageConnectionInfo::__init_done = __init_static_variables();
bool RemoteStorageConnectionInfo::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"RemoteStorageConnectionInfo", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 RemoteStorageConnectionInfo::RemoteStorageConnectionInfo(String* host, int port, ThreadContext* ctx) throw()  : IObject(ctx), host(nullptr), port(0)
{
	__GC_MV(this, &(this->host), host, String);
	this->port = port;
}
void RemoteStorageConnectionInfo::__construct_impl(String* host, int port, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->host), host, String);
	this->port = port;
}
 RemoteStorageConnectionInfo::~RemoteStorageConnectionInfo() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void RemoteStorageConnectionInfo::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"RemoteStorageConnectionInfo", L"~RemoteStorageConnectionInfo");
	__e_obj1.add(this->host, this);
	host = nullptr;
	if(!prepare){
		return;
	}
}
String* RemoteStorageConnectionInfo::getHost(ThreadContext* ctx) throw() 
{
	return host;
}
void RemoteStorageConnectionInfo::setHost(String* host, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->host), host, String);
}
int RemoteStorageConnectionInfo::getPort(ThreadContext* ctx) throw() 
{
	return port;
}
void RemoteStorageConnectionInfo::setPort(int port, ThreadContext* ctx) throw() 
{
	this->port = port;
}
void RemoteStorageConnectionInfo::__cleanUp(ThreadContext* ctx){
}
}}}}

