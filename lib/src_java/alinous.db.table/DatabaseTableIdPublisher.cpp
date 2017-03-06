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





DatabaseTableIdPublisher* DatabaseTableIdPublisher::instance = nullptr;
bool DatabaseTableIdPublisher::__init_done = __init_static_variables();
bool DatabaseTableIdPublisher::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DatabaseTableIdPublisher", L"__init_static_variables");
		__GC_MV(nullptr, &(instance), nullptr, DatabaseTableIdPublisher);
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 DatabaseTableIdPublisher::DatabaseTableIdPublisher(ThreadContext* ctx) throw()  : IObject(ctx), tableIdSerial(0), ids(GCUtils<HashMap<String,Integer> >::ins(this, (new(ctx) HashMap<String,Integer>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
	this->tableIdSerial = 1;
}
void DatabaseTableIdPublisher::__construct_impl(ThreadContext* ctx) throw() 
{
	this->tableIdSerial = 1;
}
 DatabaseTableIdPublisher::~DatabaseTableIdPublisher() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void DatabaseTableIdPublisher::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"DatabaseTableIdPublisher", L"~DatabaseTableIdPublisher");
	__e_obj1.add(this->ids, this);
	ids = nullptr;
	if(!prepare){
		return;
	}
}
int DatabaseTableIdPublisher::getId(String* name, ThreadContext* ctx) throw() 
{
	if(instance == nullptr)
	{
		__GC_MV(nullptr, &(instance), (new(ctx) DatabaseTableIdPublisher(ctx)), DatabaseTableIdPublisher);
	}
	Integer* id = instance->ids->get(name, ctx);
	if(id != nullptr)
	{
		return id->intValue(ctx);
	}
	int ret = instance->tableIdSerial;
	instance->tableIdSerial ++ ;
	instance->ids->put(name, (new(ctx) Integer(ret, ctx)), ctx);
	return ret;
}
String* DatabaseTableIdPublisher::idToName(int id, ThreadContext* ctx) throw() 
{
	if(instance == nullptr)
	{
		__GC_MV(nullptr, &(instance), (new(ctx) DatabaseTableIdPublisher(ctx)), DatabaseTableIdPublisher);
	}
	Iterator<String>* it = instance->ids->keySet(ctx)->iterator(ctx);
	while(it->hasNext(ctx))
	{
		String* key = it->next(ctx);
		Integer* value = instance->ids->get(key, ctx);
		if(value->intValue(ctx) == id)
		{
			return key;
		}
	}
	return nullptr;
}
void DatabaseTableIdPublisher::__cleanUp(ThreadContext* ctx){
	GCUtils<DatabaseTableIdPublisher>::dec(nullptr, DatabaseTableIdPublisher::instance, ctx, __FILEW__, __LINE__, L"DatabaseTableIdPublisher");
}
}}}

