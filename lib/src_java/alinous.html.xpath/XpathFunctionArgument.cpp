#include "includes.h"


namespace alinous {namespace html {namespace xpath {





bool XpathFunctionArgument::__init_done = __init_static_variables();
bool XpathFunctionArgument::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"XpathFunctionArgument", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 XpathFunctionArgument::XpathFunctionArgument(IXpathElement* element, ThreadContext* ctx) throw()  : IObject(ctx), IXpathElement(ctx), element(nullptr)
{
	__GC_MV(this, &(this->element), element, IXpathElement);
}
void XpathFunctionArgument::__construct_impl(IXpathElement* element, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->element), element, IXpathElement);
}
 XpathFunctionArgument::~XpathFunctionArgument() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void XpathFunctionArgument::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"XpathFunctionArgument", L"~XpathFunctionArgument");
	__e_obj1.add(this->element, this);
	element = nullptr;
	if(!prepare){
		return;
	}
}
IXpathElement* XpathFunctionArgument::getElement(ThreadContext* ctx) throw() 
{
	return element;
}
void XpathFunctionArgument::setElement(IXpathElement* element, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->element), element, IXpathElement);
}
String* XpathFunctionArgument::toString(ThreadContext* ctx) throw() 
{
	return this->element->toString(ctx);
}
}}}

