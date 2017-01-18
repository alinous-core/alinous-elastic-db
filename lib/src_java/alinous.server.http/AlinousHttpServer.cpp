#include "includes.h"


namespace alinous {namespace server {namespace http {





bool AlinousHttpServer::__init_done = __init_static_variables();
bool AlinousHttpServer::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AlinousHttpServer", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AlinousHttpServer::AlinousHttpServer(int port, AlinousCore* core, int maxThread, ThreadContext* ctx) throw()  : IObject(ctx), Runnable(ctx), core(nullptr), port(0), serverSocket(nullptr), threadPool(nullptr), thread(nullptr), running(0), webProccessor(nullptr), refLock(__GC_INS(this, (new(ctx) LockObject(ctx)), LockObject)), refs(0)
{
	this->port = port;
	__GC_MV(this, &(this->core), core, AlinousCore);
	__GC_MV(this, &(this->webProccessor), (new(ctx) AlinousWebContentProcessor(core, ctx)), AlinousWebContentProcessor);
	__GC_MV(this, &(this->threadPool), (new(ctx) ThreadPool(maxThread, ConstStr::getCNST_STR_3510(), ctx)), ThreadPool);
}
void AlinousHttpServer::__construct_impl(int port, AlinousCore* core, int maxThread, ThreadContext* ctx) throw() 
{
	this->port = port;
	__GC_MV(this, &(this->core), core, AlinousCore);
	__GC_MV(this, &(this->webProccessor), (new(ctx) AlinousWebContentProcessor(core, ctx)), AlinousWebContentProcessor);
	__GC_MV(this, &(this->threadPool), (new(ctx) ThreadPool(maxThread, ConstStr::getCNST_STR_3510(), ctx)), ThreadPool);
}
 AlinousHttpServer::~AlinousHttpServer() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AlinousHttpServer::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"AlinousHttpServer", L"~AlinousHttpServer");
	__e_obj1.add(this->core, this);
	core = nullptr;
	__e_obj1.add(this->serverSocket, this);
	serverSocket = nullptr;
	__e_obj1.add(this->threadPool, this);
	threadPool = nullptr;
	__e_obj1.add(this->thread, this);
	thread = nullptr;
	__e_obj1.add(this->webProccessor, this);
	webProccessor = nullptr;
	__e_obj1.add(this->refLock, this);
	refLock = nullptr;
	if(!prepare){
		return;
	}
}
void AlinousHttpServer::startServer(ThreadContext* ctx) throw() 
{
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
	System::out->println(ConstStr::getCNST_STR_3511(), ctx);
}
void AlinousHttpServer::stopServer(ThreadContext* ctx) throw() 
{
	this->running = false;
	HttpClient* client = (new(ctx) HttpClient(ctx));
	HttpRequestHeaders* params = (new(ctx) HttpRequestHeaders(ctx));
	{
		try
		{
			client->get(ConstStr::getCNST_STR_3512(), this->port, AlinousWebContentProcessor::PING_TO_SERVER, params, ctx);
			client->dispose(ctx);
		}
		catch(UnknownHostException* e)
		{
			e->printStackTrace(ctx);
			this->core->getLogger(ctx)->logError(e, ctx);
		}
		catch(IOException* e)
		{
			e->printStackTrace(ctx);
			this->core->getLogger(ctx)->logError(e, ctx);
		}
		catch(AlinousException* e)
		{
			e->printStackTrace(ctx);
			this->core->getLogger(ctx)->logError(e, ctx);
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
			this->core->getLogger(ctx)->logError(e, ctx);
		}
	}
	this->threadPool->dispose(ctx);
}
void AlinousHttpServer::run(ThreadContext* ctx) throw() 
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
				this->core->getLogger(ctx)->logError(e, ctx);
				if(retry > 200)
				{
					return;
				}
				retry ++ ;
				System::out->println(ConstStr::getCNST_STR_3513(), ctx);
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
	System::out->println(ConstStr::getCNST_STR_3514()->clone(ctx)->append(this->refs, ctx), ctx);
}
void AlinousHttpServer::dec(ThreadContext* ctx) throw() 
{
	{
		SynchronizedBlockObj __synchronized_2(this->refLock, ctx);
		this->refs -- ;
	}
}
void AlinousHttpServer::handleRequest(ThreadContext* ctx) throw() 
{
	GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AlinousHttpServer", L"handleRequest");
	{
		try
		{
			Socket* socket = this->serverSocket->accept(ctx);
			AlinousThread* execThread = this->threadPool->borrow(true, ctx);
			{
				SynchronizedBlockObj __synchronized_3(this->refLock, ctx);
				this->refs ++ ;
			}
			ProcessRequestAction* action = (new(ctx) ProcessRequestAction(socket, this->webProccessor, this, ctx));
			execThread->execute(action, ctx);
		}
		catch(IOException* e)
		{
			e->printStackTrace(ctx);
			this->core->getLogger(ctx)->logError(e, ctx);
		}
		catch(Throwable* e)
		{
			e->printStackTrace(ctx);
			this->core->getLogger(ctx)->logError(e, ctx);
		}
	}
}
}}}

