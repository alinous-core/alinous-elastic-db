#include "include/global.h"


#include "alinous.compile/IAlinousElementVisitor.h"
#include "alinous.compile.analyse/SourceValidator.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile/IStatement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.compile.stmt/AbstractAlinousStatement.h"
#include "alinous.compile.stmt/StatementList.h"
#include "alinous.compile.stmt/StatementBlock.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.html/IDomObject.h"
#include "alinous.html/DomNode.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.system/AlinousException.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.runtime.dbif/IDatabaseConnection.h"
#include "alinous.runtime.dbif/IDatabaseDriver.h"
#include "alinous.runtime.dom/IDomVariableContainer.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.dom/IDomVariable.h"
#include "alinous.runtime.dom.typed/ITypedVariable.h"
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
#include "alinous.runtime.engine/AlinousNullPointerException.h"
#include "alinous.runtime.variant/VariantValue.h"
#include "alinous.runtime.dom.typed/BoolVariable.h"
#include "alinous.runtime.dom.clazz/IAlinousClassVariable.h"
#include "alinous.runtime.dom.clazz/AlinousClassVariable.h"
#include "alinous.server.http.params/AbstractHttpParameter.h"
#include "alinous.server.http.params/HttpArrayParameter.h"
#include "alinous.server.http.params/HttpParameter.h"
#include "alinous.server.http.params/HttpUploadParameter.h"
#include "alinous.runtime.dom/DomVariableContainer.h"
#include "alinous.runtime.engine/DebugMainFrameSrcElement.h"
#include "alinous.runtime.dom.typed/TypedVariableContainer.h"
#include "alinous.runtime.engine/IStackFrame.h"
#include "alinous.runtime.engine/AbstractStackFrame.h"
#include "alinous.runtime.engine/SubStackFrame.h"
#include "alinous.runtime.engine/MainStackFrame.h"
#include "alinous.runtime.engine/DatabaseHandle.h"
#include "alinous.compile.expression.expstream/IdentifierVariable.h"
#include "alinous.compile.stmt/AssignmentStatement.h"
#include "alinous.compile.stmt/ExpressionStatement.h"
#include "alinous.compile.stmt/ReturnStatement.h"
#include "alinous.compile.stmt/TypedVariableDeclare.h"
#include "alinous.runtime.engine/AlinousStatementRunner.h"
#include "alinous.runtime.engine/SQLStatementRunner.h"
#include "alinous.runtime.engine/ExpressionStreamBuffer.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.compile.expression/DomVariableDescriptor.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.runtime.dom/DomVariable.h"
#include "alinous.runtime.dom.typed/BigDecimalVariable.h"
#include "alinous.runtime.engine/ScriptRunner.h"
#include "alinous.runtime/AlinousModule.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile/Token.h"
#include "alinous.runtime.engine/HttpParamHandler.h"

namespace alinous {namespace runtime {namespace engine {





bool DebugMainFrameSrcElement::__init_done = __init_static_variables();
bool DebugMainFrameSrcElement::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DebugMainFrameSrcElement", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 DebugMainFrameSrcElement::DebugMainFrameSrcElement(ThreadContext* ctx) throw()  : IObject(ctx), AbstractSrcElement(ctx), filePath(nullptr), debugFilePath(nullptr), line(0)
{
}
void DebugMainFrameSrcElement::__construct_impl(ThreadContext* ctx) throw() 
{
}
 DebugMainFrameSrcElement::~DebugMainFrameSrcElement() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void DebugMainFrameSrcElement::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"DebugMainFrameSrcElement", L"~DebugMainFrameSrcElement");
	__e_obj1.add(this->filePath, this);
	filePath = nullptr;
	__e_obj1.add(this->debugFilePath, this);
	debugFilePath = nullptr;
	if(!prepare){
		return;
	}
	AbstractSrcElement::__releaseRegerences(true, ctx);
}
int DebugMainFrameSrcElement::getLine(ThreadContext* ctx) throw() 
{
	return this->line;
}
int DebugMainFrameSrcElement::getStartPosition(ThreadContext* ctx) throw() 
{
	return 0;
}
int DebugMainFrameSrcElement::getEndLine(ThreadContext* ctx) throw() 
{
	return 0;
}
int DebugMainFrameSrcElement::getEndPosition(ThreadContext* ctx) throw() 
{
	return 0;
}
AbstractSrcElement* DebugMainFrameSrcElement::getParent(ThreadContext* ctx) throw() 
{
	return nullptr;
}
void DebugMainFrameSrcElement::setParent(AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
}
String* DebugMainFrameSrcElement::getFilePath(ThreadContext* ctx) throw() 
{
	return this->filePath;
}
void DebugMainFrameSrcElement::setFilePath(String* path, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->filePath), path, String);
}
bool DebugMainFrameSrcElement::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	return true;
}
String* DebugMainFrameSrcElement::getDebugFilePath(ThreadContext* ctx) throw() 
{
	return debugFilePath;
}
void DebugMainFrameSrcElement::setDebugFilePath(String* debugFilePath, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->debugFilePath), debugFilePath, String);
}
void DebugMainFrameSrcElement::__cleanUp(ThreadContext* ctx){
}
}}}

