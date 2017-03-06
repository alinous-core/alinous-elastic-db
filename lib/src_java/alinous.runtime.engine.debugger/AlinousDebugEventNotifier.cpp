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
	debugOut(ConstStr::getCNST_STR_1180(), ctx);
	this->loop = true;
	__GC_MV(this, &(this->th), (new(ctx) Thread(this, ConstStr::getCNST_STR_1181(), ctx)), Thread);
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
	debugOut(ConstStr::getCNST_STR_1182(), ctx);
}
void AlinousDebugEventNotifier::__construct_impl(AlinousScriptDebugger* debugManager, ThreadContext* ctx) throw() 
{
	this->port = -1;
	__GC_MV(this, &(this->debugManager), debugManager, AlinousScriptDebugger);
	debugOut(ConstStr::getCNST_STR_1180(), ctx);
	this->loop = true;
	__GC_MV(this, &(this->th), (new(ctx) Thread(this, ConstStr::getCNST_STR_1181(), ctx)), Thread);
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
	debugOut(ConstStr::getCNST_STR_1182(), ctx);
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
					debugOut(ConstStr::getCNST_STR_1183()->clone(ctx)->append(queuesize, ctx), ctx);
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
	con = (new(ctx) Socket(ConstStr::getCNST_STR_1184(), port, ctx));
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
void AlinousDebugEventNotifier::__cleanUp(ThreadContext* ctx){
}
}}}}

