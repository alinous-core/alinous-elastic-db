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





bool LockObject::__init_done = __init_static_variables();
bool LockObject::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"LockObject", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 LockObject::~LockObject() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void LockObject::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
}}

