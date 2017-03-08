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
#include "alinous.runtime.engine/IStackFrame.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile.expression/DomVariableDescriptor.h"
#include "alinous.runtime.dom.typed/ITypedCaller.h"
#include "alinous.runtime.dom.typed/AbstractTypedVariable.h"
#include "alinous.runtime.dom.typed/TypedVariableArray.h"
#include "alinous.runtime.dom.typed/TimestampVariable.h"
#include "alinous.runtime.dom.typed/TimeVariable.h"
#include "alinous.runtime.dom.typed/ShortVariable.h"
#include "alinous.runtime.dom.typed/LongVariable.h"
#include "alinous.runtime.dom.typed/IntegerVariable.h"
#include "alinous.runtime.dom.typed/FloatVariable.h"
#include "alinous.runtime.dom.typed/DoubleVariable.h"
#include "alinous.runtime.dom.typed/CharVariable.h"
#include "alinous.runtime.dom.typed/ByteVariable.h"
#include "alinous.runtime.dom.typed/StringVariable.h"
#include "alinous.runtime.dom.typed/BoolVariable.h"
#include "alinous.runtime.variant/VariantValue.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.runtime.dom/DomVariable.h"
#include "alinous.runtime.dom.typed/BigDecimalVariable.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile/Token.h"
#include "alinous.runtime.dom/DomVariableContainer.h"
#include "alinous.runtime.dom.typed/TypedVariableContainer.h"
#include "alinous.runtime.engine/AbstractStackFrame.h"
#include "alinous.runtime.engine/SubStackFrame.h"
#include "alinous.runtime.engine/MainStackFrame.h"
#include "alinous.runtime.engine.debugger/AlinousScriptDebugger.h"
#include "alinous.runtime.engine.debugger.server/IDebuggerOperation.h"
#include "alinous.runtime.engine.debugger/DebugThread.h"
#include "alinous.runtime.engine.debugger/AlinousDebugEvent.h"
#include "alinous.runtime.engine.debugger.server/AbstractDebuggerOperation.h"
#include "alinous.runtime.engine.debugger.server/StepReturnOperation.h"

namespace alinous {namespace runtime {namespace engine {namespace debugger {namespace server {





bool StepReturnOperation::__init_done = __init_static_variables();
bool StepReturnOperation::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"StepReturnOperation", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 StepReturnOperation::StepReturnOperation(DebugThread* thread, AlinousScriptDebugger* manager, long long currentStackId, ThreadContext* ctx) throw()  : IObject(ctx), AbstractDebuggerOperation(thread, manager, ctx), currentStackId(0)
{
	this->currentStackId = currentStackId;
}
void StepReturnOperation::__construct_impl(DebugThread* thread, AlinousScriptDebugger* manager, long long currentStackId, ThreadContext* ctx) throw() 
{
	this->currentStackId = currentStackId;
}
 StepReturnOperation::~StepReturnOperation() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void StepReturnOperation::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"StepReturnOperation", L"~StepReturnOperation");
	if(!prepare){
		return;
	}
	AbstractDebuggerOperation::__releaseRegerences(true, ctx);
}
void StepReturnOperation::handleEvent(AlinousDebugEvent* event, ScriptMachine* machine, ThreadContext* ctx) throw() 
{
	MainStackFrame* frame = machine->getFrame(ctx);
	frame->setCurrentLine(event->getLine(ctx), ctx);
}
void StepReturnOperation::init(DebugThread* debugThread, AlinousScriptDebugger* manager, ThreadContext* ctx) throw() 
{
}
long long StepReturnOperation::getCurrentStackId(ThreadContext* ctx) throw() 
{
	return currentStackId;
}
void StepReturnOperation::__cleanUp(ThreadContext* ctx){
}
}}}}}

