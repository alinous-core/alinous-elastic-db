#include "includes.h"


namespace alinous {namespace remote {namespace socket {





bool SocketConnectionPool::__init_done = __init_static_variables();
bool SocketConnectionPool::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"SocketConnectionPool", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 SocketConnectionPool::SocketConnectionPool(ISocketConnectionFactory* factory, ThreadContext* ctx) throw()  : IObject(ctx), connections(GCUtils<Stack<ISocketConnection> >::ins(this, (new(ctx) Stack<ISocketConnection>(ctx)), ctx, __FILEW__, __LINE__, L"")), lockObject(__GC_INS(this, (new(ctx) LockObject(ctx)), LockObject)), factory(nullptr), active(0)
{
	__GC_MV(this, &(this->factory), factory, ISocketConnectionFactory);
	this->active = true;
}
void SocketConnectionPool::__construct_impl(ISocketConnectionFactory* factory, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->factory), factory, ISocketConnectionFactory);
	this->active = true;
}
 SocketConnectionPool::~SocketConnectionPool() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void SocketConnectionPool::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"SocketConnectionPool", L"~SocketConnectionPool");
	__e_obj1.add(this->connections, this);
	connections = nullptr;
	__e_obj1.add(this->lockObject, this);
	lockObject = nullptr;
	__e_obj1.add(this->factory, this);
	factory = nullptr;
	if(!prepare){
		return;
	}
}
ISocketConnection* SocketConnectionPool::getConnection(ThreadContext* ctx)
{
	if(!active)
	{
		throw (new(ctx) AlinousException(ConstStr::getCNST_STR_3560(), ctx));
	}
	ISocketConnection* con = nullptr;
	{
		SynchronizedBlockObj __synchronized_2(this->lockObject, ctx);
		if(this->connections->isEmpty(ctx))
		{
			con = this->factory->newConnection(this, ctx);
		}
				else 
		{
			con = this->connections->pop(ctx);
		}
	}
	return con;
}
void SocketConnectionPool::returnConnection(ISocketConnection* con, ThreadContext* ctx) throw() 
{
	if(con == nullptr)
	{
		return;
	}
	{
		SynchronizedBlockObj __synchronized_2(this->lockObject, ctx);
		this->connections->push(con, ctx);
	}
}
void SocketConnectionPool::dispose(ThreadContext* ctx) throw() 
{
	this->active = false;
	{
		SynchronizedBlockObj __synchronized_2(this->lockObject, ctx);
		while(!this->connections->isEmpty(ctx))
		{
			ISocketConnection* con = this->connections->pop(ctx);
			con->shutdown(ctx);
			con->dispose(ctx);
		}
	}
}
}}}

