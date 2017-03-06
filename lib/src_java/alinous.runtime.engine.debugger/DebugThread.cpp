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
#include "alinous.html.xpath/IVariableValue.h"
#include "alinous.html/IDomObject.h"
#include "alinous.html/Attribute.h"
#include "alinous.html/DomNode.h"
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
#include "alinous.runtime.engine.debugger.server/ICommandSender.h"
#include "alinous.runtime.engine.debugger/AlinousDebugEventNotifier.h"
#include "alinous.runtime.engine.debugger.server/IDebuggerOperation.h"
#include "alinous.runtime.engine.debugger.server/AbstractDebuggerOperation.h"
#include "alinous.runtime.engine.debugger.server/RunningOperation.h"
#include "alinous.runtime.engine.debugger/DebugStackFrame.h"
#include "alinous.runtime.engine.debugger/DebugThread.h"
#include "alinous.runtime.engine.debugger/AlinousDebugEvent.h"
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





constexpr const int DebugThread::STATUS_NONE;
constexpr const int DebugThread::STATUS_RUNNING;
constexpr const int DebugThread::STATUS_SUSPEND;
String* DebugThread::TAG_THREAD = ConstStr::getCNST_STR_1177();
String* DebugThread::ATTR_THREAD_ID = ConstStr::getCNST_STR_1178();
String* DebugThread::ATTR_STATUS = ConstStr::getCNST_STR_1179();
bool DebugThread::__init_done = __init_static_variables();
bool DebugThread::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DebugThread", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 DebugThread::DebugThread(ThreadContext* ctx) throw()  : IObject(ctx), threadId(0), machine(nullptr), operation(nullptr), status(0), sem(__GC_INS(this, (new(ctx) LockObject(ctx)), LockObject)), stackFrames(nullptr)
{
}
void DebugThread::__construct_impl(ThreadContext* ctx) throw() 
{
}
 DebugThread::DebugThread(long long threadId, ScriptMachine* machine, ThreadContext* ctx) throw()  : IObject(ctx), threadId(0), machine(nullptr), operation(nullptr), status(0), sem(__GC_INS(this, (new(ctx) LockObject(ctx)), LockObject)), stackFrames(nullptr)
{
	this->threadId = threadId;
	__GC_MV(this, &(this->machine), machine, ScriptMachine);
	if(machine != nullptr)
	{
		init(machine->getCore(ctx)->getDebugger(ctx), ctx);
	}
}
void DebugThread::__construct_impl(long long threadId, ScriptMachine* machine, ThreadContext* ctx) throw() 
{
	this->threadId = threadId;
	__GC_MV(this, &(this->machine), machine, ScriptMachine);
	if(machine != nullptr)
	{
		init(machine->getCore(ctx)->getDebugger(ctx), ctx);
	}
}
 DebugThread::~DebugThread() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void DebugThread::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"DebugThread", L"~DebugThread");
	__e_obj1.add(this->machine, this);
	machine = nullptr;
	__e_obj1.add(this->operation, this);
	operation = nullptr;
	__e_obj1.add(this->sem, this);
	sem = nullptr;
	__e_obj1.add(this->stackFrames, this);
	stackFrames = nullptr;
	if(!prepare){
		return;
	}
}
void DebugThread::outDebugXml(DomNode* parentNode, ThreadContext* ctx) throw() 
{
	DomNode* node = (new(ctx) DomNode(TAG_THREAD, ctx));
	parentNode->addChild(node, ctx);
	Attribute* attr = (new(ctx) Attribute(ATTR_THREAD_ID, Long::toString(this->threadId, ctx), node, ctx));
	node->addAttribute(attr, ctx);
	attr = (new(ctx) Attribute(ATTR_STATUS, Integer::toString(this->status, ctx), node, ctx));
	node->addAttribute(attr, ctx);
	this->machine->outDebugXml(node, ctx);
}
IDebuggerOperation* DebugThread::getOperation(ThreadContext* ctx) throw() 
{
	return this->operation;
}
void DebugThread::setOperation(IDebuggerOperation* ope, AlinousScriptDebugger* manager, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->operation), ope, IDebuggerOperation);
	this->operation->init(this, manager, ctx);
}
void DebugThread::handleEvent(AlinousDebugEvent* event, ScriptMachine* machine, ThreadContext* ctx) throw() 
{
	this->operation->handleEvent(event, machine, ctx);
}
long long DebugThread::getThreadId(ThreadContext* ctx) throw() 
{
	return this->threadId;
}
void DebugThread::suspend(ThreadContext* ctx)
{
	{
		SynchronizedBlockObj __synchronized_2(this->sem, ctx);
		this->status = STATUS_SUSPEND;
		this->sem->wait(ctx);
		this->status = STATUS_RUNNING;
	}
}
void DebugThread::resume(ThreadContext* ctx) throw() 
{
	{
		SynchronizedBlockObj __synchronized_2(this->sem, ctx);
		if(this->status == STATUS_SUSPEND)
		{
			this->sem->notifyAll(ctx);
		}
	}
}
int DebugThread::getStatus(ThreadContext* ctx) throw() 
{
	return status;
}
void DebugThread::terminate(ThreadContext* ctx) throw() 
{
	if(this->status == STATUS_SUSPEND)
	{
		this->sem->notifyAll(ctx);
	}
}
IArrayObject<DebugStackFrame>* DebugThread::getStackFrames(ThreadContext* ctx) throw() 
{
	Stack<MainStackFrame>* stackFrames = this->stackFrames;
	ArrayList<DebugStackFrame>* list = (new(ctx) ArrayList<DebugStackFrame>(ctx));
	int maxLoop = stackFrames->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		MainStackFrame* f = stackFrames->get(i, ctx);
		bool peek = (i == maxLoop - 1);
		DebugStackFrame* df = (new(ctx) DebugStackFrame(f, peek, f->getStackId(ctx), ctx));
		list->add(df, ctx);
	}
	return list->toArray(ArrayAllocator<DebugStackFrame>::allocate(ctx, list->size(ctx)), ctx);
}
void DebugThread::init(AlinousScriptDebugger* manager, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->operation), (new(ctx) RunningOperation(this, manager, ctx)), IDebuggerOperation);
}
DebugThread* DebugThread::importFromDebugXml(DomNode* node, ThreadContext* ctx) throw() 
{
	if(!node->getName(ctx)->equals(DebugThread::TAG_THREAD, ctx))
	{
		return nullptr;
	}
	DebugThread* thread = (new(ctx) DebugThread(ctx));
	IVariableValue* v = node->getAttributeValue(ATTR_THREAD_ID, ctx);
	thread->threadId = Long::parseLong(v->toString(ctx), ctx);
	v = node->getAttributeValue(ATTR_STATUS, ctx);
	thread->status = Integer::parseInt(v->toString(ctx), ctx);
	GCUtils<Stack<MainStackFrame> >::mv(thread, &(thread->stackFrames), (new(ctx) Stack<MainStackFrame>(ctx)), ctx);
	int maxLoop = node->getNumChildern(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		DomNode* n = node->getChildNodeAt(i, ctx);
		MainStackFrame* frame = MainStackFrame::importFromDebugXml(n, ctx);
		if(frame != nullptr)
		{
			thread->stackFrames->push(frame, ctx);
		}
	}
	return thread;
}
void DebugThread::__cleanUp(ThreadContext* ctx){
}
}}}}

