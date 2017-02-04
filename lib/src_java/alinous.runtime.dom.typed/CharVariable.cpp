#include "includes.h"


namespace alinous {namespace runtime {namespace dom {namespace typed {





String* CharVariable::VAL_TYPE = ConstStr::getCNST_STR_1137();
bool CharVariable::__init_done = __init_static_variables();
bool CharVariable::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"CharVariable", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 CharVariable::CharVariable(wchar_t value, ThreadContext* ctx) throw()  : IObject(ctx), AbstractTypedVariable(ctx), value(0)
{
	this->value = value;
}
void CharVariable::__construct_impl(wchar_t value, ThreadContext* ctx) throw() 
{
	this->value = value;
}
 CharVariable::~CharVariable() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void CharVariable::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"CharVariable", L"~CharVariable");
	if(!prepare){
		return;
	}
	AbstractTypedVariable::__releaseRegerences(true, ctx);
}
void CharVariable::outDebugXml(DomNode* parentNode, String* name, ThreadContext* ctx) throw() 
{
	DomNode* node = (new(ctx) DomNode(VAL_TYPE, ctx));
	parentNode->addChild(node, ctx);
	if(name != nullptr)
	{
		Attribute* nameattr = (new(ctx) Attribute(IAlinousVariable::ATTR_NAME, name, node, ctx));
		node->addAttribute(nameattr, ctx);
	}
	Attribute* attr = (new(ctx) Attribute(AbstractTypedVariable::VALUE, Character::toString(this->value, ctx), node, ctx));
	parentNode->addAttribute(attr, ctx);
}
int CharVariable::getVariableClass(ThreadContext* ctx) throw() 
{
	return IAlinousVariable::CLASS_TYPED;
}
int CharVariable::getTypedType(ThreadContext* ctx) throw() 
{
	return ITypedVariable::TYPE_CHAR;
}
VariantValue* CharVariable::toVariantValue(ThreadContext* ctx)
{
	return (new(ctx) VariantValue(this->value, ctx));
}
int CharVariable::getIntValue(ThreadContext* ctx)
{
	return this->value;
}
String* CharVariable::getStringValue(ThreadContext* ctx)
{
	return Character::toString(this->value, ctx);
}
wchar_t CharVariable::getValue(ThreadContext* ctx) throw() 
{
	return value;
}
void CharVariable::setValue(wchar_t value, ThreadContext* ctx) throw() 
{
	this->value = value;
}
IAlinousVariable* CharVariable::copy(ThreadContext* ctx)
{
	return (new(ctx) CharVariable(this->value, ctx));
}
IDomVariable* CharVariable::toDomVariable(ThreadContext* ctx) throw() 
{
	DomVariable* ret = (new(ctx) DomVariable(ctx));
	ret->setValue((new(ctx) VariantValue(this->value, ctx)), ctx);
	return ret;
}
IAlinousVariable* CharVariable::add(VariantValue* variable, ThreadContext* ctx)
{
	return variable->add(this, ctx)->copy(ctx);
}
IAlinousVariable* CharVariable::add(DomVariable* variable, ThreadContext* ctx)
{
	return variable->add(this, ctx)->copy(ctx);
}
IAlinousVariable* CharVariable::add(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1131(), ctx));
}
IAlinousVariable* CharVariable::add(ByteVariable* variable, ThreadContext* ctx)
{
	this->value = ((wchar_t)(this->value + variable->getValue(ctx)));
	return this;
}
IAlinousVariable* CharVariable::add(CharVariable* variable, ThreadContext* ctx)
{
	this->value = ((wchar_t)(this->value + variable->getValue(ctx)));
	return this;
}
IAlinousVariable* CharVariable::add(DoubleVariable* variable, ThreadContext* ctx)
{
	double res = this->value + variable->getValue(ctx);
	return (new(ctx) DoubleVariable(res, ctx));
}
IAlinousVariable* CharVariable::add(FloatVariable* variable, ThreadContext* ctx)
{
	float res = this->value + variable->getValue(ctx);
	return (new(ctx) FloatVariable(res, ctx));
}
IAlinousVariable* CharVariable::add(IntegerVariable* variable, ThreadContext* ctx)
{
	int res = this->value + variable->getValue(ctx);
	return (new(ctx) IntegerVariable(res, ctx));
}
IAlinousVariable* CharVariable::add(ShortVariable* variable, ThreadContext* ctx)
{
	short res = ((short)(this->value + variable->getValue(ctx)));
	return (new(ctx) ShortVariable(res, ctx));
}
IAlinousVariable* CharVariable::add(StringVariable* variable, ThreadContext* ctx)
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	buff->append(Character::toString(value, ctx), ctx);
	buff->append(variable->getValue(ctx), ctx);
	return (new(ctx) StringVariable(buff->toString(ctx), ctx));
}
IAlinousVariable* CharVariable::minus(VariantValue* variable, ThreadContext* ctx)
{
	return (new(ctx) VariantValue(this->value, ctx))->minus(variable, ctx);
}
IAlinousVariable* CharVariable::minus(DomVariable* variable, ThreadContext* ctx)
{
	return (new(ctx) VariantValue(this->value, ctx))->minus(variable, ctx);
}
IAlinousVariable* CharVariable::minus(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1131(), ctx));
}
IAlinousVariable* CharVariable::minus(ByteVariable* variable, ThreadContext* ctx)
{
	this->value = ((wchar_t)(this->value - variable->getValue(ctx)));
	return this;
}
IAlinousVariable* CharVariable::minus(CharVariable* variable, ThreadContext* ctx)
{
	this->value = ((wchar_t)(this->value - variable->getValue(ctx)));
	return this;
}
IAlinousVariable* CharVariable::minus(DoubleVariable* variable, ThreadContext* ctx)
{
	double res = this->value - variable->getValue(ctx);
	return (new(ctx) DoubleVariable(res, ctx));
}
IAlinousVariable* CharVariable::minus(FloatVariable* variable, ThreadContext* ctx)
{
	float res = this->value - variable->getValue(ctx);
	return (new(ctx) FloatVariable(res, ctx));
}
IAlinousVariable* CharVariable::minus(IntegerVariable* variable, ThreadContext* ctx)
{
	int res = this->value - variable->getValue(ctx);
	return (new(ctx) IntegerVariable(res, ctx));
}
IAlinousVariable* CharVariable::minus(ShortVariable* variable, ThreadContext* ctx)
{
	short res = ((short)(this->value - variable->getValue(ctx)));
	return (new(ctx) ShortVariable(res, ctx));
}
IAlinousVariable* CharVariable::minus(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1132(), ctx));
}
IAlinousVariable* CharVariable::multiply(VariantValue* variable, ThreadContext* ctx)
{
	return variable->multiply(this, ctx)->copy(ctx);
}
IAlinousVariable* CharVariable::multiply(DomVariable* variable, ThreadContext* ctx)
{
	return variable->multiply(this, ctx)->copy(ctx);
}
IAlinousVariable* CharVariable::multiply(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1131(), ctx));
}
IAlinousVariable* CharVariable::multiply(ByteVariable* variable, ThreadContext* ctx)
{
	this->value = ((wchar_t)(this->value * variable->getValue(ctx)));
	return this;
}
IAlinousVariable* CharVariable::multiply(CharVariable* variable, ThreadContext* ctx)
{
	this->value = ((wchar_t)(this->value * variable->getValue(ctx)));
	return this;
}
IAlinousVariable* CharVariable::multiply(DoubleVariable* variable, ThreadContext* ctx)
{
	double res = this->value * variable->getValue(ctx);
	return (new(ctx) DoubleVariable(res, ctx));
}
IAlinousVariable* CharVariable::multiply(FloatVariable* variable, ThreadContext* ctx)
{
	float res = this->value * variable->getValue(ctx);
	return (new(ctx) FloatVariable(res, ctx));
}
IAlinousVariable* CharVariable::multiply(IntegerVariable* variable, ThreadContext* ctx)
{
	int res = this->value * variable->getValue(ctx);
	return (new(ctx) IntegerVariable(res, ctx));
}
IAlinousVariable* CharVariable::multiply(ShortVariable* variable, ThreadContext* ctx)
{
	short res = ((short)(this->value * variable->getValue(ctx)));
	return (new(ctx) ShortVariable(res, ctx));
}
IAlinousVariable* CharVariable::multiply(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1132(), ctx));
}
IAlinousVariable* CharVariable::div(VariantValue* variable, ThreadContext* ctx)
{
	return (new(ctx) VariantValue(this->value, ctx))->div(variable, ctx);
}
IAlinousVariable* CharVariable::div(DomVariable* variable, ThreadContext* ctx)
{
	return (new(ctx) VariantValue(this->value, ctx))->div(variable, ctx);
}
IAlinousVariable* CharVariable::div(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1131(), ctx));
}
IAlinousVariable* CharVariable::div(ByteVariable* variable, ThreadContext* ctx)
{
	this->value = ((wchar_t)(this->value / variable->getValue(ctx)));
	return this;
}
IAlinousVariable* CharVariable::div(CharVariable* variable, ThreadContext* ctx)
{
	this->value = ((wchar_t)(this->value / variable->getValue(ctx)));
	return this;
}
IAlinousVariable* CharVariable::div(DoubleVariable* variable, ThreadContext* ctx)
{
	double res = this->value / variable->getValue(ctx);
	return (new(ctx) DoubleVariable(res, ctx));
}
IAlinousVariable* CharVariable::div(FloatVariable* variable, ThreadContext* ctx)
{
	float res = this->value / variable->getValue(ctx);
	return (new(ctx) FloatVariable(res, ctx));
}
IAlinousVariable* CharVariable::div(IntegerVariable* variable, ThreadContext* ctx)
{
	int res = this->value / variable->getValue(ctx);
	return (new(ctx) IntegerVariable(res, ctx));
}
IAlinousVariable* CharVariable::div(ShortVariable* variable, ThreadContext* ctx)
{
	short res = ((short)(this->value / variable->getValue(ctx)));
	return (new(ctx) ShortVariable(res, ctx));
}
IAlinousVariable* CharVariable::div(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1132(), ctx));
}
IAlinousVariable* CharVariable::bitReverse(ThreadContext* ctx)
{
	this->value = ((wchar_t)~this->value);
	return this;
}
IAlinousVariable* CharVariable::add(LongVariable* variable, ThreadContext* ctx)
{
	long long res = this->value + variable->getValue(ctx);
	return (new(ctx) LongVariable(res, ctx));
}
IAlinousVariable* CharVariable::minus(LongVariable* variable, ThreadContext* ctx)
{
	long long res = this->value - variable->getValue(ctx);
	return (new(ctx) LongVariable(res, ctx));
}
IAlinousVariable* CharVariable::multiply(LongVariable* variable, ThreadContext* ctx)
{
	long long res = this->value * variable->getValue(ctx);
	return (new(ctx) LongVariable(res, ctx));
}
IAlinousVariable* CharVariable::div(LongVariable* variable, ThreadContext* ctx)
{
	long long res = this->value / variable->getValue(ctx);
	return (new(ctx) LongVariable(res, ctx));
}
bool CharVariable::isNull(ThreadContext* ctx) throw() 
{
	return false;
}
bool CharVariable::isArray(ThreadContext* ctx) throw() 
{
	return false;
}
IAlinousVariable* CharVariable::shiftLeft(VariantValue* variable, ThreadContext* ctx)
{
	this->value = ((wchar_t)(this->value << variable->getInt(ctx)));
	return this;
}
IAlinousVariable* CharVariable::shiftLeft(DomVariable* variable, ThreadContext* ctx)
{
	this->value = ((wchar_t)(this->value << variable->getValue(ctx)->getInt(ctx)));
	return this;
}
IAlinousVariable* CharVariable::shiftLeft(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1131(), ctx));
}
IAlinousVariable* CharVariable::shiftLeft(ByteVariable* variable, ThreadContext* ctx)
{
	this->value = ((wchar_t)(this->value << variable->getValue(ctx)));
	return this;
}
IAlinousVariable* CharVariable::shiftLeft(CharVariable* variable, ThreadContext* ctx)
{
	this->value = ((wchar_t)(this->value << variable->getValue(ctx)));
	return this;
}
IAlinousVariable* CharVariable::shiftLeft(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* CharVariable::shiftLeft(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* CharVariable::shiftLeft(IntegerVariable* variable, ThreadContext* ctx)
{
	this->value = ((wchar_t)(this->value << variable->getValue(ctx)));
	return this;
}
IAlinousVariable* CharVariable::shiftLeft(LongVariable* variable, ThreadContext* ctx)
{
	this->value = ((wchar_t)(this->value << variable->getValue(ctx)));
	return this;
}
IAlinousVariable* CharVariable::shiftLeft(ShortVariable* variable, ThreadContext* ctx)
{
	this->value = ((wchar_t)(this->value << variable->getValue(ctx)));
	return this;
}
IAlinousVariable* CharVariable::shiftLeft(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1132(), ctx));
}
IAlinousVariable* CharVariable::shiftRight(VariantValue* variable, ThreadContext* ctx)
{
	this->value = ((wchar_t)(this->value >> variable->getInt(ctx)));
	return this;
}
IAlinousVariable* CharVariable::shiftRight(DomVariable* variable, ThreadContext* ctx)
{
	this->value = ((wchar_t)(this->value >> variable->getValue(ctx)->getInt(ctx)));
	return this;
}
IAlinousVariable* CharVariable::shiftRight(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1131(), ctx));
}
IAlinousVariable* CharVariable::shiftRight(ByteVariable* variable, ThreadContext* ctx)
{
	this->value = ((wchar_t)(this->value >> variable->getValue(ctx)));
	return this;
}
IAlinousVariable* CharVariable::shiftRight(CharVariable* variable, ThreadContext* ctx)
{
	this->value = ((wchar_t)(this->value >> variable->getValue(ctx)));
	return this;
}
IAlinousVariable* CharVariable::shiftRight(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* CharVariable::shiftRight(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* CharVariable::shiftRight(IntegerVariable* variable, ThreadContext* ctx)
{
	this->value = ((wchar_t)(this->value >> variable->getValue(ctx)));
	return this;
}
IAlinousVariable* CharVariable::shiftRight(LongVariable* variable, ThreadContext* ctx)
{
	this->value = ((wchar_t)(this->value >> variable->getValue(ctx)));
	return this;
}
IAlinousVariable* CharVariable::shiftRight(ShortVariable* variable, ThreadContext* ctx)
{
	this->value = ((wchar_t)(this->value >> variable->getValue(ctx)));
	return this;
}
IAlinousVariable* CharVariable::shiftRight(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1132(), ctx));
}
IAlinousVariable* CharVariable::modulo(VariantValue* variable, ThreadContext* ctx)
{
	this->value = ((wchar_t)(this->value % variable->getChar(ctx)));
	return this;
}
IAlinousVariable* CharVariable::modulo(DomVariable* variable, ThreadContext* ctx)
{
	this->value = ((wchar_t)(this->value % variable->getValue(ctx)->getChar(ctx)));
	return this;
}
IAlinousVariable* CharVariable::modulo(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1131(), ctx));
}
IAlinousVariable* CharVariable::modulo(ByteVariable* variable, ThreadContext* ctx)
{
	this->value = ((wchar_t)(this->value % variable->getValue(ctx)));
	return this;
}
IAlinousVariable* CharVariable::modulo(CharVariable* variable, ThreadContext* ctx)
{
	this->value = ((wchar_t)(this->value % variable->getValue(ctx)));
	return this;
}
IAlinousVariable* CharVariable::modulo(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* CharVariable::modulo(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* CharVariable::modulo(IntegerVariable* variable, ThreadContext* ctx)
{
	this->value = ((wchar_t)(this->value % variable->getValue(ctx)));
	return this;
}
IAlinousVariable* CharVariable::modulo(LongVariable* variable, ThreadContext* ctx)
{
	this->value = ((wchar_t)(this->value % variable->getValue(ctx)));
	return this;
}
IAlinousVariable* CharVariable::modulo(ShortVariable* variable, ThreadContext* ctx)
{
	this->value = ((wchar_t)(this->value % variable->getValue(ctx)));
	return this;
}
IAlinousVariable* CharVariable::modulo(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1132(), ctx));
}
IAlinousVariable* CharVariable::substitute(VariantValue* variable, ThreadContext* ctx)
{
	this->value = variable->getChar(ctx);
	return this;
}
IAlinousVariable* CharVariable::substitute(DomVariable* variable, ThreadContext* ctx)
{
	this->value = variable->getValue(ctx)->getChar(ctx);
	return this;
}
IAlinousVariable* CharVariable::substitute(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1131(), ctx));
}
IAlinousVariable* CharVariable::substitute(ByteVariable* variable, ThreadContext* ctx)
{
	this->value = ((wchar_t)variable->getValue(ctx));
	return this;
}
IAlinousVariable* CharVariable::substitute(CharVariable* variable, ThreadContext* ctx)
{
	this->value = variable->getValue(ctx);
	return this;
}
IAlinousVariable* CharVariable::substitute(DoubleVariable* variable, ThreadContext* ctx)
{
	this->value = ((wchar_t)variable->getValue(ctx));
	return this;
}
IAlinousVariable* CharVariable::substitute(FloatVariable* variable, ThreadContext* ctx)
{
	this->value = ((wchar_t)variable->getValue(ctx));
	return this;
}
IAlinousVariable* CharVariable::substitute(IntegerVariable* variable, ThreadContext* ctx)
{
	this->value = ((wchar_t)variable->getValue(ctx));
	return this;
}
IAlinousVariable* CharVariable::substitute(LongVariable* variable, ThreadContext* ctx)
{
	this->value = ((wchar_t)variable->getValue(ctx));
	return this;
}
IAlinousVariable* CharVariable::substitute(ShortVariable* variable, ThreadContext* ctx)
{
	this->value = ((wchar_t)variable->getValue(ctx));
	return this;
}
IAlinousVariable* CharVariable::substitute(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1132(), ctx));
}
int CharVariable::compareTo(VariantValue* variable, ThreadContext* ctx)
{
	return ((int)(this->value - variable->getChar(ctx)));
}
int CharVariable::compareTo(DomVariable* variable, ThreadContext* ctx)
{
	return ((int)(this->value - variable->getValue(ctx)->getChar(ctx)));
}
int CharVariable::compareTo(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1131(), ctx));
}
int CharVariable::compareTo(ByteVariable* variable, ThreadContext* ctx)
{
	return ((int)(this->value - variable->getValue(ctx)));
}
int CharVariable::compareTo(CharVariable* variable, ThreadContext* ctx)
{
	return ((int)(this->value - variable->getValue(ctx)));
}
int CharVariable::compareTo(DoubleVariable* variable, ThreadContext* ctx)
{
	return ((int)(this->value - variable->getValue(ctx)));
}
int CharVariable::compareTo(FloatVariable* variable, ThreadContext* ctx)
{
	return ((int)(this->value - variable->getValue(ctx)));
}
int CharVariable::compareTo(IntegerVariable* variable, ThreadContext* ctx)
{
	return ((int)(this->value - variable->getValue(ctx)));
}
int CharVariable::compareTo(LongVariable* variable, ThreadContext* ctx)
{
	return ((int)(this->value - variable->getValue(ctx)));
}
int CharVariable::compareTo(ShortVariable* variable, ThreadContext* ctx)
{
	return ((int)(this->value - variable->getValue(ctx)));
}
int CharVariable::compareTo(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1132(), ctx));
}
bool CharVariable::isTrue(ThreadContext* ctx)
{
	return this->value > (wchar_t)0;
}
IAlinousVariable* CharVariable::bitOr(VariantValue* variable, ThreadContext* ctx)
{
	this->value = ((wchar_t)(this->value | variable->getChar(ctx)));
	return this;
}
IAlinousVariable* CharVariable::bitOr(DomVariable* variable, ThreadContext* ctx)
{
	this->value = ((wchar_t)(this->value | variable->getValue(ctx)->getChar(ctx)));
	return this;
}
IAlinousVariable* CharVariable::bitOr(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1131(), ctx));
}
IAlinousVariable* CharVariable::bitOr(ByteVariable* variable, ThreadContext* ctx)
{
	this->value = ((wchar_t)(this->value | variable->getValue(ctx)));
	return this;
}
IAlinousVariable* CharVariable::bitOr(CharVariable* variable, ThreadContext* ctx)
{
	this->value = ((wchar_t)(this->value | variable->getValue(ctx)));
	return this;
}
IAlinousVariable* CharVariable::bitOr(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1134(), ctx));
}
IAlinousVariable* CharVariable::bitOr(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1134(), ctx));
}
IAlinousVariable* CharVariable::bitOr(IntegerVariable* variable, ThreadContext* ctx)
{
	this->value = ((wchar_t)(this->value | variable->getValue(ctx)));
	return this;
}
IAlinousVariable* CharVariable::bitOr(LongVariable* variable, ThreadContext* ctx)
{
	this->value = ((wchar_t)(this->value | variable->getValue(ctx)));
	return this;
}
IAlinousVariable* CharVariable::bitOr(ShortVariable* variable, ThreadContext* ctx)
{
	this->value = ((wchar_t)(this->value | variable->getValue(ctx)));
	return this;
}
IAlinousVariable* CharVariable::bitOr(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1132(), ctx));
}
IAlinousVariable* CharVariable::bitAnd(VariantValue* variable, ThreadContext* ctx)
{
	this->value = ((wchar_t)(this->value & variable->getChar(ctx)));
	return this;
}
IAlinousVariable* CharVariable::bitAnd(DomVariable* variable, ThreadContext* ctx)
{
	this->value = ((wchar_t)(this->value & variable->getValue(ctx)->getChar(ctx)));
	return this;
}
IAlinousVariable* CharVariable::bitAnd(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1131(), ctx));
}
IAlinousVariable* CharVariable::bitAnd(ByteVariable* variable, ThreadContext* ctx)
{
	this->value = ((wchar_t)(this->value & variable->getValue(ctx)));
	return this;
}
IAlinousVariable* CharVariable::bitAnd(CharVariable* variable, ThreadContext* ctx)
{
	this->value = ((wchar_t)(this->value & variable->getValue(ctx)));
	return this;
}
IAlinousVariable* CharVariable::bitAnd(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1134(), ctx));
}
IAlinousVariable* CharVariable::bitAnd(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1134(), ctx));
}
IAlinousVariable* CharVariable::bitAnd(IntegerVariable* variable, ThreadContext* ctx)
{
	this->value = ((wchar_t)(this->value & variable->getValue(ctx)));
	return this;
}
IAlinousVariable* CharVariable::bitAnd(LongVariable* variable, ThreadContext* ctx)
{
	this->value = ((wchar_t)(this->value & variable->getValue(ctx)));
	return this;
}
IAlinousVariable* CharVariable::bitAnd(ShortVariable* variable, ThreadContext* ctx)
{
	this->value = ((wchar_t)(this->value & variable->getValue(ctx)));
	return this;
}
IAlinousVariable* CharVariable::bitAnd(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1132(), ctx));
}
IAlinousVariable* CharVariable::bitExor(VariantValue* variable, ThreadContext* ctx)
{
	this->value = ((wchar_t)(this->value ^ variable->getChar(ctx)));
	return this;
}
IAlinousVariable* CharVariable::bitExor(DomVariable* variable, ThreadContext* ctx)
{
	this->value = ((wchar_t)(this->value ^ variable->getValue(ctx)->getChar(ctx)));
	return this;
}
IAlinousVariable* CharVariable::bitExor(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1131(), ctx));
}
IAlinousVariable* CharVariable::bitExor(ByteVariable* variable, ThreadContext* ctx)
{
	this->value = ((wchar_t)(this->value ^ variable->getValue(ctx)));
	return this;
}
IAlinousVariable* CharVariable::bitExor(CharVariable* variable, ThreadContext* ctx)
{
	this->value = ((wchar_t)(this->value ^ variable->getValue(ctx)));
	return this;
}
IAlinousVariable* CharVariable::bitExor(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1134(), ctx));
}
IAlinousVariable* CharVariable::bitExor(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1134(), ctx));
}
IAlinousVariable* CharVariable::bitExor(IntegerVariable* variable, ThreadContext* ctx)
{
	this->value = ((wchar_t)(this->value ^ variable->getValue(ctx)));
	return this;
}
IAlinousVariable* CharVariable::bitExor(LongVariable* variable, ThreadContext* ctx)
{
	this->value = ((wchar_t)(this->value ^ variable->getValue(ctx)));
	return this;
}
IAlinousVariable* CharVariable::bitExor(ShortVariable* variable, ThreadContext* ctx)
{
	this->value = ((wchar_t)(this->value ^ variable->getValue(ctx)));
	return this;
}
IAlinousVariable* CharVariable::bitExor(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1132(), ctx));
}
IAlinousVariable* CharVariable::add(BigDecimalVariable* variable, ThreadContext* ctx)
{
	this->value = ((wchar_t)(this->value + variable->getValue(ctx)->shortValue(ctx)));
	return this;
}
IAlinousVariable* CharVariable::minus(BigDecimalVariable* variable, ThreadContext* ctx)
{
	this->value = ((wchar_t)(this->value - variable->getValue(ctx)->shortValue(ctx)));
	return this;
}
IAlinousVariable* CharVariable::multiply(BigDecimalVariable* variable, ThreadContext* ctx)
{
	this->value = ((wchar_t)(this->value * variable->getValue(ctx)->shortValue(ctx)));
	return this;
}
IAlinousVariable* CharVariable::div(BigDecimalVariable* variable, ThreadContext* ctx)
{
	this->value = ((wchar_t)(this->value / variable->getValue(ctx)->shortValue(ctx)));
	return this;
}
IAlinousVariable* CharVariable::shiftLeft(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* CharVariable::shiftRight(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* CharVariable::modulo(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* CharVariable::bitOr(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* CharVariable::bitAnd(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* CharVariable::bitExor(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* CharVariable::substitute(BigDecimalVariable* variable, ThreadContext* ctx)
{
	this->value = ((wchar_t)variable->getValue(ctx)->shortValue(ctx));
	return this;
}
int CharVariable::compareTo(BigDecimalVariable* variable, ThreadContext* ctx)
{
	return ((int)(this->value - variable->getValue(ctx)->shortValue(ctx)));
}
IAlinousVariable* CharVariable::shiftRightUnsigned(VariantValue* variable, ThreadContext* ctx)
{
	this->value = ((wchar_t)(((unsigned wchar_t)this->value)>> variable->getInt(ctx)));
	return this;
}
IAlinousVariable* CharVariable::shiftRightUnsigned(DomVariable* variable, ThreadContext* ctx)
{
	this->value = ((wchar_t)(((unsigned wchar_t)this->value)>> variable->getValue(ctx)->getInt(ctx)));
	return this;
}
IAlinousVariable* CharVariable::shiftRightUnsigned(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1131(), ctx));
}
IAlinousVariable* CharVariable::shiftRightUnsigned(ByteVariable* variable, ThreadContext* ctx)
{
	this->value = ((wchar_t)(((unsigned wchar_t)this->value)>> variable->getValue(ctx)));
	return this;
}
IAlinousVariable* CharVariable::shiftRightUnsigned(CharVariable* variable, ThreadContext* ctx)
{
	this->value = ((wchar_t)(((unsigned wchar_t)this->value)>> variable->getValue(ctx)));
	return this;
}
IAlinousVariable* CharVariable::shiftRightUnsigned(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1134(), ctx));
}
IAlinousVariable* CharVariable::shiftRightUnsigned(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1134(), ctx));
}
IAlinousVariable* CharVariable::shiftRightUnsigned(IntegerVariable* variable, ThreadContext* ctx)
{
	this->value = ((wchar_t)(((unsigned wchar_t)this->value)>> variable->getValue(ctx)));
	return this;
}
IAlinousVariable* CharVariable::shiftRightUnsigned(LongVariable* variable, ThreadContext* ctx)
{
	this->value = ((wchar_t)(((unsigned wchar_t)this->value)>> variable->getValue(ctx)));
	return this;
}
IAlinousVariable* CharVariable::shiftRightUnsigned(ShortVariable* variable, ThreadContext* ctx)
{
	this->value = ((wchar_t)(((unsigned wchar_t)this->value)>> variable->getValue(ctx)));
	return this;
}
IAlinousVariable* CharVariable::shiftRightUnsigned(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1132(), ctx));
}
IAlinousVariable* CharVariable::shiftRightUnsigned(BigDecimalVariable* variable, ThreadContext* ctx)
{
	this->value = ((wchar_t)(((unsigned wchar_t)this->value)>> variable->getValue(ctx)->intValue(ctx)));
	return this;
}
BoolVariable* CharVariable::toBoolVariable(ThreadContext* ctx)
{
	return (new(ctx) BoolVariable(isTrue(ctx), ctx));
}
ByteVariable* CharVariable::toByteVariable(ThreadContext* ctx)
{
	return (new(ctx) ByteVariable(((char)this->value), ctx));
}
CharVariable* CharVariable::toCharVariable(ThreadContext* ctx)
{
	return static_cast<CharVariable*>(copy(ctx));
}
ShortVariable* CharVariable::toShortVariable(ThreadContext* ctx)
{
	return (new(ctx) ShortVariable(((short)this->value), ctx));
}
IntegerVariable* CharVariable::toIntVariable(ThreadContext* ctx)
{
	return (new(ctx) IntegerVariable(this->value, ctx));
}
LongVariable* CharVariable::toLongVariable(ThreadContext* ctx)
{
	return (new(ctx) LongVariable(this->value, ctx));
}
StringVariable* CharVariable::toStringVariable(ThreadContext* ctx)
{
	return (new(ctx) StringVariable(getStringValue(ctx), ctx));
}
BigDecimalVariable* CharVariable::toBigDecimalVariable(ThreadContext* ctx)
{
	BigDecimal* dec = (new(ctx) BigDecimal(this->value, ctx));
	return (new(ctx) BigDecimalVariable(dec, ctx));
}
long long CharVariable::getLongValue(ThreadContext* ctx)
{
	return this->value;
}
FloatVariable* CharVariable::toFloatVariable(ThreadContext* ctx)
{
	return (new(ctx) FloatVariable(this->value, ctx));
}
DoubleVariable* CharVariable::toDoubleVariable(ThreadContext* ctx)
{
	return (new(ctx) DoubleVariable(this->value, ctx));
}
TimeVariable* CharVariable::toTimeVariable(ThreadContext* ctx)
{
	TimeOnlyTimestamp* tm = (new(ctx) TimeOnlyTimestamp(this->value, ctx));
	return (new(ctx) TimeVariable(tm, ctx));
}
TimestampVariable* CharVariable::toTimestampVariable(ThreadContext* ctx)
{
	Timestamp* tm = (new(ctx) Timestamp(this->value, ctx));
	return (new(ctx) TimestampVariable(tm, ctx));
}
IAlinousVariable* CharVariable::add(TimeVariable* variable, ThreadContext* ctx)
{
	this->value = ((wchar_t)(this->value + variable->getValue(ctx)->getTime(ctx)));
	return this;
}
IAlinousVariable* CharVariable::add(TimestampVariable* variable, ThreadContext* ctx)
{
	this->value = ((wchar_t)(this->value + variable->getValue(ctx)->getTime(ctx)));
	return this;
}
IAlinousVariable* CharVariable::minus(TimeVariable* variable, ThreadContext* ctx)
{
	this->value = ((wchar_t)(this->value - variable->getValue(ctx)->getTime(ctx)));
	return this;
}
IAlinousVariable* CharVariable::minus(TimestampVariable* variable, ThreadContext* ctx)
{
	this->value = ((wchar_t)(this->value - variable->getValue(ctx)->getTime(ctx)));
	return this;
}
IAlinousVariable* CharVariable::multiply(TimeVariable* variable, ThreadContext* ctx)
{
	this->value = ((wchar_t)(this->value * variable->getValue(ctx)->getTime(ctx)));
	return this;
}
IAlinousVariable* CharVariable::multiply(TimestampVariable* variable, ThreadContext* ctx)
{
	this->value = ((wchar_t)(this->value * variable->getValue(ctx)->getTime(ctx)));
	return this;
}
IAlinousVariable* CharVariable::div(TimeVariable* variable, ThreadContext* ctx)
{
	this->value = ((wchar_t)(this->value / variable->getValue(ctx)->getTime(ctx)));
	return this;
}
IAlinousVariable* CharVariable::div(TimestampVariable* variable, ThreadContext* ctx)
{
	this->value = ((wchar_t)(this->value / variable->getValue(ctx)->getTime(ctx)));
	return this;
}
IAlinousVariable* CharVariable::shiftLeft(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* CharVariable::shiftLeft(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* CharVariable::shiftRight(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* CharVariable::shiftRight(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* CharVariable::shiftRightUnsigned(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* CharVariable::shiftRightUnsigned(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* CharVariable::modulo(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* CharVariable::modulo(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* CharVariable::bitOr(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* CharVariable::bitOr(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* CharVariable::bitAnd(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* CharVariable::bitAnd(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* CharVariable::bitExor(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* CharVariable::bitExor(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* CharVariable::substitute(TimeVariable* variable, ThreadContext* ctx)
{
	this->value = ((wchar_t)variable->getValue(ctx)->getTime(ctx));
	return this;
}
IAlinousVariable* CharVariable::substitute(TimestampVariable* variable, ThreadContext* ctx)
{
	this->value = ((wchar_t)variable->getValue(ctx)->getTime(ctx));
	return this;
}
int CharVariable::compareTo(TimeVariable* variable, ThreadContext* ctx)
{
	return ((int)(this->value - variable->getValue(ctx)->getTime(ctx)));
}
int CharVariable::compareTo(TimestampVariable* variable, ThreadContext* ctx)
{
	return ((int)(this->value - variable->getValue(ctx)->getTime(ctx)));
}
IAlinousVariable* CharVariable::substitute(TypedVariableArray* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1126(), ctx));
}
void CharVariable::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	this->value = buff->getChar(ctx);
}
void CharVariable::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putInt(ICommandData::__CharVariable, ctx);
	buff->putChar(this->value, ctx);
}
CharVariable* CharVariable::fromDebugXml(DomNode* node, ThreadContext* ctx) throw() 
{
	IVariableValue* attrVal = node->getAttributeValue(VAL_TYPE, ctx);
	if(attrVal == nullptr)
	{
		return nullptr;
	}
	String* str = attrVal->toString(ctx);
	wchar_t value = 0;
	{
		try
		{
			value = ((wchar_t)Integer::parseInt(str, ctx));
		}
		catch(Throwable* e)
		{
			e->printStackTrace(ctx);
			return nullptr;
		}
	}
	return (new(ctx) CharVariable(value, ctx));
}
int CharVariable::ValueCompare::operator() (VariantValue* _this, VariantValue* variable, ThreadContext* ctx) const throw()
{
	return _this->compareTo(variable, ctx);
}
}}}}

