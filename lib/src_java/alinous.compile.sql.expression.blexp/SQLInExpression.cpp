#include "includes.h"


namespace alinous {namespace compile {namespace sql {namespace expression {namespace blexp {





bool SQLInExpression::__init_done = __init_static_variables();
bool SQLInExpression::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"SQLInExpression", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 SQLInExpression::SQLInExpression(ThreadContext* ctx) throw()  : IObject(ctx), AbstractSQLBooleanExpression(ctx), first(nullptr), list(nullptr)
{
}
void SQLInExpression::__construct_impl(ThreadContext* ctx) throw() 
{
}
 SQLInExpression::~SQLInExpression() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void SQLInExpression::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"SQLInExpression", L"~SQLInExpression");
	__e_obj1.add(this->first, this);
	first = nullptr;
	__e_obj1.add(this->list, this);
	list = nullptr;
	if(!prepare){
		return;
	}
	AbstractSQLBooleanExpression::__releaseRegerences(true, ctx);
}
bool SQLInExpression::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	if(this->first != nullptr && !this->first->visit(visitor, this, ctx))
	{
		return false;
	}
	if(this->list != nullptr && !this->list->visit(visitor, this, ctx))
	{
		return false;
	}
	return true;
}
bool SQLInExpression::isConstant(ThreadContext* ctx) throw() 
{
	if(this->first != nullptr && !this->first->isConstant(ctx))
	{
		return false;
	}
	if(this->list != nullptr && !this->list->isConstant(ctx))
	{
		return false;
	}
	return true;
}
bool SQLInExpression::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	if(this->first != nullptr)
	{
		this->first->analyse(context, leftValue, ctx);
	}
	if(this->list != nullptr)
	{
		this->list->analyse(context, leftValue, ctx);
	}
	return true;
}
ISQLExpression* SQLInExpression::getFirst(ThreadContext* ctx) throw() 
{
	return first;
}
void SQLInExpression::setFirst(ISQLExpression* first, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->first), first, ISQLExpression);
}
SQLExpressionList* SQLInExpression::getList(ThreadContext* ctx) throw() 
{
	return list;
}
void SQLInExpression::setList(SQLExpressionList* list, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->list), list, SQLExpressionList);
}
IAlinousVariable* SQLInExpression::resolveExpression(ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
ExpressionSourceId* SQLInExpression::getSourceId(ThreadContext* ctx) throw() 
{
	return (new(ctx) ExpressionSourceId(nullptr, this, (new(ctx) AlinousType(AlinousType::BOOL_TYPE, AlinousType::TYPE_PRIMITIVE, ctx)), ctx));
}
bool SQLInExpression::analyseSQL(SQLAnalyseContext* context, bool leftValue, bool debug, ThreadContext* ctx)
{
	if(this->first != nullptr)
	{
		this->first->analyseSQL(context, leftValue, debug, ctx);
	}
	if(this->list != nullptr)
	{
		this->list->analyseSQL(context, leftValue, debug, ctx);
	}
	ArrayList<ScanTableColumnIdentifier>* colList = this->first->getColumns(ctx);
	if(colList == nullptr || colList->isEmpty(ctx))
	{
		throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1075(), ctx));
	}
	return true;
}
bool SQLInExpression::hasTable(ScanTableIdentifier* table, ThreadContext* ctx) throw() 
{
	if(this->first != nullptr && this->first->hasTable(table, ctx))
	{
		return true;
	}
	if(this->list != nullptr && this->list->hasTable(table, ctx))
	{
		return true;
	}
	return false;
}
ArrayList<ScanTableColumnIdentifier>* SQLInExpression::getColumns(ThreadContext* ctx) throw() 
{
	ArrayList<ScanTableColumnIdentifier>* list = (new(ctx) ArrayList<ScanTableColumnIdentifier>(ctx));
	list = SQLAnalyseContext::joinList(list, this->first, ctx);
	list = SQLAnalyseContext::joinList(list, this->list, ctx);
	return list;
}
bool SQLInExpression::hasSubExp(ThreadContext* ctx) throw() 
{
	return false;
}
bool SQLInExpression::isJoinCondition(ThreadContext* ctx) throw() 
{
	return false;
}
void SQLInExpression::collectJoinCondition(ArrayList<ISQLExpression>* list, ThreadContext* ctx) throw() 
{
}
bool SQLInExpression::isColumnIdentifier(ThreadContext* ctx) throw() 
{
	return false;
}
ArrayList<ScanTableColumnIdentifier>* SQLInExpression::getIndexTargetColumn(ThreadContext* ctx) throw() 
{
	ArrayList<ScanTableColumnIdentifier>* cols = this->first->getColumns(ctx);
	return cols;
}
IndexColumnMatchCondition* SQLInExpression::getIndexScanPart(ThreadContext* ctx) throw() 
{
	if(isJoinCondition(ctx))
	{
		return nullptr;
	}
	if(this->first->isColumnIdentifier(ctx))
	{
		IndexColumnMatchCondition* matchingCondition = (new(ctx) IndexColumnMatchCondition(this->first->toColumnIdentifier(ctx), this->list->getList(ctx), ctx));
		return matchingCondition;
	}
	return nullptr;
}
ScanTableColumnIdentifier* SQLInExpression::toColumnIdentifier(ThreadContext* ctx) throw() 
{
	return nullptr;
}
VariantValue* SQLInExpression::resolveSQLExpression(ScanResultRecord* record, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	VariantValue* val = this->first->resolveSQLExpression(record, machine, debug, ctx);
	ArrayList<VariantValue>* valueList = this->list->resolveSQLExpressionAsArray(record, machine, debug, ctx);
	int maxLoop = valueList->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		VariantValue* invalue = valueList->get(i, ctx);
		if(val->compareTo(invalue, ctx) == 0)
		{
			return (new(ctx) VariantValue(((char)1), ctx));
		}
	}
	return (new(ctx) VariantValue(((char)0), ctx));
}
bool SQLInExpression::hasArrayResult(ThreadContext* ctx) throw() 
{
	return false;
}
ArrayList<VariantValue>* SQLInExpression::resolveSQLExpressionAsArray(ScanResultRecord* record, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1038(), ctx));
}
int SQLInExpression::getExpressionType(ThreadContext* ctx) throw() 
{
	return IExpression::sQLInExpression;
}
void SQLInExpression::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	__readData(buff, ctx);
	bool isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<ISQLExpression*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1046(), ctx));
		}
		__GC_MV(this, &(this->first), static_cast<ISQLExpression*>(el), ISQLExpression);
	}
	isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<SQLExpressionList*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1039(), ctx));
		}
		__GC_MV(this, &(this->list), static_cast<SQLExpressionList*>(el), SQLExpressionList);
	}
}
void SQLInExpression::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putInt(ICommandData::__SQLInExpression, ctx);
	__writeData(buff, ctx);
	bool isnull = (this->first == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->first->writeData(buff, ctx);
	}
	isnull = (this->list == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->list->writeData(buff, ctx);
	}
}
int SQLInExpression::fileSize(ThreadContext* ctx)
{
	int total = __fileSize(ctx);
	bool isnull = (this->first == nullptr);
	total += 1;
	if(!isnull)
	{
		total += this->first->fileSize(ctx);
	}
	isnull = (this->list == nullptr);
	total += 1;
	if(!isnull)
	{
		total += this->list->fileSize(ctx);
	}
	return total;
}
void SQLInExpression::toFileEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	builder->putInt(IExpressionFactory::__SQLInExpression, ctx);
	__toFileEntry(builder, ctx);
	bool isnull = (this->first == nullptr);
	builder->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->first->toFileEntry(builder, ctx);
	}
	isnull = (this->list == nullptr);
	builder->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->list->toFileEntry(builder, ctx);
	}
}
void SQLInExpression::fromFileEntry(FileStorageEntryFetcher* fetcher, ThreadContext* ctx)
{
	__fromFileEntry(fetcher, ctx);
	bool isnull = fetcher->fetchBoolean(ctx);
	if(!isnull)
	{
		IExpression* el = IExpressionFactory::fromFetcher(fetcher, ctx);
		if(el == nullptr || !((dynamic_cast<ISQLExpression*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1046(), ctx));
		}
		__GC_MV(this, &(this->first), static_cast<ISQLExpression*>(el), ISQLExpression);
	}
	isnull = fetcher->fetchBoolean(ctx);
	if(!isnull)
	{
		IExpression* el = IExpressionFactory::fromFetcher(fetcher, ctx);
		if(el == nullptr || !((dynamic_cast<SQLExpressionList*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1039(), ctx));
		}
		__GC_MV(this, &(this->list), static_cast<SQLExpressionList*>(el), SQLExpressionList);
	}
}
}}}}}

