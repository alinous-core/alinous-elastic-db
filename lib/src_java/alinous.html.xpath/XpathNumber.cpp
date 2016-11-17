#include "includes.h"


namespace alinous {namespace html {namespace xpath {





bool XpathNumber::__init_done = __init_static_variables();
bool XpathNumber::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"XpathNumber", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 XpathNumber::~XpathNumber() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void XpathNumber::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"XpathNumber", L"~XpathNumber");
	__e_obj1.add(this->number, this);
	number = nullptr;
	if(!prepare){
		return;
	}
}
String* XpathNumber::getNumber(ThreadContext* ctx) throw() 
{
	return number;
}
void XpathNumber::setNumber(String* number, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->number), number, String);
}
String* XpathNumber::toString(ThreadContext* ctx) throw() 
{
	return number;
}
IVariableValue* XpathNumber::getValue(DomDocument* document, DomNode* currentNode, ThreadContext* ctx) throw() 
{
	return (new(ctx) NumberValue(Integer::parseInt(this->number, ctx), ctx));
}
}}}

