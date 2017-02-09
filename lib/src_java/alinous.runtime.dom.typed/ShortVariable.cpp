#include "includes.h"


namespace alinous {namespace runtime {namespace dom {namespace typed {





String* ShortVariable::VAL_TYPE = ConstStr::getCNST_STR_1147();
bool ShortVariable::__init_done = __init_static_variables();
bool ShortVariable::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ShortVariable", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ShortVariable::ShortVariable(short value, ThreadContext* ctx) throw()  : IObject(ctx), AbstractTypedVariable(ctx), value(0)
{
	this->value = value;
}
void ShortVariable::__construct_impl(short value, ThreadContext* ctx) throw() 
{
	this->value = value;
}
 ShortVariable::~ShortVariable() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ShortVariable::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ShortVariable", L"~ShortVariable");
	if(!prepare){
		return;
	}
	AbstractTypedVariable::__releaseRegerences(true, ctx);
}
void ShortVariable::outDebugXml(DomNode* parentNode, String* name, ThreadContext* ctx) throw() 
{
	DomNode* node = (new(ctx) DomNode(VAL_TYPE, ctx));
	parentNode->addChild(node, ctx);
	if(name != nullptr)
	{
		Attribute* nameattr = (new(ctx) Attribute(IAlinousVariable::ATTR_NAME, name, node, ctx));
		node->addAttribute(nameattr, ctx);
	}
	Attribute* attr = (new(ctx) Attribute(AbstractTypedVariable::VALUE, Short::toString(this->value, ctx), node, ctx));
	parentNode->addAttribute(attr, ctx);
}
int ShortVariable::getVariableClass(ThreadContext* ctx) throw() 
{
	return IAlinousVariable::CLASS_TYPED;
}
int ShortVariable::getTypedType(ThreadContext* ctx) throw() 
{
	return ITypedVariable::TYPE_SHORT;
}
short ShortVariable::getValue(ThreadContext* ctx) throw() 
{
	return value;
}
void ShortVariable::setValue(short value, ThreadContext* ctx) throw() 
{
	this->value = value;
}
VariantValue* ShortVariable::toVariantValue(ThreadContext* ctx)
{
	return (new(ctx) VariantValue(this->value, ctx));
}
int ShortVariable::getIntValue(ThreadContext* ctx)
{
	return this->value;
}
String* ShortVariable::getStringValue(ThreadContext* ctx)
{
	return Short::toString(this->value, ctx);
}
IAlinousVariable* ShortVariable::copy(ThreadContext* ctx)
{
	return (new(ctx) ShortVariable(this->value, ctx));
}
IDomVariable* ShortVariable::toDomVariable(ThreadContext* ctx) throw() 
{
	DomVariable* ret = (new(ctx) DomVariable(ctx));
	ret->setValue((new(ctx) VariantValue(this->value, ctx)), ctx);
	return ret;
}
IAlinousVariable* ShortVariable::add(LongVariable* variable, ThreadContext* ctx)
{
	long long res = this->value + variable->getValue(ctx);
	return (new(ctx) LongVariable(res, ctx));
}
IAlinousVariable* ShortVariable::minus(LongVariable* variable, ThreadContext* ctx)
{
	long long res = this->value - variable->getValue(ctx);
	return (new(ctx) LongVariable(res, ctx));
}
IAlinousVariable* ShortVariable::multiply(LongVariable* variable, ThreadContext* ctx)
{
	long long res = this->value * variable->getValue(ctx);
	return (new(ctx) LongVariable(res, ctx));
}
IAlinousVariable* ShortVariable::div(LongVariable* variable, ThreadContext* ctx)
{
	long long res = this->value / variable->getValue(ctx);
	return (new(ctx) LongVariable(res, ctx));
}
IAlinousVariable* ShortVariable::add(VariantValue* variable, ThreadContext* ctx)
{
	return variable->add(this, ctx)->copy(ctx);
}
IAlinousVariable* ShortVariable::add(DomVariable* variable, ThreadContext* ctx)
{
	return variable->add(this, ctx)->copy(ctx);
}
IAlinousVariable* ShortVariable::add(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1134(), ctx));
}
IAlinousVariable* ShortVariable::add(ByteVariable* variable, ThreadContext* ctx)
{
	this->value = ((short)(this->value + variable->getValue(ctx)));
	return this;
}
IAlinousVariable* ShortVariable::add(CharVariable* variable, ThreadContext* ctx)
{
	this->value = ((short)(this->value + variable->getValue(ctx)));
	return this;
}
IAlinousVariable* ShortVariable::add(DoubleVariable* variable, ThreadContext* ctx)
{
	double res = this->value + variable->getValue(ctx);
	return (new(ctx) DoubleVariable(res, ctx));
}
IAlinousVariable* ShortVariable::add(FloatVariable* variable, ThreadContext* ctx)
{
	float res = this->value + variable->getValue(ctx);
	return (new(ctx) FloatVariable(res, ctx));
}
IAlinousVariable* ShortVariable::add(IntegerVariable* variable, ThreadContext* ctx)
{
	int res = this->value + variable->getValue(ctx);
	return (new(ctx) IntegerVariable(res, ctx));
}
IAlinousVariable* ShortVariable::add(ShortVariable* variable, ThreadContext* ctx)
{
	this->value = ((short)(this->value + variable->getValue(ctx)));
	return this;
}
IAlinousVariable* ShortVariable::add(StringVariable* variable, ThreadContext* ctx)
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	buff->append(Short::toString(value, ctx), ctx);
	buff->append(variable->getValue(ctx), ctx);
	return (new(ctx) StringVariable(buff->toString(ctx), ctx));
}
IAlinousVariable* ShortVariable::minus(VariantValue* variable, ThreadContext* ctx)
{
	return (new(ctx) VariantValue(this->value, ctx))->minus(variable, ctx);
}
IAlinousVariable* ShortVariable::minus(DomVariable* variable, ThreadContext* ctx)
{
	return (new(ctx) VariantValue(this->value, ctx))->minus(variable, ctx);
}
IAlinousVariable* ShortVariable::minus(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1134(), ctx));
}
IAlinousVariable* ShortVariable::minus(ByteVariable* variable, ThreadContext* ctx)
{
	this->value = ((short)(this->value - variable->getValue(ctx)));
	return this;
}
IAlinousVariable* ShortVariable::minus(CharVariable* variable, ThreadContext* ctx)
{
	this->value = ((short)(this->value - variable->getValue(ctx)));
	return this;
}
IAlinousVariable* ShortVariable::minus(DoubleVariable* variable, ThreadContext* ctx)
{
	double res = this->value - variable->getValue(ctx);
	return (new(ctx) DoubleVariable(res, ctx));
}
IAlinousVariable* ShortVariable::minus(FloatVariable* variable, ThreadContext* ctx)
{
	float res = this->value - variable->getValue(ctx);
	return (new(ctx) FloatVariable(res, ctx));
}
IAlinousVariable* ShortVariable::minus(IntegerVariable* variable, ThreadContext* ctx)
{
	int res = this->value - variable->getValue(ctx);
	return (new(ctx) IntegerVariable(res, ctx));
}
IAlinousVariable* ShortVariable::minus(ShortVariable* variable, ThreadContext* ctx)
{
	this->value = ((short)(this->value - variable->getValue(ctx)));
	return this;
}
IAlinousVariable* ShortVariable::minus(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* ShortVariable::multiply(VariantValue* variable, ThreadContext* ctx)
{
	return variable->multiply(this, ctx)->copy(ctx);
}
IAlinousVariable* ShortVariable::multiply(DomVariable* variable, ThreadContext* ctx)
{
	return variable->multiply(this, ctx)->copy(ctx);
}
IAlinousVariable* ShortVariable::multiply(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1134(), ctx));
}
IAlinousVariable* ShortVariable::multiply(ByteVariable* variable, ThreadContext* ctx)
{
	this->value = ((short)(this->value * variable->getValue(ctx)));
	return this;
}
IAlinousVariable* ShortVariable::multiply(CharVariable* variable, ThreadContext* ctx)
{
	this->value = ((short)(this->value * variable->getValue(ctx)));
	return this;
}
IAlinousVariable* ShortVariable::multiply(DoubleVariable* variable, ThreadContext* ctx)
{
	double res = this->value * variable->getValue(ctx);
	return (new(ctx) DoubleVariable(res, ctx));
}
IAlinousVariable* ShortVariable::multiply(FloatVariable* variable, ThreadContext* ctx)
{
	float res = this->value * variable->getValue(ctx);
	return (new(ctx) FloatVariable(res, ctx));
}
IAlinousVariable* ShortVariable::multiply(IntegerVariable* variable, ThreadContext* ctx)
{
	int res = this->value * variable->getValue(ctx);
	return (new(ctx) IntegerVariable(res, ctx));
}
IAlinousVariable* ShortVariable::multiply(ShortVariable* variable, ThreadContext* ctx)
{
	this->value = ((short)(this->value / variable->getValue(ctx)));
	return this;
}
IAlinousVariable* ShortVariable::multiply(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* ShortVariable::div(VariantValue* variable, ThreadContext* ctx)
{
	return (new(ctx) VariantValue(this->value, ctx))->div(variable, ctx);
}
IAlinousVariable* ShortVariable::div(DomVariable* variable, ThreadContext* ctx)
{
	return (new(ctx) VariantValue(this->value, ctx))->div(variable, ctx);
}
IAlinousVariable* ShortVariable::div(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1134(), ctx));
}
IAlinousVariable* ShortVariable::div(ByteVariable* variable, ThreadContext* ctx)
{
	this->value = ((short)(this->value / variable->getValue(ctx)));
	return this;
}
IAlinousVariable* ShortVariable::div(CharVariable* variable, ThreadContext* ctx)
{
	this->value = ((short)(this->value / variable->getValue(ctx)));
	return this;
}
IAlinousVariable* ShortVariable::div(DoubleVariable* variable, ThreadContext* ctx)
{
	double res = this->value / variable->getValue(ctx);
	return (new(ctx) DoubleVariable(res, ctx));
}
IAlinousVariable* ShortVariable::div(FloatVariable* variable, ThreadContext* ctx)
{
	float res = this->value / variable->getValue(ctx);
	return (new(ctx) FloatVariable(res, ctx));
}
IAlinousVariable* ShortVariable::div(IntegerVariable* variable, ThreadContext* ctx)
{
	int res = this->value / variable->getValue(ctx);
	return (new(ctx) IntegerVariable(res, ctx));
}
IAlinousVariable* ShortVariable::div(ShortVariable* variable, ThreadContext* ctx)
{
	this->value = ((short)(this->value / variable->getValue(ctx)));
	return this;
}
IAlinousVariable* ShortVariable::div(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* ShortVariable::bitReverse(ThreadContext* ctx)
{
	this->value = ((short)~this->value);
	return this;
}
bool ShortVariable::isNull(ThreadContext* ctx) throw() 
{
	return false;
}
bool ShortVariable::isArray(ThreadContext* ctx) throw() 
{
	return false;
}
IAlinousVariable* ShortVariable::shiftLeft(VariantValue* variable, ThreadContext* ctx)
{
	this->value = ((short)(this->value << variable->getInt(ctx)));
	return this;
}
IAlinousVariable* ShortVariable::shiftLeft(DomVariable* variable, ThreadContext* ctx)
{
	this->value = ((short)(this->value << variable->getValue(ctx)->getInt(ctx)));
	return this;
}
IAlinousVariable* ShortVariable::shiftLeft(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1134(), ctx));
}
IAlinousVariable* ShortVariable::shiftLeft(ByteVariable* variable, ThreadContext* ctx)
{
	this->value = ((short)(this->value << variable->getValue(ctx)));
	return this;
}
IAlinousVariable* ShortVariable::shiftLeft(CharVariable* variable, ThreadContext* ctx)
{
	this->value = ((short)(this->value << variable->getValue(ctx)));
	return this;
}
IAlinousVariable* ShortVariable::shiftLeft(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* ShortVariable::shiftLeft(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* ShortVariable::shiftLeft(IntegerVariable* variable, ThreadContext* ctx)
{
	this->value = ((short)(this->value << variable->getValue(ctx)));
	return this;
}
IAlinousVariable* ShortVariable::shiftLeft(LongVariable* variable, ThreadContext* ctx)
{
	this->value = ((short)(this->value << variable->getValue(ctx)));
	return this;
}
IAlinousVariable* ShortVariable::shiftLeft(ShortVariable* variable, ThreadContext* ctx)
{
	this->value = ((short)(this->value << variable->getValue(ctx)));
	return this;
}
IAlinousVariable* ShortVariable::shiftLeft(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* ShortVariable::shiftRight(VariantValue* variable, ThreadContext* ctx)
{
	this->value = ((short)(this->value >> variable->getInt(ctx)));
	return this;
}
IAlinousVariable* ShortVariable::shiftRight(DomVariable* variable, ThreadContext* ctx)
{
	this->value = ((short)(this->value >> variable->getValue(ctx)->getInt(ctx)));
	return this;
}
IAlinousVariable* ShortVariable::shiftRight(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1134(), ctx));
}
IAlinousVariable* ShortVariable::shiftRight(ByteVariable* variable, ThreadContext* ctx)
{
	this->value = ((short)(this->value >> variable->getValue(ctx)));
	return this;
}
IAlinousVariable* ShortVariable::shiftRight(CharVariable* variable, ThreadContext* ctx)
{
	this->value = ((short)(this->value >> variable->getValue(ctx)));
	return this;
}
IAlinousVariable* ShortVariable::shiftRight(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* ShortVariable::shiftRight(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* ShortVariable::shiftRight(IntegerVariable* variable, ThreadContext* ctx)
{
	this->value = ((short)(this->value >> variable->getValue(ctx)));
	return this;
}
IAlinousVariable* ShortVariable::shiftRight(LongVariable* variable, ThreadContext* ctx)
{
	this->value = ((short)(this->value >> variable->getValue(ctx)));
	return this;
}
IAlinousVariable* ShortVariable::shiftRight(ShortVariable* variable, ThreadContext* ctx)
{
	this->value = ((short)(this->value >> variable->getValue(ctx)));
	return this;
}
IAlinousVariable* ShortVariable::shiftRight(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* ShortVariable::modulo(VariantValue* variable, ThreadContext* ctx)
{
	this->value = ((short)(this->value % variable->getShort(ctx)));
	return this;
}
IAlinousVariable* ShortVariable::modulo(DomVariable* variable, ThreadContext* ctx)
{
	this->value = ((short)(this->value % variable->getValue(ctx)->getShort(ctx)));
	return this;
}
IAlinousVariable* ShortVariable::modulo(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1134(), ctx));
}
IAlinousVariable* ShortVariable::modulo(ByteVariable* variable, ThreadContext* ctx)
{
	this->value = ((short)(this->value % variable->getValue(ctx)));
	return this;
}
IAlinousVariable* ShortVariable::modulo(CharVariable* variable, ThreadContext* ctx)
{
	this->value = ((short)(this->value % variable->getValue(ctx)));
	return this;
}
IAlinousVariable* ShortVariable::modulo(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* ShortVariable::modulo(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* ShortVariable::modulo(IntegerVariable* variable, ThreadContext* ctx)
{
	this->value = ((short)(this->value % variable->getValue(ctx)));
	return this;
}
IAlinousVariable* ShortVariable::modulo(LongVariable* variable, ThreadContext* ctx)
{
	this->value = ((short)(this->value % variable->getValue(ctx)));
	return this;
}
IAlinousVariable* ShortVariable::modulo(ShortVariable* variable, ThreadContext* ctx)
{
	this->value = ((short)(this->value % variable->getValue(ctx)));
	return this;
}
IAlinousVariable* ShortVariable::modulo(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* ShortVariable::substitute(VariantValue* variable, ThreadContext* ctx)
{
	this->value = ((short)variable->getShort(ctx));
	return this;
}
IAlinousVariable* ShortVariable::substitute(DomVariable* variable, ThreadContext* ctx)
{
	this->value = ((short)variable->getValue(ctx)->getShort(ctx));
	return this;
}
IAlinousVariable* ShortVariable::substitute(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1134(), ctx));
}
IAlinousVariable* ShortVariable::substitute(ByteVariable* variable, ThreadContext* ctx)
{
	this->value = variable->getValue(ctx);
	return this;
}
IAlinousVariable* ShortVariable::substitute(CharVariable* variable, ThreadContext* ctx)
{
	this->value = ((short)variable->getValue(ctx));
	return this;
}
IAlinousVariable* ShortVariable::substitute(DoubleVariable* variable, ThreadContext* ctx)
{
	this->value = ((short)variable->getValue(ctx));
	return this;
}
IAlinousVariable* ShortVariable::substitute(FloatVariable* variable, ThreadContext* ctx)
{
	this->value = ((short)variable->getValue(ctx));
	return this;
}
IAlinousVariable* ShortVariable::substitute(IntegerVariable* variable, ThreadContext* ctx)
{
	this->value = ((short)variable->getValue(ctx));
	return this;
}
IAlinousVariable* ShortVariable::substitute(LongVariable* variable, ThreadContext* ctx)
{
	this->value = ((short)variable->getValue(ctx));
	return this;
}
IAlinousVariable* ShortVariable::substitute(ShortVariable* variable, ThreadContext* ctx)
{
	this->value = variable->getValue(ctx);
	return this;
}
IAlinousVariable* ShortVariable::substitute(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
int ShortVariable::compareTo(VariantValue* variable, ThreadContext* ctx)
{
	return ((int)(this->value - variable->getShort(ctx)));
}
int ShortVariable::compareTo(DomVariable* variable, ThreadContext* ctx)
{
	return ((int)(this->value - variable->getValue(ctx)->getShort(ctx)));
}
int ShortVariable::compareTo(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1134(), ctx));
}
int ShortVariable::compareTo(ByteVariable* variable, ThreadContext* ctx)
{
	return ((int)(this->value - variable->getValue(ctx)));
}
int ShortVariable::compareTo(CharVariable* variable, ThreadContext* ctx)
{
	return ((int)(this->value - variable->getValue(ctx)));
}
int ShortVariable::compareTo(DoubleVariable* variable, ThreadContext* ctx)
{
	return ((int)(this->value - variable->getValue(ctx)));
}
int ShortVariable::compareTo(FloatVariable* variable, ThreadContext* ctx)
{
	return ((int)(this->value - variable->getValue(ctx)));
}
int ShortVariable::compareTo(IntegerVariable* variable, ThreadContext* ctx)
{
	return ((int)(this->value - variable->getValue(ctx)));
}
int ShortVariable::compareTo(LongVariable* variable, ThreadContext* ctx)
{
	return ((int)(this->value - variable->getValue(ctx)));
}
int ShortVariable::compareTo(ShortVariable* variable, ThreadContext* ctx)
{
	return ((int)(this->value - variable->getValue(ctx)));
}
int ShortVariable::compareTo(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
bool ShortVariable::isTrue(ThreadContext* ctx)
{
	return this->value > (short)0;
}
IAlinousVariable* ShortVariable::bitOr(VariantValue* variable, ThreadContext* ctx)
{
	this->value = ((short)(this->value | variable->getShort(ctx)));
	return this;
}
IAlinousVariable* ShortVariable::bitOr(DomVariable* variable, ThreadContext* ctx)
{
	this->value = ((short)(this->value | variable->getValue(ctx)->getShort(ctx)));
	return this;
}
IAlinousVariable* ShortVariable::bitOr(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1134(), ctx));
}
IAlinousVariable* ShortVariable::bitOr(ByteVariable* variable, ThreadContext* ctx)
{
	this->value = ((short)(this->value | variable->getValue(ctx)));
	return this;
}
IAlinousVariable* ShortVariable::bitOr(CharVariable* variable, ThreadContext* ctx)
{
	this->value = ((short)(this->value | variable->getValue(ctx)));
	return this;
}
IAlinousVariable* ShortVariable::bitOr(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1137(), ctx));
}
IAlinousVariable* ShortVariable::bitOr(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1137(), ctx));
}
IAlinousVariable* ShortVariable::bitOr(IntegerVariable* variable, ThreadContext* ctx)
{
	this->value = ((short)(this->value | variable->getValue(ctx)));
	return this;
}
IAlinousVariable* ShortVariable::bitOr(LongVariable* variable, ThreadContext* ctx)
{
	this->value = ((short)(this->value | variable->getValue(ctx)));
	return this;
}
IAlinousVariable* ShortVariable::bitOr(ShortVariable* variable, ThreadContext* ctx)
{
	this->value = ((short)(this->value | variable->getValue(ctx)));
	return this;
}
IAlinousVariable* ShortVariable::bitOr(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* ShortVariable::bitAnd(VariantValue* variable, ThreadContext* ctx)
{
	this->value = ((short)(this->value & variable->getShort(ctx)));
	return this;
}
IAlinousVariable* ShortVariable::bitAnd(DomVariable* variable, ThreadContext* ctx)
{
	this->value = ((short)(this->value & variable->getValue(ctx)->getShort(ctx)));
	return this;
}
IAlinousVariable* ShortVariable::bitAnd(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1134(), ctx));
}
IAlinousVariable* ShortVariable::bitAnd(ByteVariable* variable, ThreadContext* ctx)
{
	this->value = ((short)(this->value & variable->getValue(ctx)));
	return this;
}
IAlinousVariable* ShortVariable::bitAnd(CharVariable* variable, ThreadContext* ctx)
{
	this->value = ((short)(this->value & variable->getValue(ctx)));
	return this;
}
IAlinousVariable* ShortVariable::bitAnd(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1137(), ctx));
}
IAlinousVariable* ShortVariable::bitAnd(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1137(), ctx));
}
IAlinousVariable* ShortVariable::bitAnd(IntegerVariable* variable, ThreadContext* ctx)
{
	this->value = ((short)(this->value & variable->getValue(ctx)));
	return this;
}
IAlinousVariable* ShortVariable::bitAnd(LongVariable* variable, ThreadContext* ctx)
{
	this->value = ((short)(this->value & variable->getValue(ctx)));
	return this;
}
IAlinousVariable* ShortVariable::bitAnd(ShortVariable* variable, ThreadContext* ctx)
{
	this->value = ((short)(this->value & variable->getValue(ctx)));
	return this;
}
IAlinousVariable* ShortVariable::bitAnd(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* ShortVariable::bitExor(VariantValue* variable, ThreadContext* ctx)
{
	this->value = ((short)(this->value ^ variable->getShort(ctx)));
	return this;
}
IAlinousVariable* ShortVariable::bitExor(DomVariable* variable, ThreadContext* ctx)
{
	this->value = ((short)(this->value ^ variable->getValue(ctx)->getShort(ctx)));
	return this;
}
IAlinousVariable* ShortVariable::bitExor(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1134(), ctx));
}
IAlinousVariable* ShortVariable::bitExor(ByteVariable* variable, ThreadContext* ctx)
{
	this->value = ((short)(this->value ^ variable->getValue(ctx)));
	return this;
}
IAlinousVariable* ShortVariable::bitExor(CharVariable* variable, ThreadContext* ctx)
{
	this->value = ((short)(this->value ^ variable->getValue(ctx)));
	return this;
}
IAlinousVariable* ShortVariable::bitExor(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1137(), ctx));
}
IAlinousVariable* ShortVariable::bitExor(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1137(), ctx));
}
IAlinousVariable* ShortVariable::bitExor(IntegerVariable* variable, ThreadContext* ctx)
{
	this->value = ((short)(this->value ^ variable->getValue(ctx)));
	return this;
}
IAlinousVariable* ShortVariable::bitExor(LongVariable* variable, ThreadContext* ctx)
{
	this->value = ((short)(this->value ^ variable->getValue(ctx)));
	return this;
}
IAlinousVariable* ShortVariable::bitExor(ShortVariable* variable, ThreadContext* ctx)
{
	this->value = ((short)(this->value ^ variable->getValue(ctx)));
	return this;
}
IAlinousVariable* ShortVariable::bitExor(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* ShortVariable::add(BigDecimalVariable* variable, ThreadContext* ctx)
{
	this->value = ((short)(this->value + variable->getValue(ctx)->shortValue(ctx)));
	return this;
}
IAlinousVariable* ShortVariable::minus(BigDecimalVariable* variable, ThreadContext* ctx)
{
	this->value = ((short)(this->value - variable->getValue(ctx)->shortValue(ctx)));
	return this;
}
IAlinousVariable* ShortVariable::multiply(BigDecimalVariable* variable, ThreadContext* ctx)
{
	this->value = ((short)(this->value * variable->getValue(ctx)->shortValue(ctx)));
	return this;
}
IAlinousVariable* ShortVariable::div(BigDecimalVariable* variable, ThreadContext* ctx)
{
	this->value = ((short)(this->value / variable->getValue(ctx)->shortValue(ctx)));
	return this;
}
IAlinousVariable* ShortVariable::shiftLeft(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1138(), ctx));
}
IAlinousVariable* ShortVariable::shiftRight(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1138(), ctx));
}
IAlinousVariable* ShortVariable::modulo(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1138(), ctx));
}
IAlinousVariable* ShortVariable::bitOr(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1138(), ctx));
}
IAlinousVariable* ShortVariable::bitAnd(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1138(), ctx));
}
IAlinousVariable* ShortVariable::bitExor(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1138(), ctx));
}
IAlinousVariable* ShortVariable::substitute(BigDecimalVariable* variable, ThreadContext* ctx)
{
	this->value = variable->getValue(ctx)->shortValue(ctx);
	return this;
}
int ShortVariable::compareTo(BigDecimalVariable* variable, ThreadContext* ctx)
{
	return ((int)(this->value - variable->getValue(ctx)->shortValue(ctx)));
}
IAlinousVariable* ShortVariable::shiftRightUnsigned(VariantValue* variable, ThreadContext* ctx)
{
	this->value = ((short)(((unsigned short)this->value)>> variable->getInt(ctx)));
	return this;
}
IAlinousVariable* ShortVariable::shiftRightUnsigned(DomVariable* variable, ThreadContext* ctx)
{
	this->value = ((short)(((unsigned short)this->value)>> variable->getValue(ctx)->getInt(ctx)));
	return this;
}
IAlinousVariable* ShortVariable::shiftRightUnsigned(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1134(), ctx));
}
IAlinousVariable* ShortVariable::shiftRightUnsigned(ByteVariable* variable, ThreadContext* ctx)
{
	this->value = ((short)(((unsigned short)this->value)>> variable->getValue(ctx)));
	return this;
}
IAlinousVariable* ShortVariable::shiftRightUnsigned(CharVariable* variable, ThreadContext* ctx)
{
	this->value = ((short)(((unsigned short)this->value)>> variable->getValue(ctx)));
	return this;
}
IAlinousVariable* ShortVariable::shiftRightUnsigned(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1137(), ctx));
}
IAlinousVariable* ShortVariable::shiftRightUnsigned(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1137(), ctx));
}
IAlinousVariable* ShortVariable::shiftRightUnsigned(IntegerVariable* variable, ThreadContext* ctx)
{
	this->value = ((short)(((unsigned short)this->value)>> variable->getValue(ctx)));
	return this;
}
IAlinousVariable* ShortVariable::shiftRightUnsigned(LongVariable* variable, ThreadContext* ctx)
{
	this->value = ((short)(((unsigned short)this->value)>> variable->getValue(ctx)));
	return this;
}
IAlinousVariable* ShortVariable::shiftRightUnsigned(ShortVariable* variable, ThreadContext* ctx)
{
	this->value = ((short)(((unsigned short)this->value)>> variable->getValue(ctx)));
	return this;
}
IAlinousVariable* ShortVariable::shiftRightUnsigned(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* ShortVariable::shiftRightUnsigned(BigDecimalVariable* variable, ThreadContext* ctx)
{
	this->value = ((short)(((unsigned short)this->value)>> variable->getValue(ctx)->intValue(ctx)));
	return this;
}
BoolVariable* ShortVariable::toBoolVariable(ThreadContext* ctx)
{
	return (new(ctx) BoolVariable(isTrue(ctx), ctx));
}
ByteVariable* ShortVariable::toByteVariable(ThreadContext* ctx)
{
	return (new(ctx) ByteVariable(((char)this->value), ctx));
}
CharVariable* ShortVariable::toCharVariable(ThreadContext* ctx)
{
	return (new(ctx) CharVariable(((wchar_t)this->value), ctx));
}
ShortVariable* ShortVariable::toShortVariable(ThreadContext* ctx)
{
	return static_cast<ShortVariable*>(copy(ctx));
}
IntegerVariable* ShortVariable::toIntVariable(ThreadContext* ctx)
{
	return (new(ctx) IntegerVariable(this->value, ctx));
}
LongVariable* ShortVariable::toLongVariable(ThreadContext* ctx)
{
	return (new(ctx) LongVariable(this->value, ctx));
}
StringVariable* ShortVariable::toStringVariable(ThreadContext* ctx)
{
	return (new(ctx) StringVariable(getStringValue(ctx), ctx));
}
BigDecimalVariable* ShortVariable::toBigDecimalVariable(ThreadContext* ctx)
{
	BigDecimal* dec = (new(ctx) BigDecimal(this->value, ctx));
	return (new(ctx) BigDecimalVariable(dec, ctx));
}
long long ShortVariable::getLongValue(ThreadContext* ctx)
{
	return this->value;
}
FloatVariable* ShortVariable::toFloatVariable(ThreadContext* ctx)
{
	return (new(ctx) FloatVariable(this->value, ctx));
}
DoubleVariable* ShortVariable::toDoubleVariable(ThreadContext* ctx)
{
	return (new(ctx) DoubleVariable(this->value, ctx));
}
TimeVariable* ShortVariable::toTimeVariable(ThreadContext* ctx)
{
	TimeOnlyTimestamp* tm = (new(ctx) TimeOnlyTimestamp(this->value, ctx));
	return (new(ctx) TimeVariable(tm, ctx));
}
TimestampVariable* ShortVariable::toTimestampVariable(ThreadContext* ctx)
{
	Timestamp* tm = (new(ctx) Timestamp(this->value, ctx));
	return (new(ctx) TimestampVariable(tm, ctx));
}
IAlinousVariable* ShortVariable::add(TimeVariable* variable, ThreadContext* ctx)
{
	this->value = ((short)(this->value + variable->getValue(ctx)->getTime(ctx)));
	return this;
}
IAlinousVariable* ShortVariable::add(TimestampVariable* variable, ThreadContext* ctx)
{
	this->value = ((short)(this->value + variable->getValue(ctx)->getTime(ctx)));
	return this;
}
IAlinousVariable* ShortVariable::minus(TimeVariable* variable, ThreadContext* ctx)
{
	this->value = ((short)(this->value - variable->getValue(ctx)->getTime(ctx)));
	return this;
}
IAlinousVariable* ShortVariable::minus(TimestampVariable* variable, ThreadContext* ctx)
{
	this->value = ((short)(this->value - variable->getValue(ctx)->getTime(ctx)));
	return this;
}
IAlinousVariable* ShortVariable::multiply(TimeVariable* variable, ThreadContext* ctx)
{
	this->value = ((short)(this->value * variable->getValue(ctx)->getTime(ctx)));
	return this;
}
IAlinousVariable* ShortVariable::multiply(TimestampVariable* variable, ThreadContext* ctx)
{
	this->value = ((short)(this->value * variable->getValue(ctx)->getTime(ctx)));
	return this;
}
IAlinousVariable* ShortVariable::div(TimeVariable* variable, ThreadContext* ctx)
{
	this->value = ((short)(this->value / variable->getValue(ctx)->getTime(ctx)));
	return this;
}
IAlinousVariable* ShortVariable::div(TimestampVariable* variable, ThreadContext* ctx)
{
	this->value = ((short)(this->value / variable->getValue(ctx)->getTime(ctx)));
	return this;
}
IAlinousVariable* ShortVariable::shiftLeft(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1139(), ctx));
}
IAlinousVariable* ShortVariable::shiftLeft(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1139(), ctx));
}
IAlinousVariable* ShortVariable::shiftRight(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1139(), ctx));
}
IAlinousVariable* ShortVariable::shiftRight(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1139(), ctx));
}
IAlinousVariable* ShortVariable::shiftRightUnsigned(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1139(), ctx));
}
IAlinousVariable* ShortVariable::shiftRightUnsigned(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1139(), ctx));
}
IAlinousVariable* ShortVariable::modulo(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1139(), ctx));
}
IAlinousVariable* ShortVariable::modulo(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1139(), ctx));
}
IAlinousVariable* ShortVariable::bitOr(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1139(), ctx));
}
IAlinousVariable* ShortVariable::bitOr(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1139(), ctx));
}
IAlinousVariable* ShortVariable::bitAnd(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1139(), ctx));
}
IAlinousVariable* ShortVariable::bitAnd(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1139(), ctx));
}
IAlinousVariable* ShortVariable::bitExor(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1139(), ctx));
}
IAlinousVariable* ShortVariable::bitExor(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1139(), ctx));
}
IAlinousVariable* ShortVariable::substitute(TimeVariable* variable, ThreadContext* ctx)
{
	this->value = ((short)variable->getValue(ctx)->getTime(ctx));
	return this;
}
IAlinousVariable* ShortVariable::substitute(TimestampVariable* variable, ThreadContext* ctx)
{
	this->value = ((short)variable->getValue(ctx)->getTime(ctx));
	return this;
}
int ShortVariable::compareTo(TimeVariable* variable, ThreadContext* ctx)
{
	return ((int)(this->value - variable->getValue(ctx)->getTime(ctx)));
}
int ShortVariable::compareTo(TimestampVariable* variable, ThreadContext* ctx)
{
	return ((int)(this->value - variable->getValue(ctx)->getTime(ctx)));
}
IAlinousVariable* ShortVariable::substitute(TypedVariableArray* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1129(), ctx));
}
void ShortVariable::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	this->value = buff->getShort(ctx);
}
void ShortVariable::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putInt(ICommandData::__ShortVariable, ctx);
	buff->putShort(this->value, ctx);
}
ShortVariable* ShortVariable::fromDebugXml(DomNode* node, ThreadContext* ctx) throw() 
{
	IVariableValue* attrVal = node->getAttributeValue(VAL_TYPE, ctx);
	if(attrVal == nullptr)
	{
		return nullptr;
	}
	String* str = attrVal->toString(ctx);
	short value = 0;
	{
		try
		{
			value = Short::parseShort(str, ctx);
		}
		catch(Throwable* e)
		{
			e->printStackTrace(ctx);
			return nullptr;
		}
	}
	return (new(ctx) ShortVariable(value, ctx));
}
int ShortVariable::ValueCompare::operator() (VariantValue* _this, VariantValue* variable, ThreadContext* ctx) const throw()
{
	return _this->compareTo(variable, ctx);
}
}}}}

