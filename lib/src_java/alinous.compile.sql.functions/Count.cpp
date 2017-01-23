#include "includes.h"


namespace alinous {namespace compile {namespace sql {namespace functions {





bool Count::__init_done = __init_static_variables();
bool Count::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"Count", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 Count::~Count() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void Count::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
String* Count::getName(ThreadContext* ctx) throw() 
{
	return ConstStr::getCNST_STR_1078();
}
VariantValue* Count::resolveSQLExpression(ScanResultRecord* record, ScriptMachine* machine, FunctionArguments* args, bool debug, ThreadContext* ctx)
{
	return nullptr;
}
}}}}

