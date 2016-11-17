#include "includes.h"


namespace alinous {namespace compile {namespace analyse {





bool SubVariableDeclareHolder::__init_done = __init_static_variables();
bool SubVariableDeclareHolder::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"SubVariableDeclareHolder", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 SubVariableDeclareHolder::~SubVariableDeclareHolder() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void SubVariableDeclareHolder::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"SubVariableDeclareHolder", L"~SubVariableDeclareHolder");
	__e_obj1.add(this->typedVariableDeclare, this);
	typedVariableDeclare = nullptr;
	if(!prepare){
		return;
	}
}
HashMap<String,TypedVariableDeclareSource>* SubVariableDeclareHolder::getTypedVariableDeclare(ThreadContext* ctx) throw() 
{
	return typedVariableDeclare;
}
void SubVariableDeclareHolder::addTypedVariableDeclare(TypedVariableDeclare* typedVariableDeclare, ThreadContext* ctx) throw() 
{
	TypedVariableDeclareSource* src = (new(ctx) TypedVariableDeclareSource(typedVariableDeclare, ctx));
	this->typedVariableDeclare->put(src->getSearchId(ctx), src, ctx);
}
void SubVariableDeclareHolder::addFunctionArgumentDefine(FunctionArgumentDefine* argumentDefine, ThreadContext* ctx) throw() 
{
	TypedVariableDeclareSource* src = (new(ctx) TypedVariableDeclareSource(argumentDefine, ctx));
	this->typedVariableDeclare->put(src->getSearchId(ctx), src, ctx);
}
TypedVariableDeclareSource* SubVariableDeclareHolder::getTypedVariableDeclareSource(String* name, ThreadContext* ctx) throw() 
{
	return this->typedVariableDeclare->get(name, ctx);
}
}}}

