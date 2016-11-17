#include "includes.h"


namespace alinous {namespace runtime {namespace exceptions {





constexpr const long long ScriptNullPointerException::serialVersionUID;
bool ScriptNullPointerException::__init_done = __init_static_variables();
bool ScriptNullPointerException::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ScriptNullPointerException", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ScriptNullPointerException::ScriptNullPointerException(AbstractSrcElement* element, ThreadContext* ctx) throw()  : IObject(ctx), AlinousException(ctx), element(nullptr)
{
	__GC_MV(this, &(this->element), element, AbstractSrcElement);
}
void ScriptNullPointerException::__construct_impl(AbstractSrcElement* element, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->element), element, AbstractSrcElement);
}
 ScriptNullPointerException::~ScriptNullPointerException() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ScriptNullPointerException::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ScriptNullPointerException", L"~ScriptNullPointerException");
	__e_obj1.add(this->element, this);
	element = nullptr;
	if(!prepare){
		return;
	}
	AlinousException::__releaseRegerences(true, ctx);
}
}}}

