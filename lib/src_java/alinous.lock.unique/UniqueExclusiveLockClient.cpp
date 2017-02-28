#include "includes.h"


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
 UniqueExclusiveLockClient::UniqueExclusiveLockClient(UniqueExclusiveLockManager* mgr, ThreadContext* ctx) throw()  : IObject(ctx), mgr(nullptr)
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
	if(!prepare){
		return;
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
			throw (new(ctx) AlinousException(ConstStr::getCNST_STR_1758(), e, ctx));
		}
		catch(IOException* e)
		{
			throw (new(ctx) AlinousException(ConstStr::getCNST_STR_1758(), e, ctx));
		}
		catch(InterruptedException* e)
		{
			throw (new(ctx) AlinousException(ConstStr::getCNST_STR_1758(), e, ctx));
		}
		catch(BTreeException* e)
		{
			throw (new(ctx) AlinousException(ConstStr::getCNST_STR_1758(), e, ctx));
		}
	}
	return lock != nullptr;
}
void UniqueExclusiveLockClient::dispose(ThreadContext* ctx) throw() 
{
	this->mgr->dispose(ctx);
	__GC_MV(this, &(this->mgr), nullptr, UniqueExclusiveLockManager);
}
}}}

