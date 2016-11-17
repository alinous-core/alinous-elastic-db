#include "includes.h"


namespace alinous {namespace compile {namespace analyse {





bool DomVariableDeclareSource::__init_done = __init_static_variables();
bool DomVariableDeclareSource::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DomVariableDeclareSource", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 DomVariableDeclareSource::DomVariableDeclareSource(String* domPath, IExpression* exp, ThreadContext* ctx) throw()  : IObject(ctx), domPath(nullptr), exp(nullptr)
{
	__GC_MV(this, &(this->domPath), domPath, String);
	__GC_MV(this, &(this->exp), exp, IExpression);
}
void DomVariableDeclareSource::__construct_impl(String* domPath, IExpression* exp, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->domPath), domPath, String);
	__GC_MV(this, &(this->exp), exp, IExpression);
}
 DomVariableDeclareSource::~DomVariableDeclareSource() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void DomVariableDeclareSource::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"DomVariableDeclareSource", L"~DomVariableDeclareSource");
	__e_obj1.add(this->domPath, this);
	domPath = nullptr;
	__e_obj1.add(this->exp, this);
	exp = nullptr;
	if(!prepare){
		return;
	}
}
String* DomVariableDeclareSource::getDomPath(ThreadContext* ctx) throw() 
{
	return domPath;
}
void DomVariableDeclareSource::setDomPath(String* domPath, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->domPath), domPath, String);
}
IExpression* DomVariableDeclareSource::getExp(ThreadContext* ctx) throw() 
{
	return exp;
}
void DomVariableDeclareSource::setExp(IExpression* exp, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->exp), exp, IExpression);
}
}}}

