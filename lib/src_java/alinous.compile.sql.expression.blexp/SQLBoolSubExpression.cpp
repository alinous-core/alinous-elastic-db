#include "includes.h"


namespace alinous {namespace compile {namespace sql {namespace expression {namespace blexp {





bool SQLBoolSubExpression::__init_done = __init_static_variables();
bool SQLBoolSubExpression::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"SQLBoolSubExpression", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 SQLBoolSubExpression::SQLBoolSubExpression(String* op, ISQLExpression* exp, ThreadContext* ctx) throw()  : IObject(ctx), AbstractSQLBooleanExpression(ctx), op(0), exp(nullptr)
{
	this->op = AbstractSQLBooleanExpression::operatorFromString(op, ctx);
	__GC_MV(this, &(this->exp), exp, ISQLExpression);
}
void SQLBoolSubExpression::__construct_impl(String* op, ISQLExpression* exp, ThreadContext* ctx) throw() 
{
	this->op = AbstractSQLBooleanExpression::operatorFromString(op, ctx);
	__GC_MV(this, &(this->exp), exp, ISQLExpression);
}
 SQLBoolSubExpression::~SQLBoolSubExpression() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void SQLBoolSubExpression::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"SQLBoolSubExpression", L"~SQLBoolSubExpression");
	__e_obj1.add(this->exp, this);
	exp = nullptr;
	if(!prepare){
		return;
	}
	AbstractSQLBooleanExpression::__releaseRegerences(true, ctx);
}
bool SQLBoolSubExpression::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
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
bool SQLBoolSubExpression::isConstant(ThreadContext* ctx) throw() 
{
	if(this->exp != nullptr && !this->exp->isConstant(ctx))
	{
		return false;
	}
	return true;
}
bool SQLBoolSubExpression::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	if(this->exp != nullptr)
	{
		return this->exp->analyse(context, leftValue, ctx);
	}
	return true;
}
ISQLExpression* SQLBoolSubExpression::getExp(ThreadContext* ctx) throw() 
{
	return exp;
}
void SQLBoolSubExpression::setExp(ISQLExpression* exp, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->exp), exp, ISQLExpression);
}
int SQLBoolSubExpression::getOp(ThreadContext* ctx) throw() 
{
	return op;
}
void SQLBoolSubExpression::setOp(int op, ThreadContext* ctx) throw() 
{
	this->op = op;
}
IAlinousVariable* SQLBoolSubExpression::resolveExpression(ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	return this->exp->resolveExpression(machine, debug, ctx);
}
ExpressionSourceId* SQLBoolSubExpression::getSourceId(ThreadContext* ctx) throw() 
{
	return (new(ctx) ExpressionSourceId(nullptr, this, (new(ctx) AlinousType(AlinousType::BOOL_TYPE, AlinousType::TYPE_PRIMITIVE, ctx)), ctx));
}
bool SQLBoolSubExpression::analyseSQL(SQLAnalyseContext* context, bool leftValue, bool debug, ThreadContext* ctx)
{
	if(this->exp != nullptr)
	{
		this->exp->analyseSQL(context, leftValue, debug, ctx);
	}
	return true;
}
bool SQLBoolSubExpression::hasSubExp(ThreadContext* ctx) throw() 
{
	return true;
}
bool SQLBoolSubExpression::hasTable(ScanTableIdentifier* table, ThreadContext* ctx) throw() 
{
	if(this->exp != nullptr)
	{
		return this->exp->hasTable(table, ctx);
	}
	return false;
}
ArrayList<ScanTableColumnIdentifier>* SQLBoolSubExpression::getColumns(ThreadContext* ctx) throw() 
{
	ArrayList<ScanTableColumnIdentifier>* list = (new(ctx) ArrayList<ScanTableColumnIdentifier>(ctx));
	if(this->exp != nullptr)
	{
		list = SQLAnalyseContext::joinList(list, this->exp, ctx);
	}
	return list;
}
bool SQLBoolSubExpression::isJoinCondition(ThreadContext* ctx) throw() 
{
	return false;
}
void SQLBoolSubExpression::collectJoinCondition(ArrayList<ISQLExpression>* list, ThreadContext* ctx) throw() 
{
	this->exp->collectJoinCondition(list, ctx);
}
bool SQLBoolSubExpression::isColumnIdentifier(ThreadContext* ctx) throw() 
{
	return false;
}
ArrayList<ScanTableColumnIdentifier>* SQLBoolSubExpression::getIndexTargetColumn(ThreadContext* ctx) throw() 
{
	if((dynamic_cast<AbstractSQLBooleanExpression*>(this->exp) != 0))
	{
		return (static_cast<AbstractSQLBooleanExpression*>(this->exp))->getIndexTargetColumn(ctx);
	}
	return nullptr;
}
IndexColumnMatchCondition* SQLBoolSubExpression::getIndexScanPart(ThreadContext* ctx) throw() 
{
	return nullptr;
}
ScanTableColumnIdentifier* SQLBoolSubExpression::toColumnIdentifier(ThreadContext* ctx) throw() 
{
	return nullptr;
}
VariantValue* SQLBoolSubExpression::resolveSQLExpression(ScanResultRecord* record, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	return this->exp->resolveSQLExpression(record, machine, debug, ctx);
}
bool SQLBoolSubExpression::hasArrayResult(ThreadContext* ctx) throw() 
{
	return false;
}
ArrayList<VariantValue>* SQLBoolSubExpression::resolveSQLExpressionAsArray(ScanResultRecord* record, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1038(), ctx));
}
int SQLBoolSubExpression::getExpressionType(ThreadContext* ctx) throw() 
{
	return IExpression::sQLBoolSubExpression;
}
void SQLBoolSubExpression::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
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
void SQLBoolSubExpression::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	buff->putInt(ICommandData::__SQLBoolSubExpression, ctx);
	__writeData(buff, ctx);
	buff->putInt(this->op, ctx);
	bool isnull = (this->exp == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->exp->writeData(buff, ctx);
	}
}
int SQLBoolSubExpression::fileSize(ThreadContext* ctx)
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
void SQLBoolSubExpression::toFileEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	builder->putInt(IExpressionFactory::__SQLBoolSubExpression, ctx);
	__toFileEntry(builder, ctx);
	builder->putInt(this->op, ctx);
	bool isnull = (this->exp == nullptr);
	builder->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->exp->toFileEntry(builder, ctx);
	}
}
void SQLBoolSubExpression::fromFileEntry(FileStorageEntryFetcher* fetcher, ThreadContext* ctx)
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
}}}}}

