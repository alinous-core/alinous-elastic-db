#include "includes.h"


namespace alinous {namespace runtime {namespace dom {namespace typed {





String* StringVariable::VAL_TYPE = ConstStr::getCNST_STR_1160();
bool StringVariable::__init_done = __init_static_variables();
bool StringVariable::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"StringVariable", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 StringVariable::StringVariable(String* value, ThreadContext* ctx) throw()  : IObject(ctx), AbstractTypedVariable(ctx), value(nullptr)
{
	__GC_MV(this, &(this->value), value, String);
}
void StringVariable::__construct_impl(String* value, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->value), value, String);
}
 StringVariable::~StringVariable() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void StringVariable::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"StringVariable", L"~StringVariable");
	__e_obj1.add(this->value, this);
	value = nullptr;
	if(!prepare){
		return;
	}
	AbstractTypedVariable::__releaseRegerences(true, ctx);
}
void StringVariable::outDebugXml(DomNode* parentNode, String* name, ThreadContext* ctx) throw() 
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
int StringVariable::getVariableClass(ThreadContext* ctx) throw() 
{
	return IAlinousVariable::CLASS_TYPED;
}
int StringVariable::getTypedType(ThreadContext* ctx) throw() 
{
	return ITypedVariable::TYPE_STRING;
}
String* StringVariable::getValue(ThreadContext* ctx) throw() 
{
	return value;
}
void StringVariable::setValue(String* value, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->value), value, String);
}
VariantValue* StringVariable::toVariantValue(ThreadContext* ctx)
{
	return (new(ctx) VariantValue(this->value, ctx));
}
int StringVariable::getIntValue(ThreadContext* ctx)
{
	return Integer::parseInt(this->value, ctx);
}
String* StringVariable::getStringValue(ThreadContext* ctx)
{
	return this->value;
}
IDomVariable* StringVariable::toDomVariable(ThreadContext* ctx) throw() 
{
	DomVariable* ret = (new(ctx) DomVariable(ctx));
	ret->setValue((new(ctx) VariantValue(this->value, ctx)), ctx);
	return ret;
}
IAlinousVariable* StringVariable::copy(ThreadContext* ctx)
{
	return (new(ctx) StringVariable(this->value, ctx));
}
IAlinousVariable* StringVariable::add(IAlinousVariable* variable, ThreadContext* ctx)
{
	return VariableOperationCaller::add(this, variable, ctx);
}
IAlinousVariable* StringVariable::add(VariantValue* variable, ThreadContext* ctx)
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	buff->append(this->value, ctx);
	buff->append(variable->getString(ctx), ctx);
	__GC_MV(this, &(this->value), buff->toString(ctx), String);
	return this;
}
IAlinousVariable* StringVariable::add(DomVariable* variable, ThreadContext* ctx)
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	buff->append(this->value, ctx);
	buff->append(variable->getValue(ctx)->getString(ctx), ctx);
	__GC_MV(this, &(this->value), buff->toString(ctx), String);
	return this;
}
IAlinousVariable* StringVariable::add(BoolVariable* variable, ThreadContext* ctx)
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	buff->append(this->value, ctx);
	buff->append(Boolean::toString(variable->isValue(ctx), ctx), ctx);
	__GC_MV(this, &(this->value), buff->toString(ctx), String);
	return this;
}
IAlinousVariable* StringVariable::add(ByteVariable* variable, ThreadContext* ctx)
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	buff->append(this->value, ctx);
	buff->append(Byte::toString(variable->getValue(ctx), ctx), ctx);
	__GC_MV(this, &(this->value), buff->toString(ctx), String);
	return this;
}
IAlinousVariable* StringVariable::add(CharVariable* variable, ThreadContext* ctx)
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	buff->append(this->value, ctx);
	buff->append(Character::toString(variable->getValue(ctx), ctx), ctx);
	__GC_MV(this, &(this->value), buff->toString(ctx), String);
	return this;
}
IAlinousVariable* StringVariable::add(DoubleVariable* variable, ThreadContext* ctx)
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	buff->append(this->value, ctx);
	buff->append(Double::toString(variable->getValue(ctx), ctx), ctx);
	__GC_MV(this, &(this->value), buff->toString(ctx), String);
	return this;
}
IAlinousVariable* StringVariable::add(FloatVariable* variable, ThreadContext* ctx)
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	buff->append(this->value, ctx);
	buff->append(Float::toString(variable->getValue(ctx), ctx), ctx);
	__GC_MV(this, &(this->value), buff->toString(ctx), String);
	return this;
}
IAlinousVariable* StringVariable::add(IntegerVariable* variable, ThreadContext* ctx)
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	buff->append(this->value, ctx);
	buff->append(Integer::toString(variable->getValue(ctx), ctx), ctx);
	__GC_MV(this, &(this->value), buff->toString(ctx), String);
	return this;
}
IAlinousVariable* StringVariable::add(ShortVariable* variable, ThreadContext* ctx)
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	buff->append(this->value, ctx);
	buff->append(Short::toString(variable->getValue(ctx), ctx), ctx);
	__GC_MV(this, &(this->value), buff->toString(ctx), String);
	return this;
}
IAlinousVariable* StringVariable::add(StringVariable* variable, ThreadContext* ctx)
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	buff->append(this->value, ctx);
	buff->append(variable->getValue(ctx), ctx);
	__GC_MV(this, &(this->value), buff->toString(ctx), String);
	return this;
}
IAlinousVariable* StringVariable::minus(IAlinousVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::minus(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::minus(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::minus(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::minus(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::minus(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::minus(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::minus(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::minus(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::minus(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::minus(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::multiply(IAlinousVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::multiply(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::multiply(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::multiply(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::multiply(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::multiply(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::multiply(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::multiply(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::multiply(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::multiply(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::multiply(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::div(IAlinousVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::div(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::div(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::div(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::div(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::div(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::div(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::div(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::div(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::div(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::div(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::bitReverse(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::add(LongVariable* variable, ThreadContext* ctx)
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	buff->append(this->value, ctx);
	buff->append(Long::toString(variable->getValue(ctx), ctx), ctx);
	__GC_MV(this, &(this->value), buff->toString(ctx), String);
	return this;
}
IAlinousVariable* StringVariable::minus(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::multiply(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::div(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
bool StringVariable::isNull(ThreadContext* ctx) throw() 
{
	return this->value == nullptr;
}
bool StringVariable::isArray(ThreadContext* ctx) throw() 
{
	return false;
}
IAlinousVariable* StringVariable::shiftLeft(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::shiftLeft(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::shiftLeft(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::shiftLeft(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::shiftLeft(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::shiftLeft(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::shiftLeft(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::shiftLeft(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::shiftLeft(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::shiftLeft(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::shiftLeft(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::shiftRight(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::shiftRight(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::shiftRight(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::shiftRight(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::shiftRight(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::shiftRight(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::shiftRight(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::shiftRight(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::shiftRight(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::shiftRight(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::shiftRight(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::modulo(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::modulo(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::modulo(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::modulo(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::modulo(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::modulo(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::modulo(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::modulo(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::modulo(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::modulo(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::modulo(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::substitute(VariantValue* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), variable->getString(ctx), String);
	return this;
}
IAlinousVariable* StringVariable::substitute(DomVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), variable->getValue(ctx)->getString(ctx), String);
	return this;
}
IAlinousVariable* StringVariable::substitute(BoolVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), Boolean::toString(variable->isValue(ctx), ctx), String);
	return this;
}
IAlinousVariable* StringVariable::substitute(ByteVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), Byte::toString(variable->getValue(ctx), ctx), String);
	return this;
}
IAlinousVariable* StringVariable::substitute(CharVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), Character::toString(variable->getValue(ctx), ctx), String);
	return this;
}
IAlinousVariable* StringVariable::substitute(DoubleVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), Double::toString(variable->getValue(ctx), ctx), String);
	return this;
}
IAlinousVariable* StringVariable::substitute(FloatVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), Double::toString((double)variable->getValue(ctx), ctx), String);
	return this;
}
IAlinousVariable* StringVariable::substitute(IntegerVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), Integer::toString(variable->getValue(ctx), ctx), String);
	return this;
}
IAlinousVariable* StringVariable::substitute(LongVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), Long::toString(variable->getValue(ctx), ctx), String);
	return this;
}
IAlinousVariable* StringVariable::substitute(ShortVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), Short::toString(variable->getValue(ctx), ctx), String);
	return this;
}
IAlinousVariable* StringVariable::substitute(StringVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), variable->getValue(ctx), String);
	return this;
}
int StringVariable::compareTo(VariantValue* variable, ThreadContext* ctx)
{
	return this->value->compareTo(variable->getString(ctx), ctx);
}
int StringVariable::compareTo(DomVariable* variable, ThreadContext* ctx)
{
	return this->value->compareTo(variable->getValue(ctx)->getString(ctx), ctx);
}
int StringVariable::compareTo(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1134(), ctx));
}
int StringVariable::compareTo(ByteVariable* variable, ThreadContext* ctx)
{
	return this->value->compareTo(Byte::toString(variable->getValue(ctx), ctx), ctx);
}
int StringVariable::compareTo(CharVariable* variable, ThreadContext* ctx)
{
	return this->value->compareTo(Character::toString(variable->getValue(ctx), ctx), ctx);
}
int StringVariable::compareTo(DoubleVariable* variable, ThreadContext* ctx)
{
	return this->value->compareTo(Double::toString(variable->getValue(ctx), ctx), ctx);
}
int StringVariable::compareTo(FloatVariable* variable, ThreadContext* ctx)
{
	return this->value->compareTo(Float::toString(variable->getValue(ctx), ctx), ctx);
}
int StringVariable::compareTo(IntegerVariable* variable, ThreadContext* ctx)
{
	return this->value->compareTo(Integer::toString(variable->getValue(ctx), ctx), ctx);
}
int StringVariable::compareTo(LongVariable* variable, ThreadContext* ctx)
{
	return this->value->compareTo(Long::toString(variable->getValue(ctx), ctx), ctx);
}
int StringVariable::compareTo(ShortVariable* variable, ThreadContext* ctx)
{
	return this->value->compareTo(Short::toString(variable->getValue(ctx), ctx), ctx);
}
int StringVariable::compareTo(StringVariable* variable, ThreadContext* ctx)
{
	return this->value->compareTo(variable->value, ctx);
}
bool StringVariable::isTrue(ThreadContext* ctx)
{
	return this->value != nullptr;
}
IAlinousVariable* StringVariable::bitOr(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::bitOr(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::bitOr(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::bitOr(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::bitOr(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::bitOr(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::bitOr(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::bitOr(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::bitOr(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::bitOr(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::bitOr(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::bitAnd(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::bitAnd(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::bitAnd(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::bitAnd(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::bitAnd(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::bitAnd(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::bitAnd(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::bitAnd(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::bitAnd(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::bitAnd(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::bitAnd(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::bitExor(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::bitExor(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::bitExor(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::bitExor(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::bitExor(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::bitExor(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::bitExor(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::bitExor(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::bitExor(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::bitExor(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::bitExor(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::add(BigDecimalVariable* variable, ThreadContext* ctx)
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	buff->append(this->value, ctx);
	buff->append(variable->toString(ctx), ctx);
	__GC_MV(this, &(this->value), buff->toString(ctx), String);
	return this;
}
IAlinousVariable* StringVariable::minus(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::multiply(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::div(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::shiftLeft(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::shiftRight(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::modulo(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::bitOr(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::bitAnd(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::bitExor(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::substitute(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
int StringVariable::compareTo(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::shiftRightUnsigned(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* StringVariable::shiftRightUnsigned(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* StringVariable::shiftRightUnsigned(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* StringVariable::shiftRightUnsigned(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* StringVariable::shiftRightUnsigned(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* StringVariable::shiftRightUnsigned(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* StringVariable::shiftRightUnsigned(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* StringVariable::shiftRightUnsigned(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* StringVariable::shiftRightUnsigned(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* StringVariable::shiftRightUnsigned(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* StringVariable::shiftRightUnsigned(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* StringVariable::shiftRightUnsigned(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
BoolVariable* StringVariable::toBoolVariable(ThreadContext* ctx)
{
	if(this->value->equalsIgnoreCase(ConstStr::getCNST_STR_372(), ctx))
	{
		return (new(ctx) BoolVariable(true, ctx));
	}
		else 
	{
		if(this->value->equalsIgnoreCase(ConstStr::getCNST_STR_1142(), ctx))
		{
			return (new(ctx) BoolVariable(false, ctx));
		}
	}
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1158(), ctx));
}
ByteVariable* StringVariable::toByteVariable(ThreadContext* ctx)
{
	{
		try
		{
			return (new(ctx) ByteVariable(Byte::parseByte(this->value, ctx), ctx));
		}
		catch(Throwable* e)
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1159(), e, ctx));
		}
	}
}
CharVariable* StringVariable::toCharVariable(ThreadContext* ctx)
{
	{
		try
		{
			return (new(ctx) CharVariable(((wchar_t)Short::parseShort(this->value, ctx)), ctx));
		}
		catch(Throwable* e)
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1159(), e, ctx));
		}
	}
}
ShortVariable* StringVariable::toShortVariable(ThreadContext* ctx)
{
	{
		try
		{
			return (new(ctx) ShortVariable(Short::parseShort(this->value, ctx), ctx));
		}
		catch(Throwable* e)
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1159(), e, ctx));
		}
	}
}
IntegerVariable* StringVariable::toIntVariable(ThreadContext* ctx)
{
	{
		try
		{
			return (new(ctx) IntegerVariable(Integer::parseInt(this->value, ctx), ctx));
		}
		catch(Throwable* e)
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1159(), e, ctx));
		}
	}
}
LongVariable* StringVariable::toLongVariable(ThreadContext* ctx)
{
	{
		try
		{
			return (new(ctx) LongVariable(Long::parseLong(this->value, ctx), ctx));
		}
		catch(Throwable* e)
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1159(), e, ctx));
		}
	}
}
StringVariable* StringVariable::toStringVariable(ThreadContext* ctx)
{
	return static_cast<StringVariable*>(copy(ctx));
}
BigDecimalVariable* StringVariable::toBigDecimalVariable(ThreadContext* ctx)
{
	{
		try
		{
			return (new(ctx) BigDecimalVariable((new(ctx) BigDecimal(this->value, ctx)), ctx));
		}
		catch(Throwable* e)
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1159(), e, ctx));
		}
	}
}
long long StringVariable::getLongValue(ThreadContext* ctx)
{
	{
		try
		{
			return Long::parseLong(this->value, ctx);
		}
		catch(Throwable* e)
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1159(), e, ctx));
		}
	}
}
FloatVariable* StringVariable::toFloatVariable(ThreadContext* ctx)
{
	{
		try
		{
			return (new(ctx) FloatVariable(Float::parseFloat(this->value, ctx), ctx));
		}
		catch(Throwable* e)
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1159(), e, ctx));
		}
	}
}
DoubleVariable* StringVariable::toDoubleVariable(ThreadContext* ctx)
{
	{
		try
		{
			return (new(ctx) DoubleVariable(Double::parseDouble(this->value, ctx), ctx));
		}
		catch(Throwable* e)
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1159(), e, ctx));
		}
	}
}
TimeVariable* StringVariable::toTimeVariable(ThreadContext* ctx)
{
	return (new(ctx) TimeVariable(TimeOnlyTimestamp::valueOf(this->value, ctx), ctx));
}
TimestampVariable* StringVariable::toTimestampVariable(ThreadContext* ctx)
{
	return (new(ctx) TimestampVariable(Timestamp::valueOf(this->value, ctx), ctx));
}
IAlinousVariable* StringVariable::add(TimeVariable* variable, ThreadContext* ctx)
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	buff->append(this->value, ctx)->append(variable->getValue(ctx)->toString(ctx), ctx);
	__GC_MV(this, &(this->value), buff->toString(ctx), String);
	return this;
}
IAlinousVariable* StringVariable::add(TimestampVariable* variable, ThreadContext* ctx)
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	buff->append(this->value, ctx)->append(variable->getValue(ctx)->toString(ctx), ctx);
	__GC_MV(this, &(this->value), buff->toString(ctx), String);
	return this;
}
IAlinousVariable* StringVariable::minus(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::minus(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::multiply(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::multiply(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::div(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::div(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::shiftLeft(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::shiftLeft(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::shiftRight(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::shiftRight(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::shiftRightUnsigned(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::shiftRightUnsigned(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::modulo(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::modulo(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::bitOr(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::bitOr(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::bitAnd(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::bitAnd(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::bitExor(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::bitExor(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1135(), ctx));
}
IAlinousVariable* StringVariable::substitute(TimeVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), variable->getValue(ctx)->toString(ctx), String);
	return this;
}
IAlinousVariable* StringVariable::substitute(TimestampVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), variable->getValue(ctx)->toString(ctx), String);
	return this;
}
int StringVariable::compareTo(TimeVariable* variable, ThreadContext* ctx)
{
	return this->value->compareTo(variable->getStringValue(ctx), ctx);
}
int StringVariable::compareTo(TimestampVariable* variable, ThreadContext* ctx)
{
	return this->value->compareTo(variable->getStringValue(ctx), ctx);
}
IAlinousVariable* StringVariable::substitute(TypedVariableArray* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1129(), ctx));
}
void StringVariable::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	char nullbl = buff->getByte(ctx);
	if(nullbl == (char)0)
	{
		return;
	}
	__GC_MV(this, &(this->value), buff->getString(ctx), String);
}
void StringVariable::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putInt(ICommandData::__StringVariable, ctx);
	char nullbl = ((char)(isNull(ctx) ? 0 : 1));
	buff->putByte(nullbl, ctx);
	if(nullbl == (char)0)
	{
		return;
	}
	buff->putString(this->value, ctx);
}
StringVariable* StringVariable::fromDebugXml(DomNode* node, ThreadContext* ctx) throw() 
{
	IVariableValue* attrVal = node->getAttributeValue(VAL_TYPE, ctx);
	if(attrVal == nullptr)
	{
		return nullptr;
	}
	String* str = attrVal->toString(ctx);
	return (new(ctx) StringVariable(str, ctx));
}
int StringVariable::ValueCompare::operator() (VariantValue* _this, VariantValue* variable, ThreadContext* ctx) const throw()
{
	return _this->compareTo(variable, ctx);
}
}}}}

