#include "include/global.h"


#include "java.util/BitSet.h"
#include "alinous.lock/ConcurrentGate.h"
#include "alinous.buffer.storage/FileStorageEntry.h"
#include "alinous.buffer.storage/IFileStorage.h"
#include "alinous.buffer.storage/FileStorageEntryWriter.h"
#include "alinous.buffer.storage/FileStorageEntryReader.h"
#include "alinous.buffer.storage/FileStorage.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "java.lang/Comparable.h"
#include "alinous.btree/IBTreeKey.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.btree/IBTreeNode.h"
#include "alinous.btree/LongValue.h"
#include "alinous.db/AlinousDbException.h"
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
#include "alinous.btree/BTreeGlobalCache.h"
#include "alinous.runtime.parallel/ThreadPool.h"
#include "alinous.runtime.parallel/IThreadAction.h"
#include "alinous.runtime.parallel/SequentialBackgroundJob.h"
#include "alinous.system/ISystemLog.h"
#include "alinous.system/AlinousCore.h"
#include "java.lang/Number.h"
#include "java.lang/Integer.h"
#include "alinous.btree/IBTree.h"
#include "alinous.btree/BTree.h"
#include "alinous.db.table/IScannableIndex.h"
#include "alinous.db.table/TableIndexMetadata.h"
#include "alinous.db.table/TableMetadata.h"
#include "alinous.db.table/IDatabaseTable.h"
#include "alinous.db.table/DatabaseRecord.h"
#include "alinous.btree.scan/BTreeScanner.h"
#include "alinous.db.table/IBtreeTableIndex.h"
#include "alinous.db.table/BTreeIndexKey.h"
#include "alinous.db.table/TableIndex.h"
#include "alinous.db.table/DatabaseException.h"
#include "alinous.db.table/AbstractDatabaseTable.h"
#include "alinous.db.table/DatatableUpdateCache.h"
#include "alinous.db.table/DataTableStorageSupport.h"
#include "alinous.db.table/DatatableLockSupport.h"
#include "alinous.db.table/DatatableDDLSupport.h"
#include "alinous.db.table/DatatableUpdateSupport.h"
#include "alinous.db.table.cache/DbRecordCache.h"
#include "alinous.db.table.cache/RecordCacheEngine.h"
#include "alinous.db.table.cache/DbRecordHashArray.h"
#include "alinous.db.table.cache/DbREcordHashListIterator.h"
#include "alinous.db.table.cache/DbRecordHashMainList.h"

namespace alinous {namespace db {namespace table {namespace cache {





bool DbREcordHashListIterator::__init_done = __init_static_variables();
bool DbREcordHashListIterator::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DbREcordHashListIterator", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 DbREcordHashListIterator::DbREcordHashListIterator(IArrayObject<DbRecordHashArray>* arrays, BitSet* bitset, long long MAX_HASH, ThreadContext* ctx) throw()  : IObject(ctx), MAX_HASH(0), hashCode(0), index(0), arrays(nullptr), bitset(nullptr)
{
	this->MAX_HASH = MAX_HASH;
	this->hashCode = 0;
	this->index = 0;
	__GC_MV(this, &(this->arrays), arrays, IArrayObject<DbRecordHashArray>);
	__GC_MV(this, &(this->bitset), bitset, BitSet);
}
void DbREcordHashListIterator::__construct_impl(IArrayObject<DbRecordHashArray>* arrays, BitSet* bitset, long long MAX_HASH, ThreadContext* ctx) throw() 
{
	this->MAX_HASH = MAX_HASH;
	this->hashCode = 0;
	this->index = 0;
	__GC_MV(this, &(this->arrays), arrays, IArrayObject<DbRecordHashArray>);
	__GC_MV(this, &(this->bitset), bitset, BitSet);
}
 DbREcordHashListIterator::~DbREcordHashListIterator() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void DbREcordHashListIterator::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"DbREcordHashListIterator", L"~DbREcordHashListIterator");
	__e_obj1.add(this->arrays, this);
	arrays = nullptr;
	__e_obj1.add(this->bitset, this);
	bitset = nullptr;
	if(!prepare){
		return;
	}
}
bool DbREcordHashListIterator::hasNext(ThreadContext* ctx) throw() 
{
	DbRecordHashArray* current = arrays->get(hashCode);
	if(current->size(ctx) == index)
	{
		int nextHash = hashCode + 1;
		if(nextHash == (int)MAX_HASH)
		{
			return false;
		}
		int next = bitset->nextSetBit(nextHash, ctx);
		if(next < 0)
		{
			return false;
		}
		return true;
	}
	return true;
}
DatabaseRecord* DbREcordHashListIterator::next(ThreadContext* ctx) throw() 
{
	DbRecordHashArray* current = arrays->get(hashCode);
	if(current->size(ctx) == index)
	{
		int nextHash = hashCode + 1;
		int next = bitset->nextSetBit(nextHash, ctx);
		if(nextHash == (int)MAX_HASH || next < 0)
		{
			return nullptr;
		}
		index = 0;
		hashCode = next;
	}
	current = arrays->get(hashCode);
	return current->get(index++, ctx);
}
void DbREcordHashListIterator::__cleanUp(ThreadContext* ctx){
}
}}}}

