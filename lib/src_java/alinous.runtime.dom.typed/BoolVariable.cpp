#include "include/global.h"


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
#include "alinous.runtime.dom.typed/StringVariable.h"
#include "alinous.runtime.dom.typed/ShortVariable.h"
#include "alinous.runtime.dom.typed/LongVariable.h"
#include "alinous.runtime.dom.typed/IntegerVariable.h"
#include "alinous.runtime.dom.typed/FloatVariable.h"
#include "alinous.runtime.dom.typed/DoubleVariable.h"
#include "alinous.runtime.dom.typed/CharVariable.h"
#include "alinous.runtime.dom.typed/ByteVariable.h"
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
#include "alinous.runtime.dom.typed/BoolVariable.h"

namespace alinous {namespace runtime {namespace dom {namespace typed {





String* BoolVariable::VAL_TYPE = ConstStr::getCNST_STR_1145();
bool BoolVariable::__init_done = __init_static_variables();
bool BoolVariable::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"BoolVariable", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 BoolVariable::BoolVariable(ThreadContext* ctx) throw()  : IObject(ctx), AbstractTypedVariable(ctx), value(0)
{
}
void BoolVariable::__construct_impl(ThreadContext* ctx) throw() 
{
}
 BoolVariable::BoolVariable(bool value, ThreadContext* ctx) throw()  : IObject(ctx), AbstractTypedVariable(ctx), value(0)
{
	this->value = value;
}
void BoolVariable::__construct_impl(bool value, ThreadContext* ctx) throw() 
{
	this->value = value;
}
 BoolVariable::~BoolVariable() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void BoolVariable::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"BoolVariable", L"~BoolVariable");
	if(!prepare){
		return;
	}
	AbstractTypedVariable::__releaseRegerences(true, ctx);
}
void BoolVariable::outDebugXml(DomNode* parentNode, String* name, ThreadContext* ctx) throw() 
{
	DomNode* node = (new(ctx) DomNode(VAL_TYPE, ctx));
	parentNode->addChild(node, ctx);
	if(name != nullptr)
	{
		Attribute* nameattr = (new(ctx) Attribute(IAlinousVariable::ATTR_NAME, name, node, ctx));
		node->addAttribute(nameattr, ctx);
	}
	Attribute* attr = (new(ctx) Attribute(AbstractTypedVariable::VALUE, Boolean::toString(this->value, ctx), node, ctx));
	parentNode->addAttribute(attr, ctx);
}
int BoolVariable::getIntValue(ThreadContext* ctx)
{
	int ret = this->value ? 1 : 0;
	return ret;
}
String* BoolVariable::getStringValue(ThreadContext* ctx)
{
	String* ret = this->value ? ConstStr::getCNST_STR_372() : ConstStr::getCNST_STR_1144();
	return ret;
}
VariantValue* BoolVariable::toVariantValue(ThreadContext* ctx)
{
	return (new(ctx) VariantValue(((char)getIntValue(ctx)), ctx));
}
int BoolVariable::getVariableClass(ThreadContext* ctx) throw() 
{
	return IAlinousVariable::CLASS_TYPED;
}
int BoolVariable::getTypedType(ThreadContext* ctx) throw() 
{
	return ITypedVariable::TYPE_BOOL;
}
bool BoolVariable::isValue(ThreadContext* ctx) throw() 
{
	return value;
}
void BoolVariable::setValue(bool value, ThreadContext* ctx) throw() 
{
	this->value = value;
}
IAlinousVariable* BoolVariable::copy(ThreadContext* ctx)
{
	return (new(ctx) BoolVariable(this->value, ctx));
}
IDomVariable* BoolVariable::toDomVariable(ThreadContext* ctx) throw() 
{
	DomVariable* ret = (new(ctx) DomVariable(ctx));
	int bl = this->value == true ? 1 : 0;
	ret->setValue((new(ctx) VariantValue(bl, ctx)), ctx);
	return ret;
}
IAlinousVariable* BoolVariable::add(VariantValue* variable, ThreadContext* ctx)
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	buff->append(Boolean::toString(this->value, ctx), ctx);
	buff->append(variable->getString(ctx), ctx);
	return (new(ctx) StringVariable(buff->toString(ctx), ctx));
}
IAlinousVariable* BoolVariable::add(DomVariable* variable, ThreadContext* ctx)
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	buff->append(Boolean::toString(this->value, ctx), ctx);
	buff->append(variable->getValue(ctx)->getString(ctx), ctx);
	return (new(ctx) StringVariable(buff->toString(ctx), ctx));
}
IAlinousVariable* BoolVariable::add(BoolVariable* variable, ThreadContext* ctx)
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	buff->append(Boolean::toString(this->value, ctx), ctx);
	buff->append(variable->isValue(ctx), ctx);
	return (new(ctx) StringVariable(buff->toString(ctx), ctx));
}
IAlinousVariable* BoolVariable::add(ByteVariable* variable, ThreadContext* ctx)
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	buff->append(Boolean::toString(this->value, ctx), ctx);
	buff->append((wchar_t)variable->getValue(ctx), ctx);
	return (new(ctx) StringVariable(buff->toString(ctx), ctx));
}
IAlinousVariable* BoolVariable::add(CharVariable* variable, ThreadContext* ctx)
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	buff->append(Boolean::toString(this->value, ctx), ctx);
	buff->append(variable->getValue(ctx), ctx);
	return (new(ctx) StringVariable(buff->toString(ctx), ctx));
}
IAlinousVariable* BoolVariable::add(DoubleVariable* variable, ThreadContext* ctx)
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	buff->append(Boolean::toString(this->value, ctx), ctx);
	buff->append(variable->getValue(ctx), ctx);
	return (new(ctx) StringVariable(buff->toString(ctx), ctx));
}
IAlinousVariable* BoolVariable::add(FloatVariable* variable, ThreadContext* ctx)
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	buff->append(Boolean::toString(this->value, ctx), ctx);
	buff->append(variable->getValue(ctx), ctx);
	return (new(ctx) StringVariable(buff->toString(ctx), ctx));
}
IAlinousVariable* BoolVariable::add(IntegerVariable* variable, ThreadContext* ctx)
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	buff->append(Boolean::toString(this->value, ctx), ctx);
	buff->append(variable->getValue(ctx), ctx);
	return (new(ctx) StringVariable(buff->toString(ctx), ctx));
}
IAlinousVariable* BoolVariable::add(ShortVariable* variable, ThreadContext* ctx)
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	buff->append(Boolean::toString(this->value, ctx), ctx);
	buff->append((int)variable->getValue(ctx), ctx);
	return (new(ctx) StringVariable(buff->toString(ctx), ctx));
}
IAlinousVariable* BoolVariable::add(StringVariable* variable, ThreadContext* ctx)
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	buff->append(Boolean::toString(this->value, ctx), ctx);
	buff->append(variable->getValue(ctx), ctx);
	return (new(ctx) StringVariable(buff->toString(ctx), ctx));
}
IAlinousVariable* BoolVariable::minus(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::minus(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::minus(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::minus(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::minus(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::minus(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::minus(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::minus(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::minus(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::minus(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::multiply(IAlinousVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::multiply(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::multiply(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::multiply(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::multiply(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::multiply(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::multiply(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::multiply(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::multiply(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::multiply(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::div(IAlinousVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::div(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::div(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::div(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::div(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::div(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::div(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::div(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::div(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::div(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::bitReverse(ThreadContext* ctx)
{
	this->value = this->value == true ? false : true;
	return this;
}
IAlinousVariable* BoolVariable::multiply(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::div(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::add(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::minus(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::multiply(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::div(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
bool BoolVariable::isNull(ThreadContext* ctx) throw() 
{
	return false;
}
bool BoolVariable::isArray(ThreadContext* ctx) throw() 
{
	return false;
}
IAlinousVariable* BoolVariable::shiftLeft(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::shiftLeft(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::shiftLeft(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::shiftLeft(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::shiftLeft(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::shiftLeft(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::shiftLeft(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::shiftLeft(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::shiftLeft(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::shiftLeft(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::shiftLeft(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::shiftRight(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::shiftRight(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::shiftRight(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::shiftRight(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::shiftRight(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::shiftRight(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::shiftRight(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::shiftRight(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::shiftRight(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::shiftRight(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::shiftRight(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::modulo(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::modulo(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::modulo(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::modulo(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::modulo(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::modulo(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::modulo(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::modulo(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::modulo(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::modulo(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::modulo(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::substitute(VariantValue* variable, ThreadContext* ctx)
{
	this->value = variable->getInt(ctx) > 0 ? true : false;
	return this;
}
IAlinousVariable* BoolVariable::substitute(DomVariable* variable, ThreadContext* ctx)
{
	this->value = variable->getValue(ctx)->getInt(ctx) > 0 ? true : false;
	return this;
}
IAlinousVariable* BoolVariable::substitute(BoolVariable* variable, ThreadContext* ctx)
{
	this->value = variable->isValue(ctx);
	return this;
}
IAlinousVariable* BoolVariable::substitute(ByteVariable* variable, ThreadContext* ctx)
{
	this->value = variable->getValue(ctx) > (char)0 ? true : false;
	return this;
}
IAlinousVariable* BoolVariable::substitute(CharVariable* variable, ThreadContext* ctx)
{
	this->value = variable->getValue(ctx) > (wchar_t)0 ? true : false;
	return this;
}
IAlinousVariable* BoolVariable::substitute(DoubleVariable* variable, ThreadContext* ctx)
{
	this->value = variable->getValue(ctx) > (double)0 ? true : false;
	return this;
}
IAlinousVariable* BoolVariable::substitute(FloatVariable* variable, ThreadContext* ctx)
{
	this->value = variable->getValue(ctx) > (float)0 ? true : false;
	return this;
}
IAlinousVariable* BoolVariable::substitute(IntegerVariable* variable, ThreadContext* ctx)
{
	this->value = variable->getValue(ctx) > 0 ? true : false;
	return this;
}
IAlinousVariable* BoolVariable::substitute(LongVariable* variable, ThreadContext* ctx)
{
	this->value = variable->getValue(ctx) > (long long)0 ? true : false;
	return this;
}
IAlinousVariable* BoolVariable::substitute(ShortVariable* variable, ThreadContext* ctx)
{
	this->value = variable->getValue(ctx) > (short)0 ? true : false;
	return this;
}
IAlinousVariable* BoolVariable::substitute(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
int BoolVariable::compareTo(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
int BoolVariable::compareTo(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
int BoolVariable::compareTo(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
int BoolVariable::compareTo(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
int BoolVariable::compareTo(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
int BoolVariable::compareTo(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
int BoolVariable::compareTo(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
int BoolVariable::compareTo(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
int BoolVariable::compareTo(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
int BoolVariable::compareTo(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
int BoolVariable::compareTo(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
bool BoolVariable::isTrue(ThreadContext* ctx)
{
	return this->value;
}
IAlinousVariable* BoolVariable::bitOr(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::bitOr(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::bitOr(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::bitOr(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::bitOr(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::bitOr(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::bitOr(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::bitOr(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::bitOr(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::bitOr(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::bitOr(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::bitAnd(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::bitAnd(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::bitAnd(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::bitAnd(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::bitAnd(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::bitAnd(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::bitAnd(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::bitAnd(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::bitAnd(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::bitAnd(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::bitAnd(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::bitExor(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::bitExor(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::bitExor(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::bitExor(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::bitExor(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::bitExor(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::bitExor(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::bitExor(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::bitExor(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::bitExor(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::bitExor(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::add(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::minus(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::multiply(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::div(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::shiftLeft(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::shiftRight(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::modulo(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::bitOr(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::bitAnd(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::bitExor(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::substitute(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
int BoolVariable::compareTo(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::shiftRightUnsigned(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::shiftRightUnsigned(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::shiftRightUnsigned(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::shiftRightUnsigned(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::shiftRightUnsigned(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::shiftRightUnsigned(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::shiftRightUnsigned(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::shiftRightUnsigned(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::shiftRightUnsigned(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::shiftRightUnsigned(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::shiftRightUnsigned(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::shiftRightUnsigned(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
BoolVariable* BoolVariable::toBoolVariable(ThreadContext* ctx)
{
	return static_cast<BoolVariable*>(copy(ctx));
}
ByteVariable* BoolVariable::toByteVariable(ThreadContext* ctx)
{
	return (new(ctx) ByteVariable(((char)(this->value ? 1 : 0)), ctx));
}
CharVariable* BoolVariable::toCharVariable(ThreadContext* ctx)
{
	return (new(ctx) CharVariable(((wchar_t)(this->value ? 1 : 0)), ctx));
}
ShortVariable* BoolVariable::toShortVariable(ThreadContext* ctx)
{
	return (new(ctx) ShortVariable(((short)(this->value ? 1 : 0)), ctx));
}
IntegerVariable* BoolVariable::toIntVariable(ThreadContext* ctx)
{
	return (new(ctx) IntegerVariable(this->value ? 1 : 0, ctx));
}
LongVariable* BoolVariable::toLongVariable(ThreadContext* ctx)
{
	return (new(ctx) LongVariable(this->value ? 1 : 0, ctx));
}
StringVariable* BoolVariable::toStringVariable(ThreadContext* ctx)
{
	return (new(ctx) StringVariable(this->value ? ConstStr::getCNST_STR_372() : ConstStr::getCNST_STR_1144(), ctx));
}
BigDecimalVariable* BoolVariable::toBigDecimalVariable(ThreadContext* ctx)
{
	BigDecimal* dec = (new(ctx) BigDecimal(getLongValue(ctx), ctx));
	return (new(ctx) BigDecimalVariable(dec, ctx));
}
long long BoolVariable::getLongValue(ThreadContext* ctx)
{
	return this->value ? 1 : 0;
}
FloatVariable* BoolVariable::toFloatVariable(ThreadContext* ctx)
{
	return (new(ctx) FloatVariable(this->value ? 1 : 0, ctx));
}
DoubleVariable* BoolVariable::toDoubleVariable(ThreadContext* ctx)
{
	return (new(ctx) DoubleVariable(this->value ? 1 : 0, ctx));
}
TimeVariable* BoolVariable::toTimeVariable(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
TimestampVariable* BoolVariable::toTimestampVariable(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::add(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::add(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::minus(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::minus(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::multiply(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::multiply(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::div(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::div(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::shiftLeft(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::shiftLeft(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::shiftRight(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::shiftRight(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::shiftRightUnsigned(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::shiftRightUnsigned(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::modulo(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::modulo(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::bitOr(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::bitOr(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::bitAnd(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::bitAnd(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::bitExor(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::bitExor(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::substitute(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::substitute(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
int BoolVariable::compareTo(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
int BoolVariable::compareTo(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1136(), ctx));
}
IAlinousVariable* BoolVariable::substitute(TypedVariableArray* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1131(), ctx));
}
void BoolVariable::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	char bl = buff->getByte(ctx);
	this->value = (bl == (char)1);
}
void BoolVariable::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putInt(ICommandData::__BoolVariable, ctx);
	char bl = ((char)(this->value ? 1 : 0));
	buff->putByte(bl, ctx);
}
BoolVariable* BoolVariable::fromDebugXml(DomNode* node, ThreadContext* ctx) throw() 
{
	IVariableValue* attrVal = node->getAttributeValue(VAL_TYPE, ctx);
	if(attrVal == nullptr)
	{
		return nullptr;
	}
	String* str = attrVal->toString(ctx);
	bool value = false;
	{
		try
		{
			int n = Integer::parseInt(str, ctx);
			if(n > 0)
			{
				value = true;
			}
		}
		catch(Throwable* e)
		{
			e->printStackTrace(ctx);
			return nullptr;
		}
	}
	BoolVariable* bl = (new(ctx) BoolVariable(ctx));
	bl->value = value;
	return bl;
}
void BoolVariable::__cleanUp(ThreadContext* ctx){
}
int BoolVariable::ValueCompare::operator() (VariantValue* _this, VariantValue* variable, ThreadContext* ctx) const throw()
{
	return _this->compareTo(variable, ctx);
}
}}}}

