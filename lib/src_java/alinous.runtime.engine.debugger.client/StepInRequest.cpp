#include "include/global.h"


#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.html/IDomObject.h"
#include "alinous.html/DomNode.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.runtime.dom/IDomVariableContainer.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.dom/IDomVariable.h"
#include "alinous.runtime.dom.typed/ITypedVariable.h"
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
#include "alinous.runtime.engine.debugger/AlinousScriptDebugger.h"
#include "alinous.runtime.engine.debugger/AlinousServerDebugHttpResponse.h"
#include "alinous.runtime.engine.debugger.client/IClientRequest.h"
#include "alinous.runtime.engine.debugger.client/SetupAllBreakPointsRequest.h"
#include "alinous.runtime.engine.debugger.client/TerminateServerRequest.h"
#include "alinous.runtime.engine.debugger.client/StatusThreadRequest.h"
#include "alinous.runtime.engine.debugger.client/ClearBreakpointsRequest.h"
#include "alinous.runtime.engine.debugger.client/AddBreakpointsRequest.h"
#include "alinous.runtime.engine.debugger.client/ResumeRequest.h"
#include "alinous.runtime.engine.debugger.client/StepOverRequest.h"
#include "alinous.runtime.engine.debugger.server/AbstractDebuggerOperation.h"
#include "alinous.runtime.engine.debugger.server/StepInOperation.h"
#include "alinous.runtime.engine.debugger.client/StepInRequest.h"
#include "alinous.runtime.engine.debugger.client/StepReturnRequest.h"
#include "alinous.runtime.engine.debugger.client/ClientRequestFactory.h"

namespace alinous {namespace runtime {namespace engine {namespace debugger {namespace client {





String* StepInRequest::THREAD_ID = ConstStr::getCNST_STR_1198();
String* StepInRequest::STACK_ID = ConstStr::getCNST_STR_1199();
bool StepInRequest::__init_done = __init_static_variables();
bool StepInRequest::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"StepInRequest", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 StepInRequest::StepInRequest(ThreadContext* ctx) throw()  : IObject(ctx), IClientRequest(ctx), threadId(0), stackId(0)
{
}
void StepInRequest::__construct_impl(ThreadContext* ctx) throw() 
{
}
 StepInRequest::~StepInRequest() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void StepInRequest::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"StepInRequest", L"~StepInRequest");
	if(!prepare){
		return;
	}
}
AlinousServerDebugHttpResponse* StepInRequest::executeRequest(AlinousScriptDebugger* debugManager, ThreadContext* ctx) throw() 
{
	DebugThread* debugThread = debugManager->getDebugThread(this->threadId, ctx);
	StepInOperation* ope = (new(ctx) StepInOperation(debugThread, debugManager, ctx));
	debugManager->setOperation(this->threadId, ope, ctx);
	debugManager->resume(this->threadId, ctx);
	AlinousServerDebugHttpResponse* responce = (new(ctx) AlinousServerDebugHttpResponse(0, ctx));
	return responce;
}
String* StepInRequest::getCommand(ThreadContext* ctx) throw() 
{
	return IClientRequest::CMD_STEP_IN;
}
Map<String,String>* StepInRequest::getParamMap(ThreadContext* ctx) throw() 
{
	Map<String,String>* m = (new(ctx) HashMap<String,String>(ctx));
	m->put(THREAD_ID, Long::toString(this->threadId, ctx), ctx);
	m->put(STACK_ID, Long::toString(this->stackId, ctx), ctx);
	return m;
}
void StepInRequest::importParams(Map<String,String>* params, ThreadContext* ctx) throw() 
{
	String* strThreadId = params->get(THREAD_ID, ctx);
	if(strThreadId != nullptr)
	{
		this->threadId = Long::parseLong(strThreadId, ctx);
	}
	String* strStackId = params->get(STACK_ID, ctx);
	if(strStackId != nullptr)
	{
		this->stackId = Long::parseLong(strStackId, ctx);
	}
}
long long StepInRequest::getStackId(ThreadContext* ctx) throw() 
{
	return stackId;
}
void StepInRequest::setStackId(long long stackId, ThreadContext* ctx) throw() 
{
	this->stackId = stackId;
}
long long StepInRequest::getThreadId(ThreadContext* ctx) throw() 
{
	return threadId;
}
void StepInRequest::setThreadId(long long threadId, ThreadContext* ctx) throw() 
{
	this->threadId = threadId;
}
void StepInRequest::__cleanUp(ThreadContext* ctx){
}
}}}}}

