#include "includes.h"


namespace alinous {namespace compile {namespace sql {namespace select {namespace join {





bool TableJoinTarget::__init_done = __init_static_variables();
bool TableJoinTarget::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"TableJoinTarget", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 TableJoinTarget::~TableJoinTarget() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void TableJoinTarget::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"TableJoinTarget", L"~TableJoinTarget");
	__e_obj1.add(this->name, this);
	name = nullptr;
	__e_obj1.add(this->asName, this);
	asName = nullptr;
	__e_obj1.add(this->scanMeta, this);
	scanMeta = nullptr;
	__e_obj1.add(this->tableId, this);
	tableId = nullptr;
	__e_obj1.add(this->strategy, this);
	strategy = nullptr;
	if(!prepare){
		return;
	}
	AbstractJoinTarget::__releaseRegerences(true, ctx);
}
bool TableJoinTarget::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	if(this->name != nullptr && !this->name->visit(visitor, this, ctx))
	{
		return false;
	}
	return true;
}
bool TableJoinTarget::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	return true;
}
AlinousName* TableJoinTarget::getName(ThreadContext* ctx) throw() 
{
	return name;
}
void TableJoinTarget::setName(AlinousName* name, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->name), name, AlinousName);
}
String* TableJoinTarget::getAsName(ThreadContext* ctx) throw() 
{
	return asName;
}
void TableJoinTarget::setAsName(String* asName, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->asName), asName, String);
}
bool TableJoinTarget::analyseSQLTables(SQLAnalyseContext* context, bool leftValue, bool debug, ThreadContext* ctx)
{
	ArrayList<String>* segments = this->name->getSegments(ctx);
	int size = segments->size(ctx);
	String* schema = nullptr;
	String* table = nullptr;
	switch(size) {
	case 1:
		schema = ConstStr::getCNST_STR_955();
		table = segments->get(0, ctx);
		break ;
	case 2:
		schema = segments->get(0, ctx);
		table = segments->get(1, ctx);
		break ;
	default:
		throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1084()->clone(ctx)->append(this->name->toString(ctx), ctx), ctx));
		break;
	}
	AlinousDatabase* db = context->getDatabase(ctx);
	IDatabaseTable* tableStore = db->getTable(schema, table, ctx);
	if(tableStore == nullptr)
	{
		throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1084()->clone(ctx)->append(this->name->toString(ctx), ctx), ctx));
	}
	__GC_MV(this, &(this->scanMeta), (new(ctx) ScanTableMetadata(tableStore->getMetadata(ctx), this->asName, ctx)), ScanTableMetadata);
	__GC_MV(this, &(this->tableId), (new(ctx) ScanTableIdentifier((new(ctx) TableAndSchema(schema, table, ctx)), this->asName, this->scanMeta->getColumns(ctx)->size(ctx), ctx)), ScanTableIdentifier);
	context->addTable(scanMeta, this->asName, ctx);
	return true;
}
void TableJoinTarget::analyzeSQL(SQLAnalyseContext* context, bool debug, ThreadContext* ctx)
{
}
bool TableJoinTarget::hasTable(ScanTableIdentifier* table, ThreadContext* ctx) throw() 
{
	return this->scanMeta->hasTable(table, ctx);
}
void TableJoinTarget::optimizeScan(SQLAnalyseContext* context, SQLWhere* where, SQLGroupBy* groupby, SQLLimitOffset* limit, ArrayList<ScanTableColumnIdentifier>* joinRequest, bool debug, ThreadContext* ctx)
{
	__GC_MV(this, &(this->strategy), (new(ctx) ScanSingleStrategy(this->scanMeta, this->tableId, context->getDatabase(ctx), ctx)), ScanSingleStrategy);
	this->strategy->analyzeFilterCondition(where, ctx);
	this->strategy->analyzeIndex(where, this->scanMeta, debug, ctx);
	this->strategy->optimize(ctx);
}
ScanTableMetadata* TableJoinTarget::getScanTableMetadata(ThreadContext* ctx) throw() 
{
	return this->scanMeta;
}
bool TableJoinTarget::isOptimizerCacheable(ThreadContext* ctx) throw() 
{
	return true;
}
ITableTargetScanner* TableJoinTarget::getScanner(DbTransaction* trx, ScriptMachine* machine, ArrayList<ScanTableColumnIdentifier>* joinRequest, bool debug, ThreadContext* ctx)
{
	ITableTargetScanner* scanner = this->strategy->getScanner(machine, trx, joinRequest, debug, ctx);
	return scanner;
}
SQLJoinCondition* TableJoinTarget::getCondition(ThreadContext* ctx)
{
	return nullptr;
}
IStatement::StatementType TableJoinTarget::getType(ThreadContext* ctx) throw() 
{
	return StatementType::JOIN_PART;
}
void TableJoinTarget::validate(SourceValidator* validator, ThreadContext* ctx) throw() 
{
}
void TableJoinTarget::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	bool isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<AlinousName*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_970(), ctx));
		}
		__GC_MV(this, &(this->name), static_cast<AlinousName*>(el), AlinousName);
	}
	isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		__GC_MV(this, &(this->asName), buff->getString(ctx), String);
	}
}
void TableJoinTarget::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putInt(ICommandData::__TableJoinTarget, ctx);
	bool isnull = (this->name == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->name->writeData(buff, ctx);
	}
	isnull = (this->asName == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		buff->putString(this->asName, ctx);
	}
}
}}}}}

