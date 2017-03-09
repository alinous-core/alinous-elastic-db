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
 XHtmlSQString::XHtmlSQString(ThreadContext* ctx) throw()  : IObject(ctx), AbstractXHtmlAttributeValue(ctx)
{
}
void XHtmlSQString::__construct_impl(ThreadContext* ctx) throw() 
{
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
	context->addStaticString(ConstStr::getCNST_STR_1780(), ctx);
	context->addParts(this->parts, ctx);
	context->addStaticString(ConstStr::getCNST_STR_1780(), ctx);
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
		buff->append(ConstStr::getCNST_STR_1780(), ctx)->append(this->value->toString(ctx), ctx)->append(ConstStr::getCNST_STR_1780(), ctx);
	}
	return buff->toString(ctx);
}
AbstractXHtmlElement::ElementType XHtmlSQString::getElementType(ThreadContext* ctx) throw() 
{
	return AbstractXHtmlElement::ElementType::SqString;
}
void XHtmlSQString::__cleanUp(ThreadContext* ctx){
}
}}}

