#include "includes.h"


namespace alinous {namespace runtime {namespace dom {namespace clazz {





String* AlinousClassVariable::CLASS_VARIABLE = ConstStr::getCNST_STR_1118();
String* AlinousClassVariable::CLASS_TYPE = ConstStr::getCNST_STR_1119();
String* AlinousClassVariable::MEMBERS = ConstStr::getCNST_STR_1118();
bool AlinousClassVariable::__init_done = __init_static_variables();
bool AlinousClassVariable::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AlinousClassVariable", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AlinousClassVariable::AlinousClassVariable(AlinousClass* classDeclare, ThreadContext* ctx) throw()  : IObject(ctx), IAlinousClassVariable(ctx), memberValues(GCUtils<HashMap<String,IAlinousVariable> >::ins(this, (new(ctx) HashMap<String,IAlinousVariable>(ctx)), ctx, __FILEW__, __LINE__, L"")), classDeclare(nullptr), nullObject(0)
{
	__GC_MV(this, &(this->classDeclare), classDeclare, AlinousClass);
	this->nullObject = true;
}
void AlinousClassVariable::__construct_impl(AlinousClass* classDeclare, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->classDeclare), classDeclare, AlinousClass);
	this->nullObject = true;
}
 AlinousClassVariable::AlinousClassVariable(ThreadContext* ctx) throw()  : IObject(ctx), IAlinousClassVariable(ctx), memberValues(GCUtils<HashMap<String,IAlinousVariable> >::ins(this, (new(ctx) HashMap<String,IAlinousVariable>(ctx)), ctx, __FILEW__, __LINE__, L"")), classDeclare(nullptr), nullObject(0)
{
	this->nullObject = true;
}
void AlinousClassVariable::__construct_impl(ThreadContext* ctx) throw() 
{
	this->nullObject = true;
}
 AlinousClassVariable::~AlinousClassVariable() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AlinousClassVariable::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"AlinousClassVariable", L"~AlinousClassVariable");
	__e_obj1.add(this->memberValues, this);
	memberValues = nullptr;
	__e_obj1.add(this->classDeclare, this);
	classDeclare = nullptr;
	if(!prepare){
		return;
	}
}
void AlinousClassVariable::outDebugXml(DomNode* parentNode, String* nm, ThreadContext* ctx) throw() 
{
	DomNode* node = (new(ctx) DomNode(CLASS_VARIABLE, ctx));
	parentNode->addChild(node, ctx);
	StringBuilder* buff = (new(ctx) StringBuilder(ctx));
	AlinousName* name = this->classDeclare->getName(ctx);
	buff->append(name->getPackageName(ctx), ctx)->append(ConstStr::getCNST_STR_950(), ctx)->append(name->getClassName(ctx), ctx);
	Attribute* attr = (new(ctx) Attribute(CLASS_TYPE, buff->toString(ctx), node, ctx));
	parentNode->addAttribute(attr, ctx);
	DomNode* mambers = (new(ctx) DomNode(MEMBERS, ctx));
	node->addChild(mambers, ctx);
	Iterator<String>* it = this->memberValues->keySet(ctx)->iterator(ctx);
	while(it->hasNext(ctx))
	{
		String* key = it->next(ctx);
		IAlinousVariable* val = this->memberValues->get(key, ctx);
		val->outDebugXml(mambers, nm, ctx);
	}
}
AlinousClass* AlinousClassVariable::getClassDeclare(ThreadContext* ctx) throw() 
{
	return classDeclare;
}
void AlinousClassVariable::setMemberVariable(String* name, IAlinousVariable* variable, ThreadContext* ctx) throw() 
{
	this->memberValues->put(name, variable, ctx);
	this->nullObject = false;
}
IAlinousVariable* AlinousClassVariable::getMemberVariable(String* name, ThreadContext* ctx) throw() 
{
	return this->memberValues->get(name, ctx);
}
int AlinousClassVariable::getTypedType(ThreadContext* ctx) throw() 
{
	return ITypedVariable::TYPE_CLASS_OBJECT;
}
int AlinousClassVariable::getVariableClass(ThreadContext* ctx) throw() 
{
	return IAlinousVariable::CLASS_OBJECT;
}
IAlinousVariable* AlinousClassVariable::copy(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IDomVariable* AlinousClassVariable::toDomVariable(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
bool AlinousClassVariable::isNull(ThreadContext* ctx) throw() 
{
	return this->nullObject;
}
String* AlinousClassVariable::toString(ThreadContext* ctx) throw() 
{
	if(this->nullObject)
	{
		return ConstStr::getCNST_STR_369();
	}
	int count = 0;
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	Iterator<String>* it = this->memberValues->keySet(ctx)->iterator(ctx);
	while(it->hasNext(ctx))
	{
		String* key = it->next(ctx);
		IAlinousVariable* val = this->memberValues->get(key, ctx);
		if(count != 0)
		{
			buff->append(ConstStr::getCNST_STR_73(), ctx);
		}
		buff->append(key, ctx)->append(ConstStr::getCNST_STR_1074(), ctx);
		if(val != nullptr)
		{
			buff->append(val->toString(ctx), ctx);
		}
				else 
		{
			buff->append(ConstStr::getCNST_STR_369(), ctx);
		}
		count ++ ;
	}
	return buff->toString(ctx);
}
bool AlinousClassVariable::isArray(ThreadContext* ctx) throw() 
{
	return false;
}
BoolVariable* AlinousClassVariable::toBoolVariable(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
ByteVariable* AlinousClassVariable::toByteVariable(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
CharVariable* AlinousClassVariable::toCharVariable(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
ShortVariable* AlinousClassVariable::toShortVariable(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IntegerVariable* AlinousClassVariable::toIntVariable(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
LongVariable* AlinousClassVariable::toLongVariable(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
StringVariable* AlinousClassVariable::toStringVariable(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
FloatVariable* AlinousClassVariable::toFloatVariable(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
DoubleVariable* AlinousClassVariable::toDoubleVariable(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
BigDecimalVariable* AlinousClassVariable::toBigDecimalVariable(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
TimeVariable* AlinousClassVariable::toTimeVariable(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
TimestampVariable* AlinousClassVariable::toTimestampVariable(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
int AlinousClassVariable::getIntValue(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
long long AlinousClassVariable::getLongValue(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
String* AlinousClassVariable::getStringValue(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::add(IAlinousVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::add(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::add(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::add(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::add(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::add(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::add(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::add(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::add(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::add(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::add(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::add(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::add(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::add(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::add(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::minus(IAlinousVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::minus(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::minus(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::minus(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::minus(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::minus(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::minus(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::minus(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::minus(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::minus(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::minus(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::minus(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::minus(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::minus(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::minus(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::multiply(IAlinousVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::multiply(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::multiply(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::multiply(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::multiply(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::multiply(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::multiply(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::multiply(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::multiply(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::multiply(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::multiply(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::multiply(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::multiply(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::multiply(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::multiply(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::div(IAlinousVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::div(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::div(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::div(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::div(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::div(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::div(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::div(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::div(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::div(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::div(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::div(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::div(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::div(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::div(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::shiftLeft(IAlinousVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::shiftLeft(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::shiftLeft(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::shiftLeft(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::shiftLeft(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::shiftLeft(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::shiftLeft(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::shiftLeft(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::shiftLeft(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::shiftLeft(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::shiftLeft(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::shiftLeft(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::shiftLeft(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::shiftLeft(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::shiftLeft(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::shiftRight(IAlinousVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::shiftRight(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::shiftRight(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::shiftRight(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::shiftRight(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::shiftRight(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::shiftRight(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::shiftRight(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::shiftRight(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::shiftRight(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::shiftRight(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::shiftRight(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::shiftRight(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::shiftRight(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::shiftRight(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::shiftRightUnsigned(IAlinousVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::shiftRightUnsigned(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::shiftRightUnsigned(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::shiftRightUnsigned(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::shiftRightUnsigned(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::shiftRightUnsigned(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::shiftRightUnsigned(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::shiftRightUnsigned(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::shiftRightUnsigned(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::shiftRightUnsigned(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::shiftRightUnsigned(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::shiftRightUnsigned(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::shiftRightUnsigned(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::shiftRightUnsigned(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::shiftRightUnsigned(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::modulo(IAlinousVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::modulo(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::modulo(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::modulo(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::modulo(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::modulo(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::modulo(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::modulo(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::modulo(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::modulo(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::modulo(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::modulo(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::modulo(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::modulo(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::modulo(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::bitOr(IAlinousVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::bitOr(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::bitOr(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::bitOr(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::bitOr(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::bitOr(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::bitOr(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::bitOr(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::bitOr(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::bitOr(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::bitOr(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::bitOr(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::bitOr(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::bitOr(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::bitOr(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::bitAnd(IAlinousVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::bitAnd(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::bitAnd(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::bitAnd(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::bitAnd(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::bitAnd(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::bitAnd(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::bitAnd(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::bitAnd(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::bitAnd(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::bitAnd(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::bitAnd(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::bitAnd(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::bitAnd(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::bitAnd(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::bitExor(IAlinousVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::bitExor(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::bitExor(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::bitExor(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::bitExor(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::bitExor(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::bitExor(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::bitExor(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::bitExor(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::bitExor(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::bitExor(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::bitExor(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::bitExor(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::bitExor(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::bitExor(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::bitReverse(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::substitute(IAlinousVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::substitute(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::substitute(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::substitute(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::substitute(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::substitute(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::substitute(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::substitute(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::substitute(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::substitute(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::substitute(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::substitute(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::substitute(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::substitute(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::substitute(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
IAlinousVariable* AlinousClassVariable::substitute(TypedVariableArray* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
int AlinousClassVariable::compareTo(IAlinousVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
int AlinousClassVariable::compareTo(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
int AlinousClassVariable::compareTo(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
int AlinousClassVariable::compareTo(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
int AlinousClassVariable::compareTo(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
int AlinousClassVariable::compareTo(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
int AlinousClassVariable::compareTo(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
int AlinousClassVariable::compareTo(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
int AlinousClassVariable::compareTo(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
int AlinousClassVariable::compareTo(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
int AlinousClassVariable::compareTo(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
int AlinousClassVariable::compareTo(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
int AlinousClassVariable::compareTo(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
int AlinousClassVariable::compareTo(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
int AlinousClassVariable::compareTo(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
bool AlinousClassVariable::isTrue(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
VariantValue* AlinousClassVariable::toVariantValue(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1117(), ctx));
}
void AlinousClassVariable::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	int maxLoop = buff->getInt(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		String* key = buff->getString(ctx);
		IAlinousVariable* val = NetworkAlinousVariableFactory::fromNetworkData(buff, ctx);
		this->memberValues->put(key, val, ctx);
	}
	bool isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<AlinousClass*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_952(), ctx));
		}
	}
	this->nullObject = buff->getBoolean(ctx);
}
void AlinousClassVariable::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putInt(ICommandData::__AlinousClass, ctx);
	int size = this->memberValues->size(ctx);
	buff->putInt(size, ctx);
	Iterator<String>* it = this->memberValues->keySet(ctx)->iterator(ctx);
	while(it->hasNext(ctx))
	{
		String* key = it->next(ctx);
		IAlinousVariable* val = this->memberValues->get(key, ctx);
		buff->putString(key, ctx);
		val->writeData(buff, ctx);
	}
	bool isnull = (this->classDeclare == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->classDeclare->writeData(buff, ctx);
	}
	buff->putBoolean(this->nullObject, ctx);
}
int AlinousClassVariable::ValueCompare::operator() (IAlinousVariable* _this, IAlinousVariable* variable, ThreadContext* ctx) const throw()
{
	return _this->compareTo(variable, ctx);
}
}}}}

