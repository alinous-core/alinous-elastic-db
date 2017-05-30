#include "include/global.h"


#include "alinous.lock/ConcurrentGate.h"
#include "alinous.remote.region.server.lock/IRemoteTableLock.h"
#include "alinous.remote.region.server.lock/RemoteTableLock.h"

namespace alinous {namespace remote {namespace region {namespace server {namespace lock {





bool RemoteTableLock::__init_done = __init_static_variables();
bool RemoteTableLock::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"RemoteTableLock", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 RemoteTableLock::RemoteTableLock(ThreadContext* ctx) throw()  : IObject(ctx), IRemoteTableLock(ctx), gate(nullptr)
{
	__GC_MV(this, &(this->gate), (new(ctx) ConcurrentGate(ctx)), ConcurrentGate);
}
void RemoteTableLock::__construct_impl(ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->gate), (new(ctx) ConcurrentGate(ctx)), ConcurrentGate);
}
 RemoteTableLock::~RemoteTableLock() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void RemoteTableLock::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"RemoteTableLock", L"~RemoteTableLock");
	__e_obj1.add(this->gate, this);
	gate = nullptr;
	if(!prepare){
		return;
	}
}
void RemoteTableLock::shareLock(ThreadContext* ctx)
{
	this->gate->enter(ctx);
}
void RemoteTableLock::shareUnlock(ThreadContext* ctx) throw() 
{
	this->gate->exit(ctx);
}
void RemoteTableLock::updateLock(ThreadContext* ctx)
{
	this->gate->close(ctx);
}
void RemoteTableLock::updateUnlock(ThreadContext* ctx)
{
	this->gate->open(ctx);
}
void RemoteTableLock::__cleanUp(ThreadContext* ctx){
}
}}}}}

