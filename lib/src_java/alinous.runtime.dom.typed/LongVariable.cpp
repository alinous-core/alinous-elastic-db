#include "includes.h"


namespace alinous {namespace runtime {namespace dom {namespace typed {





String* LongVariable::VAL_TYPE = ConstStr::getCNST_STR_1143();
bool LongVariable::__init_done = __init_static_variables();
bool LongVariable::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"LongVariable", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 LongVariable::LongVariable(long long value, ThreadContext* ctx) throw()  : IObject(ctx), AbstractTypedVariable(ctx), value(0)
{
	this->value = value;
}
void LongVariable::__construct_impl(long long value, ThreadContext* ctx) throw() 
{
	this->value = value;
}
 LongVariable::~LongVariable() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void LongVariable::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"LongVariable", L"~LongVariable");
	if(!prepare){
		return;
	}
	AbstractTypedVariable::__releaseRegerences(true, ctx);
}
void LongVariable::outDebugXml(DomNode* parentNode, String* name, ThreadContext* ctx) throw() 
{
	DomNode* node = (new(ctx) DomNode(VAL_TYPE, ctx));
	parentNode->addChild(node, ctx);
	if(name != nullptr)
	{
		Attribute* nameattr = (new(ctx) Attribute(IAlinousVariable::ATTR_NAME, name, node, ctx));
		node->addAttribute(nameattr, ctx);
	}
	Attribute* attr = (new(ctx) Attribute(AbstractTypedVariable::VALUE, Long::toString(this->value, ctx), node, ctx));
	parentNode->addAttribute(attr, ctx);
}
int LongVariable::getVariableClass(ThreadContext* ctx) throw() 
{
	return IAlinousVariable::CLASS_TYPED;
}
int LongVariable::getTypedType(ThreadContext* ctx) throw() 
{
	return ITypedVariable::TYPE_LONG;
}
long long LongVariable::getValue(ThreadContext* ctx) throw() 
{
	return value;
}
void LongVariable::setValue(long long value, ThreadContext* ctx) throw() 
{
	this->value = value;
}
VariantValue* LongVariable::toVariantValue(ThreadContext* ctx)
{
	return (new(ctx) VariantValue(this->value, ctx));
}
int LongVariable::getIntValue(ThreadContext* ctx)
{
	return ((int)this->value);
}
String* LongVariable::getStringValue(ThreadContext* ctx)
{
	return Long::toString(this->value, ctx);
}
IAlinousVariable* LongVariable::copy(ThreadContext* ctx)
{
	return (new(ctx) LongVariable(this->value, ctx));
}
IDomVariable* LongVariable::toDomVariable(ThreadContext* ctx) throw() 
{
	DomVariable* ret = (new(ctx) DomVariable(ctx));
	ret->setValue((new(ctx) VariantValue(this->value, ctx)), ctx);
	return ret;
}
IAlinousVariable* LongVariable::add(LongVariable* variable, ThreadContext* ctx)
{
	this->value = this->value + variable->getValue(ctx);
	return this;
}
IAlinousVariable* LongVariable::minus(LongVariable* variable, ThreadContext* ctx)
{
	this->value = this->value - variable->getValue(ctx);
	return this;
}
IAlinousVariable* LongVariable::multiply(LongVariable* variable, ThreadContext* ctx)
{
	this->value = this->value * variable->getValue(ctx);
	return this;
}
IAlinousVariable* LongVariable::div(LongVariable* variable, ThreadContext* ctx)
{
	this->value = this->value / variable->getValue(ctx);
	return this;
}
IAlinousVariable* LongVariable::add(VariantValue* variable, ThreadContext* ctx)
{
	return variable->add(this, ctx)->copy(ctx);
}
IAlinousVariable* LongVariable::add(DomVariable* variable, ThreadContext* ctx)
{
	return variable->add(this, ctx)->copy(ctx);
}
IAlinousVariable* LongVariable::add(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1129(), ctx));
}
IAlinousVariable* LongVariable::add(ByteVariable* variable, ThreadContext* ctx)
{
	this->value = this->value + variable->getValue(ctx);
	return this;
}
IAlinousVariable* LongVariable::add(CharVariable* variable, ThreadContext* ctx)
{
	this->value = this->value + variable->getValue(ctx);
	return this;
}
IAlinousVariable* LongVariable::add(DoubleVariable* variable, ThreadContext* ctx)
{
	double res = this->value + variable->getValue(ctx);
	return (new(ctx) DoubleVariable(res, ctx));
}
IAlinousVariable* LongVariable::add(FloatVariable* variable, ThreadContext* ctx)
{
	float res = this->value + variable->getValue(ctx);
	return (new(ctx) FloatVariable(res, ctx));
}
IAlinousVariable* LongVariable::add(IntegerVariable* variable, ThreadContext* ctx)
{
	this->value = this->value + variable->getValue(ctx);
	return this;
}
IAlinousVariable* LongVariable::add(ShortVariable* variable, ThreadContext* ctx)
{
	this->value = this->value + variable->getValue(ctx);
	return this;
}
IAlinousVariable* LongVariable::add(StringVariable* variable, ThreadContext* ctx)
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	buff->append(Long::toString(value, ctx), ctx);
	buff->append(variable->getValue(ctx), ctx);
	return (new(ctx) StringVariable(buff->toString(ctx), ctx));
}
IAlinousVariable* LongVariable::minus(VariantValue* variable, ThreadContext* ctx)
{
	return (new(ctx) VariantValue(this->value, ctx))->minus(variable, ctx);
}
IAlinousVariable* LongVariable::minus(DomVariable* variable, ThreadContext* ctx)
{
	return (new(ctx) VariantValue(this->value, ctx))->minus(variable, ctx);
}
IAlinousVariable* LongVariable::minus(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1129(), ctx));
}
IAlinousVariable* LongVariable::minus(ByteVariable* variable, ThreadContext* ctx)
{
	this->value = this->value - variable->getValue(ctx);
	return this;
}
IAlinousVariable* LongVariable::minus(CharVariable* variable, ThreadContext* ctx)
{
	this->value = this->value - variable->getValue(ctx);
	return this;
}
IAlinousVariable* LongVariable::minus(DoubleVariable* variable, ThreadContext* ctx)
{
	double res = this->value - variable->getValue(ctx);
	return (new(ctx) DoubleVariable(res, ctx));
}
IAlinousVariable* LongVariable::minus(FloatVariable* variable, ThreadContext* ctx)
{
	float res = this->value - variable->getValue(ctx);
	return (new(ctx) FloatVariable(res, ctx));
}
IAlinousVariable* LongVariable::minus(IntegerVariable* variable, ThreadContext* ctx)
{
	this->value = this->value - variable->getValue(ctx);
	return this;
}
IAlinousVariable* LongVariable::minus(ShortVariable* variable, ThreadContext* ctx)
{
	this->value = this->value - variable->getValue(ctx);
	return this;
}
IAlinousVariable* LongVariable::minus(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1130(), ctx));
}
IAlinousVariable* LongVariable::multiply(VariantValue* variable, ThreadContext* ctx)
{
	return variable->multiply(this, ctx)->copy(ctx);
}
IAlinousVariable* LongVariable::multiply(DomVariable* variable, ThreadContext* ctx)
{
	return variable->multiply(this, ctx)->copy(ctx);
}
IAlinousVariable* LongVariable::multiply(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1129(), ctx));
}
IAlinousVariable* LongVariable::multiply(ByteVariable* variable, ThreadContext* ctx)
{
	this->value = this->value * variable->getValue(ctx);
	return this;
}
IAlinousVariable* LongVariable::multiply(CharVariable* variable, ThreadContext* ctx)
{
	this->value = this->value * variable->getValue(ctx);
	return this;
}
IAlinousVariable* LongVariable::multiply(DoubleVariable* variable, ThreadContext* ctx)
{
	double res = this->value * variable->getValue(ctx);
	return (new(ctx) DoubleVariable(res, ctx));
}
IAlinousVariable* LongVariable::multiply(FloatVariable* variable, ThreadContext* ctx)
{
	float res = this->value * variable->getValue(ctx);
	return (new(ctx) FloatVariable(res, ctx));
}
IAlinousVariable* LongVariable::multiply(IntegerVariable* variable, ThreadContext* ctx)
{
	this->value = this->value * variable->getValue(ctx);
	return this;
}
IAlinousVariable* LongVariable::multiply(ShortVariable* variable, ThreadContext* ctx)
{
	this->value = this->value * variable->getValue(ctx);
	return this;
}
IAlinousVariable* LongVariable::multiply(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1130(), ctx));
}
IAlinousVariable* LongVariable::div(VariantValue* variable, ThreadContext* ctx)
{
	return (new(ctx) VariantValue(this->value, ctx))->div(variable, ctx);
}
IAlinousVariable* LongVariable::div(DomVariable* variable, ThreadContext* ctx)
{
	return (new(ctx) VariantValue(this->value, ctx))->div(variable, ctx);
}
IAlinousVariable* LongVariable::div(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1129(), ctx));
}
IAlinousVariable* LongVariable::div(ByteVariable* variable, ThreadContext* ctx)
{
	this->value = this->value / variable->getValue(ctx);
	return this;
}
IAlinousVariable* LongVariable::div(CharVariable* variable, ThreadContext* ctx)
{
	this->value = this->value / variable->getValue(ctx);
	return this;
}
IAlinousVariable* LongVariable::div(DoubleVariable* variable, ThreadContext* ctx)
{
	double res = this->value / variable->getValue(ctx);
	return (new(ctx) DoubleVariable(res, ctx));
}
IAlinousVariable* LongVariable::div(FloatVariable* variable, ThreadContext* ctx)
{
	float res = this->value / variable->getValue(ctx);
	return (new(ctx) FloatVariable(res, ctx));
}
IAlinousVariable* LongVariable::div(IntegerVariable* variable, ThreadContext* ctx)
{
	this->value = this->value / variable->getValue(ctx);
	return this;
}
IAlinousVariable* LongVariable::div(ShortVariable* variable, ThreadContext* ctx)
{
	this->value = this->value / variable->getValue(ctx);
	return this;
}
IAlinousVariable* LongVariable::div(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1130(), ctx));
}
IAlinousVariable* LongVariable::bitReverse(ThreadContext* ctx)
{
	this->value = ~this->value;
	return this;
}
bool LongVariable::isNull(ThreadContext* ctx) throw() 
{
	return false;
}
bool LongVariable::isArray(ThreadContext* ctx) throw() 
{
	return false;
}
IAlinousVariable* LongVariable::shiftLeft(VariantValue* variable, ThreadContext* ctx)
{
	this->value = this->value << variable->getInt(ctx);
	return this;
}
IAlinousVariable* LongVariable::shiftLeft(DomVariable* variable, ThreadContext* ctx)
{
	this->value = this->value << variable->getValue(ctx)->getInt(ctx);
	return this;
}
IAlinousVariable* LongVariable::shiftLeft(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1129(), ctx));
}
IAlinousVariable* LongVariable::shiftLeft(ByteVariable* variable, ThreadContext* ctx)
{
	this->value = this->value << variable->getValue(ctx);
	return this;
}
IAlinousVariable* LongVariable::shiftLeft(CharVariable* variable, ThreadContext* ctx)
{
	this->value = this->value << variable->getValue(ctx);
	return this;
}
IAlinousVariable* LongVariable::shiftLeft(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1131(), ctx));
}
IAlinousVariable* LongVariable::shiftLeft(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1131(), ctx));
}
IAlinousVariable* LongVariable::shiftLeft(IntegerVariable* variable, ThreadContext* ctx)
{
	this->value = this->value << variable->getValue(ctx);
	return this;
}
IAlinousVariable* LongVariable::shiftLeft(LongVariable* variable, ThreadContext* ctx)
{
	this->value = this->value << variable->getValue(ctx);
	return this;
}
IAlinousVariable* LongVariable::shiftLeft(ShortVariable* variable, ThreadContext* ctx)
{
	this->value = this->value << variable->getValue(ctx);
	return this;
}
IAlinousVariable* LongVariable::shiftLeft(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1130(), ctx));
}
IAlinousVariable* LongVariable::shiftRight(VariantValue* variable, ThreadContext* ctx)
{
	this->value = this->value >> variable->getInt(ctx);
	return this;
}
IAlinousVariable* LongVariable::shiftRight(DomVariable* variable, ThreadContext* ctx)
{
	this->value = this->value >> variable->getValue(ctx)->getInt(ctx);
	return this;
}
IAlinousVariable* LongVariable::shiftRight(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1129(), ctx));
}
IAlinousVariable* LongVariable::shiftRight(ByteVariable* variable, ThreadContext* ctx)
{
	this->value = this->value >> variable->getValue(ctx);
	return this;
}
IAlinousVariable* LongVariable::shiftRight(CharVariable* variable, ThreadContext* ctx)
{
	this->value = this->value >> variable->getValue(ctx);
	return this;
}
IAlinousVariable* LongVariable::shiftRight(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1131(), ctx));
}
IAlinousVariable* LongVariable::shiftRight(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1131(), ctx));
}
IAlinousVariable* LongVariable::shiftRight(IntegerVariable* variable, ThreadContext* ctx)
{
	this->value = this->value >> variable->getValue(ctx);
	return this;
}
IAlinousVariable* LongVariable::shiftRight(LongVariable* variable, ThreadContext* ctx)
{
	this->value = this->value >> variable->getValue(ctx);
	return this;
}
IAlinousVariable* LongVariable::shiftRight(ShortVariable* variable, ThreadContext* ctx)
{
	this->value = this->value >> variable->getValue(ctx);
	return this;
}
IAlinousVariable* LongVariable::shiftRight(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1130(), ctx));
}
IAlinousVariable* LongVariable::modulo(VariantValue* variable, ThreadContext* ctx)
{
	this->value = this->value % variable->getLong(ctx);
	return this;
}
IAlinousVariable* LongVariable::modulo(DomVariable* variable, ThreadContext* ctx)
{
	this->value = this->value % variable->getValue(ctx)->getLong(ctx);
	return this;
}
IAlinousVariable* LongVariable::modulo(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1129(), ctx));
}
IAlinousVariable* LongVariable::modulo(ByteVariable* variable, ThreadContext* ctx)
{
	this->value = this->value % variable->getValue(ctx);
	return this;
}
IAlinousVariable* LongVariable::modulo(CharVariable* variable, ThreadContext* ctx)
{
	this->value = this->value % variable->getValue(ctx);
	return this;
}
IAlinousVariable* LongVariable::modulo(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1131(), ctx));
}
IAlinousVariable* LongVariable::modulo(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1131(), ctx));
}
IAlinousVariable* LongVariable::modulo(IntegerVariable* variable, ThreadContext* ctx)
{
	this->value = this->value % variable->getValue(ctx);
	return this;
}
IAlinousVariable* LongVariable::modulo(LongVariable* variable, ThreadContext* ctx)
{
	this->value = this->value % variable->getValue(ctx);
	return this;
}
IAlinousVariable* LongVariable::modulo(ShortVariable* variable, ThreadContext* ctx)
{
	this->value = this->value % variable->getValue(ctx);
	return this;
}
IAlinousVariable* LongVariable::modulo(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1130(), ctx));
}
IAlinousVariable* LongVariable::substitute(VariantValue* variable, ThreadContext* ctx)
{
	this->value = variable->getLong(ctx);
	return this;
}
IAlinousVariable* LongVariable::substitute(DomVariable* variable, ThreadContext* ctx)
{
	this->value = variable->getValue(ctx)->getLong(ctx);
	return this;
}
IAlinousVariable* LongVariable::substitute(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1129(), ctx));
}
IAlinousVariable* LongVariable::substitute(ByteVariable* variable, ThreadContext* ctx)
{
	this->value = variable->getValue(ctx);
	return this;
}
IAlinousVariable* LongVariable::substitute(CharVariable* variable, ThreadContext* ctx)
{
	this->value = variable->getValue(ctx);
	return this;
}
IAlinousVariable* LongVariable::substitute(DoubleVariable* variable, ThreadContext* ctx)
{
	this->value = ((long long)variable->getValue(ctx));
	return this;
}
IAlinousVariable* LongVariable::substitute(FloatVariable* variable, ThreadContext* ctx)
{
	this->value = ((long long)variable->getValue(ctx));
	return this;
}
IAlinousVariable* LongVariable::substitute(IntegerVariable* variable, ThreadContext* ctx)
{
	this->value = variable->getValue(ctx);
	return this;
}
IAlinousVariable* LongVariable::substitute(LongVariable* variable, ThreadContext* ctx)
{
	this->value = variable->getValue(ctx);
	return this;
}
IAlinousVariable* LongVariable::substitute(ShortVariable* variable, ThreadContext* ctx)
{
	this->value = variable->getValue(ctx);
	return this;
}
IAlinousVariable* LongVariable::substitute(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1130(), ctx));
}
int LongVariable::compareTo(VariantValue* variable, ThreadContext* ctx)
{
	return ((int)(this->value - variable->getLong(ctx)));
}
int LongVariable::compareTo(DomVariable* variable, ThreadContext* ctx)
{
	return ((int)(this->value - variable->getValue(ctx)->getLong(ctx)));
}
int LongVariable::compareTo(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1129(), ctx));
}
int LongVariable::compareTo(ByteVariable* variable, ThreadContext* ctx)
{
	return ((int)(this->value - variable->getValue(ctx)));
}
int LongVariable::compareTo(CharVariable* variable, ThreadContext* ctx)
{
	return ((int)(this->value - variable->getValue(ctx)));
}
int LongVariable::compareTo(DoubleVariable* variable, ThreadContext* ctx)
{
	return ((int)(this->value - variable->getValue(ctx)));
}
int LongVariable::compareTo(FloatVariable* variable, ThreadContext* ctx)
{
	return ((int)(this->value - variable->getValue(ctx)));
}
int LongVariable::compareTo(IntegerVariable* variable, ThreadContext* ctx)
{
	return ((int)(this->value - variable->getValue(ctx)));
}
int LongVariable::compareTo(LongVariable* variable, ThreadContext* ctx)
{
	return ((int)(this->value - variable->getValue(ctx)));
}
int LongVariable::compareTo(ShortVariable* variable, ThreadContext* ctx)
{
	return ((int)(this->value - variable->getValue(ctx)));
}
int LongVariable::compareTo(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1130(), ctx));
}
bool LongVariable::isTrue(ThreadContext* ctx)
{
	return this->value > (long long)0;
}
IAlinousVariable* LongVariable::bitOr(VariantValue* variable, ThreadContext* ctx)
{
	this->value = this->value | variable->getLong(ctx);
	return this;
}
IAlinousVariable* LongVariable::bitOr(DomVariable* variable, ThreadContext* ctx)
{
	this->value = this->value | variable->getValue(ctx)->getLong(ctx);
	return this;
}
IAlinousVariable* LongVariable::bitOr(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1129(), ctx));
}
IAlinousVariable* LongVariable::bitOr(ByteVariable* variable, ThreadContext* ctx)
{
	this->value = this->value | variable->getValue(ctx);
	return this;
}
IAlinousVariable* LongVariable::bitOr(CharVariable* variable, ThreadContext* ctx)
{
	this->value = this->value | variable->getValue(ctx);
	return this;
}
IAlinousVariable* LongVariable::bitOr(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1132(), ctx));
}
IAlinousVariable* LongVariable::bitOr(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1132(), ctx));
}
IAlinousVariable* LongVariable::bitOr(IntegerVariable* variable, ThreadContext* ctx)
{
	this->value = this->value | variable->getValue(ctx);
	return this;
}
IAlinousVariable* LongVariable::bitOr(LongVariable* variable, ThreadContext* ctx)
{
	this->value = this->value | variable->getValue(ctx);
	return this;
}
IAlinousVariable* LongVariable::bitOr(ShortVariable* variable, ThreadContext* ctx)
{
	this->value = this->value | variable->getValue(ctx);
	return this;
}
IAlinousVariable* LongVariable::bitOr(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1130(), ctx));
}
IAlinousVariable* LongVariable::bitAnd(VariantValue* variable, ThreadContext* ctx)
{
	this->value = this->value & variable->getLong(ctx);
	return this;
}
IAlinousVariable* LongVariable::bitAnd(DomVariable* variable, ThreadContext* ctx)
{
	this->value = this->value & variable->getValue(ctx)->getLong(ctx);
	return this;
}
IAlinousVariable* LongVariable::bitAnd(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1129(), ctx));
}
IAlinousVariable* LongVariable::bitAnd(ByteVariable* variable, ThreadContext* ctx)
{
	this->value = this->value & variable->getValue(ctx);
	return this;
}
IAlinousVariable* LongVariable::bitAnd(CharVariable* variable, ThreadContext* ctx)
{
	this->value = this->value & variable->getValue(ctx);
	return this;
}
IAlinousVariable* LongVariable::bitAnd(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1132(), ctx));
}
IAlinousVariable* LongVariable::bitAnd(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1132(), ctx));
}
IAlinousVariable* LongVariable::bitAnd(IntegerVariable* variable, ThreadContext* ctx)
{
	this->value = this->value & variable->getValue(ctx);
	return this;
}
IAlinousVariable* LongVariable::bitAnd(LongVariable* variable, ThreadContext* ctx)
{
	this->value = this->value & variable->getValue(ctx);
	return this;
}
IAlinousVariable* LongVariable::bitAnd(ShortVariable* variable, ThreadContext* ctx)
{
	this->value = this->value & variable->getValue(ctx);
	return this;
}
IAlinousVariable* LongVariable::bitAnd(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1130(), ctx));
}
IAlinousVariable* LongVariable::bitExor(VariantValue* variable, ThreadContext* ctx)
{
	this->value = this->value ^ variable->getLong(ctx);
	return this;
}
IAlinousVariable* LongVariable::bitExor(DomVariable* variable, ThreadContext* ctx)
{
	this->value = this->value ^ variable->getValue(ctx)->getLong(ctx);
	return this;
}
IAlinousVariable* LongVariable::bitExor(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1129(), ctx));
}
IAlinousVariable* LongVariable::bitExor(ByteVariable* variable, ThreadContext* ctx)
{
	this->value = this->value ^ variable->getValue(ctx);
	return this;
}
IAlinousVariable* LongVariable::bitExor(CharVariable* variable, ThreadContext* ctx)
{
	this->value = this->value ^ variable->getValue(ctx);
	return this;
}
IAlinousVariable* LongVariable::bitExor(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1132(), ctx));
}
IAlinousVariable* LongVariable::bitExor(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1132(), ctx));
}
IAlinousVariable* LongVariable::bitExor(IntegerVariable* variable, ThreadContext* ctx)
{
	this->value = this->value ^ variable->getValue(ctx);
	return this;
}
IAlinousVariable* LongVariable::bitExor(LongVariable* variable, ThreadContext* ctx)
{
	this->value = this->value ^ variable->getValue(ctx);
	return this;
}
IAlinousVariable* LongVariable::bitExor(ShortVariable* variable, ThreadContext* ctx)
{
	this->value = this->value ^ variable->getValue(ctx);
	return this;
}
IAlinousVariable* LongVariable::bitExor(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1130(), ctx));
}
IAlinousVariable* LongVariable::add(BigDecimalVariable* variable, ThreadContext* ctx)
{
	this->value = this->value + variable->getValue(ctx)->longValue(ctx);
	return this;
}
IAlinousVariable* LongVariable::minus(BigDecimalVariable* variable, ThreadContext* ctx)
{
	this->value = this->value - variable->getValue(ctx)->longValue(ctx);
	return this;
}
IAlinousVariable* LongVariable::multiply(BigDecimalVariable* variable, ThreadContext* ctx)
{
	this->value = this->value * variable->getValue(ctx)->longValue(ctx);
	return this;
}
IAlinousVariable* LongVariable::div(BigDecimalVariable* variable, ThreadContext* ctx)
{
	this->value = this->value / variable->getValue(ctx)->longValue(ctx);
	return this;
}
IAlinousVariable* LongVariable::shiftLeft(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* LongVariable::shiftRight(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* LongVariable::modulo(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* LongVariable::bitOr(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* LongVariable::bitAnd(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* LongVariable::bitExor(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* LongVariable::substitute(BigDecimalVariable* variable, ThreadContext* ctx)
{
	this->value = variable->getValue(ctx)->longValue(ctx);
	return this;
}
int LongVariable::compareTo(BigDecimalVariable* variable, ThreadContext* ctx)
{
	return ((int)(this->value - variable->getValue(ctx)->longValue(ctx)));
}
IAlinousVariable* LongVariable::shiftRightUnsigned(VariantValue* variable, ThreadContext* ctx)
{
	this->value = ((unsigned long long)this->value)>> variable->getInt(ctx);
	return this;
}
IAlinousVariable* LongVariable::shiftRightUnsigned(DomVariable* variable, ThreadContext* ctx)
{
	this->value = ((unsigned long long)this->value)>> variable->getValue(ctx)->getInt(ctx);
	return this;
}
IAlinousVariable* LongVariable::shiftRightUnsigned(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1129(), ctx));
}
IAlinousVariable* LongVariable::shiftRightUnsigned(ByteVariable* variable, ThreadContext* ctx)
{
	this->value = ((unsigned long long)this->value)>> variable->getValue(ctx);
	return this;
}
IAlinousVariable* LongVariable::shiftRightUnsigned(CharVariable* variable, ThreadContext* ctx)
{
	this->value = ((unsigned long long)this->value)>> variable->getValue(ctx);
	return this;
}
IAlinousVariable* LongVariable::shiftRightUnsigned(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1132(), ctx));
}
IAlinousVariable* LongVariable::shiftRightUnsigned(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1132(), ctx));
}
IAlinousVariable* LongVariable::shiftRightUnsigned(IntegerVariable* variable, ThreadContext* ctx)
{
	this->value = ((unsigned long long)this->value)>> variable->getValue(ctx);
	return this;
}
IAlinousVariable* LongVariable::shiftRightUnsigned(LongVariable* variable, ThreadContext* ctx)
{
	this->value = ((unsigned long long)this->value)>> variable->getValue(ctx);
	return this;
}
IAlinousVariable* LongVariable::shiftRightUnsigned(ShortVariable* variable, ThreadContext* ctx)
{
	this->value = ((unsigned long long)this->value)>> variable->getValue(ctx);
	return this;
}
IAlinousVariable* LongVariable::shiftRightUnsigned(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1130(), ctx));
}
IAlinousVariable* LongVariable::shiftRightUnsigned(BigDecimalVariable* variable, ThreadContext* ctx)
{
	this->value = ((unsigned long long)this->value)>> variable->getValue(ctx)->intValue(ctx);
	return this;
}
BoolVariable* LongVariable::toBoolVariable(ThreadContext* ctx)
{
	return (new(ctx) BoolVariable(isTrue(ctx), ctx));
}
ByteVariable* LongVariable::toByteVariable(ThreadContext* ctx)
{
	return (new(ctx) ByteVariable(((char)this->value), ctx));
}
CharVariable* LongVariable::toCharVariable(ThreadContext* ctx)
{
	return (new(ctx) CharVariable(((wchar_t)this->value), ctx));
}
ShortVariable* LongVariable::toShortVariable(ThreadContext* ctx)
{
	return (new(ctx) ShortVariable(((short)this->value), ctx));
}
IntegerVariable* LongVariable::toIntVariable(ThreadContext* ctx)
{
	return (new(ctx) IntegerVariable(((int)this->value), ctx));
}
LongVariable* LongVariable::toLongVariable(ThreadContext* ctx)
{
	return static_cast<LongVariable*>(copy(ctx));
}
StringVariable* LongVariable::toStringVariable(ThreadContext* ctx)
{
	return (new(ctx) StringVariable(getStringValue(ctx), ctx));
}
BigDecimalVariable* LongVariable::toBigDecimalVariable(ThreadContext* ctx)
{
	BigDecimal* dec = (new(ctx) BigDecimal(this->value, ctx));
	return (new(ctx) BigDecimalVariable(dec, ctx));
}
long long LongVariable::getLongValue(ThreadContext* ctx)
{
	return this->value;
}
FloatVariable* LongVariable::toFloatVariable(ThreadContext* ctx)
{
	return (new(ctx) FloatVariable(this->value, ctx));
}
DoubleVariable* LongVariable::toDoubleVariable(ThreadContext* ctx)
{
	return (new(ctx) DoubleVariable(this->value, ctx));
}
TimeVariable* LongVariable::toTimeVariable(ThreadContext* ctx)
{
	TimeOnlyTimestamp* tm = (new(ctx) TimeOnlyTimestamp(this->value, ctx));
	return (new(ctx) TimeVariable(tm, ctx));
}
TimestampVariable* LongVariable::toTimestampVariable(ThreadContext* ctx)
{
	Timestamp* tm = (new(ctx) Timestamp(this->value, ctx));
	return (new(ctx) TimestampVariable(tm, ctx));
}
IAlinousVariable* LongVariable::add(TimeVariable* variable, ThreadContext* ctx)
{
	this->value = this->value + variable->getValue(ctx)->getTime(ctx);
	return this;
}
IAlinousVariable* LongVariable::add(TimestampVariable* variable, ThreadContext* ctx)
{
	this->value = this->value + variable->getValue(ctx)->getTime(ctx);
	return this;
}
IAlinousVariable* LongVariable::minus(TimeVariable* variable, ThreadContext* ctx)
{
	this->value = this->value - variable->getValue(ctx)->getTime(ctx);
	return this;
}
IAlinousVariable* LongVariable::minus(TimestampVariable* variable, ThreadContext* ctx)
{
	this->value = this->value - variable->getValue(ctx)->getTime(ctx);
	return this;
}
IAlinousVariable* LongVariable::multiply(TimeVariable* variable, ThreadContext* ctx)
{
	this->value = this->value * variable->getValue(ctx)->getTime(ctx);
	return this;
}
IAlinousVariable* LongVariable::multiply(TimestampVariable* variable, ThreadContext* ctx)
{
	this->value = this->value * variable->getValue(ctx)->getTime(ctx);
	return this;
}
IAlinousVariable* LongVariable::div(TimeVariable* variable, ThreadContext* ctx)
{
	this->value = this->value / variable->getValue(ctx)->getTime(ctx);
	return this;
}
IAlinousVariable* LongVariable::div(TimestampVariable* variable, ThreadContext* ctx)
{
	this->value = this->value / variable->getValue(ctx)->getTime(ctx);
	return this;
}
IAlinousVariable* LongVariable::shiftLeft(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1134(), ctx));
}
IAlinousVariable* LongVariable::shiftLeft(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1134(), ctx));
}
IAlinousVariable* LongVariable::shiftRight(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1134(), ctx));
}
IAlinousVariable* LongVariable::shiftRight(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1134(), ctx));
}
IAlinousVariable* LongVariable::shiftRightUnsigned(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1134(), ctx));
}
IAlinousVariable* LongVariable::shiftRightUnsigned(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1134(), ctx));
}
IAlinousVariable* LongVariable::modulo(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1134(), ctx));
}
IAlinousVariable* LongVariable::modulo(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1134(), ctx));
}
IAlinousVariable* LongVariable::bitOr(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1134(), ctx));
}
IAlinousVariable* LongVariable::bitOr(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1134(), ctx));
}
IAlinousVariable* LongVariable::bitAnd(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1134(), ctx));
}
IAlinousVariable* LongVariable::bitAnd(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1134(), ctx));
}
IAlinousVariable* LongVariable::bitExor(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1134(), ctx));
}
IAlinousVariable* LongVariable::bitExor(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1134(), ctx));
}
IAlinousVariable* LongVariable::substitute(TimeVariable* variable, ThreadContext* ctx)
{
	this->value = variable->getValue(ctx)->getTime(ctx);
	return this;
}
IAlinousVariable* LongVariable::substitute(TimestampVariable* variable, ThreadContext* ctx)
{
	this->value = variable->getValue(ctx)->getTime(ctx);
	return this;
}
int LongVariable::compareTo(TimeVariable* variable, ThreadContext* ctx)
{
	return ((int)(this->value - variable->getValue(ctx)->getTime(ctx)));
}
int LongVariable::compareTo(TimestampVariable* variable, ThreadContext* ctx)
{
	return ((int)(this->value - variable->getValue(ctx)->getTime(ctx)));
}
IAlinousVariable* LongVariable::substitute(TypedVariableArray* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1124(), ctx));
}
void LongVariable::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	this->value = buff->getLong(ctx);
}
void LongVariable::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putInt(ICommandData::__LongVariable, ctx);
	buff->putLong(this->value, ctx);
}
LongVariable* LongVariable::fromDebugXml(DomNode* node, ThreadContext* ctx) throw() 
{
	IVariableValue* attrVal = node->getAttributeValue(VAL_TYPE, ctx);
	if(attrVal == nullptr)
	{
		return nullptr;
	}
	String* str = attrVal->toString(ctx);
	long long value = 0;
	{
		try
		{
			value = Long::parseLong(str, ctx);
		}
		catch(Throwable* e)
		{
			e->printStackTrace(ctx);
			return nullptr;
		}
	}
	return (new(ctx) LongVariable(value, ctx));
}
int LongVariable::ValueCompare::operator() (VariantValue* _this, VariantValue* variable, ThreadContext* ctx) const throw()
{
	return _this->compareTo(variable, ctx);
}
}}}}

