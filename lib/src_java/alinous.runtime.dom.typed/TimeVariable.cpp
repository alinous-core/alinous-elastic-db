#include "includes.h"


namespace alinous {namespace runtime {namespace dom {namespace typed {





String* TimeVariable::VAL_TYPE = ConstStr::getCNST_STR_1070();
bool TimeVariable::__init_done = __init_static_variables();
bool TimeVariable::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"TimeVariable", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 TimeVariable::TimeVariable(TimeOnlyTimestamp* time, ThreadContext* ctx) throw()  : IObject(ctx), AbstractTypedVariable(ctx), value(nullptr)
{
	__GC_MV(this, &(this->value), time, TimeOnlyTimestamp);
}
void TimeVariable::__construct_impl(TimeOnlyTimestamp* time, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->value), time, TimeOnlyTimestamp);
}
 TimeVariable::~TimeVariable() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void TimeVariable::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"TimeVariable", L"~TimeVariable");
	__e_obj1.add(this->value, this);
	value = nullptr;
	if(!prepare){
		return;
	}
	AbstractTypedVariable::__releaseRegerences(true, ctx);
}
void TimeVariable::outDebugXml(DomNode* parentNode, String* name, ThreadContext* ctx) throw() 
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
int TimeVariable::getVariableClass(ThreadContext* ctx) throw() 
{
	return IAlinousVariable::CLASS_TYPED;
}
int TimeVariable::getTypedType(ThreadContext* ctx) throw() 
{
	return ITypedVariable::TYPE_TIME;
}
TimeOnlyTimestamp* TimeVariable::getValue(ThreadContext* ctx) throw() 
{
	return value;
}
void TimeVariable::setValue(TimeOnlyTimestamp* value, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->value), value, TimeOnlyTimestamp);
}
VariantValue* TimeVariable::toVariantValue(ThreadContext* ctx)
{
	return (new(ctx) VariantValue(this->value, ctx));
}
IDomVariable* TimeVariable::toDomVariable(ThreadContext* ctx) throw() 
{
	VariantValue* value = (new(ctx) VariantValue(this->value, ctx));
	DomVariable* dom = (new(ctx) DomVariable(ctx));
	dom->setValue(value, ctx);
	return dom;
}
IAlinousVariable* TimeVariable::copy(ThreadContext* ctx)
{
	return nullptr;
}
bool TimeVariable::isNull(ThreadContext* ctx) throw() 
{
	return this->value == nullptr;
}
bool TimeVariable::isArray(ThreadContext* ctx) throw() 
{
	return false;
}
BoolVariable* TimeVariable::toBoolVariable(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1065(), ctx));
}
ByteVariable* TimeVariable::toByteVariable(ThreadContext* ctx)
{
	return (new(ctx) ByteVariable(((char)this->value->getTime(ctx)), ctx));
}
CharVariable* TimeVariable::toCharVariable(ThreadContext* ctx)
{
	return (new(ctx) CharVariable(((wchar_t)this->value->getTime(ctx)), ctx));
}
ShortVariable* TimeVariable::toShortVariable(ThreadContext* ctx)
{
	return (new(ctx) ShortVariable(((short)this->value->getTime(ctx)), ctx));
}
IntegerVariable* TimeVariable::toIntVariable(ThreadContext* ctx)
{
	return (new(ctx) IntegerVariable(((int)this->value->getTime(ctx)), ctx));
}
LongVariable* TimeVariable::toLongVariable(ThreadContext* ctx)
{
	return (new(ctx) LongVariable(this->value->getTime(ctx), ctx));
}
StringVariable* TimeVariable::toStringVariable(ThreadContext* ctx)
{
	return (new(ctx) StringVariable(this->value->toString(ctx), ctx));
}
FloatVariable* TimeVariable::toFloatVariable(ThreadContext* ctx)
{
	return (new(ctx) FloatVariable(this->value->getTime(ctx), ctx));
}
DoubleVariable* TimeVariable::toDoubleVariable(ThreadContext* ctx)
{
	return (new(ctx) DoubleVariable(this->value->getTime(ctx), ctx));
}
BigDecimalVariable* TimeVariable::toBigDecimalVariable(ThreadContext* ctx)
{
	return (new(ctx) BigDecimalVariable((new(ctx) BigDecimal(this->value->getTime(ctx), ctx)), ctx));
}
TimeVariable* TimeVariable::toTimeVariable(ThreadContext* ctx)
{
	return (new(ctx) TimeVariable((new(ctx) TimeOnlyTimestamp(this->value->getTime(ctx), ctx)), ctx));
}
TimestampVariable* TimeVariable::toTimestampVariable(ThreadContext* ctx)
{
	return (new(ctx) TimestampVariable((new(ctx) Timestamp(this->value->getTime(ctx), ctx)), ctx));
}
int TimeVariable::getIntValue(ThreadContext* ctx)
{
	return ((int)this->value->getTime(ctx));
}
long long TimeVariable::getLongValue(ThreadContext* ctx)
{
	return this->value->getTime(ctx);
}
String* TimeVariable::getStringValue(ThreadContext* ctx)
{
	return this->value->toString(ctx);
}
IAlinousVariable* TimeVariable::add(VariantValue* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) TimeOnlyTimestamp(this->value->getTime(ctx) + variable->getLong(ctx), ctx)), TimeOnlyTimestamp);
	return this;
}
IAlinousVariable* TimeVariable::add(DomVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) TimeOnlyTimestamp(this->value->getTime(ctx) + variable->getValue(ctx)->getLong(ctx), ctx)), TimeOnlyTimestamp);
	return this;
}
IAlinousVariable* TimeVariable::add(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1065(), ctx));
}
IAlinousVariable* TimeVariable::add(ByteVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) TimeOnlyTimestamp(this->value->getTime(ctx) + variable->getValue(ctx), ctx)), TimeOnlyTimestamp);
	return this;
}
IAlinousVariable* TimeVariable::add(CharVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) TimeOnlyTimestamp(this->value->getTime(ctx) + variable->getValue(ctx), ctx)), TimeOnlyTimestamp);
	return this;
}
IAlinousVariable* TimeVariable::add(DoubleVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) TimeOnlyTimestamp(((long long)(this->value->getTime(ctx) + variable->getValue(ctx))), ctx)), TimeOnlyTimestamp);
	return this;
}
IAlinousVariable* TimeVariable::add(FloatVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) TimeOnlyTimestamp(((long long)(this->value->getTime(ctx) + variable->getValue(ctx))), ctx)), TimeOnlyTimestamp);
	return this;
}
IAlinousVariable* TimeVariable::add(IntegerVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) TimeOnlyTimestamp(((long long)(this->value->getTime(ctx) + variable->getValue(ctx))), ctx)), TimeOnlyTimestamp);
	return this;
}
IAlinousVariable* TimeVariable::add(LongVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) TimeOnlyTimestamp(((long long)(this->value->getTime(ctx) + variable->getValue(ctx))), ctx)), TimeOnlyTimestamp);
	return this;
}
IAlinousVariable* TimeVariable::add(ShortVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) TimeOnlyTimestamp(((long long)(this->value->getTime(ctx) + variable->getValue(ctx))), ctx)), TimeOnlyTimestamp);
	return this;
}
IAlinousVariable* TimeVariable::add(StringVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) TimeOnlyTimestamp(((long long)(this->value->getTime(ctx) + variable->toTimeVariable(ctx)->getValue(ctx)->getTime(ctx))), ctx)), TimeOnlyTimestamp);
	return this;
}
IAlinousVariable* TimeVariable::add(BigDecimalVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) TimeOnlyTimestamp(this->value->getTime(ctx) + variable->getValue(ctx)->longValue(ctx), ctx)), TimeOnlyTimestamp);
	return this;
}
IAlinousVariable* TimeVariable::add(TimeVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) TimeOnlyTimestamp(this->value->getTime(ctx) + variable->getValue(ctx)->getTime(ctx), ctx)), TimeOnlyTimestamp);
	return this;
}
IAlinousVariable* TimeVariable::add(TimestampVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) TimeOnlyTimestamp(this->value->getTime(ctx) + variable->getValue(ctx)->getTime(ctx), ctx)), TimeOnlyTimestamp);
	return this;
}
IAlinousVariable* TimeVariable::minus(VariantValue* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) TimeOnlyTimestamp(this->value->getTime(ctx) - variable->getLong(ctx), ctx)), TimeOnlyTimestamp);
	return this;
}
IAlinousVariable* TimeVariable::minus(DomVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) TimeOnlyTimestamp(this->value->getTime(ctx) - variable->getValue(ctx)->getLong(ctx), ctx)), TimeOnlyTimestamp);
	return this;
}
IAlinousVariable* TimeVariable::minus(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1065(), ctx));
}
IAlinousVariable* TimeVariable::minus(ByteVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) TimeOnlyTimestamp(this->value->getTime(ctx) - variable->getValue(ctx), ctx)), TimeOnlyTimestamp);
	return this;
}
IAlinousVariable* TimeVariable::minus(CharVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) TimeOnlyTimestamp(this->value->getTime(ctx) - variable->getValue(ctx), ctx)), TimeOnlyTimestamp);
	return this;
}
IAlinousVariable* TimeVariable::minus(DoubleVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) TimeOnlyTimestamp(((long long)(this->value->getTime(ctx) - variable->getValue(ctx))), ctx)), TimeOnlyTimestamp);
	return this;
}
IAlinousVariable* TimeVariable::minus(FloatVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) TimeOnlyTimestamp(((long long)(this->value->getTime(ctx) - variable->getValue(ctx))), ctx)), TimeOnlyTimestamp);
	return this;
}
IAlinousVariable* TimeVariable::minus(IntegerVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) TimeOnlyTimestamp(((long long)(this->value->getTime(ctx) - variable->getValue(ctx))), ctx)), TimeOnlyTimestamp);
	return this;
}
IAlinousVariable* TimeVariable::minus(LongVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) TimeOnlyTimestamp(((long long)(this->value->getTime(ctx) - variable->getValue(ctx))), ctx)), TimeOnlyTimestamp);
	return this;
}
IAlinousVariable* TimeVariable::minus(ShortVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) TimeOnlyTimestamp(((long long)(this->value->getTime(ctx) - variable->getValue(ctx))), ctx)), TimeOnlyTimestamp);
	return this;
}
IAlinousVariable* TimeVariable::minus(StringVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) TimeOnlyTimestamp(((long long)(this->value->getTime(ctx) - variable->toTimestampVariable(ctx)->getValue(ctx)->getTime(ctx))), ctx)), TimeOnlyTimestamp);
	return this;
}
IAlinousVariable* TimeVariable::minus(BigDecimalVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) TimeOnlyTimestamp(this->value->getTime(ctx) - variable->getValue(ctx)->longValue(ctx), ctx)), TimeOnlyTimestamp);
	return this;
}
IAlinousVariable* TimeVariable::minus(TimeVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) TimeOnlyTimestamp(this->value->getTime(ctx) - variable->getValue(ctx)->getTime(ctx), ctx)), TimeOnlyTimestamp);
	return this;
}
IAlinousVariable* TimeVariable::minus(TimestampVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) TimeOnlyTimestamp(this->value->getTime(ctx) - variable->getValue(ctx)->getTime(ctx), ctx)), TimeOnlyTimestamp);
	return this;
}
IAlinousVariable* TimeVariable::div(VariantValue* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) TimeOnlyTimestamp(this->value->getTime(ctx) / variable->getLong(ctx), ctx)), TimeOnlyTimestamp);
	return this;
}
IAlinousVariable* TimeVariable::div(DomVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) TimeOnlyTimestamp(this->value->getTime(ctx) / variable->getValue(ctx)->getLong(ctx), ctx)), TimeOnlyTimestamp);
	return this;
}
IAlinousVariable* TimeVariable::div(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1065(), ctx));
}
IAlinousVariable* TimeVariable::div(ByteVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) TimeOnlyTimestamp(this->value->getTime(ctx) / variable->getValue(ctx), ctx)), TimeOnlyTimestamp);
	return this;
}
IAlinousVariable* TimeVariable::div(CharVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) TimeOnlyTimestamp(this->value->getTime(ctx) / variable->getValue(ctx), ctx)), TimeOnlyTimestamp);
	return this;
}
IAlinousVariable* TimeVariable::div(DoubleVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) TimeOnlyTimestamp(((long long)(this->value->getTime(ctx) / variable->getValue(ctx))), ctx)), TimeOnlyTimestamp);
	return this;
}
IAlinousVariable* TimeVariable::div(FloatVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) TimeOnlyTimestamp(((long long)(this->value->getTime(ctx) / variable->getValue(ctx))), ctx)), TimeOnlyTimestamp);
	return this;
}
IAlinousVariable* TimeVariable::div(IntegerVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) TimeOnlyTimestamp(((long long)(this->value->getTime(ctx) / variable->getValue(ctx))), ctx)), TimeOnlyTimestamp);
	return this;
}
IAlinousVariable* TimeVariable::div(LongVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) TimeOnlyTimestamp(((long long)(this->value->getTime(ctx) / variable->getValue(ctx))), ctx)), TimeOnlyTimestamp);
	return this;
}
IAlinousVariable* TimeVariable::div(ShortVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) TimeOnlyTimestamp(((long long)(this->value->getTime(ctx) / variable->getValue(ctx))), ctx)), TimeOnlyTimestamp);
	return this;
}
IAlinousVariable* TimeVariable::div(StringVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) TimeOnlyTimestamp(((long long)(this->value->getTime(ctx) / variable->toTimestampVariable(ctx)->getValue(ctx)->getTime(ctx))), ctx)), TimeOnlyTimestamp);
	return this;
}
IAlinousVariable* TimeVariable::div(BigDecimalVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) TimeOnlyTimestamp(this->value->getTime(ctx) / variable->getValue(ctx)->longValue(ctx), ctx)), TimeOnlyTimestamp);
	return this;
}
IAlinousVariable* TimeVariable::div(TimeVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) TimeOnlyTimestamp(this->value->getTime(ctx) / variable->getValue(ctx)->getTime(ctx), ctx)), TimeOnlyTimestamp);
	return this;
}
IAlinousVariable* TimeVariable::div(TimestampVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) TimeOnlyTimestamp(this->value->getTime(ctx) / variable->getValue(ctx)->getTime(ctx), ctx)), TimeOnlyTimestamp);
	return this;
}
IAlinousVariable* TimeVariable::multiply(VariantValue* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) TimeOnlyTimestamp(this->value->getTime(ctx) * variable->getLong(ctx), ctx)), TimeOnlyTimestamp);
	return this;
}
IAlinousVariable* TimeVariable::multiply(DomVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) TimeOnlyTimestamp(this->value->getTime(ctx) * variable->getValue(ctx)->getLong(ctx), ctx)), TimeOnlyTimestamp);
	return this;
}
IAlinousVariable* TimeVariable::multiply(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1065(), ctx));
}
IAlinousVariable* TimeVariable::multiply(ByteVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) TimeOnlyTimestamp(this->value->getTime(ctx) * variable->getValue(ctx), ctx)), TimeOnlyTimestamp);
	return this;
}
IAlinousVariable* TimeVariable::multiply(CharVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) TimeOnlyTimestamp(this->value->getTime(ctx) * variable->getValue(ctx), ctx)), TimeOnlyTimestamp);
	return this;
}
IAlinousVariable* TimeVariable::multiply(DoubleVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) TimeOnlyTimestamp(((long long)(this->value->getTime(ctx) * variable->getValue(ctx))), ctx)), TimeOnlyTimestamp);
	return this;
}
IAlinousVariable* TimeVariable::multiply(FloatVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) TimeOnlyTimestamp(((long long)(this->value->getTime(ctx) * variable->getValue(ctx))), ctx)), TimeOnlyTimestamp);
	return this;
}
IAlinousVariable* TimeVariable::multiply(IntegerVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) TimeOnlyTimestamp(((long long)(this->value->getTime(ctx) * variable->getValue(ctx))), ctx)), TimeOnlyTimestamp);
	return this;
}
IAlinousVariable* TimeVariable::multiply(LongVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) TimeOnlyTimestamp(((long long)(this->value->getTime(ctx) * variable->getValue(ctx))), ctx)), TimeOnlyTimestamp);
	return this;
}
IAlinousVariable* TimeVariable::multiply(ShortVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) TimeOnlyTimestamp(((long long)(this->value->getTime(ctx) * variable->getValue(ctx))), ctx)), TimeOnlyTimestamp);
	return this;
}
IAlinousVariable* TimeVariable::multiply(StringVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) TimeOnlyTimestamp(((long long)(this->value->getTime(ctx) * variable->toTimestampVariable(ctx)->getValue(ctx)->getTime(ctx))), ctx)), TimeOnlyTimestamp);
	return this;
}
IAlinousVariable* TimeVariable::multiply(BigDecimalVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) TimeOnlyTimestamp(this->value->getTime(ctx) * variable->getValue(ctx)->longValue(ctx), ctx)), TimeOnlyTimestamp);
	return this;
}
IAlinousVariable* TimeVariable::multiply(TimeVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) TimeOnlyTimestamp(this->value->getTime(ctx) * variable->getValue(ctx)->getTime(ctx), ctx)), TimeOnlyTimestamp);
	return this;
}
IAlinousVariable* TimeVariable::multiply(TimestampVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) TimeOnlyTimestamp(this->value->getTime(ctx) * variable->getValue(ctx)->getTime(ctx), ctx)), TimeOnlyTimestamp);
	return this;
}
IAlinousVariable* TimeVariable::substitute(VariantValue* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) TimeOnlyTimestamp(variable->getLong(ctx), ctx)), TimeOnlyTimestamp);
	return this;
}
IAlinousVariable* TimeVariable::substitute(DomVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) TimeOnlyTimestamp(variable->getValue(ctx)->getLong(ctx), ctx)), TimeOnlyTimestamp);
	return this;
}
IAlinousVariable* TimeVariable::substitute(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1065(), ctx));
}
IAlinousVariable* TimeVariable::substitute(ByteVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) TimeOnlyTimestamp(variable->getValue(ctx), ctx)), TimeOnlyTimestamp);
	return this;
}
IAlinousVariable* TimeVariable::substitute(CharVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) TimeOnlyTimestamp(variable->getValue(ctx), ctx)), TimeOnlyTimestamp);
	return this;
}
IAlinousVariable* TimeVariable::substitute(DoubleVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) TimeOnlyTimestamp(((long long)variable->getValue(ctx)), ctx)), TimeOnlyTimestamp);
	return this;
}
IAlinousVariable* TimeVariable::substitute(FloatVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) TimeOnlyTimestamp(((long long)variable->getValue(ctx)), ctx)), TimeOnlyTimestamp);
	return this;
}
IAlinousVariable* TimeVariable::substitute(IntegerVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) TimeOnlyTimestamp(variable->getValue(ctx), ctx)), TimeOnlyTimestamp);
	return this;
}
IAlinousVariable* TimeVariable::substitute(LongVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) TimeOnlyTimestamp(variable->getValue(ctx), ctx)), TimeOnlyTimestamp);
	return this;
}
IAlinousVariable* TimeVariable::substitute(ShortVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) TimeOnlyTimestamp(variable->getValue(ctx), ctx)), TimeOnlyTimestamp);
	return this;
}
IAlinousVariable* TimeVariable::substitute(StringVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), variable->toTimeVariable(ctx)->getValue(ctx), TimeOnlyTimestamp);
	return this;
}
IAlinousVariable* TimeVariable::substitute(BigDecimalVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) TimeOnlyTimestamp(variable->getValue(ctx)->longValue(ctx), ctx)), TimeOnlyTimestamp);
	return this;
}
IAlinousVariable* TimeVariable::substitute(TimeVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), variable->getValue(ctx), TimeOnlyTimestamp);
	return nullptr;
}
IAlinousVariable* TimeVariable::substitute(TimestampVariable* variable, ThreadContext* ctx)
{
	__GC_MV(this, &(this->value), (new(ctx) TimeOnlyTimestamp(variable->getValue(ctx)->getTime(ctx), ctx)), TimeOnlyTimestamp);
	return this;
}
int TimeVariable::compareTo(VariantValue* variable, ThreadContext* ctx)
{
	return this->value->compareTo(variable->getTime(ctx), ctx);
}
int TimeVariable::compareTo(DomVariable* variable, ThreadContext* ctx)
{
	return this->value->compareTo(variable->getValue(ctx)->getTime(ctx), ctx);
}
int TimeVariable::compareTo(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1066(), ctx));
}
int TimeVariable::compareTo(ByteVariable* variable, ThreadContext* ctx)
{
	return this->value->compareTo(variable->toTimeVariable(ctx)->getValue(ctx), ctx);
}
int TimeVariable::compareTo(CharVariable* variable, ThreadContext* ctx)
{
	return this->value->compareTo(variable->toTimeVariable(ctx)->getValue(ctx), ctx);
}
int TimeVariable::compareTo(DoubleVariable* variable, ThreadContext* ctx)
{
	return this->value->compareTo(variable->toTimeVariable(ctx)->getValue(ctx), ctx);
}
int TimeVariable::compareTo(FloatVariable* variable, ThreadContext* ctx)
{
	return this->value->compareTo(variable->toTimeVariable(ctx)->getValue(ctx), ctx);
}
int TimeVariable::compareTo(IntegerVariable* variable, ThreadContext* ctx)
{
	return this->value->compareTo(variable->toTimeVariable(ctx)->getValue(ctx), ctx);
}
int TimeVariable::compareTo(LongVariable* variable, ThreadContext* ctx)
{
	return this->value->compareTo(variable->toTimeVariable(ctx)->getValue(ctx), ctx);
}
int TimeVariable::compareTo(ShortVariable* variable, ThreadContext* ctx)
{
	return this->value->compareTo(variable->toTimeVariable(ctx)->getValue(ctx), ctx);
}
int TimeVariable::compareTo(StringVariable* variable, ThreadContext* ctx)
{
	return this->value->compareTo(variable->toTimeVariable(ctx)->getValue(ctx), ctx);
}
int TimeVariable::compareTo(BigDecimalVariable* variable, ThreadContext* ctx)
{
	return this->value->compareTo(variable->toTimeVariable(ctx)->getValue(ctx), ctx);
}
int TimeVariable::compareTo(TimeVariable* variable, ThreadContext* ctx)
{
	return this->value->compareTo(variable->toTimeVariable(ctx)->getValue(ctx), ctx);
}
int TimeVariable::compareTo(TimestampVariable* variable, ThreadContext* ctx)
{
	return this->value->compareTo(variable->toTimeVariable(ctx)->getValue(ctx), ctx);
}
bool TimeVariable::isTrue(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1067(), ctx));
}
IAlinousVariable* TimeVariable::shiftLeft(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::shiftLeft(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::shiftLeft(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::shiftLeft(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::shiftLeft(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::shiftLeft(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::shiftLeft(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::shiftLeft(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::shiftLeft(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::shiftLeft(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::shiftLeft(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::shiftLeft(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::shiftLeft(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::shiftLeft(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::shiftRight(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::shiftRight(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::shiftRight(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::shiftRight(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::shiftRight(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::shiftRight(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::shiftRight(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::shiftRight(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::shiftRight(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::shiftRight(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::shiftRight(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::shiftRight(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::shiftRight(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::shiftRight(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::shiftRightUnsigned(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::shiftRightUnsigned(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::shiftRightUnsigned(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::shiftRightUnsigned(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::shiftRightUnsigned(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::shiftRightUnsigned(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::shiftRightUnsigned(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::shiftRightUnsigned(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::shiftRightUnsigned(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::shiftRightUnsigned(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::shiftRightUnsigned(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::shiftRightUnsigned(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::shiftRightUnsigned(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::shiftRightUnsigned(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::modulo(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::modulo(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::modulo(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::modulo(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::modulo(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::modulo(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::modulo(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::modulo(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::modulo(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::modulo(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::modulo(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::modulo(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::modulo(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::modulo(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::bitOr(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::bitOr(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::bitOr(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::bitOr(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::bitOr(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::bitOr(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::bitOr(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::bitOr(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::bitOr(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::bitOr(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::bitOr(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::bitOr(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::bitOr(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::bitOr(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::bitAnd(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::bitAnd(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::bitAnd(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::bitAnd(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::bitAnd(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::bitAnd(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::bitAnd(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::bitAnd(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::bitAnd(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::bitAnd(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::bitAnd(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::bitAnd(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::bitAnd(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::bitAnd(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::bitExor(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::bitExor(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::bitExor(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::bitExor(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::bitExor(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::bitExor(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::bitExor(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::bitExor(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::bitExor(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::bitExor(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::bitExor(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::bitExor(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::bitExor(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::bitExor(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::bitReverse(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1068(), ctx));
}
IAlinousVariable* TimeVariable::substitute(TypedVariableArray* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1069(), ctx));
}
TimeVariable* TimeVariable::fromDebugXml(DomNode* node, ThreadContext* ctx) throw() 
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
	return (new(ctx) TimeVariable((new(ctx) TimeOnlyTimestamp(value, ctx)), ctx));
}
int TimeVariable::ValueCompare::operator() (VariantValue* _this, VariantValue* variable, ThreadContext* ctx) const throw()
{
	return _this->compareTo(variable, ctx);
}
}}}}

