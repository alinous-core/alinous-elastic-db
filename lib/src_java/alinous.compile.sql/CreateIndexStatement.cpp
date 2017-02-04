#include "includes.h"


namespace alinous {namespace compile {namespace sql {





bool CreateIndexStatement::__init_done = __init_static_variables();
bool CreateIndexStatement::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"CreateIndexStatement", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 CreateIndexStatement::~CreateIndexStatement() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void CreateIndexStatement::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"CreateIndexStatement", L"~CreateIndexStatement");
	__e_obj1.add(this->name, this);
	name = nullptr;
	__e_obj1.add(this->table, this);
	table = nullptr;
	__e_obj1.add(this->columns, this);
	columns = nullptr;
	if(!prepare){
		return;
	}
	AbstractSQLStatement::__releaseRegerences(true, ctx);
}
String* CreateIndexStatement::getIndexName(ThreadContext* ctx) throw() 
{
	TableJoinTarget* tbl = static_cast<TableJoinTarget*>(this->name);
	ArrayList<String>* segments = tbl->getName(ctx)->getSegments(ctx);
	if(segments->size(ctx) == 1)
	{
		return segments->get(0, ctx);
	}
	return segments->get(1, ctx);
}
TableAndSchema* CreateIndexStatement::getTableAndSchema(ThreadContext* ctx) throw() 
{
	TableJoinTarget* tbl = static_cast<TableJoinTarget*>(this->table);
	ArrayList<String>* segments = tbl->getName(ctx)->getSegments(ctx);
	String* schemeName = nullptr;
	String* tblName = nullptr;
	if(segments->size(ctx) == 1)
	{
		schemeName = ConstStr::getCNST_STR_955();
		tblName = segments->get(0, ctx);
	}
		else 
	{
		if(segments->size(ctx) == 2)
		{
			schemeName = segments->get(0, ctx);
			tblName = segments->get(1, ctx);
		}
	}
	return (new(ctx) TableAndSchema(schemeName, tblName, ctx));
}
IStatement::StatementType CreateIndexStatement::getType(ThreadContext* ctx) throw() 
{
	return StatementType::CREATE_INDEX;
}
void CreateIndexStatement::validate(SourceValidator* validator, ThreadContext* ctx) throw() 
{
	if(!((dynamic_cast<TableJoinTarget*>(table) != 0)))
	{
		validator->addError(ConstStr::getCNST_STR_1051(), this, ctx);
	}
}
bool CreateIndexStatement::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	if(this->name != nullptr && !this->name->visit(visitor, this, ctx))
	{
		return false;
	}
	if(this->table != nullptr && !this->table->visit(visitor, this, ctx))
	{
		return false;
	}
	return true;
}
bool CreateIndexStatement::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	if(this->name != nullptr)
	{
		this->name->analyse(context, leftValue, ctx);
	}
	if(this->table != nullptr)
	{
		this->table->analyse(context, leftValue, ctx);
	}
	return true;
}
void CreateIndexStatement::addColumn(String* column, ThreadContext* ctx) throw() 
{
	this->columns->add(column, ctx);
}
IJoinTarget* CreateIndexStatement::getName(ThreadContext* ctx) throw() 
{
	return name;
}
void CreateIndexStatement::setName(IJoinTarget* name, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->name), name, IJoinTarget);
}
IJoinTarget* CreateIndexStatement::getTable(ThreadContext* ctx) throw() 
{
	return table;
}
void CreateIndexStatement::setTable(IJoinTarget* table, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->table), table, IJoinTarget);
}
ArrayList<String>* CreateIndexStatement::getColumns(ThreadContext* ctx) throw() 
{
	return columns;
}
void CreateIndexStatement::analyzeSQL(SQLAnalyseContext* context, bool debug, ThreadContext* ctx) throw() 
{
}
void CreateIndexStatement::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	bool isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<IJoinTarget*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1030(), ctx));
		}
		__GC_MV(this, &(this->name), static_cast<IJoinTarget*>(el), IJoinTarget);
	}
	isnull = buff->getBoolean(ctx);
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
		String* str = buff->getString(ctx);
		this->columns->add(str, ctx);
	}
}
void CreateIndexStatement::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putInt(ICommandData::__CreateIndexStatement, ctx);
	bool isnull = (this->name == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->name->writeData(buff, ctx);
	}
	isnull = (this->table == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->table->writeData(buff, ctx);
	}
	int maxLoop = this->columns->size(ctx);
	buff->putInt(maxLoop, ctx);
	for(int i = 0; i < maxLoop; ++i)
	{
		String* str = this->columns->get(i, ctx);
		buff->putString(str, ctx);
	}
}
}}}

