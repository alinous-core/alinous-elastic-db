#include "includes.h"


namespace alinous {namespace db {namespace table {namespace lockmonitor {





bool TableLock::__init_done = __init_static_variables();
bool TableLock::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"TableLock", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 TableLock::TableLock(bool update, DatabaseTable* table, ThreadLocker* locker, ConcurrentGate* gate, ThreadContext* ctx) throw()  : IObject(ctx), IDatabaseLock(ctx), update(0), table(nullptr), locker(nullptr), count(0), pushBack(0), gate(nullptr)
{
	this->update = update;
	__GC_MV(this, &(this->table), table, DatabaseTable);
	__GC_MV(this, &(this->locker), locker, ThreadLocker);
	__GC_MV(this, &(this->gate), gate, ConcurrentGate);
	this->pushBack = false;
}
void TableLock::__construct_impl(bool update, DatabaseTable* table, ThreadLocker* locker, ConcurrentGate* gate, ThreadContext* ctx) throw() 
{
	this->update = update;
	__GC_MV(this, &(this->table), table, DatabaseTable);
	__GC_MV(this, &(this->locker), locker, ThreadLocker);
	__GC_MV(this, &(this->gate), gate, ConcurrentGate);
	this->pushBack = false;
}
 TableLock::~TableLock() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void TableLock::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"TableLock", L"~TableLock");
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
void TableLock::lock(ThreadContext* ctx)
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
			throw (new(ctx) DatabaseLockException(ConstStr::getCNST_STR_1581(), e, ctx));
		}
	}
	count ++ ;
}
void TableLock::unlock(ConcurrentGatePool* gatePool, ThreadContext* ctx)
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
			throw (new(ctx) DatabaseLockException(ConstStr::getCNST_STR_1581(), e, ctx));
		}
	}
	if(this->pushBack)
	{
		gatePool->pushBack(gate, ctx);
	}
}
int TableLock::getLockType(ThreadContext* ctx) throw() 
{
	return IDatabaseLock::TABLE_LOCK;
}
}}}}

