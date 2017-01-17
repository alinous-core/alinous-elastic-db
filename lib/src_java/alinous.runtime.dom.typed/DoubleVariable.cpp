#include "includes.h"


namespace alinous {namespace runtime {namespace dom {namespace typed {





String* DoubleVariable::VAL_TYPE = ConstStr::getCNST_STR_1134();
bool DoubleVariable::__init_done = __init_static_variables();
bool DoubleVariable::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DoubleVariable", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 DoubleVariable::DoubleVariable(double value, ThreadContext* ctx) throw()  : IObject(ctx), AbstractTypedVariable(ctx), value(0)
{
	this->value = value;
}
void DoubleVariable::__construct_impl(double value, ThreadContext* ctx) throw() 
{
	this->value = value;
}
 DoubleVariable::~DoubleVariable() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void DoubleVariable::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"DoubleVariable", L"~DoubleVariable");
	if(!prepare){
		return;
	}
	AbstractTypedVariable::__releaseRegerences(true, ctx);
}
void DoubleVariable::outDebugXml(DomNode* parentNode, String* name, ThreadContext* ctx) throw() 
{
	DomNode* node = (new(ctx) DomNode(VAL_TYPE, ctx));
	parentNode->addChild(node, ctx);
	if(name != nullptr)
	{
		Attribute* nameattr = (new(ctx) Attribute(IAlinousVariable::ATTR_NAME, name, node, ctx));
		node->addAttribute(nameattr, ctx);
	}
	Attribute* attr = (new(ctx) Attribute(AbstractTypedVariable::VALUE, Double::toString(this->value, ctx), node, ctx));
	parentNode->addAttribute(attr, ctx);
}
int DoubleVariable::getVariableClass(ThreadContext* ctx) throw() 
{
	return IAlinousVariable::CLASS_TYPED;
}
int DoubleVariable::getTypedType(ThreadContext* ctx) throw() 
{
	return ITypedVariable::TYPE_DOUBLE;
}
VariantValue* DoubleVariable::toVariantValue(ThreadContext* ctx)
{
	return (new(ctx) VariantValue(this->value, ctx));
}
int DoubleVariable::getIntValue(ThreadContext* ctx)
{
	return ((int)this->value);
}
String* DoubleVariable::getStringValue(ThreadContext* ctx)
{
	return Double::toString(this->value, ctx);
}
double DoubleVariable::getValue(ThreadContext* ctx) throw() 
{
	return value;
}
void DoubleVariable::setValue(double value, ThreadContext* ctx) throw() 
{
	this->value = value;
}
IAlinousVariable* DoubleVariable::copy(ThreadContext* ctx)
{
	return (new(ctx) DoubleVariable(this->value, ctx));
}
IDomVariable* DoubleVariable::toDomVariable(ThreadContext* ctx) throw() 
{
	DomVariable* ret = (new(ctx) DomVariable(ctx));
	ret->setValue((new(ctx) VariantValue(this->value, ctx)), ctx);
	return ret;
}
IAlinousVariable* DoubleVariable::add(VariantValue* variable, ThreadContext* ctx)
{
	return variable->add(this, ctx)->copy(ctx);
}
IAlinousVariable* DoubleVariable::add(DomVariable* variable, ThreadContext* ctx)
{
	return variable->add(this, ctx)->copy(ctx);
}
IAlinousVariable* DoubleVariable::add(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1127(), ctx));
}
IAlinousVariable* DoubleVariable::add(ByteVariable* variable, ThreadContext* ctx)
{
	this->value = this->value + variable->getValue(ctx);
	return this;
}
IAlinousVariable* DoubleVariable::add(CharVariable* variable, ThreadContext* ctx)
{
	this->value = this->value + variable->getValue(ctx);
	return this;
}
IAlinousVariable* DoubleVariable::add(DoubleVariable* variable, ThreadContext* ctx)
{
	this->value = this->value + variable->getValue(ctx);
	return this;
}
IAlinousVariable* DoubleVariable::add(FloatVariable* variable, ThreadContext* ctx)
{
	this->value = this->value + variable->getValue(ctx);
	return this;
}
IAlinousVariable* DoubleVariable::add(IntegerVariable* variable, ThreadContext* ctx)
{
	this->value = this->value + variable->getValue(ctx);
	return this;
}
IAlinousVariable* DoubleVariable::add(LongVariable* variable, ThreadContext* ctx)
{
	this->value = this->value + variable->getValue(ctx);
	return this;
}
IAlinousVariable* DoubleVariable::add(ShortVariable* variable, ThreadContext* ctx)
{
	this->value = this->value + variable->getValue(ctx);
	return this;
}
IAlinousVariable* DoubleVariable::add(StringVariable* variable, ThreadContext* ctx)
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	buff->append(Double::toString(value, ctx), ctx);
	buff->append(variable->getValue(ctx), ctx);
	return (new(ctx) StringVariable(buff->toString(ctx), ctx));
}
IAlinousVariable* DoubleVariable::minus(VariantValue* variable, ThreadContext* ctx)
{
	return (new(ctx) VariantValue(this->value, ctx))->minus(variable, ctx);
}
IAlinousVariable* DoubleVariable::minus(DomVariable* variable, ThreadContext* ctx)
{
	return (new(ctx) VariantValue(this->value, ctx))->minus(variable, ctx);
}
IAlinousVariable* DoubleVariable::minus(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1127(), ctx));
}
IAlinousVariable* DoubleVariable::minus(ByteVariable* variable, ThreadContext* ctx)
{
	this->value = this->value - variable->getValue(ctx);
	return this;
}
IAlinousVariable* DoubleVariable::minus(CharVariable* variable, ThreadContext* ctx)
{
	this->value = this->value - variable->getValue(ctx);
	return this;
}
IAlinousVariable* DoubleVariable::minus(DoubleVariable* variable, ThreadContext* ctx)
{
	this->value = this->value - variable->getValue(ctx);
	return this;
}
IAlinousVariable* DoubleVariable::minus(FloatVariable* variable, ThreadContext* ctx)
{
	this->value = this->value - variable->getValue(ctx);
	return this;
}
IAlinousVariable* DoubleVariable::minus(IntegerVariable* variable, ThreadContext* ctx)
{
	this->value = this->value - variable->getValue(ctx);
	return this;
}
IAlinousVariable* DoubleVariable::minus(LongVariable* variable, ThreadContext* ctx)
{
	this->value = this->value - variable->getValue(ctx);
	return this;
}
IAlinousVariable* DoubleVariable::minus(ShortVariable* variable, ThreadContext* ctx)
{
	this->value = this->value - variable->getValue(ctx);
	return this;
}
IAlinousVariable* DoubleVariable::minus(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1128(), ctx));
}
IAlinousVariable* DoubleVariable::multiply(VariantValue* variable, ThreadContext* ctx)
{
	return variable->multiply(this, ctx)->copy(ctx);
}
IAlinousVariable* DoubleVariable::multiply(DomVariable* variable, ThreadContext* ctx)
{
	return variable->multiply(this, ctx)->copy(ctx);
}
IAlinousVariable* DoubleVariable::multiply(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1127(), ctx));
}
IAlinousVariable* DoubleVariable::multiply(ByteVariable* variable, ThreadContext* ctx)
{
	this->value = this->value * variable->getValue(ctx);
	return this;
}
IAlinousVariable* DoubleVariable::multiply(CharVariable* variable, ThreadContext* ctx)
{
	this->value = this->value * variable->getValue(ctx);
	return this;
}
IAlinousVariable* DoubleVariable::multiply(DoubleVariable* variable, ThreadContext* ctx)
{
	this->value = this->value * variable->getValue(ctx);
	return this;
}
IAlinousVariable* DoubleVariable::multiply(FloatVariable* variable, ThreadContext* ctx)
{
	this->value = this->value * variable->getValue(ctx);
	return this;
}
IAlinousVariable* DoubleVariable::multiply(IntegerVariable* variable, ThreadContext* ctx)
{
	this->value = this->value * variable->getValue(ctx);
	return this;
}
IAlinousVariable* DoubleVariable::multiply(LongVariable* variable, ThreadContext* ctx)
{
	this->value = this->value * variable->getValue(ctx);
	return this;
}
IAlinousVariable* DoubleVariable::multiply(ShortVariable* variable, ThreadContext* ctx)
{
	this->value = this->value * variable->getValue(ctx);
	return this;
}
IAlinousVariable* DoubleVariable::multiply(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1128(), ctx));
}
IAlinousVariable* DoubleVariable::div(VariantValue* variable, ThreadContext* ctx)
{
	return (new(ctx) VariantValue(this->value, ctx))->div(variable, ctx);
}
IAlinousVariable* DoubleVariable::div(DomVariable* variable, ThreadContext* ctx)
{
	return (new(ctx) VariantValue(this->value, ctx))->div(variable, ctx);
}
IAlinousVariable* DoubleVariable::div(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1127(), ctx));
}
IAlinousVariable* DoubleVariable::div(ByteVariable* variable, ThreadContext* ctx)
{
	this->value = this->value / variable->getValue(ctx);
	return this;
}
IAlinousVariable* DoubleVariable::div(CharVariable* variable, ThreadContext* ctx)
{
	this->value = this->value / variable->getValue(ctx);
	return this;
}
IAlinousVariable* DoubleVariable::div(DoubleVariable* variable, ThreadContext* ctx)
{
	this->value = this->value / variable->getValue(ctx);
	return this;
}
IAlinousVariable* DoubleVariable::div(FloatVariable* variable, ThreadContext* ctx)
{
	this->value = this->value / variable->getValue(ctx);
	return this;
}
IAlinousVariable* DoubleVariable::div(IntegerVariable* variable, ThreadContext* ctx)
{
	this->value = this->value / variable->getValue(ctx);
	return this;
}
IAlinousVariable* DoubleVariable::div(LongVariable* variable, ThreadContext* ctx)
{
	this->value = this->value / variable->getValue(ctx);
	return this;
}
IAlinousVariable* DoubleVariable::div(ShortVariable* variable, ThreadContext* ctx)
{
	this->value = this->value / variable->getValue(ctx);
	return this;
}
IAlinousVariable* DoubleVariable::div(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1128(), ctx));
}
IAlinousVariable* DoubleVariable::bitReverse(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1130(), ctx));
}
bool DoubleVariable::isNull(ThreadContext* ctx) throw() 
{
	return false;
}
bool DoubleVariable::isArray(ThreadContext* ctx) throw() 
{
	return false;
}
IAlinousVariable* DoubleVariable::shiftLeft(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1129(), ctx));
}
IAlinousVariable* DoubleVariable::shiftLeft(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1129(), ctx));
}
IAlinousVariable* DoubleVariable::shiftLeft(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1129(), ctx));
}
IAlinousVariable* DoubleVariable::shiftLeft(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1129(), ctx));
}
IAlinousVariable* DoubleVariable::shiftLeft(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1129(), ctx));
}
IAlinousVariable* DoubleVariable::shiftLeft(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1129(), ctx));
}
IAlinousVariable* DoubleVariable::shiftLeft(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1129(), ctx));
}
IAlinousVariable* DoubleVariable::shiftLeft(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1129(), ctx));
}
IAlinousVariable* DoubleVariable::shiftLeft(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1129(), ctx));
}
IAlinousVariable* DoubleVariable::shiftLeft(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1129(), ctx));
}
IAlinousVariable* DoubleVariable::shiftLeft(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1129(), ctx));
}
IAlinousVariable* DoubleVariable::shiftRight(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1129(), ctx));
}
IAlinousVariable* DoubleVariable::shiftRight(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1129(), ctx));
}
IAlinousVariable* DoubleVariable::shiftRight(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1129(), ctx));
}
IAlinousVariable* DoubleVariable::shiftRight(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1129(), ctx));
}
IAlinousVariable* DoubleVariable::shiftRight(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1129(), ctx));
}
IAlinousVariable* DoubleVariable::shiftRight(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1129(), ctx));
}
IAlinousVariable* DoubleVariable::shiftRight(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1129(), ctx));
}
IAlinousVariable* DoubleVariable::shiftRight(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1129(), ctx));
}
IAlinousVariable* DoubleVariable::shiftRight(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1129(), ctx));
}
IAlinousVariable* DoubleVariable::shiftRight(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1129(), ctx));
}
IAlinousVariable* DoubleVariable::shiftRight(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1129(), ctx));
}
IAlinousVariable* DoubleVariable::modulo(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1129(), ctx));
}
IAlinousVariable* DoubleVariable::modulo(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1129(), ctx));
}
IAlinousVariable* DoubleVariable::modulo(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1129(), ctx));
}
IAlinousVariable* DoubleVariable::modulo(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1129(), ctx));
}
IAlinousVariable* DoubleVariable::modulo(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1129(), ctx));
}
IAlinousVariable* DoubleVariable::modulo(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1129(), ctx));
}
IAlinousVariable* DoubleVariable::modulo(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1129(), ctx));
}
IAlinousVariable* DoubleVariable::modulo(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1129(), ctx));
}
IAlinousVariable* DoubleVariable::modulo(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1129(), ctx));
}
IAlinousVariable* DoubleVariable::modulo(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1129(), ctx));
}
IAlinousVariable* DoubleVariable::modulo(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1129(), ctx));
}
IAlinousVariable* DoubleVariable::substitute(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1127(), ctx));
}
IAlinousVariable* DoubleVariable::substitute(DomVariable* variable, ThreadContext* ctx)
{
	this->value = variable->getValue(ctx)->getDouble(ctx);
	return this;
}
IAlinousVariable* DoubleVariable::substitute(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1127(), ctx));
}
IAlinousVariable* DoubleVariable::substitute(ByteVariable* variable, ThreadContext* ctx)
{
	this->value = variable->getValue(ctx);
	return this;
}
IAlinousVariable* DoubleVariable::substitute(CharVariable* variable, ThreadContext* ctx)
{
	this->value = variable->getValue(ctx);
	return this;
}
IAlinousVariable* DoubleVariable::substitute(DoubleVariable* variable, ThreadContext* ctx)
{
	this->value = variable->getValue(ctx);
	return this;
}
IAlinousVariable* DoubleVariable::substitute(FloatVariable* variable, ThreadContext* ctx)
{
	this->value = variable->getValue(ctx);
	return this;
}
IAlinousVariable* DoubleVariable::substitute(IntegerVariable* variable, ThreadContext* ctx)
{
	this->value = variable->getValue(ctx);
	return this;
}
IAlinousVariable* DoubleVariable::substitute(LongVariable* variable, ThreadContext* ctx)
{
	this->value = variable->getValue(ctx);
	return this;
}
IAlinousVariable* DoubleVariable::substitute(ShortVariable* variable, ThreadContext* ctx)
{
	this->value = variable->getValue(ctx);
	return this;
}
IAlinousVariable* DoubleVariable::substitute(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1129(), ctx));
}
int DoubleVariable::compareTo(VariantValue* variable, ThreadContext* ctx)
{
	return ((int)(this->value - variable->getDouble(ctx)));
}
int DoubleVariable::compareTo(DomVariable* variable, ThreadContext* ctx)
{
	return ((int)(this->value - variable->getValue(ctx)->getDouble(ctx)));
}
int DoubleVariable::compareTo(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1127(), ctx));
}
int DoubleVariable::compareTo(ByteVariable* variable, ThreadContext* ctx)
{
	return ((int)(this->value - variable->getValue(ctx)));
}
int DoubleVariable::compareTo(CharVariable* variable, ThreadContext* ctx)
{
	return ((int)(this->value - variable->getValue(ctx)));
}
int DoubleVariable::compareTo(DoubleVariable* variable, ThreadContext* ctx)
{
	return ((int)(this->value - variable->getValue(ctx)));
}
int DoubleVariable::compareTo(FloatVariable* variable, ThreadContext* ctx)
{
	return ((int)(this->value - variable->getValue(ctx)));
}
int DoubleVariable::compareTo(IntegerVariable* variable, ThreadContext* ctx)
{
	return ((int)(this->value - variable->getValue(ctx)));
}
int DoubleVariable::compareTo(LongVariable* variable, ThreadContext* ctx)
{
	return ((int)(this->value - variable->getValue(ctx)));
}
int DoubleVariable::compareTo(ShortVariable* variable, ThreadContext* ctx)
{
	return ((int)(this->value - variable->getValue(ctx)));
}
int DoubleVariable::compareTo(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1128(), ctx));
}
bool DoubleVariable::isTrue(ThreadContext* ctx)
{
	return this->value > (double)0;
}
IAlinousVariable* DoubleVariable::bitOr(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1130(), ctx));
}
IAlinousVariable* DoubleVariable::bitOr(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1130(), ctx));
}
IAlinousVariable* DoubleVariable::bitOr(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1130(), ctx));
}
IAlinousVariable* DoubleVariable::bitOr(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1130(), ctx));
}
IAlinousVariable* DoubleVariable::bitOr(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1130(), ctx));
}
IAlinousVariable* DoubleVariable::bitOr(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1130(), ctx));
}
IAlinousVariable* DoubleVariable::bitOr(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1130(), ctx));
}
IAlinousVariable* DoubleVariable::bitOr(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1130(), ctx));
}
IAlinousVariable* DoubleVariable::bitOr(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1130(), ctx));
}
IAlinousVariable* DoubleVariable::bitOr(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1130(), ctx));
}
IAlinousVariable* DoubleVariable::bitOr(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1130(), ctx));
}
IAlinousVariable* DoubleVariable::bitAnd(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1130(), ctx));
}
IAlinousVariable* DoubleVariable::bitAnd(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1130(), ctx));
}
IAlinousVariable* DoubleVariable::bitAnd(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1130(), ctx));
}
IAlinousVariable* DoubleVariable::bitAnd(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1130(), ctx));
}
IAlinousVariable* DoubleVariable::bitAnd(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1130(), ctx));
}
IAlinousVariable* DoubleVariable::bitAnd(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1130(), ctx));
}
IAlinousVariable* DoubleVariable::bitAnd(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1130(), ctx));
}
IAlinousVariable* DoubleVariable::bitAnd(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1130(), ctx));
}
IAlinousVariable* DoubleVariable::bitAnd(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1130(), ctx));
}
IAlinousVariable* DoubleVariable::bitAnd(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1130(), ctx));
}
IAlinousVariable* DoubleVariable::bitAnd(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1130(), ctx));
}
IAlinousVariable* DoubleVariable::bitExor(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1130(), ctx));
}
IAlinousVariable* DoubleVariable::bitExor(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1130(), ctx));
}
IAlinousVariable* DoubleVariable::bitExor(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1130(), ctx));
}
IAlinousVariable* DoubleVariable::bitExor(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1130(), ctx));
}
IAlinousVariable* DoubleVariable::bitExor(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1130(), ctx));
}
IAlinousVariable* DoubleVariable::bitExor(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1130(), ctx));
}
IAlinousVariable* DoubleVariable::bitExor(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1130(), ctx));
}
IAlinousVariable* DoubleVariable::bitExor(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1130(), ctx));
}
IAlinousVariable* DoubleVariable::bitExor(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1130(), ctx));
}
IAlinousVariable* DoubleVariable::bitExor(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1130(), ctx));
}
IAlinousVariable* DoubleVariable::bitExor(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1130(), ctx));
}
IAlinousVariable* DoubleVariable::add(BigDecimalVariable* variable, ThreadContext* ctx)
{
	this->value = this->value + variable->getValue(ctx)->doubleValue(ctx);
	return this;
}
IAlinousVariable* DoubleVariable::minus(BigDecimalVariable* variable, ThreadContext* ctx)
{
	this->value = this->value - variable->getValue(ctx)->doubleValue(ctx);
	return this;
}
IAlinousVariable* DoubleVariable::multiply(BigDecimalVariable* variable, ThreadContext* ctx)
{
	this->value = this->value * variable->getValue(ctx)->doubleValue(ctx);
	return this;
}
IAlinousVariable* DoubleVariable::div(BigDecimalVariable* variable, ThreadContext* ctx)
{
	this->value = this->value / variable->getValue(ctx)->doubleValue(ctx);
	return this;
}
IAlinousVariable* DoubleVariable::shiftLeft(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1131(), ctx));
}
IAlinousVariable* DoubleVariable::shiftRight(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1131(), ctx));
}
IAlinousVariable* DoubleVariable::modulo(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1131(), ctx));
}
IAlinousVariable* DoubleVariable::bitOr(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1131(), ctx));
}
IAlinousVariable* DoubleVariable::bitAnd(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1131(), ctx));
}
IAlinousVariable* DoubleVariable::bitExor(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1131(), ctx));
}
IAlinousVariable* DoubleVariable::substitute(BigDecimalVariable* variable, ThreadContext* ctx)
{
	this->value = variable->getValue(ctx)->doubleValue(ctx);
	return this;
}
int DoubleVariable::compareTo(BigDecimalVariable* variable, ThreadContext* ctx)
{
	return ((int)(this->value - variable->getValue(ctx)->doubleValue(ctx)));
}
IAlinousVariable* DoubleVariable::shiftRightUnsigned(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1129(), ctx));
}
IAlinousVariable* DoubleVariable::shiftRightUnsigned(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1129(), ctx));
}
IAlinousVariable* DoubleVariable::shiftRightUnsigned(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1129(), ctx));
}
IAlinousVariable* DoubleVariable::shiftRightUnsigned(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1129(), ctx));
}
IAlinousVariable* DoubleVariable::shiftRightUnsigned(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1129(), ctx));
}
IAlinousVariable* DoubleVariable::shiftRightUnsigned(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1129(), ctx));
}
IAlinousVariable* DoubleVariable::shiftRightUnsigned(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1129(), ctx));
}
IAlinousVariable* DoubleVariable::shiftRightUnsigned(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1129(), ctx));
}
IAlinousVariable* DoubleVariable::shiftRightUnsigned(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1129(), ctx));
}
IAlinousVariable* DoubleVariable::shiftRightUnsigned(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1129(), ctx));
}
IAlinousVariable* DoubleVariable::shiftRightUnsigned(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1129(), ctx));
}
IAlinousVariable* DoubleVariable::shiftRightUnsigned(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1129(), ctx));
}
BoolVariable* DoubleVariable::toBoolVariable(ThreadContext* ctx)
{
	return (new(ctx) BoolVariable(isTrue(ctx), ctx));
}
ByteVariable* DoubleVariable::toByteVariable(ThreadContext* ctx)
{
	return (new(ctx) ByteVariable(((char)this->value), ctx));
}
CharVariable* DoubleVariable::toCharVariable(ThreadContext* ctx)
{
	return (new(ctx) CharVariable(((wchar_t)this->value), ctx));
}
ShortVariable* DoubleVariable::toShortVariable(ThreadContext* ctx)
{
	return (new(ctx) ShortVariable(((short)this->value), ctx));
}
IntegerVariable* DoubleVariable::toIntVariable(ThreadContext* ctx)
{
	return (new(ctx) IntegerVariable(((int)this->value), ctx));
}
LongVariable* DoubleVariable::toLongVariable(ThreadContext* ctx)
{
	return (new(ctx) LongVariable(((long long)this->value), ctx));
}
StringVariable* DoubleVariable::toStringVariable(ThreadContext* ctx)
{
	return (new(ctx) StringVariable(getStringValue(ctx), ctx));
}
BigDecimalVariable* DoubleVariable::toBigDecimalVariable(ThreadContext* ctx)
{
	BigDecimal* dec = (new(ctx) BigDecimal(this->value, ctx));
	return (new(ctx) BigDecimalVariable(dec, ctx));
}
long long DoubleVariable::getLongValue(ThreadContext* ctx)
{
	return ((long long)this->value);
}
FloatVariable* DoubleVariable::toFloatVariable(ThreadContext* ctx)
{
	return (new(ctx) FloatVariable(((float)this->value), ctx));
}
DoubleVariable* DoubleVariable::toDoubleVariable(ThreadContext* ctx)
{
	return (new(ctx) DoubleVariable(this->value, ctx));
}
TimeVariable* DoubleVariable::toTimeVariable(ThreadContext* ctx)
{
	TimeOnlyTimestamp* tm = (new(ctx) TimeOnlyTimestamp(((long long)this->value), ctx));
	return (new(ctx) TimeVariable(tm, ctx));
}
TimestampVariable* DoubleVariable::toTimestampVariable(ThreadContext* ctx)
{
	Timestamp* tm = (new(ctx) Timestamp(((long long)this->value), ctx));
	return (new(ctx) TimestampVariable(tm, ctx));
}
IAlinousVariable* DoubleVariable::add(TimeVariable* variable, ThreadContext* ctx)
{
	this->value = this->value + variable->getValue(ctx)->getTime(ctx);
	return this;
}
IAlinousVariable* DoubleVariable::add(TimestampVariable* variable, ThreadContext* ctx)
{
	this->value = this->value + variable->getValue(ctx)->getTime(ctx);
	return this;
}
IAlinousVariable* DoubleVariable::minus(TimeVariable* variable, ThreadContext* ctx)
{
	this->value = this->value - variable->getValue(ctx)->getTime(ctx);
	return this;
}
IAlinousVariable* DoubleVariable::minus(TimestampVariable* variable, ThreadContext* ctx)
{
	this->value = this->value - variable->getValue(ctx)->getTime(ctx);
	return this;
}
IAlinousVariable* DoubleVariable::multiply(TimeVariable* variable, ThreadContext* ctx)
{
	this->value = this->value * variable->getValue(ctx)->getTime(ctx);
	return this;
}
IAlinousVariable* DoubleVariable::multiply(TimestampVariable* variable, ThreadContext* ctx)
{
	this->value = this->value * variable->getValue(ctx)->getTime(ctx);
	return this;
}
IAlinousVariable* DoubleVariable::div(TimeVariable* variable, ThreadContext* ctx)
{
	this->value = this->value / variable->getValue(ctx)->getTime(ctx);
	return this;
}
IAlinousVariable* DoubleVariable::div(TimestampVariable* variable, ThreadContext* ctx)
{
	this->value = this->value / variable->getValue(ctx)->getTime(ctx);
	return this;
}
IAlinousVariable* DoubleVariable::shiftLeft(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1132(), ctx));
}
IAlinousVariable* DoubleVariable::shiftLeft(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1132(), ctx));
}
IAlinousVariable* DoubleVariable::shiftRight(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1132(), ctx));
}
IAlinousVariable* DoubleVariable::shiftRight(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1132(), ctx));
}
IAlinousVariable* DoubleVariable::shiftRightUnsigned(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1132(), ctx));
}
IAlinousVariable* DoubleVariable::shiftRightUnsigned(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1132(), ctx));
}
IAlinousVariable* DoubleVariable::modulo(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1132(), ctx));
}
IAlinousVariable* DoubleVariable::modulo(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1132(), ctx));
}
IAlinousVariable* DoubleVariable::bitOr(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1132(), ctx));
}
IAlinousVariable* DoubleVariable::bitOr(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1132(), ctx));
}
IAlinousVariable* DoubleVariable::bitAnd(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1132(), ctx));
}
IAlinousVariable* DoubleVariable::bitAnd(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1132(), ctx));
}
IAlinousVariable* DoubleVariable::bitExor(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1132(), ctx));
}
IAlinousVariable* DoubleVariable::bitExor(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1132(), ctx));
}
IAlinousVariable* DoubleVariable::substitute(TimeVariable* variable, ThreadContext* ctx)
{
	this->value = variable->getValue(ctx)->getTime(ctx);
	return this;
}
IAlinousVariable* DoubleVariable::substitute(TimestampVariable* variable, ThreadContext* ctx)
{
	this->value = variable->getValue(ctx)->getTime(ctx);
	return this;
}
int DoubleVariable::compareTo(TimeVariable* variable, ThreadContext* ctx)
{
	return ((int)(this->value - variable->getValue(ctx)->getTime(ctx)));
}
int DoubleVariable::compareTo(TimestampVariable* variable, ThreadContext* ctx)
{
	return ((int)(this->value - variable->getValue(ctx)->getTime(ctx)));
}
IAlinousVariable* DoubleVariable::substitute(TypedVariableArray* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1122(), ctx));
}
void DoubleVariable::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	this->value = buff->getDouble(ctx);
}
void DoubleVariable::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putInt(ICommandData::__DoubleVariable, ctx);
	buff->putDouble(this->value, ctx);
}
DoubleVariable* DoubleVariable::fromDebugXml(DomNode* node, ThreadContext* ctx) throw() 
{
	IVariableValue* attrVal = node->getAttributeValue(VAL_TYPE, ctx);
	if(attrVal == nullptr)
	{
		return nullptr;
	}
	String* str = attrVal->toString(ctx);
	double value = 0;
	{
		try
		{
			value = Double::parseDouble(str, ctx);
		}
		catch(Throwable* e)
		{
			e->printStackTrace(ctx);
			return nullptr;
		}
	}
	return (new(ctx) DoubleVariable(value, ctx));
}
int DoubleVariable::ValueCompare::operator() (VariantValue* _this, VariantValue* variable, ThreadContext* ctx) const throw()
{
	return _this->compareTo(variable, ctx);
}
}}}}

