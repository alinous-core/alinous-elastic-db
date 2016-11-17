#include "includes.h"


namespace alinous {namespace runtime {namespace engine {namespace debugger {





bool AlinousScriptDebugger::__init_done = __init_static_variables();
bool AlinousScriptDebugger::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AlinousScriptDebugger", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AlinousScriptDebugger::AlinousScriptDebugger(AlinousCore* core, int debugPort, ThreadContext* ctx) throw()  : IObject(ctx), ThreadMonitor(ctx), core(nullptr), breakPointContainers(GCUtils<HashMap<String,FileBreakpointContainer> >::ins(this, (new(ctx) HashMap<String,FileBreakpointContainer>(ctx)), ctx, __FILEW__, __LINE__, L"")), lock(__GC_INS(this, (new(ctx) LockObject(ctx)), LockObject)), debugEventNotifier(nullptr), threads(GCUtils<HashMap<Long,DebugThread> >::ins(this, (new(ctx) HashMap<Long,DebugThread>(ctx)), ctx, __FILEW__, __LINE__, L"")), hotThreadId(0)
{
	__GC_MV(this, &(this->core), core, AlinousCore);
	__GC_MV(this, &(this->debugEventNotifier), (new(ctx) AlinousDebugEventNotifier(this, ctx)), AlinousDebugEventNotifier);
	this->debugEventNotifier->setPort(debugPort, ctx);
}
void AlinousScriptDebugger::__construct_impl(AlinousCore* core, int debugPort, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->core), core, AlinousCore);
	__GC_MV(this, &(this->debugEventNotifier), (new(ctx) AlinousDebugEventNotifier(this, ctx)), AlinousDebugEventNotifier);
	this->debugEventNotifier->setPort(debugPort, ctx);
}
 AlinousScriptDebugger::~AlinousScriptDebugger() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AlinousScriptDebugger::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"AlinousScriptDebugger", L"~AlinousScriptDebugger");
	__e_obj1.add(this->core, this);
	core = nullptr;
	__e_obj1.add(this->breakPointContainers, this);
	breakPointContainers = nullptr;
	__e_obj1.add(this->lock, this);
	lock = nullptr;
	__e_obj1.add(this->debugEventNotifier, this);
	debugEventNotifier = nullptr;
	__e_obj1.add(this->threads, this);
	threads = nullptr;
	if(!prepare){
		return;
	}
}
void AlinousScriptDebugger::dispose(ThreadContext* ctx)
{
	this->debugEventNotifier->dispose(ctx);
}
void AlinousScriptDebugger::startAlinousOperation(ScriptMachine* machine, ThreadContext* ctx) throw() 
{
	long long threadId = Thread::currentThread(ctx)->getId(ctx);
	DebugThread* th = (new(ctx) DebugThread(threadId, machine, ctx));
	{
		SynchronizedBlockObj __synchronized_2(this, ctx);
		this->threads->put((new(ctx) Long(threadId, ctx)), th, ctx);
	}
	{
		try
		{
			this->debugEventNotifier->notifyToClient((new(ctx) NotifyThreadStartCommand(Thread::currentThread(ctx)->getId(ctx), ctx)), machine, ctx);
		}
		catch(AlinousException* e)
		{
			this->core->getLogger(ctx)->logError(e, ctx);
		}
	}
}
void AlinousScriptDebugger::endAlinousOperation(ScriptMachine* machine, ThreadContext* ctx) throw() 
{
	long long threadId = Thread::currentThread(ctx)->getId(ctx);
	Long* longId = (new(ctx) Long(threadId, ctx));
	{
		SynchronizedBlockObj __synchronized_2(this, ctx);
		this->threads->remove(longId, ctx);
	}
	{
		try
		{
			this->debugEventNotifier->notifyToClient((new(ctx) NotifyThreadEndedCommand(Thread::currentThread(ctx)->getId(ctx), ctx)), machine, ctx);
		}
		catch(AlinousException* e)
		{
			this->core->getLogger(ctx)->logError(e, ctx);
		}
	}
}
void AlinousScriptDebugger::setOperation(long long threadId, IDebuggerOperation* ope, ThreadContext* ctx) throw() 
{
	DebugThread* thread = getDebugThread(threadId, ctx);
	thread->setOperation(ope, this, ctx);
}
void AlinousScriptDebugger::notifyBefore(IStatement* srcElement, ScriptMachine* machine, ThreadContext* ctx) throw() 
{
	long long threadId = Thread::currentThread(ctx)->getId(ctx);
	Long* longId = (new(ctx) Long(threadId, ctx));
	DebugThread* thread = nullptr;
	{
		SynchronizedBlockObj __synchronized_2(this, ctx);
		thread = this->threads->get(longId, ctx);
	}
	AlinousDebugEvent* event = (new(ctx) AlinousDebugEvent(AlinousDebugEvent::BEFORE_SENTENCE, (static_cast<AbstractSrcElement*>(srcElement))->getLine(ctx), (static_cast<AbstractSrcElement*>(srcElement))->getFilePath(ctx), (static_cast<AbstractSrcElement*>(srcElement))->getDebugFilePath(ctx), thread, ctx));
	thread->handleEvent(event, machine, ctx);
}
void AlinousScriptDebugger::notifyBeforeExpression(IExpression* srcExp, ScriptMachine* machine, ThreadContext* ctx) throw() 
{
	long long threadId = Thread::currentThread(ctx)->getId(ctx);
	Long* longId = (new(ctx) Long(threadId, ctx));
	DebugThread* thread = nullptr;
	{
		SynchronizedBlockObj __synchronized_2(this, ctx);
		thread = this->threads->get(longId, ctx);
	}
	AlinousDebugEvent* event = (new(ctx) AlinousDebugEvent(AlinousDebugEvent::BEFORE_EXPRESSION, (static_cast<AbstractSrcElement*>(srcExp))->getLine(ctx), (static_cast<AbstractSrcElement*>(srcExp))->getFilePath(ctx), (static_cast<AbstractSrcElement*>(srcExp))->getDebugFilePath(ctx), thread, ctx));
	thread->handleEvent(event, machine, ctx);
}
void AlinousScriptDebugger::clearBreakpoints(String* filePath, ThreadContext* ctx) throw() 
{
	{
		SynchronizedBlockObj __synchronized_2(this->lock, ctx);
		FileBreakpointContainer* container = this->breakPointContainers->get(filePath, ctx);
		if(container == nullptr)
		{
			return;
		}
		container->clear(ctx);
	}
}
FileBreakpointContainer* AlinousScriptDebugger::getFileBreakpointContainer(String* filePath, ThreadContext* ctx) throw() 
{
	FileBreakpointContainer* container = nullptr;
	{
		SynchronizedBlockObj __synchronized_2(this->lock, ctx);
		container = this->breakPointContainers->get(filePath, ctx);
		if(container == nullptr)
		{
			container = (new(ctx) FileBreakpointContainer(ctx));
			this->breakPointContainers->put(filePath, container, ctx);
		}
	}
	return container;
}
void AlinousScriptDebugger::addBreakPoint(ServerBreakPoint* breakpoint, ThreadContext* ctx) throw() 
{
	FileBreakpointContainer* container = getFileBreakpointContainer(breakpoint->getFilePath(ctx), ctx);
	container->addBreakpoint(breakpoint, ctx);
}
void AlinousScriptDebugger::setBreakpoints(IArrayObject<ServerBreakPoint>* breakpoints, ThreadContext* ctx) throw() 
{
	{
		SynchronizedBlockObj __synchronized_2(this->lock, ctx);
		breakPointContainers->clear(ctx);
		for(int i = 0; i < breakpoints->length; i ++ )
		{
			String* filePath = breakpoints->get(i)->getFilePath(ctx);
			FileBreakpointContainer* container = breakPointContainers->get(filePath, ctx);
			if(container == nullptr)
			{
				container = (new(ctx) FileBreakpointContainer(ctx));
				this->breakPointContainers->put(filePath, container, ctx);
			}
			container->addBreakpoint(breakpoints->get(i), ctx);
		}
	}
}
void AlinousScriptDebugger::clearBreakpoints(ThreadContext* ctx) throw() 
{
	{
		SynchronizedBlockObj __synchronized_2(this->lock, ctx);
		breakPointContainers->clear(ctx);
	}
}
void AlinousScriptDebugger::removeBreakpoint(String* filePath, int line, ThreadContext* ctx) throw() 
{
	{
		SynchronizedBlockObj __synchronized_2(this->lock, ctx);
		FileBreakpointContainer* container = this->breakPointContainers->get(filePath, ctx);
		if(container == nullptr)
		{
			return;
		}
		container->removeBreakpoint(line, ctx);
	}
}
void AlinousScriptDebugger::resume(long long hotThreadId, ThreadContext* ctx) throw() 
{
	DebugThread* th = nullptr;
	{
		SynchronizedBlockObj __synchronized_2(this, ctx);
		Long* id = (new(ctx) Long(hotThreadId, ctx));
		th = this->threads->get(id, ctx);
		th->resume(ctx);
	}
}
DebugThread* AlinousScriptDebugger::getDebugThread(long long threadId, ThreadContext* ctx) throw() 
{
	DebugThread* th = nullptr;
	{
		SynchronizedBlockObj __synchronized_2(this, ctx);
		Long* id = (new(ctx) Long(threadId, ctx));
		th = this->threads->get(id, ctx);
	}
	return th;
}
long long AlinousScriptDebugger::getHotThreadId(ThreadContext* ctx) throw() 
{
	return hotThreadId;
}
void AlinousScriptDebugger::setHotThreadId(long long hotThreadId, ThreadContext* ctx) throw() 
{
	this->hotThreadId = hotThreadId;
}
IArrayObject<DebugThread>* AlinousScriptDebugger::getThreads(ThreadContext* ctx) throw() 
{
	IArrayObject<DebugThread>* array = ArrayAllocator<DebugThread>::allocate(ctx, this->threads->size(ctx));
	int idx = 0;
	Iterator<Long>* it = this->threads->keySet(ctx)->iterator(ctx);
	while(it->hasNext(ctx))
	{
		Long* id = it->next(ctx);
		DebugThread* th = this->threads->get(id, ctx);
		array->set(th,idx++, ctx);
	}
	return array;
}
AlinousDebugEventNotifier* AlinousScriptDebugger::getDebugEventNotifier(ThreadContext* ctx) throw() 
{
	return debugEventNotifier;
}
}}}}

