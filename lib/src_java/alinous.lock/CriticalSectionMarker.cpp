#include "includes.h"


namespace alinous {namespace lock {





bool CriticalSectionMarker::__init_done = __init_static_variables();
bool CriticalSectionMarker::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"CriticalSectionMarker", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 CriticalSectionMarker::CriticalSectionMarker(ThreadContext* ctx) throw()  : IObject(ctx), critical(0), lock(__GC_INS(this, (new(ctx) LockObject(ctx)), LockObject))
{
	this->critical = false;
}
void CriticalSectionMarker::__construct_impl(ThreadContext* ctx) throw() 
{
	this->critical = false;
}
 CriticalSectionMarker::~CriticalSectionMarker() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void CriticalSectionMarker::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"CriticalSectionMarker", L"~CriticalSectionMarker");
	__e_obj1.add(this->lock, this);
	lock = nullptr;
	if(!prepare){
		return;
	}
}
void CriticalSectionMarker::enter(ThreadContext* ctx)
{
	{
		SynchronizedBlockObj __synchronized_2(this->lock, ctx);
		if(this->critical == true)
		{
			throw (new(ctx) CriticalSectionMarkerException(ConstStr::getCNST_STR_1726(), ctx));
		}
		this->critical = true;
	}
}
void CriticalSectionMarker::exit(ThreadContext* ctx)
{
	{
		SynchronizedBlockObj __synchronized_2(this->lock, ctx);
		if(this->critical == false)
		{
			throw (new(ctx) CriticalSectionMarkerException(ConstStr::getCNST_STR_1727(), ctx));
		}
		this->critical = false;
	}
}
void CriticalSectionMarker::checkCritical(ThreadContext* ctx)
{
	{
		SynchronizedBlockObj __synchronized_2(this->lock, ctx);
		if(this->critical == true)
		{
			throw (new(ctx) CriticalSectionMarkerException(ConstStr::getCNST_STR_1728(), ctx));
		}
	}
}
}}

