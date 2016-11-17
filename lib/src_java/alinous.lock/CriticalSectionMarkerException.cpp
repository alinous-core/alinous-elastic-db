#include "includes.h"


namespace alinous {namespace lock {





constexpr const long long CriticalSectionMarkerException::serialVersionUID;
bool CriticalSectionMarkerException::__init_done = __init_static_variables();
bool CriticalSectionMarkerException::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"CriticalSectionMarkerException", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 CriticalSectionMarkerException::CriticalSectionMarkerException(String* string, ThreadContext* ctx) throw()  : IObject(ctx), Throwable(string, ctx)
{
}
void CriticalSectionMarkerException::__construct_impl(String* string, ThreadContext* ctx) throw() 
{
}
 CriticalSectionMarkerException::~CriticalSectionMarkerException() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void CriticalSectionMarkerException::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	Throwable::__releaseRegerences(true, ctx);
}
}}

