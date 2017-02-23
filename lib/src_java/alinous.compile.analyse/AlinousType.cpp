#include "includes.h"


namespace alinous {namespace compile {namespace analyse {





constexpr const int AlinousType::TYPE_PRIMITIVE;
constexpr const int AlinousType::TYPE_STANDARD_OBJ;
constexpr const int AlinousType::TYPE_CLASS_OBJ;
constexpr const int AlinousType::TYPE_DOM;
constexpr const int AlinousType::TYPE_VOID;
constexpr const int AlinousType::NULL_TYPE;
constexpr const int AlinousType::BOOL_TYPE;
constexpr const int AlinousType::BYTE_TYPE;
constexpr const int AlinousType::SHORT_TYPE;
constexpr const int AlinousType::CHAR_TYPE;
constexpr const int AlinousType::INT_TYPE;
constexpr const int AlinousType::LONG_TYPE;
constexpr const int AlinousType::FLOAT_TYPE;
constexpr const int AlinousType::DOUBLE_TYPE;
constexpr const int AlinousType::TIME;
constexpr const int AlinousType::TIMESTAMP;
constexpr const int AlinousType::BIGDECIMAL;
constexpr const int AlinousType::STRING_TYPE;
constexpr const int AlinousType::OBJECT_TYPE;
bool AlinousType::__init_done = __init_static_variables();
bool AlinousType::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AlinousType", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AlinousType::AlinousType(AlinousClass* clazz, ThreadContext* ctx) throw()  : IObject(ctx), ICommandData(ctx), typeClass(0), clazz(nullptr), type(0), dimension(0)
{
	__GC_MV(this, &(this->clazz), clazz, AlinousClass);
	this->typeClass = TYPE_CLASS_OBJ;
}
void AlinousType::__construct_impl(AlinousClass* clazz, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->clazz), clazz, AlinousClass);
	this->typeClass = TYPE_CLASS_OBJ;
}
 AlinousType::AlinousType(int type, int typeClass, ThreadContext* ctx) throw()  : IObject(ctx), ICommandData(ctx), typeClass(0), clazz(nullptr), type(0), dimension(0)
{
	this->type = type;
	this->typeClass = typeClass;
}
void AlinousType::__construct_impl(int type, int typeClass, ThreadContext* ctx) throw() 
{
	this->type = type;
	this->typeClass = typeClass;
}
 AlinousType::AlinousType(ThreadContext* ctx) throw()  : IObject(ctx), ICommandData(ctx), typeClass(0), clazz(nullptr), type(0), dimension(0)
{
	this->typeClass = TYPE_DOM;
	this->type = -1;
}
void AlinousType::__construct_impl(ThreadContext* ctx) throw() 
{
	this->typeClass = TYPE_DOM;
	this->type = -1;
}
 AlinousType::~AlinousType() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AlinousType::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"AlinousType", L"~AlinousType");
	__e_obj1.add(this->clazz, this);
	clazz = nullptr;
	if(!prepare){
		return;
	}
}
int AlinousType::getTypeClass(ThreadContext* ctx) throw() 
{
	return typeClass;
}
AlinousClass* AlinousType::getClazz(ThreadContext* ctx) throw() 
{
	return clazz;
}
int AlinousType::getType(ThreadContext* ctx) throw() 
{
	return type;
}
IAlinousVariable* AlinousType::makeDefault(ThreadContext* ctx) throw() 
{
	if(this->dimension == 0)
	{
		switch(this->typeClass) {
		case TYPE_PRIMITIVE:
			return returnPrimitive(ctx);
		case TYPE_STANDARD_OBJ:
			return returnStandardVariable(ctx);
		case TYPE_CLASS_OBJ:
			return returnClasssVariable(ctx);
		case TYPE_DOM:
			return (new(ctx) DocumentVariable(ctx));
		case TYPE_VOID:
		default:
			break ;
		}
	}
	TypedVariableArray* arratVar = (new(ctx) TypedVariableArray(ctx));
	return arratVar;
}
int AlinousType::getDimension(ThreadContext* ctx) throw() 
{
	return dimension;
}
void AlinousType::setDimension(int dimension, ThreadContext* ctx) throw() 
{
	this->dimension = dimension;
}
void AlinousType::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	this->typeClass = buff->getInt(ctx);
	bool isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<AlinousClass*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_952(), ctx));
		}
		__GC_MV(this, &(this->clazz), static_cast<AlinousClass*>(el), AlinousClass);
	}
	this->type = buff->getInt(ctx);
	this->dimension = buff->getInt(ctx);
}
void AlinousType::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	buff->putInt(this->typeClass, ctx);
	bool isnull = (this->clazz == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->clazz->writeData(buff, ctx);
	}
	buff->putInt(this->type, ctx);
	buff->putInt(this->dimension, ctx);
}
IAlinousVariable* AlinousType::returnClasssVariable(ThreadContext* ctx) throw() 
{
	AlinousClassVariable* val = (new(ctx) AlinousClassVariable(this->clazz, ctx));
	return val;
}
IAlinousVariable* AlinousType::returnStandardVariable(ThreadContext* ctx) throw() 
{
	switch(this->type) {
	case TIME:
		return (new(ctx) TimeVariable((new(ctx) TimeOnlyTimestamp(System::currentTimeMillis(ctx), ctx)), ctx));
	case TIMESTAMP:
		return (new(ctx) TimestampVariable((new(ctx) Timestamp(System::currentTimeMillis(ctx), ctx)), ctx));
	case BIGDECIMAL:
		return (new(ctx) BigDecimalVariable((new(ctx) BigDecimal(0, ctx)), ctx));
	case STRING_TYPE:
		return (new(ctx) StringVariable(ctx));
	default:
		break ;
	}
	return nullptr;
}
IAlinousVariable* AlinousType::returnPrimitive(ThreadContext* ctx) throw() 
{
	switch(this->type) {
	case BOOL_TYPE:
		return (new(ctx) BoolVariable(ctx));
	case BYTE_TYPE:
		return (new(ctx) ByteVariable(ctx));
	case SHORT_TYPE:
		return (new(ctx) ShortVariable(ctx));
	case CHAR_TYPE:
		return (new(ctx) CharVariable(ctx));
	case INT_TYPE:
		return (new(ctx) IntegerVariable(ctx));
	case LONG_TYPE:
		return (new(ctx) LongVariable(ctx));
	case FLOAT_TYPE:
		return (new(ctx) FloatVariable(ctx));
	case DOUBLE_TYPE:
		return (new(ctx) DoubleVariable(ctx));
	case NULL_TYPE:
	default:
		break ;
	}
	return nullptr;
}
void AlinousType::fillArray(int level, ScriptMachine* machine, TypedVariableArray* parent, AlinousType* analysedType, ArrayList<IExpression>* arrayCapacity, bool debug, ThreadContext* ctx)
{
	IExpression* exp = arrayCapacity->get(level, ctx);
	IAlinousVariable* capV = exp->resolveExpression(machine, debug, ctx);
	int fillCap = capV->getIntValue(ctx);
	if(level == (arrayCapacity->size(ctx) - 1))
	{
		fillLeafArray(fillCap, parent, analysedType, ctx);
		return;
	}
	int newLevel = level + 1;
	for(int i = 0; i != fillCap; ++i)
	{
		TypedVariableArray* arratVar = (new(ctx) TypedVariableArray(ctx));
		parent->addElement(arratVar, ctx);
		fillArray(newLevel, machine, arratVar, analysedType, arrayCapacity, debug, ctx);
	}
	return;
}
TypedVariableArray* AlinousType::fillLeafArray(int count, TypedVariableArray* arrayVar, AlinousType* analysedType, ThreadContext* ctx)
{
	for(int i = 0; i != count; ++i)
	{
		ITypedVariable* variable = newBlankVariable(analysedType, ctx);
		arrayVar->addElement(variable, ctx);
	}
	return arrayVar;
}
ITypedVariable* AlinousType::newBlankVariable(AlinousType* analysedType, ThreadContext* ctx)
{
	switch(analysedType->getTypeClass(ctx)) {
	case AlinousType::TYPE_STANDARD_OBJ:
		switch(analysedType->getType(ctx)) {
		case AlinousType::STRING_TYPE:
			return (new(ctx) StringVariable(ctx));
		case AlinousType::TIME:
			return (new(ctx) TimeVariable(ctx));
		case AlinousType::TIMESTAMP:
			return (new(ctx) TimestampVariable(ctx));
		case AlinousType::BIGDECIMAL:
			return (new(ctx) BigDecimalVariable(ctx));
		default:
			break ;
		}
		break ;
	case AlinousType::TYPE_CLASS_OBJ:
		return (new(ctx) AlinousClassVariable(analysedType->getClazz(ctx), ctx));
	case AlinousType::TYPE_PRIMITIVE:
		switch(analysedType->getType(ctx)) {
		case AlinousType::BOOL_TYPE:
			return (new(ctx) BoolVariable(ctx));
		case AlinousType::BYTE_TYPE:
			return (new(ctx) ByteVariable(ctx));
		case AlinousType::SHORT_TYPE:
			return (new(ctx) ShortVariable(ctx));
		case AlinousType::CHAR_TYPE:
			return (new(ctx) CharVariable(ctx));
		case AlinousType::INT_TYPE:
			return (new(ctx) IntegerVariable(ctx));
		case AlinousType::LONG_TYPE:
			return (new(ctx) LongVariable(ctx));
		case AlinousType::FLOAT_TYPE:
			return (new(ctx) FloatVariable(ctx));
		case AlinousType::DOUBLE_TYPE:
			return (new(ctx) DoubleVariable(ctx));
		case AlinousType::NULL_TYPE:
		default:
			break ;
		}
	default:
		break ;
	}
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_951(), ctx));
}
}}}

