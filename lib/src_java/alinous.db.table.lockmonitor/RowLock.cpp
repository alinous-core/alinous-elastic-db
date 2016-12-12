#include "includes.h"


namespace alinous {namespace db {namespace table {namespace lockmonitor {





bool RowLock::__init_done = __init_static_variables();
bool RowLock::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"RowLock", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 RowLock::RowLock(IDatabaseTable* table, long long oid, bool update, IThreadLocker* locker, ConcurrentGate* gate, ThreadContext* ctx) throw()  : IObject(ctx), IDatabaseLock(ctx), update(0), table(nullptr), oid(0), locker(nullptr), gate(nullptr), count(0), pushBack(0)
{
	__GC_MV(this, &(this->table), table, IDatabaseTable);
	this->oid = oid;
	this->update = update;
	__GC_MV(this, &(this->locker), locker, IThreadLocker);
	__GC_MV(this, &(this->gate), gate, ConcurrentGate);
	this->pushBack = false;
}
void RowLock::__construct_impl(IDatabaseTable* table, long long oid, bool update, IThreadLocker* locker, ConcurrentGate* gate, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->table), table, IDatabaseTable);
	this->oid = oid;
	this->update = update;
	__GC_MV(this, &(this->locker), locker, IThreadLocker);
	__GC_MV(this, &(this->gate), gate, ConcurrentGate);
	this->pushBack = false;
}
 RowLock::~RowLock() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void RowLock::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"RowLock", L"~RowLock");
	__e_obj1.add(this->table, this);
	table = nullptr;
	__e_obj1.add(this->locker, this);
	locker = nullptr;
	__e_obj1.add(this->gate, this);
	gate = nullptr;
	if(!prepare){
		return;
	}
}
void RowLock::lock(ThreadContext* ctx)
{
	if(count > 0)
	{
		count ++ ;
		return;
	}
	{
		try
		{
			if(this->update)
			{
				gate->close(ctx);
			}
						else 
			{
				gate->enter(ctx);
			}
		}
		catch(InterruptedException* e)
		{
			throw (new(ctx) DatabaseLockException(ConstStr::getCNST_STR_1614(), e, ctx));
		}
	}
	count ++ ;
}
void RowLock::unlock(ConcurrentGatePool* gatePool, ThreadContext* ctx)
{
	count -- ;
	if(count > 0)
	{
		return;
	}
	{
		try
		{
			if(this->update)
			{
				gate->open(ctx);
			}
						else 
			{
				gate->exit(ctx);
			}
		}
		catch(InterruptedException* e)
		{
			if(this->pushBack)
			{
				gatePool->pushBack(gate, ctx);
			}
			throw (new(ctx) DatabaseLockException(ConstStr::getCNST_STR_1614(), e, ctx));
		}
	}
	if(this->pushBack)
	{
		gatePool->pushBack(gate, ctx);
	}
}
int RowLock::getLockType(ThreadContext* ctx) throw() 
{
	return IDatabaseLock::ROW_LOCK;
}
}}}}

