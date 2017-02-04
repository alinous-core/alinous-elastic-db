#include "includes.h"


namespace alinous {namespace compile {namespace sql {





bool InsertStatement::__init_done = __init_static_variables();
bool InsertStatement::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"InsertStatement", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 InsertStatement::~InsertStatement() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void InsertStatement::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"InsertStatement", L"~InsertStatement");
	__e_obj1.add(this->table, this);
	table = nullptr;
	__e_obj1.add(this->list, this);
	list = nullptr;
	__e_obj1.add(this->values, this);
	values = nullptr;
	__e_obj1.add(this->schemeName, this);
	schemeName = nullptr;
	__e_obj1.add(this->tblName, this);
	tblName = nullptr;
	__e_obj1.add(this->vctx, this);
	vctx = nullptr;
	if(!prepare){
		return;
	}
	AbstractSQLStatement::__releaseRegerences(true, ctx);
}
TrxRecordsCache* InsertStatement::getCache(ScriptMachine* machine, TrxStorageManager* trxStorageManager, ThreadContext* ctx)
{
	if(this->schemeName == nullptr || this->tblName == nullptr)
	{
		TableJoinTarget* tbl = static_cast<TableJoinTarget*>(this->table);
		ArrayList<String>* segments = tbl->getName(ctx)->getSegments(ctx);
		if(segments->size(ctx) == 1)
		{
			__GC_MV(this, &(schemeName), ConstStr::getCNST_STR_955(), String);
			__GC_MV(this, &(tblName), segments->get(0, ctx), String);
		}
				else 
		{
			if(segments->size(ctx) == 2)
			{
				__GC_MV(this, &(schemeName), segments->get(0, ctx), String);
				__GC_MV(this, &(tblName), segments->get(1, ctx), String);
			}
		}
	}
	TrxRecordsCache* cache = trxStorageManager->getInsertCacheWithCreate(schemeName, tblName, ctx);
	return cache;
}
ArrayList<CulumnOrder>* InsertStatement::getColumnOrder(ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	ArrayList<CulumnOrder>* orderlist = (new(ctx) ArrayList<CulumnOrder>(ctx));
	ArrayList<ISQLExpression>* colExpList = this->list->getList(ctx);
	int maxLoop = colExpList->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ISQLExpression* exp = colExpList->get(i, ctx);
		IAlinousVariable* dom = exp->resolveExpression(machine, debug, ctx);
		CulumnOrder* ord = (new(ctx) CulumnOrder(ctx));
		ord->setValuesOrder(i, ctx);
		ord->setColumnName(dom->getStringValue(ctx), ctx);
		orderlist->add(ord, ctx);
	}
	return orderlist;
}
ArrayList<IDomVariable>* InsertStatement::getInsertRercords(ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	ArrayList<IDomVariable>* reclist = (new(ctx) ArrayList<IDomVariable>(ctx));
	int MaxLoop = this->values->size(ctx);
	for(int i = 0; i != MaxLoop; ++i)
	{
		InsertValues* values = this->values->get(i, ctx);
		IDomVariable* vl = values->getValues(machine, debug, ctx);
		reclist->add(vl, ctx);
	}
	return reclist;
}
void InsertStatement::validate(SourceValidator* validator, ThreadContext* ctx) throw() 
{
	if(!((dynamic_cast<TableJoinTarget*>(this->table) != 0)))
	{
		validator->addError(ConstStr::getCNST_STR_1049(), this->table, ctx);
	}
}
bool InsertStatement::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	if(this->table != nullptr && !this->table->visit(visitor, this, ctx))
	{
		return false;
	}
	if(this->list != nullptr && !this->list->visit(visitor, this, ctx))
	{
		return false;
	}
	int max = this->values->size(ctx);
	for(int i = 0; i != max; ++i)
	{
		if(!this->values->get(i, ctx)->visit(visitor, this, ctx))
		{
			return false;
		}
	}
	return true;
}
bool InsertStatement::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	if(this->table != nullptr)
	{
		this->table->analyse(context, leftValue, ctx);
	}
	if(this->list != nullptr)
	{
		this->list->analyse(context, leftValue, ctx);
	}
	int max = this->values->size(ctx);
	for(int i = 0; i != max; ++i)
	{
		this->values->get(i, ctx)->analyse(context, leftValue, ctx);
	}
	return true;
}
void InsertStatement::addValue(InsertValues* value, ThreadContext* ctx) throw() 
{
	this->values->add(value, ctx);
}
IJoinTarget* InsertStatement::getTable(ThreadContext* ctx) throw() 
{
	return table;
}
void InsertStatement::setTable(IJoinTarget* table, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->table), table, IJoinTarget);
}
SQLExpressionList* InsertStatement::getList(ThreadContext* ctx) throw() 
{
	return list;
}
void InsertStatement::setList(SQLExpressionList* list, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->list), list, SQLExpressionList);
}
ArrayList<InsertValues>* InsertStatement::getValues(ThreadContext* ctx) throw() 
{
	return values;
}
IStatement::StatementType InsertStatement::getType(ThreadContext* ctx) throw() 
{
	return StatementType::INSERT;
}
bool InsertStatement::needsAnalyse(DbVersionContext* vctx, ThreadContext* ctx) throw() 
{
	if(this->vctx == nullptr)
	{
		return true;
	}
	long long lastSchemaVer = this->vctx->getSchemaVersion(ctx);
	if(lastSchemaVer < vctx->getSchemaVersion(ctx))
	{
		return true;
	}
	return true;
}
void InsertStatement::analyzeSQL(SQLAnalyseContext* context, bool debug, ThreadContext* ctx)
{
	{
		SynchronizedBlockObj __synchronized_2(this, ctx);
		this->table->analyseSQLTables(context, false, debug, ctx);
		if(this->table != nullptr)
		{
			this->table->analyzeSQL(context, debug, ctx);
		}
		if(this->list != nullptr)
		{
			this->list->analyseSQL(context, false, debug, ctx);
		}
		int max = this->values->size(ctx);
		for(int i = 0; i != max; ++i)
		{
			this->values->get(i, ctx)->analyseSQL(context, false, debug, ctx);
		}
	}
}
void InsertStatement::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
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
		if(el == nullptr || !((dynamic_cast<SQLExpressionList*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1039(), ctx));
		}
		__GC_MV(this, &(this->list), static_cast<SQLExpressionList*>(el), SQLExpressionList);
	}
	int maxLoop = buff->getInt(ctx);
	for(int i = 0; i < maxLoop; ++i)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<InsertValues*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1050(), ctx));
		}
		this->values->add(static_cast<InsertValues*>(el), ctx);
	}
}
void InsertStatement::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putInt(ICommandData::__InsertStatement, ctx);
	bool isnull = (this->table == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->table->writeData(buff, ctx);
	}
	isnull = (this->list == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->list->writeData(buff, ctx);
	}
	int maxLoop = this->values->size(ctx);
	buff->putInt(maxLoop, ctx);
	for(int i = 0; i < maxLoop; ++i)
	{
		InsertValues* exp = this->values->get(i, ctx);
		exp->writeData(buff, ctx);
	}
}
DbVersionContext* InsertStatement::getVctx(ThreadContext* ctx) throw() 
{
	return vctx;
}
void InsertStatement::setVctx(DbVersionContext* vctx, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->vctx), vctx, DbVersionContext);
}
}}}

