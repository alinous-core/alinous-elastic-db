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





bool DebugStackFrame::__init_done = __init_static_variables();
bool DebugStackFrame::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DebugStackFrame", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 DebugStackFrame::DebugStackFrame(MainStackFrame* frame, bool peek, long long stackId, ThreadContext* ctx) throw()  : IObject(ctx), line(0), fileName(nullptr), peek(0), stackId(0), frame(nullptr)
{
	__GC_MV(this, &(this->frame), frame, MainStackFrame);
	AbstractSrcElement* src = frame->sourceElement;
	this->line = src->getLine(ctx);
	__GC_MV(this, &(this->fileName), src->getFilePath(ctx), String);
	this->peek = peek;
	this->stackId = stackId;
}
void DebugStackFrame::__construct_impl(MainStackFrame* frame, bool peek, long long stackId, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->frame), frame, MainStackFrame);
	AbstractSrcElement* src = frame->sourceElement;
	this->line = src->getLine(ctx);
	__GC_MV(this, &(this->fileName), src->getFilePath(ctx), String);
	this->peek = peek;
	this->stackId = stackId;
}
 DebugStackFrame::~DebugStackFrame() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void DebugStackFrame::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"DebugStackFrame", L"~DebugStackFrame");
	__e_obj1.add(this->fileName, this);
	fileName = nullptr;
	__e_obj1.add(this->frame, this);
	frame = nullptr;
	if(!prepare){
		return;
	}
}
String* DebugStackFrame::getFileName(ThreadContext* ctx) throw() 
{
	return fileName;
}
void DebugStackFrame::setFileName(String* fileName, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->fileName), fileName, String);
}
int DebugStackFrame::getLine(ThreadContext* ctx) throw() 
{
	return line;
}
void DebugStackFrame::setLine(int line, ThreadContext* ctx) throw() 
{
	this->line = line;
}
bool DebugStackFrame::isPeek(ThreadContext* ctx) throw() 
{
	return peek;
}
void DebugStackFrame::setPeek(bool peek, ThreadContext* ctx) throw() 
{
	this->peek = peek;
}
long long DebugStackFrame::getStackId(ThreadContext* ctx) throw() 
{
	return stackId;
}
void DebugStackFrame::setStackId(long long stackId, ThreadContext* ctx) throw() 
{
	this->stackId = stackId;
}
MainStackFrame* DebugStackFrame::getFrame(ThreadContext* ctx) throw() 
{
	return frame;
}
void DebugStackFrame::__cleanUp(ThreadContext* ctx){
}
}}}}

