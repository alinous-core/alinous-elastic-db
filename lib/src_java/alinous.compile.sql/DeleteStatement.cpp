#include "includes.h"


namespace alinous {namespace compile {namespace sql {





bool DeleteStatement::__init_done = __init_static_variables();
bool DeleteStatement::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DeleteStatement", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 DeleteStatement::~DeleteStatement() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void DeleteStatement::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"DeleteStatement", L"~DeleteStatement");
	__e_obj1.add(this->table, this);
	table = nullptr;
	__e_obj1.add(this->where, this);
	where = nullptr;
	if(!prepare){
		return;
	}
	AbstractSQLStatement::__releaseRegerences(true, ctx);
}
void DeleteStatement::validate(SourceValidator* validator, ThreadContext* ctx) throw() 
{
}
bool DeleteStatement::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	if(this->table != nullptr && !this->table->visit(visitor, this, ctx))
	{
		return false;
	}
	if(this->where != nullptr && !this->where->visit(visitor, this, ctx))
	{
		return false;
	}
	return true;
}
bool DeleteStatement::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	if(this->table != nullptr)
	{
		this->table->analyse(context, leftValue, ctx);
	}
	if(this->where != nullptr)
	{
		this->where->analyse(context, leftValue, ctx);
	}
	return true;
}
IJoinTarget* DeleteStatement::getTable(ThreadContext* ctx) throw() 
{
	return table;
}
void DeleteStatement::setTable(IJoinTarget* table, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->table), table, IJoinTarget);
}
SQLWhere* DeleteStatement::getWhere(ThreadContext* ctx) throw() 
{
	return where;
}
void DeleteStatement::setWhere(SQLWhere* where, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->where), where, SQLWhere);
}
IStatement::StatementType DeleteStatement::getType(ThreadContext* ctx) throw() 
{
	return StatementType::DELETE;
}
void DeleteStatement::analyzeSQL(SQLAnalyseContext* context, bool debug, ThreadContext* ctx)
{
	{
		SynchronizedBlockObj __synchronized_2(this, ctx);
		this->table->analyseSQLTables(context, false, debug, ctx);
		this->table->analyzeSQL(context, debug, ctx);
		if(this->where != nullptr && this->where->getCondition(ctx) != nullptr)
		{
			this->where->getCondition(ctx)->analyseSQL(context, false, debug, ctx);
		}
	}
}
void DeleteStatement::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	bool isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<IJoinTarget*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1030(), ctx));
		}
		__GC_MV(this, &(this->table), static_cast<IJoinTarget*>(el), IJoinTarget);
	}
	isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<SQLWhere*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1039(), ctx));
		}
		__GC_MV(this, &(this->where), static_cast<SQLWhere*>(el), SQLWhere);
	}
}
void DeleteStatement::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putInt(ICommandData::__DeleteStatement, ctx);
	bool isnull = (this->table == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->table->writeData(buff, ctx);
	}
	isnull = (this->where == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->where->writeData(buff, ctx);
	}
}
}}}

