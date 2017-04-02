#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.lock/LockObject.h"
#include "alinous.lock/ConcurrentGate.h"
#include "alinous.buffer.storage/IFileStorage.h"
#include "alinous.buffer.storage/FileStorage.h"
#include "alinous.db.table/IDatabaseRecord.h"
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
#include "alinous.db.table.cache/RecordCacheEngine.h"
#include "alinous.numeric/InternalDate.h"
#include "java.sql/Timestamp.h"
#include "alinous.db.table/DatabaseTableIdPublisher.h"
#include "alinous.db.table/IBtreeTableIndex.h"
#include "alinous.db.table/TableIndex.h"
#include "alinous.db.table/DatatableUpdateCache.h"
#include "alinous.db.table/AbstractDatabaseTable.h"
#include "alinous.db.table/DataTableStorageSupport.h"
#include "alinous.db.table/DatatableLockSupport.h"

namespace alinous {namespace db {namespace table {





bool DatatableLockSupport::__init_done = __init_static_variables();
bool DatatableLockSupport::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DatatableLockSupport", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 DatatableLockSupport::DatatableLockSupport(String* schema, String* name, String* baseDir, ThreadContext* ctx) throw()  : IObject(ctx), DataTableStorageSupport(schema, name, baseDir, ctx)
{
}
void DatatableLockSupport::__construct_impl(String* schema, String* name, String* baseDir, ThreadContext* ctx) throw() 
{
}
 DatatableLockSupport::~DatatableLockSupport() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void DatatableLockSupport::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	DataTableStorageSupport::__releaseRegerences(true, ctx);
}
void DatatableLockSupport::lockStorage(ThreadContext* ctx)
{
	this->storageLock->close(ctx);
}
void DatatableLockSupport::unlockStorage(ThreadContext* ctx)
{
	this->storageLock->open(ctx);
}
void DatatableLockSupport::sharelockStorage(ThreadContext* ctx)
{
	this->storageLock->enter(ctx);
}
void DatatableLockSupport::shareunlockStorage(ThreadContext* ctx) throw() 
{
	this->storageLock->exit(ctx);
}
void DatatableLockSupport::__cleanUp(ThreadContext* ctx){
}
}}}

