#include "include/global.h"


#include "alinous.btree/BTreeException.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.db/AlinousDbException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.db.table/TableColumnMetadata.h"
#include "alinous.db.table/TableMetadataUnique.h"
#include "alinous.compile.sql.analyze/ScanUnique.h"
#include "alinous.lock/LockObject.h"
#include "alinous.lock.unique/UniqueExclusiveLock.h"
#include "alinous.lock.unique/UniqueExclusiveException.h"
#include "alinous.lock.unique/ColumnsUniqueCollections.h"

namespace alinous {namespace lock {namespace unique {





bool ColumnsUniqueCollections::__init_done = __init_static_variables();
bool ColumnsUniqueCollections::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ColumnsUniqueCollections", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ColumnsUniqueCollections::ColumnsUniqueCollections(ThreadContext* ctx) throw()  : IObject(ctx), lock(__GC_INS(this, (new(ctx) LockObject(ctx)), LockObject)), locks(GCUtils<Map<String,UniqueExclusiveLock> >::ins(this, (new(ctx) HashMap<String,UniqueExclusiveLock>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
}
void ColumnsUniqueCollections::__construct_impl(ThreadContext* ctx) throw() 
{
}
 ColumnsUniqueCollections::~ColumnsUniqueCollections() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ColumnsUniqueCollections::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ColumnsUniqueCollections", L"~ColumnsUniqueCollections");
	__e_obj1.add(this->lock, this);
	lock = nullptr;
	__e_obj1.add(this->locks, this);
	locks = nullptr;
	if(!prepare){
		return;
	}
}
UniqueExclusiveLock* ColumnsUniqueCollections::lockWithCheck(ScanUnique* unique, String* lockString, bool throwex, ThreadContext* ctx)
{
	UniqueExclusiveLock* lock = nullptr;
	{
		SynchronizedBlockObj __synchronized_2(this->lock, ctx);
		lock = this->locks->get(lockString, ctx);
		if(lock != nullptr)
		{
			if(throwex)
			{
				throw (new(ctx) UniqueExclusiveException(lockString->clone(ctx)->append(ConstStr::getCNST_STR_1764(), ctx), ctx));
			}
			{
				try
				{
					lock->lock(ctx);
				}
				catch(InterruptedException* e)
				{
					throw (new(ctx) UniqueExclusiveException(ConstStr::getCNST_STR_1765(), e, ctx));
				}
			}
			return lock;
		}
		lock = (new(ctx) UniqueExclusiveLock(unique, lockString, ctx));
		this->locks->put(lockString, lock, ctx);
		{
			try
			{
				lock->lock(ctx);
			}
			catch(InterruptedException* e)
			{
				throw (new(ctx) UniqueExclusiveException(ConstStr::getCNST_STR_1765(), e, ctx));
			}
		}
	}
	return lock;
}
bool ColumnsUniqueCollections::unlock(ScanUnique* unique, String* lockString, ThreadContext* ctx) throw() 
{
	UniqueExclusiveLock* lock = nullptr;
	{
		SynchronizedBlockObj __synchronized_2(this->lock, ctx);
		lock = this->locks->get(lockString, ctx);
		if(lock == nullptr)
		{
			return this->locks->isEmpty(ctx);
		}
		lock->unlock(ctx);
		if(lock->getCount(ctx) == 0)
		{
			this->locks->remove(lockString, ctx);
			return this->locks->isEmpty(ctx);
		}
	}
	return false;
}
UniqueExclusiveLock* ColumnsUniqueCollections::getLock(ScanUnique* unique, String* lockString, ThreadContext* ctx)
{
	UniqueExclusiveLock* lock = nullptr;
	{
		SynchronizedBlockObj __synchronized_2(this->lock, ctx);
		lock = this->locks->get(lockString, ctx);
	}
	return lock;
}
void ColumnsUniqueCollections::dispose(ThreadContext* ctx) throw() 
{
}
void ColumnsUniqueCollections::__cleanUp(ThreadContext* ctx){
}
}}}

