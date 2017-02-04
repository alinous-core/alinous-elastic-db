#include "includes.h"


namespace alinous {namespace compile {namespace sql {namespace functions {





bool Coalesce::__init_done = __init_static_variables();
bool Coalesce::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"Coalesce", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 Coalesce::~Coalesce() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void Coalesce::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
String* Coalesce::getName(ThreadContext* ctx) throw() 
{
	return ConstStr::getCNST_STR_1079();
}
VariantValue* Coalesce::resolveSQLExpression(ScanResultRecord* record, ScriptMachine* machine, FunctionArguments* args, bool debug, ThreadContext* ctx)
{
	return nullptr;
}
}}}}

