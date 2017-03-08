#include "include/global.h"


#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.analyse/AlinousType.h"
#include "alinous.runtime.function/IAlinousNativeFunction.h"

namespace alinous {namespace runtime {namespace function {




bool IAlinousNativeFunction::__init_done = __init_static_variables();
bool IAlinousNativeFunction::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"IAlinousNativeFunction", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 IAlinousNativeFunction::IAlinousNativeFunction(ThreadContext* ctx) throw()  : IObject(ctx)
{
}
void IAlinousNativeFunction::__construct_impl(ThreadContext* ctx) throw() 
{
}
 IAlinousNativeFunction::~IAlinousNativeFunction() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void IAlinousNativeFunction::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
void IAlinousNativeFunction::__cleanUp(ThreadContext* ctx){
}
}}}

