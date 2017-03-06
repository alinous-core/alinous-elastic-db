#include "include/global.h"


#include "alinous.lock/ILock.h"
#include "alinous.lock/IConcurrentLockManager.h"
#include "alinous.lock/UpdateLock.h"
#include "alinous.lock/ShareLock.h"
#include "alinous.lock/ConcurrentLock.h"
#include "alinous.lock/LockObject.h"
#include "alinous.lock/UpgreadableGate.h"
#include "alinous.lock/CriticalSectionMarkerException.h"
#include "alinous.lock/CriticalSectionMarker.h"
#include "alinous.lock/ConcurrentGate.h"

namespace alinous {namespace lock {





bool UpdateLock::__init_done = __init_static_variables();
bool UpdateLock::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"UpdateLock", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 UpdateLock::UpdateLock(IConcurrentLockManager* parent, ThreadContext* ctx) throw()  : IObject(ctx), ILock(ctx), parent(nullptr)
{
	__GC_MV(this, &(this->parent), parent, IConcurrentLockManager);
}
void UpdateLock::__construct_impl(IConcurrentLockManager* parent, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->parent), parent, IConcurrentLockManager);
}
 UpdateLock::~UpdateLock() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void UpdateLock::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"UpdateLock", L"~UpdateLock");
	__e_obj1.add(this->parent, this);
	parent = nullptr;
	if(!prepare){
		return;
	}
}
void UpdateLock::unlock(ThreadContext* ctx)
{
	parent->endUpdateLock(ctx);
}
void UpdateLock::__cleanUp(ThreadContext* ctx){
}
}}

