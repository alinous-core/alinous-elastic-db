#include "includes.h"


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
UniqueExclusiveLock* ColumnsUniqueCollections::lockWithCheck(ScanUnique* unique, IDatabaseRecord* record, bool throwex, ThreadContext* ctx)
{
	String* lockString = getLockValueString(unique, record, ctx);
	UniqueExclusiveLock* lock = nullptr;
	{
		SynchronizedBlockObj __synchronized_2(this->lock, ctx);
		lock = this->locks->get(lockString, ctx);
		if(lock != nullptr)
		{
			if(throwex)
			{
				throw (new(ctx) UniqueExclusiveException(lockString->clone(ctx)->append(ConstStr::getCNST_STR_1757(), ctx), ctx));
			}
			{
				try
				{
					lock->lock(ctx);
				}
				catch(InterruptedException* e)
				{
					throw (new(ctx) UniqueExclusiveException(ConstStr::getCNST_STR_1758(), e, ctx));
				}
			}
			return lock;
		}
		lock = (new(ctx) UniqueExclusiveLock(unique, record, ctx));
		this->locks->put(lockString, lock, ctx);
		{
			try
			{
				lock->lock(ctx);
			}
			catch(InterruptedException* e)
			{
				throw (new(ctx) UniqueExclusiveException(ConstStr::getCNST_STR_1758(), e, ctx));
			}
		}
	}
	return lock;
}
bool ColumnsUniqueCollections::unlock(ScanUnique* unique, IDatabaseRecord* record, ThreadContext* ctx) throw() 
{
	String* lockString = getLockValueString(unique, record, ctx);
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
UniqueExclusiveLock* ColumnsUniqueCollections::getLock(ScanUnique* unique, IDatabaseRecord* value, ThreadContext* ctx)
{
	String* lockString = getLockValueString(unique, value, ctx);
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
String* ColumnsUniqueCollections::getLockValueString(ScanUnique* unique, IDatabaseRecord* value, ThreadContext* ctx) throw() 
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	ArrayList<TableColumnMetadata>* colslist = unique->getUniqueColList(ctx);
	int maxLoop = colslist->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		TableColumnMetadata* col = colslist->get(i, ctx);
		VariantValue* vv = value->getColumnValue(col->columnOrder, ctx);
		if(i != 0)
		{
			buff->append(ConstStr::getCNST_STR_888(), ctx);
		}
		String* str = vv->toString(ctx);
		buff->append(str, ctx);
	}
	return buff->toString(ctx);
}
}}}

