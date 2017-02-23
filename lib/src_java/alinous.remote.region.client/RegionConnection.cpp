#include "includes.h"


namespace alinous {namespace remote {namespace region {namespace client {





bool RegionConnection::__init_done = __init_static_variables();
bool RegionConnection::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"RegionConnection", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 RegionConnection::RegionConnection(SocketConnectionPool* pool, RegionConnectionInfo* info, ThreadContext* ctx) throw()  : IObject(ctx), ISocketConnection(ctx), pool(nullptr), info(nullptr), socket(nullptr)
{
	__GC_MV(this, &(this->pool), pool, SocketConnectionPool);
	__GC_MV(this, &(this->info), info, RegionConnectionInfo);
}
void RegionConnection::__construct_impl(SocketConnectionPool* pool, RegionConnectionInfo* info, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->pool), pool, SocketConnectionPool);
	__GC_MV(this, &(this->info), info, RegionConnectionInfo);
}
 RegionConnection::~RegionConnection() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void RegionConnection::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"RegionConnection", L"~RegionConnection");
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
void RegionConnection::connect(ThreadContext* ctx)
{
	__GC_MV(this, &(this->socket), (new(ctx) AlinousSocket(info->getHost(ctx), info->getPort(ctx), ctx))->init(ctx), AlinousSocket);
	NodeRegionConnectCommand* cmd = (new(ctx) NodeRegionConnectCommand(ctx));
	AbstractNodeRegionCommand* retcmd = cmd->sendCommand(this->socket, ctx);
	if(retcmd->getType(ctx) != AbstractNodeRegionCommand::TYPE_CONNECT)
	{
		throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_3571(), ctx));
	}
	cmd = static_cast<NodeRegionConnectCommand*>(retcmd);
	if(!cmd->isConnected(ctx))
	{
		throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_3571(), ctx));
	}
}
void RegionConnection::close(ThreadContext* ctx) throw() 
{
	this->pool->returnConnection(this, ctx);
}
void RegionConnection::dispose(ThreadContext* ctx) throw() 
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
AlinousSocket* RegionConnection::getSocket(ThreadContext* ctx) throw() 
{
	return socket;
}
void RegionConnection::shutdown(ThreadContext* ctx) throw() 
{
	NodeRegionFinishConnectionCommand* cmd = (new(ctx) NodeRegionFinishConnectionCommand(ctx));
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
}}}}

