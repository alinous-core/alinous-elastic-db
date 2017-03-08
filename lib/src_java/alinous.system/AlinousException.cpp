#include "include/global.h"


#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"

namespace alinous {namespace system {





constexpr const long long AlinousException::serialVersionUID;
bool AlinousException::__init_done = __init_static_variables();
bool AlinousException::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AlinousException", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AlinousException::AlinousException(ThreadContext* ctx) throw()  : IObject(ctx), Throwable(ctx), srcElement(nullptr)
{
}
void AlinousException::__construct_impl(ThreadContext* ctx) throw() 
{
}
 AlinousException::AlinousException(String* msg, ThreadContext* ctx) throw()  : IObject(ctx), Throwable(msg, ctx), srcElement(nullptr)
{
}
void AlinousException::__construct_impl(String* msg, ThreadContext* ctx) throw() 
{
}
 AlinousException::AlinousException(String* msg, Throwable* e, ThreadContext* ctx) throw()  : IObject(ctx), Throwable(msg, e, ctx), srcElement(nullptr)
{
}
void AlinousException::__construct_impl(String* msg, Throwable* e, ThreadContext* ctx) throw() 
{
}
 AlinousException::AlinousException(String* msg, AbstractSrcElement* element, ThreadContext* ctx) throw()  : IObject(ctx), Throwable(msg, ctx), srcElement(nullptr)
{
	__GC_MV(this, &(this->srcElement), element, AbstractSrcElement);
}
void AlinousException::__construct_impl(String* msg, AbstractSrcElement* element, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->srcElement), element, AbstractSrcElement);
}
 AlinousException::AlinousException(Throwable* e, ThreadContext* ctx) throw()  : IObject(ctx), Throwable(e, ctx), srcElement(nullptr)
{
}
void AlinousException::__construct_impl(Throwable* e, ThreadContext* ctx) throw() 
{
}
 AlinousException::~AlinousException() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AlinousException::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"AlinousException", L"~AlinousException");
	__e_obj1.add(this->srcElement, this);
	srcElement = nullptr;
	if(!prepare){
		return;
	}
	Throwable::__releaseRegerences(true, ctx);
}
AbstractSrcElement* AlinousException::getSrcElement(ThreadContext* ctx) throw() 
{
	return srcElement;
}
void AlinousException::setSrcElement(AbstractSrcElement* srcElement, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->srcElement), srcElement, AbstractSrcElement);
}
void AlinousException::__cleanUp(ThreadContext* ctx){
}
}}

