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





IArrayObject<IVariableClassOperationCaller>* VariableOperationCaller::callers = nullptr;
bool VariableOperationCaller::__init_done = __init_static_variables();
bool VariableOperationCaller::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"VariableOperationCaller", L"__init_static_variables");
		__GC_MV(nullptr, &(callers), (new ArrayObject<IVariableClassOperationCaller>(createCallers(ctx), ctx)), IArrayObject<IVariableClassOperationCaller>);
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 VariableOperationCaller::VariableOperationCaller(ThreadContext* ctx) throw()  : IObject(ctx)
{
}
void VariableOperationCaller::__construct_impl(ThreadContext* ctx) throw() 
{
}
 VariableOperationCaller::~VariableOperationCaller() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void VariableOperationCaller::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
IArrayObject<IVariableClassOperationCaller>* VariableOperationCaller::createCallers(ThreadContext* ctx) throw() 
{
	IArrayObject<IVariableClassOperationCaller>* callers = ArrayAllocator<IVariableClassOperationCaller>::allocate(ctx, 4);
	callers->set((new(ctx) VariableOperationCaller::VariantCaller(ctx)),IAlinousVariable::CLASS_VARIANT, ctx);
	callers->set((new(ctx) VariableOperationCaller::DomCaller(ctx)),IAlinousVariable::CLASS_DOM, ctx);
	callers->set((new(ctx) VariableOperationCaller::ObjectCaller(ctx)),IAlinousVariable::CLASS_OBJECT, ctx);
	callers->set((new(ctx) VariableOperationCaller::TypedVariableCaller(ctx)),IAlinousVariable::CLASS_TYPED, ctx);
	return callers;
}
IAlinousVariable* VariableOperationCaller::add(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	int variableClass = operand->getVariableClass(ctx);
	return callers->get(variableClass)->add(variable, operand, ctx);
}
IAlinousVariable* VariableOperationCaller::minus(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	int variableClass = operand->getVariableClass(ctx);
	return callers->get(variableClass)->minus(variable, operand, ctx);
}
IAlinousVariable* VariableOperationCaller::multiply(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	int variableClass = operand->getVariableClass(ctx);
	return callers->get(variableClass)->multiply(variable, operand, ctx);
}
IAlinousVariable* VariableOperationCaller::div(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	int variableClass = operand->getVariableClass(ctx);
	return callers->get(variableClass)->div(variable, operand, ctx);
}
IAlinousVariable* VariableOperationCaller::shiftLeft(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	int variableClass = operand->getVariableClass(ctx);
	return callers->get(variableClass)->shiftLeft(variable, operand, ctx);
}
IAlinousVariable* VariableOperationCaller::shiftRight(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	int variableClass = operand->getVariableClass(ctx);
	return callers->get(variableClass)->shiftRight(variable, operand, ctx);
}
IAlinousVariable* VariableOperationCaller::shiftRightUnsigned(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	int variableClass = operand->getVariableClass(ctx);
	return callers->get(variableClass)->shiftRightUnsigned(variable, operand, ctx);
}
IAlinousVariable* VariableOperationCaller::modulo(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	int variableClass = operand->getVariableClass(ctx);
	return callers->get(variableClass)->modulo(variable, operand, ctx);
}
IAlinousVariable* VariableOperationCaller::substitute(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	int variableClass = operand->getVariableClass(ctx);
	return callers->get(variableClass)->substitute(variable, operand, ctx);
}
int VariableOperationCaller::compareTo(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	int variableClass = operand->getVariableClass(ctx);
	return callers->get(variableClass)->compareTo(variable, operand, ctx);
}
IAlinousVariable* VariableOperationCaller::bitOr(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	int variableClass = operand->getVariableClass(ctx);
	return callers->get(variableClass)->bitOr(variable, operand, ctx);
}
IAlinousVariable* VariableOperationCaller::bitAnd(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	int variableClass = operand->getVariableClass(ctx);
	return callers->get(variableClass)->bitAnd(variable, operand, ctx);
}
IAlinousVariable* VariableOperationCaller::bitExor(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	int variableClass = operand->getVariableClass(ctx);
	return callers->get(variableClass)->bitExor(variable, operand, ctx);
}
void VariableOperationCaller::__cleanUp(ThreadContext* ctx){
	GCUtils<IArrayObject<IVariableClassOperationCaller>>::dec(nullptr, VariableOperationCaller::callers, ctx, __FILEW__, __LINE__, L"IArrayObject<IVariableClassOperationCaller>");
}
}}}

