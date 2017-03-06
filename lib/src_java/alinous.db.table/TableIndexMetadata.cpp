#include "include/global.h"


#include "alinous.lock/LockObject.h"
#include "alinous.lock/ConcurrentGate.h"
#include "alinous.buffer.storage/FileStorageEntry.h"
#include "alinous.buffer.storage/IFileStorage.h"
#include "alinous.buffer.storage/FileStorageEntryWriter.h"
#include "alinous.buffer.storage/FileStorageEntryReader.h"
#include "alinous.buffer.storage/FileStorage.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "java.lang/Comparable.h"
#include "alinous.btree/IBTreeKey.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.btree/IBTreeNode.h"
#include "alinous.btree/BTreeGlobalCache.h"
#include "alinous.btree/IBTree.h"
#include "alinous.btree/BTree.h"
#include "alinous.compile.sql.analyze/ScanTableIdentifier.h"
#include "alinous.btree.scan/BTreeScanner.h"
#include "alinous.compile.sql.analyze/ScanTableColumnIdentifier.h"
#include "alinous.db/AlinousDbException.h"
#include "alinous.db.table/DatabaseException.h"
#include "java.util/Locale.h"
#include "java.util/Calendar.h"
#include "java.util/GregorianCalendar.h"
#include "java.util/Date.h"
#include "alinous.numeric/InternalDate.h"
#include "java.util/TimeZone.h"
#include "java.sql/Timestamp.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.variant/VariantValue.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.db.table.lockmonitor/IThreadLocker.h"
#include "alinous.runtime.parallel/ThreadPool.h"
#include "alinous.runtime.parallel/IThreadAction.h"
#include "alinous.runtime.parallel/SequentialBackgroundJob.h"
#include "alinous.system/ISystemLog.h"
#include "alinous.system/AlinousCore.h"
#include "java.lang/Number.h"
#include "java.lang/Integer.h"
#include "alinous.db.table/TableColumnMetadata.h"
#include "alinous.db.table/DatabaseRecord.h"
#include "alinous.db.table/IScannableIndex.h"
#include "alinous.db.table/TableMetadataUnique.h"
#include "alinous.db.table/TablePartitionKey.h"
#include "alinous.compile.sql.analyze/ScanUnique.h"
#include "alinous.db.table/TableIndexMetadata.h"
#include "alinous.db.table/TablePartitionKeyCollection.h"
#include "alinous.db.table/TablePartitionRange.h"
#include "alinous.db.table/TablePartitionRangeCollection.h"
#include "alinous.db.table/TableMetadata.h"
#include "alinous.db.table/IDatabaseTable.h"
#include "alinous.db.trx.scan/ITableTargetScanner.h"
#include "alinous.db.trx/DbTransaction.h"
#include "alinous.db.table/IBtreeTableIndex.h"
#include "alinous.db.table/BTreeIndexKey.h"
#include "alinous.db.table/TableIndexValue.h"
#include "alinous.db.table/TableIndex.h"
#include "alinous.btree/LongValue.h"
#include "alinous.db.table/AbstractDatabaseTable.h"
#include "alinous.db.table/DataTableStorageSupport.h"
#include "alinous.db.table/DatatableLockSupport.h"
#include "alinous.db.table/DatatableDDLSupport.h"
#include "alinous.db.table/DatatableUpdateSupport.h"
#include "alinous.db.table/IndexInsertJob.h"
#include "alinous.db.table/OidIndexJob.h"
#include "alinous.db.table.cache/RecordCacheEngine.h"
#include "alinous.db.table.lockmonitor/DBThreadMonitor.h"
#include "alinous.db.table/DatabaseTable.h"
#include "alinous.db.table/DatatableUpdateCache.h"
#include "alinous.db.table/DatabaseTableIdPublisher.h"
#include "alinous.db.table/IOidPublisher.h"
#include "alinous.db.table/OidPublisherFactory.h"
#include "alinous.db.table/LocalOidCounter.h"
#include "alinous.db.table/LocalOidPublisher.h"
#include "alinous.db.table/DatatableConstants.h"

