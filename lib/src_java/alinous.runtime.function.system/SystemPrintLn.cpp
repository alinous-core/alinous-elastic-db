#include "includes.h"


namespace alinous {namespace runtime {namespace function {namespace system {





bool SystemPrintLn::__init_done = __init_static_variables();
bool SystemPrintLn::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"SystemPrintLn", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 SystemPrintLn::SystemPrintLn(ThreadContext* ctx) throw()  : IObject(ctx), AbstractNativeFunction(ctx)
{
	__GC_MV(this, &(this->prefix), ConstStr::getCNST_STR_1154(), String);
	__GC_MV(this, &(this->name), ConstStr::getCNST_STR_1155(), String);
	this->argumentMetadata->add(makeStringType(ctx), ctx);
}
void SystemPrintLn::__construct_impl(ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->prefix), ConstStr::getCNST_STR_1154(), String);
	__GC_MV(this, &(this->name), ConstStr::getCNST_STR_1155(), String);
	this->argumentMetadata->add(makeStringType(ctx), ctx);
}
 SystemPrintLn::~SystemPrintLn() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void SystemPrintLn::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	AbstractNativeFunction::__releaseRegerences(true, ctx);
}
AlinousType* SystemPrintLn::getReturnType(ThreadContext* ctx) throw() 
{
	return makeVoidType(ctx);
}
void SystemPrintLn::execute(ArrayList<IAlinousVariable>* args, ScriptMachine* machine, ThreadContext* ctx)
{
	if(args->get(0, ctx) != nullptr)
	{
		doExecute(args->get(0, ctx)->getStringValue(ctx), ctx);
		return;
	}
	doExecute(ConstStr::getCNST_STR_369(), ctx);
}
void SystemPrintLn::doExecute(String* str, ThreadContext* ctx) throw() 
{
	System::out->println(str, ctx);
}
}}}}

