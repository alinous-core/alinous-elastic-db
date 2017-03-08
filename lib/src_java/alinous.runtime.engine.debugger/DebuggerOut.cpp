#include "include/global.h"


#include "alinous.runtime.engine.debugger/DebuggerOut.h"

namespace alinous {namespace runtime {namespace engine {namespace debugger {





bool DebuggerOut::__init_done = __init_static_variables();
bool DebuggerOut::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DebuggerOut", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 DebuggerOut::DebuggerOut(ThreadContext* ctx) throw()  : IObject(ctx)
{
}
void DebuggerOut::__construct_impl(ThreadContext* ctx) throw() 
{
}
 DebuggerOut::~DebuggerOut() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void DebuggerOut::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
void DebuggerOut::out(String* str, ThreadContext* ctx) throw() 
{
	System::out->println(str, ctx);
}
void DebuggerOut::__cleanUp(ThreadContext* ctx){
}
}}}}