namespace alinous {namespace runtime {namespace dom {





bool VariableOperationCaller::VariantCaller::__init_done = __init_static_variables();
bool VariableOperationCaller::VariantCaller::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"VariableOperationCaller::VariantCaller", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 VariableOperationCaller::VariantCaller::VariantCaller(ThreadContext* ctx) throw()  : IObject(ctx), IVariableClassOperationCaller(ctx)
{
}
void VariableOperationCaller::VariantCaller::__construct_impl(ThreadContext* ctx) throw() 
{
}
 VariableOperationCaller::VariantCaller::~VariantCaller() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void VariableOperationCaller::VariantCaller::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
IAlinousVariable* VariableOperationCaller::VariantCaller::add(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->add(static_cast<VariantValue*>(operand), ctx);
}
IAlinousVariable* VariableOperationCaller::VariantCaller::minus(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->minus(static_cast<VariantValue*>(operand), ctx);
}
IAlinousVariable* VariableOperationCaller::VariantCaller::multiply(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->multiply(static_cast<VariantValue*>(operand), ctx);
}
IAlinousVariable* VariableOperationCaller::VariantCaller::div(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->div(static_cast<VariantValue*>(operand), ctx);
}
IAlinousVariable* VariableOperationCaller::VariantCaller::shiftLeft(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->shiftLeft(static_cast<VariantValue*>(operand), ctx);
}
IAlinousVariable* VariableOperationCaller::VariantCaller::shiftRight(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->shiftRight(static_cast<VariantValue*>(operand), ctx);
}
IAlinousVariable* VariableOperationCaller::VariantCaller::modulo(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->modulo(static_cast<VariantValue*>(operand), ctx);
}
IAlinousVariable* VariableOperationCaller::VariantCaller::substitute(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->substitute(static_cast<VariantValue*>(operand), ctx);
}
int VariableOperationCaller::VariantCaller::compareTo(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->compareTo(static_cast<VariantValue*>(operand), ctx);
}
IAlinousVariable* VariableOperationCaller::VariantCaller::bitOr(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->bitOr(static_cast<VariantValue*>(operand), ctx);
}
IAlinousVariable* VariableOperationCaller::VariantCaller::bitAnd(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->bitAnd(static_cast<VariantValue*>(operand), ctx);
}
IAlinousVariable* VariableOperationCaller::VariantCaller::bitExor(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->bitAnd(static_cast<VariantValue*>(operand), ctx);
}
IAlinousVariable* VariableOperationCaller::VariantCaller::shiftRightUnsigned(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->shiftRightUnsigned(static_cast<VariantValue*>(operand), ctx);
}
void VariableOperationCaller::VariantCaller::__cleanUp(ThreadContext* ctx){
}
}}}

