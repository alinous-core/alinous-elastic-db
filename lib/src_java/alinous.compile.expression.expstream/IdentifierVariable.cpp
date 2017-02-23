#include "includes.h"


namespace alinous {namespace compile {namespace expression {namespace expstream {





bool IdentifierVariable::__init_done = __init_static_variables();
bool IdentifierVariable::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"IdentifierVariable", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 IdentifierVariable::IdentifierVariable(DomVariableDescriptor* id, ThreadContext* ctx) throw()  : IObject(ctx), IAlinousVariable(ctx), id(nullptr), arrayIndexes(nullptr), domDescriptor(nullptr)
{
	__GC_MV(this, &(this->domDescriptor), id, DomVariableDescriptor);
}
void IdentifierVariable::__construct_impl(DomVariableDescriptor* id, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->domDescriptor), id, DomVariableDescriptor);
}
 IdentifierVariable::IdentifierVariable(String* id, ThreadContext* ctx) throw()  : IObject(ctx), IAlinousVariable(ctx), id(nullptr), arrayIndexes(nullptr), domDescriptor(nullptr)
{
	__GC_MV(this, &(this->id), id, String);
}
void IdentifierVariable::__construct_impl(String* id, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->id), id, String);
}
 IdentifierVariable::IdentifierVariable(String* id, ArrayList<IExpression>* arrayIndexes, ThreadContext* ctx) throw()  : IObject(ctx), IAlinousVariable(ctx), id(nullptr), arrayIndexes(nullptr), domDescriptor(nullptr)
{
	__GC_MV(this, &(this->id), id, String);
	GCUtils<ArrayList<IExpression> >::mv(this, &(this->arrayIndexes), arrayIndexes, ctx);
}
void IdentifierVariable::__construct_impl(String* id, ArrayList<IExpression>* arrayIndexes, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->id), id, String);
	GCUtils<ArrayList<IExpression> >::mv(this, &(this->arrayIndexes), arrayIndexes, ctx);
}
 IdentifierVariable::~IdentifierVariable() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void IdentifierVariable::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"IdentifierVariable", L"~IdentifierVariable");
	__e_obj1.add(this->id, this);
	id = nullptr;
	__e_obj1.add(this->arrayIndexes, this);
	arrayIndexes = nullptr;
	__e_obj1.add(this->domDescriptor, this);
	domDescriptor = nullptr;
	if(!prepare){
		return;
	}
}
void IdentifierVariable::outDebugXml(DomNode* parentNode, String* name, ThreadContext* ctx) throw() 
{
}
String* IdentifierVariable::getId(ThreadContext* ctx) throw() 
{
	return id;
}
DomVariableDescriptor* IdentifierVariable::getDomDescriptor(ThreadContext* ctx) throw() 
{
	return domDescriptor;
}
void IdentifierVariable::addDomArrayIndex(int index, ThreadContext* ctx) throw() 
{
	Literal* lit = (new(ctx) Literal(Literal::literalTypes::INTEGER_LITERAL, ctx));
	lit->setValue(ConstStr::getCNST_STR_1021(), ctx);
	DomIndexSegment* idxSeg = (new(ctx) DomIndexSegment(lit, ctx));
	this->domDescriptor->addSegment(idxSeg, ctx);
}
bool IdentifierVariable::isDomDescriptor(ThreadContext* ctx) throw() 
{
	return this->domDescriptor != nullptr;
}
int IdentifierVariable::getVariableClass(ThreadContext* ctx) throw() 
{
	return IAlinousVariable::CLASS_IDENTIFIER;
}
IAlinousVariable* IdentifierVariable::copy(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IDomVariable* IdentifierVariable::toDomVariable(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
VariantValue* IdentifierVariable::toVariantValue(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
bool IdentifierVariable::isNull(ThreadContext* ctx) throw() 
{
	return false;
}
bool IdentifierVariable::isArray(ThreadContext* ctx) throw() 
{
	return false;
}
ArrayList<IExpression>* IdentifierVariable::getArrayIndexes(ThreadContext* ctx) throw() 
{
	return arrayIndexes;
}
BoolVariable* IdentifierVariable::toBoolVariable(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
ByteVariable* IdentifierVariable::toByteVariable(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
CharVariable* IdentifierVariable::toCharVariable(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
ShortVariable* IdentifierVariable::toShortVariable(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IntegerVariable* IdentifierVariable::toIntVariable(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
LongVariable* IdentifierVariable::toLongVariable(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
StringVariable* IdentifierVariable::toStringVariable(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
FloatVariable* IdentifierVariable::toFloatVariable(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
DoubleVariable* IdentifierVariable::toDoubleVariable(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
BigDecimalVariable* IdentifierVariable::toBigDecimalVariable(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
TimeVariable* IdentifierVariable::toTimeVariable(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
TimestampVariable* IdentifierVariable::toTimestampVariable(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
int IdentifierVariable::getIntValue(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
long long IdentifierVariable::getLongValue(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
String* IdentifierVariable::getStringValue(ThreadContext* ctx)
{
	return this->id;
}
IAlinousVariable* IdentifierVariable::add(IAlinousVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::add(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::add(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::add(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::add(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::add(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::add(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::add(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::add(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::add(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::add(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::add(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::add(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::add(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::add(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::minus(IAlinousVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::minus(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::minus(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::minus(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::minus(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::minus(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::minus(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::minus(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::minus(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::minus(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::minus(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::minus(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::minus(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::minus(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::minus(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::multiply(IAlinousVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::multiply(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::multiply(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::multiply(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::multiply(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::multiply(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::multiply(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::multiply(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::multiply(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::multiply(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::multiply(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::multiply(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::multiply(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::multiply(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::multiply(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::div(IAlinousVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::div(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::div(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::div(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::div(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::div(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::div(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::div(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::div(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::div(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::div(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::div(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::div(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::div(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::div(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::shiftLeft(IAlinousVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::shiftLeft(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::shiftLeft(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::shiftLeft(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::shiftLeft(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::shiftLeft(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::shiftLeft(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::shiftLeft(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::shiftLeft(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::shiftLeft(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::shiftLeft(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::shiftLeft(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::shiftLeft(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::shiftLeft(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::shiftLeft(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::shiftRight(IAlinousVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::shiftRight(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::shiftRight(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::shiftRight(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::shiftRight(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::shiftRight(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::shiftRight(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::shiftRight(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::shiftRight(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::shiftRight(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::shiftRight(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::shiftRight(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::shiftRight(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::shiftRight(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::shiftRight(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::shiftRightUnsigned(IAlinousVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::shiftRightUnsigned(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::shiftRightUnsigned(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::shiftRightUnsigned(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::shiftRightUnsigned(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::shiftRightUnsigned(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::shiftRightUnsigned(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::shiftRightUnsigned(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::shiftRightUnsigned(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::shiftRightUnsigned(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::shiftRightUnsigned(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::shiftRightUnsigned(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::shiftRightUnsigned(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::shiftRightUnsigned(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::shiftRightUnsigned(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::modulo(IAlinousVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::modulo(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::modulo(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::modulo(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::modulo(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::modulo(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::modulo(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::modulo(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::modulo(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::modulo(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::modulo(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::modulo(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::modulo(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::modulo(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::modulo(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::bitOr(IAlinousVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::bitOr(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::bitOr(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::bitOr(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::bitOr(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::bitOr(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::bitOr(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::bitOr(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::bitOr(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::bitOr(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::bitOr(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::bitOr(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::bitOr(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::bitOr(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::bitOr(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::bitAnd(IAlinousVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::bitAnd(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::bitAnd(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::bitAnd(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::bitAnd(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::bitAnd(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::bitAnd(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::bitAnd(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::bitAnd(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::bitAnd(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::bitAnd(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::bitAnd(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::bitAnd(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::bitAnd(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::bitAnd(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::bitExor(IAlinousVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::bitExor(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::bitExor(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::bitExor(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::bitExor(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::bitExor(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::bitExor(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::bitExor(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::bitExor(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::bitExor(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::bitExor(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::bitExor(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::bitExor(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::bitExor(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::bitExor(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::bitReverse(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::substitute(IAlinousVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::substitute(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::substitute(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::substitute(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::substitute(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::substitute(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::substitute(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::substitute(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::substitute(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::substitute(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::substitute(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::substitute(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::substitute(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::substitute(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::substitute(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
int IdentifierVariable::compareTo(IAlinousVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
int IdentifierVariable::compareTo(VariantValue* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
int IdentifierVariable::compareTo(DomVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
int IdentifierVariable::compareTo(BoolVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
int IdentifierVariable::compareTo(ByteVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
int IdentifierVariable::compareTo(CharVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
int IdentifierVariable::compareTo(DoubleVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
int IdentifierVariable::compareTo(FloatVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
int IdentifierVariable::compareTo(IntegerVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
int IdentifierVariable::compareTo(LongVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
int IdentifierVariable::compareTo(ShortVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
int IdentifierVariable::compareTo(StringVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
int IdentifierVariable::compareTo(BigDecimalVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
int IdentifierVariable::compareTo(TimeVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
int IdentifierVariable::compareTo(TimestampVariable* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
bool IdentifierVariable::isTrue(ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
IAlinousVariable* IdentifierVariable::substitute(TypedVariableArray* variable, ThreadContext* ctx)
{
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1022(), ctx));
}
void IdentifierVariable::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	bool isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		__GC_MV(this, &(this->id), buff->getString(ctx), String);
	}
	isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		int maxLoop = buff->getInt(ctx);
		for(int i = 0; i < maxLoop; ++i)
		{
			IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
			if(el == nullptr || !((dynamic_cast<IExpression*>(el) != 0)))
			{
				throw (new(ctx) VariableException(ConstStr::getCNST_STR_980(), ctx));
			}
			this->arrayIndexes->add(static_cast<IExpression*>(el), ctx);
		}
	}
	isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<DomVariableDescriptor*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_979(), ctx));
		}
		__GC_MV(this, &(this->domDescriptor), static_cast<DomVariableDescriptor*>(el), DomVariableDescriptor);
	}
}
void IdentifierVariable::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	buff->putInt(ICommandData::__IdentifierVariable, ctx);
	bool isnull = (this->id == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		buff->putString(this->id, ctx);
	}
	isnull = (this->arrayIndexes == nullptr);
	if(!isnull)
	{
		int maxLoop = this->arrayIndexes->size(ctx);
		buff->putInt(maxLoop, ctx);
		for(int i = 0; i < maxLoop; ++i)
		{
			IExpression* exp = this->arrayIndexes->get(i, ctx);
			exp->writeData(buff, ctx);
		}
	}
	isnull = (this->domDescriptor == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->domDescriptor->writeData(buff, ctx);
	}
}
int IdentifierVariable::ValueCompare::operator() (IAlinousVariable* _this, IAlinousVariable* variable, ThreadContext* ctx) const throw()
{
	return _this->compareTo(variable, ctx);
}
}}}}

