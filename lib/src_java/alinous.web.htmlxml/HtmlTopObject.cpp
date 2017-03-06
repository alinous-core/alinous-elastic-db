#include "include/global.h"


#include "alinous.web.htmlxml/XmlHeaderTagObject.h"
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





bool HtmlTopObject::__init_done = __init_static_variables();
bool HtmlTopObject::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"HtmlTopObject", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 HtmlTopObject::HtmlTopObject(ThreadContext* ctx) throw()  : IObject(ctx), elements(GCUtils<ArrayList<AbstractXHtmlElement> >::ins(this, (new(ctx) ArrayList<AbstractXHtmlElement>(ctx)), ctx, __FILEW__, __LINE__, L"")), docType(nullptr)
{
}
void HtmlTopObject::__construct_impl(ThreadContext* ctx) throw() 
{
}
 HtmlTopObject::~HtmlTopObject() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void HtmlTopObject::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"HtmlTopObject", L"~HtmlTopObject");
	__e_obj1.add(this->elements, this);
	elements = nullptr;
	__e_obj1.add(this->docType, this);
	docType = nullptr;
	if(!prepare){
		return;
	}
}
void HtmlTopObject::addElement(AbstractXHtmlElement* element, ThreadContext* ctx) throw() 
{
	this->elements->add(element, ctx);
}
void HtmlTopObject::serialize(SerializeContext* context, ThreadContext* ctx)
{
	if(this->docType != nullptr)
	{
		this->docType->serialize(context, ctx);
	}
	ArrayList<AbstractXHtmlElement>* elements = this->elements;
	int maxLoop = elements->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		AbstractXHtmlElement* element = elements->get(i, ctx);
		element->serialize(context, ctx);
	}
}
HtmlDocType* HtmlTopObject::getDocType(ThreadContext* ctx) throw() 
{
	return docType;
}
void HtmlTopObject::setDocType(HtmlDocType* docType, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->docType), docType, HtmlDocType);
}
String* HtmlTopObject::toString(ThreadContext* ctx) throw() 
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	if(this->docType != nullptr)
	{
		buff->append(this->docType->toString(ctx), ctx);
	}
	int maxLoop = this->elements->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		AbstractXHtmlElement* element = this->elements->get(i, ctx);
		buff->append(element->toString(ctx), ctx);
	}
	return buff->toString(ctx);
}
void HtmlTopObject::__cleanUp(ThreadContext* ctx){
}
}}}

