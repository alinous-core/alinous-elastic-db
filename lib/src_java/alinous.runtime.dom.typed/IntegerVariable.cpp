#include "include/global.h"


#include "alinous.numeric/InternalDate.h"
#include "alinous.numeric/TimeOnlyTimestamp.h"
#include "java.sql/Timestamp.h"
#include "alinous.html.xpath/IVariableValue.h"
#include "alinous.html/IDomObject.h"
#include "alinous.html/DomNode.h"
#include "alinous.html/Attribute.h"
#include "java.lang/Number.h"
#include "java.lang/Comparable.h"
#include "alinous.numeric/BigDecimal.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.system/AlinousException.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.runtime.dom/IDomVariableContainer.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.dom/IDomVariable.h"
#include "alinous.runtime.dom.typed/ITypedVariable.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile.expression/DomVariableDescriptor.h"
#include "alinous.runtime.dom.typed/ITypedCaller.h"
#include "alinous.runtime.dom.typed/AbstractTypedVariable.h"
#include "alinous.runtime.dom.typed/TypedVariableArray.h"
#include "alinous.runtime.dom.typed/TimestampVariable.h"
#include "alinous.runtime.dom.typed/TimeVariable.h"
#include "alinous.runtime.dom.typed/ShortVariable.h"
#include "alinous.runtime.dom.typed/LongVariable.h"
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
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile/Token.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.runtime.dom.typed/IntegerVariable.h"

