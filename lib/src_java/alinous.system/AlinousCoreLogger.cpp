#include "includes.h"


namespace alinous {namespace system {





bool AlinousCoreLogger::__init_done = __init_static_variables();
bool AlinousCoreLogger::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AlinousCoreLogger", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AlinousCoreLogger::~AlinousCoreLogger() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AlinousCoreLogger::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
void AlinousCoreLogger::logError(Throwable* e, ThreadContext* ctx) throw() 
{
	e->printStackTrace(ctx);
}
void AlinousCoreLogger::logWarning(String* message, ThreadContext* ctx) throw() 
{
	System::out->println(message, ctx);
}
void AlinousCoreLogger::logInfo(String* message, ThreadContext* ctx) throw() 
{
	System::out->println(message, ctx);
}
}}

