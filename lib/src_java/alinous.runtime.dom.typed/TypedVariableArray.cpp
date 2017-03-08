#include "include/global.h"


#include "alinous.html/IDomObject.h"
#include "alinous.html/DomNode.h"
#include "alinous.html/Attribute.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile/Token.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.runtime.dom/IDomVariableContainer.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.dom/IDomVariable.h"
#include "alinous.runtime.dom.typed/ITypedCaller.h"
#include "alinous.runtime.dom.typed/ITypedVariable.h"
#include "alinous.runtime.dom.typed/AbstractTypedVariable.h"
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
#include "alinous.runtime.dom.typed/BoolVariable.h"
#include "alinous.runtime.dom.clazz/IAlinousClassVariable.h"
#include "alinous.runtime.dom.clazz/AlinousClassVariable.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile.expression/DomVariableDescriptor.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.runtime.dom/DomVariable.h"
#include "alinous.runtime.dom.typed/BigDecimalVariable.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile.expression.expstream/IdentifierVariable.h"
#include "alinous.runtime.dom/DomArray.h"
#include "alinous.runtime.dom/DocumentVariable.h"
#include "alinous.runtime.dom/NetworkAlinousVariableFactory.h"
#include "alinous.runtime.dom.typed/TypedVariableDomFactory.h"
#include "alinous.runtime.dom.typed/TypedVariableArray.h"

