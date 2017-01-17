#include "includes.h"


namespace alinous {namespace compile {namespace sql {namespace expression {





constexpr const int SQLExpressionStream::ANA_COLUMN_OR_VARIABLE;
constexpr const int SQLExpressionStream::ANA_SQL_FUNC;
constexpr const int SQLExpressionStream::ANA_PROG_FUNC;
bool SQLExpressionStream::__init_done = __init_static_variables();
bool SQLExpressionStream::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"SQLExpressionStream", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 SQLExpressionStream::SQLExpressionStream(ThreadContext* ctx) throw()  : IObject(ctx), ISQLExpression(ctx), asName(nullptr), exp(nullptr), analyzedExpressionType(0), sqlFunction(nullptr), arguments(nullptr), columnIdentifier(nullptr)
{
}
void SQLExpressionStream::__construct_impl(ThreadContext* ctx) throw() 
{
}
 SQLExpressionStream::~SQLExpressionStream() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void SQLExpressionStream::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"SQLExpressionStream", L"~SQLExpressionStream");
	__e_obj1.add(this->asName, this);
	asName = nullptr;
	__e_obj1.add(this->exp, this);
	exp = nullptr;
	__e_obj1.add(this->sqlFunction, this);
	sqlFunction = nullptr;
	__e_obj1.add(this->arguments, this);
	arguments = nullptr;
	__e_obj1.add(this->columnIdentifier, this);
	columnIdentifier = nullptr;
	if(!prepare){
		return;
	}
	ISQLExpression::__releaseRegerences(true, ctx);
}
bool SQLExpressionStream::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	if(this->exp->isProgramOnlyOnAnalyze(ctx))
	{
		this->analyzedExpressionType = ANA_PROG_FUNC;
		this->exp->analyse(context, leftValue, ctx);
		return true;
	}
	if(this->exp->hasFunction(ctx))
	{
		String* sqlFuncName = this->exp->getSQLFunctionName(ctx);
		__GC_MV(this, &(this->sqlFunction), context->sqlFunctionManager->getFunction(sqlFuncName, ctx), ISQLFunctionBody);
		if(this->sqlFunction != nullptr)
		{
			__GC_MV(this, &(this->arguments), this->exp->getSQLFunctionArguments(ctx), FunctionArguments);
			this->analyzedExpressionType = ANA_SQL_FUNC;
		}
				else 
		{
			this->analyzedExpressionType = ANA_PROG_FUNC;
			this->exp->analyse(context, leftValue, ctx);
		}
		return true;
	}
	this->analyzedExpressionType = ANA_COLUMN_OR_VARIABLE;
	AlinousName* colidname = this->exp->toAlinousName(ctx);
	if(colidname == nullptr)
	{
		this->analyzedExpressionType = ANA_PROG_FUNC;
		this->exp->analyse(context, leftValue, ctx);
		return true;
	}
	return true;
}
bool SQLExpressionStream::analyseSQL(SQLAnalyseContext* context, bool leftValue, bool debug, ThreadContext* ctx)
{
	switch(this->analyzedExpressionType) {
	case ANA_PROG_FUNC:
	case ANA_SQL_FUNC:
		return true;
	case ANA_COLUMN_OR_VARIABLE:
	default:
		break;
	}
	AlinousName* colidname = this->exp->toAlinousName(ctx);
	__GC_MV(this, &(this->columnIdentifier), (new(ctx) SQLColumnIdentifier(colidname, ctx)), SQLColumnIdentifier);
	this->columnIdentifier->position(this, this, ctx);
	this->columnIdentifier->analyseSQL(context, leftValue, debug, ctx);
	return true;
}
IAlinousVariable* SQLExpressionStream::resolveExpression(ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	switch(this->analyzedExpressionType) {
	case ANA_PROG_FUNC:
		return this->exp->resolveExpression(machine, debug, ctx);
	case ANA_SQL_FUNC:
		return this->sqlFunction->resolveSQLExpression(nullptr, machine, this->arguments, debug, ctx);
	case ANA_COLUMN_OR_VARIABLE:
	default:
		break;
	}
	if(this->columnIdentifier != nullptr)
	{
		return this->columnIdentifier->resolveExpression(machine, debug, ctx);
	}
	return this->exp->resolveExpression(machine, debug, ctx);
}
VariantValue* SQLExpressionStream::resolveSQLExpression(ScanResultRecord* record, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	switch(this->analyzedExpressionType) {
	case ANA_PROG_FUNC:
		return static_cast<VariantValue*>(this->exp->resolveExpression(machine, debug, ctx));
	case ANA_SQL_FUNC:
		return this->sqlFunction->resolveSQLExpression(record, machine, this->arguments, debug, ctx);
	case ANA_COLUMN_OR_VARIABLE:
	default:
		break;
	}
	if(this->columnIdentifier != nullptr)
	{
		return this->columnIdentifier->resolveSQLExpression(record, machine, debug, ctx);
	}
	return static_cast<VariantValue*>(this->exp->resolveExpression(machine, debug, ctx));
}
ExpressionSourceId* SQLExpressionStream::getSourceId(ThreadContext* ctx) throw() 
{
	return (new(ctx) ExpressionSourceId(nullptr, this, this->exp->getSourceId(ctx)->getType(ctx), ctx));
}
bool SQLExpressionStream::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	if(!exp->visit(visitor, this, ctx))
	{
		return false;
	}
	return true;
}
bool SQLExpressionStream::isConstant(ThreadContext* ctx) throw() 
{
	return false;
}
ExpressionStream* SQLExpressionStream::getExp(ThreadContext* ctx) throw() 
{
	return exp;
}
void SQLExpressionStream::setExp(ExpressionStream* exp, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->exp), exp, ExpressionStream);
}
bool SQLExpressionStream::hasTable(ScanTableIdentifier* table, ThreadContext* ctx) throw() 
{
	if(this->columnIdentifier != nullptr)
	{
		return this->columnIdentifier->hasTable(table, ctx);
	}
	return false;
}
ArrayList<ScanTableColumnIdentifier>* SQLExpressionStream::getColumns(ThreadContext* ctx) throw() 
{
	if(this->columnIdentifier != nullptr)
	{
		return this->columnIdentifier->getColumns(ctx);
	}
	return nullptr;
}
bool SQLExpressionStream::hasSubExp(ThreadContext* ctx) throw() 
{
	return false;
}
bool SQLExpressionStream::isJoinCondition(ThreadContext* ctx) throw() 
{
	if(this->columnIdentifier != nullptr)
	{
		return this->columnIdentifier->isJoinCondition(ctx);
	}
	return false;
}
void SQLExpressionStream::collectJoinCondition(ArrayList<ISQLExpression>* list, ThreadContext* ctx) throw() 
{
	if(this->columnIdentifier != nullptr)
	{
		this->columnIdentifier->collectJoinCondition(list, ctx);
	}
}
bool SQLExpressionStream::isColumnIdentifier(ThreadContext* ctx) throw() 
{
	return this->columnIdentifier != nullptr;
}
ScanTableColumnIdentifier* SQLExpressionStream::toColumnIdentifier(ThreadContext* ctx) throw() 
{
	if(this->columnIdentifier != nullptr)
	{
		return this->columnIdentifier->toColumnIdentifier(ctx);
	}
	return nullptr;
}
int SQLExpressionStream::getLine(ThreadContext* ctx) throw() 
{
	return ISQLExpression::getLine(ctx);
}
int SQLExpressionStream::getStartPosition(ThreadContext* ctx) throw() 
{
	return ISQLExpression::getStartPosition(ctx);
}
int SQLExpressionStream::getEndLine(ThreadContext* ctx) throw() 
{
	return ISQLExpression::getEndLine(ctx);
}
int SQLExpressionStream::getEndPosition(ThreadContext* ctx) throw() 
{
	return ISQLExpression::getEndPosition(ctx);
}
AbstractSrcElement* SQLExpressionStream::getParent(ThreadContext* ctx) throw() 
{
	return ISQLExpression::getParent(ctx);
}
void SQLExpressionStream::setParent(AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	ISQLExpression::setParent(parent, ctx);
}
bool SQLExpressionStream::hasArrayResult(ThreadContext* ctx) throw() 
{
	return false;
}
ArrayList<VariantValue>* SQLExpressionStream::resolveSQLExpressionAsArray(ScanResultRecord* record, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1036(), ctx));
}
bool SQLExpressionStream::isSQLExp(ThreadContext* ctx) throw() 
{
	return true;
}
String* SQLExpressionStream::getAsName(ThreadContext* ctx) throw() 
{
	return this->asName;
}
void SQLExpressionStream::setAsName(String* name, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->asName), name, String);
}
int SQLExpressionStream::getExpressionType(ThreadContext* ctx) throw() 
{
	return IExpression::sQLExpressionStream;
}
void SQLExpressionStream::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	bool isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<ExpressionStream*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1018(), ctx));
		}
		__GC_MV(this, &(this->exp), static_cast<ExpressionStream*>(el), ExpressionStream);
	}
	isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		__GC_MV(this, &(this->asName), buff->getString(ctx), String);
	}
}
void SQLExpressionStream::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putInt(ICommandData::__SQLEqualityExpression, ctx);
	bool isnull = (this->exp == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->exp->writeData(buff, ctx);
	}
	isnull = (this->asName == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		buff->putString(this->asName, ctx);
	}
}
int SQLExpressionStream::fileSize(ThreadContext* ctx)
{
	int total = 4;
	bool isnull = (this->exp == nullptr);
	total += 1;
	if(!isnull)
	{
		total += this->exp->fileSize(ctx);
	}
	isnull = (this->asName == nullptr);
	total += 1;
	if(!isnull)
	{
		total += asName->length(ctx) * 2 + 4;
	}
	return total;
}
void SQLExpressionStream::toFileEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx) throw() 
{
}
void SQLExpressionStream::fromFileEntry(FileStorageEntryFetcher* fetcher, ThreadContext* ctx)
{
}
}}}}

