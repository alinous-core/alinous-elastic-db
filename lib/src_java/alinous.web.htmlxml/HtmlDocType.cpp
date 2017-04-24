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





bool HtmlDocType::__init_done = __init_static_variables();
bool HtmlDocType::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"HtmlDocType", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 HtmlDocType::HtmlDocType(ThreadContext* ctx) throw()  : IObject(ctx), AbstractXHtmlElement(ctx), elements(GCUtils<ArrayList<AbstractXHtmlElement> >::ins(this, (new(ctx) ArrayList<AbstractXHtmlElement>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
	this->isDynamic = false;
}
void HtmlDocType::__construct_impl(ThreadContext* ctx) throw() 
{
	this->isDynamic = false;
}
 HtmlDocType::~HtmlDocType() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void HtmlDocType::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"HtmlDocType", L"~HtmlDocType");
	__e_obj1.add(this->elements, this);
	elements = nullptr;
	if(!prepare){
		return;
	}
	AbstractXHtmlElement::__releaseRegerences(true, ctx);
}
void HtmlDocType::serialize(SerializeContext* context, ThreadContext* ctx) throw() 
{
	String* htmlCode = toString(ctx);
	context->addStaticString(htmlCode, ctx);
}
String* HtmlDocType::execute(ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	return toString(ctx);
}
void HtmlDocType::addElement(AbstractXHtmlElement* element, ThreadContext* ctx) throw() 
{
	this->elements->add(element, ctx);
}
ArrayList<AbstractXHtmlElement>* HtmlDocType::getElements(ThreadContext* ctx) throw() 
{
	return elements;
}
String* HtmlDocType::toString(ThreadContext* ctx) throw() 
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	buff->append(ConstStr::getCNST_STR_1791(), ctx);
	int maxLoop = this->elements->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		AbstractXHtmlElement* element = this->elements->get(i, ctx);
		buff->append(ConstStr::getCNST_STR_380(), ctx);
		buff->append(element->toString(ctx), ctx);
	}
	buff->append(ConstStr::getCNST_STR_82(), ctx);
	return buff->toString(ctx);
}
AbstractXHtmlElement::ElementType HtmlDocType::getElementType(ThreadContext* ctx) throw() 
{
	return AbstractXHtmlElement::ElementType::HtmlDocType;
}
bool HtmlDocType::isDinamicAll(ThreadContext* ctx) throw() 
{
	return this->isDynamic;
}
void HtmlDocType::__cleanUp(ThreadContext* ctx){
}
}}}

