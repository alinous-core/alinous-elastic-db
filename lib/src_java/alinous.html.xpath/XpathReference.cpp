#include "includes.h"


namespace alinous {namespace html {namespace xpath {





bool XpathReference::__init_done = __init_static_variables();
bool XpathReference::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"XpathReference", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 XpathReference::~XpathReference() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void XpathReference::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"XpathReference", L"~XpathReference");
	__e_obj1.add(this->xpath, this);
	xpath = nullptr;
	if(!prepare){
		return;
	}
}
Xpath* XpathReference::getXpath(ThreadContext* ctx) throw() 
{
	return xpath;
}
void XpathReference::setXpath(Xpath* xpath, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->xpath), xpath, Xpath);
}
String* XpathReference::toString(ThreadContext* ctx) throw() 
{
	return this->xpath->toString(ctx);
}
IVariableValue* XpathReference::getValue(DomDocument* document, DomNode* currentNode, ThreadContext* ctx)
{
	return this->xpath->getValue(document, currentNode, ctx);
}
}}}

