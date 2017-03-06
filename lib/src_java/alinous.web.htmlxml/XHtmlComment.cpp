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





bool XHtmlComment::__init_done = __init_static_variables();
bool XHtmlComment::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"XHtmlComment", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 XHtmlComment::XHtmlComment(ThreadContext* ctx) throw()  : IObject(ctx), AbstractXHtmlElement(ctx), comment(nullptr)
{
	this->isDynamic = false;
}
void XHtmlComment::__construct_impl(ThreadContext* ctx) throw() 
{
	this->isDynamic = false;
}
 XHtmlComment::~XHtmlComment() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void XHtmlComment::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"XHtmlComment", L"~XHtmlComment");
	__e_obj1.add(this->comment, this);
	comment = nullptr;
	if(!prepare){
		return;
	}
	AbstractXHtmlElement::__releaseRegerences(true, ctx);
}
bool XHtmlComment::isDinamicAll(ThreadContext* ctx) throw() 
{
	return this->isDynamic;
}
void XHtmlComment::serialize(SerializeContext* context, ThreadContext* ctx) throw() 
{
	context->addStaticString(toString(ctx), ctx);
}
String* XHtmlComment::execute(ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	return toString(ctx);
}
String* XHtmlComment::getComment(ThreadContext* ctx) throw() 
{
	return comment;
}
void XHtmlComment::setComment(String* comment, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->comment), comment, String);
}
String* XHtmlComment::toString(ThreadContext* ctx) throw() 
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	buff->append(ConstStr::getCNST_STR_1808(), ctx)->append(this->comment, ctx)->append(ConstStr::getCNST_STR_1809(), ctx);
	return buff->toString(ctx);
}
AbstractXHtmlElement::ElementType XHtmlComment::getElementType(ThreadContext* ctx) throw() 
{
	return AbstractXHtmlElement::ElementType::Comment;
}
void XHtmlComment::__cleanUp(ThreadContext* ctx){
}
}}}

