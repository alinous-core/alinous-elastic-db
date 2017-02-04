#include "includes.h"


namespace alinous {namespace runtime {namespace engine {namespace debugger {





constexpr const bool AlinousDebugEventNotifier::debugDebugger;
bool AlinousDebugEventNotifier::__init_done = __init_static_variables();
bool AlinousDebugEventNotifier::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AlinousDebugEventNotifier", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AlinousDebugEventNotifier::AlinousDebugEventNotifier(AlinousScriptDebugger* debugManager, ThreadContext* ctx) throw()  : IObject(ctx), Runnable(ctx), ICommandSender(ctx), port(0), commandqueue(GCUtils<List<IServerCommand> >::ins(this, (new(ctx) LinkedList<IServerCommand>(ctx)), ctx, __FILEW__, __LINE__, L"")), lock(__GC_INS(this, (new(ctx) LockObject(ctx)), LockObject)), loop(0), debugManager(nullptr), th(nullptr)
{
	this->port = -1;
	__GC_MV(this, &(this->debugManager), debugManager, AlinousScriptDebugger);
	debugOut(ConstStr::getCNST_STR_1175(), ctx);
	this->loop = true;
	__GC_MV(this, &(this->th), (new(ctx) Thread(this, ConstStr::getCNST_STR_1176(), ctx)), Thread);
	this->th->start(ctx);
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
	debugOut(ConstStr::getCNST_STR_1177(), ctx);
}
void AlinousDebugEventNotifier::__construct_impl(AlinousScriptDebugger* debugManager, ThreadContext* ctx) throw() 
{
	this->port = -1;
	__GC_MV(this, &(this->debugManager), debugManager, AlinousScriptDebugger);
	debugOut(ConstStr::getCNST_STR_1175(), ctx);
	this->loop = true;
	__GC_MV(this, &(this->th), (new(ctx) Thread(this, ConstStr::getCNST_STR_1176(), ctx)), Thread);
	this->th->start(ctx);
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
	debugOut(ConstStr::getCNST_STR_1177(), ctx);
}
 AlinousDebugEventNotifier::~AlinousDebugEventNotifier() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AlinousDebugEventNotifier::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"AlinousDebugEventNotifier", L"~AlinousDebugEventNotifier");
	__e_obj1.add(this->commandqueue, this);
	commandqueue = nullptr;
	__e_obj1.add(this->lock, this);
	lock = nullptr;
	__e_obj1.add(this->debugManager, this);
	debugManager = nullptr;
	__e_obj1.add(this->th, this);
	th = nullptr;
	if(!prepare){
		return;
	}
}
void AlinousDebugEventNotifier::dispose(ThreadContext* ctx)
{
	{
		SynchronizedBlockObj __synchronized_2(this->lock, ctx);
		this->loop = false;
		this->lock->notifyAll(ctx);
	}
	{
		try
		{
			this->th->join(ctx);
		}
		catch(InterruptedException* e)
		{
			e->printStackTrace(ctx);
			throw e;
		}
	}
}
void AlinousDebugEventNotifier::notifyToClient(IServerCommand* command, ScriptMachine* machine, ThreadContext* ctx)
{
	{
		SynchronizedBlockObj __synchronized_2(this->lock, ctx);
		this->commandqueue->add(command, ctx);
		this->lock->notifyAll(ctx);
	}
}
void AlinousDebugEventNotifier::run(ThreadContext* ctx) throw() 
{
	IServerCommand* nextCmd = nullptr;
	int waitCount = 0;
	while(this->loop)
	{
		bool isEmpty = 0;
		int queuesize = 0;
		{
			SynchronizedBlockObj __synchronized_3(this->lock, ctx);
			isEmpty = this->commandqueue->isEmpty(ctx);
			queuesize = this->commandqueue->size(ctx);
		}
		if(isEmpty && waitCount > 10)
		{
			{
				try
				{
					debugOut(ConstStr::getCNST_STR_1178()->clone(ctx)->append(queuesize, ctx), ctx);
					{
						SynchronizedBlockObj __synchronized_5(this->lock, ctx);
						this->lock->wait(ctx);
					}
					waitCount = 0;
					if(this->loop == false)
					{
						return;
					}
				}
				catch(InterruptedException* e)
				{
					e->printStackTrace(ctx);
				}
			}
		}
		waitCount ++ ;
		{
			try
			{
				Thread::sleep(20, ctx);
			}
			catch(InterruptedException* e)
			{
				e->printStackTrace(ctx);
			}
		}
		{
			try
			{
				{
					SynchronizedBlockObj __synchronized_4(this->lock, ctx);
					nextCmd = fetch(ctx);
					this->lock->notifyAll(ctx);
				}
				while(nextCmd != nullptr)
				{
					nextCmd->sendCommand(this, nullptr, ctx);
					{
						SynchronizedBlockObj __synchronized_5(this->lock, ctx);
						nextCmd = fetch(ctx);
						this->lock->notifyAll(ctx);
					}
				}
			}
			catch(Throwable* e)
			{
				e->printStackTrace(ctx);
			}
		}
	}
}
void AlinousDebugEventNotifier::sendCommand(IServerCommand* command, ScriptMachine* context, ThreadContext* ctx)
{
	Socket* con = nullptr;
	con = (new(ctx) Socket(ConstStr::getCNST_STR_1179(), port, ctx));
	OutputStream* stream = nullptr;
	Writer* writer = nullptr;
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			stream->close(ctx);
			writer->close(ctx);
			{
				try
				{
					con->close(ctx);
				}
				catch(IOException* e)
				{
				}
			}
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			stream = con->getOutputStream(ctx);
			writer = (new(ctx) PrintWriter(stream, true, ctx));
			command->writeCommand(writer, ctx);
		}
		catch(IOException* e)
		{
			e->printStackTrace(ctx);
		}
	}
}
IServerCommand* AlinousDebugEventNotifier::fetch(ThreadContext* ctx) throw() 
{
	if(this->commandqueue->isEmpty(ctx))
	{
		return nullptr;
	}
	IServerCommand* el = this->commandqueue->get(0, ctx);
	this->commandqueue->remove(0, ctx);
	return el;
}
int AlinousDebugEventNotifier::getPort(ThreadContext* ctx) throw() 
{
	return port;
}
void AlinousDebugEventNotifier::setPort(int port, ThreadContext* ctx) throw() 
{
	this->port = port;
}
void AlinousDebugEventNotifier::debugOut(String* str, ThreadContext* ctx) throw() 
{
	if(!debugDebugger)
	{
		return;
	}
	System::out->println(str, ctx);
	System::out->flush(ctx);
}
AlinousScriptDebugger* AlinousDebugEventNotifier::getDebugManager(ThreadContext* ctx) throw() 
{
	return debugManager;
}
}}}}

