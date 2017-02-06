#include "includes.h"


namespace alinous {namespace remote {namespace socket {





bool SocketServer::__init_done = __init_static_variables();
bool SocketServer::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"SocketServer", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 SocketServer::SocketServer(int port, ISystemLog* logger, ISocketActionFactory* factory, ThreadContext* ctx) throw()  : IObject(ctx), Runnable(ctx), port(0), serverSocket(nullptr), threadPool(nullptr), thread(nullptr), running(0), logger(nullptr), factory(nullptr), refLock(__GC_INS(this, (new(ctx) LockObject(ctx)), LockObject)), refs(0)
{
	this->running = false;
	this->port = port;
	__GC_MV(this, &(this->logger), logger, ISystemLog);
	__GC_MV(this, &(this->factory), factory, ISocketActionFactory);
}
void SocketServer::__construct_impl(int port, ISystemLog* logger, ISocketActionFactory* factory, ThreadContext* ctx) throw() 
{
	this->running = false;
	this->port = port;
	__GC_MV(this, &(this->logger), logger, ISystemLog);
	__GC_MV(this, &(this->factory), factory, ISocketActionFactory);
}
 SocketServer::~SocketServer() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void SocketServer::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"SocketServer", L"~SocketServer");
	__e_obj1.add(this->serverSocket, this);
	serverSocket = nullptr;
	__e_obj1.add(this->threadPool, this);
	threadPool = nullptr;
	__e_obj1.add(this->thread, this);
	thread = nullptr;
	__e_obj1.add(this->logger, this);
	logger = nullptr;
	__e_obj1.add(this->factory, this);
	factory = nullptr;
	__e_obj1.add(this->refLock, this);
	refLock = nullptr;
	if(!prepare){
		return;
	}
}
void SocketServer::start(int maxthread, String* threadName, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->threadPool), (new(ctx) ThreadPool(maxthread, threadName, ctx)), ThreadPool);
	this->running = false;
	__GC_MV(this, &(this->thread), (new(ctx) Thread(this, ctx)), Thread);
	this->thread->start(ctx);
	while(!this->running)
	{
		{
			try
			{
				Thread::sleep(100, ctx);
			}
			catch(InterruptedException* e)
			{
				e->printStackTrace(ctx);
			}
		}
	}
}
void SocketServer::dispose(ThreadContext* ctx) throw() 
{
	this->running = false;
	AlinousSocket* socket = (new(ctx) AlinousSocket(ConstStr::getCNST_STR_1179(), this->port, ctx));
	{
		try
		{
			socket->init(ctx);
			TerminateCommand* cmd = (new(ctx) TerminateCommand(ctx));
			cmd->sendCommand(socket, ctx);
			socket->close(ctx);
		}
		catch(IOException* e)
		{
			e->printStackTrace(ctx);
			this->logger->logError(e, ctx);
		}
		catch(AlinousException* e)
		{
			e->printStackTrace(ctx);
			this->logger->logError(e, ctx);
		}
	}
	{
		try
		{
			this->thread->join(ctx);
		}
		catch(InterruptedException* e)
		{
			e->printStackTrace(ctx);
			this->logger->logError(e, ctx);
		}
	}
	this->threadPool->dispose(ctx);
}
void SocketServer::run(ThreadContext* ctx) throw() 
{
	bool binded = false;
	int retry = 0;
	while(!binded)
	{
		{
			try
			{
				__GC_MV(this, &(this->serverSocket), (new(ctx) AlinousServerSocket(this->port, ctx))->init(ctx), AlinousServerSocket);
				binded = true;
			}
			catch(Throwable* e)
			{
				if(retry > 200)
				{
					return;
				}
				retry ++ ;
				System::out->println(ConstStr::getCNST_STR_3528(), ctx);
				{
					try
					{
						Thread::sleep(1500, ctx);
					}
					catch(InterruptedException* ie)
					{
						ie->printStackTrace(ctx);
					}
				}
			}
		}
	}
	this->running = true;
	while(this->running)
	{
		handleRequest(ctx);
	}
	while(getRefs(ctx) > 0)
	{
		{
			try
			{
				Thread::sleep(300, ctx);
			}
			catch(InterruptedException* e)
			{
				e->printStackTrace(ctx);
			}
		}
	}
}
void SocketServer::dec(ThreadContext* ctx) throw() 
{
	{
		SynchronizedBlockObj __synchronized_2(this->refLock, ctx);
		this->refs -- ;
	}
}
int SocketServer::getRefs(ThreadContext* ctx) throw() 
{
	int cur = 0;
	{
		SynchronizedBlockObj __synchronized_2(this->refLock, ctx);
		cur = refs;
	}
	return cur;
}
void SocketServer::handleRequest(ThreadContext* ctx) throw() 
{
	GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"SocketServer", L"handleRequest");
	{
		try
		{
			Socket* socket = this->serverSocket->accept(ctx);
			AlinousThread* execThread = this->threadPool->borrow(true, ctx);
			{
				SynchronizedBlockObj __synchronized_3(this->refLock, ctx);
				this->refs ++ ;
			}
			IThreadAction* action = this->factory->getAction(socket, this, ctx);
			execThread->execute(action, ctx);
		}
		catch(IOException* e)
		{
			e->printStackTrace(ctx);
			this->logger->logError(e, ctx);
		}
		catch(Throwable* e)
		{
			e->printStackTrace(ctx);
			this->logger->logError(e, ctx);
		}
	}
}
}}}

