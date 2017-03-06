#include "include/global.h"


#include "alinous.web.htmlxml/XmlHeaderTagObject.h"
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





bool XmlHeaderTagObject::__init_done = __init_static_variables();
bool XmlHeaderTagObject::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"XmlHeaderTagObject", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 XmlHeaderTagObject::XmlHeaderTagObject(ThreadContext* ctx) throw()  : IObject(ctx)
{
}
void XmlHeaderTagObject::__construct_impl(ThreadContext* ctx) throw() 
{
}
 XmlHeaderTagObject::~XmlHeaderTagObject() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void XmlHeaderTagObject::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
void XmlHeaderTagObject::__cleanUp(ThreadContext* ctx){
}
}}}

