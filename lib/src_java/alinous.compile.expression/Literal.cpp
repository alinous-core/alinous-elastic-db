#include "includes.h"


namespace alinous {namespace compile {namespace expression {



constexpr EnumBase __Literal__literalTypes::__DEFAULT_NULL;
constexpr EnumBase __Literal__literalTypes::INTEGER_LITERAL;
constexpr EnumBase __Literal__literalTypes::FLOATING_POINT_LITERAL;
constexpr EnumBase __Literal__literalTypes::CHARACTER_LITERAL;
constexpr EnumBase __Literal__literalTypes::STRING_LITERAL;
constexpr EnumBase __Literal__literalTypes::SQL_STRING_LITERAL;
constexpr EnumBase __Literal__literalTypes::BOOLEAN;
constexpr EnumBase __Literal__literalTypes::NULL_LITERAL;


bool Literal::__init_done = __init_static_variables();
bool Literal::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"Literal", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 Literal::Literal(Literal::literalTypes type, ThreadContext* ctx) throw()  : IObject(ctx), AbstractExpression(ctx), value(nullptr)
{
	litType = type;
}
void Literal::__construct_impl(Literal::literalTypes type, ThreadContext* ctx) throw() 
{
	litType = type;
}
 Literal::~Literal() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void Literal::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"Literal", L"~Literal");
	__e_obj1.add(this->value, this);
	value = nullptr;
	if(!prepare){
		return;
	}
	AbstractExpression::__releaseRegerences(true, ctx);
}
bool Literal::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	return true;
}
bool Literal::isConstant(ThreadContext* ctx) throw() 
{
	return true;
}
bool Literal::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	return true;
}
String* Literal::getValue(ThreadContext* ctx) throw() 
{
	return value;
}
void Literal::setValue(String* value, ThreadContext* ctx) throw() 
{
	if(this->litType == literalTypes::STRING_LITERAL || this->litType == literalTypes::SQL_STRING_LITERAL)
	{
		__GC_MV(this, &(this->value), value->substring(1, value->length(ctx) - 1, ctx), String);
	}
		else 
	{
		__GC_MV(this, &(this->value), value, String);
	}
}
Literal::literalTypes Literal::getLitType(ThreadContext* ctx) throw() 
{
	return litType;
}
IAlinousVariable* Literal::resolveExpression(ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	VariantValue* vv = nullptr;
	int ivalue = 0;
	double dvalue = 0;
	wchar_t ch = 0;
	switch(this->litType) {
	case Literal::literalTypes::INTEGER_LITERAL:
		ivalue = Integer::parseInt(this->value, ctx);
		vv = (new(ctx) VariantValue(ivalue, ctx));
		return vv;
	case Literal::literalTypes::FLOATING_POINT_LITERAL:
		dvalue = Double::valueOf(this->value, ctx)->doubleValue(ctx);
		vv = (new(ctx) VariantValue(dvalue, ctx));
		return vv;
	case Literal::literalTypes::CHARACTER_LITERAL:
		ch = this->value->charAt(1, ctx);
		vv = (new(ctx) VariantValue(ch, ctx));
		return vv;
	case Literal::literalTypes::STRING_LITERAL:
		vv = (new(ctx) VariantValue(this->value, ctx));
		return vv;
	case Literal::literalTypes::BOOLEAN:
		vv = (new(ctx) VariantValue(ctx));
		if(this->value->equals(ConstStr::getCNST_STR_372(), ctx))
		{
			vv->setInt(1, ctx);
		}
				else 
		{
			vv->setInt(0, ctx);
		}
		return vv;
	case Literal::literalTypes::NULL_LITERAL:
		vv = (new(ctx) VariantValue(ctx));
	default:
		break ;
	}
	return nullptr;
}
ExpressionSourceId* Literal::getSourceId(ThreadContext* ctx) throw() 
{
	AlinousType* type = nullptr;
	switch(this->litType) {
	case Literal::literalTypes::INTEGER_LITERAL:
		type = (new(ctx) AlinousType(AlinousType::INT_TYPE, AlinousType::TYPE_PRIMITIVE, ctx));
		break ;
	case Literal::literalTypes::FLOATING_POINT_LITERAL:
		type = (new(ctx) AlinousType(AlinousType::DOUBLE_TYPE, AlinousType::TYPE_PRIMITIVE, ctx));
		break ;
	case Literal::literalTypes::CHARACTER_LITERAL:
		type = (new(ctx) AlinousType(AlinousType::CHAR_TYPE, AlinousType::TYPE_PRIMITIVE, ctx));
		break ;
	case Literal::literalTypes::STRING_LITERAL:
		type = (new(ctx) AlinousType(AlinousType::STRING_TYPE, AlinousType::TYPE_STANDARD_OBJ, ctx));
		break ;
	case Literal::literalTypes::BOOLEAN:
		type = (new(ctx) AlinousType(AlinousType::BOOL_TYPE, AlinousType::TYPE_PRIMITIVE, ctx));
		break ;
	case Literal::literalTypes::NULL_LITERAL:
		type = (new(ctx) AlinousType(AlinousType::NULL_TYPE, AlinousType::TYPE_STANDARD_OBJ, ctx));
		break ;
	default:
		break ;
	}
	return (new(ctx) ExpressionSourceId(nullptr, this, type, ctx));
}
bool Literal::isSQLExp(ThreadContext* ctx) throw() 
{
	return false;
}
int Literal::getExpressionType(ThreadContext* ctx) throw() 
{
	return IExpression::literalType;
}
Literal* Literal::intLiteral(int value, ThreadContext* ctx) throw() 
{
	Literal* lit = (new(ctx) Literal(literalTypes::INTEGER_LITERAL, ctx));
	lit->setValue(Integer::toString(value, ctx), ctx);
	return lit;
}
}}}

