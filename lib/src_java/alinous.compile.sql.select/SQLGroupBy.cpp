#include "includes.h"


namespace alinous {namespace compile {namespace sql {namespace select {





bool SQLGroupBy::__init_done = __init_static_variables();
bool SQLGroupBy::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"SQLGroupBy", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 SQLGroupBy::SQLGroupBy(ThreadContext* ctx) throw()  : IObject(ctx), ISQLExpression(ctx), groupList(nullptr), havingCondition(nullptr)
{
}
void SQLGroupBy::__construct_impl(ThreadContext* ctx) throw() 
{
}
 SQLGroupBy::~SQLGroupBy() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void SQLGroupBy::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"SQLGroupBy", L"~SQLGroupBy");
	__e_obj1.add(this->groupList, this);
	groupList = nullptr;
	__e_obj1.add(this->havingCondition, this);
	havingCondition = nullptr;
	if(!prepare){
		return;
	}
	ISQLExpression::__releaseRegerences(true, ctx);
}
bool SQLGroupBy::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	if(this->groupList != nullptr && !this->groupList->visit(visitor, this, ctx))
	{
		return false;
	}
	if(this->havingCondition != nullptr && !this->havingCondition->visit(visitor, this, ctx))
	{
		return false;
	}
	return true;
}
bool SQLGroupBy::isConstant(ThreadContext* ctx) throw() 
{
	return false;
}
bool SQLGroupBy::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	if(this->groupList != nullptr)
	{
		this->groupList->analyse(context, leftValue, ctx);
	}
	if(this->havingCondition != nullptr)
	{
		this->havingCondition->analyse(context, leftValue, ctx);
	}
	return true;
}
SQLExpressionList* SQLGroupBy::getGroupList(ThreadContext* ctx) throw() 
{
	return groupList;
}
void SQLGroupBy::setGroupList(SQLExpressionList* groupList, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->groupList), groupList, SQLExpressionList);
}
ISQLExpression* SQLGroupBy::getHavingCondition(ThreadContext* ctx) throw() 
{
	return havingCondition;
}
void SQLGroupBy::setHavingCondition(ISQLExpression* havingCondition, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->havingCondition), havingCondition, ISQLExpression);
}
IAlinousVariable* SQLGroupBy::resolveExpression(ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	return nullptr;
}
ExpressionSourceId* SQLGroupBy::getSourceId(ThreadContext* ctx) throw() 
{
	return (new(ctx) ExpressionSourceId(nullptr, this, nullptr, ctx));
}
bool SQLGroupBy::hasSubExp(ThreadContext* ctx) throw() 
{
	return false;
}
bool SQLGroupBy::analyseSQL(SQLAnalyseContext* context, bool leftValue, bool debug, ThreadContext* ctx)
{
	if(this->groupList != nullptr)
	{
		this->groupList->analyseSQL(context, leftValue, debug, ctx);
	}
	if(this->havingCondition != nullptr)
	{
		this->havingCondition->analyseSQL(context, leftValue, debug, ctx);
	}
	return true;
}
bool SQLGroupBy::hasTable(ScanTableIdentifier* table, ThreadContext* ctx) throw() 
{
	if(this->groupList != nullptr && this->groupList->hasTable(table, ctx))
	{
		return true;
	}
	if(this->havingCondition != nullptr && havingCondition->hasTable(table, ctx))
	{
		return true;
	}
	return false;
}
ArrayList<ScanTableColumnIdentifier>* SQLGroupBy::getColumns(ThreadContext* ctx) throw() 
{
	return nullptr;
}
bool SQLGroupBy::isJoinCondition(ThreadContext* ctx) throw() 
{
	return false;
}
void SQLGroupBy::collectJoinCondition(ArrayList<ISQLExpression>* list, ThreadContext* ctx) throw() 
{
}
bool SQLGroupBy::isColumnIdentifier(ThreadContext* ctx) throw() 
{
	return false;
}
ScanTableColumnIdentifier* SQLGroupBy::toColumnIdentifier(ThreadContext* ctx) throw() 
{
	return nullptr;
}
VariantValue* SQLGroupBy::resolveSQLExpression(ScanResultRecord* record, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	return nullptr;
}
int SQLGroupBy::getLine(ThreadContext* ctx) throw() 
{
	return ISQLExpression::getLine(ctx);
}
int SQLGroupBy::getStartPosition(ThreadContext* ctx) throw() 
{
	return ISQLExpression::getStartPosition(ctx);
}
int SQLGroupBy::getEndLine(ThreadContext* ctx) throw() 
{
	return ISQLExpression::getEndLine(ctx);
}
int SQLGroupBy::getEndPosition(ThreadContext* ctx) throw() 
{
	return ISQLExpression::getEndPosition(ctx);
}
AbstractSrcElement* SQLGroupBy::getParent(ThreadContext* ctx) throw() 
{
	return ISQLExpression::getParent(ctx);
}
void SQLGroupBy::setParent(AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	ISQLExpression::setParent(parent, ctx);
}
bool SQLGroupBy::hasArrayResult(ThreadContext* ctx) throw() 
{
	return false;
}
ArrayList<VariantValue>* SQLGroupBy::resolveSQLExpressionAsArray(ScanResultRecord* record, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1038(), ctx));
}
bool SQLGroupBy::isSQLExp(ThreadContext* ctx) throw() 
{
	return true;
}
String* SQLGroupBy::getAsName(ThreadContext* ctx) throw() 
{
	return nullptr;
}
void SQLGroupBy::setAsName(String* name, ThreadContext* ctx) throw() 
{
}
int SQLGroupBy::getExpressionType(ThreadContext* ctx) throw() 
{
	return IExpression::sQLGroupBy;
}
void SQLGroupBy::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	bool isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<SQLExpressionList*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1039(), ctx));
		}
		__GC_MV(this, &(this->groupList), static_cast<SQLExpressionList*>(el), SQLExpressionList);
	}
	isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<ISQLExpression*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1046(), ctx));
		}
		__GC_MV(this, &(this->havingCondition), static_cast<ISQLExpression*>(el), ISQLExpression);
	}
}
void SQLGroupBy::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putInt(ICommandData::__SQLGroupBy, ctx);
	bool isnull = (this->groupList == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->groupList->writeData(buff, ctx);
	}
	isnull = (this->havingCondition == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->havingCondition->writeData(buff, ctx);
	}
}
int SQLGroupBy::fileSize(ThreadContext* ctx)
{
	int total = 4;
	bool isnull = (this->groupList == nullptr);
	total += 1;
	if(!isnull)
	{
		total += this->groupList->fileSize(ctx);
	}
	isnull = (this->havingCondition == nullptr);
	total += 1;
	if(!isnull)
	{
		total += this->havingCondition->fileSize(ctx);
	}
	return total;
}
void SQLGroupBy::toFileEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	builder->putInt(IExpressionFactory::__InsertValues, ctx);
	bool isnull = (this->groupList == nullptr);
	builder->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->groupList->toFileEntry(builder, ctx);
	}
	isnull = (this->havingCondition == nullptr);
	builder->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->havingCondition->toFileEntry(builder, ctx);
	}
}
void SQLGroupBy::fromFileEntry(FileStorageEntryFetcher* fetcher, ThreadContext* ctx)
{
	bool isnull = fetcher->fetchBoolean(ctx);
	if(!isnull)
	{
		IExpression* exp = IExpressionFactory::fromFetcher(fetcher, ctx);
		if(exp != nullptr || !((dynamic_cast<SQLExpressionList*>(exp) != 0)))
		{
			throw (new(ctx) AlinousException(ConstStr::getCNST_STR_1039(), ctx));
		}
		__GC_MV(this, &(this->groupList), static_cast<SQLExpressionList*>(exp), SQLExpressionList);
	}
	isnull = fetcher->fetchBoolean(ctx);
	if(!isnull)
	{
		IExpression* exp = IExpressionFactory::fromFetcher(fetcher, ctx);
		if(exp != nullptr)
		{
			throw (new(ctx) AlinousException(ConstStr::getCNST_STR_1040(), ctx));
		}
		__GC_MV(this, &(this->havingCondition), static_cast<ISQLExpression*>(exp), ISQLExpression);
	}
}
}}}}

