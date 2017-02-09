#include "includes.h"


namespace alinous {namespace compile {namespace sql {





bool CreateTableStatement::__init_done = __init_static_variables();
bool CreateTableStatement::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"CreateTableStatement", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 CreateTableStatement::~CreateTableStatement() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void CreateTableStatement::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"CreateTableStatement", L"~CreateTableStatement");
	__e_obj1.add(this->table, this);
	table = nullptr;
	__e_obj1.add(this->columns, this);
	columns = nullptr;
	__e_obj1.add(this->uniques, this);
	uniques = nullptr;
	__e_obj1.add(this->checks, this);
	checks = nullptr;
	__e_obj1.add(this->primaryKeys, this);
	primaryKeys = nullptr;
	__e_obj1.add(this->region, this);
	region = nullptr;
	__e_obj1.add(this->shardKeys, this);
	shardKeys = nullptr;
	__e_obj1.add(this->subShardKeys, this);
	subShardKeys = nullptr;
	__e_obj1.add(this->metadata, this);
	metadata = nullptr;
	if(!prepare){
		return;
	}
	AbstractSQLStatement::__releaseRegerences(true, ctx);
}
TableSchema* CreateTableStatement::createMetadata(ScriptMachine* machine, bool debug, ThreadContext* ctx)
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
	TableSchema* schema = (new(ctx) TableSchema(schemeName, nullptr, ctx));
	TableMetadata* tblMetadata = (new(ctx) TableMetadata(tblName, ctx));
	schema->addTableMetadata(tblMetadata, ctx);
	int maxLoop = this->columns->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		DdlColumnDescriptor* colDesc = this->columns->get(i, ctx);
		TableColumnMetadata* colMeta = colDesc->toMetadata(machine, debug, ctx);
		tblMetadata->addColumn(colMeta, ctx);
	}
	ArrayList<String>* prims = this->primaryKeys->getColumns(ctx);
	maxLoop = prims->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		String* prim = prims->get(i, ctx);
		tblMetadata->addPrimaryKey(prim, ctx);
	}
	tblMetadata->setChecks(this->checks, ctx);
	schema->setRegionName(this->region, ctx);
	ArrayList<String>* scolumns = this->primaryKeys->getColumns(ctx);
	if(this->shardKeys != nullptr)
	{
		scolumns = this->shardKeys->getColumns(ctx);
	}
	maxLoop = scolumns->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		String* key = scolumns->get(i, ctx);
		tblMetadata->addShardKey(key, ctx);
	}
	if(this->subShardKeys != nullptr)
	{
		scolumns = this->subShardKeys->getColumns(ctx);
		maxLoop = scolumns->size(ctx);
		for(int i = 0; i != maxLoop; ++i)
		{
			String* key = scolumns->get(i, ctx);
			tblMetadata->addSubShardKey(key, ctx);
		}
	}
	TablePartitionMaxValue* maxPartitionValue = makeMaxTablePartitionMaxValue(tblMetadata, ctx);
	tblMetadata->setMaxPartitionValue(maxPartitionValue, ctx);
	return schema;
}
void CreateTableStatement::validate(SourceValidator* validator, ThreadContext* ctx) throw() 
{
	if(!((dynamic_cast<TableJoinTarget*>(this->table) != 0)))
	{
		validator->addError(ConstStr::getCNST_STR_1028(), this, ctx);
	}
		else 
	{
		TableJoinTarget* tbl = static_cast<TableJoinTarget*>(this->table);
		ArrayList<String>* segments = tbl->getName(ctx)->getSegments(ctx);
		if(segments->size(ctx) > 2)
		{
			validator->addError(ConstStr::getCNST_STR_1028(), this, ctx);
		}
	}
	int maxLoop = this->columns->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		DdlColumnDescriptor* colDesc = this->columns->get(i, ctx);
		colDesc->validate(validator, ctx);
	}
	if(this->primaryKeys == nullptr)
	{
		validator->addError(ConstStr::getCNST_STR_1029(), this, ctx);
	}
}
TableMetadata* CreateTableStatement::getMetadata(ThreadContext* ctx) throw() 
{
	return metadata;
}
bool CreateTableStatement::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	if(this->table != nullptr && !this->table->visit(visitor, this, ctx))
	{
		return false;
	}
	int max = this->columns->size(ctx);
	for(int i = 0; i != max; ++i)
	{
		if(!this->columns->get(i, ctx)->visit(visitor, this, ctx))
		{
			return false;
		}
	}
	max = this->uniques->size(ctx);
	for(int i = 0; i != max; ++i)
	{
		if(!this->uniques->get(i, ctx)->visit(visitor, this, ctx))
		{
			return false;
		}
	}
	max = this->checks->size(ctx);
	for(int i = 0; i != max; ++i)
	{
		if(!this->checks->get(i, ctx)->visit(visitor, this, ctx))
		{
			return false;
		}
	}
	if(this->primaryKeys != nullptr && !this->primaryKeys->visit(visitor, this, ctx))
	{
		return false;
	}
	return true;
}
bool CreateTableStatement::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	if(this->table != nullptr)
	{
		this->table->analyse(context, leftValue, ctx);
	}
	int max = this->columns->size(ctx);
	for(int i = 0; i != max; ++i)
	{
		this->columns->get(i, ctx)->analyse(context, leftValue, ctx);
	}
	max = this->uniques->size(ctx);
	for(int i = 0; i != max; ++i)
	{
		this->uniques->get(i, ctx)->analyse(context, leftValue, ctx);
	}
	max = this->checks->size(ctx);
	for(int i = 0; i != max; ++i)
	{
		this->checks->get(i, ctx)->analyse(context, leftValue, ctx);
	}
	if(this->primaryKeys != nullptr)
	{
		this->primaryKeys->analyse(context, leftValue, ctx);
	}
	return true;
}
void CreateTableStatement::addColumn(DdlColumnDescriptor* col, ThreadContext* ctx) throw() 
{
	this->columns->add(col, ctx);
}
void CreateTableStatement::addUnique(Unique* unique, ThreadContext* ctx) throw() 
{
	this->uniques->add(unique, ctx);
}
void CreateTableStatement::addCheckDef(CheckDefinition* def, ThreadContext* ctx) throw() 
{
	this->checks->add(def, ctx);
}
IJoinTarget* CreateTableStatement::getTable(ThreadContext* ctx) throw() 
{
	return table;
}
void CreateTableStatement::setTable(IJoinTarget* table, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->table), table, IJoinTarget);
}
PrimaryKeys* CreateTableStatement::getPrimaryKeys(ThreadContext* ctx) throw() 
{
	return primaryKeys;
}
void CreateTableStatement::setPrimaryKeys(PrimaryKeys* primaryKeys, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->primaryKeys), primaryKeys, PrimaryKeys);
}
ArrayList<DdlColumnDescriptor>* CreateTableStatement::getColumns(ThreadContext* ctx) throw() 
{
	return columns;
}
ArrayList<Unique>* CreateTableStatement::getUniques(ThreadContext* ctx) throw() 
{
	return uniques;
}
ArrayList<CheckDefinition>* CreateTableStatement::getChecks(ThreadContext* ctx) throw() 
{
	return checks;
}
String* CreateTableStatement::getRegion(ThreadContext* ctx) throw() 
{
	return region;
}
void CreateTableStatement::setRegion(String* region, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->region), region, String);
}
IStatement::StatementType CreateTableStatement::getType(ThreadContext* ctx) throw() 
{
	return StatementType::CREATE_TABLE;
}
void CreateTableStatement::analyzeSQL(SQLAnalyseContext* context, bool debug, ThreadContext* ctx) throw() 
{
}
void CreateTableStatement::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
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
		if(el == nullptr || !((dynamic_cast<DdlColumnDescriptor*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1031(), ctx));
		}
		this->columns->add(static_cast<DdlColumnDescriptor*>(el), ctx);
	}
	maxLoop = buff->getInt(ctx);
	for(int i = 0; i < maxLoop; ++i)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<Unique*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1032(), ctx));
		}
		this->uniques->add(static_cast<Unique*>(el), ctx);
	}
	maxLoop = buff->getInt(ctx);
	for(int i = 0; i < maxLoop; ++i)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<CheckDefinition*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1033(), ctx));
		}
		this->checks->add(static_cast<CheckDefinition*>(el), ctx);
	}
	isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<PrimaryKeys*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1034(), ctx));
		}
		__GC_MV(this, &(this->primaryKeys), static_cast<PrimaryKeys*>(el), PrimaryKeys);
	}
	isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		__GC_MV(this, &(this->region), buff->getString(ctx), String);
	}
	isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<ShardKeys*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1035(), ctx));
		}
		__GC_MV(this, &(this->shardKeys), static_cast<ShardKeys*>(el), ShardKeys);
	}
	isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<SubShardKeys*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1036(), ctx));
		}
		__GC_MV(this, &(this->subShardKeys), static_cast<SubShardKeys*>(el), SubShardKeys);
	}
}
void CreateTableStatement::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putInt(ICommandData::__CreateTableStatement, ctx);
	bool isnull = (this->table == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->table->writeData(buff, ctx);
	}
	int maxLoop = this->columns->size(ctx);
	buff->putInt(maxLoop, ctx);
	for(int i = 0; i < maxLoop; ++i)
	{
		DdlColumnDescriptor* exp = this->columns->get(i, ctx);
		exp->writeData(buff, ctx);
	}
	maxLoop = this->uniques->size(ctx);
	buff->putInt(maxLoop, ctx);
	for(int i = 0; i < maxLoop; ++i)
	{
		Unique* exp = this->uniques->get(i, ctx);
		exp->writeData(buff, ctx);
	}
	maxLoop = this->checks->size(ctx);
	buff->putInt(maxLoop, ctx);
	for(int i = 0; i < maxLoop; ++i)
	{
		CheckDefinition* exp = this->checks->get(i, ctx);
		exp->writeData(buff, ctx);
	}
	isnull = (this->primaryKeys == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->primaryKeys->writeData(buff, ctx);
	}
	isnull = (this->region == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		buff->putString(this->region, ctx);
	}
	isnull = (this->shardKeys == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		shardKeys->writeData(buff, ctx);
	}
	isnull = (this->subShardKeys == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		subShardKeys->writeData(buff, ctx);
	}
}
ShardKeys* CreateTableStatement::getShardKeys(ThreadContext* ctx) throw() 
{
	return shardKeys;
}
void CreateTableStatement::setShardKeys(ShardKeys* shardKeys, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->shardKeys), shardKeys, ShardKeys);
}
SubShardKeys* CreateTableStatement::getSubShardKeys(ThreadContext* ctx) throw() 
{
	return subShardKeys;
}
void CreateTableStatement::setSubShardKeys(SubShardKeys* subShardKeys, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->subShardKeys), subShardKeys, SubShardKeys);
}
TablePartitionMaxValue* CreateTableStatement::makeMaxTablePartitionMaxValue(TableMetadata* tblMetadata, ThreadContext* ctx) throw() 
{
	TablePartitionMaxValue* value = (new(ctx) TablePartitionMaxValue(ctx));
	ArrayList<String>* scolumns = this->primaryKeys->getColumns(ctx);
	if(this->shardKeys != nullptr)
	{
		scolumns = this->shardKeys->getColumns(ctx);
	}
	int maxLoop = scolumns->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		String* key = scolumns->get(i, ctx);
		TableColumnMetadata* col = tblMetadata->getColumnByName(key, ctx);
		int coltype = col->getType(ctx);
		int type = ddlColumnType2VariantType(coltype, ctx);
		VariantValue* max = VariantValue::createMaxValue(type, ctx);
		value->addValue(max, ctx);
	}
	if(this->subShardKeys != nullptr)
	{
		scolumns = this->subShardKeys->getColumns(ctx);
		maxLoop = scolumns->size(ctx);
		for(int i = 0; i != maxLoop; ++i)
		{
			String* key = scolumns->get(i, ctx);
			TableColumnMetadata* col = tblMetadata->getColumnByName(key, ctx);
			int coltype = col->getType(ctx);
			int type = ddlColumnType2VariantType(coltype, ctx);
			VariantValue* max = VariantValue::createMaxValue(type, ctx);
			value->addSubValue(max, ctx);
		}
	}
	return value;
}
int CreateTableStatement::ddlColumnType2VariantType(int coltype, ThreadContext* ctx) throw() 
{
	int type = 0;
	switch(coltype) {
	case ColumnTypeDescriptor::INT:
		type = VariantValue::TYPE_INT;
		break ;
	case ColumnTypeDescriptor::DOUBLE:
		type = VariantValue::TYPE_DOUBLE;
		break ;
	case ColumnTypeDescriptor::DATE:
	case ColumnTypeDescriptor::TIMESTAMP:
		type = VariantValue::TYPE_TIMESTAMP;
		break ;
	case ColumnTypeDescriptor::TIME:
		type = VariantValue::TYPE_TIME;
		break ;
	case ColumnTypeDescriptor::BIG_DECIMAL:
		type = VariantValue::TYPE_BIG_DECIMAL;
		break ;
	case ColumnTypeDescriptor::VARCHAR:
	case ColumnTypeDescriptor::TEXT:
	case ColumnTypeDescriptor::BLOB:
	default:
		type = VariantValue::TYPE_STRING;
		break ;
	}
	return type;
}
}}}

