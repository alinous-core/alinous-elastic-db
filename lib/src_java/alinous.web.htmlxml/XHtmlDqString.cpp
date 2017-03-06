#include "include/global.h"


#include "alinous.web.htmlxml/XmlHeaderTagObject.h"
#include "alinous.db.table/DatabaseException.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.web.htmlxml.inner/IHtmlStringPart.h"
#include "alinous.web.parse.htmlxml/Token.h"
#include "alinous.web.htmlxml/AbstractXHtmlElement.h"
#include "alinous.web.htmlxml/AbstractXHtmlAttributeValue.h"
#include "alinous.web.htmlxml/XHtmlAttribute.h"
#include "alinous.web.htmlxml/XMLTagBase.h"
#include "alinous.web.htmlxml.module/SerializeContext.h"
#include "alinous.web.htmlxml/XHtmlComment.h"
#include "alinous.web.htmlxml/HtmlDocType.h"
#include "alinous.web.htmlxml/HtmlTopObject.h"
#include "alinous.web.htmlxml/AlinousAttrs.h"
#include "alinous.web.htmlxml.module/DynamicExecutableAttributeValue.h"
#include "alinous.web.htmlxml/XHtmlDqString.h"
#include "alinous.web.htmlxml/XHtmlSQString.h"
#include "alinous.web.htmlxml/BodyText.h"

namespace alinous {namespace web {namespace htmlxml {





bool XHtmlDqString::__init_done = __init_static_variables();
bool XHtmlDqString::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"XHtmlDqString", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 XHtmlDqString::XHtmlDqString(ThreadContext* ctx) throw()  : IObject(ctx), AbstractXHtmlAttributeValue(ctx), dynValue(nullptr)
{
}
void XHtmlDqString::__construct_impl(ThreadContext* ctx) throw() 
{
}
 XHtmlDqString::~XHtmlDqString() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void XHtmlDqString::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"XHtmlDqString", L"~XHtmlDqString");
	__e_obj1.add(this->dynValue, this);
	dynValue = nullptr;
	if(!prepare){
		return;
	}
	AbstractXHtmlAttributeValue::__releaseRegerences(true, ctx);
}
void XHtmlDqString::initDinamicProgram(ThreadContext* ctx)
{
	__GC_MV(this, &(this->dynValue), (new(ctx) DynamicExecutableAttributeValue(this->value, ctx)), DynamicExecutableAttributeValue);
}
bool XHtmlDqString::isDinamicAll(ThreadContext* ctx) throw() 
{
	return this->isDynamic;
}
void XHtmlDqString::serialize(SerializeContext* context, ThreadContext* ctx)
{
	context->addStaticString(ConstStr::getCNST_STR_1317(), ctx);
	context->addParts(this->parts, ctx);
	context->addStaticString(ConstStr::getCNST_STR_1317(), ctx);
}
String* XHtmlDqString::execute(ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	return this->value;
}
String* XHtmlDqString::toString(ThreadContext* ctx) throw() 
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	if(this->value != nullptr)
	{
		buff->append(ConstStr::getCNST_STR_1317(), ctx)->append(this->value->toString(ctx), ctx)->append(ConstStr::getCNST_STR_1317(), ctx);
	}
	return buff->toString(ctx);
}
AbstractXHtmlElement::ElementType XHtmlDqString::getElementType(ThreadContext* ctx) throw() 
{
	return AbstractXHtmlElement::ElementType::DqString;
}
void XHtmlDqString::__cleanUp(ThreadContext* ctx){
}
}}}

