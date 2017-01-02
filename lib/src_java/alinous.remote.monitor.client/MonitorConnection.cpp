#include "includes.h"


namespace alinous {namespace remote {namespace monitor {namespace client {





bool MonitorConnection::__init_done = __init_static_variables();
bool MonitorConnection::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"MonitorConnection", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 MonitorConnection::MonitorConnection(SocketConnectionPool* pool, MonitorConnectionInfo* info, ThreadContext* ctx) throw()  : IObject(ctx), ISocketConnection(ctx), pool(nullptr), info(nullptr), socket(nullptr)
{
	__GC_MV(this, &(this->pool), pool, SocketConnectionPool);
	__GC_MV(this, &(this->info), info, MonitorConnectionInfo);
}
void MonitorConnection::__construct_impl(SocketConnectionPool* pool, MonitorConnectionInfo* info, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->pool), pool, SocketConnectionPool);
	__GC_MV(this, &(this->info), info, MonitorConnectionInfo);
}
 MonitorConnection::~MonitorConnection() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void MonitorConnection::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"MonitorConnection", L"~MonitorConnection");
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
void MonitorConnection::connect(ThreadContext* ctx)
{
	__GC_MV(this, &(this->socket), (new(ctx) AlinousSocket(info->getHost(ctx), info->getPort(ctx), ctx))->init(ctx), AlinousSocket);
	MonitorConnectCommand* cmd = (new(ctx) MonitorConnectCommand(ctx));
	AbstractMonitorCommand* retcmd = cmd->sendCommand(this->socket, ctx);
	if(retcmd->getType(ctx) != AbstractMonitorCommand::TYPE_CONNECT)
	{
		throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_3486(), ctx));
	}
	cmd = static_cast<MonitorConnectCommand*>(retcmd);
	if(!cmd->isConnected(ctx))
	{
		throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_3486(), ctx));
	}
}
AlinousSocket* MonitorConnection::getSocket(ThreadContext* ctx) throw() 
{
	return socket;
}
void MonitorConnection::close(ThreadContext* ctx) throw() 
{
	this->pool->returnConnection(this, ctx);
}
void MonitorConnection::dispose(ThreadContext* ctx) throw() 
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
}}}}

