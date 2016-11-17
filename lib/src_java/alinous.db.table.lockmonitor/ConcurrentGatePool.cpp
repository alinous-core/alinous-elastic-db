#include "includes.h"


namespace alinous {namespace db {namespace table {namespace lockmonitor {





bool ConcurrentGatePool::__init_done = __init_static_variables();
bool ConcurrentGatePool::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ConcurrentGatePool", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ConcurrentGatePool::ConcurrentGatePool(int maxPool, ThreadContext* ctx) throw()  : IObject(ctx), ThreadMonitor(ctx), stack(GCUtils<Stack<ConcurrentGate> >::ins(this, (new(ctx) Stack<ConcurrentGate>(ctx)), ctx, __FILEW__, __LINE__, L"")), maxPool(0), mutex(nullptr)
{
	this->maxPool = maxPool;
	__GC_MV(this, &(this->mutex), (new(ctx) SpinMutex(ctx)), SpinMutex);
	for(int i = 0; i != maxPool; ++i)
	{
		ConcurrentGate* gate = (new(ctx) ConcurrentGate(ctx));
		this->stack->push(gate, ctx);
	}
}
void ConcurrentGatePool::__construct_impl(int maxPool, ThreadContext* ctx) throw() 
{
	this->maxPool = maxPool;
	__GC_MV(this, &(this->mutex), (new(ctx) SpinMutex(ctx)), SpinMutex);
	for(int i = 0; i != maxPool; ++i)
	{
		ConcurrentGate* gate = (new(ctx) ConcurrentGate(ctx));
		this->stack->push(gate, ctx);
	}
}
 ConcurrentGatePool::~ConcurrentGatePool() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ConcurrentGatePool::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ConcurrentGatePool", L"~ConcurrentGatePool");
	__e_obj1.add(this->stack, this);
	stack = nullptr;
	__e_obj1.add(this->mutex, this);
	mutex = nullptr;
	if(!prepare){
		return;
	}
}
ConcurrentGate* ConcurrentGatePool::borrow(ThreadContext* ctx) throw() 
{
	ConcurrentGate* gate = 0;
	this->mutex->lock(ctx);
	if(this->stack->isEmpty(ctx))
	{
		int ext = this->maxPool / 10;
		for(int i = 0; i != ext; ++i)
		{
			gate = (new(ctx) ConcurrentGate(ctx));
			this->stack->push(gate, ctx);
		}
	}
	gate = this->stack->pop(ctx);
	this->mutex->unlock(ctx);
	return gate;
}
void ConcurrentGatePool::pushBack(ConcurrentGate* gate, ThreadContext* ctx) throw() 
{
	this->mutex->lock(ctx);
	this->stack->push(gate, ctx);
	this->mutex->unlock(ctx);
}
}}}}

