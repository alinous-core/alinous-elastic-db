#include "includes.h"


namespace alinous {namespace runtime {namespace dom {





bool DocumentVariable::__init_done = __init_static_variables();
bool DocumentVariable::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DocumentVariable", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 DocumentVariable::DocumentVariable(ThreadContext* ctx) throw()  : IObject(ctx), IDomVariable(ctx), value(nullptr)
{
	__GC_MV(this, &(this->value), (new(ctx) DomVariable(ctx)), IDomVariable);
}
void DocumentVariable::__construct_impl(ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->value), (new(ctx) DomVariable(ctx)), IDomVariable);
}
 DocumentVariable::DocumentVariable(bool array, ThreadContext* ctx) throw()  : IObject(ctx), IDomVariable(ctx), value(nullptr)
{
	if(array)
	{
		__GC_MV(this, &(this->value), (new(ctx) DomArray(ctx)), IDomVariable);
	}
		else 
	{
		__GC_MV(this, &(this->value), (new(ctx) DomVariable(ctx)), IDomVariable);
	}
}
void DocumentVariable::__construct_impl(bool array, ThreadContext* ctx) throw() 
{
	if(array)
	{
		__GC_MV(this, &(this->value), (new(ctx) DomArray(ctx)), IDomVariable);
	}
		else 
	{
		__GC_MV(this, &(this->value), (new(ctx) DomVariable(ctx)), IDomVariable);
	}
}
 DocumentVariable::~DocumentVariable() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void DocumentVariable::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"DocumentVariable", L"~DocumentVariable");
	__e_obj1.add(this->value, this);
	value = nullptr;
	if(!prepare){
		return;
	}
}
void DocumentVariable::outDebugXml(DomNode* parentNode, String* name, ThreadContext* ctx) throw() 
{
	if(this->value != nullptr)
	{
		this->value->outDebugXml(parentNode, name, ctx);
	}
}
IDomVariable* DocumentVariable::getByDescriptor(DomVariableDescriptor* desc, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ctx));
}
void DocumentVariable::setProperty(String* key, IDomVariable* value, ThreadContext* ctx)
{
	this->value->setProperty(key, value, ctx);
}
IDomVariableContainer* DocumentVariable::getProperty(String* key, ThreadContext* ctx)
{
	return this->value->getProperty(key, ctx);
}
IDomVariableContainer* DocumentVariable::get(int index, ThreadContext* ctx) throw() 
{
	return this->value->get(index, ctx);
}
void DocumentVariable::set(IDomVariable* val, int index, ThreadContext* ctx) throw() 
{
	this->value->set(val, index, ctx);
}
int DocumentVariable::getVariableClass(ThreadContext* ctx) throw() 
{
	return this->value->getVariableClass(ctx);
}
IAlinousVariable* DocumentVariable::copy(ThreadContext* ctx)
{
	DocumentVariable* newObj = (new(ctx) DocumentVariable(ctx));
	IDomVariable* val = static_cast<IDomVariable*>(this->value->copy(ctx));
	__GC_MV(newObj, &(newObj->value), val, IDomVariable);
	return newObj;
}
IDomVariable* DocumentVariable::toDomVariable(ThreadContext* ctx)
{
	return this;
}
bool DocumentVariable::isNull(ThreadContext* ctx) throw() 
{
	return this->value->isNull(ctx);
}
bool DocumentVariable::isArray(ThreadContext* ctx) throw() 
{
	return this->value->isArray(ctx);
}
BoolVariable* DocumentVariable::toBoolVariable(ThreadContext* ctx)
{
	return this->value->toBoolVariable(ctx);
}
ByteVariable* DocumentVariable::toByteVariable(ThreadContext* ctx)
{
	return this->value->toByteVariable(ctx);
}
CharVariable* DocumentVariable::toCharVariable(ThreadContext* ctx)
{
	return this->value->toCharVariable(ctx);
}
ShortVariable* DocumentVariable::toShortVariable(ThreadContext* ctx)
{
	return this->value->toShortVariable(ctx);
}
IntegerVariable* DocumentVariable::toIntVariable(ThreadContext* ctx)
{
	return this->value->toIntVariable(ctx);
}
LongVariable* DocumentVariable::toLongVariable(ThreadContext* ctx)
{
	return this->value->toLongVariable(ctx);
}
StringVariable* DocumentVariable::toStringVariable(ThreadContext* ctx)
{
	return this->value->toStringVariable(ctx);
}
FloatVariable* DocumentVariable::toFloatVariable(ThreadContext* ctx)
{
	return this->value->toFloatVariable(ctx);
}
DoubleVariable* DocumentVariable::toDoubleVariable(ThreadContext* ctx)
{
	return this->value->toDoubleVariable(ctx);
}
BigDecimalVariable* DocumentVariable::toBigDecimalVariable(ThreadContext* ctx)
{
	return this->value->toBigDecimalVariable(ctx);
}
TimeVariable* DocumentVariable::toTimeVariable(ThreadContext* ctx)
{
	return this->value->toTimeVariable(ctx);
}
TimestampVariable* DocumentVariable::toTimestampVariable(ThreadContext* ctx)
{
	return this->value->toTimestampVariable(ctx);
}
VariantValue* DocumentVariable::toVariantValue(ThreadContext* ctx)
{
	return this->value->toVariantValue(ctx);
}
int DocumentVariable::getIntValue(ThreadContext* ctx)
{
	return this->value->getIntValue(ctx);
}
long long DocumentVariable::getLongValue(ThreadContext* ctx)
{
	return this->value->getLongValue(ctx);
}
String* DocumentVariable::getStringValue(ThreadContext* ctx)
{
	return this->value->getStringValue(ctx);
}
IAlinousVariable* DocumentVariable::add(IAlinousVariable* variable, ThreadContext* ctx)
{
	return this->value->add(variable, ctx);
}
IAlinousVariable* DocumentVariable::add(VariantValue* variable, ThreadContext* ctx)
{
	return this->value->add(variable, ctx);
}
IAlinousVariable* DocumentVariable::add(DomVariable* variable, ThreadContext* ctx)
{
	return this->value->add(variable, ctx);
}
IAlinousVariable* DocumentVariable::add(BoolVariable* variable, ThreadContext* ctx)
{
	return this->value->add(variable, ctx);
}
IAlinousVariable* DocumentVariable::add(ByteVariable* variable, ThreadContext* ctx)
{
	return this->value->add(variable, ctx);
}
IAlinousVariable* DocumentVariable::add(CharVariable* variable, ThreadContext* ctx)
{
	return this->value->add(variable, ctx);
}
IAlinousVariable* DocumentVariable::add(DoubleVariable* variable, ThreadContext* ctx)
{
	return this->value->add(variable, ctx);
}
IAlinousVariable* DocumentVariable::add(FloatVariable* variable, ThreadContext* ctx)
{
	return this->value->add(variable, ctx);
}
IAlinousVariable* DocumentVariable::add(IntegerVariable* variable, ThreadContext* ctx)
{
	return this->value->add(variable, ctx);
}
IAlinousVariable* DocumentVariable::add(LongVariable* variable, ThreadContext* ctx)
{
	return this->value->add(variable, ctx);
}
IAlinousVariable* DocumentVariable::add(ShortVariable* variable, ThreadContext* ctx)
{
	return this->value->add(variable, ctx);
}
IAlinousVariable* DocumentVariable::add(StringVariable* variable, ThreadContext* ctx)
{
	return this->value->add(variable, ctx);
}
IAlinousVariable* DocumentVariable::add(BigDecimalVariable* variable, ThreadContext* ctx)
{
	return this->value->add(variable, ctx);
}
IAlinousVariable* DocumentVariable::add(TimeVariable* variable, ThreadContext* ctx)
{
	return this->value->add(variable, ctx);
}
IAlinousVariable* DocumentVariable::add(TimestampVariable* variable, ThreadContext* ctx)
{
	return this->value->add(variable, ctx);
}
IAlinousVariable* DocumentVariable::minus(IAlinousVariable* variable, ThreadContext* ctx)
{
	return this->value->minus(variable, ctx);
}
IAlinousVariable* DocumentVariable::minus(VariantValue* variable, ThreadContext* ctx)
{
	return this->value->minus(variable, ctx);
}
IAlinousVariable* DocumentVariable::minus(DomVariable* variable, ThreadContext* ctx)
{
	return this->value->minus(variable, ctx);
}
IAlinousVariable* DocumentVariable::minus(BoolVariable* variable, ThreadContext* ctx)
{
	return this->value->minus(variable, ctx);
}
IAlinousVariable* DocumentVariable::minus(ByteVariable* variable, ThreadContext* ctx)
{
	return this->value->minus(variable, ctx);
}
IAlinousVariable* DocumentVariable::minus(CharVariable* variable, ThreadContext* ctx)
{
	return this->value->minus(variable, ctx);
}
IAlinousVariable* DocumentVariable::minus(DoubleVariable* variable, ThreadContext* ctx)
{
	return this->value->minus(variable, ctx);
}
IAlinousVariable* DocumentVariable::minus(FloatVariable* variable, ThreadContext* ctx)
{
	return this->value->minus(variable, ctx);
}
IAlinousVariable* DocumentVariable::minus(IntegerVariable* variable, ThreadContext* ctx)
{
	return this->value->minus(variable, ctx);
}
IAlinousVariable* DocumentVariable::minus(LongVariable* variable, ThreadContext* ctx)
{
	return this->value->minus(variable, ctx);
}
IAlinousVariable* DocumentVariable::minus(ShortVariable* variable, ThreadContext* ctx)
{
	return this->value->minus(variable, ctx);
}
IAlinousVariable* DocumentVariable::minus(StringVariable* variable, ThreadContext* ctx)
{
	return this->value->minus(variable, ctx);
}
IAlinousVariable* DocumentVariable::minus(BigDecimalVariable* variable, ThreadContext* ctx)
{
	return this->value->minus(variable, ctx);
}
IAlinousVariable* DocumentVariable::minus(TimeVariable* variable, ThreadContext* ctx)
{
	return this->value->minus(variable, ctx);
}
IAlinousVariable* DocumentVariable::minus(TimestampVariable* variable, ThreadContext* ctx)
{
	return this->value->minus(variable, ctx);
}
IAlinousVariable* DocumentVariable::multiply(IAlinousVariable* variable, ThreadContext* ctx)
{
	return this->value->multiply(variable, ctx);
}
IAlinousVariable* DocumentVariable::multiply(VariantValue* variable, ThreadContext* ctx)
{
	return this->value->multiply(variable, ctx);
}
IAlinousVariable* DocumentVariable::multiply(DomVariable* variable, ThreadContext* ctx)
{
	return this->value->multiply(variable, ctx);
}
IAlinousVariable* DocumentVariable::multiply(BoolVariable* variable, ThreadContext* ctx)
{
	return this->value->multiply(variable, ctx);
}
IAlinousVariable* DocumentVariable::multiply(ByteVariable* variable, ThreadContext* ctx)
{
	return this->value->multiply(variable, ctx);
}
IAlinousVariable* DocumentVariable::multiply(CharVariable* variable, ThreadContext* ctx)
{
	return this->value->multiply(variable, ctx);
}
IAlinousVariable* DocumentVariable::multiply(DoubleVariable* variable, ThreadContext* ctx)
{
	return this->value->multiply(variable, ctx);
}
IAlinousVariable* DocumentVariable::multiply(FloatVariable* variable, ThreadContext* ctx)
{
	return this->value->multiply(variable, ctx);
}
IAlinousVariable* DocumentVariable::multiply(IntegerVariable* variable, ThreadContext* ctx)
{
	return this->value->multiply(variable, ctx);
}
IAlinousVariable* DocumentVariable::multiply(LongVariable* variable, ThreadContext* ctx)
{
	return this->value->multiply(variable, ctx);
}
IAlinousVariable* DocumentVariable::multiply(ShortVariable* variable, ThreadContext* ctx)
{
	return this->value->multiply(variable, ctx);
}
IAlinousVariable* DocumentVariable::multiply(StringVariable* variable, ThreadContext* ctx)
{
	return this->value->multiply(variable, ctx);
}
IAlinousVariable* DocumentVariable::multiply(BigDecimalVariable* variable, ThreadContext* ctx)
{
	return this->value->multiply(variable, ctx);
}
IAlinousVariable* DocumentVariable::multiply(TimeVariable* variable, ThreadContext* ctx)
{
	return this->value->multiply(variable, ctx);
}
IAlinousVariable* DocumentVariable::multiply(TimestampVariable* variable, ThreadContext* ctx)
{
	return this->value->multiply(variable, ctx);
}
IAlinousVariable* DocumentVariable::div(IAlinousVariable* variable, ThreadContext* ctx)
{
	return this->value->div(variable, ctx);
}
IAlinousVariable* DocumentVariable::div(VariantValue* variable, ThreadContext* ctx)
{
	return this->value->div(variable, ctx);
}
IAlinousVariable* DocumentVariable::div(DomVariable* variable, ThreadContext* ctx)
{
	return this->value->div(variable, ctx);
}
IAlinousVariable* DocumentVariable::div(BoolVariable* variable, ThreadContext* ctx)
{
	return this->value->div(variable, ctx);
}
IAlinousVariable* DocumentVariable::div(ByteVariable* variable, ThreadContext* ctx)
{
	return this->value->div(variable, ctx);
}
IAlinousVariable* DocumentVariable::div(CharVariable* variable, ThreadContext* ctx)
{
	return this->value->div(variable, ctx);
}
IAlinousVariable* DocumentVariable::div(DoubleVariable* variable, ThreadContext* ctx)
{
	return this->value->div(variable, ctx);
}
IAlinousVariable* DocumentVariable::div(FloatVariable* variable, ThreadContext* ctx)
{
	return this->value->div(variable, ctx);
}
IAlinousVariable* DocumentVariable::div(IntegerVariable* variable, ThreadContext* ctx)
{
	return this->value->div(variable, ctx);
}
IAlinousVariable* DocumentVariable::div(LongVariable* variable, ThreadContext* ctx)
{
	return this->value->div(variable, ctx);
}
IAlinousVariable* DocumentVariable::div(ShortVariable* variable, ThreadContext* ctx)
{
	return this->value->div(variable, ctx);
}
IAlinousVariable* DocumentVariable::div(StringVariable* variable, ThreadContext* ctx)
{
	return this->value->div(variable, ctx);
}
IAlinousVariable* DocumentVariable::div(BigDecimalVariable* variable, ThreadContext* ctx)
{
	return this->value->div(variable, ctx);
}
IAlinousVariable* DocumentVariable::div(TimeVariable* variable, ThreadContext* ctx)
{
	return this->value->div(variable, ctx);
}
IAlinousVariable* DocumentVariable::div(TimestampVariable* variable, ThreadContext* ctx)
{
	return this->value->div(variable, ctx);
}
IAlinousVariable* DocumentVariable::shiftLeft(IAlinousVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftLeft(variable, ctx);
}
IAlinousVariable* DocumentVariable::shiftLeft(VariantValue* variable, ThreadContext* ctx)
{
	return this->value->shiftLeft(variable, ctx);
}
IAlinousVariable* DocumentVariable::shiftLeft(DomVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftLeft(variable, ctx);
}
IAlinousVariable* DocumentVariable::shiftLeft(BoolVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftLeft(variable, ctx);
}
IAlinousVariable* DocumentVariable::shiftLeft(ByteVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftLeft(variable, ctx);
}
IAlinousVariable* DocumentVariable::shiftLeft(CharVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftLeft(variable, ctx);
}
IAlinousVariable* DocumentVariable::shiftLeft(DoubleVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftLeft(variable, ctx);
}
IAlinousVariable* DocumentVariable::shiftLeft(FloatVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftLeft(variable, ctx);
}
IAlinousVariable* DocumentVariable::shiftLeft(IntegerVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftLeft(variable, ctx);
}
IAlinousVariable* DocumentVariable::shiftLeft(LongVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftLeft(variable, ctx);
}
IAlinousVariable* DocumentVariable::shiftLeft(ShortVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftLeft(variable, ctx);
}
IAlinousVariable* DocumentVariable::shiftLeft(StringVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftLeft(variable, ctx);
}
IAlinousVariable* DocumentVariable::shiftLeft(BigDecimalVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftLeft(variable, ctx);
}
IAlinousVariable* DocumentVariable::shiftLeft(TimeVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftLeft(variable, ctx);
}
IAlinousVariable* DocumentVariable::shiftLeft(TimestampVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftLeft(variable, ctx);
}
IAlinousVariable* DocumentVariable::shiftRight(IAlinousVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftRight(variable, ctx);
}
IAlinousVariable* DocumentVariable::shiftRight(VariantValue* variable, ThreadContext* ctx)
{
	return this->value->shiftRight(variable, ctx);
}
IAlinousVariable* DocumentVariable::shiftRight(DomVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftRight(variable, ctx);
}
IAlinousVariable* DocumentVariable::shiftRight(BoolVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftRight(variable, ctx);
}
IAlinousVariable* DocumentVariable::shiftRight(ByteVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftRight(variable, ctx);
}
IAlinousVariable* DocumentVariable::shiftRight(CharVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftRight(variable, ctx);
}
IAlinousVariable* DocumentVariable::shiftRight(DoubleVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftRight(variable, ctx);
}
IAlinousVariable* DocumentVariable::shiftRight(FloatVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftRight(variable, ctx);
}
IAlinousVariable* DocumentVariable::shiftRight(IntegerVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftRight(variable, ctx);
}
IAlinousVariable* DocumentVariable::shiftRight(LongVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftRight(variable, ctx);
}
IAlinousVariable* DocumentVariable::shiftRight(ShortVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftRight(variable, ctx);
}
IAlinousVariable* DocumentVariable::shiftRight(StringVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftRight(variable, ctx);
}
IAlinousVariable* DocumentVariable::shiftRight(BigDecimalVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftRight(variable, ctx);
}
IAlinousVariable* DocumentVariable::shiftRight(TimeVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftRight(variable, ctx);
}
IAlinousVariable* DocumentVariable::shiftRight(TimestampVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftRight(variable, ctx);
}
IAlinousVariable* DocumentVariable::shiftRightUnsigned(IAlinousVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftRightUnsigned(variable, ctx);
}
IAlinousVariable* DocumentVariable::shiftRightUnsigned(VariantValue* variable, ThreadContext* ctx)
{
	return this->value->shiftRightUnsigned(variable, ctx);
}
IAlinousVariable* DocumentVariable::shiftRightUnsigned(DomVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftRightUnsigned(variable, ctx);
}
IAlinousVariable* DocumentVariable::shiftRightUnsigned(BoolVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftRightUnsigned(variable, ctx);
}
IAlinousVariable* DocumentVariable::shiftRightUnsigned(ByteVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftRightUnsigned(variable, ctx);
}
IAlinousVariable* DocumentVariable::shiftRightUnsigned(CharVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftRightUnsigned(variable, ctx);
}
IAlinousVariable* DocumentVariable::shiftRightUnsigned(DoubleVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftRightUnsigned(variable, ctx);
}
IAlinousVariable* DocumentVariable::shiftRightUnsigned(FloatVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftRightUnsigned(variable, ctx);
}
IAlinousVariable* DocumentVariable::shiftRightUnsigned(IntegerVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftRightUnsigned(variable, ctx);
}
IAlinousVariable* DocumentVariable::shiftRightUnsigned(LongVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftRightUnsigned(variable, ctx);
}
IAlinousVariable* DocumentVariable::shiftRightUnsigned(ShortVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftRightUnsigned(variable, ctx);
}
IAlinousVariable* DocumentVariable::shiftRightUnsigned(StringVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftRightUnsigned(variable, ctx);
}
IAlinousVariable* DocumentVariable::shiftRightUnsigned(BigDecimalVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftRightUnsigned(variable, ctx);
}
IAlinousVariable* DocumentVariable::shiftRightUnsigned(TimeVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftRightUnsigned(variable, ctx);
}
IAlinousVariable* DocumentVariable::shiftRightUnsigned(TimestampVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftRightUnsigned(variable, ctx);
}
IAlinousVariable* DocumentVariable::modulo(IAlinousVariable* variable, ThreadContext* ctx)
{
	return this->value->shiftRightUnsigned(variable, ctx);
}
IAlinousVariable* DocumentVariable::modulo(VariantValue* variable, ThreadContext* ctx)
{
	return this->value->modulo(variable, ctx);
}
IAlinousVariable* DocumentVariable::modulo(DomVariable* variable, ThreadContext* ctx)
{
	return this->value->modulo(variable, ctx);
}
IAlinousVariable* DocumentVariable::modulo(BoolVariable* variable, ThreadContext* ctx)
{
	return this->value->modulo(variable, ctx);
}
IAlinousVariable* DocumentVariable::modulo(ByteVariable* variable, ThreadContext* ctx)
{
	return this->value->modulo(variable, ctx);
}
IAlinousVariable* DocumentVariable::modulo(CharVariable* variable, ThreadContext* ctx)
{
	return this->value->modulo(variable, ctx);
}
IAlinousVariable* DocumentVariable::modulo(DoubleVariable* variable, ThreadContext* ctx)
{
	return this->value->modulo(variable, ctx);
}
IAlinousVariable* DocumentVariable::modulo(FloatVariable* variable, ThreadContext* ctx)
{
	return this->value->modulo(variable, ctx);
}
IAlinousVariable* DocumentVariable::modulo(IntegerVariable* variable, ThreadContext* ctx)
{
	return this->value->modulo(variable, ctx);
}
IAlinousVariable* DocumentVariable::modulo(LongVariable* variable, ThreadContext* ctx)
{
	return this->value->modulo(variable, ctx);
}
IAlinousVariable* DocumentVariable::modulo(ShortVariable* variable, ThreadContext* ctx)
{
	return this->value->modulo(variable, ctx);
}
IAlinousVariable* DocumentVariable::modulo(StringVariable* variable, ThreadContext* ctx)
{
	return this->value->modulo(variable, ctx);
}
IAlinousVariable* DocumentVariable::modulo(BigDecimalVariable* variable, ThreadContext* ctx)
{
	return this->value->modulo(variable, ctx);
}
IAlinousVariable* DocumentVariable::modulo(TimeVariable* variable, ThreadContext* ctx)
{
	return this->value->modulo(variable, ctx);
}
IAlinousVariable* DocumentVariable::modulo(TimestampVariable* variable, ThreadContext* ctx)
{
	return this->value->modulo(variable, ctx);
}
IAlinousVariable* DocumentVariable::bitOr(IAlinousVariable* variable, ThreadContext* ctx)
{
	return this->value->bitOr(variable, ctx);
}
IAlinousVariable* DocumentVariable::bitOr(VariantValue* variable, ThreadContext* ctx)
{
	return this->value->bitOr(variable, ctx);
}
IAlinousVariable* DocumentVariable::bitOr(DomVariable* variable, ThreadContext* ctx)
{
	return this->value->bitOr(variable, ctx);
}
IAlinousVariable* DocumentVariable::bitOr(BoolVariable* variable, ThreadContext* ctx)
{
	return this->value->bitOr(variable, ctx);
}
IAlinousVariable* DocumentVariable::bitOr(ByteVariable* variable, ThreadContext* ctx)
{
	return this->value->bitOr(variable, ctx);
}
IAlinousVariable* DocumentVariable::bitOr(CharVariable* variable, ThreadContext* ctx)
{
	return this->value->bitOr(variable, ctx);
}
IAlinousVariable* DocumentVariable::bitOr(DoubleVariable* variable, ThreadContext* ctx)
{
	return this->value->bitOr(variable, ctx);
}
IAlinousVariable* DocumentVariable::bitOr(FloatVariable* variable, ThreadContext* ctx)
{
	return this->value->bitOr(variable, ctx);
}
IAlinousVariable* DocumentVariable::bitOr(IntegerVariable* variable, ThreadContext* ctx)
{
	return this->value->bitOr(variable, ctx);
}
IAlinousVariable* DocumentVariable::bitOr(LongVariable* variable, ThreadContext* ctx)
{
	return this->value->bitOr(variable, ctx);
}
IAlinousVariable* DocumentVariable::bitOr(ShortVariable* variable, ThreadContext* ctx)
{
	return this->value->bitOr(variable, ctx);
}
IAlinousVariable* DocumentVariable::bitOr(StringVariable* variable, ThreadContext* ctx)
{
	return this->value->bitOr(variable, ctx);
}
IAlinousVariable* DocumentVariable::bitOr(BigDecimalVariable* variable, ThreadContext* ctx)
{
	return this->value->bitOr(variable, ctx);
}
IAlinousVariable* DocumentVariable::bitOr(TimeVariable* variable, ThreadContext* ctx)
{
	return this->value->bitOr(variable, ctx);
}
IAlinousVariable* DocumentVariable::bitOr(TimestampVariable* variable, ThreadContext* ctx)
{
	return this->value->bitOr(variable, ctx);
}
IAlinousVariable* DocumentVariable::bitAnd(IAlinousVariable* variable, ThreadContext* ctx)
{
	return this->value->bitAnd(variable, ctx);
}
IAlinousVariable* DocumentVariable::bitAnd(VariantValue* variable, ThreadContext* ctx)
{
	return this->value->bitAnd(variable, ctx);
}
IAlinousVariable* DocumentVariable::bitAnd(DomVariable* variable, ThreadContext* ctx)
{
	return this->value->bitAnd(variable, ctx);
}
IAlinousVariable* DocumentVariable::bitAnd(BoolVariable* variable, ThreadContext* ctx)
{
	return this->value->bitAnd(variable, ctx);
}
IAlinousVariable* DocumentVariable::bitAnd(ByteVariable* variable, ThreadContext* ctx)
{
	return this->value->bitAnd(variable, ctx);
}
IAlinousVariable* DocumentVariable::bitAnd(CharVariable* variable, ThreadContext* ctx)
{
	return this->value->bitAnd(variable, ctx);
}
IAlinousVariable* DocumentVariable::bitAnd(DoubleVariable* variable, ThreadContext* ctx)
{
	return this->value->bitAnd(variable, ctx);
}
IAlinousVariable* DocumentVariable::bitAnd(FloatVariable* variable, ThreadContext* ctx)
{
	return this->value->bitAnd(variable, ctx);
}
IAlinousVariable* DocumentVariable::bitAnd(IntegerVariable* variable, ThreadContext* ctx)
{
	return this->value->bitAnd(variable, ctx);
}
IAlinousVariable* DocumentVariable::bitAnd(LongVariable* variable, ThreadContext* ctx)
{
	return this->value->bitAnd(variable, ctx);
}
IAlinousVariable* DocumentVariable::bitAnd(ShortVariable* variable, ThreadContext* ctx)
{
	return this->value->bitAnd(variable, ctx);
}
IAlinousVariable* DocumentVariable::bitAnd(StringVariable* variable, ThreadContext* ctx)
{
	return this->value->bitAnd(variable, ctx);
}
IAlinousVariable* DocumentVariable::bitAnd(BigDecimalVariable* variable, ThreadContext* ctx)
{
	return this->value->bitAnd(variable, ctx);
}
IAlinousVariable* DocumentVariable::bitAnd(TimeVariable* variable, ThreadContext* ctx)
{
	return this->value->bitAnd(variable, ctx);
}
IAlinousVariable* DocumentVariable::bitAnd(TimestampVariable* variable, ThreadContext* ctx)
{
	return this->value->bitAnd(variable, ctx);
}
IAlinousVariable* DocumentVariable::bitExor(IAlinousVariable* variable, ThreadContext* ctx)
{
	return this->value->bitExor(variable, ctx);
}
IAlinousVariable* DocumentVariable::bitExor(VariantValue* variable, ThreadContext* ctx)
{
	return this->value->bitExor(variable, ctx);
}
IAlinousVariable* DocumentVariable::bitExor(DomVariable* variable, ThreadContext* ctx)
{
	return this->value->bitExor(variable, ctx);
}
IAlinousVariable* DocumentVariable::bitExor(BoolVariable* variable, ThreadContext* ctx)
{
	return this->value->bitExor(variable, ctx);
}
IAlinousVariable* DocumentVariable::bitExor(ByteVariable* variable, ThreadContext* ctx)
{
	return this->value->bitExor(variable, ctx);
}
IAlinousVariable* DocumentVariable::bitExor(CharVariable* variable, ThreadContext* ctx)
{
	return this->value->bitExor(variable, ctx);
}
IAlinousVariable* DocumentVariable::bitExor(DoubleVariable* variable, ThreadContext* ctx)
{
	return this->value->bitExor(variable, ctx);
}
IAlinousVariable* DocumentVariable::bitExor(FloatVariable* variable, ThreadContext* ctx)
{
	return this->value->bitExor(variable, ctx);
}
IAlinousVariable* DocumentVariable::bitExor(IntegerVariable* variable, ThreadContext* ctx)
{
	return this->value->bitExor(variable, ctx);
}
IAlinousVariable* DocumentVariable::bitExor(LongVariable* variable, ThreadContext* ctx)
{
	return this->value->bitExor(variable, ctx);
}
IAlinousVariable* DocumentVariable::bitExor(ShortVariable* variable, ThreadContext* ctx)
{
	return this->value->bitExor(variable, ctx);
}
IAlinousVariable* DocumentVariable::bitExor(StringVariable* variable, ThreadContext* ctx)
{
	return this->value->bitExor(variable, ctx);
}
IAlinousVariable* DocumentVariable::bitExor(BigDecimalVariable* variable, ThreadContext* ctx)
{
	return this->value->bitExor(variable, ctx);
}
IAlinousVariable* DocumentVariable::bitExor(TimeVariable* variable, ThreadContext* ctx)
{
	return this->value->bitExor(variable, ctx);
}
IAlinousVariable* DocumentVariable::bitExor(TimestampVariable* variable, ThreadContext* ctx)
{
	return this->value->bitExor(variable, ctx);
}
IAlinousVariable* DocumentVariable::bitReverse(ThreadContext* ctx)
{
	return this->value->bitReverse(ctx);
}
IAlinousVariable* DocumentVariable::substitute(IAlinousVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), variable->toDomVariable(ctx), IDomVariable);
	return this;
}
IAlinousVariable* DocumentVariable::substitute(VariantValue* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), variable->toDomVariable(ctx), IDomVariable);
	return this;
}
IAlinousVariable* DocumentVariable::substitute(DomVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), variable, IDomVariable);
	return this;
}
IAlinousVariable* DocumentVariable::substitute(BoolVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), variable->toDomVariable(ctx), IDomVariable);
	return this;
}
IAlinousVariable* DocumentVariable::substitute(ByteVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), variable->toDomVariable(ctx), IDomVariable);
	return this;
}
IAlinousVariable* DocumentVariable::substitute(CharVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), variable->toDomVariable(ctx), IDomVariable);
	return this;
}
IAlinousVariable* DocumentVariable::substitute(DoubleVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), variable->toDomVariable(ctx), IDomVariable);
	return this;
}
IAlinousVariable* DocumentVariable::substitute(FloatVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), variable->toDomVariable(ctx), IDomVariable);
	return this;
}
IAlinousVariable* DocumentVariable::substitute(IntegerVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), variable->toDomVariable(ctx), IDomVariable);
	return this;
}
IAlinousVariable* DocumentVariable::substitute(LongVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), variable->toDomVariable(ctx), IDomVariable);
	return this;
}
IAlinousVariable* DocumentVariable::substitute(ShortVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), variable->toDomVariable(ctx), IDomVariable);
	return this;
}
IAlinousVariable* DocumentVariable::substitute(StringVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), variable->toDomVariable(ctx), IDomVariable);
	return this;
}
IAlinousVariable* DocumentVariable::substitute(BigDecimalVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), variable->toDomVariable(ctx), IDomVariable);
	return this;
}
IAlinousVariable* DocumentVariable::substitute(TimeVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), variable->toDomVariable(ctx), IDomVariable);
	return this;
}
IAlinousVariable* DocumentVariable::substitute(TimestampVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), variable->toDomVariable(ctx), IDomVariable);
	return this;
}
IAlinousVariable* DocumentVariable::substitute(TypedVariableArray* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), variable->toDomVariable(ctx), IDomVariable);
	return this;
}
int DocumentVariable::compareTo(IAlinousVariable* variable, ThreadContext* ctx)
{
	return this->value->compareTo(variable, ctx);
}
int DocumentVariable::compareTo(VariantValue* variable, ThreadContext* ctx)
{
	return this->value->compareTo(variable, ctx);
}
int DocumentVariable::compareTo(DomVariable* variable, ThreadContext* ctx)
{
	return this->value->compareTo(variable, ctx);
}
int DocumentVariable::compareTo(BoolVariable* variable, ThreadContext* ctx)
{
	return this->value->compareTo(variable, ctx);
}
int DocumentVariable::compareTo(ByteVariable* variable, ThreadContext* ctx)
{
	return this->value->compareTo(variable, ctx);
}
int DocumentVariable::compareTo(CharVariable* variable, ThreadContext* ctx)
{
	return this->value->compareTo(variable, ctx);
}
int DocumentVariable::compareTo(DoubleVariable* variable, ThreadContext* ctx)
{
	return this->value->compareTo(variable, ctx);
}
int DocumentVariable::compareTo(FloatVariable* variable, ThreadContext* ctx)
{
	return this->value->compareTo(variable, ctx);
}
int DocumentVariable::compareTo(IntegerVariable* variable, ThreadContext* ctx)
{
	return this->value->compareTo(variable, ctx);
}
int DocumentVariable::compareTo(LongVariable* variable, ThreadContext* ctx)
{
	return this->value->compareTo(variable, ctx);
}
int DocumentVariable::compareTo(ShortVariable* variable, ThreadContext* ctx)
{
	return this->value->compareTo(variable, ctx);
}
int DocumentVariable::compareTo(StringVariable* variable, ThreadContext* ctx)
{
	return this->value->compareTo(variable, ctx);
}
int DocumentVariable::compareTo(BigDecimalVariable* variable, ThreadContext* ctx)
{
	return this->value->compareTo(variable, ctx);
}
int DocumentVariable::compareTo(TimeVariable* variable, ThreadContext* ctx)
{
	return this->value->compareTo(variable, ctx);
}
int DocumentVariable::compareTo(TimestampVariable* variable, ThreadContext* ctx)
{
	return this->value->compareTo(variable, ctx);
}
bool DocumentVariable::isTrue(ThreadContext* ctx)
{
	return this->value->isTrue(ctx);
}
int DocumentVariable::getDomType(ThreadContext* ctx) throw() 
{
	return this->value->getDomType(ctx);
}
IDomVariable* DocumentVariable::toDom(ThreadContext* ctx) throw() 
{
	return this->value->toDom(ctx);
}
void DocumentVariable::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	char nullbl = buff->getByte(ctx);
	if(nullbl == (char)0)
	{
		return;
	}
	this->value->readData(buff, ctx);
}
void DocumentVariable::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putInt(ICommandData::__DocumentVariable, ctx);
	char nullbl = ((char)(isNull(ctx) ? 0 : 1));
	buff->putByte(nullbl, ctx);
	if(nullbl == (char)0)
	{
		return;
	}
	this->value->writeData(buff, ctx);
}
int DocumentVariable::ValueCompare::operator() (IAlinousVariable* _this, IAlinousVariable* variable, ThreadContext* ctx) const throw()
{
	return _this->compareTo(variable, ctx);
}
}}}

