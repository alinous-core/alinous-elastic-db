#include "includes.h"


namespace alinous {namespace compile {namespace sql {namespace expression {





bool SQLParenthesisExpression::__init_done = __init_static_variables();
bool SQLParenthesisExpression::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"SQLParenthesisExpression", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 SQLParenthesisExpression::~SQLParenthesisExpression() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void SQLParenthesisExpression::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"SQLParenthesisExpression", L"~SQLParenthesisExpression");
	__e_obj1.add(this->exp, this);
	exp = nullptr;
	if(!prepare){
		return;
	}
	AbstractSQLExpression::__releaseRegerences(true, ctx);
}
IAlinousVariable* SQLParenthesisExpression::resolveExpression(ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	return this->exp->resolveExpression(machine, debug, ctx);
}
bool SQLParenthesisExpression::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
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
bool SQLParenthesisExpression::isConstant(ThreadContext* ctx) throw() 
{
	if(this->exp != nullptr && !this->exp->isConstant(ctx))
	{
		return false;
	}
	return true;
}
ISQLExpression* SQLParenthesisExpression::getExp(ThreadContext* ctx) throw() 
{
	return exp;
}
void SQLParenthesisExpression::setExp(ISQLExpression* exp, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->exp), exp, ISQLExpression);
}
bool SQLParenthesisExpression::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	if(this->exp != nullptr)
	{
		this->exp->analyse(context, leftValue, ctx);
	}
	return true;
}
ExpressionSourceId* SQLParenthesisExpression::getSourceId(ThreadContext* ctx) throw() 
{
	return (new(ctx) ExpressionSourceId(nullptr, this, this->exp->getSourceId(ctx)->getType(ctx), ctx));
}
bool SQLParenthesisExpression::analyseSQL(SQLAnalyseContext* context, bool leftValue, bool debug, ThreadContext* ctx)
{
	if(this->exp != nullptr)
	{
		this->exp->analyseSQL(context, leftValue, debug, ctx);
	}
	return true;
}
bool SQLParenthesisExpression::hasTable(ScanTableIdentifier* table, ThreadContext* ctx) throw() 
{
	if(this->exp != nullptr)
	{
		return this->exp->hasTable(table, ctx);
	}
	return false;
}
ArrayList<ScanTableColumnIdentifier>* SQLParenthesisExpression::getColumns(ThreadContext* ctx) throw() 
{
	ArrayList<ScanTableColumnIdentifier>* list = (new(ctx) ArrayList<ScanTableColumnIdentifier>(ctx));
	if(this->exp != nullptr)
	{
		list = SQLAnalyseContext::joinList(list, this->exp, ctx);
	}
	return list;
}
bool SQLParenthesisExpression::hasSubExp(ThreadContext* ctx) throw() 
{
	return true;
}
bool SQLParenthesisExpression::isJoinCondition(ThreadContext* ctx) throw() 
{
	return false;
}
void SQLParenthesisExpression::collectJoinCondition(ArrayList<ISQLExpression>* list, ThreadContext* ctx) throw() 
{
	this->exp->collectJoinCondition(list, ctx);
}
bool SQLParenthesisExpression::isColumnIdentifier(ThreadContext* ctx) throw() 
{
	return this->exp->isColumnIdentifier(ctx);
}
ScanTableColumnIdentifier* SQLParenthesisExpression::toColumnIdentifier(ThreadContext* ctx) throw() 
{
	return this->exp->toColumnIdentifier(ctx);
}
VariantValue* SQLParenthesisExpression::resolveSQLExpression(ScanResultRecord* record, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	return this->exp->resolveSQLExpression(record, machine, debug, ctx);
}
bool SQLParenthesisExpression::hasArrayResult(ThreadContext* ctx) throw() 
{
	return this->exp->hasArrayResult(ctx);
}
ArrayList<VariantValue>* SQLParenthesisExpression::resolveSQLExpressionAsArray(ScanResultRecord* record, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	return this->exp->resolveSQLExpressionAsArray(record, machine, debug, ctx);
}
int SQLParenthesisExpression::getExpressionType(ThreadContext* ctx) throw() 
{
	return IExpression::sQLParenthesisExpression;
}
void SQLParenthesisExpression::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
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
void SQLParenthesisExpression::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putInt(ICommandData::__SQLParenthesisExpression, ctx);
	bool isnull = (this->exp == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->exp->writeData(buff, ctx);
	}
}
int SQLParenthesisExpression::fileSize(ThreadContext* ctx)
{
	int total = 4;
	bool isnull = (this->exp == nullptr);
	total += 1;
	if(!isnull)
	{
		total += this->exp->fileSize(ctx);
	}
	return total;
}
void SQLParenthesisExpression::toFileEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	builder->putInt(IExpressionFactory::__SQLParenthesisExpression, ctx);
	bool isnull = (this->exp == nullptr);
	builder->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->exp->toFileEntry(builder, ctx);
	}
}
void SQLParenthesisExpression::fromFileEntry(FileStorageEntryFetcher* fetcher, ThreadContext* ctx)
{
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

