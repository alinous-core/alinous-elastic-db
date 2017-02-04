#include "includes.h"


namespace alinous {namespace compile {namespace sql {namespace select {namespace join {





bool JoinSubQueryTarget::__init_done = __init_static_variables();
bool JoinSubQueryTarget::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"JoinSubQueryTarget", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 JoinSubQueryTarget::~JoinSubQueryTarget() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void JoinSubQueryTarget::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"JoinSubQueryTarget", L"~JoinSubQueryTarget");
	__e_obj1.add(this->selectStatement, this);
	selectStatement = nullptr;
	__e_obj1.add(this->asName, this);
	asName = nullptr;
	if(!prepare){
		return;
	}
	AbstractJoinTarget::__releaseRegerences(true, ctx);
}
bool JoinSubQueryTarget::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	if(this->selectStatement != nullptr && !this->selectStatement->visit(visitor, this, ctx))
	{
		return false;
	}
	return true;
}
bool JoinSubQueryTarget::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	if(this->selectStatement != nullptr)
	{
		this->selectStatement->analyse(context, leftValue, ctx);
	}
	return true;
}
SelectStatement* JoinSubQueryTarget::getSelectStatement(ThreadContext* ctx) throw() 
{
	return selectStatement;
}
void JoinSubQueryTarget::setSelectStatement(SelectStatement* selectStatement, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->selectStatement), selectStatement, SelectStatement);
}
String* JoinSubQueryTarget::getAsName(ThreadContext* ctx) throw() 
{
	return asName;
}
void JoinSubQueryTarget::setAsName(String* asName, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->asName), asName, String);
}
bool JoinSubQueryTarget::analyseSQLTables(SQLAnalyseContext* context, bool leftValue, bool debug, ThreadContext* ctx)
{
	SQLFrom* from = this->selectStatement->getFrom(ctx);
	if(from != nullptr)
	{
		from->getJoin(ctx)->analyseSQLTables(context, leftValue, debug, ctx);
	}
	return false;
}
void JoinSubQueryTarget::analyzeSQL(SQLAnalyseContext* context, bool debug, ThreadContext* ctx)
{
	this->selectStatement->analyzeSQL(context, debug, ctx);
}
bool JoinSubQueryTarget::hasTable(ScanTableIdentifier* table, ThreadContext* ctx) throw() 
{
	return false;
}
void JoinSubQueryTarget::optimizeScan(SQLAnalyseContext* context, SQLWhere* where, SQLGroupBy* groupby, SQLLimitOffset* limit, ArrayList<ScanTableColumnIdentifier>* joinRequest, bool debug, ThreadContext* ctx)
{
	this->selectStatement->optimizeScan(context, where, groupby, limit, joinRequest, debug, ctx);
}
ScanTableMetadata* JoinSubQueryTarget::getScanTableMetadata(ThreadContext* ctx) throw() 
{
	return this->selectStatement->getScanTableMetadata(ctx);
}
bool JoinSubQueryTarget::isOptimizerCacheable(ThreadContext* ctx) throw() 
{
	return this->selectStatement->isOptimizerCacheable(ctx);
}
ITableTargetScanner* JoinSubQueryTarget::getScanner(DbTransaction* trx, ScriptMachine* machine, ArrayList<ScanTableColumnIdentifier>* joinRequest, bool debug, ThreadContext* ctx)
{
	return this->selectStatement->getScanner(trx, machine, joinRequest, debug, ctx);
}
SQLJoinCondition* JoinSubQueryTarget::getCondition(ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
IStatement::StatementType JoinSubQueryTarget::getType(ThreadContext* ctx) throw() 
{
	return StatementType::JOIN_PART;
}
void JoinSubQueryTarget::validate(SourceValidator* validator, ThreadContext* ctx) throw() 
{
}
void JoinSubQueryTarget::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	bool isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<SelectStatement*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1070(), ctx));
		}
		__GC_MV(this, &(this->selectStatement), static_cast<SelectStatement*>(el), SelectStatement);
	}
	isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		__GC_MV(this, &(this->asName), buff->getString(ctx), String);
	}
}
void JoinSubQueryTarget::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putInt(ICommandData::__JoinSubQueryTarget, ctx);
	bool isnull = (this->selectStatement == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->selectStatement->writeData(buff, ctx);
	}
	isnull = (this->asName == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		buff->putString(this->asName, ctx);
	}
}
}}}}}

