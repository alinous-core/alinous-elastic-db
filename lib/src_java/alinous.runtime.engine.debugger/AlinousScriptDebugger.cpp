#include "include/global.h"


#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile/IStatement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.html/IDomObject.h"
#include "alinous.html/DomNode.h"
#include "alinous.system/AlinousException.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.runtime.dom/IDomVariableContainer.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.dom/IDomVariable.h"
#include "alinous.runtime.dom.typed/ITypedVariable.h"
#include "alinous.system/ISystemLog.h"
#include "alinous.system/AlinousCore.h"
#include "alinous.runtime.dom/DomVariableContainer.h"
#include "alinous.runtime.dom.typed/ITypedCaller.h"
#include "alinous.runtime.dom.typed/AbstractTypedVariable.h"
#include "alinous.runtime.dom.typed/TypedVariableArray.h"
#include "alinous.runtime.dom.typed/TimestampVariable.h"
#include "alinous.runtime.dom.typed/TimeVariable.h"
#include "alinous.runtime.dom.typed/StringVariable.h"
#include "alinous.runtime.dom.typed/ShortVariable.h"
#include "alinous.runtime.dom.typed/LongVariable.h"
#include "alinous.runtime.dom.typed/IntegerVariable.h"
#include "alinous.runtime.dom.typed/FloatVariable.h"
#include "alinous.runtime.dom.typed/DoubleVariable.h"
#include "alinous.runtime.dom.typed/CharVariable.h"
#include "alinous.runtime.dom.typed/ByteVariable.h"
#include "alinous.runtime.variant/VariantValue.h"
#include "alinous.runtime.dom.typed/BoolVariable.h"
#include "alinous.runtime.dom.typed/TypedVariableContainer.h"
#include "alinous.runtime.engine/IStackFrame.h"
#include "alinous.runtime.engine/AbstractStackFrame.h"
#include "alinous.runtime.engine/SubStackFrame.h"
#include "alinous.runtime.engine/MainStackFrame.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile.expression/DomVariableDescriptor.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.runtime.dom/DomVariable.h"
#include "alinous.runtime.dom.typed/BigDecimalVariable.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile/Token.h"
#include "alinous.lock/LockObject.h"
#include "alinous.runtime.engine.debugger.server/ServerBreakPoint.h"
#include "alinous.runtime.engine.debugger.server/FileBreakpointContainer.h"
#include "alinous.runtime.engine.debugger/DebugStackFrame.h"
#include "alinous.runtime.engine.debugger/DebugThread.h"
#include "alinous.runtime.engine.debugger/AlinousDebugEvent.h"
#include "alinous.runtime.engine.debugger.server/IDebuggerOperation.h"
#include "alinous.runtime.engine.debugger.server/IServerCommand.h"
#include "alinous.runtime.engine.debugger.server/ICommandSender.h"
#include "alinous.runtime.engine.debugger.server/AbstractAlinousServerCommand.h"
#include "alinous.runtime.engine.debugger.server/NotifyThreadEndedCommand.h"
#include "alinous.runtime.engine.debugger.server/NotifyThreadStartCommand.h"
#include "alinous.runtime.engine.debugger/AlinousDebugEventNotifier.h"
#include "java.lang/Number.h"
#include "java.lang/Comparable.h"
#include "java.lang/Long.h"
#include "alinous.runtime.engine.debugger/AlinousScriptDebugger.h"
#include "alinous.runtime.engine.debugger/AlinousServerDebugHttpResponse.h"
#include "alinous.runtime.engine.debugger.client/IClientRequest.h"
#include "alinous.runtime.engine.debugger/IHttpAccessMethod.h"
#include "alinous.runtime.engine.debugger/AlinousDebugCommandSender.h"
#include "alinous.runtime.engine.debugger/DebuggerOut.h"

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
			ISystemLog* log = this->core->getLogger(ctx);
			log->logError(e, ctx);
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
			ISystemLog* log = this->core->getLogger(ctx);
			log->logError(e, ctx);
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
void AlinousScriptDebugger::__cleanUp(ThreadContext* ctx){
}
}}}}

