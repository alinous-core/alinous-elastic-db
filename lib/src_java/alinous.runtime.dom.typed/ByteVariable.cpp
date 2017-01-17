#include "includes.h"


namespace alinous {namespace runtime {namespace dom {namespace typed {





String* ByteVariable::VAL_TYPE = ConstStr::getCNST_STR_1144();
bool ByteVariable::__init_done = __init_static_variables();
bool ByteVariable::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ByteVariable", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ByteVariable::ByteVariable(char value, ThreadContext* ctx) throw()  : IObject(ctx), AbstractTypedVariable(ctx), value(0)
{
	this->value = value;
}
void ByteVariable::__construct_impl(char value, ThreadContext* ctx) throw() 
{
	this->value = value;
}
 ByteVariable::~ByteVariable() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ByteVariable::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ByteVariable", L"~ByteVariable");
	if(!prepare){
		return;
	}
	AbstractTypedVariable::__releaseRegerences(true, ctx);
}
void ByteVariable::outDebugXml(DomNode* parentNode, String* name, ThreadContext* ctx) throw() 
{
	DomNode* node = (new(ctx) DomNode(VAL_TYPE, ctx));
	parentNode->addChild(node, ctx);
	if(name != nullptr)
	{
		Attribute* nameattr = (new(ctx) Attribute(IAlinousVariable::ATTR_NAME, name, node, ctx));
		node->addAttribute(nameattr, ctx);
	}
	Attribute* attr = (new(ctx) Attribute(AbstractTypedVariable::VALUE, Byte::toString(this->value, ctx), node, ctx));
	parentNode->addAttribute(attr, ctx);
}
int ByteVariable::getVariableClass(ThreadContext* ctx) throw() 
{
	return IAlinousVariable::CLASS_TYPED;
}
int ByteVariable::getTypedType(ThreadContext* ctx) throw() 
{
	return ITypedVariable::TYPE_BYTE;
}
VariantValue* ByteVariable::toVariantValue(ThreadContext* ctx)
{
	return (new(ctx) VariantValue(this->value, ctx));
}
int ByteVariable::getIntValue(ThreadContext* ctx)
{
	return this->value;
}
String* ByteVariable::getStringValue(ThreadContext* ctx)
{
	return Byte::toString(this->value, ctx);
}
char ByteVariable::getValue(ThreadContext* ctx) throw() 
{
	return value;
}
void ByteVariable::setValue(char value, ThreadContext* ctx) throw() 
{
	this->value = value;
}
IAlinousVariable* ByteVariable::copy(ThreadContext* ctx)
{
	return (new(ctx) ByteVariable(this->value, ctx));
}
IDomVariable* ByteVariable::toDomVariable(ThreadContext* ctx) throw() 
{
	DomVariable* ret = (new(ctx) DomVariable(ctx));
	ret->setValue((new(ctx) VariantValue(this->value, ctx)), ctx);
	return ret;
}
IAlinousVariable* ByteVariable::add(VariantValue* variable, ThreadContext* ctx)
{
	return variable->add(this, ctx)->copy(ctx);
}
IAlinousVariable* ByteVariable::add(DomVariable* variable, ThreadContext* ctx)
{
	return variable->getValue(ctx)->add(this, ctx)->copy(ctx);
}
IAlinousVariable* ByteVariable::add(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1127(), ctx));
}
IAlinousVariable* ByteVariable::add(ByteVariable* variable, ThreadContext* ctx)
{
	this->value += variable->getValue(ctx);
	return this;
}
IAlinousVariable* ByteVariable::add(CharVariable* variable, ThreadContext* ctx)
{
	wchar_t ch = ((wchar_t)(this->value + variable->getValue(ctx)));
	return (new(ctx) CharVariable(ch, ctx));
}
IAlinousVariable* ByteVariable::add(DoubleVariable* variable, ThreadContext* ctx)
{
	double res = this->value + variable->getValue(ctx);
	return (new(ctx) DoubleVariable(res, ctx));
}
IAlinousVariable* ByteVariable::add(FloatVariable* variable, ThreadContext* ctx)
{
	float res = this->value + variable->getValue(ctx);
	return (new(ctx) FloatVariable(res, ctx));
}
IAlinousVariable* ByteVariable::add(IntegerVariable* variable, ThreadContext* ctx)
{
	int res = this->value + variable->getValue(ctx);
	return (new(ctx) IntegerVariable(res, ctx));
}
IAlinousVariable* ByteVariable::add(ShortVariable* variable, ThreadContext* ctx)
{
	short res = ((short)(this->value + variable->getValue(ctx)));
	return (new(ctx) ShortVariable(res, ctx));
}
IAlinousVariable* ByteVariable::add(StringVariable* variable, ThreadContext* ctx)
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	buff->append(Byte::toString(value, ctx), ctx);
	buff->append(variable->getValue(ctx), ctx);
	return (new(ctx) StringVariable(buff->toString(ctx), ctx));
}
IAlinousVariable* ByteVariable::minus(DomVariable* variable, ThreadContext* ctx)
{
	return (new(ctx) VariantValue(this->value, ctx))->minus(variable, ctx);
}
IAlinousVariable* ByteVariable::minus(VariantValue* variable, ThreadContext* ctx)
{
	return (new(ctx) VariantValue(this->value, ctx))->minus(variable, ctx);
}
IAlinousVariable* ByteVariable::minus(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1127(), ctx));
}
IAlinousVariable* ByteVariable::minus(ByteVariable* variable, ThreadContext* ctx)
{
	this->value -= variable->getValue(ctx);
	return this;
}
IAlinousVariable* ByteVariable::minus(CharVariable* variable, ThreadContext* ctx)
{
	wchar_t ch = ((wchar_t)(this->value - variable->getValue(ctx)));
	return (new(ctx) CharVariable(ch, ctx));
}
IAlinousVariable* ByteVariable::minus(DoubleVariable* variable, ThreadContext* ctx)
{
	double res = this->value - variable->getValue(ctx);
	return (new(ctx) DoubleVariable(res, ctx));
}
IAlinousVariable* ByteVariable::minus(FloatVariable* variable, ThreadContext* ctx)
{
	float res = this->value - variable->getValue(ctx);
	return (new(ctx) FloatVariable(res, ctx));
}
IAlinousVariable* ByteVariable::minus(IntegerVariable* variable, ThreadContext* ctx)
{
	int res = this->value - variable->getValue(ctx);
	return (new(ctx) IntegerVariable(res, ctx));
}
IAlinousVariable* ByteVariable::minus(ShortVariable* variable, ThreadContext* ctx)
{
	short res = ((short)(this->value - variable->getValue(ctx)));
	return (new(ctx) ShortVariable(res, ctx));
}
IAlinousVariable* ByteVariable::minus(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1128(), ctx));
}
IAlinousVariable* ByteVariable::multiply(DomVariable* variable, ThreadContext* ctx)
{
	return variable->getValue(ctx)->multiply(this, ctx)->copy(ctx);
}
IAlinousVariable* ByteVariable::multiply(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1127(), ctx));
}
IAlinousVariable* ByteVariable::multiply(ByteVariable* variable, ThreadContext* ctx)
{
	this->value = ((char)(this->value * variable->getValue(ctx)));
	return this;
}
IAlinousVariable* ByteVariable::multiply(CharVariable* variable, ThreadContext* ctx)
{
	wchar_t ch = ((wchar_t)(this->value * variable->getValue(ctx)));
	return (new(ctx) CharVariable(ch, ctx));
}
IAlinousVariable* ByteVariable::multiply(DoubleVariable* variable, ThreadContext* ctx)
{
	double res = this->value * variable->getValue(ctx);
	return (new(ctx) DoubleVariable(res, ctx));
}
IAlinousVariable* ByteVariable::multiply(FloatVariable* variable, ThreadContext* ctx)
{
	float res = this->value * variable->getValue(ctx);
	return (new(ctx) FloatVariable(res, ctx));
}
IAlinousVariable* ByteVariable::multiply(IntegerVariable* variable, ThreadContext* ctx)
{
	int res = this->value * variable->getValue(ctx);
	return (new(ctx) IntegerVariable(res, ctx));
}
IAlinousVariable* ByteVariable::multiply(ShortVariable* variable, ThreadContext* ctx)
{
	short res = ((short)(this->value * variable->getValue(ctx)));
	return (new(ctx) ShortVariable(res, ctx));
}
IAlinousVariable* ByteVariable::multiply(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1128(), ctx));
}
IAlinousVariable* ByteVariable::div(DomVariable* variable, ThreadContext* ctx)
{
	return (new(ctx) VariantValue(this->value, ctx))->div(variable, ctx);
}
IAlinousVariable* ByteVariable::div(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1127(), ctx));
}
IAlinousVariable* ByteVariable::div(ByteVariable* variable, ThreadContext* ctx)
{
	this->value = ((char)(this->value / variable->getValue(ctx)));
	return this;
}
IAlinousVariable* ByteVariable::div(CharVariable* variable, ThreadContext* ctx)
{
	wchar_t ch = ((wchar_t)(this->value / variable->getValue(ctx)));
	return (new(ctx) CharVariable(ch, ctx));
}
IAlinousVariable* ByteVariable::div(DoubleVariable* variable, ThreadContext* ctx)
{
	double res = this->value / variable->getValue(ctx);
	return (new(ctx) DoubleVariable(res, ctx));
}
IAlinousVariable* ByteVariable::div(FloatVariable* variable, ThreadContext* ctx)
{
	float res = this->value / variable->getValue(ctx);
	return (new(ctx) FloatVariable(res, ctx));
}
IAlinousVariable* ByteVariable::div(IntegerVariable* variable, ThreadContext* ctx)
{
	int res = this->value / variable->getValue(ctx);
	return (new(ctx) IntegerVariable(res, ctx));
}
IAlinousVariable* ByteVariable::div(ShortVariable* variable, ThreadContext* ctx)
{
	short res = ((short)(this->value / variable->getValue(ctx)));
	return (new(ctx) ShortVariable(res, ctx));
}
IAlinousVariable* ByteVariable::div(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1128(), ctx));
}
IAlinousVariable* ByteVariable::bitReverse(ThreadContext* ctx)
{
	this->value = ((char)~this->value);
	return this;
}
IAlinousVariable* ByteVariable::multiply(VariantValue* variable, ThreadContext* ctx)
{
	return variable->multiply(this, ctx)->copy(ctx);
}
IAlinousVariable* ByteVariable::div(VariantValue* variable, ThreadContext* ctx)
{
	return (new(ctx) VariantValue(this->value, ctx))->div(variable, ctx);
}
IAlinousVariable* ByteVariable::add(LongVariable* variable, ThreadContext* ctx)
{
	long long res = this->value + variable->getValue(ctx);
	return (new(ctx) LongVariable(res, ctx));
}
IAlinousVariable* ByteVariable::minus(LongVariable* variable, ThreadContext* ctx)
{
	long long res = this->value - variable->getValue(ctx);
	return (new(ctx) LongVariable(res, ctx));
}
IAlinousVariable* ByteVariable::multiply(LongVariable* variable, ThreadContext* ctx)
{
	long long res = this->value * variable->getValue(ctx);
	return (new(ctx) LongVariable(res, ctx));
}
IAlinousVariable* ByteVariable::div(LongVariable* variable, ThreadContext* ctx)
{
	long long res = this->value / variable->getValue(ctx);
	return (new(ctx) LongVariable(res, ctx));
}
bool ByteVariable::isNull(ThreadContext* ctx) throw() 
{
	return false;
}
bool ByteVariable::isArray(ThreadContext* ctx) throw() 
{
	return false;
}
IAlinousVariable* ByteVariable::shiftLeft(VariantValue* variable, ThreadContext* ctx)
{
	this->value = ((char)(this->value << variable->getInt(ctx)));
	return this;
}
IAlinousVariable* ByteVariable::shiftLeft(DomVariable* variable, ThreadContext* ctx)
{
	this->value = ((char)(this->value << variable->getValue(ctx)->getInt(ctx)));
	return this;
}
IAlinousVariable* ByteVariable::shiftLeft(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1127(), ctx));
}
IAlinousVariable* ByteVariable::shiftLeft(ByteVariable* variable, ThreadContext* ctx)
{
	this->value = ((char)(this->value << variable->getValue(ctx)));
	return this;
}
IAlinousVariable* ByteVariable::shiftLeft(CharVariable* variable, ThreadContext* ctx)
{
	this->value = ((char)(this->value << variable->getValue(ctx)));
	return this;
}
IAlinousVariable* ByteVariable::shiftLeft(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1129(), ctx));
}
IAlinousVariable* ByteVariable::shiftLeft(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1129(), ctx));
}
IAlinousVariable* ByteVariable::shiftLeft(IntegerVariable* variable, ThreadContext* ctx)
{
	this->value = ((char)(this->value << variable->getValue(ctx)));
	return this;
}
IAlinousVariable* ByteVariable::shiftLeft(LongVariable* variable, ThreadContext* ctx)
{
	this->value = ((char)(this->value << variable->getValue(ctx)));
	return this;
}
IAlinousVariable* ByteVariable::shiftLeft(ShortVariable* variable, ThreadContext* ctx)
{
	this->value = ((char)(this->value << variable->getValue(ctx)));
	return this;
}
IAlinousVariable* ByteVariable::shiftLeft(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1128(), ctx));
}
IAlinousVariable* ByteVariable::shiftRight(VariantValue* variable, ThreadContext* ctx)
{
	this->value = ((char)(this->value >> variable->getInt(ctx)));
	return this;
}
IAlinousVariable* ByteVariable::shiftRight(DomVariable* variable, ThreadContext* ctx)
{
	this->value = ((char)(this->value >> variable->getValue(ctx)->getInt(ctx)));
	return this;
}
IAlinousVariable* ByteVariable::shiftRight(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1127(), ctx));
}
IAlinousVariable* ByteVariable::shiftRight(ByteVariable* variable, ThreadContext* ctx)
{
	this->value = ((char)(this->value >> variable->getValue(ctx)));
	return this;
}
IAlinousVariable* ByteVariable::shiftRight(CharVariable* variable, ThreadContext* ctx)
{
	this->value = ((char)(this->value >> variable->getValue(ctx)));
	return this;
}
IAlinousVariable* ByteVariable::shiftRight(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1129(), ctx));
}
IAlinousVariable* ByteVariable::shiftRight(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1129(), ctx));
}
IAlinousVariable* ByteVariable::shiftRight(IntegerVariable* variable, ThreadContext* ctx)
{
	this->value = ((char)(this->value >> variable->getValue(ctx)));
	return this;
}
IAlinousVariable* ByteVariable::shiftRight(LongVariable* variable, ThreadContext* ctx)
{
	this->value = ((char)(this->value >> variable->getValue(ctx)));
	return this;
}
IAlinousVariable* ByteVariable::shiftRight(ShortVariable* variable, ThreadContext* ctx)
{
	this->value = ((char)(this->value >> variable->getValue(ctx)));
	return this;
}
IAlinousVariable* ByteVariable::shiftRight(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1128(), ctx));
}
IAlinousVariable* ByteVariable::modulo(VariantValue* variable, ThreadContext* ctx)
{
	this->value = ((char)(this->value % variable->getInt(ctx)));
	return this;
}
IAlinousVariable* ByteVariable::modulo(DomVariable* variable, ThreadContext* ctx)
{
	this->value = ((char)(this->value % variable->getValue(ctx)->getInt(ctx)));
	return this;
}
IAlinousVariable* ByteVariable::modulo(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1127(), ctx));
}
IAlinousVariable* ByteVariable::modulo(ByteVariable* variable, ThreadContext* ctx)
{
	this->value = ((char)(this->value % variable->getValue(ctx)));
	return this;
}
IAlinousVariable* ByteVariable::modulo(CharVariable* variable, ThreadContext* ctx)
{
	this->value = ((char)(this->value % variable->getValue(ctx)));
	return this;
}
IAlinousVariable* ByteVariable::modulo(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1130(), ctx));
}
IAlinousVariable* ByteVariable::modulo(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1130(), ctx));
}
IAlinousVariable* ByteVariable::modulo(IntegerVariable* variable, ThreadContext* ctx)
{
	this->value = ((char)(this->value % variable->getValue(ctx)));
	return this;
}
IAlinousVariable* ByteVariable::modulo(LongVariable* variable, ThreadContext* ctx)
{
	this->value = ((char)(this->value % variable->getValue(ctx)));
	return this;
}
IAlinousVariable* ByteVariable::modulo(ShortVariable* variable, ThreadContext* ctx)
{
	this->value = ((char)(this->value % variable->getValue(ctx)));
	return this;
}
IAlinousVariable* ByteVariable::modulo(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1128(), ctx));
}
IAlinousVariable* ByteVariable::substitute(VariantValue* variable, ThreadContext* ctx)
{
	this->value = variable->getByte(ctx);
	return this;
}
IAlinousVariable* ByteVariable::substitute(DomVariable* variable, ThreadContext* ctx)
{
	this->value = variable->getValue(ctx)->getByte(ctx);
	return this;
}
IAlinousVariable* ByteVariable::substitute(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1127(), ctx));
}
IAlinousVariable* ByteVariable::substitute(ByteVariable* variable, ThreadContext* ctx)
{
	this->value = variable->getValue(ctx);
	return this;
}
IAlinousVariable* ByteVariable::substitute(CharVariable* variable, ThreadContext* ctx)
{
	this->value = ((char)variable->getValue(ctx));
	return this;
}
IAlinousVariable* ByteVariable::substitute(DoubleVariable* variable, ThreadContext* ctx)
{
	this->value = ((char)variable->getValue(ctx));
	return this;
}
IAlinousVariable* ByteVariable::substitute(FloatVariable* variable, ThreadContext* ctx)
{
	this->value = ((char)variable->getValue(ctx));
	return this;
}
IAlinousVariable* ByteVariable::substitute(IntegerVariable* variable, ThreadContext* ctx)
{
	this->value = ((char)variable->getValue(ctx));
	return this;
}
IAlinousVariable* ByteVariable::substitute(LongVariable* variable, ThreadContext* ctx)
{
	this->value = ((char)variable->getValue(ctx));
	return this;
}
IAlinousVariable* ByteVariable::substitute(ShortVariable* variable, ThreadContext* ctx)
{
	this->value = ((char)variable->getValue(ctx));
	return this;
}
IAlinousVariable* ByteVariable::substitute(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1128(), ctx));
}
int ByteVariable::compareTo(VariantValue* variable, ThreadContext* ctx)
{
	return ((int)(this->value - variable->getLong(ctx)));
}
int ByteVariable::compareTo(DomVariable* variable, ThreadContext* ctx)
{
	return ((int)(this->value - variable->getValue(ctx)->getLong(ctx)));
}
int ByteVariable::compareTo(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1127(), ctx));
}
int ByteVariable::compareTo(ByteVariable* variable, ThreadContext* ctx)
{
	return ((int)(this->value - variable->getValue(ctx)));
}
int ByteVariable::compareTo(CharVariable* variable, ThreadContext* ctx)
{
	return ((int)(this->value - variable->getValue(ctx)));
}
int ByteVariable::compareTo(DoubleVariable* variable, ThreadContext* ctx)
{
	return ((int)(this->value - variable->getValue(ctx)));
}
int ByteVariable::compareTo(FloatVariable* variable, ThreadContext* ctx)
{
	return ((int)(this->value - variable->getValue(ctx)));
}
int ByteVariable::compareTo(IntegerVariable* variable, ThreadContext* ctx)
{
	return ((int)(this->value - variable->getValue(ctx)));
}
int ByteVariable::compareTo(LongVariable* variable, ThreadContext* ctx)
{
	return ((int)(this->value - variable->getValue(ctx)));
}
int ByteVariable::compareTo(ShortVariable* variable, ThreadContext* ctx)
{
	return ((int)(this->value - variable->getValue(ctx)));
}
int ByteVariable::compareTo(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1128(), ctx));
}
bool ByteVariable::isTrue(ThreadContext* ctx)
{
	return this->value > (char)0;
}
IAlinousVariable* ByteVariable::bitOr(VariantValue* variable, ThreadContext* ctx)
{
	this->value = ((char)(this->value | variable->getByte(ctx)));
	return this;
}
IAlinousVariable* ByteVariable::bitOr(DomVariable* variable, ThreadContext* ctx)
{
	this->value = ((char)(this->value | variable->getValue(ctx)->getByte(ctx)));
	return this;
}
IAlinousVariable* ByteVariable::bitOr(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1127(), ctx));
}
IAlinousVariable* ByteVariable::bitOr(ByteVariable* variable, ThreadContext* ctx)
{
	this->value = ((char)(this->value | variable->getValue(ctx)));
	return this;
}
IAlinousVariable* ByteVariable::bitOr(CharVariable* variable, ThreadContext* ctx)
{
	this->value = ((char)(this->value | variable->getValue(ctx)));
	return this;
}
IAlinousVariable* ByteVariable::bitOr(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1130(), ctx));
}
IAlinousVariable* ByteVariable::bitOr(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1130(), ctx));
}
IAlinousVariable* ByteVariable::bitOr(IntegerVariable* variable, ThreadContext* ctx)
{
	this->value = ((char)(this->value | variable->getValue(ctx)));
	return this;
}
IAlinousVariable* ByteVariable::bitOr(LongVariable* variable, ThreadContext* ctx)
{
	this->value = ((char)(this->value | variable->getValue(ctx)));
	return this;
}
IAlinousVariable* ByteVariable::bitOr(ShortVariable* variable, ThreadContext* ctx)
{
	this->value = ((char)(this->value | variable->getValue(ctx)));
	return this;
}
IAlinousVariable* ByteVariable::bitOr(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1128(), ctx));
}
IAlinousVariable* ByteVariable::bitAnd(VariantValue* variable, ThreadContext* ctx)
{
	this->value = ((char)(this->value & variable->getByte(ctx)));
	return this;
}
IAlinousVariable* ByteVariable::bitAnd(DomVariable* variable, ThreadContext* ctx)
{
	this->value = ((char)(this->value & variable->getValue(ctx)->getByte(ctx)));
	return this;
}
IAlinousVariable* ByteVariable::bitAnd(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1127(), ctx));
}
IAlinousVariable* ByteVariable::bitAnd(ByteVariable* variable, ThreadContext* ctx)
{
	this->value = ((char)(this->value & variable->getValue(ctx)));
	return this;
}
IAlinousVariable* ByteVariable::bitAnd(CharVariable* variable, ThreadContext* ctx)
{
	this->value = ((char)(this->value & variable->getValue(ctx)));
	return this;
}
IAlinousVariable* ByteVariable::bitAnd(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1130(), ctx));
}
IAlinousVariable* ByteVariable::bitAnd(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1130(), ctx));
}
IAlinousVariable* ByteVariable::bitAnd(IntegerVariable* variable, ThreadContext* ctx)
{
	this->value = ((char)(this->value & variable->getValue(ctx)));
	return this;
}
IAlinousVariable* ByteVariable::bitAnd(LongVariable* variable, ThreadContext* ctx)
{
	this->value = ((char)(this->value & variable->getValue(ctx)));
	return this;
}
IAlinousVariable* ByteVariable::bitAnd(ShortVariable* variable, ThreadContext* ctx)
{
	this->value = ((char)(this->value & variable->getValue(ctx)));
	return this;
}
IAlinousVariable* ByteVariable::bitAnd(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1128(), ctx));
}
IAlinousVariable* ByteVariable::bitExor(VariantValue* variable, ThreadContext* ctx)
{
	this->value = ((char)(this->value ^ variable->getByte(ctx)));
	return this;
}
IAlinousVariable* ByteVariable::bitExor(DomVariable* variable, ThreadContext* ctx)
{
	this->value = ((char)(this->value ^ variable->getValue(ctx)->getByte(ctx)));
	return this;
}
IAlinousVariable* ByteVariable::bitExor(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1127(), ctx));
}
IAlinousVariable* ByteVariable::bitExor(ByteVariable* variable, ThreadContext* ctx)
{
	this->value = ((char)(this->value ^ variable->getValue(ctx)));
	return this;
}
IAlinousVariable* ByteVariable::bitExor(CharVariable* variable, ThreadContext* ctx)
{
	this->value = ((char)(this->value ^ variable->getValue(ctx)));
	return this;
}
IAlinousVariable* ByteVariable::bitExor(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1130(), ctx));
}
IAlinousVariable* ByteVariable::bitExor(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1130(), ctx));
}
IAlinousVariable* ByteVariable::bitExor(IntegerVariable* variable, ThreadContext* ctx)
{
	this->value = ((char)(this->value ^ variable->getValue(ctx)));
	return this;
}
IAlinousVariable* ByteVariable::bitExor(LongVariable* variable, ThreadContext* ctx)
{
	this->value = ((char)(this->value ^ variable->getValue(ctx)));
	return this;
}
IAlinousVariable* ByteVariable::bitExor(ShortVariable* variable, ThreadContext* ctx)
{
	this->value = ((char)(this->value ^ variable->getValue(ctx)));
	return this;
}
IAlinousVariable* ByteVariable::bitExor(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1128(), ctx));
}
IAlinousVariable* ByteVariable::add(BigDecimalVariable* variable, ThreadContext* ctx)
{
	this->value = ((char)(this->value + variable->getValue(ctx)->byteValue(ctx)));
	return this;
}
IAlinousVariable* ByteVariable::minus(BigDecimalVariable* variable, ThreadContext* ctx)
{
	this->value = ((char)(this->value - variable->getValue(ctx)->byteValue(ctx)));
	return this;
}
IAlinousVariable* ByteVariable::multiply(BigDecimalVariable* variable, ThreadContext* ctx)
{
	this->value = ((char)(this->value * variable->getValue(ctx)->byteValue(ctx)));
	return this;
}
IAlinousVariable* ByteVariable::div(BigDecimalVariable* variable, ThreadContext* ctx)
{
	this->value = ((char)(this->value / variable->getValue(ctx)->byteValue(ctx)));
	return this;
}
IAlinousVariable* ByteVariable::shiftLeft(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1131(), ctx));
}
IAlinousVariable* ByteVariable::shiftRight(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1131(), ctx));
}
IAlinousVariable* ByteVariable::modulo(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1131(), ctx));
}
IAlinousVariable* ByteVariable::bitOr(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1131(), ctx));
}
IAlinousVariable* ByteVariable::bitAnd(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1131(), ctx));
}
IAlinousVariable* ByteVariable::bitExor(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1131(), ctx));
}
IAlinousVariable* ByteVariable::substitute(BigDecimalVariable* variable, ThreadContext* ctx)
{
	this->value = variable->getValue(ctx)->byteValue(ctx);
	return this;
}
int ByteVariable::compareTo(BigDecimalVariable* variable, ThreadContext* ctx)
{
	return ((int)(this->value - variable->getValue(ctx)->byteValue(ctx)));
}
IAlinousVariable* ByteVariable::shiftRightUnsigned(VariantValue* variable, ThreadContext* ctx)
{
	this->value = ((char)(((unsigned char)this->value)>> variable->getInt(ctx)));
	return this;
}
IAlinousVariable* ByteVariable::shiftRightUnsigned(DomVariable* variable, ThreadContext* ctx)
{
	this->value = ((char)(((unsigned char)this->value)>> variable->getValue(ctx)->getInt(ctx)));
	return this;
}
IAlinousVariable* ByteVariable::shiftRightUnsigned(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1127(), ctx));
}
IAlinousVariable* ByteVariable::shiftRightUnsigned(ByteVariable* variable, ThreadContext* ctx)
{
	this->value = ((char)(((unsigned char)this->value)>> variable->getValue(ctx)));
	return this;
}
IAlinousVariable* ByteVariable::shiftRightUnsigned(CharVariable* variable, ThreadContext* ctx)
{
	this->value = ((char)(((unsigned char)this->value)>> variable->getValue(ctx)));
	return this;
}
IAlinousVariable* ByteVariable::shiftRightUnsigned(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1130(), ctx));
}
IAlinousVariable* ByteVariable::shiftRightUnsigned(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1130(), ctx));
}
IAlinousVariable* ByteVariable::shiftRightUnsigned(IntegerVariable* variable, ThreadContext* ctx)
{
	this->value = ((char)(((unsigned char)this->value)>> variable->getValue(ctx)));
	return this;
}
IAlinousVariable* ByteVariable::shiftRightUnsigned(LongVariable* variable, ThreadContext* ctx)
{
	this->value = ((char)(((unsigned char)this->value)>> variable->getValue(ctx)));
	return this;
}
IAlinousVariable* ByteVariable::shiftRightUnsigned(ShortVariable* variable, ThreadContext* ctx)
{
	this->value = ((char)(((unsigned char)this->value)>> variable->getValue(ctx)));
	return this;
}
IAlinousVariable* ByteVariable::shiftRightUnsigned(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1128(), ctx));
}
IAlinousVariable* ByteVariable::shiftRightUnsigned(BigDecimalVariable* variable, ThreadContext* ctx)
{
	this->value = ((char)(((unsigned char)this->value)>> variable->getValue(ctx)->intValue(ctx)));
	return this;
}
BoolVariable* ByteVariable::toBoolVariable(ThreadContext* ctx)
{
	return (new(ctx) BoolVariable(isTrue(ctx), ctx));
}
ByteVariable* ByteVariable::toByteVariable(ThreadContext* ctx)
{
	return static_cast<ByteVariable*>(copy(ctx));
}
CharVariable* ByteVariable::toCharVariable(ThreadContext* ctx)
{
	return (new(ctx) CharVariable(((wchar_t)this->value), ctx));
}
ShortVariable* ByteVariable::toShortVariable(ThreadContext* ctx)
{
	return (new(ctx) ShortVariable(((short)this->value), ctx));
}
IntegerVariable* ByteVariable::toIntVariable(ThreadContext* ctx)
{
	return (new(ctx) IntegerVariable(this->value, ctx));
}
LongVariable* ByteVariable::toLongVariable(ThreadContext* ctx)
{
	return (new(ctx) LongVariable(this->value, ctx));
}
StringVariable* ByteVariable::toStringVariable(ThreadContext* ctx)
{
	return (new(ctx) StringVariable(getStringValue(ctx), ctx));
}
BigDecimalVariable* ByteVariable::toBigDecimalVariable(ThreadContext* ctx)
{
	BigDecimal* dec = (new(ctx) BigDecimal(this->value, ctx));
	return (new(ctx) BigDecimalVariable(dec, ctx));
}
long long ByteVariable::getLongValue(ThreadContext* ctx)
{
	return this->value;
}
FloatVariable* ByteVariable::toFloatVariable(ThreadContext* ctx)
{
	return (new(ctx) FloatVariable(this->value, ctx));
}
DoubleVariable* ByteVariable::toDoubleVariable(ThreadContext* ctx)
{
	return (new(ctx) DoubleVariable(this->value, ctx));
}
TimeVariable* ByteVariable::toTimeVariable(ThreadContext* ctx)
{
	TimeOnlyTimestamp* tm = (new(ctx) TimeOnlyTimestamp(this->value, ctx));
	return (new(ctx) TimeVariable(tm, ctx));
}
TimestampVariable* ByteVariable::toTimestampVariable(ThreadContext* ctx)
{
	Timestamp* tm = (new(ctx) Timestamp(this->value, ctx));
	return (new(ctx) TimestampVariable(tm, ctx));
}
IAlinousVariable* ByteVariable::add(TimeVariable* variable, ThreadContext* ctx)
{
	this->value = ((char)(this->value + variable->getValue(ctx)->getTime(ctx)));
	return this;
}
IAlinousVariable* ByteVariable::add(TimestampVariable* variable, ThreadContext* ctx)
{
	this->value = ((char)(this->value + variable->getValue(ctx)->getTime(ctx)));
	return this;
}
IAlinousVariable* ByteVariable::minus(TimeVariable* variable, ThreadContext* ctx)
{
	this->value = ((char)(this->value - variable->getValue(ctx)->getTime(ctx)));
	return this;
}
IAlinousVariable* ByteVariable::minus(TimestampVariable* variable, ThreadContext* ctx)
{
	this->value = ((char)(this->value - variable->getValue(ctx)->getTime(ctx)));
	return this;
}
IAlinousVariable* ByteVariable::multiply(TimeVariable* variable, ThreadContext* ctx)
{
	this->value = ((char)(this->value * variable->getValue(ctx)->getTime(ctx)));
	return this;
}
IAlinousVariable* ByteVariable::multiply(TimestampVariable* variable, ThreadContext* ctx)
{
	this->value = ((char)(this->value * variable->getValue(ctx)->getTime(ctx)));
	return this;
}
IAlinousVariable* ByteVariable::div(TimeVariable* variable, ThreadContext* ctx)
{
	this->value = ((char)(this->value / variable->getValue(ctx)->getTime(ctx)));
	return this;
}
IAlinousVariable* ByteVariable::div(TimestampVariable* variable, ThreadContext* ctx)
{
	this->value = ((char)(this->value / variable->getValue(ctx)->getTime(ctx)));
	return this;
}
IAlinousVariable* ByteVariable::shiftLeft(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1132(), ctx));
}
IAlinousVariable* ByteVariable::shiftLeft(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1132(), ctx));
}
IAlinousVariable* ByteVariable::shiftRight(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1132(), ctx));
}
IAlinousVariable* ByteVariable::shiftRight(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1132(), ctx));
}
IAlinousVariable* ByteVariable::shiftRightUnsigned(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1132(), ctx));
}
IAlinousVariable* ByteVariable::shiftRightUnsigned(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1132(), ctx));
}
IAlinousVariable* ByteVariable::modulo(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1132(), ctx));
}
IAlinousVariable* ByteVariable::modulo(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1132(), ctx));
}
IAlinousVariable* ByteVariable::bitOr(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1132(), ctx));
}
IAlinousVariable* ByteVariable::bitOr(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1132(), ctx));
}
IAlinousVariable* ByteVariable::bitAnd(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1132(), ctx));
}
IAlinousVariable* ByteVariable::bitAnd(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1132(), ctx));
}
IAlinousVariable* ByteVariable::bitExor(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1132(), ctx));
}
IAlinousVariable* ByteVariable::bitExor(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1132(), ctx));
}
IAlinousVariable* ByteVariable::substitute(TimeVariable* variable, ThreadContext* ctx)
{
	this->value = ((char)variable->getValue(ctx)->getTime(ctx));
	return this;
}
IAlinousVariable* ByteVariable::substitute(TimestampVariable* variable, ThreadContext* ctx)
{
	this->value = ((char)variable->getValue(ctx)->getTime(ctx));
	return this;
}
int ByteVariable::compareTo(TimeVariable* variable, ThreadContext* ctx)
{
	return ((int)(this->value - variable->getValue(ctx)->getTime(ctx)));
}
int ByteVariable::compareTo(TimestampVariable* variable, ThreadContext* ctx)
{
	return ((int)(this->value - variable->getValue(ctx)->getTime(ctx)));
}
IAlinousVariable* ByteVariable::substitute(TypedVariableArray* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1122(), ctx));
}
void ByteVariable::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	this->value = buff->getByte(ctx);
}
void ByteVariable::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putInt(ICommandData::__ByteVariable, ctx);
	buff->putByte(this->value, ctx);
}
ByteVariable* ByteVariable::fromDebugXml(DomNode* node, ThreadContext* ctx) throw() 
{
	IVariableValue* attrVal = node->getAttributeValue(VAL_TYPE, ctx);
	if(attrVal == nullptr)
	{
		return nullptr;
	}
	String* str = attrVal->toString(ctx);
	char value = 0;
	{
		try
		{
			value = Byte::parseByte(str, ctx);
		}
		catch(Throwable* e)
		{
			e->printStackTrace(ctx);
			return nullptr;
		}
	}
	return (new(ctx) ByteVariable(value, ctx));
}
int ByteVariable::ValueCompare::operator() (VariantValue* _this, VariantValue* variable, ThreadContext* ctx) const throw()
{
	return _this->compareTo(variable, ctx);
}
}}}}

