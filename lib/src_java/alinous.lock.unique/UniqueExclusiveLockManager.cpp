#include "include/global.h"


#include "alinous.btree/BTreeException.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.db.table/TableColumnMetadata.h"
#include "alinous.db.table/TableMetadataUnique.h"
#include "alinous.compile.sql.analyze/ScanUnique.h"
#include "alinous.lock/LockObject.h"
#include "alinous.lock.unique/UniqueExclusiveLock.h"
#include "alinous.lock.unique/TableUniqueCollections.h"
#include "alinous.lock.unique/UniqueExclusiveLockManager.h"

namespace alinous {namespace lock {namespace unique {





bool UniqueExclusiveLockManager::__init_done = __init_static_variables();
bool UniqueExclusiveLockManager::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"UniqueExclusiveLockManager", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 UniqueExclusiveLockManager::UniqueExclusiveLockManager(ThreadContext* ctx) throw()  : IObject(ctx), tables(GCUtils<Map<String,TableUniqueCollections> >::ins(this, (new(ctx) HashMap<String,TableUniqueCollections>(ctx)), ctx, __FILEW__, __LINE__, L"")), lock(__GC_INS(this, (new(ctx) LockObject(ctx)), LockObject))
{
}
void UniqueExclusiveLockManager::__construct_impl(ThreadContext* ctx) throw() 
{
}
 UniqueExclusiveLockManager::~UniqueExclusiveLockManager() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void UniqueExclusiveLockManager::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"UniqueExclusiveLockManager", L"~UniqueExclusiveLockManager");
	__e_obj1.add(this->tables, this);
	tables = nullptr;
	__e_obj1.add(this->lock, this);
	lock = nullptr;
	if(!prepare){
		return;
	}
}
UniqueExclusiveLock* UniqueExclusiveLockManager::lockWithCheck(ScanUnique* unique, IDatabaseRecord* record, bool throwex, ThreadContext* ctx)
{
	TableUniqueCollections* tableUnique = nullptr;
	{
		SynchronizedBlockObj __synchronized_2(this->lock, ctx);
		String* fullName = unique->getTableFullName(ctx);
		tableUnique = getTableUnique(fullName, ctx);
		if(tableUnique == nullptr)
		{
			tableUnique = (new(ctx) TableUniqueCollections(ctx));
			this->tables->put(fullName, tableUnique, ctx);
		}
	}
	return tableUnique->lockWithCheck(unique, record, throwex, ctx);
}
void UniqueExclusiveLockManager::unlock(UniqueExclusiveLock* lock, ThreadContext* ctx) throw() 
{
	ScanUnique* unique = lock->getUnique(ctx);
	IDatabaseRecord* record = lock->getRecord(ctx);
	TableUniqueCollections* tableUnique = nullptr;
	{
		SynchronizedBlockObj __synchronized_2(this->lock, ctx);
		String* fullName = unique->getTableFullName(ctx);
		tableUnique = getTableUnique(fullName, ctx);
		bool isEmpty = tableUnique->unlock(unique, record, ctx);
		if(isEmpty)
		{
			this->tables->remove(fullName, ctx);
		}
	}
}
UniqueExclusiveLock* UniqueExclusiveLockManager::findLock(ScanUnique* unique, IDatabaseRecord* value, ThreadContext* ctx)
{
	TableUniqueCollections* tableUnique = getTableUnique(unique->getTableFullName(ctx), ctx);
	if(tableUnique == nullptr)
	{
		return nullptr;
	}
	return tableUnique->findLock(unique, value, ctx);
}
void UniqueExclusiveLockManager::dispose(ThreadContext* ctx) throw() 
{
	Iterator<String>* it = this->tables->keySet(ctx)->iterator(ctx);
	while(it->hasNext(ctx))
	{
		String* tableName = it->next(ctx);
		TableUniqueCollections* tableLock = this->tables->get(tableName, ctx);
		tableLock->dispose(ctx);
	}
	this->tables->clear(ctx);
}
TableUniqueCollections* UniqueExclusiveLockManager::getTableUnique(String* fullName, ThreadContext* ctx) throw() 
{
	return this->tables->get(fullName, ctx);
}
void UniqueExclusiveLockManager::__cleanUp(ThreadContext* ctx){
}
}}}

