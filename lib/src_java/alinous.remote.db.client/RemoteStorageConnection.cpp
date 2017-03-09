#include "include/global.h"


#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.db/AlinousDbException.h"
#include "java.io/FilterOutputStream.h"
#include "java.io/BufferedOutputStream.h"
#include "alinous.remote.db/RemoteTableStorageServer.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.db.client.command/AbstractRemoteStorageCommand.h"
#include "alinous.remote.db.client.command/FinishRemoteStorageConnectionCommand.h"
#include "alinous.remote.db.client.command/RemoteStorageConnectCommand.h"
#include "alinous.remote.db.client.command/RemoteStorageCommandReader.h"
#include "alinous.remote.socket/ISocketConnection.h"
#include "alinous.remote.socket/SocketConnectionPool.h"
#include "alinous.remote.db.client/RemoteStorageConnectionInfo.h"
#include "alinous.remote.db.client/RemoteStorageConnection.h"

namespace alinous {namespace remote {namespace db {namespace client {





bool RemoteStorageConnection::__init_done = __init_static_variables();
bool RemoteStorageConnection::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"RemoteStorageConnection", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 RemoteStorageConnection::RemoteStorageConnection(SocketConnectionPool* pool, RemoteStorageConnectionInfo* info, ThreadContext* ctx) throw()  : IObject(ctx), ISocketConnection(ctx), pool(nullptr), info(nullptr), socket(nullptr)
{
	__GC_MV(this, &(this->pool), pool, SocketConnectionPool);
	__GC_MV(this, &(this->info), info, RemoteStorageConnectionInfo);
}
void RemoteStorageConnection::__construct_impl(SocketConnectionPool* pool, RemoteStorageConnectionInfo* info, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->pool), pool, SocketConnectionPool);
	__GC_MV(this, &(this->info), info, RemoteStorageConnectionInfo);
}
 RemoteStorageConnection::~RemoteStorageConnection() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void RemoteStorageConnection::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"RemoteStorageConnection", L"~RemoteStorageConnection");
	__e_obj1.add(this->pool, this);
	pool = nullptr;
	__e_obj1.add(this->info, this);
	info = nullptr;
	__e_obj1.add(this->socket, this);
	socket = nullptr;
	if(!prepare){
		return;
	}
}
void RemoteStorageConnection::connect(ThreadContext* ctx)
{
	__GC_MV(this, &(this->socket), (new(ctx) AlinousSocket(info->getHost(ctx), info->getPort(ctx), ctx))->init(ctx), AlinousSocket);
	RemoteStorageConnectCommand* cmd = (new(ctx) RemoteStorageConnectCommand(ctx));
	AbstractRemoteStorageCommand* retcmd = cmd->sendCommand(this->socket, ctx);
	if(retcmd->getType(ctx) != AbstractRemoteStorageCommand::TYPE_CONNECT)
	{
		throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_3582(), ctx));
	}
	cmd = static_cast<RemoteStorageConnectCommand*>(retcmd);
	if(!cmd->isConnected(ctx))
	{
		throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_3582(), ctx));
	}
}
void RemoteStorageConnection::close(ThreadContext* ctx) throw() 
{
	this->pool->returnConnection(this, ctx);
}
void RemoteStorageConnection::dispose(ThreadContext* ctx) throw() 
{
	{
		try
		{
			this->socket->close(ctx);
		}
		catch(IOException* e)
		{
			e->printStackTrace(ctx);
		}
	}
}
AlinousSocket* RemoteStorageConnection::getSocket(ThreadContext* ctx) throw() 
{
	return socket;
}
void RemoteStorageConnection::shutdown(ThreadContext* ctx) throw() 
{
	FinishRemoteStorageConnectionCommand* cmd = (new(ctx) FinishRemoteStorageConnectionCommand(ctx));
	{
		try
		{
			cmd->sendCommand(this->socket, ctx);
		}
		catch(IOException* e)
		{
			e->printStackTrace(ctx);
		}
		catch(AlinousException* e)
		{
			e->printStackTrace(ctx);
		}
	}
}
void RemoteStorageConnection::__cleanUp(ThreadContext* ctx){
}
}}}}

