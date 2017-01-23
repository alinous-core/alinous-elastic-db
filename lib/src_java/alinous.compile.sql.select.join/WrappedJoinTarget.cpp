#include "includes.h"


namespace alinous {namespace compile {namespace sql {namespace select {namespace join {





bool WrappedJoinTarget::__init_done = __init_static_variables();
bool WrappedJoinTarget::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"WrappedJoinTarget", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 WrappedJoinTarget::~WrappedJoinTarget() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void WrappedJoinTarget::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"WrappedJoinTarget", L"~WrappedJoinTarget");
	__e_obj1.add(this->join, this);
	join = nullptr;
	if(!prepare){
		return;
	}
	AbstractJoinTarget::__releaseRegerences(true, ctx);
}
bool WrappedJoinTarget::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	if(this->join != nullptr && !this->join->visit(visitor, this, ctx))
	{
		return false;
	}
	return true;
}
bool WrappedJoinTarget::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	if(this->join != nullptr)
	{
		this->join->analyse(context, leftValue, ctx);
	}
	return true;
}
IJoin* WrappedJoinTarget::getJoin(ThreadContext* ctx) throw() 
{
	return join;
}
void WrappedJoinTarget::setJoin(IJoin* join, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->join), join, IJoin);
}
bool WrappedJoinTarget::analyseSQLTables(SQLAnalyseContext* context, bool leftValue, bool debug, ThreadContext* ctx)
{
	this->join->analyseSQLTables(context, leftValue, debug, ctx);
	return true;
}
void WrappedJoinTarget::analyzeSQL(SQLAnalyseContext* context, bool debug, ThreadContext* ctx)
{
	this->join->analyzeSQL(context, debug, ctx);
}
bool WrappedJoinTarget::hasTable(ScanTableIdentifier* table, ThreadContext* ctx) throw() 
{
	return this->join->hasTable(table, ctx);
}
void WrappedJoinTarget::optimizeScan(SQLAnalyseContext* context, SQLWhere* where, SQLGroupBy* groupby, SQLLimitOffset* limit, ArrayList<ScanTableColumnIdentifier>* joinRequest, bool debug, ThreadContext* ctx)
{
	this->join->optimizeScan(context, where, groupby, limit, joinRequest, debug, ctx);
}
ScanTableMetadata* WrappedJoinTarget::getScanTableMetadata(ThreadContext* ctx) throw() 
{
	return this->join->getScanTableMetadata(ctx);
}
bool WrappedJoinTarget::isOptimizerCacheable(ThreadContext* ctx) throw() 
{
	return this->join->isOptimizerCacheable(ctx);
}
ITableTargetScanner* WrappedJoinTarget::getScanner(DbTransaction* trx, ScriptMachine* machine, ArrayList<ScanTableColumnIdentifier>* joinRequest, bool debug, ThreadContext* ctx)
{
	return this->join->getScanner(trx, machine, joinRequest, debug, ctx);
}
SQLJoinCondition* WrappedJoinTarget::getCondition(ThreadContext* ctx)
{
	return this->join->getCondition(ctx);
}
IStatement::StatementType WrappedJoinTarget::getType(ThreadContext* ctx) throw() 
{
	return StatementType::JOIN_PART;
}
void WrappedJoinTarget::validate(SourceValidator* validator, ThreadContext* ctx) throw() 
{
}
void WrappedJoinTarget::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	bool isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<IJoin*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1081(), ctx));
		}
		__GC_MV(this, &(this->join), static_cast<IJoin*>(el), IJoin);
	}
}
void WrappedJoinTarget::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putInt(ICommandData::__WrappedJoinTarget, ctx);
	bool isnull = (this->join == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->join->writeData(buff, ctx);
	}
}
}}}}}

