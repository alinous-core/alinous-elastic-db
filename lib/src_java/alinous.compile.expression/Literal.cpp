#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/IAlinousElementVisitor.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.variant/VariantValue.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile/Token.h"
#include "alinous.compile.expression/IDomSegment.h"
#include "alinous.compile.expression/DomIndexSegment.h"
#include "alinous.compile.expression/DomNameSegment.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile.analyse/AlinousType.h"
#include "alinous.compile.declare/AlinousName.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile.expression/AbstractExpression.h"
#include "alinous.compile.expression/FunctionArguments.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile.analyse/DomVariableDeclareSource.h"
#include "alinous.compile.expression/DomVariableDescriptor.h"
#include "alinous.compile.expression/Literal.h"
#include "alinous.compile.expression/SubExpression.h"
#include "alinous.compile.expression/AbstractCollectionExpression.h"
#include "alinous.compile.expression/AdditiveExpression.h"
#include "alinous.compile.expression/MultiplicativeExpression.h"
#include "alinous.compile.expression/ShiftExpression.h"
#include "alinous.compile.expression/AllocationExpression.h"
#include "alinous.compile.expression/BitReverseExpression.h"
#include "alinous.compile.expression/CastExpression.h"
#include "alinous.compile.expression/ConditionalExpression.h"
#include "alinous.compile.expression/BooleanLiteral.h"
#include "alinous.compile.expression/NullLiteral.h"
#include "alinous.compile.expression/ParenthesisExpression.h"
#include "alinous.compile.expression/PreDecrementExpression.h"
#include "alinous.compile.expression/PreIncrementExpression.h"
#include "alinous.compile.expression/UnaryExpression.h"
#include "alinous.compile.expression/IExpressionFactory.h"

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
 Literal::Literal(ThreadContext* ctx) throw()  : IObject(ctx), AbstractExpression(ctx), value(nullptr)
{
}
void Literal::__construct_impl(ThreadContext* ctx) throw() 
{
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
void Literal::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	__readData(buff, ctx);
}
void Literal::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putInt(ICommandData::__Literal, ctx);
	__writeData(buff, ctx);
}
int Literal::fileSize(ThreadContext* ctx)
{
	int total = 4;
	total += 4;
	bool isnull = (this->value == nullptr);
	total += 1;
	if(!isnull)
	{
		total += this->value->length(ctx) * 2 + 1;
	}
	return total;
}
void Literal::toFileEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	builder->putInt(IExpressionFactory::__Literal, ctx);
	__toFileEntry(builder, ctx);
}
void Literal::__toFileEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	int type = fromEnum(ctx);
	builder->putInt(type, ctx);
	bool isnull = (this->value == nullptr);
	builder->putBoolean(isnull, ctx);
	if(!isnull)
	{
		builder->putString(this->value, ctx);
	}
}
void Literal::fromFileEntry(FileStorageEntryFetcher* fetcher, ThreadContext* ctx)
{
	int num = fetcher->fetchInt(ctx);
	toEnum(num, ctx);
	bool isnull = fetcher->fetchBoolean(ctx);
	if(!isnull)
	{
		__GC_MV(this, &(this->value), fetcher->fetchString(ctx), String);
	}
}
void Literal::__readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	int num = buff->getInt(ctx);
	toEnum(num, ctx);
	bool isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		__GC_MV(this, &(this->value), buff->getString(ctx), String);
	}
}
void Literal::__writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	int type = fromEnum(ctx);
	buff->putInt(type, ctx);
	bool isnull = (this->value == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		buff->putString(this->value, ctx);
	}
}
int Literal::fromEnum(ThreadContext* ctx) throw() 
{
	switch(this->litType) {
	case Literal::literalTypes::INTEGER_LITERAL:
		return 1;
	case Literal::literalTypes::FLOATING_POINT_LITERAL:
		return 2;
	case Literal::literalTypes::CHARACTER_LITERAL:
		return 3;
	case Literal::literalTypes::STRING_LITERAL:
		return 4;
	case Literal::literalTypes::SQL_STRING_LITERAL:
		return 5;
	case Literal::literalTypes::BOOLEAN:
		return 6;
	case Literal::literalTypes::NULL_LITERAL:
		return 7;
	default:
		break ;
	}
	return 7;
}
void Literal::toEnum(int num, ThreadContext* ctx) throw() 
{
	switch(num) {
	case 1:
		this->litType = literalTypes::INTEGER_LITERAL;
		break ;
	case 2:
		this->litType = literalTypes::FLOATING_POINT_LITERAL;
		break ;
	case 3:
		this->litType = literalTypes::CHARACTER_LITERAL;
		break ;
	case 4:
		this->litType = literalTypes::STRING_LITERAL;
		break ;
	case 5:
		this->litType = literalTypes::SQL_STRING_LITERAL;
		break ;
	case 6:
		this->litType = literalTypes::BOOLEAN;
		break ;
	case 7:
	default:
		this->litType = literalTypes::NULL_LITERAL;
		break ;
	}
}
Literal* Literal::intLiteral(int value, ThreadContext* ctx) throw() 
{
	Literal* lit = (new(ctx) Literal(literalTypes::INTEGER_LITERAL, ctx));
	lit->setValue(Integer::toString(value, ctx), ctx);
	return lit;
}
void Literal::__cleanUp(ThreadContext* ctx){
}
}}}

