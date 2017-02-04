#include "includes.h"


namespace alinous {namespace web {namespace htmlxml {





bool XHtmlSQString::__init_done = __init_static_variables();
bool XHtmlSQString::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"XHtmlSQString", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 XHtmlSQString::~XHtmlSQString() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void XHtmlSQString::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	AbstractXHtmlAttributeValue::__releaseRegerences(true, ctx);
}
bool XHtmlSQString::isDinamicAll(ThreadContext* ctx) throw() 
{
	return this->isDynamic;
}
void XHtmlSQString::serialize(SerializeContext* context, ThreadContext* ctx)
{
	context->addStaticString(ConstStr::getCNST_STR_1748(), ctx);
	context->addParts(this->parts, ctx);
	context->addStaticString(ConstStr::getCNST_STR_1748(), ctx);
}
String* XHtmlSQString::execute(ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	return nullptr;
}
String* XHtmlSQString::toString(ThreadContext* ctx) throw() 
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	if(this->value != nullptr)
	{
		buff->append(ConstStr::getCNST_STR_1748(), ctx)->append(this->value->toString(ctx), ctx)->append(ConstStr::getCNST_STR_1748(), ctx);
	}
	return buff->toString(ctx);
}
AbstractXHtmlElement::ElementType XHtmlSQString::getElementType(ThreadContext* ctx) throw() 
{
	return AbstractXHtmlElement::ElementType::SqString;
}
}}}