namespace alinous {namespace db {namespace table {





bool TableIndexMetadata::__init_done = __init_static_variables();
bool TableIndexMetadata::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"TableIndexMetadata", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 TableIndexMetadata::TableIndexMetadata(String* name, ArrayList<String>* columns, ThreadContext* ctx) throw()  : IObject(ctx), ICommandData(ctx), name(nullptr), columns(nullptr), metadata(GCUtils<ArrayList<TableColumnMetadata> >::ins(this, (new(ctx) ArrayList<TableColumnMetadata>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
	__GC_MV(this, &(this->name), name, String);
	GCUtils<ArrayList<String> >::mv(this, &(this->columns), columns, ctx);
}
void TableIndexMetadata::__construct_impl(String* name, ArrayList<String>* columns, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->name), name, String);
	GCUtils<ArrayList<String> >::mv(this, &(this->columns), columns, ctx);
}
 TableIndexMetadata::TableIndexMetadata(ThreadContext* ctx) throw()  : IObject(ctx), ICommandData(ctx), name(nullptr), columns(nullptr), metadata(GCUtils<ArrayList<TableColumnMetadata> >::ins(this, (new(ctx) ArrayList<TableColumnMetadata>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
}
void TableIndexMetadata::__construct_impl(ThreadContext* ctx) throw() 
{
}
 TableIndexMetadata::~TableIndexMetadata() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void TableIndexMetadata::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"TableIndexMetadata", L"~TableIndexMetadata");
	__e_obj1.add(this->name, this);
	name = nullptr;
	__e_obj1.add(this->columns, this);
	columns = nullptr;
	__e_obj1.add(this->metadata, this);
	metadata = nullptr;
	if(!prepare){
		return;
	}
}
void TableIndexMetadata::setupColumnMetadata(TableMetadata* meta, ThreadContext* ctx)
{
	int maxLoop = this->columns->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		String* name = this->columns->get(i, ctx);
		TableColumnMetadata* col = meta->getColumnByName(name, ctx);
		if(col == nullptr)
		{
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1695()->clone(ctx)->append(name, ctx)->append(ConstStr::getCNST_STR_1696(), ctx)->append(this->name, ctx), ctx));
		}
		this->metadata->add(col, ctx);
	}
}
void TableIndexMetadata::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	if(this->columns == nullptr)
	{
		GCUtils<ArrayList<String> >::mv(this, &(this->columns), (new(ctx) ArrayList<String>(ctx)), ctx);
	}
	__GC_MV(this, &(this->name), buff->getString(ctx), String);
	int maxLoop = buff->getInt(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		String* col = buff->getString(ctx);
		this->columns->add(col, ctx);
	}
}
void TableIndexMetadata::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	buff->putString(this->name, ctx);
	int maxLoop = this->columns->size(ctx);
	buff->putInt(maxLoop, ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		String* col = this->columns->get(i, ctx);
		buff->putString(col, ctx);
	}
}
int TableIndexMetadata::fileSize(ThreadContext* ctx) throw() 
{
	int total = this->name->length(ctx) * 2 + 4;
	int maxLoop = this->columns->size(ctx);
	total += 4;
	for(int i = 0; i != maxLoop; ++i)
	{
		String* col = this->columns->get(i, ctx);
		total += col->length(ctx) * 2 + 4;
	}
	return total;
}
void TableIndexMetadata::toFileEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx) throw() 
{
	builder->putString(this->name, ctx);
	int maxLoop = this->columns->size(ctx);
	builder->putInt(maxLoop, ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		String* col = this->columns->get(i, ctx);
		builder->putString(col, ctx);
	}
}
String* TableIndexMetadata::getName(ThreadContext* ctx) throw() 
{
	return name;
}
void TableIndexMetadata::setName(String* name, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->name), name, String);
}
ArrayList<String>* TableIndexMetadata::getColumns(ThreadContext* ctx) throw() 
{
	return columns;
}
void TableIndexMetadata::setColumns(ArrayList<String>* columns, ThreadContext* ctx) throw() 
{
	GCUtils<ArrayList<String> >::mv(this, &(this->columns), columns, ctx);
}
ArrayList<TableColumnMetadata>* TableIndexMetadata::getMetadata(ThreadContext* ctx) throw() 
{
	return metadata;
}
bool TableIndexMetadata::hasColumn(String* name, ThreadContext* ctx) throw() 
{
	int maxLoop = this->columns->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		String* colname = this->columns->get(i, ctx);
		if(!colname->equals(name, ctx))
		{
			return false;
		}
	}
	return true;
}
TableIndexMetadata* TableIndexMetadata::fromNetwork(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	TableIndexMetadata* meta = (new(ctx) TableIndexMetadata(ctx));
	meta->readData(buff, ctx);
	return meta;
}
TableIndexMetadata* TableIndexMetadata::loadFromFetcher(FileStorageEntryFetcher* fetcher, ThreadContext* ctx) throw() 
{
	String* name = fetcher->fetchString(ctx);
	ArrayList<String>* list = (new(ctx) ArrayList<String>(ctx));
	int maxLoop = fetcher->fetchInt(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		String* col = fetcher->fetchString(ctx);
		list->add(col, ctx);
	}
	TableIndexMetadata* meta = (new(ctx) TableIndexMetadata(name, list, ctx));
	return meta;
}
void TableIndexMetadata::__cleanUp(ThreadContext* ctx){
}
}}}

