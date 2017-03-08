#include "include/global.h"


#include "alinous.lock/IConcurrentLockManager.h"
#include "alinous.lock/ILock.h"
#include "alinous.lock/ShareLock.h"

namespace alinous {namespace lock {





bool ShareLock::__init_done = __init_static_variables();
bool ShareLock::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ShareLock", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ShareLock::ShareLock(IConcurrentLockManager* parent, ThreadContext* ctx) throw()  : IObject(ctx), ILock(ctx), parent(nullptr), cnt(0)
{
	__GC_MV(this, &(this->parent), parent, IConcurrentLockManager);
	this->cnt = 1;
}
void ShareLock::__construct_impl(IConcurrentLockManager* parent, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->parent), parent, IConcurrentLockManager);
	this->cnt = 1;
}
 ShareLock::~ShareLock() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ShareLock::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ShareLock", L"~ShareLock");
	__e_obj1.add(this->parent, this);
	parent = nullptr;
	if(!prepare){
		return;
	}
}
ShareLock* ShareLock::inc(ThreadContext* ctx) throw() 
{
	this->cnt ++ ;
	return this;
}
int ShareLock::dec(ThreadContext* ctx) throw() 
{
	this->cnt -- ;
	return this->cnt;
}
void ShareLock::unlock(ThreadContext* ctx)
{
	this->parent->endShareLock(ctx);
}
int ShareLock::getCnt(ThreadContext* ctx) throw() 
{
	return cnt;
}
void ShareLock::__cleanUp(ThreadContext* ctx){
}
}}

