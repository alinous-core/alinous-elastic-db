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
 ColumnsUniqueCollections::ColumnsUniqueCollections(ThreadContext* ctx) throw()  : IObject(ctx), lockStore(nullptr), lock(__GC_INS(this, (new(ctx) LockObject(ctx)), LockObject))
{
	__GC_MV(this, &(this->lockStore), (new(ctx) BTreeOnMemory(16, ctx)), IBTree);
}
void ColumnsUniqueCollections::__construct_impl(ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->lockStore), (new(ctx) BTreeOnMemory(16, ctx)), IBTree);
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
	__e_obj1.add(this->lockStore, this);
	lockStore = nullptr;
	__e_obj1.add(this->lock, this);
	lock = nullptr;
	if(!prepare){
		return;
	}
}
UniqueExclusiveLock* ColumnsUniqueCollections::getLock(ScanUnique* unique, IDatabaseRecord* value, ThreadContext* ctx)
{
	ValueCollections* key = (new(ctx) ValueCollections(value, ctx));
	{
		SynchronizedBlockObj __synchronized_2(this->lock, ctx);
		IBTreeNode* node = this->lockStore->findByKey(key, ctx);
		if(node == nullptr)
		{
			return nullptr;
		}
		ArrayList<IBTreeValue>* values = node->getValues(ctx);
		if(values->isEmpty(ctx))
		{
			return nullptr;
		}
	}
	return nullptr;
}
void ColumnsUniqueCollections::dispose(ThreadContext* ctx) throw() 
{
	{
		try
		{
			this->lockStore->close(ctx);
		}
		catch(IOException* e)
		{
		}
		catch(InterruptedException* e)
		{
		}
	}
	__GC_MV(this, &(this->lockStore), nullptr, IBTree);
}
}}}

