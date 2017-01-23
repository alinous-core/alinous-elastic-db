#include "includes.h"


namespace alinous {namespace runtime {namespace dom {namespace typed {





String* BigDecimalVariable::VAL_TYPE = ConstStr::getCNST_STR_1151();
bool BigDecimalVariable::__init_done = __init_static_variables();
bool BigDecimalVariable::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"BigDecimalVariable", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 BigDecimalVariable::BigDecimalVariable(BigDecimal* bigDecimal, ThreadContext* ctx) throw()  : IObject(ctx), AbstractTypedVariable(ctx), value(nullptr)
{
	__GC_MV(this, &(this->value), bigDecimal, BigDecimal);
}
void BigDecimalVariable::__construct_impl(BigDecimal* bigDecimal, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->value), bigDecimal, BigDecimal);
}
 BigDecimalVariable::~BigDecimalVariable() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void BigDecimalVariable::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"BigDecimalVariable", L"~BigDecimalVariable");
	__e_obj1.add(this->value, this);
	value = nullptr;
	if(!prepare){
		return;
	}
	AbstractTypedVariable::__releaseRegerences(true, ctx);
}
void BigDecimalVariable::outDebugXml(DomNode* parentNode, String* name, ThreadContext* ctx) throw() 
{
	DomNode* node = (new(ctx) DomNode(VAL_TYPE, ctx));
	parentNode->addChild(node, ctx);
	if(name != nullptr)
	{
		Attribute* nameattr = (new(ctx) Attribute(IAlinousVariable::ATTR_NAME, name, node, ctx));
		node->addAttribute(nameattr, ctx);
	}
	if(this->value != nullptr)
	{
		Attribute* attr = (new(ctx) Attribute(AbstractTypedVariable::VALUE, this->value->toString(ctx), node, ctx));
		parentNode->addAttribute(attr, ctx);
	}
}
BigDecimal* BigDecimalVariable::getValue(ThreadContext* ctx) throw() 
{
	return value;
}
VariantValue* BigDecimalVariable::toVariantValue(ThreadContext* ctx)
{
	return (new(ctx) VariantValue(this->value, ctx));
}
int BigDecimalVariable::getTypedType(ThreadContext* ctx) throw() 
{
	return ITypedVariable::TYPE_BIGDECIMAL;
}
int BigDecimalVariable::getVariableClass(ThreadContext* ctx) throw() 
{
	return IAlinousVariable::CLASS_TYPED;
}
IAlinousVariable* BigDecimalVariable::copy(ThreadContext* ctx)
{
	return (new(ctx) BigDecimalVariable(this->value, ctx));
}
IDomVariable* BigDecimalVariable::toDomVariable(ThreadContext* ctx) throw() 
{
	DomVariable* dom = (new(ctx) DomVariable(ctx));
	dom->setValue((new(ctx) VariantValue(this->value, ctx)), ctx);
	return dom;
}
bool BigDecimalVariable::isNull(ThreadContext* ctx) throw() 
{
	return this->value == nullptr;
}
bool BigDecimalVariable::isArray(ThreadContext* ctx) throw() 
{
	return false;
}
BoolVariable* BigDecimalVariable::toBoolVariable(ThreadContext* ctx)
{
	return (new(ctx) BoolVariable(this->value->intValue(ctx) > 0, ctx));
}
ByteVariable* BigDecimalVariable::toByteVariable(ThreadContext* ctx)
{
	return (new(ctx) ByteVariable(this->value->byteValue(ctx), ctx));
}
CharVariable* BigDecimalVariable::toCharVariable(ThreadContext* ctx)
{
	return (new(ctx) CharVariable(((wchar_t)this->value->shortValue(ctx)), ctx));
}
ShortVariable* BigDecimalVariable::toShortVariable(ThreadContext* ctx)
{
	return (new(ctx) ShortVariable(this->value->shortValue(ctx), ctx));
}
IntegerVariable* BigDecimalVariable::toIntVariable(ThreadContext* ctx)
{
	return (new(ctx) IntegerVariable(this->value->intValue(ctx), ctx));
}
LongVariable* BigDecimalVariable::toLongVariable(ThreadContext* ctx)
{
	return (new(ctx) LongVariable(this->value->longValue(ctx), ctx));
}
StringVariable* BigDecimalVariable::toStringVariable(ThreadContext* ctx)
{
	return (new(ctx) StringVariable(this->value->toPlainString(ctx), ctx));
}
BigDecimalVariable* BigDecimalVariable::toBigDecimalVariable(ThreadContext* ctx)
{
	return static_cast<BigDecimalVariable*>(copy(ctx));
}
int BigDecimalVariable::getIntValue(ThreadContext* ctx)
{
	return this->value->intValue(ctx);
}
long long BigDecimalVariable::getLongValue(ThreadContext* ctx)
{
	return this->getLongValue(ctx);
}
String* BigDecimalVariable::getStringValue(ThreadContext* ctx)
{
	return this->value->toPlainString(ctx);
}
FloatVariable* BigDecimalVariable::toFloatVariable(ThreadContext* ctx)
{
	return (new(ctx) FloatVariable(this->value->floatValue(ctx), ctx));
}
DoubleVariable* BigDecimalVariable::toDoubleVariable(ThreadContext* ctx)
{
	return (new(ctx) DoubleVariable(this->value->doubleValue(ctx), ctx));
}
IAlinousVariable* BigDecimalVariable::add(VariantValue* variable, ThreadContext* ctx)
{
	this->value->add(variable->getBigDecimal(ctx), ctx);
	return this;
}
IAlinousVariable* BigDecimalVariable::add(DomVariable* variable, ThreadContext* ctx)
{
	this->value->add(variable->getValue(ctx)->getBigDecimal(ctx), ctx);
	return this;
}
IAlinousVariable* BigDecimalVariable::add(BoolVariable* variable, ThreadContext* ctx)
{
	this->value->add(variable->toBigDecimalVariable(ctx)->getValue(ctx), ctx);
	return this;
}
IAlinousVariable* BigDecimalVariable::add(ByteVariable* variable, ThreadContext* ctx)
{
	this->value->add(variable->toBigDecimalVariable(ctx)->getValue(ctx), ctx);
	return this;
}
IAlinousVariable* BigDecimalVariable::add(CharVariable* variable, ThreadContext* ctx)
{
	this->value->add(variable->toBigDecimalVariable(ctx)->getValue(ctx), ctx);
	return this;
}
IAlinousVariable* BigDecimalVariable::add(DoubleVariable* variable, ThreadContext* ctx)
{
	this->value->add(variable->toBigDecimalVariable(ctx)->getValue(ctx), ctx);
	return this;
}
IAlinousVariable* BigDecimalVariable::add(FloatVariable* variable, ThreadContext* ctx)
{
	this->value->add(variable->toBigDecimalVariable(ctx)->getValue(ctx), ctx);
	return this;
}
IAlinousVariable* BigDecimalVariable::add(IntegerVariable* variable, ThreadContext* ctx)
{
	this->value->add(variable->toBigDecimalVariable(ctx)->getValue(ctx), ctx);
	return this;
}
IAlinousVariable* BigDecimalVariable::add(LongVariable* variable, ThreadContext* ctx)
{
	this->value->add(variable->toBigDecimalVariable(ctx)->getValue(ctx), ctx);
	return this;
}
IAlinousVariable* BigDecimalVariable::add(ShortVariable* variable, ThreadContext* ctx)
{
	this->value->add(variable->toBigDecimalVariable(ctx)->getValue(ctx), ctx);
	return this;
}
IAlinousVariable* BigDecimalVariable::add(StringVariable* variable, ThreadContext* ctx)
{
	this->value->add(variable->toBigDecimalVariable(ctx)->getValue(ctx), ctx);
	return this;
}
IAlinousVariable* BigDecimalVariable::add(BigDecimalVariable* variable, ThreadContext* ctx)
{
	this->value->add(variable->toBigDecimalVariable(ctx)->getValue(ctx), ctx);
	return this;
}
IAlinousVariable* BigDecimalVariable::minus(VariantValue* variable, ThreadContext* ctx)
{
	this->value->subtract(variable->getBigDecimal(ctx), ctx);
	return this;
}
IAlinousVariable* BigDecimalVariable::minus(DomVariable* variable, ThreadContext* ctx)
{
	this->value->subtract(variable->getValue(ctx)->getBigDecimal(ctx), ctx);
	return this;
}
IAlinousVariable* BigDecimalVariable::minus(BoolVariable* variable, ThreadContext* ctx)
{
	this->value->subtract(variable->toBigDecimalVariable(ctx)->getValue(ctx), ctx);
	return this;
}
IAlinousVariable* BigDecimalVariable::minus(ByteVariable* variable, ThreadContext* ctx)
{
	this->value->subtract(variable->toBigDecimalVariable(ctx)->getValue(ctx), ctx);
	return this;
}
IAlinousVariable* BigDecimalVariable::minus(CharVariable* variable, ThreadContext* ctx)
{
	this->value->subtract(variable->toBigDecimalVariable(ctx)->getValue(ctx), ctx);
	return this;
}
IAlinousVariable* BigDecimalVariable::minus(DoubleVariable* variable, ThreadContext* ctx)
{
	this->value->subtract(variable->toBigDecimalVariable(ctx)->getValue(ctx), ctx);
	return this;
}
IAlinousVariable* BigDecimalVariable::minus(FloatVariable* variable, ThreadContext* ctx)
{
	this->value->subtract(variable->toBigDecimalVariable(ctx)->getValue(ctx), ctx);
	return this;
}
IAlinousVariable* BigDecimalVariable::minus(IntegerVariable* variable, ThreadContext* ctx)
{
	this->value->subtract(variable->toBigDecimalVariable(ctx)->getValue(ctx), ctx);
	return this;
}
IAlinousVariable* BigDecimalVariable::minus(LongVariable* variable, ThreadContext* ctx)
{
	this->value->subtract(variable->toBigDecimalVariable(ctx)->getValue(ctx), ctx);
	return this;
}
IAlinousVariable* BigDecimalVariable::minus(ShortVariable* variable, ThreadContext* ctx)
{
	this->value->subtract(variable->toBigDecimalVariable(ctx)->getValue(ctx), ctx);
	return this;
}
IAlinousVariable* BigDecimalVariable::minus(StringVariable* variable, ThreadContext* ctx)
{
	this->value->subtract(variable->toBigDecimalVariable(ctx)->getValue(ctx), ctx);
	return this;
}
IAlinousVariable* BigDecimalVariable::minus(BigDecimalVariable* variable, ThreadContext* ctx)
{
	this->value->subtract(variable->toBigDecimalVariable(ctx)->getValue(ctx), ctx);
	return this;
}
IAlinousVariable* BigDecimalVariable::multiply(VariantValue* variable, ThreadContext* ctx)
{
	this->value->multiply(variable->getBigDecimal(ctx), ctx);
	return this;
}
IAlinousVariable* BigDecimalVariable::multiply(DomVariable* variable, ThreadContext* ctx)
{
	this->value->multiply(variable->getValue(ctx)->getBigDecimal(ctx), ctx);
	return this;
}
IAlinousVariable* BigDecimalVariable::multiply(BoolVariable* variable, ThreadContext* ctx)
{
	this->value->multiply(variable->toBigDecimalVariable(ctx)->getValue(ctx), ctx);
	return this;
}
IAlinousVariable* BigDecimalVariable::multiply(ByteVariable* variable, ThreadContext* ctx)
{
	this->value->multiply(variable->toBigDecimalVariable(ctx)->getValue(ctx), ctx);
	return this;
}
IAlinousVariable* BigDecimalVariable::multiply(CharVariable* variable, ThreadContext* ctx)
{
	this->value->multiply(variable->toBigDecimalVariable(ctx)->getValue(ctx), ctx);
	return this;
}
IAlinousVariable* BigDecimalVariable::multiply(DoubleVariable* variable, ThreadContext* ctx)
{
	this->value->multiply(variable->toBigDecimalVariable(ctx)->getValue(ctx), ctx);
	return this;
}
IAlinousVariable* BigDecimalVariable::multiply(FloatVariable* variable, ThreadContext* ctx)
{
	this->value->multiply(variable->toBigDecimalVariable(ctx)->getValue(ctx), ctx);
	return this;
}
IAlinousVariable* BigDecimalVariable::multiply(IntegerVariable* variable, ThreadContext* ctx)
{
	this->value->multiply(variable->toBigDecimalVariable(ctx)->getValue(ctx), ctx);
	return this;
}
IAlinousVariable* BigDecimalVariable::multiply(LongVariable* variable, ThreadContext* ctx)
{
	this->value->multiply(variable->toBigDecimalVariable(ctx)->getValue(ctx), ctx);
	return this;
}
IAlinousVariable* BigDecimalVariable::multiply(ShortVariable* variable, ThreadContext* ctx)
{
	this->value->multiply(variable->toBigDecimalVariable(ctx)->getValue(ctx), ctx);
	return this;
}
IAlinousVariable* BigDecimalVariable::multiply(StringVariable* variable, ThreadContext* ctx)
{
	this->value->multiply(variable->toBigDecimalVariable(ctx)->getValue(ctx), ctx);
	return this;
}
IAlinousVariable* BigDecimalVariable::multiply(BigDecimalVariable* variable, ThreadContext* ctx)
{
	this->value->multiply(variable->toBigDecimalVariable(ctx)->getValue(ctx), ctx);
	return this;
}
IAlinousVariable* BigDecimalVariable::div(VariantValue* variable, ThreadContext* ctx)
{
	this->value->divide(variable->getBigDecimal(ctx), ctx);
	return this;
}
IAlinousVariable* BigDecimalVariable::div(DomVariable* variable, ThreadContext* ctx)
{
	this->value->divide(variable->getValue(ctx)->getBigDecimal(ctx), ctx);
	return this;
}
IAlinousVariable* BigDecimalVariable::div(BoolVariable* variable, ThreadContext* ctx)
{
	this->value->divide(variable->toBigDecimalVariable(ctx)->getValue(ctx), ctx);
	return this;
}
IAlinousVariable* BigDecimalVariable::div(ByteVariable* variable, ThreadContext* ctx)
{
	this->value->divide(variable->toBigDecimalVariable(ctx)->getValue(ctx), ctx);
	return this;
}
IAlinousVariable* BigDecimalVariable::div(CharVariable* variable, ThreadContext* ctx)
{
	this->value->divide(variable->toBigDecimalVariable(ctx)->getValue(ctx), ctx);
	return this;
}
IAlinousVariable* BigDecimalVariable::div(DoubleVariable* variable, ThreadContext* ctx)
{
	this->value->divide(variable->toBigDecimalVariable(ctx)->getValue(ctx), ctx);
	return this;
}
IAlinousVariable* BigDecimalVariable::div(FloatVariable* variable, ThreadContext* ctx)
{
	this->value->divide(variable->toBigDecimalVariable(ctx)->getValue(ctx), ctx);
	return this;
}
IAlinousVariable* BigDecimalVariable::div(IntegerVariable* variable, ThreadContext* ctx)
{
	this->value->divide(variable->toBigDecimalVariable(ctx)->getValue(ctx), ctx);
	return this;
}
IAlinousVariable* BigDecimalVariable::div(LongVariable* variable, ThreadContext* ctx)
{
	this->value->divide(variable->toBigDecimalVariable(ctx)->getValue(ctx), ctx);
	return this;
}
IAlinousVariable* BigDecimalVariable::div(ShortVariable* variable, ThreadContext* ctx)
{
	this->value->divide(variable->toBigDecimalVariable(ctx)->getValue(ctx), ctx);
	return this;
}
IAlinousVariable* BigDecimalVariable::div(StringVariable* variable, ThreadContext* ctx)
{
	this->value->divide(variable->toBigDecimalVariable(ctx)->getValue(ctx), ctx);
	return this;
}
IAlinousVariable* BigDecimalVariable::div(BigDecimalVariable* variable, ThreadContext* ctx)
{
	this->value->divide(variable->toBigDecimalVariable(ctx)->getValue(ctx), ctx);
	return this;
}
IAlinousVariable* BigDecimalVariable::shiftLeft(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::shiftLeft(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::shiftLeft(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::shiftLeft(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::shiftLeft(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::shiftLeft(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::shiftLeft(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::shiftLeft(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::shiftLeft(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::shiftLeft(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::shiftLeft(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::shiftLeft(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::shiftRight(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::shiftRight(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::shiftRight(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::shiftRight(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::shiftRight(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::shiftRight(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::shiftRight(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::shiftRight(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::shiftRight(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::shiftRight(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::shiftRight(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::shiftRight(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::shiftRightUnsigned(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::shiftRightUnsigned(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::shiftRightUnsigned(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::shiftRightUnsigned(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::shiftRightUnsigned(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::shiftRightUnsigned(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::shiftRightUnsigned(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::shiftRightUnsigned(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::shiftRightUnsigned(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::shiftRightUnsigned(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::shiftRightUnsigned(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::shiftRightUnsigned(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::modulo(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::modulo(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::modulo(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::modulo(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::modulo(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::modulo(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::modulo(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::modulo(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::modulo(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::modulo(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::modulo(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::modulo(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::bitOr(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::bitOr(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::bitOr(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::bitOr(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::bitOr(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::bitOr(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::bitOr(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::bitOr(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::bitOr(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::bitOr(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::bitOr(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::bitOr(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::bitAnd(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::bitAnd(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::bitAnd(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::bitAnd(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::bitAnd(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::bitAnd(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::bitAnd(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::bitAnd(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::bitAnd(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::bitAnd(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::bitAnd(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::bitAnd(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::bitExor(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::bitExor(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::bitExor(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::bitExor(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::bitExor(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::bitExor(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::bitExor(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::bitExor(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::bitExor(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::bitExor(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::bitExor(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::bitExor(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::bitReverse(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::substitute(VariantValue* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), variable->toBigDecimalVariable(ctx)->getValue(ctx), BigDecimal);
	return this;
}
IAlinousVariable* BigDecimalVariable::substitute(DomVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), variable->toBigDecimalVariable(ctx)->getValue(ctx), BigDecimal);
	return this;
}
IAlinousVariable* BigDecimalVariable::substitute(BoolVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), variable->toBigDecimalVariable(ctx)->getValue(ctx), BigDecimal);
	return this;
}
IAlinousVariable* BigDecimalVariable::substitute(ByteVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), variable->toBigDecimalVariable(ctx)->getValue(ctx), BigDecimal);
	return this;
}
IAlinousVariable* BigDecimalVariable::substitute(CharVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), variable->toBigDecimalVariable(ctx)->getValue(ctx), BigDecimal);
	return this;
}
IAlinousVariable* BigDecimalVariable::substitute(DoubleVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), variable->toBigDecimalVariable(ctx)->getValue(ctx), BigDecimal);
	return this;
}
IAlinousVariable* BigDecimalVariable::substitute(FloatVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), variable->toBigDecimalVariable(ctx)->getValue(ctx), BigDecimal);
	return this;
}
IAlinousVariable* BigDecimalVariable::substitute(IntegerVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), variable->toBigDecimalVariable(ctx)->getValue(ctx), BigDecimal);
	return this;
}
IAlinousVariable* BigDecimalVariable::substitute(LongVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), variable->toBigDecimalVariable(ctx)->getValue(ctx), BigDecimal);
	return this;
}
IAlinousVariable* BigDecimalVariable::substitute(ShortVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), variable->toBigDecimalVariable(ctx)->getValue(ctx), BigDecimal);
	return this;
}
IAlinousVariable* BigDecimalVariable::substitute(StringVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), variable->toBigDecimalVariable(ctx)->getValue(ctx), BigDecimal);
	return this;
}
IAlinousVariable* BigDecimalVariable::substitute(BigDecimalVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), variable->toBigDecimalVariable(ctx)->getValue(ctx), BigDecimal);
	return this;
}
int BigDecimalVariable::compareTo(VariantValue* variable, ThreadContext* ctx)
{
	return this->value->compareTo(variable->toBigDecimalVariable(ctx)->getValue(ctx), ctx);
}
int BigDecimalVariable::compareTo(DomVariable* variable, ThreadContext* ctx)
{
	return this->value->compareTo(variable->toBigDecimalVariable(ctx)->getValue(ctx), ctx);
}
int BigDecimalVariable::compareTo(BoolVariable* variable, ThreadContext* ctx)
{
	return this->value->compareTo(variable->toBigDecimalVariable(ctx)->getValue(ctx), ctx);
}
int BigDecimalVariable::compareTo(ByteVariable* variable, ThreadContext* ctx)
{
	return this->value->compareTo(variable->toBigDecimalVariable(ctx)->getValue(ctx), ctx);
}
int BigDecimalVariable::compareTo(CharVariable* variable, ThreadContext* ctx)
{
	return this->value->compareTo(variable->toBigDecimalVariable(ctx)->getValue(ctx), ctx);
}
int BigDecimalVariable::compareTo(DoubleVariable* variable, ThreadContext* ctx)
{
	return this->value->compareTo(variable->toBigDecimalVariable(ctx)->getValue(ctx), ctx);
}
int BigDecimalVariable::compareTo(FloatVariable* variable, ThreadContext* ctx)
{
	return this->value->compareTo(variable->toBigDecimalVariable(ctx)->getValue(ctx), ctx);
}
int BigDecimalVariable::compareTo(IntegerVariable* variable, ThreadContext* ctx)
{
	return this->value->compareTo(variable->toBigDecimalVariable(ctx)->getValue(ctx), ctx);
}
int BigDecimalVariable::compareTo(LongVariable* variable, ThreadContext* ctx)
{
	return this->value->compareTo(variable->toBigDecimalVariable(ctx)->getValue(ctx), ctx);
}
int BigDecimalVariable::compareTo(ShortVariable* variable, ThreadContext* ctx)
{
	return this->value->compareTo(variable->toBigDecimalVariable(ctx)->getValue(ctx), ctx);
}
int BigDecimalVariable::compareTo(StringVariable* variable, ThreadContext* ctx)
{
	return this->value->compareTo(variable->toBigDecimalVariable(ctx)->getValue(ctx), ctx);
}
int BigDecimalVariable::compareTo(BigDecimalVariable* variable, ThreadContext* ctx)
{
	return this->value->compareTo(variable->toBigDecimalVariable(ctx)->getValue(ctx), ctx);
}
bool BigDecimalVariable::isTrue(ThreadContext* ctx)
{
	return this->value->longValue(ctx) > (long long)0;
}
TimeVariable* BigDecimalVariable::toTimeVariable(ThreadContext* ctx)
{
	TimeOnlyTimestamp* time = (new(ctx) TimeOnlyTimestamp(this->value->longValue(ctx), ctx));
	return (new(ctx) TimeVariable(time, ctx));
}
TimestampVariable* BigDecimalVariable::toTimestampVariable(ThreadContext* ctx)
{
	Timestamp* time = (new(ctx) Timestamp(this->value->longValue(ctx), ctx));
	return (new(ctx) TimestampVariable(time, ctx));
}
IAlinousVariable* BigDecimalVariable::add(TimeVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), this->value->add(variable->toBigDecimalVariable(ctx)->getValue(ctx), ctx), BigDecimal);
	return this;
}
IAlinousVariable* BigDecimalVariable::add(TimestampVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), this->value->add(variable->toBigDecimalVariable(ctx)->getValue(ctx), ctx), BigDecimal);
	return this;
}
IAlinousVariable* BigDecimalVariable::minus(TimeVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), this->value->subtract(variable->toBigDecimalVariable(ctx)->getValue(ctx), ctx), BigDecimal);
	return this;
}
IAlinousVariable* BigDecimalVariable::minus(TimestampVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), this->value->subtract(variable->toBigDecimalVariable(ctx)->getValue(ctx), ctx), BigDecimal);
	return this;
}
IAlinousVariable* BigDecimalVariable::multiply(TimeVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), this->value->multiply(variable->toBigDecimalVariable(ctx)->getValue(ctx), ctx), BigDecimal);
	return this;
}
IAlinousVariable* BigDecimalVariable::multiply(TimestampVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), this->value->multiply(variable->toBigDecimalVariable(ctx)->getValue(ctx), ctx), BigDecimal);
	return this;
}
IAlinousVariable* BigDecimalVariable::div(TimeVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), this->value->divide(variable->toBigDecimalVariable(ctx)->getValue(ctx), ctx), BigDecimal);
	return this;
}
IAlinousVariable* BigDecimalVariable::div(TimestampVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), this->value->divide(variable->toBigDecimalVariable(ctx)->getValue(ctx), ctx), BigDecimal);
	return this;
}
IAlinousVariable* BigDecimalVariable::shiftLeft(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::shiftLeft(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::shiftRight(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::shiftRight(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::shiftRightUnsigned(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::shiftRightUnsigned(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::modulo(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::modulo(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::bitOr(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::bitOr(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::bitAnd(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::bitAnd(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::bitExor(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::bitExor(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1150(), ctx));
}
IAlinousVariable* BigDecimalVariable::substitute(TimeVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), variable->toBigDecimalVariable(ctx)->getValue(ctx), BigDecimal);
	return this;
}
IAlinousVariable* BigDecimalVariable::substitute(TimestampVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), variable->toBigDecimalVariable(ctx)->getValue(ctx), BigDecimal);
	return this;
}
int BigDecimalVariable::compareTo(TimeVariable* variable, ThreadContext* ctx)
{
	return this->value->compareTo(variable->toBigDecimalVariable(ctx)->getValue(ctx), ctx);
}
int BigDecimalVariable::compareTo(TimestampVariable* variable, ThreadContext* ctx)
{
	return this->value->compareTo(variable->toBigDecimalVariable(ctx)->getValue(ctx), ctx);
}
IAlinousVariable* BigDecimalVariable::substitute(TypedVariableArray* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1124(), ctx));
}
void BigDecimalVariable::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	char nullbl = buff->getByte(ctx);
	if(nullbl == (char)0)
	{
		return;
	}
	String* str = buff->getString(ctx);
	__GC_MV(this, &(this->value), (new(ctx) BigDecimal(str, ctx)), BigDecimal);
}
void BigDecimalVariable::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putInt(ICommandData::__BigDecimalVariable, ctx);
	char nullbl = ((char)(isNull(ctx) ? 0 : 1));
	buff->putByte(nullbl, ctx);
	if(nullbl == (char)0)
	{
		return;
	}
	buff->putString(this->value->toPlainString(ctx), ctx);
}
BigDecimalVariable* BigDecimalVariable::fromDebugXml(DomNode* node, ThreadContext* ctx) throw() 
{
	IVariableValue* attrVal = node->getAttributeValue(VAL_TYPE, ctx);
	if(attrVal == nullptr)
	{
		return nullptr;
	}
	String* str = attrVal->toString(ctx);
	BigDecimal* dec = nullptr;
	{
		try
		{
			dec = (new(ctx) BigDecimal(str, ctx));
		}
		catch(Throwable* e)
		{
			e->printStackTrace(ctx);
			return nullptr;
		}
	}
	return (new(ctx) BigDecimalVariable(dec, ctx));
}
int BigDecimalVariable::ValueCompare::operator() (VariantValue* _this, VariantValue* variable, ThreadContext* ctx) const throw()
{
	return _this->compareTo(variable, ctx);
}
}}}}

