#include "includes.h"


namespace alinous {namespace compile {namespace sql {





bool SelectStatement::__init_done = __init_static_variables();
bool SelectStatement::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"SelectStatement", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 SelectStatement::~SelectStatement() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void SelectStatement::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"SelectStatement", L"~SelectStatement");
	__e_obj1.add(this->intoDesc, this);
	intoDesc = nullptr;
	__e_obj1.add(this->resultDesc, this);
	resultDesc = nullptr;
	__e_obj1.add(this->groupByDesc, this);
	groupByDesc = nullptr;
	__e_obj1.add(this->list, this);
	list = nullptr;
	__e_obj1.add(this->into, this);
	into = nullptr;
	__e_obj1.add(this->from, this);
	from = nullptr;
	__e_obj1.add(this->where, this);
	where = nullptr;
	__e_obj1.add(this->groupBy, this);
	groupBy = nullptr;
	__e_obj1.add(this->limitOffset, this);
	limitOffset = nullptr;
	if(!prepare){
		return;
	}
	IJoinTarget::__releaseRegerences(true, ctx);
}
void SelectStatement::validate(SourceValidator* validator, ThreadContext* ctx) throw() 
{
}
bool SelectStatement::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	if(this->list != nullptr && !this->list->visit(visitor, this, ctx))
	{
		return false;
	}
	if(this->from != nullptr && !this->from->visit(visitor, this, ctx))
	{
		return false;
	}
	if(this->where != nullptr && !this->where->visit(visitor, this, ctx))
	{
		return false;
	}
	if(this->groupBy != nullptr && !this->groupBy->visit(visitor, this, ctx))
	{
		return false;
	}
	if(this->limitOffset != nullptr && !this->limitOffset->visit(visitor, this, ctx))
	{
		return false;
	}
	return true;
}
bool SelectStatement::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	if(this->list != nullptr)
	{
		this->list->analyse(context, leftValue, ctx);
	}
	if(this->from != nullptr)
	{
		this->from->analyse(context, leftValue, ctx);
	}
	if(this->where != nullptr)
	{
		this->where->analyse(context, leftValue, ctx);
	}
	if(this->groupBy != nullptr)
	{
		this->groupBy->analyse(context, leftValue, ctx);
	}
	if(this->limitOffset != nullptr)
	{
		this->limitOffset->analyse(context, leftValue, ctx);
	}
	if(this->into != nullptr)
	{
		__GC_MV(this, &(this->intoDesc), this->into->toDomVariableDescriptor(ctx), DomVariableDescriptor);
	}
	return true;
}
SQLExpressionList* SelectStatement::getList(ThreadContext* ctx) throw() 
{
	return list;
}
void SelectStatement::setList(SQLExpressionList* list, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->list), list, SQLExpressionList);
}
SQLFrom* SelectStatement::getFrom(ThreadContext* ctx) throw() 
{
	return from;
}
void SelectStatement::setFrom(SQLFrom* from, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->from), from, SQLFrom);
}
SQLGroupBy* SelectStatement::getGroupBy(ThreadContext* ctx) throw() 
{
	return groupBy;
}
void SelectStatement::setGroupBy(SQLGroupBy* groupBy, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->groupBy), groupBy, SQLGroupBy);
}
SQLLimitOffset* SelectStatement::getLimitOffset(ThreadContext* ctx) throw() 
{
	return limitOffset;
}
void SelectStatement::setLimitOffset(SQLLimitOffset* limitOffset, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->limitOffset), limitOffset, SQLLimitOffset);
}
SQLWhere* SelectStatement::getWhere(ThreadContext* ctx) throw() 
{
	return where;
}
void SelectStatement::setWhere(SQLWhere* where, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->where), where, SQLWhere);
}
IStatement::StatementType SelectStatement::getType(ThreadContext* ctx) throw() 
{
	return StatementType::SELECT;
}
void SelectStatement::analyzeSQL(SQLAnalyseContext* context, bool debug, ThreadContext* ctx)
{
	{
		SynchronizedBlockObj __synchronized_2(this, ctx);
		if(this->list != nullptr)
		{
			this->list->analyseSQL(context, false, debug, ctx);
		}
		if(this->from != nullptr)
		{
			this->from->analyseSQL(context, false, debug, ctx);
		}
		if(this->where != nullptr && this->where->getCondition(ctx) != nullptr)
		{
			this->where->getCondition(ctx)->analyseSQL(context, false, debug, ctx);
		}
		if(this->groupBy != nullptr)
		{
			this->groupBy->analyseSQL(context, false, debug, ctx);
		}
	}
	optimizeScan(context, this->where, this->groupBy, this->limitOffset, nullptr, debug, ctx);
}
void SelectStatement::optimizeScan(SQLAnalyseContext* context, SQLWhere* where, SQLGroupBy* groupby, SQLLimitOffset* limit, ArrayList<ScanTableColumnIdentifier>* joinRequest, bool debug, ThreadContext* ctx)
{
	IJoin* join = this->from->getJoin(ctx);
	if(join != nullptr)
	{
		join->optimizeScan(context, where, groupby, limit, joinRequest, debug, ctx);
	}
	ScanTableMetadata* metadata = join->getScanTableMetadata(ctx);
	__GC_MV(this, &(this->resultDesc), (new(ctx) SelectResultDescription(this->list, metadata, ctx)), SelectResultDescription);
	if(this->groupBy != nullptr)
	{
		__GC_MV(this, &(this->groupByDesc), (new(ctx) SelectResultDescription(this->groupBy->getGroupList(ctx), metadata, ctx)), SelectResultDescription);
	}
}
bool SelectStatement::analyseSQLTables(SQLAnalyseContext* context, bool leftValue, bool debug, ThreadContext* ctx)
{
	return true;
}
bool SelectStatement::hasTable(ScanTableIdentifier* table, ThreadContext* ctx) throw() 
{
	return false;
}
ScanTableMetadata* SelectStatement::getScanTableMetadata(ThreadContext* ctx) throw() 
{
	return nullptr;
}
bool SelectStatement::isOptimizerCacheable(ThreadContext* ctx) throw() 
{
	return this->from->getJoin(ctx)->isOptimizerCacheable(ctx);
}
ITableTargetScanner* SelectStatement::getScanner(DbTransaction* trx, ScriptMachine* machine, ArrayList<ScanTableColumnIdentifier>* joinRequest, bool debug, ThreadContext* ctx)
{
	IJoin* join = this->from->getJoin(ctx);
	if(join != nullptr)
	{
		return join->getScanner(trx, machine, joinRequest, debug, ctx);
	}
	return nullptr;
}
AlinousName* SelectStatement::getInto(ThreadContext* ctx) throw() 
{
	return into;
}
void SelectStatement::setInto(AlinousName* into, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->into), into, AlinousName);
}
SQLJoinCondition* SelectStatement::getCondition(ThreadContext* ctx)
{
	return nullptr;
}
int SelectStatement::getLine(ThreadContext* ctx) throw() 
{
	return IJoinTarget::getLine(ctx);
}
int SelectStatement::getStartPosition(ThreadContext* ctx) throw() 
{
	return IJoinTarget::getStartPosition(ctx);
}
int SelectStatement::getEndLine(ThreadContext* ctx) throw() 
{
	return IJoinTarget::getEndLine(ctx);
}
int SelectStatement::getEndPosition(ThreadContext* ctx) throw() 
{
	return IJoinTarget::getEndPosition(ctx);
}
AbstractSrcElement* SelectStatement::getParent(ThreadContext* ctx) throw() 
{
	return IJoinTarget::getParent(ctx);
}
void SelectStatement::setParent(AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	IJoinTarget::setParent(parent, ctx);
}
void SelectStatement::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	bool isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<SQLExpressionList*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1039(), ctx));
		}
		__GC_MV(this, &(this->list), static_cast<SQLExpressionList*>(el), SQLExpressionList);
	}
	isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<AlinousName*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_970(), ctx));
		}
		__GC_MV(this, &(this->into), static_cast<AlinousName*>(el), AlinousName);
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
	isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<SQLGroupBy*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1042(), ctx));
		}
		__GC_MV(this, &(this->groupBy), static_cast<SQLGroupBy*>(el), SQLGroupBy);
	}
	isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<SQLLimitOffset*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1043(), ctx));
		}
		__GC_MV(this, &(this->limitOffset), static_cast<SQLLimitOffset*>(el), SQLLimitOffset);
	}
}
void SelectStatement::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	buff->putInt(ICommandData::__SelectStatement, ctx);
	bool isnull = (this->list == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->list->writeData(buff, ctx);
	}
	isnull = (this->into == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->into->writeData(buff, ctx);
	}
	isnull = (this->from == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->from->writeData(buff, ctx);
	}
	isnull = (this->where == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->where->writeData(buff, ctx);
	}
	isnull = (this->groupBy == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->groupBy->writeData(buff, ctx);
	}
	isnull = (this->limitOffset == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->limitOffset->writeData(buff, ctx);
	}
}
}}}