namespace alinous {namespace runtime {namespace dom {namespace typed {





String* TypedVariableArray::VAL_TYPE = ConstStr::getCNST_STR_1135();
bool TypedVariableArray::__init_done = __init_static_variables();
bool TypedVariableArray::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"TypedVariableArray", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 TypedVariableArray::TypedVariableArray(ThreadContext* ctx) throw()  : IObject(ctx), AbstractTypedVariable(ctx), array(GCUtils<ArrayList<ITypedVariable> >::ins(this, (new(ctx) ArrayList<ITypedVariable>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
}
void TypedVariableArray::__construct_impl(ThreadContext* ctx) throw() 
{
}
 TypedVariableArray::~TypedVariableArray() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void TypedVariableArray::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"TypedVariableArray", L"~TypedVariableArray");
	__e_obj1.add(this->array, this);
	array = nullptr;
	if(!prepare){
		return;
	}
	AbstractTypedVariable::__releaseRegerences(true, ctx);
}
void TypedVariableArray::outDebugXml(DomNode* parentNode, String* name, ThreadContext* ctx) throw() 
{
	DomNode* node = (new(ctx) DomNode(VAL_TYPE, ctx));
	parentNode->addChild(node, ctx);
	if(name != nullptr)
	{
		Attribute* nameattr = (new(ctx) Attribute(IAlinousVariable::ATTR_NAME, name, node, ctx));
		node->addAttribute(nameattr, ctx);
	}
	int maxLoop = this->array->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ITypedVariable* val = this->array->get(i, ctx);
		val->outDebugXml(node, nullptr, ctx);
	}
}
void TypedVariableArray::addElement(ITypedVariable* element, ThreadContext* ctx) throw() 
{
	this->array->add(element, ctx);
}
ITypedVariable* TypedVariableArray::get(int index, ThreadContext* ctx) throw() 
{
	return this->array->get(index, ctx);
}
IAlinousVariable* TypedVariableArray::substitute(TypedVariableArray* variable, ThreadContext* ctx)
{
	this->array->clear(ctx);
	int maxLoop = variable->array->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ITypedVariable* val = variable->array->get(i, ctx);
		addElement(val, ctx);
	}
	return this;
}
VariantValue* TypedVariableArray::toVariantValue(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
int TypedVariableArray::getVariableClass(ThreadContext* ctx) throw() 
{
	return IAlinousVariable::CLASS_TYPED;
}
int TypedVariableArray::getTypedType(ThreadContext* ctx) throw() 
{
	return ITypedVariable::TYPE_ARRAY;
}
bool TypedVariableArray::isTrue(ThreadContext* ctx)
{
	return !this->array->isEmpty(ctx);
}
IAlinousVariable* TypedVariableArray::copy(ThreadContext* ctx)
{
	TypedVariableArray* newArray = (new(ctx) TypedVariableArray(ctx));
	int maxLoop = this->array->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ITypedVariable* val = this->array->get(i, ctx);
		newArray->addElement(val, ctx);
	}
	return newArray;
}
IDomVariable* TypedVariableArray::toDomVariable(ThreadContext* ctx)
{
	DomArray* domArray = (new(ctx) DomArray(ctx));
	int maxLoop = this->array->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ITypedVariable* val = this->array->get(i, ctx);
		IDomVariable* dm = val->toDomVariable(ctx);
		domArray->put(dm, ctx);
	}
	return domArray;
}
bool TypedVariableArray::isNull(ThreadContext* ctx) throw() 
{
	return this->array->isEmpty(ctx);
}
bool TypedVariableArray::isArray(ThreadContext* ctx) throw() 
{
	return true;
}
BoolVariable* TypedVariableArray::toBoolVariable(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
ByteVariable* TypedVariableArray::toByteVariable(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
CharVariable* TypedVariableArray::toCharVariable(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
ShortVariable* TypedVariableArray::toShortVariable(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IntegerVariable* TypedVariableArray::toIntVariable(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
LongVariable* TypedVariableArray::toLongVariable(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
StringVariable* TypedVariableArray::toStringVariable(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
FloatVariable* TypedVariableArray::toFloatVariable(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
DoubleVariable* TypedVariableArray::toDoubleVariable(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
BigDecimalVariable* TypedVariableArray::toBigDecimalVariable(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
TimeVariable* TypedVariableArray::toTimeVariable(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
TimestampVariable* TypedVariableArray::toTimestampVariable(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
int TypedVariableArray::getIntValue(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
long long TypedVariableArray::getLongValue(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
String* TypedVariableArray::getStringValue(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::add(IAlinousVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::add(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::add(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::add(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::add(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::add(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::add(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::add(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::add(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::add(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::add(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::add(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::add(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::add(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::add(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::minus(IAlinousVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::minus(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::minus(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::minus(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::minus(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::minus(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::minus(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::minus(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::minus(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::minus(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::minus(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::minus(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::minus(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::minus(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::minus(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::multiply(IAlinousVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::multiply(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::multiply(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::multiply(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::multiply(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::multiply(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::multiply(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::multiply(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::multiply(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::multiply(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::multiply(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::multiply(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::multiply(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::multiply(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::multiply(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::div(IAlinousVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::div(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::div(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::div(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::div(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::div(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::div(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::div(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::div(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::div(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::div(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::div(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::div(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::div(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::div(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::shiftLeft(IAlinousVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::shiftLeft(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::shiftLeft(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::shiftLeft(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::shiftLeft(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::shiftLeft(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::shiftLeft(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::shiftLeft(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::shiftLeft(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::shiftLeft(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::shiftLeft(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::shiftLeft(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::shiftLeft(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::shiftLeft(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::shiftLeft(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::shiftRight(IAlinousVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::shiftRight(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::shiftRight(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::shiftRight(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::shiftRight(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::shiftRight(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::shiftRight(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::shiftRight(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::shiftRight(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::shiftRight(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::shiftRight(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::shiftRight(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::shiftRight(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::shiftRight(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::shiftRight(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::shiftRightUnsigned(IAlinousVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::shiftRightUnsigned(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::shiftRightUnsigned(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::shiftRightUnsigned(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::shiftRightUnsigned(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::shiftRightUnsigned(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::shiftRightUnsigned(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::shiftRightUnsigned(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::shiftRightUnsigned(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::shiftRightUnsigned(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::shiftRightUnsigned(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::shiftRightUnsigned(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::shiftRightUnsigned(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::shiftRightUnsigned(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::shiftRightUnsigned(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::modulo(IAlinousVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::modulo(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::modulo(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::modulo(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::modulo(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::modulo(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::modulo(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::modulo(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::modulo(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::modulo(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::modulo(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::modulo(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::modulo(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::modulo(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::modulo(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::bitOr(IAlinousVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::bitOr(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::bitOr(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::bitOr(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::bitOr(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::bitOr(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::bitOr(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::bitOr(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::bitOr(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::bitOr(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::bitOr(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::bitOr(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::bitOr(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::bitOr(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::bitOr(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::bitAnd(IAlinousVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::bitAnd(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::bitAnd(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::bitAnd(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::bitAnd(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::bitAnd(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::bitAnd(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::bitAnd(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::bitAnd(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::bitAnd(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::bitAnd(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::bitAnd(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::bitAnd(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::bitAnd(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::bitAnd(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::bitExor(IAlinousVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::bitExor(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::bitExor(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::bitExor(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::bitExor(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::bitExor(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::bitExor(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::bitExor(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::bitExor(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::bitExor(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::bitExor(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::bitExor(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::bitExor(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::bitExor(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::bitExor(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::bitReverse(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::substitute(IAlinousVariable* variable, ThreadContext* ctx)
{
	if(variable->getVariableClass(ctx) == IAlinousVariable::CLASS_TYPED && (static_cast<ITypedVariable*>(variable))->getTypedType(ctx) == ITypedVariable::TYPE_ARRAY)
	{
		TypedVariableArray* arrayValue = static_cast<TypedVariableArray*>(variable);
		GCUtils<ArrayList<ITypedVariable> >::mv(this, &(this->array), arrayValue->array, ctx);
		return this;
	}
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::substitute(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::substitute(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::substitute(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::substitute(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::substitute(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::substitute(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::substitute(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::substitute(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::substitute(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::substitute(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::substitute(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::substitute(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::substitute(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
IAlinousVariable* TypedVariableArray::substitute(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
int TypedVariableArray::compareTo(IAlinousVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
int TypedVariableArray::compareTo(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
int TypedVariableArray::compareTo(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
int TypedVariableArray::compareTo(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
int TypedVariableArray::compareTo(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
int TypedVariableArray::compareTo(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
int TypedVariableArray::compareTo(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
int TypedVariableArray::compareTo(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
int TypedVariableArray::compareTo(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
int TypedVariableArray::compareTo(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
int TypedVariableArray::compareTo(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
int TypedVariableArray::compareTo(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
int TypedVariableArray::compareTo(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
int TypedVariableArray::compareTo(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
int TypedVariableArray::compareTo(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1133(), ctx));
}
void TypedVariableArray::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	int maxLoop = buff->getInt(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IAlinousVariable* val = NetworkAlinousVariableFactory::fromNetworkData(buff, ctx);
		int type = val->getVariableClass(ctx);
		if(type != IAlinousVariable::CLASS_TYPED && type != IAlinousVariable::CLASS_OBJECT)
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1134(), ctx));
		}
		this->array->add(static_cast<ITypedVariable*>(val), ctx);
	}
}
void TypedVariableArray::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	buff->putInt(ICommandData::__TypedVariableArray, ctx);
	int maxLoop = this->array->size(ctx);
	buff->putInt(maxLoop, ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ITypedVariable* val = this->array->get(i, ctx);
		val->writeData(buff, ctx);
	}
}
void TypedVariableArray::includes(TypedVariableDomFactory* arg0, ThreadContext* ctx) throw() 
{
}
TypedVariableArray* TypedVariableArray::fromDebugXml(DomNode* node, ThreadContext* ctx) throw() 
{
	TypedVariableArray* array = (new(ctx) TypedVariableArray(ctx));
	int maxLoop = node->getNumChildern(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		DomNode* n = node->getChildNodeAt(i, ctx);
		ITypedVariable* val = TypedVariableDomFactory::importFromDomNode(n, ctx);
		array->array->add(val, ctx);
	}
	return array;
}
void TypedVariableArray::__cleanUp(ThreadContext* ctx){
}
int TypedVariableArray::ValueCompare::operator() (IAlinousVariable* _this, IAlinousVariable* variable, ThreadContext* ctx) const throw()
{
	return _this->compareTo(variable, ctx);
}
}}}}