namespace alinous {namespace runtime {namespace dom {





bool VariableOperationCaller::DomCaller::__init_done = __init_static_variables();
bool VariableOperationCaller::DomCaller::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"VariableOperationCaller::DomCaller", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 VariableOperationCaller::DomCaller::DomCaller(ThreadContext* ctx) throw()  : IObject(ctx), IVariableClassOperationCaller(ctx)
{
}
void VariableOperationCaller::DomCaller::__construct_impl(ThreadContext* ctx) throw() 
{
}
 VariableOperationCaller::DomCaller::~DomCaller() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void VariableOperationCaller::DomCaller::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
IAlinousVariable* VariableOperationCaller::DomCaller::add(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->add(static_cast<DomVariable*>(operand), ctx);
}
IAlinousVariable* VariableOperationCaller::DomCaller::minus(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->minus(static_cast<DomVariable*>(operand), ctx);
}
IAlinousVariable* VariableOperationCaller::DomCaller::multiply(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->multiply(static_cast<DomVariable*>(operand), ctx);
}
IAlinousVariable* VariableOperationCaller::DomCaller::div(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->div(static_cast<DomVariable*>(operand), ctx);
}
IAlinousVariable* VariableOperationCaller::DomCaller::shiftLeft(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->shiftLeft(static_cast<DomVariable*>(operand), ctx);
}
IAlinousVariable* VariableOperationCaller::DomCaller::shiftRight(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->shiftRight(static_cast<DomVariable*>(operand), ctx);
}
IAlinousVariable* VariableOperationCaller::DomCaller::modulo(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->modulo(static_cast<DomVariable*>(operand), ctx);
}
IAlinousVariable* VariableOperationCaller::DomCaller::substitute(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->substitute(static_cast<DomVariable*>(operand), ctx);
}
int VariableOperationCaller::DomCaller::compareTo(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->compareTo(static_cast<DomVariable*>(operand), ctx);
}
IAlinousVariable* VariableOperationCaller::DomCaller::bitOr(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->bitOr(static_cast<DomVariable*>(operand), ctx);
}
IAlinousVariable* VariableOperationCaller::DomCaller::bitAnd(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->bitAnd(static_cast<DomVariable*>(operand), ctx);
}
IAlinousVariable* VariableOperationCaller::DomCaller::bitExor(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->bitExor(static_cast<DomVariable*>(operand), ctx);
}
IAlinousVariable* VariableOperationCaller::DomCaller::shiftRightUnsigned(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->shiftRightUnsigned(static_cast<DomVariable*>(operand), ctx);
}
void VariableOperationCaller::DomCaller::__cleanUp(ThreadContext* ctx){
}
}}}

namespace alinous {namespace runtime {namespace dom {





bool VariableOperationCaller::ObjectCaller::__init_done = __init_static_variables();
bool VariableOperationCaller::ObjectCaller::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"VariableOperationCaller::ObjectCaller", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 VariableOperationCaller::ObjectCaller::ObjectCaller(ThreadContext* ctx) throw()  : IObject(ctx), IVariableClassOperationCaller(ctx)
{
}
void VariableOperationCaller::ObjectCaller::__construct_impl(ThreadContext* ctx) throw() 
{
}
 VariableOperationCaller::ObjectCaller::~ObjectCaller() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void VariableOperationCaller::ObjectCaller::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
IAlinousVariable* VariableOperationCaller::ObjectCaller::add(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1114(), ctx));
}
IAlinousVariable* VariableOperationCaller::ObjectCaller::minus(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1114(), ctx));
}
IAlinousVariable* VariableOperationCaller::ObjectCaller::multiply(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1114(), ctx));
}
IAlinousVariable* VariableOperationCaller::ObjectCaller::div(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1114(), ctx));
}
IAlinousVariable* VariableOperationCaller::ObjectCaller::shiftLeft(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1114(), ctx));
}
IAlinousVariable* VariableOperationCaller::ObjectCaller::shiftRight(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1114(), ctx));
}
IAlinousVariable* VariableOperationCaller::ObjectCaller::modulo(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1114(), ctx));
}
IAlinousVariable* VariableOperationCaller::ObjectCaller::substitute(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1114(), ctx));
}
int VariableOperationCaller::ObjectCaller::compareTo(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1114(), ctx));
}
IAlinousVariable* VariableOperationCaller::ObjectCaller::bitOr(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1114(), ctx));
}
IAlinousVariable* VariableOperationCaller::ObjectCaller::bitAnd(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1114(), ctx));
}
IAlinousVariable* VariableOperationCaller::ObjectCaller::bitExor(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1114(), ctx));
}
IAlinousVariable* VariableOperationCaller::ObjectCaller::shiftRightUnsigned(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1114(), ctx));
}
void VariableOperationCaller::ObjectCaller::__cleanUp(ThreadContext* ctx){
}
}}}

