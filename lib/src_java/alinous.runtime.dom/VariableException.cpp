#include "include/global.h"


#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.html.xpath/IVariableValue.h"
#include "alinous.html/IDomObject.h"
#include "alinous.html/DomNode.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.system/AlinousException.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.runtime.dom/IDomVariableContainer.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.dom/IDomVariable.h"
#include "alinous.runtime.dom.typed/ITypedCaller.h"
#include "alinous.runtime.dom.typed/ITypedVariable.h"
#include "alinous.system/AlinousNotSupportedException.h"
#include "alinous.runtime.dom/DomArray.h"
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
#include "alinous.runtime.dom/IVariableClassOperationCaller.h"
#include "alinous.runtime.dom/VariableOperationCaller.h"
#include "alinous.runtime.variant/VariantValue.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.runtime.dom/DomVariable.h"
#include "alinous.runtime.dom.typed/BigDecimalVariable.h"
#include "alinous.runtime.dom.clazz/IAlinousClassVariable.h"
#include "alinous.runtime.dom.clazz/AlinousClassVariable.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.compile.expression/DomVariableDescriptor.h"
#include "alinous.compile.expression.expstream/IdentifierVariable.h"
#include "alinous.runtime.dom/DocumentVariable.h"
#include "alinous.runtime.dom/NetworkAlinousVariableFactory.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile/Token.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.runtime.dom/DomVariableDebugXmlFactory.h"
#include "alinous.runtime.dom/DomVariableContainer.h"

namespace alinous {namespace runtime {namespace dom {





constexpr const long long VariableException::serialVersionUID;
bool VariableException::__init_done = __init_static_variables();
bool VariableException::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"VariableException", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 VariableException::VariableException(ThreadContext* ctx) throw()  : IObject(ctx), ExecutionException(ConstStr::getCNST_STR_1110(), ctx)
{
}
void VariableException::__construct_impl(ThreadContext* ctx) throw() 
{
}
 VariableException::VariableException(Throwable* e, ThreadContext* ctx) throw()  : IObject(ctx), ExecutionException(e, ctx)
{
}
void VariableException::__construct_impl(Throwable* e, ThreadContext* ctx) throw() 
{
}
 VariableException::VariableException(String* msg, AbstractSrcElement* element, ThreadContext* ctx) throw()  : IObject(ctx), ExecutionException(msg, element, ctx)
{
}
void VariableException::__construct_impl(String* msg, AbstractSrcElement* element, ThreadContext* ctx) throw() 
{
}
 VariableException::VariableException(String* msg, Throwable* e, ThreadContext* ctx) throw()  : IObject(ctx), ExecutionException(msg, e, ctx)
{
}
void VariableException::__construct_impl(String* msg, Throwable* e, ThreadContext* ctx) throw() 
{
}
 VariableException::VariableException(String* msg, ThreadContext* ctx) throw()  : IObject(ctx), ExecutionException(msg, ctx)
{
}
void VariableException::__construct_impl(String* msg, ThreadContext* ctx) throw() 
{
}
 VariableException::~VariableException() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void VariableException::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	ExecutionException::__releaseRegerences(true, ctx);
}
void VariableException::__cleanUp(ThreadContext* ctx){
}
}}}

