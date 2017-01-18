#include "includes.h"


namespace alinous {namespace html {namespace xpath {





bool XpathString::__init_done = __init_static_variables();
bool XpathString::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"XpathString", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 XpathString::~XpathString() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void XpathString::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"XpathString", L"~XpathString");
	__e_obj1.add(this->text, this);
	text = nullptr;
	if(!prepare){
		return;
	}
}
String* XpathString::getText(ThreadContext* ctx) throw() 
{
	return text;
}
void XpathString::setText(String* text, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->text), text, String);
}
String* XpathString::toString(ThreadContext* ctx) throw() 
{
	StringBuffer* buffer = (new(ctx) StringBuffer(ctx));
	buffer->append(ConstStr::getCNST_STR_1734(), ctx);
	buffer->append(this->text, ctx);
	buffer->append(ConstStr::getCNST_STR_1734(), ctx);
	return buffer->toString(ctx);
}
IVariableValue* XpathString::getValue(DomDocument* document, DomNode* currentNode, ThreadContext* ctx) throw() 
{
	return (new(ctx) StringValue(this->text, ctx));
}
}}}

