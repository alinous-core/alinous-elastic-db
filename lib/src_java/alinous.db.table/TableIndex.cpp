#include "includes.h"


namespace alinous {namespace db {namespace table {





constexpr const int TableIndex::capacity;
constexpr const int TableIndex::BLOCK_SIZE;
constexpr const int TableIndex::maxCache;
bool TableIndex::__init_done = __init_static_variables();
bool TableIndex::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"TableIndex", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 TableIndex::TableIndex(String* name, String* baseDir, bool primary, ArrayList<TableColumnMetadata>* metadata, ThreadContext* ctx) throw()  : IObject(ctx), IBtreeTableIndex(ctx), IScannableIndex(ctx), name(nullptr), baseDir(nullptr), primary(0), columns(GCUtils<ArrayList<TableColumnMetadata> >::ins(this, (new(ctx) ArrayList<TableColumnMetadata>(ctx)), ctx, __FILEW__, __LINE__, L"")), filePath(nullptr), storage(nullptr)
{
	__GC_MV(this, &(this->name), name, String);
	__GC_MV(this, &(this->baseDir), baseDir, String);
	this->primary = primary;
	GCUtils<ArrayList<TableColumnMetadata> >::mv(this, &(this->columns), metadata, ctx);
	setPath(ctx);
}
void TableIndex::__construct_impl(String* name, String* baseDir, bool primary, ArrayList<TableColumnMetadata>* metadata, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->name), name, String);
	__GC_MV(this, &(this->baseDir), baseDir, String);
	this->primary = primary;
	GCUtils<ArrayList<TableColumnMetadata> >::mv(this, &(this->columns), metadata, ctx);
	setPath(ctx);
}
 TableIndex::~TableIndex() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void TableIndex::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"TableIndex", L"~TableIndex");
	__e_obj1.add(this->name, this);
	name = nullptr;
	__e_obj1.add(this->baseDir, this);
	baseDir = nullptr;
	__e_obj1.add(this->columns, this);
	columns = nullptr;
	__e_obj1.add(this->filePath, this);
	filePath = nullptr;
	__e_obj1.add(this->storage, this);
	storage = nullptr;
	if(!prepare){
		return;
	}
}
bool TableIndex::isOpened(ThreadContext* ctx) throw() 
{
	return this->storage->isOpened(ctx);
}
void TableIndex::open(AlinousDatabase* database, ThreadContext* ctx)
{
	if(this->storage == nullptr)
	{
		File* file = (new(ctx) File(this->filePath, ctx));
		__GC_MV(this, &(this->storage), (new(ctx) BTree(ctx))->init(file, database->getBtreeCache(ctx), database->getCore(ctx)->diskCache, ctx), BTree);
	}
	if(!this->storage->isOpened(ctx))
	{
		this->storage->open(ctx);
	}
}
void TableIndex::close(ThreadContext* ctx)
{
	if(this->storage->isOpened(ctx))
	{
		this->storage->close(ctx);
	}
}
bool TableIndex::isAvailable(ArrayList<String>* columnsStr, ThreadContext* ctx) throw() 
{
	int maxLoop = columnsStr->size(ctx);
	if(maxLoop > this->columns->size(ctx))
	{
		return false;
	}
	for(int i = 0; i != maxLoop; ++i)
	{
		String* key = columnsStr->get(i, ctx);
		TableColumnMetadata* colMeta = this->columns->get(i, ctx);
		if(!key->equals(colMeta->name, ctx))
		{
			return false;
		}
	}
	return true;
}
bool TableIndex::isAvailableByScanId(ArrayList<ScanTableColumnIdentifier>* columnIds, ThreadContext* ctx) throw() 
{
	int maxLoop = columnIds->size(ctx);
	if(maxLoop > this->columns->size(ctx))
	{
		return false;
	}
	for(int i = 0; i != maxLoop; ++i)
	{
		String* key = columnIds->get(i, ctx)->getColumn(ctx);
		TableColumnMetadata* colMeta = this->columns->get(i, ctx);
		if(!key->equals(colMeta->name, ctx))
		{
			return false;
		}
	}
	return true;
}
void TableIndex::addIndexValue(DatabaseRecord* record, ThreadContext* ctx)
{
	BTreeIndexKey* indexKey = (new(ctx) BTreeIndexKey(this, record, ctx));
	TableIndexValue* positionValue = (new(ctx) TableIndexValue(record->getOid(ctx), record->getPosition(ctx), ctx));
	this->storage->gate->close(ctx);
	this->storage->putKeyValue(indexKey, positionValue, ctx);
	this->storage->gate->open(ctx);
}
void TableIndex::createIndex(AlinousDatabase* database, ThreadContext* ctx)
{
	File* file = (new(ctx) File(this->filePath, ctx));
	if(file->exists(ctx))
	{
		file->_delete(ctx);
	}
	{
		try
		{
			__GC_MV(this, &(this->storage), (new(ctx) BTree(ctx))->init(file, database->getBtreeCache(ctx), database->getCore(ctx)->diskCache, ctx), BTree);
			this->storage->initTreeStorage(32, IBTreeValue::TYPE_LONG, IBTreeValue::TYPE_LONG, (long long)capacity, (long long)64, ctx);
		}
		catch(IOException* e)
		{
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1610(), e, ctx));
		}
		catch(InterruptedException* e)
		{
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1610(), e, ctx));
		}
		catch(BTreeException* e)
		{
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1610(), e, ctx));
		}
	}
}
int TableIndex::archiveSize(ThreadContext* ctx) throw() 
{
	int total = 4 + (this->name->length(ctx) * 2);
	total += 1 + 4;
	int maxLoop = this->columns->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		TableColumnMetadata* col = this->columns->get(i, ctx);
		total += col->fileSize(ctx);
	}
	return total;
}
void TableIndex::appendToEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	builder->putString(this->name, ctx);
	char bl = ((char)(this->primary ? 1 : 0));
	builder->putByte(bl, ctx);
	int maxLoop = this->columns->size(ctx);
	builder->putInt(maxLoop, ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		TableColumnMetadata* col = this->columns->get(i, ctx);
		col->toFileEntry(builder, ctx);
	}
}
BTree* TableIndex::getStorage(ThreadContext* ctx) throw() 
{
	return storage;
}
String* TableIndex::getName(ThreadContext* ctx) throw() 
{
	return name;
}
bool TableIndex::isPrimary(ThreadContext* ctx) throw() 
{
	return primary;
}
ArrayList<TableColumnMetadata>* TableIndex::getColumns(ThreadContext* ctx) throw() 
{
	return columns;
}
void TableIndex::setPath(ThreadContext* ctx) throw() 
{
	StringBuilder* buff = (new(ctx) StringBuilder(ctx));
	buff->append(this->baseDir, ctx)->append(name, ctx)->append(ConstStr::getCNST_STR_1611(), ctx);
	__GC_MV(this, &(this->filePath), buff->toString(ctx), String);
}
TableIndex* TableIndex::valueFromFetcher(FileStorageEntryFetcher* fetcher, String* baseDir, ThreadContext* ctx) throw() 
{
	String* name = fetcher->fetchString(ctx);
	char bl = fetcher->fetchByte(ctx);
	bool primary = bl == (char)1;
	int maxLoop = fetcher->fetchInt(ctx);
	ArrayList<TableColumnMetadata>* metadata = (new(ctx) ArrayList<TableColumnMetadata>(ctx));
	for(int i = 0; i != maxLoop; ++i)
	{
		TableColumnMetadata* col = TableColumnMetadata::loadFromFetcher(fetcher, ctx);
		metadata->add(col, ctx);
	}
	TableIndex* tableindex = (new(ctx) TableIndex(name, baseDir, primary, metadata, ctx));
	return tableindex;
}
}}}