namespace alinous {namespace runtime {namespace dom {





bool VariableOperationCaller::TypedVariableCaller::__init_done = __init_static_variables();
bool VariableOperationCaller::TypedVariableCaller::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"VariableOperationCaller::TypedVariableCaller", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 VariableOperationCaller::TypedVariableCaller::TypedVariableCaller(ThreadContext* ctx) throw()  : IObject(ctx), IVariableClassOperationCaller(ctx)
{
}
void VariableOperationCaller::TypedVariableCaller::__construct_impl(ThreadContext* ctx) throw() 
{
}
 VariableOperationCaller::TypedVariableCaller::~TypedVariableCaller() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void VariableOperationCaller::TypedVariableCaller::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
IAlinousVariable* VariableOperationCaller::TypedVariableCaller::add(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	int type = (static_cast<ITypedVariable*>(operand))->getTypedType(ctx);
	return AbstractTypedVariable::typedCallers->get(type)->add(variable, operand, ctx);
}
IAlinousVariable* VariableOperationCaller::TypedVariableCaller::minus(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	int type = (static_cast<ITypedVariable*>(operand))->getTypedType(ctx);
	return AbstractTypedVariable::typedCallers->get(type)->minus(variable, operand, ctx);
}
IAlinousVariable* VariableOperationCaller::TypedVariableCaller::multiply(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	int type = (static_cast<ITypedVariable*>(operand))->getTypedType(ctx);
	return AbstractTypedVariable::typedCallers->get(type)->multiply(variable, operand, ctx);
}
IAlinousVariable* VariableOperationCaller::TypedVariableCaller::div(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	int type = (static_cast<ITypedVariable*>(operand))->getTypedType(ctx);
	return AbstractTypedVariable::typedCallers->get(type)->div(variable, operand, ctx);
}
IAlinousVariable* VariableOperationCaller::TypedVariableCaller::shiftLeft(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	int type = (static_cast<ITypedVariable*>(operand))->getTypedType(ctx);
	return AbstractTypedVariable::typedCallers->get(type)->shiftLeft(variable, operand, ctx);
}
IAlinousVariable* VariableOperationCaller::TypedVariableCaller::shiftRight(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	int type = (static_cast<ITypedVariable*>(operand))->getTypedType(ctx);
	return AbstractTypedVariable::typedCallers->get(type)->shiftRight(variable, operand, ctx);
}
IAlinousVariable* VariableOperationCaller::TypedVariableCaller::modulo(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	int type = (static_cast<ITypedVariable*>(operand))->getTypedType(ctx);
	return AbstractTypedVariable::typedCallers->get(type)->modulo(variable, operand, ctx);
}
IAlinousVariable* VariableOperationCaller::TypedVariableCaller::substitute(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	int type = (static_cast<ITypedVariable*>(operand))->getTypedType(ctx);
	return AbstractTypedVariable::typedCallers->get(type)->substitute(variable, operand, ctx);
}
int VariableOperationCaller::TypedVariableCaller::compareTo(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	int type = (static_cast<ITypedVariable*>(operand))->getTypedType(ctx);
	return AbstractTypedVariable::typedCallers->get(type)->compareTo(variable, operand, ctx);
}
IAlinousVariable* VariableOperationCaller::TypedVariableCaller::bitOr(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	int type = (static_cast<ITypedVariable*>(operand))->getTypedType(ctx);
	return AbstractTypedVariable::typedCallers->get(type)->bitOr(variable, operand, ctx);
}
IAlinousVariable* VariableOperationCaller::TypedVariableCaller::bitAnd(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	int type = (static_cast<ITypedVariable*>(operand))->getTypedType(ctx);
	return AbstractTypedVariable::typedCallers->get(type)->bitAnd(variable, operand, ctx);
}
IAlinousVariable* VariableOperationCaller::TypedVariableCaller::bitExor(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	int type = (static_cast<ITypedVariable*>(operand))->getTypedType(ctx);
	return AbstractTypedVariable::typedCallers->get(type)->bitExor(variable, operand, ctx);
}
IAlinousVariable* VariableOperationCaller::TypedVariableCaller::shiftRightUnsigned(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	int type = (static_cast<ITypedVariable*>(operand))->getTypedType(ctx);
	return AbstractTypedVariable::typedCallers->get(type)->shiftRightUnsigned(variable, operand, ctx);
}
void VariableOperationCaller::TypedVariableCaller::__cleanUp(ThreadContext* ctx){
}
}}}