namespace alinous {namespace runtime {namespace dom {namespace typed {





String* IntegerVariable::VAL_TYPE = ConstStr::getCNST_STR_1222();
bool IntegerVariable::__init_done = __init_static_variables();
bool IntegerVariable::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"IntegerVariable", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 IntegerVariable::IntegerVariable(ThreadContext* ctx) throw()  : IObject(ctx), AbstractTypedVariable(ctx), value(0)
{
}
void IntegerVariable::__construct_impl(ThreadContext* ctx) throw() 
{
}
 IntegerVariable::IntegerVariable(int value, ThreadContext* ctx) throw()  : IObject(ctx), AbstractTypedVariable(ctx), value(0)
{
	this->value = value;
}
void IntegerVariable::__construct_impl(int value, ThreadContext* ctx) throw() 
{
	this->value = value;
}
 IntegerVariable::~IntegerVariable() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void IntegerVariable::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"IntegerVariable", L"~IntegerVariable");
	if(!prepare){
		return;
	}
	AbstractTypedVariable::__releaseRegerences(true, ctx);
}
void IntegerVariable::outDebugXml(DomNode* parentNode, String* name, ThreadContext* ctx) throw() 
{
	DomNode* node = (new(ctx) DomNode(VAL_TYPE, ctx));
	parentNode->addChild(node, ctx);
	if(name != nullptr)
	{
		Attribute* nameattr = (new(ctx) Attribute(IAlinousVariable::ATTR_NAME, name, node, ctx));
		node->addAttribute(nameattr, ctx);
	}
	Attribute* attr = (new(ctx) Attribute(AbstractTypedVariable::VALUE, Integer::toString(this->value, ctx), node, ctx));
	parentNode->addAttribute(attr, ctx);
}
int IntegerVariable::getVariableClass(ThreadContext* ctx) throw() 
{
	return IAlinousVariable::CLASS_TYPED;
}
int IntegerVariable::getTypedType(ThreadContext* ctx) throw() 
{
	return ITypedVariable::TYPE_INT;
}
VariantValue* IntegerVariable::toVariantValue(ThreadContext* ctx)
{
	return (new(ctx) VariantValue(this->value, ctx));
}
int IntegerVariable::getIntValue(ThreadContext* ctx)
{
	return this->value;
}
String* IntegerVariable::getStringValue(ThreadContext* ctx)
{
	return Integer::toString(this->value, ctx);
}
int IntegerVariable::getValue(ThreadContext* ctx) throw() 
{
	return value;
}
void IntegerVariable::setValue(int value, ThreadContext* ctx) throw() 
{
	this->value = value;
}
IAlinousVariable* IntegerVariable::copy(ThreadContext* ctx)
{
	return (new(ctx) IntegerVariable(this->value, ctx));
}
IDomVariable* IntegerVariable::toDomVariable(ThreadContext* ctx) throw() 
{
	DomVariable* ret = (new(ctx) DomVariable(ctx));
	ret->setValue((new(ctx) VariantValue(this->value, ctx)), ctx);
	return ret;
}
IAlinousVariable* IntegerVariable::add(LongVariable* variable, ThreadContext* ctx)
{
	long long res = this->value + variable->getValue(ctx);
	return (new(ctx) LongVariable(res, ctx));
}
IAlinousVariable* IntegerVariable::minus(LongVariable* variable, ThreadContext* ctx)
{
	long long res = this->value - variable->getValue(ctx);
	return (new(ctx) LongVariable(res, ctx));
}
IAlinousVariable* IntegerVariable::multiply(LongVariable* variable, ThreadContext* ctx)
{
	long long res = this->value * variable->getValue(ctx);
	return (new(ctx) LongVariable(res, ctx));
}
IAlinousVariable* IntegerVariable::div(LongVariable* variable, ThreadContext* ctx)
{
	long long res = this->value / variable->getValue(ctx);
	return (new(ctx) LongVariable(res, ctx));
}
IAlinousVariable* IntegerVariable::add(VariantValue* variable, ThreadContext* ctx)
{
	return variable->add(this, ctx)->copy(ctx);
}
IAlinousVariable* IntegerVariable::add(DomVariable* variable, ThreadContext* ctx)
{
	return variable->add(this, ctx)->copy(ctx);
}
IAlinousVariable* IntegerVariable::add(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1205(), ctx));
}
IAlinousVariable* IntegerVariable::add(ByteVariable* variable, ThreadContext* ctx)
{
	this->value = this->value + variable->getValue(ctx);
	return this;
}
IAlinousVariable* IntegerVariable::add(CharVariable* variable, ThreadContext* ctx)
{
	this->value = this->value + variable->getValue(ctx);
	return this;
}
IAlinousVariable* IntegerVariable::add(DoubleVariable* variable, ThreadContext* ctx)
{
	double res = this->value + variable->getValue(ctx);
	return (new(ctx) DoubleVariable(res, ctx));
}
IAlinousVariable* IntegerVariable::add(FloatVariable* variable, ThreadContext* ctx)
{
	float res = this->value + variable->getValue(ctx);
	return (new(ctx) FloatVariable(res, ctx));
}
IAlinousVariable* IntegerVariable::add(IntegerVariable* variable, ThreadContext* ctx)
{
	this->value = this->value + variable->getValue(ctx);
	return this;
}
IAlinousVariable* IntegerVariable::add(ShortVariable* variable, ThreadContext* ctx)
{
	this->value = this->value + variable->getValue(ctx);
	return this;
}
IAlinousVariable* IntegerVariable::add(StringVariable* variable, ThreadContext* ctx)
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	buff->append(Integer::toString(value, ctx), ctx);
	buff->append(variable->getValue(ctx), ctx);
	return (new(ctx) StringVariable(buff->toString(ctx), ctx));
}
IAlinousVariable* IntegerVariable::minus(VariantValue* variable, ThreadContext* ctx)
{
	return (new(ctx) VariantValue(this->value, ctx))->minus(variable, ctx);
}
IAlinousVariable* IntegerVariable::minus(DomVariable* variable, ThreadContext* ctx)
{
	return (new(ctx) VariantValue(this->value, ctx))->minus(variable, ctx);
}
IAlinousVariable* IntegerVariable::minus(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1205(), ctx));
}
IAlinousVariable* IntegerVariable::minus(ByteVariable* variable, ThreadContext* ctx)
{
	this->value = this->value - variable->getValue(ctx);
	return this;
}
IAlinousVariable* IntegerVariable::minus(CharVariable* variable, ThreadContext* ctx)
{
	this->value = this->value - variable->getValue(ctx);
	return this;
}
IAlinousVariable* IntegerVariable::minus(DoubleVariable* variable, ThreadContext* ctx)
{
	double res = this->value - variable->getValue(ctx);
	return (new(ctx) DoubleVariable(res, ctx));
}
IAlinousVariable* IntegerVariable::minus(FloatVariable* variable, ThreadContext* ctx)
{
	float res = this->value - variable->getValue(ctx);
	return (new(ctx) FloatVariable(res, ctx));
}
IAlinousVariable* IntegerVariable::minus(IntegerVariable* variable, ThreadContext* ctx)
{
	this->value = this->value - variable->getValue(ctx);
	return this;
}
IAlinousVariable* IntegerVariable::minus(ShortVariable* variable, ThreadContext* ctx)
{
	this->value = this->value - variable->getValue(ctx);
	return this;
}
IAlinousVariable* IntegerVariable::minus(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1206(), ctx));
}
IAlinousVariable* IntegerVariable::multiply(VariantValue* variable, ThreadContext* ctx)
{
	return variable->multiply(this, ctx)->copy(ctx);
}
IAlinousVariable* IntegerVariable::multiply(DomVariable* variable, ThreadContext* ctx)
{
	return variable->multiply(this, ctx)->copy(ctx);
}
IAlinousVariable* IntegerVariable::multiply(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1205(), ctx));
}
IAlinousVariable* IntegerVariable::multiply(ByteVariable* variable, ThreadContext* ctx)
{
	this->value = this->value * variable->getValue(ctx);
	return this;
}
IAlinousVariable* IntegerVariable::multiply(CharVariable* variable, ThreadContext* ctx)
{
	this->value = this->value * variable->getValue(ctx);
	return this;
}
IAlinousVariable* IntegerVariable::multiply(DoubleVariable* variable, ThreadContext* ctx)
{
	double res = this->value * variable->getValue(ctx);
	return (new(ctx) DoubleVariable(res, ctx));
}
IAlinousVariable* IntegerVariable::multiply(FloatVariable* variable, ThreadContext* ctx)
{
	float res = this->value * variable->getValue(ctx);
	return (new(ctx) FloatVariable(res, ctx));
}
IAlinousVariable* IntegerVariable::multiply(IntegerVariable* variable, ThreadContext* ctx)
{
	this->value = this->value * variable->getValue(ctx);
	return this;
}
IAlinousVariable* IntegerVariable::multiply(ShortVariable* variable, ThreadContext* ctx)
{
	this->value = this->value * variable->getValue(ctx);
	return this;
}
IAlinousVariable* IntegerVariable::multiply(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1206(), ctx));
}
IAlinousVariable* IntegerVariable::div(VariantValue* variable, ThreadContext* ctx)
{
	return (new(ctx) VariantValue(this->value, ctx))->div(variable, ctx);
}
IAlinousVariable* IntegerVariable::div(DomVariable* variable, ThreadContext* ctx)
{
	return (new(ctx) VariantValue(this->value, ctx))->div(variable, ctx);
}
IAlinousVariable* IntegerVariable::div(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1205(), ctx));
}
IAlinousVariable* IntegerVariable::div(ByteVariable* variable, ThreadContext* ctx)
{
	this->value = this->value / variable->getValue(ctx);
	return this;
}
IAlinousVariable* IntegerVariable::div(CharVariable* variable, ThreadContext* ctx)
{
	this->value = this->value / variable->getValue(ctx);
	return this;
}
IAlinousVariable* IntegerVariable::div(DoubleVariable* variable, ThreadContext* ctx)
{
	double res = this->value / variable->getValue(ctx);
	return (new(ctx) DoubleVariable(res, ctx));
}
IAlinousVariable* IntegerVariable::div(FloatVariable* variable, ThreadContext* ctx)
{
	float res = this->value / variable->getValue(ctx);
	return (new(ctx) FloatVariable(res, ctx));
}
IAlinousVariable* IntegerVariable::div(IntegerVariable* variable, ThreadContext* ctx)
{
	this->value = this->value / variable->getValue(ctx);
	return this;
}
IAlinousVariable* IntegerVariable::div(ShortVariable* variable, ThreadContext* ctx)
{
	this->value = this->value / variable->getValue(ctx);
	return this;
}
IAlinousVariable* IntegerVariable::div(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1206(), ctx));
}
IAlinousVariable* IntegerVariable::bitReverse(ThreadContext* ctx)
{
	this->value = ~this->value;
	return this;
}
bool IntegerVariable::isNull(ThreadContext* ctx) throw() 
{
	return false;
}
bool IntegerVariable::isArray(ThreadContext* ctx) throw() 
{
	return false;
}
IAlinousVariable* IntegerVariable::shiftLeft(VariantValue* variable, ThreadContext* ctx)
{
	this->value = this->value << variable->getInt(ctx);
	return this;
}
IAlinousVariable* IntegerVariable::shiftLeft(DomVariable* variable, ThreadContext* ctx)
{
	this->value = this->value << variable->getValue(ctx)->getInt(ctx);
	return this;
}
IAlinousVariable* IntegerVariable::shiftLeft(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1205(), ctx));
}
IAlinousVariable* IntegerVariable::shiftLeft(ByteVariable* variable, ThreadContext* ctx)
{
	this->value = this->value << variable->getValue(ctx);
	return this;
}
IAlinousVariable* IntegerVariable::shiftLeft(CharVariable* variable, ThreadContext* ctx)
{
	this->value = this->value << variable->getValue(ctx);
	return this;
}
IAlinousVariable* IntegerVariable::shiftLeft(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1207(), ctx));
}
IAlinousVariable* IntegerVariable::shiftLeft(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1207(), ctx));
}
IAlinousVariable* IntegerVariable::shiftLeft(IntegerVariable* variable, ThreadContext* ctx)
{
	this->value = this->value << variable->getValue(ctx);
	return this;
}
IAlinousVariable* IntegerVariable::shiftLeft(LongVariable* variable, ThreadContext* ctx)
{
	this->value = this->value << variable->getValue(ctx);
	return this;
}
IAlinousVariable* IntegerVariable::shiftLeft(ShortVariable* variable, ThreadContext* ctx)
{
	this->value = this->value << variable->getValue(ctx);
	return this;
}
IAlinousVariable* IntegerVariable::shiftLeft(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1206(), ctx));
}
IAlinousVariable* IntegerVariable::shiftRight(VariantValue* variable, ThreadContext* ctx)
{
	this->value = this->value >> variable->getInt(ctx);
	return this;
}
IAlinousVariable* IntegerVariable::shiftRight(DomVariable* variable, ThreadContext* ctx)
{
	this->value = this->value >> variable->getValue(ctx)->getInt(ctx);
	return this;
}
IAlinousVariable* IntegerVariable::shiftRight(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1205(), ctx));
}
IAlinousVariable* IntegerVariable::shiftRight(ByteVariable* variable, ThreadContext* ctx)
{
	this->value = this->value >> variable->getValue(ctx);
	return this;
}
IAlinousVariable* IntegerVariable::shiftRight(CharVariable* variable, ThreadContext* ctx)
{
	this->value = this->value >> variable->getValue(ctx);
	return this;
}
IAlinousVariable* IntegerVariable::shiftRight(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1207(), ctx));
}
IAlinousVariable* IntegerVariable::shiftRight(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1207(), ctx));
}
IAlinousVariable* IntegerVariable::shiftRight(IntegerVariable* variable, ThreadContext* ctx)
{
	this->value = this->value >> variable->getValue(ctx);
	return this;
}
IAlinousVariable* IntegerVariable::shiftRight(LongVariable* variable, ThreadContext* ctx)
{
	this->value = this->value >> variable->getValue(ctx);
	return this;
}
IAlinousVariable* IntegerVariable::shiftRight(ShortVariable* variable, ThreadContext* ctx)
{
	this->value = this->value >> variable->getValue(ctx);
	return this;
}
IAlinousVariable* IntegerVariable::shiftRight(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1206(), ctx));
}
IAlinousVariable* IntegerVariable::modulo(VariantValue* variable, ThreadContext* ctx)
{
	this->value = this->value % variable->getInt(ctx);
	return this;
}
IAlinousVariable* IntegerVariable::modulo(DomVariable* variable, ThreadContext* ctx)
{
	this->value = this->value % variable->getValue(ctx)->getInt(ctx);
	return this;
}
IAlinousVariable* IntegerVariable::modulo(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1205(), ctx));
}
IAlinousVariable* IntegerVariable::modulo(ByteVariable* variable, ThreadContext* ctx)
{
	this->value = this->value % variable->getValue(ctx);
	return this;
}
IAlinousVariable* IntegerVariable::modulo(CharVariable* variable, ThreadContext* ctx)
{
	this->value = this->value % variable->getValue(ctx);
	return this;
}
IAlinousVariable* IntegerVariable::modulo(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1207(), ctx));
}
IAlinousVariable* IntegerVariable::modulo(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1207(), ctx));
}
IAlinousVariable* IntegerVariable::modulo(IntegerVariable* variable, ThreadContext* ctx)
{
	this->value = this->value % variable->getValue(ctx);
	return this;
}
IAlinousVariable* IntegerVariable::modulo(LongVariable* variable, ThreadContext* ctx)
{
	this->value = ((int)(this->value % variable->getValue(ctx)));
	return this;
}
IAlinousVariable* IntegerVariable::modulo(ShortVariable* variable, ThreadContext* ctx)
{
	this->value = this->value % variable->getValue(ctx);
	return this;
}
IAlinousVariable* IntegerVariable::modulo(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1206(), ctx));
}
IAlinousVariable* IntegerVariable::substitute(VariantValue* variable, ThreadContext* ctx)
{
	this->value = variable->getInt(ctx);
	return this;
}
IAlinousVariable* IntegerVariable::substitute(DomVariable* variable, ThreadContext* ctx)
{
	this->value = variable->getValue(ctx)->getInt(ctx);
	return this;
}
IAlinousVariable* IntegerVariable::substitute(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1205(), ctx));
}
IAlinousVariable* IntegerVariable::substitute(ByteVariable* variable, ThreadContext* ctx)
{
	this->value = variable->getValue(ctx);
	return this;
}
IAlinousVariable* IntegerVariable::substitute(CharVariable* variable, ThreadContext* ctx)
{
	this->value = variable->getValue(ctx);
	return this;
}
IAlinousVariable* IntegerVariable::substitute(DoubleVariable* variable, ThreadContext* ctx)
{
	this->value = ((int)variable->getValue(ctx));
	return this;
}
IAlinousVariable* IntegerVariable::substitute(FloatVariable* variable, ThreadContext* ctx)
{
	this->value = ((int)variable->getValue(ctx));
	return this;
}
IAlinousVariable* IntegerVariable::substitute(IntegerVariable* variable, ThreadContext* ctx)
{
	this->value = variable->getValue(ctx);
	return this;
}
IAlinousVariable* IntegerVariable::substitute(LongVariable* variable, ThreadContext* ctx)
{
	this->value = ((int)variable->getValue(ctx));
	return this;
}
IAlinousVariable* IntegerVariable::substitute(ShortVariable* variable, ThreadContext* ctx)
{
	this->value = variable->getValue(ctx);
	return this;
}
IAlinousVariable* IntegerVariable::substitute(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1206(), ctx));
}
int IntegerVariable::compareTo(VariantValue* variable, ThreadContext* ctx)
{
	return ((int)(this->value - variable->getInt(ctx)));
}
int IntegerVariable::compareTo(DomVariable* variable, ThreadContext* ctx)
{
	return ((int)(this->value - variable->getValue(ctx)->getInt(ctx)));
}
int IntegerVariable::compareTo(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1205(), ctx));
}
int IntegerVariable::compareTo(ByteVariable* variable, ThreadContext* ctx)
{
	return ((int)(this->value - variable->getValue(ctx)));
}
int IntegerVariable::compareTo(CharVariable* variable, ThreadContext* ctx)
{
	return ((int)(this->value - variable->getValue(ctx)));
}
int IntegerVariable::compareTo(DoubleVariable* variable, ThreadContext* ctx)
{
	return ((int)(this->value - variable->getValue(ctx)));
}
int IntegerVariable::compareTo(FloatVariable* variable, ThreadContext* ctx)
{
	return ((int)(this->value - variable->getValue(ctx)));
}
int IntegerVariable::compareTo(IntegerVariable* variable, ThreadContext* ctx)
{
	return ((int)(this->value - variable->getValue(ctx)));
}
int IntegerVariable::compareTo(LongVariable* variable, ThreadContext* ctx)
{
	return ((int)(this->value - variable->getValue(ctx)));
}
int IntegerVariable::compareTo(ShortVariable* variable, ThreadContext* ctx)
{
	return ((int)(this->value - variable->getValue(ctx)));
}
int IntegerVariable::compareTo(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1206(), ctx));
}
bool IntegerVariable::isTrue(ThreadContext* ctx)
{
	return this->value > 0;
}
IAlinousVariable* IntegerVariable::bitOr(VariantValue* variable, ThreadContext* ctx)
{
	this->value = this->value | variable->getInt(ctx);
	return this;
}
IAlinousVariable* IntegerVariable::bitOr(DomVariable* variable, ThreadContext* ctx)
{
	this->value = this->value | variable->getValue(ctx)->getInt(ctx);
	return this;
}
IAlinousVariable* IntegerVariable::bitOr(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1205(), ctx));
}
IAlinousVariable* IntegerVariable::bitOr(ByteVariable* variable, ThreadContext* ctx)
{
	this->value = this->value | variable->getValue(ctx);
	return this;
}
IAlinousVariable* IntegerVariable::bitOr(CharVariable* variable, ThreadContext* ctx)
{
	this->value = this->value | variable->getValue(ctx);
	return this;
}
IAlinousVariable* IntegerVariable::bitOr(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1208(), ctx));
}
IAlinousVariable* IntegerVariable::bitOr(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1208(), ctx));
}
IAlinousVariable* IntegerVariable::bitOr(IntegerVariable* variable, ThreadContext* ctx)
{
	this->value = this->value | variable->getValue(ctx);
	return this;
}
IAlinousVariable* IntegerVariable::bitOr(LongVariable* variable, ThreadContext* ctx)
{
	this->value = ((int)(this->value | variable->getValue(ctx)));
	return this;
}
IAlinousVariable* IntegerVariable::bitOr(ShortVariable* variable, ThreadContext* ctx)
{
	this->value = this->value | variable->getValue(ctx);
	return this;
}
IAlinousVariable* IntegerVariable::bitOr(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1206(), ctx));
}
IAlinousVariable* IntegerVariable::bitAnd(VariantValue* variable, ThreadContext* ctx)
{
	this->value = this->value & variable->getInt(ctx);
	return this;
}
IAlinousVariable* IntegerVariable::bitAnd(DomVariable* variable, ThreadContext* ctx)
{
	this->value = this->value & variable->getValue(ctx)->getInt(ctx);
	return this;
}
IAlinousVariable* IntegerVariable::bitAnd(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1205(), ctx));
}
IAlinousVariable* IntegerVariable::bitAnd(ByteVariable* variable, ThreadContext* ctx)
{
	this->value = this->value & variable->getValue(ctx);
	return this;
}
IAlinousVariable* IntegerVariable::bitAnd(CharVariable* variable, ThreadContext* ctx)
{
	this->value = this->value & variable->getValue(ctx);
	return this;
}
IAlinousVariable* IntegerVariable::bitAnd(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1208(), ctx));
}
IAlinousVariable* IntegerVariable::bitAnd(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1208(), ctx));
}
IAlinousVariable* IntegerVariable::bitAnd(IntegerVariable* variable, ThreadContext* ctx)
{
	this->value = this->value & variable->getValue(ctx);
	return this;
}
IAlinousVariable* IntegerVariable::bitAnd(LongVariable* variable, ThreadContext* ctx)
{
	this->value = ((int)(this->value & variable->getValue(ctx)));
	return this;
}
IAlinousVariable* IntegerVariable::bitAnd(ShortVariable* variable, ThreadContext* ctx)
{
	this->value = this->value & variable->getValue(ctx);
	return this;
}
IAlinousVariable* IntegerVariable::bitAnd(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1206(), ctx));
}
IAlinousVariable* IntegerVariable::bitExor(VariantValue* variable, ThreadContext* ctx)
{
	this->value = this->value ^ variable->getInt(ctx);
	return this;
}
IAlinousVariable* IntegerVariable::bitExor(DomVariable* variable, ThreadContext* ctx)
{
	this->value = this->value ^ variable->getValue(ctx)->getInt(ctx);
	return this;
}
IAlinousVariable* IntegerVariable::bitExor(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1205(), ctx));
}
IAlinousVariable* IntegerVariable::bitExor(ByteVariable* variable, ThreadContext* ctx)
{
	this->value = this->value ^ variable->getValue(ctx);
	return this;
}
IAlinousVariable* IntegerVariable::bitExor(CharVariable* variable, ThreadContext* ctx)
{
	this->value = this->value ^ variable->getValue(ctx);
	return this;
}
IAlinousVariable* IntegerVariable::bitExor(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1208(), ctx));
}
IAlinousVariable* IntegerVariable::bitExor(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1208(), ctx));
}
IAlinousVariable* IntegerVariable::bitExor(IntegerVariable* variable, ThreadContext* ctx)
{
	this->value = this->value ^ variable->getValue(ctx);
	return this;
}
IAlinousVariable* IntegerVariable::bitExor(LongVariable* variable, ThreadContext* ctx)
{
	this->value = ((int)(this->value ^ variable->getValue(ctx)));
	return this;
}
IAlinousVariable* IntegerVariable::bitExor(ShortVariable* variable, ThreadContext* ctx)
{
	this->value = this->value ^ variable->getValue(ctx);
	return this;
}
IAlinousVariable* IntegerVariable::bitExor(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1206(), ctx));
}
IAlinousVariable* IntegerVariable::add(BigDecimalVariable* variable, ThreadContext* ctx)
{
	this->value = this->value + variable->getValue(ctx)->intValue(ctx);
	return this;
}
IAlinousVariable* IntegerVariable::minus(BigDecimalVariable* variable, ThreadContext* ctx)
{
	this->value = this->value - variable->getValue(ctx)->intValue(ctx);
	return this;
}
IAlinousVariable* IntegerVariable::multiply(BigDecimalVariable* variable, ThreadContext* ctx)
{
	this->value = this->value * variable->getValue(ctx)->intValue(ctx);
	return this;
}
IAlinousVariable* IntegerVariable::div(BigDecimalVariable* variable, ThreadContext* ctx)
{
	this->value = this->value / variable->getValue(ctx)->intValue(ctx);
	return this;
}
IAlinousVariable* IntegerVariable::shiftLeft(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1209(), ctx));
}
IAlinousVariable* IntegerVariable::shiftRight(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1209(), ctx));
}
IAlinousVariable* IntegerVariable::modulo(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1209(), ctx));
}
IAlinousVariable* IntegerVariable::bitOr(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1209(), ctx));
}
IAlinousVariable* IntegerVariable::bitAnd(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1209(), ctx));
}
IAlinousVariable* IntegerVariable::bitExor(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1209(), ctx));
}
IAlinousVariable* IntegerVariable::substitute(BigDecimalVariable* variable, ThreadContext* ctx)
{
	this->value = variable->getValue(ctx)->intValue(ctx);
	return this;
}
int IntegerVariable::compareTo(BigDecimalVariable* variable, ThreadContext* ctx)
{
	return this->value - variable->getValue(ctx)->intValue(ctx);
}
IAlinousVariable* IntegerVariable::shiftRightUnsigned(VariantValue* variable, ThreadContext* ctx)
{
	this->value = ((unsigned int)this->value)>> variable->getInt(ctx);
	return this;
}
IAlinousVariable* IntegerVariable::shiftRightUnsigned(DomVariable* variable, ThreadContext* ctx)
{
	this->value = ((unsigned int)this->value)>> variable->getValue(ctx)->getInt(ctx);
	return this;
}
IAlinousVariable* IntegerVariable::shiftRightUnsigned(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1205(), ctx));
}
IAlinousVariable* IntegerVariable::shiftRightUnsigned(ByteVariable* variable, ThreadContext* ctx)
{
	this->value = ((unsigned int)this->value)>> variable->getValue(ctx);
	return this;
}
IAlinousVariable* IntegerVariable::shiftRightUnsigned(CharVariable* variable, ThreadContext* ctx)
{
	this->value = ((unsigned int)this->value)>> variable->getValue(ctx);
	return this;
}
IAlinousVariable* IntegerVariable::shiftRightUnsigned(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1208(), ctx));
}
IAlinousVariable* IntegerVariable::shiftRightUnsigned(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1208(), ctx));
}
IAlinousVariable* IntegerVariable::shiftRightUnsigned(IntegerVariable* variable, ThreadContext* ctx)
{
	this->value = ((unsigned int)this->value)>> variable->getValue(ctx);
	return this;
}
IAlinousVariable* IntegerVariable::shiftRightUnsigned(LongVariable* variable, ThreadContext* ctx)
{
	this->value = ((unsigned int)this->value)>> variable->getValue(ctx);
	return this;
}
IAlinousVariable* IntegerVariable::shiftRightUnsigned(ShortVariable* variable, ThreadContext* ctx)
{
	this->value = ((unsigned int)this->value)>> variable->getValue(ctx);
	return this;
}
IAlinousVariable* IntegerVariable::shiftRightUnsigned(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1206(), ctx));
}
IAlinousVariable* IntegerVariable::shiftRightUnsigned(BigDecimalVariable* variable, ThreadContext* ctx)
{
	this->value = ((unsigned int)this->value)>> variable->getValue(ctx)->intValue(ctx);
	return this;
}
BoolVariable* IntegerVariable::toBoolVariable(ThreadContext* ctx)
{
	return (new(ctx) BoolVariable(isTrue(ctx), ctx));
}
ByteVariable* IntegerVariable::toByteVariable(ThreadContext* ctx)
{
	return (new(ctx) ByteVariable(((char)this->value), ctx));
}
CharVariable* IntegerVariable::toCharVariable(ThreadContext* ctx)
{
	return (new(ctx) CharVariable(((wchar_t)this->value), ctx));
}
ShortVariable* IntegerVariable::toShortVariable(ThreadContext* ctx)
{
	return (new(ctx) ShortVariable(((short)this->value), ctx));
}
IntegerVariable* IntegerVariable::toIntVariable(ThreadContext* ctx)
{
	return static_cast<IntegerVariable*>(copy(ctx));
}
LongVariable* IntegerVariable::toLongVariable(ThreadContext* ctx)
{
	return (new(ctx) LongVariable(this->value, ctx));
}
StringVariable* IntegerVariable::toStringVariable(ThreadContext* ctx)
{
	return (new(ctx) StringVariable(getStringValue(ctx), ctx));
}
BigDecimalVariable* IntegerVariable::toBigDecimalVariable(ThreadContext* ctx)
{
	BigDecimal* dec = (new(ctx) BigDecimal(this->value, ctx));
	return (new(ctx) BigDecimalVariable(dec, ctx));
}
long long IntegerVariable::getLongValue(ThreadContext* ctx)
{
	return this->value;
}
FloatVariable* IntegerVariable::toFloatVariable(ThreadContext* ctx)
{
	return (new(ctx) FloatVariable(this->value, ctx));
}
DoubleVariable* IntegerVariable::toDoubleVariable(ThreadContext* ctx)
{
	return (new(ctx) DoubleVariable(this->value, ctx));
}
TimeVariable* IntegerVariable::toTimeVariable(ThreadContext* ctx)
{
	TimeOnlyTimestamp* tm = (new(ctx) TimeOnlyTimestamp(this->value, ctx));
	return (new(ctx) TimeVariable(tm, ctx));
}
TimestampVariable* IntegerVariable::toTimestampVariable(ThreadContext* ctx)
{
	Timestamp* tm = (new(ctx) Timestamp(this->value, ctx));
	return (new(ctx) TimestampVariable(tm, ctx));
}
IAlinousVariable* IntegerVariable::add(TimeVariable* variable, ThreadContext* ctx)
{
	this->value = ((int)(this->value + variable->getValue(ctx)->getTime(ctx)));
	return this;
}
IAlinousVariable* IntegerVariable::add(TimestampVariable* variable, ThreadContext* ctx)
{
	this->value = ((int)(this->value + variable->getValue(ctx)->getTime(ctx)));
	return this;
}
IAlinousVariable* IntegerVariable::minus(TimeVariable* variable, ThreadContext* ctx)
{
	this->value = ((int)(this->value - variable->getValue(ctx)->getTime(ctx)));
	return this;
}
IAlinousVariable* IntegerVariable::minus(TimestampVariable* variable, ThreadContext* ctx)
{
	this->value = ((int)(this->value - variable->getValue(ctx)->getTime(ctx)));
	return this;
}
IAlinousVariable* IntegerVariable::multiply(TimeVariable* variable, ThreadContext* ctx)
{
	this->value = ((int)(this->value * variable->getValue(ctx)->getTime(ctx)));
	return this;
}
IAlinousVariable* IntegerVariable::multiply(TimestampVariable* variable, ThreadContext* ctx)
{
	this->value = ((int)(this->value * variable->getValue(ctx)->getTime(ctx)));
	return this;
}
IAlinousVariable* IntegerVariable::div(TimeVariable* variable, ThreadContext* ctx)
{
	this->value = ((int)(this->value / variable->getValue(ctx)->getTime(ctx)));
	return this;
}
IAlinousVariable* IntegerVariable::div(TimestampVariable* variable, ThreadContext* ctx)
{
	this->value = ((int)(this->value / variable->getValue(ctx)->getTime(ctx)));
	return this;
}
IAlinousVariable* IntegerVariable::shiftLeft(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1210(), ctx));
}
IAlinousVariable* IntegerVariable::shiftLeft(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1210(), ctx));
}
IAlinousVariable* IntegerVariable::shiftRight(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1210(), ctx));
}
IAlinousVariable* IntegerVariable::shiftRight(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1210(), ctx));
}
IAlinousVariable* IntegerVariable::shiftRightUnsigned(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1210(), ctx));
}
IAlinousVariable* IntegerVariable::shiftRightUnsigned(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1210(), ctx));
}
IAlinousVariable* IntegerVariable::modulo(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1210(), ctx));
}
IAlinousVariable* IntegerVariable::modulo(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1210(), ctx));
}
IAlinousVariable* IntegerVariable::bitOr(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1210(), ctx));
}
IAlinousVariable* IntegerVariable::bitOr(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1210(), ctx));
}
IAlinousVariable* IntegerVariable::bitAnd(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1210(), ctx));
}
IAlinousVariable* IntegerVariable::bitAnd(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1210(), ctx));
}
IAlinousVariable* IntegerVariable::bitExor(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1210(), ctx));
}
IAlinousVariable* IntegerVariable::bitExor(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1210(), ctx));
}
IAlinousVariable* IntegerVariable::substitute(TimeVariable* variable, ThreadContext* ctx)
{
	this->value = ((int)variable->getValue(ctx)->getTime(ctx));
	return this;
}
IAlinousVariable* IntegerVariable::substitute(TimestampVariable* variable, ThreadContext* ctx)
{
	this->value = ((int)variable->getValue(ctx)->getTime(ctx));
	return this;
}
int IntegerVariable::compareTo(TimeVariable* variable, ThreadContext* ctx)
{
	return ((int)(this->value - variable->getValue(ctx)->getTime(ctx)));
}
int IntegerVariable::compareTo(TimestampVariable* variable, ThreadContext* ctx)
{
	return ((int)(this->value - variable->getValue(ctx)->getTime(ctx)));
}
IAlinousVariable* IntegerVariable::substitute(TypedVariableArray* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1200(), ctx));
}
void IntegerVariable::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	this->value = buff->getInt(ctx);
}
void IntegerVariable::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putInt(ICommandData::__IntegerVariable, ctx);
	buff->putInt(this->value, ctx);
}
IntegerVariable* IntegerVariable::fromDebugXml(DomNode* node, ThreadContext* ctx) throw() 
{
	IVariableValue* attrVal = node->getAttributeValue(VAL_TYPE, ctx);
	if(attrVal == nullptr)
	{
		return nullptr;
	}
	String* str = attrVal->toString(ctx);
	int value = 0;
	{
		try
		{
			value = Integer::parseInt(str, ctx);
		}
		catch(Throwable* e)
		{
			e->printStackTrace(ctx);
			return nullptr;
		}
	}
	return (new(ctx) IntegerVariable(value, ctx));
}
void IntegerVariable::__cleanUp(ThreadContext* ctx){
}
int IntegerVariable::ValueCompare::operator() (VariantValue* _this, VariantValue* variable, ThreadContext* ctx) const throw()
{
	return _this->compareTo(variable, ctx);
}
}}}}

