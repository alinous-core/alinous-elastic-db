#include "include/global.h"


#include "alinous.html/IDomObject.h"
#include "alinous.html/DomNode.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.runtime.dom/IDomVariableContainer.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.dom/IDomVariable.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile.expression/DomVariableDescriptor.h"
#include "alinous.runtime.dom.typed/ITypedVariable.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile/Token.h"
#include "alinous.system/AlinousException.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.runtime.dom/IVariableClassOperationCaller.h"
#include "alinous.runtime.dom/VariableOperationCaller.h"
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

namespace alinous {namespace runtime {namespace dom {namespace typed {





String* AbstractTypedVariable::VALUE = ConstStr::getCNST_STR_1159();
IArrayObject<ITypedCaller>* AbstractTypedVariable::typedCallers = nullptr;
bool AbstractTypedVariable::__init_done = __init_static_variables();
bool AbstractTypedVariable::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AbstractTypedVariable", L"__init_static_variables");
		__GC_MV(nullptr, &(typedCallers), (new ArrayObject<ITypedCaller>(createCaller(ctx), ctx)), IArrayObject<ITypedCaller>);
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AbstractTypedVariable::AbstractTypedVariable(ThreadContext* ctx) throw()  : IObject(ctx), ITypedVariable(ctx)
{
}
void AbstractTypedVariable::__construct_impl(ThreadContext* ctx) throw() 
{
}
 AbstractTypedVariable::~AbstractTypedVariable() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AbstractTypedVariable::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
IAlinousVariable* AbstractTypedVariable::add(IAlinousVariable* variable, ThreadContext* ctx)
{
	return VariableOperationCaller::add(this, variable, ctx);
}
IAlinousVariable* AbstractTypedVariable::minus(IAlinousVariable* variable, ThreadContext* ctx)
{
	return VariableOperationCaller::minus(this, variable, ctx);
}
IAlinousVariable* AbstractTypedVariable::multiply(IAlinousVariable* variable, ThreadContext* ctx)
{
	return VariableOperationCaller::multiply(this, variable, ctx);
}
IAlinousVariable* AbstractTypedVariable::div(IAlinousVariable* variable, ThreadContext* ctx)
{
	return VariableOperationCaller::div(this, variable, ctx);
}
IAlinousVariable* AbstractTypedVariable::shiftLeft(IAlinousVariable* variable, ThreadContext* ctx)
{
	return VariableOperationCaller::shiftLeft(this, variable, ctx);
}
IAlinousVariable* AbstractTypedVariable::shiftRight(IAlinousVariable* variable, ThreadContext* ctx)
{
	return VariableOperationCaller::shiftLeft(this, variable, ctx);
}
IAlinousVariable* AbstractTypedVariable::shiftRightUnsigned(IAlinousVariable* variable, ThreadContext* ctx)
{
	return VariableOperationCaller::shiftRightUnsigned(this, variable, ctx);
}
IAlinousVariable* AbstractTypedVariable::modulo(IAlinousVariable* variable, ThreadContext* ctx)
{
	return VariableOperationCaller::modulo(this, variable, ctx);
}
IAlinousVariable* AbstractTypedVariable::substitute(IAlinousVariable* variable, ThreadContext* ctx)
{
	return VariableOperationCaller::substitute(this, variable, ctx);
}
int AbstractTypedVariable::compareTo(IAlinousVariable* variable, ThreadContext* ctx)
{
	return VariableOperationCaller::compareTo(this, variable, ctx);
}
IAlinousVariable* AbstractTypedVariable::bitOr(IAlinousVariable* variable, ThreadContext* ctx)
{
	return VariableOperationCaller::bitOr(this, variable, ctx);
}
IAlinousVariable* AbstractTypedVariable::bitAnd(IAlinousVariable* variable, ThreadContext* ctx)
{
	return VariableOperationCaller::bitAnd(this, variable, ctx);
}
IAlinousVariable* AbstractTypedVariable::bitExor(IAlinousVariable* variable, ThreadContext* ctx)
{
	return VariableOperationCaller::bitAnd(this, variable, ctx);
}
IArrayObject<ITypedCaller>* AbstractTypedVariable::createCaller(ThreadContext* ctx) throw() 
{
	IArrayObject<ITypedCaller>* callers = ArrayAllocator<ITypedCaller>::allocate(ctx, 13);
	callers->set((new(ctx) AbstractTypedVariable::CallerBool(ctx)),ITypedVariable::TYPE_BOOL, ctx);
	callers->set((new(ctx) AbstractTypedVariable::CallerByte(ctx)),ITypedVariable::TYPE_BYTE, ctx);
	callers->set((new(ctx) AbstractTypedVariable::CallerChar(ctx)),ITypedVariable::TYPE_CHAR, ctx);
	callers->set((new(ctx) AbstractTypedVariable::CallerDouble(ctx)),ITypedVariable::TYPE_DOUBLE, ctx);
	callers->set((new(ctx) AbstractTypedVariable::CallerFloat(ctx)),ITypedVariable::TYPE_FLOAT, ctx);
	callers->set((new(ctx) AbstractTypedVariable::CallerInt(ctx)),ITypedVariable::TYPE_INT, ctx);
	callers->set((new(ctx) AbstractTypedVariable::CallerLong(ctx)),ITypedVariable::TYPE_LONG, ctx);
	callers->set((new(ctx) AbstractTypedVariable::CallerShort(ctx)),ITypedVariable::TYPE_SHORT, ctx);
	callers->set((new(ctx) AbstractTypedVariable::CallerString(ctx)),ITypedVariable::TYPE_STRING, ctx);
	callers->set((new(ctx) AbstractTypedVariable::CallerBigDecimal(ctx)),ITypedVariable::TYPE_BIGDECIMAL, ctx);
	callers->set((new(ctx) AbstractTypedVariable::CallerTime(ctx)),ITypedVariable::TYPE_TIME, ctx);
	callers->set((new(ctx) AbstractTypedVariable::CallerTimestamp(ctx)),ITypedVariable::TYPE_TIMESTAMP, ctx);
	callers->set((new(ctx) AbstractTypedVariable::CallerArrayObject(ctx)),ITypedVariable::TYPE_ARRAY, ctx);
	return callers;
}
void AbstractTypedVariable::__cleanUp(ThreadContext* ctx){
	GCUtils<IArrayObject<ITypedCaller>>::dec(nullptr, AbstractTypedVariable::typedCallers, ctx, __FILEW__, __LINE__, L"IArrayObject<ITypedCaller>");
}
int AbstractTypedVariable::ValueCompare::operator() (IAlinousVariable* _this, IAlinousVariable* variable, ThreadContext* ctx) const throw()
{
	return _this->compareTo(variable, ctx);
}
}}}}

