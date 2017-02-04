#include "includes.h"


namespace alinous {namespace remote {namespace region {





bool RegionInsertExecutorPool::__init_done = __init_static_variables();
bool RegionInsertExecutorPool::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"RegionInsertExecutorPool", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 RegionInsertExecutorPool::~RegionInsertExecutorPool() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void RegionInsertExecutorPool::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"RegionInsertExecutorPool", L"~RegionInsertExecutorPool");
	__e_obj1.add(this->sessions, this);
	sessions = nullptr;
	__e_obj1.add(this->lock, this);
	lock = nullptr;
	if(!prepare){
		return;
	}
}
void RegionInsertExecutorPool::putSession(RegionInsertExecutor* exec, ThreadContext* ctx) throw() 
{
	{
		SynchronizedBlockObj __synchronized_2(this->lock, ctx);
		this->sessions->put(exec->getTrxId(ctx), exec, ctx);
	}
}
RegionInsertExecutor* RegionInsertExecutorPool::getSession(long long trxId, ThreadContext* ctx) throw() 
{
	{
		SynchronizedBlockObj __synchronized_2(this->lock, ctx);
		Long* key = (new(ctx) Long(trxId, ctx));
		return this->sessions->get(key, ctx);
	}
}
void RegionInsertExecutorPool::removeSession(long long trxId, ThreadContext* ctx) throw() 
{
	{
		SynchronizedBlockObj __synchronized_2(this->lock, ctx);
		Long* key = (new(ctx) Long(trxId, ctx));
		RegionInsertExecutor* exec = this->sessions->get(key, ctx);
		if(exec == nullptr)
		{
			return;
		}
		exec->dispose(ctx);
		this->sessions->remove(key, ctx);
	}
}
}}}

