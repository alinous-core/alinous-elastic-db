#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.lock/LockObject.h"
#include "alinous.lock/ConcurrentGate.h"
#include "alinous.buffer.storage/IFileStorage.h"
#include "alinous.buffer.storage/FileStorage.h"
#include "alinous.btree/BTreeGlobalCache.h"
#include "alinous.system/AlinousCore.h"
#include "java.lang/Number.h"
#include "java.lang/Comparable.h"
#include "java.lang/Integer.h"
#include "alinous.btree/IBTree.h"
#include "alinous.btree/BTree.h"
#include "alinous.db.table/IScannableIndex.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.db.table/TableMetadata.h"
#include "alinous.db.table/IDatabaseTable.h"
#include "alinous.db.table/DatabaseRecord.h"
#include "alinous.numeric/InternalDate.h"
#include "java.sql/Timestamp.h"
#include "alinous.db.table/DatabaseTableIdPublisher.h"
#include "alinous.db.table/IBtreeTableIndex.h"
#include "alinous.db.table/TableIndex.h"
#include "alinous.db.table/DatatableUpdateCache.h"
#include "alinous.db.table/AbstractDatabaseTable.h"
#include "alinous.db.table/DataTableStorageSupport.h"
#include "alinous.db.table.cache/DbRecordHashArray.h"

namespace alinous {namespace db {namespace table {namespace cache {





bool DbRecordHashArray::__init_done = __init_static_variables();
bool DbRecordHashArray::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DbRecordHashArray", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 DbRecordHashArray::DbRecordHashArray(int i, ThreadContext* ctx) throw()  : IObject(ctx), list(nullptr)
{
	GCUtils<ArrayList<DatabaseRecord> >::mv(this, &(this->list), (new(ctx) ArrayList<DatabaseRecord>(i, ctx)), ctx);
}
void DbRecordHashArray::__construct_impl(int i, ThreadContext* ctx) throw() 
{
	GCUtils<ArrayList<DatabaseRecord> >::mv(this, &(this->list), (new(ctx) ArrayList<DatabaseRecord>(i, ctx)), ctx);
}
 DbRecordHashArray::~DbRecordHashArray() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void DbRecordHashArray::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"DbRecordHashArray", L"~DbRecordHashArray");
	__e_obj1.add(this->list, this);
	list = nullptr;
	if(!prepare){
		return;
	}
}
void DbRecordHashArray::add(DatabaseRecord* ptr, ThreadContext* ctx) throw() 
{
	list->add(ptr, ctx);
}
bool DbRecordHashArray::removeByObj(DatabaseRecord* obj, ThreadContext* ctx) throw() 
{
	bool ret = list->remove(obj, ctx);
	return ret;
}
int DbRecordHashArray::size(ThreadContext* ctx) throw() 
{
	return list->size(ctx);
}
DatabaseRecord* DbRecordHashArray::search(DataTableStorageSupport* table, long long position, ThreadContext* ctx) throw() 
{
	int maxLoop = list->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		DatabaseRecord* n = list->get(i, ctx);
		if(n->getStorageForCache(ctx) == table && n->getPosition(ctx) == position)
		{
			return n;
		}
	}
	return nullptr;
}
void DbRecordHashArray::reset(ThreadContext* ctx) throw() 
{
	list->clear(ctx);
}
DatabaseRecord* DbRecordHashArray::get(int i, ThreadContext* ctx) throw() 
{
	return list->get(i, ctx);
}
void DbRecordHashArray::__cleanUp(ThreadContext* ctx){
}
}}}}

