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
UniqueExclusiveLock* ColumnsUniqueCollections::lockWithCheck(ScanUnique* unique, IDatabaseRecord* value, ThreadContext* ctx)
{
	String* lockString = getLockValueString(unique, value, ctx);
	UniqueExclusiveLock* lock = nullptr;
	{
		SynchronizedBlockObj __synchronized_2(this->lock, ctx);
		lock = this->locks->get(lockString, ctx);
		if(lock != nullptr)
		{
			throw (new(ctx) UniqueExclusiveException(lockString->clone(ctx)->append(ConstStr::getCNST_STR_1757(), ctx), ctx));
		}
		lock = (new(ctx) UniqueExclusiveLock(ctx));
		this->locks->put(lockString, lock, ctx);
	}
	return lock;
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
		if(i != maxLoop)
		{
			buff->append(ConstStr::getCNST_STR_888(), ctx);
		}
		String* str = vv->toString(ctx);
		buff->append(str, ctx);
	}
	return buff->toString(ctx);
}
}}}

