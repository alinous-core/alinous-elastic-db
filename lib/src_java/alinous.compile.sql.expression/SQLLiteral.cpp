#include "includes.h"


namespace alinous {namespace compile {namespace sql {namespace expression {



constexpr EnumBase __SQLLiteral__sqlliteralType::__DEFAULT_NULL;
constexpr EnumBase __SQLLiteral__sqlliteralType::INTEGER_LITERAL;
constexpr EnumBase __SQLLiteral__sqlliteralType::FLOATING_POINT_LITERAL;
constexpr EnumBase __SQLLiteral__sqlliteralType::CHARACTER_LITERAL;
constexpr EnumBase __SQLLiteral__sqlliteralType::STRING_LITERAL;
constexpr EnumBase __SQLLiteral__sqlliteralType::BOOLEAN;
constexpr EnumBase __SQLLiteral__sqlliteralType::NULL_LITERAL;


bool SQLLiteral::__init_done = __init_static_variables();
bool SQLLiteral::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"SQLLiteral", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 SQLLiteral::SQLLiteral(SQLLiteral::sqlliteralType type, ThreadContext* ctx) throw()  : IObject(ctx), AbstractSQLExpression(ctx), vvalue(nullptr), value(nullptr)
{
	litType = type;
}
void SQLLiteral::__construct_impl(SQLLiteral::sqlliteralType type, ThreadContext* ctx) throw() 
{
	litType = type;
}
 SQLLiteral::~SQLLiteral() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void SQLLiteral::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"SQLLiteral", L"~SQLLiteral");
	__e_obj1.add(this->vvalue, this);
	vvalue = nullptr;
	__e_obj1.add(this->value, this);
	value = nullptr;
	if(!prepare){
		return;
	}
	AbstractSQLExpression::__releaseRegerences(true, ctx);
}
bool SQLLiteral::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	return true;
}
bool SQLLiteral::isConstant(ThreadContext* ctx) throw() 
{
	return true;
}
String* SQLLiteral::getValue(ThreadContext* ctx) throw() 
{
	return value;
}
void SQLLiteral::setValue(String* value, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->value), value, String);
}
SQLLiteral::sqlliteralType SQLLiteral::getLitType(ThreadContext* ctx) throw() 
{
	return litType;
}
IAlinousVariable* SQLLiteral::resolveExpression(ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	return this->vvalue;
}
bool SQLLiteral::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	int ivalue = 0;
	double dvalue = 0;
	wchar_t ch = 0;
	switch(this->litType) {
	case SQLLiteral::sqlliteralType::INTEGER_LITERAL:
		ivalue = Integer::parseInt(this->value, ctx);
		__GC_MV(this, &(this->vvalue), (new(ctx) VariantValue(ivalue, ctx)), VariantValue);
		break ;
	case SQLLiteral::sqlliteralType::FLOATING_POINT_LITERAL:
		dvalue = Double::valueOf(this->value, ctx)->doubleValue(ctx);
		__GC_MV(this, &(this->vvalue), (new(ctx) VariantValue(dvalue, ctx)), VariantValue);
		break ;
	case SQLLiteral::sqlliteralType::CHARACTER_LITERAL:
		ch = this->value->charAt(1, ctx);
		__GC_MV(this, &(this->vvalue), (new(ctx) VariantValue(ch, ctx)), VariantValue);
		break ;
	case SQLLiteral::sqlliteralType::STRING_LITERAL:
		__GC_MV(this, &(this->vvalue), (new(ctx) VariantValue(this->value->substring(1, this->value->length(ctx) - 1, ctx), ctx)), VariantValue);
		break ;
	case SQLLiteral::sqlliteralType::BOOLEAN:
		if(this->value->equals(ConstStr::getCNST_STR_372(), ctx))
		{
			__GC_MV(this, &(this->vvalue), (new(ctx) VariantValue(1, ctx)), VariantValue);
		}
				else 
		{
			__GC_MV(this, &(this->vvalue), (new(ctx) VariantValue(0, ctx)), VariantValue);
		}
		break ;
	case SQLLiteral::sqlliteralType::NULL_LITERAL:
		__GC_MV(this, &(this->vvalue), (new(ctx) VariantValue(ctx)), VariantValue);
		break ;
	default:
		break ;
	}
	return true;
}
ExpressionSourceId* SQLLiteral::getSourceId(ThreadContext* ctx) throw() 
{
	AlinousType* type = nullptr;
	switch(this->litType) {
	case SQLLiteral::sqlliteralType::INTEGER_LITERAL:
		break ;
	case SQLLiteral::sqlliteralType::FLOATING_POINT_LITERAL:
		break ;
	case SQLLiteral::sqlliteralType::CHARACTER_LITERAL:
		break ;
	case SQLLiteral::sqlliteralType::STRING_LITERAL:
		break ;
	case SQLLiteral::sqlliteralType::BOOLEAN:
		break ;
	case SQLLiteral::sqlliteralType::NULL_LITERAL:
	default:
		break ;
	}
	return (new(ctx) ExpressionSourceId(nullptr, this, type, ctx));
}
bool SQLLiteral::analyseSQL(SQLAnalyseContext* context, bool leftValue, bool debug, ThreadContext* ctx) throw() 
{
	return true;
}
bool SQLLiteral::hasTable(ScanTableIdentifier* table, ThreadContext* ctx) throw() 
{
	return false;
}
ArrayList<ScanTableColumnIdentifier>* SQLLiteral::getColumns(ThreadContext* ctx) throw() 
{
	return nullptr;
}
bool SQLLiteral::hasSubExp(ThreadContext* ctx) throw() 
{
	return false;
}
bool SQLLiteral::isJoinCondition(ThreadContext* ctx) throw() 
{
	return false;
}
void SQLLiteral::collectJoinCondition(ArrayList<ISQLExpression>* list, ThreadContext* ctx) throw() 
{
}
bool SQLLiteral::isColumnIdentifier(ThreadContext* ctx) throw() 
{
	return false;
}
ScanTableColumnIdentifier* SQLLiteral::toColumnIdentifier(ThreadContext* ctx) throw() 
{
	return nullptr;
}
VariantValue* SQLLiteral::resolveSQLExpression(ScanResultRecord* record, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	return static_cast<VariantValue*>(resolveExpression(machine, debug, ctx));
}
bool SQLLiteral::hasArrayResult(ThreadContext* ctx) throw() 
{
	return false;
}
ArrayList<VariantValue>* SQLLiteral::resolveSQLExpressionAsArray(ScanResultRecord* record, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1036(), ctx));
}
int SQLLiteral::getExpressionType(ThreadContext* ctx) throw() 
{
	return IExpression::sQLLiteralType;
}
void SQLLiteral::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	int num = buff->getInt(ctx);
	toEnum(num, ctx);
	bool isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		__GC_MV(this, &(this->value), buff->getString(ctx), String);
	}
}
void SQLLiteral::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putInt(ICommandData::__SQLLiteral, ctx);
	int type = fromEnum(ctx);
	buff->putInt(type, ctx);
	bool isnull = (this->value == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		buff->putString(this->value, ctx);
	}
}
int SQLLiteral::fileSize(ThreadContext* ctx)
{
	int total = 4;
	total += 4;
	bool isnull = (this->value == nullptr);
	total += 1;
	if(!isnull)
	{
		total += this->value->length(ctx) * 2 + 4;
	}
	return total;
}
void SQLLiteral::toFileEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	builder->putInt(IExpressionFactory::__SQLLiteral, ctx);
	int type = fromEnum(ctx);
	builder->putInt(type, ctx);
	bool isnull = (this->value == nullptr);
	builder->putBoolean(isnull, ctx);
	if(!isnull)
	{
		builder->putString(this->value, ctx);
	}
}
void SQLLiteral::fromFileEntry(FileStorageEntryFetcher* fetcher, ThreadContext* ctx)
{
	int num = fetcher->fetchInt(ctx);
	toEnum(num, ctx);
	bool isnull = fetcher->fetchBoolean(ctx);
	if(!isnull)
	{
		__GC_MV(this, &(this->value), fetcher->fetchString(ctx), String);
	}
}
int SQLLiteral::fromEnum(ThreadContext* ctx) throw() 
{
	switch(this->litType) {
	case SQLLiteral::sqlliteralType::INTEGER_LITERAL:
		return 1;
	case SQLLiteral::sqlliteralType::FLOATING_POINT_LITERAL:
		return 2;
	case SQLLiteral::sqlliteralType::CHARACTER_LITERAL:
		return 3;
	case SQLLiteral::sqlliteralType::STRING_LITERAL:
		return 4;
	case SQLLiteral::sqlliteralType::BOOLEAN:
		return 6;
	case SQLLiteral::sqlliteralType::NULL_LITERAL:
		return 7;
	default:
		break ;
	}
	return 7;
}
void SQLLiteral::toEnum(int num, ThreadContext* ctx) throw() 
{
	switch(num) {
	case 1:
		this->litType = sqlliteralType::INTEGER_LITERAL;
		break ;
	case 2:
		this->litType = sqlliteralType::FLOATING_POINT_LITERAL;
		break ;
	case 3:
		this->litType = sqlliteralType::CHARACTER_LITERAL;
		break ;
	case 4:
		this->litType = sqlliteralType::STRING_LITERAL;
		break ;
	case 6:
		this->litType = sqlliteralType::BOOLEAN;
		break ;
	case 7:
	default:
		this->litType = sqlliteralType::NULL_LITERAL;
		break ;
	}
}
}}}}

