#include "includes.h"


namespace alinous {namespace runtime {namespace dom {





String* DomArray::VAL_TYPE = ConstStr::getCNST_STR_1113();
bool DomArray::__init_done = __init_static_variables();
bool DomArray::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DomArray", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 DomArray::DomArray(ThreadContext* ctx) throw()  : IObject(ctx), IDomVariable(ctx), array(nullptr), num(0), cap(0)
{
	this->num = 0;
	this->cap = 32;
	GCUtils<ArrayList<IDomVariable> >::mv(this, &(this->array), (new(ctx) ArrayList<IDomVariable>(cap, ctx)), ctx);
}
void DomArray::__construct_impl(ThreadContext* ctx) throw() 
{
	this->num = 0;
	this->cap = 32;
	GCUtils<ArrayList<IDomVariable> >::mv(this, &(this->array), (new(ctx) ArrayList<IDomVariable>(cap, ctx)), ctx);
}
 DomArray::~DomArray() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void DomArray::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"DomArray", L"~DomArray");
	__e_obj1.add(this->array, this);
	array = nullptr;
	if(!prepare){
		return;
	}
}
void DomArray::outDebugXml(DomNode* parentNode, String* name, ThreadContext* ctx) throw() 
{
	DomNode* node = (new(ctx) DomNode(VAL_TYPE, ctx));
	parentNode->addChild(node, ctx);
	int maxLoop = this->array->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IDomVariable* dm = this->array->get(i, ctx);
		dm->outDebugXml(node, nullptr, ctx);
	}
}
int DomArray::getIntValue(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ctx));
}
String* DomArray::getStringValue(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ctx));
}
int DomArray::size(ThreadContext* ctx) throw() 
{
	return this->num;
}
void DomArray::put(IDomVariable* val, ThreadContext* ctx) throw() 
{
	array->add(val, ctx);
}
void DomArray::set(IDomVariable* val, int index, ThreadContext* ctx) throw() 
{
	if(array->size(ctx) >= index)
	{
		int maxLoop = index + 1;
		for(int i = this->array->size(ctx); i != maxLoop; ++i)
		{
			this->array->add((new(ctx) DomVariable(ctx)), ctx);
		}
	}
	if(array->size(ctx) < index)
	{
		for(int i = array->size(ctx); i <= index; ++i)
		{
			this->array->add((new(ctx) DomVariable(ctx)), ctx);
		}
	}
	this->array->set(index, val, ctx);
}
IDomVariable* DomArray::get(int index, ThreadContext* ctx) throw() 
{
	if(index >= this->array->size(ctx))
	{
		return nullptr;
	}
	return this->array->get(index, ctx);
}
int DomArray::getDomType(ThreadContext* ctx) throw() 
{
	return IDomVariable::TYPE_ARRAY;
}
IDomVariable* DomArray::toDom(ThreadContext* ctx) throw() 
{
	return this;
}
int DomArray::getVariableClass(ThreadContext* ctx) throw() 
{
	return IAlinousVariable::CLASS_DOM;
}
IAlinousVariable* DomArray::copy(ThreadContext* ctx)
{
	DomArray* array = (new(ctx) DomArray(ctx));
	int maxLoop = this->array->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IDomVariable* dm = this->array->get(i, ctx);
		array->put(static_cast<IDomVariable*>(dm->copy(ctx)), ctx);
	}
	return nullptr;
}
IDomVariable* DomArray::toDomVariable(ThreadContext* ctx) throw() 
{
	return this;
}
IAlinousVariable* DomArray::add(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::add(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::add(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::add(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::add(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::add(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::add(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::add(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::add(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::add(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::minus(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::minus(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::minus(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::minus(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::minus(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::minus(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::minus(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::minus(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::minus(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::minus(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::multiply(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::multiply(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::multiply(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::multiply(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::multiply(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::multiply(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::multiply(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::multiply(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::multiply(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::multiply(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::div(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::div(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::div(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::div(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::div(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::div(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::div(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::div(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::div(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::div(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::bitReverse(ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::add(IAlinousVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::minus(IAlinousVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::multiply(IAlinousVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::div(IAlinousVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::add(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::minus(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::multiply(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::div(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
bool DomArray::isNull(ThreadContext* ctx) throw() 
{
	return this->array->isEmpty(ctx);
}
bool DomArray::isArray(ThreadContext* ctx) throw() 
{
	return true;
}
IAlinousVariable* DomArray::shiftLeft(IAlinousVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::shiftLeft(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::shiftLeft(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::shiftLeft(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::shiftLeft(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::shiftLeft(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::shiftLeft(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::shiftLeft(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::shiftLeft(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::shiftLeft(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::shiftLeft(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::shiftLeft(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::shiftRight(IAlinousVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::shiftRight(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::shiftRight(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::shiftRight(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::shiftRight(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::shiftRight(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::shiftRight(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::shiftRight(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::shiftRight(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::shiftRight(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::shiftRight(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::shiftRight(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::modulo(IAlinousVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::modulo(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::modulo(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::modulo(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::modulo(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::modulo(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::modulo(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::modulo(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::modulo(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::modulo(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::modulo(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::modulo(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::substitute(IAlinousVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::substitute(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::substitute(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::substitute(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::substitute(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::substitute(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::substitute(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::substitute(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::substitute(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::substitute(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::substitute(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::substitute(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
int DomArray::compareTo(IAlinousVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
int DomArray::compareTo(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
int DomArray::compareTo(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
int DomArray::compareTo(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
int DomArray::compareTo(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
int DomArray::compareTo(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
int DomArray::compareTo(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
int DomArray::compareTo(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
int DomArray::compareTo(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
int DomArray::compareTo(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
int DomArray::compareTo(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
int DomArray::compareTo(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
bool DomArray::isTrue(ThreadContext* ctx)
{
	return !this->array->isEmpty(ctx);
}
IAlinousVariable* DomArray::bitOr(IAlinousVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::bitOr(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::bitOr(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::bitOr(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::bitOr(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::bitOr(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::bitOr(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::bitOr(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::bitOr(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::bitOr(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::bitOr(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::bitOr(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::bitAnd(IAlinousVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::bitAnd(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::bitAnd(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::bitAnd(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::bitAnd(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::bitAnd(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::bitAnd(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::bitAnd(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::bitAnd(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::bitAnd(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::bitAnd(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::bitAnd(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::bitExor(IAlinousVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::bitExor(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::bitExor(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::bitExor(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::bitExor(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::bitExor(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::bitExor(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::bitExor(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::bitExor(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::bitExor(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::bitExor(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IAlinousVariable* DomArray::bitExor(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IDomVariable* DomArray::getByDescriptor(DomVariableDescriptor* desc, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ctx));
}
void DomArray::setProperty(String* key, IDomVariable* value, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ctx));
}
IDomVariableContainer* DomArray::getProperty(String* key, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ctx));
}
VariantValue* DomArray::toVariantValue(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ctx));
}
IAlinousVariable* DomArray::add(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ctx));
}
IAlinousVariable* DomArray::minus(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ctx));
}
IAlinousVariable* DomArray::multiply(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ctx));
}
IAlinousVariable* DomArray::div(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ctx));
}
IAlinousVariable* DomArray::shiftLeft(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ctx));
}
IAlinousVariable* DomArray::shiftRight(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ctx));
}
IAlinousVariable* DomArray::modulo(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ctx));
}
IAlinousVariable* DomArray::bitOr(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ctx));
}
IAlinousVariable* DomArray::bitAnd(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ctx));
}
IAlinousVariable* DomArray::bitExor(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ctx));
}
IAlinousVariable* DomArray::substitute(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ctx));
}
int DomArray::compareTo(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ctx));
}
IAlinousVariable* DomArray::shiftRightUnsigned(IAlinousVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ctx));
}
IAlinousVariable* DomArray::shiftRightUnsigned(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ctx));
}
IAlinousVariable* DomArray::shiftRightUnsigned(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ctx));
}
IAlinousVariable* DomArray::shiftRightUnsigned(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ctx));
}
IAlinousVariable* DomArray::shiftRightUnsigned(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ctx));
}
IAlinousVariable* DomArray::shiftRightUnsigned(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ctx));
}
IAlinousVariable* DomArray::shiftRightUnsigned(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ctx));
}
IAlinousVariable* DomArray::shiftRightUnsigned(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ctx));
}
IAlinousVariable* DomArray::shiftRightUnsigned(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ctx));
}
IAlinousVariable* DomArray::shiftRightUnsigned(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ctx));
}
IAlinousVariable* DomArray::shiftRightUnsigned(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ctx));
}
IAlinousVariable* DomArray::shiftRightUnsigned(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ctx));
}
IAlinousVariable* DomArray::shiftRightUnsigned(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ctx));
}
BoolVariable* DomArray::toBoolVariable(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1111(), ctx));
}
ByteVariable* DomArray::toByteVariable(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1111(), ctx));
}
CharVariable* DomArray::toCharVariable(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1111(), ctx));
}
ShortVariable* DomArray::toShortVariable(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1111(), ctx));
}
IntegerVariable* DomArray::toIntVariable(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1111(), ctx));
}
LongVariable* DomArray::toLongVariable(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1111(), ctx));
}
StringVariable* DomArray::toStringVariable(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1111(), ctx));
}
long long DomArray::getLongValue(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1111(), ctx));
}
BigDecimalVariable* DomArray::toBigDecimalVariable(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1111(), ctx));
}
FloatVariable* DomArray::toFloatVariable(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1111(), ctx));
}
DoubleVariable* DomArray::toDoubleVariable(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1111(), ctx));
}
TimeVariable* DomArray::toTimeVariable(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1111(), ctx));
}
TimestampVariable* DomArray::toTimestampVariable(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1111(), ctx));
}
IAlinousVariable* DomArray::add(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1111(), ctx));
}
IAlinousVariable* DomArray::add(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1111(), ctx));
}
IAlinousVariable* DomArray::minus(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1111(), ctx));
}
IAlinousVariable* DomArray::minus(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1111(), ctx));
}
IAlinousVariable* DomArray::multiply(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1111(), ctx));
}
IAlinousVariable* DomArray::multiply(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1111(), ctx));
}
IAlinousVariable* DomArray::div(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1111(), ctx));
}
IAlinousVariable* DomArray::div(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1111(), ctx));
}
IAlinousVariable* DomArray::shiftLeft(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1111(), ctx));
}
IAlinousVariable* DomArray::shiftLeft(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1111(), ctx));
}
IAlinousVariable* DomArray::shiftRight(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1111(), ctx));
}
IAlinousVariable* DomArray::shiftRight(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1111(), ctx));
}
IAlinousVariable* DomArray::shiftRightUnsigned(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1111(), ctx));
}
IAlinousVariable* DomArray::shiftRightUnsigned(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1111(), ctx));
}
IAlinousVariable* DomArray::modulo(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1111(), ctx));
}
IAlinousVariable* DomArray::modulo(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1111(), ctx));
}
IAlinousVariable* DomArray::bitOr(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1111(), ctx));
}
IAlinousVariable* DomArray::bitOr(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1111(), ctx));
}
IAlinousVariable* DomArray::bitAnd(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1111(), ctx));
}
IAlinousVariable* DomArray::bitAnd(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1111(), ctx));
}
IAlinousVariable* DomArray::bitExor(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1111(), ctx));
}
IAlinousVariable* DomArray::bitExor(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1111(), ctx));
}
IAlinousVariable* DomArray::substitute(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1111(), ctx));
}
IAlinousVariable* DomArray::substitute(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1111(), ctx));
}
int DomArray::compareTo(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1111(), ctx));
}
int DomArray::compareTo(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1111(), ctx));
}
IAlinousVariable* DomArray::substitute(TypedVariableArray* variable, ThreadContext* ctx)
{
	DomArray* arrayDom = static_cast<DomArray*>(variable->toDomVariable(ctx));
	GCUtils<ArrayList<IDomVariable> >::mv(this, &(this->array), arrayDom->array, ctx);
	return this;
}
void DomArray::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	this->cap = buff->getInt(ctx);
	this->num = buff->getInt(ctx);
	int maxLoop = buff->getInt(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IAlinousVariable* val = NetworkAlinousVariableFactory::fromNetworkData(buff, ctx);
		if(val->getVariableClass(ctx) != IAlinousVariable::CLASS_DOM)
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1112(), ctx));
		}
		this->array->add(static_cast<IDomVariable*>(val), ctx);
	}
}
void DomArray::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	buff->putInt(ICommandData::__DomArray, ctx);
	buff->putInt(this->cap, ctx);
	buff->putInt(this->num, ctx);
	int maxLoop = this->array->size(ctx);
	buff->putInt(maxLoop, ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IDomVariable* dom = this->array->get(i, ctx);
		dom->writeData(buff, ctx);
	}
}
DomArray* DomArray::importFromDebugXml(DomNode* node, ThreadContext* ctx) throw() 
{
	if(!node->getName(ctx)->equals(DomVariable::VAL_TYPE, ctx))
	{
		return nullptr;
	}
	DomArray* array = (new(ctx) DomArray(ctx));
	int maxLoop = node->getNumChildern(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		DomNode* n = node->getChildNodeAt(i, ctx);
		IDomVariable* val = DomVariableDebugXmlFactory::getDom(n, ctx);
		array->put(val, ctx);
	}
	return array;
}
int DomArray::ValueCompare::operator() (IAlinousVariable* _this, IAlinousVariable* variable, ThreadContext* ctx) const throw()
{
	return _this->compareTo(variable, ctx);
}
}}}

