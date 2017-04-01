#include "include/global.h"


#include "alinous.lock/LockObject.h"
#include "alinous.remote.monitor/OidHolder.h"

namespace alinous {namespace remote {namespace monitor {





bool OidHolder::__init_done = __init_static_variables();
bool OidHolder::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"OidHolder", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 OidHolder::OidHolder(ThreadContext* ctx) throw()  : IObject(ctx), oidLock(__GC_INS(this, (new(ctx) LockObject(ctx)), LockObject)), lastOid(0)
{
}
void OidHolder::__construct_impl(ThreadContext* ctx) throw() 
{
}
 OidHolder::~OidHolder() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void OidHolder::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"OidHolder", L"~OidHolder");
	__e_obj1.add(this->oidLock, this);
	oidLock = nullptr;
	if(!prepare){
		return;
	}
}
void OidHolder::setNextOid(long long lastOid, ThreadContext* ctx) throw() 
{
	{
		SynchronizedBlockObj __synchronized_2(this->oidLock, ctx);
		this->lastOid = lastOid;
	}
}
long long OidHolder::getNextOid(int length, ThreadContext* ctx) throw() 
{
	{
		SynchronizedBlockObj __synchronized_2(this->oidLock, ctx);
		long long cur = this->lastOid;
		this->lastOid += length;
		return cur;
	}
}
void OidHolder::__cleanUp(ThreadContext* ctx){
}
}}}

