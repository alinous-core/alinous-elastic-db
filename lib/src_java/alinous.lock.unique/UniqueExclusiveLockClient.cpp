#include "include/global.h"


#include "alinous.btree/BTreeException.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.db.table/TableColumnMetadata.h"
#include "alinous.db.table/TableMetadataUnique.h"
#include "alinous.compile.sql.analyze/ScanUnique.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.lock/LockObject.h"
#include "alinous.lock.unique/UniqueExclusiveLock.h"
#include "alinous.lock.unique/UniqueExclusiveLockManager.h"
#include "alinous.lock.unique/UniqueExclusiveLockClient.h"

namespace alinous {namespace lock {namespace unique {





bool UniqueExclusiveLockClient::__init_done = __init_static_variables();
bool UniqueExclusiveLockClient::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"UniqueExclusiveLockClient", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 UniqueExclusiveLockClient::UniqueExclusiveLockClient(UniqueExclusiveLockManager* mgr, ThreadContext* ctx) throw()  : IObject(ctx), mgr(nullptr), lock(__GC_INS(this, (new(ctx) LockObject(ctx)), LockObject)), uniqueLocks(GCUtils<Map<String,UniqueExclusiveLock> >::ins(this, (new(ctx) HashMap<String,UniqueExclusiveLock>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
	__GC_MV(this, &(this->mgr), mgr, UniqueExclusiveLockManager);
}
void UniqueExclusiveLockClient::__construct_impl(UniqueExclusiveLockManager* mgr, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->mgr), mgr, UniqueExclusiveLockManager);
}
 UniqueExclusiveLockClient::~UniqueExclusiveLockClient() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void UniqueExclusiveLockClient::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"UniqueExclusiveLockClient", L"~UniqueExclusiveLockClient");
	__e_obj1.add(this->mgr, this);
	mgr = nullptr;
	__e_obj1.add(this->lock, this);
	lock = nullptr;
	__e_obj1.add(this->uniqueLocks, this);
	uniqueLocks = nullptr;
	if(!prepare){
		return;
	}
}
void UniqueExclusiveLockClient::lockWithCheck(ScanUnique* unique, IDatabaseRecord* record, bool throwex, ThreadContext* ctx)
{
	String* lockKey = UniqueExclusiveLock::makeString(unique, record, ctx);
	UniqueExclusiveLock* lock = nullptr;
	{
		SynchronizedBlockObj __synchronized_2(this->lock, ctx);
		lock = this->uniqueLocks->get(lockKey, ctx);
		if(lock != nullptr)
		{
			return;
		}
	}
	lock = this->mgr->lockWithCheck(unique, record, throwex, ctx);
	{
		SynchronizedBlockObj __synchronized_2(this->lock, ctx);
		this->uniqueLocks->put(lockKey, lock, ctx);
	}
}
bool UniqueExclusiveLockClient::checkLocking(ScanUnique* unique, IDatabaseRecord* value, ThreadContext* ctx)
{
	UniqueExclusiveLock* lock = nullptr;
	{
		try
		{
			lock = this->mgr->findLock(unique, value, ctx);
		}
		catch(VariableException* e)
		{
			throw (new(ctx) AlinousException(ConstStr::getCNST_STR_1761(), e, ctx));
		}
		catch(IOException* e)
		{
			throw (new(ctx) AlinousException(ConstStr::getCNST_STR_1761(), e, ctx));
		}
		catch(InterruptedException* e)
		{
			throw (new(ctx) AlinousException(ConstStr::getCNST_STR_1761(), e, ctx));
		}
		catch(BTreeException* e)
		{
			throw (new(ctx) AlinousException(ConstStr::getCNST_STR_1761(), e, ctx));
		}
	}
	return lock != nullptr;
}
void UniqueExclusiveLockClient::reset(ThreadContext* ctx) throw() 
{
	{
		SynchronizedBlockObj __synchronized_2(this->lock, ctx);
		Iterator<String>* it = this->uniqueLocks->keySet(ctx)->iterator(ctx);
		while(it->hasNext(ctx))
		{
			String* key = it->next(ctx);
			UniqueExclusiveLock* lock = this->uniqueLocks->get(key, ctx);
			this->mgr->unlock(lock, ctx);
		}
		this->uniqueLocks->clear(ctx);
	}
}
void UniqueExclusiveLockClient::dispose(ThreadContext* ctx) throw() 
{
	reset(ctx);
	this->mgr->dispose(ctx);
	__GC_MV(this, &(this->mgr), nullptr, UniqueExclusiveLockManager);
}
void UniqueExclusiveLockClient::__cleanUp(ThreadContext* ctx){
}
}}}