namespace alinous {namespace runtime {namespace dom {namespace typed {





bool AbstractTypedVariable::CallerBool::__init_done = __init_static_variables();
bool AbstractTypedVariable::CallerBool::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AbstractTypedVariable::CallerBool", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AbstractTypedVariable::CallerBool::CallerBool(ThreadContext* ctx) throw()  : IObject(ctx), ITypedCaller(ctx)
{
}
void AbstractTypedVariable::CallerBool::__construct_impl(ThreadContext* ctx) throw() 
{
}
 AbstractTypedVariable::CallerBool::~CallerBool() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AbstractTypedVariable::CallerBool::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
IAlinousVariable* AbstractTypedVariable::CallerBool::add(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->add(static_cast<BoolVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerBool::minus(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->minus(static_cast<BoolVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerBool::multiply(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->multiply(static_cast<BoolVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerBool::div(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->div(static_cast<BoolVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerBool::shiftLeft(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->shiftLeft(static_cast<BoolVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerBool::shiftRight(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->shiftRight(static_cast<BoolVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerBool::modulo(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->modulo(static_cast<BoolVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerBool::substitute(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->substitute(static_cast<BoolVariable*>(operand), ctx);
}
int AbstractTypedVariable::CallerBool::compareTo(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->compareTo(static_cast<BoolVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerBool::bitOr(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->bitOr(static_cast<BoolVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerBool::bitAnd(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->bitAnd(static_cast<BoolVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerBool::bitExor(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->bitExor(static_cast<BoolVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerBool::shiftRightUnsigned(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->shiftRightUnsigned(static_cast<BoolVariable*>(operand), ctx);
}
void AbstractTypedVariable::CallerBool::__cleanUp(ThreadContext* ctx){
}
}}}}

namespace alinous {namespace runtime {namespace dom {namespace typed {





bool AbstractTypedVariable::CallerByte::__init_done = __init_static_variables();
bool AbstractTypedVariable::CallerByte::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AbstractTypedVariable::CallerByte", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AbstractTypedVariable::CallerByte::CallerByte(ThreadContext* ctx) throw()  : IObject(ctx), ITypedCaller(ctx)
{
}
void AbstractTypedVariable::CallerByte::__construct_impl(ThreadContext* ctx) throw() 
{
}
 AbstractTypedVariable::CallerByte::~CallerByte() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AbstractTypedVariable::CallerByte::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
IAlinousVariable* AbstractTypedVariable::CallerByte::add(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->add(static_cast<ByteVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerByte::minus(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->minus(static_cast<ByteVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerByte::multiply(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->multiply(static_cast<ByteVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerByte::div(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->div(static_cast<ByteVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerByte::shiftLeft(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->shiftLeft(static_cast<ByteVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerByte::shiftRight(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->shiftRight(static_cast<ByteVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerByte::modulo(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->modulo(static_cast<ByteVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerByte::substitute(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->substitute(static_cast<ByteVariable*>(operand), ctx);
}
int AbstractTypedVariable::CallerByte::compareTo(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->compareTo(static_cast<ByteVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerByte::bitOr(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->bitOr(static_cast<ByteVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerByte::bitAnd(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->bitAnd(static_cast<ByteVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerByte::bitExor(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->bitExor(static_cast<ByteVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerByte::shiftRightUnsigned(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->shiftRightUnsigned(static_cast<ByteVariable*>(operand), ctx);
}
void AbstractTypedVariable::CallerByte::__cleanUp(ThreadContext* ctx){
}
}}}}

namespace alinous {namespace runtime {namespace dom {namespace typed {





bool AbstractTypedVariable::CallerChar::__init_done = __init_static_variables();
bool AbstractTypedVariable::CallerChar::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AbstractTypedVariable::CallerChar", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AbstractTypedVariable::CallerChar::CallerChar(ThreadContext* ctx) throw()  : IObject(ctx), ITypedCaller(ctx)
{
}
void AbstractTypedVariable::CallerChar::__construct_impl(ThreadContext* ctx) throw() 
{
}
 AbstractTypedVariable::CallerChar::~CallerChar() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AbstractTypedVariable::CallerChar::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
IAlinousVariable* AbstractTypedVariable::CallerChar::add(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->add(static_cast<CharVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerChar::minus(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->minus(static_cast<CharVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerChar::multiply(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->multiply(static_cast<CharVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerChar::div(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->div(static_cast<CharVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerChar::shiftLeft(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->shiftLeft(static_cast<CharVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerChar::shiftRight(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->shiftRight(static_cast<CharVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerChar::modulo(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->modulo(static_cast<CharVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerChar::substitute(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->substitute(static_cast<CharVariable*>(operand), ctx);
}
int AbstractTypedVariable::CallerChar::compareTo(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->compareTo(static_cast<CharVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerChar::bitOr(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->bitOr(static_cast<CharVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerChar::bitAnd(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->bitAnd(static_cast<CharVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerChar::bitExor(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->bitExor(static_cast<CharVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerChar::shiftRightUnsigned(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->shiftRightUnsigned(static_cast<CharVariable*>(operand), ctx);
}
void AbstractTypedVariable::CallerChar::__cleanUp(ThreadContext* ctx){
}
}}}}

namespace alinous {namespace runtime {namespace dom {namespace typed {





bool AbstractTypedVariable::CallerDouble::__init_done = __init_static_variables();
bool AbstractTypedVariable::CallerDouble::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AbstractTypedVariable::CallerDouble", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AbstractTypedVariable::CallerDouble::CallerDouble(ThreadContext* ctx) throw()  : IObject(ctx), ITypedCaller(ctx)
{
}
void AbstractTypedVariable::CallerDouble::__construct_impl(ThreadContext* ctx) throw() 
{
}
 AbstractTypedVariable::CallerDouble::~CallerDouble() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AbstractTypedVariable::CallerDouble::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
IAlinousVariable* AbstractTypedVariable::CallerDouble::add(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->add(static_cast<DoubleVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerDouble::minus(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->minus(static_cast<DoubleVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerDouble::multiply(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->multiply(static_cast<DoubleVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerDouble::div(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->div(static_cast<DoubleVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerDouble::shiftLeft(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->shiftLeft(static_cast<DoubleVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerDouble::shiftRight(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->shiftRight(static_cast<DoubleVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerDouble::modulo(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->modulo(static_cast<DoubleVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerDouble::substitute(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->substitute(static_cast<DoubleVariable*>(operand), ctx);
}
int AbstractTypedVariable::CallerDouble::compareTo(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->compareTo(static_cast<DoubleVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerDouble::bitOr(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->bitOr(static_cast<DoubleVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerDouble::bitAnd(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->bitAnd(static_cast<DoubleVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerDouble::bitExor(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->bitExor(static_cast<DoubleVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerDouble::shiftRightUnsigned(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->bitExor(static_cast<DoubleVariable*>(operand), ctx);
}
void AbstractTypedVariable::CallerDouble::__cleanUp(ThreadContext* ctx){
}
}}}}

namespace alinous {namespace runtime {namespace dom {namespace typed {





bool AbstractTypedVariable::CallerFloat::__init_done = __init_static_variables();
bool AbstractTypedVariable::CallerFloat::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AbstractTypedVariable::CallerFloat", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AbstractTypedVariable::CallerFloat::CallerFloat(ThreadContext* ctx) throw()  : IObject(ctx), ITypedCaller(ctx)
{
}
void AbstractTypedVariable::CallerFloat::__construct_impl(ThreadContext* ctx) throw() 
{
}
 AbstractTypedVariable::CallerFloat::~CallerFloat() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AbstractTypedVariable::CallerFloat::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
IAlinousVariable* AbstractTypedVariable::CallerFloat::add(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->add(static_cast<FloatVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerFloat::minus(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->minus(static_cast<FloatVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerFloat::multiply(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->multiply(static_cast<FloatVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerFloat::div(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->div(static_cast<FloatVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerFloat::shiftLeft(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->shiftLeft(static_cast<FloatVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerFloat::shiftRight(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->shiftRight(static_cast<FloatVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerFloat::modulo(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->modulo(static_cast<FloatVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerFloat::substitute(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->substitute(static_cast<FloatVariable*>(operand), ctx);
}
int AbstractTypedVariable::CallerFloat::compareTo(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->compareTo(static_cast<FloatVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerFloat::bitOr(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->bitOr(static_cast<FloatVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerFloat::bitAnd(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->bitAnd(static_cast<FloatVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerFloat::bitExor(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->bitExor(static_cast<FloatVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerFloat::shiftRightUnsigned(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->shiftRightUnsigned(static_cast<FloatVariable*>(operand), ctx);
}
void AbstractTypedVariable::CallerFloat::__cleanUp(ThreadContext* ctx){
}
}}}}

namespace alinous {namespace runtime {namespace dom {namespace typed {





bool AbstractTypedVariable::CallerInt::__init_done = __init_static_variables();
bool AbstractTypedVariable::CallerInt::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AbstractTypedVariable::CallerInt", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AbstractTypedVariable::CallerInt::CallerInt(ThreadContext* ctx) throw()  : IObject(ctx), ITypedCaller(ctx)
{
}
void AbstractTypedVariable::CallerInt::__construct_impl(ThreadContext* ctx) throw() 
{
}
 AbstractTypedVariable::CallerInt::~CallerInt() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AbstractTypedVariable::CallerInt::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
IAlinousVariable* AbstractTypedVariable::CallerInt::add(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->add(static_cast<IntegerVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerInt::minus(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->minus(static_cast<IntegerVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerInt::multiply(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->multiply(static_cast<IntegerVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerInt::div(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->div(static_cast<IntegerVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerInt::shiftLeft(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->shiftLeft(static_cast<IntegerVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerInt::shiftRight(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->shiftRight(static_cast<IntegerVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerInt::modulo(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->modulo(static_cast<IntegerVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerInt::substitute(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->substitute(static_cast<IntegerVariable*>(operand), ctx);
}
int AbstractTypedVariable::CallerInt::compareTo(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->compareTo(static_cast<IntegerVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerInt::bitOr(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->bitOr(static_cast<IntegerVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerInt::bitAnd(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->bitAnd(static_cast<IntegerVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerInt::bitExor(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->bitExor(static_cast<IntegerVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerInt::shiftRightUnsigned(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->shiftRightUnsigned(static_cast<IntegerVariable*>(operand), ctx);
}
void AbstractTypedVariable::CallerInt::__cleanUp(ThreadContext* ctx){
}
}}}}

namespace alinous {namespace runtime {namespace dom {namespace typed {





bool AbstractTypedVariable::CallerLong::__init_done = __init_static_variables();
bool AbstractTypedVariable::CallerLong::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AbstractTypedVariable::CallerLong", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AbstractTypedVariable::CallerLong::CallerLong(ThreadContext* ctx) throw()  : IObject(ctx), ITypedCaller(ctx)
{
}
void AbstractTypedVariable::CallerLong::__construct_impl(ThreadContext* ctx) throw() 
{
}
 AbstractTypedVariable::CallerLong::~CallerLong() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AbstractTypedVariable::CallerLong::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
IAlinousVariable* AbstractTypedVariable::CallerLong::add(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->add(static_cast<LongVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerLong::minus(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->minus(static_cast<LongVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerLong::multiply(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->multiply(static_cast<LongVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerLong::div(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->div(static_cast<LongVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerLong::shiftLeft(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->shiftLeft(static_cast<LongVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerLong::shiftRight(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->shiftRight(static_cast<LongVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerLong::modulo(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->modulo(static_cast<LongVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerLong::substitute(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->substitute(static_cast<LongVariable*>(operand), ctx);
}
int AbstractTypedVariable::CallerLong::compareTo(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->compareTo(static_cast<LongVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerLong::bitOr(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->bitOr(static_cast<LongVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerLong::bitAnd(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->bitAnd(static_cast<LongVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerLong::bitExor(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->bitExor(static_cast<LongVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerLong::shiftRightUnsigned(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->shiftRightUnsigned(static_cast<LongVariable*>(operand), ctx);
}
void AbstractTypedVariable::CallerLong::__cleanUp(ThreadContext* ctx){
}
}}}}

namespace alinous {namespace runtime {namespace dom {namespace typed {





bool AbstractTypedVariable::CallerShort::__init_done = __init_static_variables();
bool AbstractTypedVariable::CallerShort::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AbstractTypedVariable::CallerShort", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AbstractTypedVariable::CallerShort::CallerShort(ThreadContext* ctx) throw()  : IObject(ctx), ITypedCaller(ctx)
{
}
void AbstractTypedVariable::CallerShort::__construct_impl(ThreadContext* ctx) throw() 
{
}
 AbstractTypedVariable::CallerShort::~CallerShort() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AbstractTypedVariable::CallerShort::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
IAlinousVariable* AbstractTypedVariable::CallerShort::add(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->add(static_cast<ShortVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerShort::minus(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->minus(static_cast<ShortVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerShort::multiply(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->multiply(static_cast<ShortVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerShort::div(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->div(static_cast<ShortVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerShort::shiftLeft(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->shiftLeft(static_cast<ShortVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerShort::shiftRight(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->shiftRight(static_cast<ShortVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerShort::modulo(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->modulo(static_cast<ShortVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerShort::substitute(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->substitute(static_cast<ShortVariable*>(operand), ctx);
}
int AbstractTypedVariable::CallerShort::compareTo(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->compareTo(static_cast<ShortVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerShort::bitOr(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->bitOr(static_cast<ShortVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerShort::bitAnd(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->bitAnd(static_cast<ShortVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerShort::bitExor(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->bitExor(static_cast<ShortVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerShort::shiftRightUnsigned(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->shiftRightUnsigned(static_cast<ShortVariable*>(operand), ctx);
}
void AbstractTypedVariable::CallerShort::__cleanUp(ThreadContext* ctx){
}
}}}}

namespace alinous {namespace runtime {namespace dom {namespace typed {





bool AbstractTypedVariable::CallerString::__init_done = __init_static_variables();
bool AbstractTypedVariable::CallerString::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AbstractTypedVariable::CallerString", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AbstractTypedVariable::CallerString::CallerString(ThreadContext* ctx) throw()  : IObject(ctx), ITypedCaller(ctx)
{
}
void AbstractTypedVariable::CallerString::__construct_impl(ThreadContext* ctx) throw() 
{
}
 AbstractTypedVariable::CallerString::~CallerString() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AbstractTypedVariable::CallerString::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
IAlinousVariable* AbstractTypedVariable::CallerString::add(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->add(static_cast<StringVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerString::minus(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->minus(static_cast<StringVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerString::multiply(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->multiply(static_cast<StringVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerString::div(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->div(static_cast<StringVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerString::shiftLeft(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->shiftLeft(static_cast<StringVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerString::shiftRight(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->shiftRight(static_cast<StringVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerString::modulo(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->modulo(static_cast<StringVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerString::substitute(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->substitute(static_cast<StringVariable*>(operand), ctx);
}
int AbstractTypedVariable::CallerString::compareTo(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->compareTo(static_cast<StringVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerString::bitOr(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->bitOr(static_cast<StringVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerString::bitAnd(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->bitAnd(static_cast<StringVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerString::bitExor(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->bitExor(static_cast<StringVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerString::shiftRightUnsigned(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->shiftRightUnsigned(static_cast<StringVariable*>(operand), ctx);
}
void AbstractTypedVariable::CallerString::__cleanUp(ThreadContext* ctx){
}
}}}}

namespace alinous {namespace runtime {namespace dom {namespace typed {





bool AbstractTypedVariable::CallerBigDecimal::__init_done = __init_static_variables();
bool AbstractTypedVariable::CallerBigDecimal::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AbstractTypedVariable::CallerBigDecimal", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AbstractTypedVariable::CallerBigDecimal::CallerBigDecimal(ThreadContext* ctx) throw()  : IObject(ctx), ITypedCaller(ctx)
{
}
void AbstractTypedVariable::CallerBigDecimal::__construct_impl(ThreadContext* ctx) throw() 
{
}
 AbstractTypedVariable::CallerBigDecimal::~CallerBigDecimal() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AbstractTypedVariable::CallerBigDecimal::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
IAlinousVariable* AbstractTypedVariable::CallerBigDecimal::add(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->add(static_cast<BigDecimalVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerBigDecimal::minus(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->minus(static_cast<BigDecimalVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerBigDecimal::multiply(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->multiply(static_cast<BigDecimalVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerBigDecimal::div(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->div(static_cast<BigDecimalVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerBigDecimal::shiftLeft(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->shiftLeft(static_cast<BigDecimalVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerBigDecimal::shiftRight(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->shiftRight(static_cast<BigDecimalVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerBigDecimal::modulo(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->modulo(static_cast<BigDecimalVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerBigDecimal::substitute(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->substitute(static_cast<BigDecimalVariable*>(operand), ctx);
}
int AbstractTypedVariable::CallerBigDecimal::compareTo(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->compareTo(static_cast<BigDecimalVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerBigDecimal::bitOr(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->bitOr(static_cast<BigDecimalVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerBigDecimal::bitAnd(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->bitAnd(static_cast<BigDecimalVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerBigDecimal::bitExor(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->bitExor(static_cast<BigDecimalVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerBigDecimal::shiftRightUnsigned(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->shiftRightUnsigned(static_cast<BigDecimalVariable*>(operand), ctx);
}
void AbstractTypedVariable::CallerBigDecimal::__cleanUp(ThreadContext* ctx){
}
}}}}

namespace alinous {namespace runtime {namespace dom {namespace typed {





bool AbstractTypedVariable::CallerTime::__init_done = __init_static_variables();
bool AbstractTypedVariable::CallerTime::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AbstractTypedVariable::CallerTime", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AbstractTypedVariable::CallerTime::CallerTime(ThreadContext* ctx) throw()  : IObject(ctx), ITypedCaller(ctx)
{
}
void AbstractTypedVariable::CallerTime::__construct_impl(ThreadContext* ctx) throw() 
{
}
 AbstractTypedVariable::CallerTime::~CallerTime() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AbstractTypedVariable::CallerTime::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
IAlinousVariable* AbstractTypedVariable::CallerTime::add(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->add(static_cast<TimeVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerTime::minus(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->minus(static_cast<TimeVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerTime::multiply(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->multiply(static_cast<TimeVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerTime::div(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->div(static_cast<TimeVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerTime::shiftLeft(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->shiftLeft(static_cast<TimeVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerTime::shiftRight(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->shiftRight(static_cast<TimeVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerTime::modulo(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->modulo(static_cast<TimeVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerTime::substitute(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->substitute(static_cast<TimeVariable*>(operand), ctx);
}
int AbstractTypedVariable::CallerTime::compareTo(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->compareTo(static_cast<TimeVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerTime::bitOr(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->bitOr(static_cast<TimeVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerTime::bitAnd(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->bitAnd(static_cast<TimeVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerTime::bitExor(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->bitExor(static_cast<TimeVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerTime::shiftRightUnsigned(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->shiftRightUnsigned(static_cast<TimeVariable*>(operand), ctx);
}
void AbstractTypedVariable::CallerTime::__cleanUp(ThreadContext* ctx){
}
}}}}

namespace alinous {namespace runtime {namespace dom {namespace typed {





bool AbstractTypedVariable::CallerTimestamp::__init_done = __init_static_variables();
bool AbstractTypedVariable::CallerTimestamp::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AbstractTypedVariable::CallerTimestamp", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AbstractTypedVariable::CallerTimestamp::CallerTimestamp(ThreadContext* ctx) throw()  : IObject(ctx), ITypedCaller(ctx)
{
}
void AbstractTypedVariable::CallerTimestamp::__construct_impl(ThreadContext* ctx) throw() 
{
}
 AbstractTypedVariable::CallerTimestamp::~CallerTimestamp() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AbstractTypedVariable::CallerTimestamp::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
IAlinousVariable* AbstractTypedVariable::CallerTimestamp::add(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->add(static_cast<TimestampVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerTimestamp::minus(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->minus(static_cast<TimestampVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerTimestamp::multiply(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->multiply(static_cast<TimestampVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerTimestamp::div(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->div(static_cast<TimestampVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerTimestamp::shiftLeft(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->shiftLeft(static_cast<TimestampVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerTimestamp::shiftRight(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->shiftRight(static_cast<TimestampVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerTimestamp::modulo(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->modulo(static_cast<TimestampVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerTimestamp::substitute(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->substitute(static_cast<TimestampVariable*>(operand), ctx);
}
int AbstractTypedVariable::CallerTimestamp::compareTo(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->compareTo(static_cast<TimestampVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerTimestamp::bitOr(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->bitOr(static_cast<TimestampVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerTimestamp::bitAnd(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->bitAnd(static_cast<TimestampVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerTimestamp::bitExor(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->bitExor(static_cast<TimestampVariable*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerTimestamp::shiftRightUnsigned(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->shiftRightUnsigned(static_cast<TimestampVariable*>(operand), ctx);
}
void AbstractTypedVariable::CallerTimestamp::__cleanUp(ThreadContext* ctx){
}
}}}}

namespace alinous {namespace runtime {namespace dom {namespace typed {





bool AbstractTypedVariable::CallerArrayObject::__init_done = __init_static_variables();
bool AbstractTypedVariable::CallerArrayObject::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AbstractTypedVariable::CallerArrayObject", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AbstractTypedVariable::CallerArrayObject::CallerArrayObject(ThreadContext* ctx) throw()  : IObject(ctx), ITypedCaller(ctx)
{
}
void AbstractTypedVariable::CallerArrayObject::__construct_impl(ThreadContext* ctx) throw() 
{
}
 AbstractTypedVariable::CallerArrayObject::~CallerArrayObject() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AbstractTypedVariable::CallerArrayObject::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
IAlinousVariable* AbstractTypedVariable::CallerArrayObject::add(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->add(static_cast<TypedVariableArray*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerArrayObject::minus(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->minus(static_cast<TypedVariableArray*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerArrayObject::multiply(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->multiply(static_cast<TypedVariableArray*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerArrayObject::div(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->div(static_cast<TypedVariableArray*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerArrayObject::shiftLeft(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->shiftLeft(static_cast<TypedVariableArray*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerArrayObject::shiftRight(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->shiftRight(static_cast<TypedVariableArray*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerArrayObject::modulo(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->modulo(static_cast<TypedVariableArray*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerArrayObject::substitute(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->substitute(static_cast<TypedVariableArray*>(operand), ctx);
}
int AbstractTypedVariable::CallerArrayObject::compareTo(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->compareTo(static_cast<TypedVariableArray*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerArrayObject::bitOr(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->bitOr(static_cast<TypedVariableArray*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerArrayObject::bitAnd(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->bitAnd(static_cast<TypedVariableArray*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerArrayObject::bitExor(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->bitExor(static_cast<TypedVariableArray*>(operand), ctx);
}
IAlinousVariable* AbstractTypedVariable::CallerArrayObject::shiftRightUnsigned(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx)
{
	return variable->shiftRightUnsigned(static_cast<TypedVariableArray*>(operand), ctx);
}
void AbstractTypedVariable::CallerArrayObject::__cleanUp(ThreadContext* ctx){
}
}}}}

