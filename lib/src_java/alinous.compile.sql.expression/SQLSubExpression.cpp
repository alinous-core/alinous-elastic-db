#include "includes.h"


namespace alinous {namespace compile {namespace sql {namespace expression {





bool SQLSubExpression::__init_done = __init_static_variables();
bool SQLSubExpression::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"SQLSubExpression", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 SQLSubExpression::SQLSubExpression(String* opStr, ISQLExpression* exp, ThreadContext* ctx) throw()  : IObject(ctx), AbstractSQLBooleanExpression(ctx), op(0), exp(nullptr)
{
	this->op = AbstractSQLExpression::operatorFromString(opStr, ctx);
	__GC_MV(this, &(this->exp), exp, ISQLExpression);
}
void SQLSubExpression::__construct_impl(String* opStr, ISQLExpression* exp, ThreadContext* ctx) throw() 
{
	this->op = AbstractSQLExpression::operatorFromString(opStr, ctx);
	__GC_MV(this, &(this->exp), exp, ISQLExpression);
}
 SQLSubExpression::~SQLSubExpression() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void SQLSubExpression::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"SQLSubExpression", L"~SQLSubExpression");
	__e_obj1.add(this->exp, this);
	exp = nullptr;
	if(!prepare){
		return;
	}
	AbstractSQLBooleanExpression::__releaseRegerences(true, ctx);
}
bool SQLSubExpression::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	if(this->exp != nullptr && !this->exp->visit(visitor, this, ctx))
	{
		return false;
	}
	return true;
}
bool SQLSubExpression::isConstant(ThreadContext* ctx) throw() 
{
	if(this->exp != nullptr && !this->exp->isConstant(ctx))
	{
		return false;
	}
	return true;
}
bool SQLSubExpression::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	if(this->exp != nullptr)
	{
		this->exp->analyse(context, leftValue, ctx);
	}
	return true;
}
ISQLExpression* SQLSubExpression::getExp(ThreadContext* ctx) throw() 
{
	return exp;
}
void SQLSubExpression::setExp(ISQLExpression* exp, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->exp), exp, ISQLExpression);
}
int SQLSubExpression::getOp(ThreadContext* ctx) throw() 
{
	return op;
}
void SQLSubExpression::setOp(int op, ThreadContext* ctx) throw() 
{
	this->op = op;
}
IAlinousVariable* SQLSubExpression::resolveExpression(ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	return this->exp->resolveExpression(machine, debug, ctx);
}
ExpressionSourceId* SQLSubExpression::getSourceId(ThreadContext* ctx) throw() 
{
	return (new(ctx) ExpressionSourceId(nullptr, this, this->exp->getSourceId(ctx)->getType(ctx), ctx));
}
bool SQLSubExpression::analyseSQL(SQLAnalyseContext* context, bool leftValue, bool debug, ThreadContext* ctx)
{
	if(this->exp != nullptr)
	{
		this->exp->analyseSQL(context, leftValue, debug, ctx);
	}
	return true;
}
bool SQLSubExpression::hasTable(ScanTableIdentifier* table, ThreadContext* ctx) throw() 
{
	if(this->exp != nullptr)
	{
		return this->exp->hasTable(table, ctx);
	}
	return false;
}
ArrayList<ScanTableColumnIdentifier>* SQLSubExpression::getColumns(ThreadContext* ctx) throw() 
{
	ArrayList<ScanTableColumnIdentifier>* list = (new(ctx) ArrayList<ScanTableColumnIdentifier>(ctx));
	if(this->exp != nullptr)
	{
		list = SQLAnalyseContext::joinList(list, this->exp, ctx);
	}
	return list;
}
bool SQLSubExpression::hasSubExp(ThreadContext* ctx) throw() 
{
	return false;
}
bool SQLSubExpression::isJoinCondition(ThreadContext* ctx) throw() 
{
	return false;
}
void SQLSubExpression::collectJoinCondition(ArrayList<ISQLExpression>* list, ThreadContext* ctx) throw() 
{
	this->exp->collectJoinCondition(list, ctx);
}
bool SQLSubExpression::isColumnIdentifier(ThreadContext* ctx) throw() 
{
	return false;
}
ArrayList<ScanTableColumnIdentifier>* SQLSubExpression::getIndexTargetColumn(ThreadContext* ctx) throw() 
{
	return this->exp->getColumns(ctx);
}
IndexColumnMatchCondition* SQLSubExpression::getIndexScanPart(ThreadContext* ctx) throw() 
{
	return nullptr;
}
ScanTableColumnIdentifier* SQLSubExpression::toColumnIdentifier(ThreadContext* ctx) throw() 
{
	return nullptr;
}
VariantValue* SQLSubExpression::resolveSQLExpression(ScanResultRecord* record, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	return this->exp->resolveSQLExpression(record, machine, debug, ctx);
}
bool SQLSubExpression::hasArrayResult(ThreadContext* ctx) throw() 
{
	return false;
}
ArrayList<VariantValue>* SQLSubExpression::resolveSQLExpressionAsArray(ScanResultRecord* record, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1038(), ctx));
}
bool SQLSubExpression::isSQLExp(ThreadContext* ctx) throw() 
{
	return true;
}
int SQLSubExpression::getExpressionType(ThreadContext* ctx) throw() 
{
	return IExpression::sQLSubExpression;
}
void SQLSubExpression::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	__readData(buff, ctx);
	this->op = buff->getInt(ctx);
	bool isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<ISQLExpression*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1046(), ctx));
		}
		__GC_MV(this, &(this->exp), static_cast<ISQLExpression*>(el), ISQLExpression);
	}
}
void SQLSubExpression::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putInt(ICommandData::__SQLNotExpression, ctx);
	__writeData(buff, ctx);
	buff->putInt(this->op, ctx);
	bool isnull = (this->exp == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->exp->writeData(buff, ctx);
	}
}
int SQLSubExpression::fileSize(ThreadContext* ctx)
{
	int total = __fileSize(ctx);
	total += 4;
	bool isnull = (this->exp == nullptr);
	total += 1;
	if(!isnull)
	{
		total += this->exp->fileSize(ctx);
	}
	return total;
}
void SQLSubExpression::toFileEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	builder->putInt(IExpressionFactory::__SQLSubExpression, ctx);
	__toFileEntry(builder, ctx);
	builder->putInt(this->op, ctx);
	bool isnull = (this->exp == nullptr);
	builder->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->exp->toFileEntry(builder, ctx);
	}
}
void SQLSubExpression::fromFileEntry(FileStorageEntryFetcher* fetcher, ThreadContext* ctx)
{
	__fromFileEntry(fetcher, ctx);
	this->op = fetcher->fetchInt(ctx);
	bool isnull = fetcher->fetchBoolean(ctx);
	if(!isnull)
	{
		IExpression* el = IExpressionFactory::fromFetcher(fetcher, ctx);
		if(el == nullptr || !((dynamic_cast<ISQLExpression*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1046(), ctx));
		}
		__GC_MV(this, &(this->exp), static_cast<ISQLExpression*>(el), ISQLExpression);
	}
}
}}}}

