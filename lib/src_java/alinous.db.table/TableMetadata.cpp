#include "includes.h"


namespace alinous {namespace db {namespace table {





bool TableMetadata::__init_done = __init_static_variables();
bool TableMetadata::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"TableMetadata", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 TableMetadata::TableMetadata(String* tableName, ThreadContext* ctx) throw()  : IObject(ctx), ICommandData(ctx), columns(GCUtils<HashMap<String,TableColumnMetadata> >::ins(this, (new(ctx) HashMap<String,TableColumnMetadata>(ctx)), ctx, __FILEW__, __LINE__, L"")), columnsList(GCUtils<ArrayList<TableColumnMetadata> >::ins(this, (new(ctx) ArrayList<TableColumnMetadata>(ctx)), ctx, __FILEW__, __LINE__, L"")), primaryKeys(GCUtils<ArrayList<TableColumnMetadata> >::ins(this, (new(ctx) ArrayList<TableColumnMetadata>(ctx)), ctx, __FILEW__, __LINE__, L"")), indexes(GCUtils<ArrayList<TableIndexMetadata> >::ins(this, (new(ctx) ArrayList<TableIndexMetadata>(ctx)), ctx, __FILEW__, __LINE__, L"")), uniqueList(GCUtils<ArrayList<TableMetadataUnique> >::ins(this, (new(ctx) ArrayList<TableMetadataUnique>(ctx)), ctx, __FILEW__, __LINE__, L"")), schema(nullptr), tableName(nullptr), checks(GCUtils<ArrayList<CheckDefinition> >::ins(this, (new(ctx) ArrayList<CheckDefinition>(ctx)), ctx, __FILEW__, __LINE__, L"")), partitionKeys(nullptr), partitionValueRanges(nullptr)
{
	__GC_MV(this, &(this->schema), ConstStr::getCNST_STR_955(), String);
	__GC_MV(this, &(this->tableName), tableName, String);
}
void TableMetadata::__construct_impl(String* tableName, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->schema), ConstStr::getCNST_STR_955(), String);
	__GC_MV(this, &(this->tableName), tableName, String);
}
 TableMetadata::TableMetadata(String* schema, String* tableName, ThreadContext* ctx) throw()  : IObject(ctx), ICommandData(ctx), columns(GCUtils<HashMap<String,TableColumnMetadata> >::ins(this, (new(ctx) HashMap<String,TableColumnMetadata>(ctx)), ctx, __FILEW__, __LINE__, L"")), columnsList(GCUtils<ArrayList<TableColumnMetadata> >::ins(this, (new(ctx) ArrayList<TableColumnMetadata>(ctx)), ctx, __FILEW__, __LINE__, L"")), primaryKeys(GCUtils<ArrayList<TableColumnMetadata> >::ins(this, (new(ctx) ArrayList<TableColumnMetadata>(ctx)), ctx, __FILEW__, __LINE__, L"")), indexes(GCUtils<ArrayList<TableIndexMetadata> >::ins(this, (new(ctx) ArrayList<TableIndexMetadata>(ctx)), ctx, __FILEW__, __LINE__, L"")), uniqueList(GCUtils<ArrayList<TableMetadataUnique> >::ins(this, (new(ctx) ArrayList<TableMetadataUnique>(ctx)), ctx, __FILEW__, __LINE__, L"")), schema(nullptr), tableName(nullptr), checks(GCUtils<ArrayList<CheckDefinition> >::ins(this, (new(ctx) ArrayList<CheckDefinition>(ctx)), ctx, __FILEW__, __LINE__, L"")), partitionKeys(nullptr), partitionValueRanges(nullptr)
{
	__GC_MV(this, &(this->schema), schema, String);
	__GC_MV(this, &(this->tableName), tableName, String);
}
void TableMetadata::__construct_impl(String* schema, String* tableName, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->schema), schema, String);
	__GC_MV(this, &(this->tableName), tableName, String);
}
 TableMetadata::~TableMetadata() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void TableMetadata::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"TableMetadata", L"~TableMetadata");
	__e_obj1.add(this->columns, this);
	columns = nullptr;
	__e_obj1.add(this->columnsList, this);
	columnsList = nullptr;
	__e_obj1.add(this->primaryKeys, this);
	primaryKeys = nullptr;
	__e_obj1.add(this->indexes, this);
	indexes = nullptr;
	__e_obj1.add(this->uniqueList, this);
	uniqueList = nullptr;
	__e_obj1.add(this->schema, this);
	schema = nullptr;
	__e_obj1.add(this->tableName, this);
	tableName = nullptr;
	__e_obj1.add(this->checks, this);
	checks = nullptr;
	__e_obj1.add(this->partitionKeys, this);
	partitionKeys = nullptr;
	__e_obj1.add(this->partitionValueRanges, this);
	partitionValueRanges = nullptr;
	if(!prepare){
		return;
	}
}
TableClusterData* TableMetadata::toCommandData(String* region, String* host, int port, bool ipv6, ThreadContext* ctx) throw() 
{
	TableClusterData* data = (new(ctx) TableClusterData(ctx));
	data->setRegion(region, ctx);
	data->setName(this->tableName, ctx);
	StorageNodeData* node = (new(ctx) StorageNodeData(host, port, ipv6, this, ctx));
	data->addNode(node, ctx);
	return data;
}
bool TableMetadata::checkEquals(TableMetadata* metadata, ThreadContext* ctx) throw() 
{
	if(!this->schema->equals(metadata->schema, ctx))
	{
		return false;
	}
	if(!this->tableName->equals(metadata->tableName, ctx))
	{
		return false;
	}
	if(this->columns->size(ctx) != metadata->columns->size(ctx))
	{
		return false;
	}
	if(this->primaryKeys->size(ctx) != metadata->primaryKeys->size(ctx))
	{
		return false;
	}
	return true;
}
int TableMetadata::fileSize(ThreadContext* ctx)
{
	int total = this->schema->length(ctx) * 2 + 4;
	total += this->tableName->length(ctx) * 2 + 4;
	total += 4;
	Set<String>* list = this->columns->keySet(ctx);
	Iterator<String>* it = list->iterator(ctx);
	while(it->hasNext(ctx))
	{
		String* key = it->next(ctx);
		TableColumnMetadata* col = this->columns->get(key, ctx);
		total += col->fileSize(ctx);
	}
	int maxLoop = this->primaryKeys->size(ctx);
	total += 4;
	for(int i = 0; i != maxLoop; ++i)
	{
		TableColumnMetadata* col = this->primaryKeys->get(i, ctx);
		total += col->fileSize(ctx);
	}
	maxLoop = this->indexes->size(ctx);
	total += 4;
	for(int i = 0; i != maxLoop; ++i)
	{
		TableIndexMetadata* idx = this->indexes->get(i, ctx);
		total += idx->fileSize(ctx);
	}
	maxLoop = this->uniqueList->size(ctx);
	total += 4;
	for(int i = 0; i != maxLoop; ++i)
	{
		TableMetadataUnique* col = this->uniqueList->get(i, ctx);
		total += col->fileSize(ctx);
	}
	total += 1;
	if(this->partitionValueRanges != nullptr)
	{
		total += this->partitionValueRanges->fileSize(ctx);
	}
	maxLoop = this->checks->size(ctx);
	total += 4;
	for(int i = 0; i != maxLoop; ++i)
	{
		CheckDefinition* checkdef = this->checks->get(i, ctx);
		total += checkdef->fileSize(ctx);
	}
	total += 1;
	if(this->partitionKeys != nullptr)
	{
		total += this->partitionKeys->fileSize(ctx);
	}
	return total;
}
void TableMetadata::toFileEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	builder->putString(this->schema, ctx);
	builder->putString(this->tableName, ctx);
	Set<String>* list = this->columns->keySet(ctx);
	builder->putInt(list->size(ctx), ctx);
	Iterator<String>* it = list->iterator(ctx);
	while(it->hasNext(ctx))
	{
		String* key = it->next(ctx);
		TableColumnMetadata* col = this->columns->get(key, ctx);
		col->toFileEntry(builder, ctx);
	}
	int maxLoop = this->primaryKeys->size(ctx);
	builder->putInt(maxLoop, ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		TableColumnMetadata* col = this->primaryKeys->get(i, ctx);
		col->toFileEntry(builder, ctx);
	}
	maxLoop = this->indexes->size(ctx);
	builder->putInt(maxLoop, ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		TableIndexMetadata* idx = this->indexes->get(i, ctx);
		idx->toFileEntry(builder, ctx);
	}
	maxLoop = this->uniqueList->size(ctx);
	builder->putInt(maxLoop, ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		TableMetadataUnique* col = this->uniqueList->get(i, ctx);
		col->toFileEntry(builder, ctx);
	}
	bool isnull = (this->partitionValueRanges == nullptr);
	builder->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->partitionValueRanges->toFileEntry(builder, ctx);
	}
	maxLoop = this->checks->size(ctx);
	builder->putInt(maxLoop, ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		CheckDefinition* checkdef = this->checks->get(i, ctx);
		checkdef->toFileEntry(builder, ctx);
	}
	isnull = (this->partitionKeys == nullptr);
	builder->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->partitionKeys->toFileEntry(builder, ctx);
	}
}
void TableMetadata::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	int maxLoop = buff->getInt(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		TableColumnMetadata* col = TableColumnMetadata::fromNetwork(buff, ctx);
		addColumn(col, ctx);
	}
	maxLoop = buff->getInt(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		TableColumnMetadata* col = TableColumnMetadata::fromNetwork(buff, ctx);
		{
			try
			{
				addPrimaryKey(col, ctx);
			}
			catch(AlinousDbException* e)
			{
				throw (new(ctx) VariableException(ConstStr::getCNST_STR_1701(), e, ctx));
			}
		}
	}
	maxLoop = buff->getInt(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		TableIndexMetadata* idx = TableIndexMetadata::fromNetwork(buff, ctx);
		{
			try
			{
				idx->setupColumnMetadata(this, ctx);
			}
			catch(AlinousDbException* e)
			{
				throw (new(ctx) VariableException(ConstStr::getCNST_STR_1702(), e, ctx));
			}
		}
		indexes->add(idx, ctx);
	}
	maxLoop = buff->getInt(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		TableMetadataUnique* col = TableMetadataUnique::fromNetwork(buff, ctx);
		this->uniqueList->add(col, ctx);
	}
	bool isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		__GC_MV(this, &(this->partitionValueRanges), TablePartitionRangeCollection::fromNetwork(buff, ctx), TablePartitionRangeCollection);
	}
	maxLoop = buff->getInt(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<CheckDefinition*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1034(), ctx));
		}
		CheckDefinition* def = static_cast<CheckDefinition*>(el);
		this->checks->add(def, ctx);
	}
	isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		__GC_MV(this, &(this->partitionKeys), TablePartitionKeyCollection::fromNetwork(buff, ctx), TablePartitionKeyCollection);
	}
}
void TableMetadata::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	buff->putString(this->schema, ctx);
	buff->putString(this->tableName, ctx);
	Set<String>* list = this->columns->keySet(ctx);
	buff->putInt(list->size(ctx), ctx);
	Iterator<String>* it = list->iterator(ctx);
	while(it->hasNext(ctx))
	{
		String* key = it->next(ctx);
		TableColumnMetadata* col = this->columns->get(key, ctx);
		col->writeData(buff, ctx);
	}
	int maxLoop = this->primaryKeys->size(ctx);
	buff->putInt(maxLoop, ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		TableColumnMetadata* col = this->primaryKeys->get(i, ctx);
		col->writeData(buff, ctx);
	}
	maxLoop = this->indexes->size(ctx);
	buff->putInt(maxLoop, ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		TableIndexMetadata* idx = this->indexes->get(i, ctx);
		idx->writeData(buff, ctx);
	}
	maxLoop = this->uniqueList->size(ctx);
	buff->putInt(maxLoop, ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		TableMetadataUnique* col = this->uniqueList->get(i, ctx);
		col->writeData(buff, ctx);
	}
	bool isnull = (this->partitionValueRanges == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->partitionValueRanges->writeData(buff, ctx);
	}
	maxLoop = this->checks->size(ctx);
	buff->putInt(maxLoop, ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		CheckDefinition* checkdef = this->checks->get(i, ctx);
		checkdef->writeData(buff, ctx);
	}
	isnull = (this->partitionKeys == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->partitionKeys->writeData(buff, ctx);
	}
}
void TableMetadata::addindex(TableIndexMetadata* indexMeta, ThreadContext* ctx) throw() 
{
	this->indexes->add(indexMeta, ctx);
}
void TableMetadata::addColumn(String* name, int type, int length, ThreadContext* ctx) throw() 
{
	TableColumnMetadata* column = (new(ctx) TableColumnMetadata(name, type, length, ctx));
	column->columnOrder = this->columnsList->size(ctx);
	this->columns->put(column->name->toLowerCase(ctx), column, ctx);
	this->columnsList->add(column, ctx);
}
void TableMetadata::addColumn(TableColumnMetadata* meta, ThreadContext* ctx) throw() 
{
	meta->columnOrder = this->columnsList->size(ctx);
	this->columns->put(meta->name->toLowerCase(ctx), meta, ctx);
	this->columnsList->add(meta, ctx);
}
ArrayList<TableColumnMetadata>* TableMetadata::getColumnsList(ThreadContext* ctx) throw() 
{
	return columnsList;
}
int TableMetadata::size(ThreadContext* ctx) throw() 
{
	return this->columnsList->size(ctx);
}
TableColumnMetadata* TableMetadata::getColumnByName(String* name, ThreadContext* ctx) throw() 
{
	TableColumnMetadata* data = columns->get(name, ctx);
	return data;
}
int TableMetadata::getColumnOrder(String* columnName, ThreadContext* ctx) throw() 
{
	TableColumnMetadata* col = this->columns->get(columnName, ctx);
	if(col == nullptr)
	{
		return -1;
	}
	return col->columnOrder;
}
int TableMetadata::getColumnCount(ThreadContext* ctx) throw() 
{
	return this->columnsList->size(ctx);
}
ArrayList<TableIndexMetadata>* TableMetadata::getIndexes(ThreadContext* ctx) throw() 
{
	return indexes;
}
String* TableMetadata::getSchema(ThreadContext* ctx) throw() 
{
	return schema;
}
void TableMetadata::setSchema(String* schema, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->schema), schema, String);
}
String* TableMetadata::getTableName(ThreadContext* ctx) throw() 
{
	return tableName;
}
ArrayList<TableColumnMetadata>* TableMetadata::getPrimaryKeys(ThreadContext* ctx) throw() 
{
	return primaryKeys;
}
void TableMetadata::addPrimaryKey(String* col, ThreadContext* ctx)
{
	TableColumnMetadata* colmeta = this->columns->get(col->toLowerCase(ctx), ctx);
	if(colmeta == nullptr)
	{
		throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1703(), ctx));
	}
	this->primaryKeys->add(colmeta, ctx);
	colmeta->setPrimaryKey(true, ctx);
}
void TableMetadata::addPrimaryKey(TableColumnMetadata* colmeta, ThreadContext* ctx)
{
	this->primaryKeys->add(colmeta, ctx);
	colmeta->setPrimaryKey(true, ctx);
}
ArrayList<CheckDefinition>* TableMetadata::getChecks(ThreadContext* ctx) throw() 
{
	return checks;
}
void TableMetadata::setChecks(ArrayList<CheckDefinition>* checks, ThreadContext* ctx) throw() 
{
	GCUtils<ArrayList<CheckDefinition> >::mv(this, &(this->checks), checks, ctx);
}
bool TableMetadata::checkHasIndex(ArrayList<String>* columns, String* indexName, ThreadContext* ctx) throw() 
{
	int maxLoop = this->indexes->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		TableIndexMetadata* index = this->indexes->get(i, ctx);
		String* name = index->getName(ctx);
		if(name->equals(indexName, ctx))
		{
			return true;
		}
		if(checkColumnArrays(columns, index, ctx))
		{
			return true;
		}
	}
	return false;
}
TableMetadataUniqueCollection* TableMetadata::getUniques(ThreadContext* ctx) throw() 
{
	TableMetadataUniqueCollection* list = (new(ctx) TableMetadataUniqueCollection(ctx));
	int maxLoop = this->primaryKeys->size(ctx);
	if(maxLoop > 0)
	{
		ScanUnique* unique = (new(ctx) ScanUnique(ctx));
		for(int i = 0; i != maxLoop; ++i)
		{
			TableColumnMetadata* col = this->primaryKeys->get(i, ctx);
			unique->addUnique(col, ctx);
		}
		list->addUnique(unique, ctx);
	}
	maxLoop = this->columnsList->size(ctx);
	if(maxLoop > 0)
	{
		for(int i = 0; i != maxLoop; ++i)
		{
			TableColumnMetadata* col = this->columnsList->get(i, ctx);
			if(col->isUnique(ctx))
			{
				ScanUnique* unique = (new(ctx) ScanUnique(ctx));
				unique->addUnique(col, ctx);
				list->addUnique(unique, ctx);
			}
		}
	}
	maxLoop = this->uniqueList->size(ctx);
	if(maxLoop > 0)
	{
		for(int i = 0; i != maxLoop; ++i)
		{
			TableMetadataUnique* unique = this->uniqueList->get(i, ctx);
			list->addUnique(unique->toScanUnique(ctx), ctx);
		}
	}
	return list;
}
TablePartitionKeyCollection* TableMetadata::getPartitionKeys(ThreadContext* ctx) throw() 
{
	return partitionKeys;
}
TablePartitionRangeCollection* TableMetadata::getPartitionValueRanges(ThreadContext* ctx) throw() 
{
	return partitionValueRanges;
}
void TableMetadata::setPartitionValueRanges(TablePartitionRangeCollection* partitionValueRanges, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->partitionValueRanges), partitionValueRanges, TablePartitionRangeCollection);
}
void TableMetadata::setPartitionKeys(TablePartitionKeyCollection* partitionKeys, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->partitionKeys), partitionKeys, TablePartitionKeyCollection);
}
bool TableMetadata::checkColumnArrays(ArrayList<String>* columns, TableIndexMetadata* index, ThreadContext* ctx) throw() 
{
	int maxLoop = columns->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		String* name = columns->get(i, ctx);
		if(!index->hasColumn(name, ctx))
		{
			return false;
		}
	}
	return true;
}
TableMetadata* TableMetadata::loadFromFetcher(FileStorageEntryFetcher* fetcher, ThreadContext* ctx)
{
	String* sc = fetcher->fetchString(ctx);
	String* tableName = fetcher->fetchString(ctx);
	TableMetadata* metadata = (new(ctx) TableMetadata(sc, tableName, ctx));
	int maxLoop = fetcher->fetchInt(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		TableColumnMetadata* col = TableColumnMetadata::loadFromFetcher(fetcher, ctx);
		metadata->addColumn(col, ctx);
	}
	maxLoop = fetcher->fetchInt(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		TableColumnMetadata* col = TableColumnMetadata::loadFromFetcher(fetcher, ctx);
		metadata->addPrimaryKey(col, ctx);
	}
	maxLoop = fetcher->fetchInt(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		TableIndexMetadata* idx = TableIndexMetadata::loadFromFetcher(fetcher, ctx);
		idx->setupColumnMetadata(metadata, ctx);
		metadata->indexes->add(idx, ctx);
	}
	maxLoop = fetcher->fetchInt(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		TableMetadataUnique* col = TableMetadataUnique::loadFromFetcher(fetcher, ctx);
		metadata->uniqueList->add(col, ctx);
	}
	char isnull = fetcher->fetchByte(ctx);
	if(isnull == (char)0)
	{
		__GC_MV(metadata, &(metadata->partitionValueRanges), TablePartitionRangeCollection::loadFromFetcher(fetcher, ctx), TablePartitionRangeCollection);
	}
	maxLoop = fetcher->fetchInt(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		CheckDefinition* def = CheckDefinition::fromFileEntry(fetcher, ctx);
		metadata->checks->add(def, ctx);
	}
	isnull = fetcher->fetchByte(ctx);
	if(isnull == (char)0)
	{
		__GC_MV(metadata, &(metadata->partitionKeys), TablePartitionKeyCollection::loadFromFetcher(fetcher, ctx), TablePartitionKeyCollection);
	}
	return metadata;
}
TableMetadata* TableMetadata::fromNetwork(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	String* sc = buff->getString(ctx);
	String* tableName = buff->getString(ctx);
	TableMetadata* metadata = (new(ctx) TableMetadata(sc, tableName, ctx));
	metadata->readData(buff, ctx);
	return metadata;
}
}}}

