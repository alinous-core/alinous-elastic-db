#include "includes.h"


namespace alinous {namespace compile {namespace sql {





bool UpdateStatement::__init_done = __init_static_variables();
bool UpdateStatement::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"UpdateStatement", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 UpdateStatement::~UpdateStatement() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void UpdateStatement::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"UpdateStatement", L"~UpdateStatement");
	__e_obj1.add(this->table, this);
	table = nullptr;
	__e_obj1.add(this->sets, this);
	sets = nullptr;
	__e_obj1.add(this->where, this);
	where = nullptr;
	if(!prepare){
		return;
	}
	AbstractSQLStatement::__releaseRegerences(true, ctx);
}
void UpdateStatement::validate(SourceValidator* validator, ThreadContext* ctx) throw() 
{
	if(!((dynamic_cast<TableJoinTarget*>(this->table) != 0)))
	{
		validator->addError(ConstStr::getCNST_STR_1047(), this->table, ctx);
	}
}
AlinousName* UpdateStatement::getTableName(ThreadContext* ctx) throw() 
{
	TableJoinTarget* target = static_cast<TableJoinTarget*>(this->table);
	return target->getName(ctx);
}
bool UpdateStatement::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	if(this->table != nullptr && !this->table->visit(visitor, this, ctx))
	{
		return false;
	}
	int maxLoop = this->sets->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		if(!this->sets->get(i, ctx)->visit(visitor, this, ctx))
		{
			return false;
		}
	}
	if(this->where != nullptr && !this->where->visit(visitor, this, ctx))
	{
		return false;
	}
	return true;
}
bool UpdateStatement::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	if(this->table != nullptr)
	{
		this->table->analyse(context, leftValue, ctx);
	}
	int maxLoop = this->sets->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		this->sets->get(i, ctx)->analyse(context, leftValue, ctx);
	}
	if(this->where != nullptr)
	{
		this->where->analyse(context, leftValue, ctx);
	}
	return true;
}
void UpdateStatement::addUpdateSet(UpdateSet* updset, ThreadContext* ctx) throw() 
{
	this->sets->add(updset, ctx);
}
IJoinTarget* UpdateStatement::getTable(ThreadContext* ctx) throw() 
{
	return table;
}
void UpdateStatement::setTable(IJoinTarget* table, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->table), table, IJoinTarget);
}
ArrayList<UpdateSet>* UpdateStatement::getSets(ThreadContext* ctx) throw() 
{
	return sets;
}
void UpdateStatement::setSets(ArrayList<UpdateSet>* sets, ThreadContext* ctx) throw() 
{
	GCUtils<ArrayList<UpdateSet> >::mv(this, &(this->sets), sets, ctx);
}
SQLWhere* UpdateStatement::getWhere(ThreadContext* ctx) throw() 
{
	return where;
}
void UpdateStatement::setWhere(SQLWhere* where, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->where), where, SQLWhere);
}
IStatement::StatementType UpdateStatement::getType(ThreadContext* ctx) throw() 
{
	return StatementType::UPDATE;
}
void UpdateStatement::analyzeSQL(SQLAnalyseContext* context, bool debug, ThreadContext* ctx)
{
	{
		SynchronizedBlockObj __synchronized_2(this, ctx);
		this->table->analyseSQLTables(context, false, debug, ctx);
		this->table->analyzeSQL(context, debug, ctx);
		int maxLoop = this->sets->size(ctx);
		for(int i = 0; i != maxLoop; ++i)
		{
			UpdateSet* st = this->sets->get(i, ctx);
			st->analyseSQL(context, false, debug, ctx);
		}
		if(this->where != nullptr && this->where->getCondition(ctx) != nullptr)
		{
			this->where->getCondition(ctx)->analyseSQL(context, false, debug, ctx);
		}
		this->table->optimizeScan(context, this->where, nullptr, nullptr, nullptr, debug, ctx);
	}
}
void UpdateStatement::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
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
	int maxLoop = buff->getInt(ctx);
	for(int i = 0; i < maxLoop; ++i)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<UpdateSet*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1048(), ctx));
		}
		UpdateSet* set = static_cast<UpdateSet*>(el);
		this->sets->add(set, ctx);
	}
	isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<SQLWhere*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1041(), ctx));
		}
		__GC_MV(this, &(this->where), static_cast<SQLWhere*>(el), SQLWhere);
	}
}
void UpdateStatement::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putInt(ICommandData::__UpdateStatement, ctx);
	bool isnull = (this->table == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->table->writeData(buff, ctx);
	}
	int maxLoop = this->sets->size(ctx);
	buff->putInt(maxLoop, ctx);
	for(int i = 0; i < maxLoop; ++i)
	{
		UpdateSet* exp = this->sets->get(i, ctx);
		exp->writeData(buff, ctx);
	}
	isnull = (this->where == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->where->writeData(buff, ctx);
	}
}
}}}

