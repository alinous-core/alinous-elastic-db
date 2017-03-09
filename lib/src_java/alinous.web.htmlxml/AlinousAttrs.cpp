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





String* AlinousAttrs::ALINOUS_IF = ConstStr::getCNST_STR_1847();
String* AlinousAttrs::ALINOUS_INNER = ConstStr::getCNST_STR_1848();
String* AlinousAttrs::ALINOUS_TAGID = ConstStr::getCNST_STR_1849();
String* AlinousAttrs::ALINOUS_TARGET = ConstStr::getCNST_STR_1850();
String* AlinousAttrs::ALINOUS_ITERATE = ConstStr::getCNST_STR_1851();
String* AlinousAttrs::ALINOUS_VARIABLE = ConstStr::getCNST_STR_1852();
String* AlinousAttrs::ALINOUS_MSG = ConstStr::getCNST_STR_1853();
String* AlinousAttrs::ALINOUS_MSG_TARGET = ConstStr::getCNST_STR_1854();
String* AlinousAttrs::ALINOUS_FORM = ConstStr::getCNST_STR_1855();
String* AlinousAttrs::ALINOUS_BACK = ConstStr::getCNST_STR_1856();
String* AlinousAttrs::ALINOUS_VALIDATE_TYPE = ConstStr::getCNST_STR_1857();
String* AlinousAttrs::ALINOUS_VALIDATE_IF = ConstStr::getCNST_STR_1858();
String* AlinousAttrs::ALINOUS_REGEX = ConstStr::getCNST_STR_1859();
String* AlinousAttrs::ALINOUS_PARAM = ConstStr::getCNST_STR_1860();
String* AlinousAttrs::ALINOUS_TYPE = ConstStr::getCNST_STR_1861();
String* AlinousAttrs::ALINOUS_NO_FORM_CACHE = ConstStr::getCNST_STR_1862();
String* AlinousAttrs::ALINOUS_IGNOREBLANK = ConstStr::getCNST_STR_1863();
String* AlinousAttrs::ALINOUS_IGNORE_SELF_ITERATE = ConstStr::getCNST_STR_1864();
String* AlinousAttrs::ALINOUS_EXTRACT = ConstStr::getCNST_STR_1865();
String* AlinousAttrs::ALINOUS_COMPONENT = ConstStr::getCNST_STR_1866();
String* AlinousAttrs::ALINOUS_COMPONENT_ID = ConstStr::getCNST_STR_1867();
String* AlinousAttrs::ALINOUS_COMPONENT_WIDTH = ConstStr::getCNST_STR_1868();
String* AlinousAttrs::ALINOUS_COMPONENT_EDIT = ConstStr::getCNST_STR_1869();
String* AlinousAttrs::ALINOUS_COMPONENT_VIEW = ConstStr::getCNST_STR_1870();
String* AlinousAttrs::ALINOUS_COMPONENT_VIEWTYPE = ConstStr::getCNST_STR_1871();
String* AlinousAttrs::ALINOUS_COMPONENT_ROOT = ConstStr::getCNST_STR_1872();
String* AlinousAttrs::VALUE_TRUE = ConstStr::getCNST_STR_372();
String* AlinousAttrs::VALUE_FALSE = ConstStr::getCNST_STR_989();
String* AlinousAttrs::VALUE_VIEWTYPE_FRAME = ConstStr::getCNST_STR_1873();
String* AlinousAttrs::VALUE_VIEWTYPE_INNER = ConstStr::getCNST_STR_1874();
String* AlinousAttrs::ALINOUS_ALINOUS_FORM = ConstStr::getCNST_STR_1875();
bool AlinousAttrs::__init_done = __init_static_variables();
bool AlinousAttrs::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AlinousAttrs", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AlinousAttrs::AlinousAttrs(ThreadContext* ctx) throw()  : IObject(ctx)
{
}
void AlinousAttrs::__construct_impl(ThreadContext* ctx) throw() 
{
}
 AlinousAttrs::~AlinousAttrs() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AlinousAttrs::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
bool AlinousAttrs::isAlinousAttr(String* attrStr, ThreadContext* ctx) throw() 
{
	attrStr = attrStr->toLowerCase(ctx);
	return attrStr->equals(ALINOUS_IF, ctx) || attrStr->equals(ALINOUS_INNER, ctx) || attrStr->equals(ALINOUS_TAGID, ctx) || attrStr->equals(ALINOUS_TARGET, ctx) || attrStr->equals(ALINOUS_ITERATE, ctx) || attrStr->equals(ALINOUS_VARIABLE, ctx) || attrStr->equals(ALINOUS_MSG, ctx) || attrStr->equals(ALINOUS_MSG_TARGET, ctx) || attrStr->equals(ALINOUS_FORM, ctx) || attrStr->equals(ALINOUS_BACK, ctx) || attrStr->equals(ALINOUS_VALIDATE_TYPE, ctx) || attrStr->equals(ALINOUS_VALIDATE_IF, ctx) || attrStr->equals(ALINOUS_REGEX, ctx) || attrStr->equals(ALINOUS_PARAM, ctx) || attrStr->equals(ALINOUS_TYPE, ctx) || attrStr->equals(ALINOUS_NO_FORM_CACHE, ctx) || attrStr->equals(ALINOUS_IGNOREBLANK, ctx) || attrStr->equals(ALINOUS_IGNORE_SELF_ITERATE, ctx) || attrStr->equals(ALINOUS_EXTRACT, ctx) || attrStr->equals(ALINOUS_COMPONENT, ctx) || attrStr->equals(ALINOUS_COMPONENT_ID, ctx) || attrStr->equals(ALINOUS_COMPONENT_WIDTH, ctx) || attrStr->equals(ALINOUS_COMPONENT_EDIT, ctx) || attrStr->equals(ALINOUS_COMPONENT_VIEW, ctx) || attrStr->equals(ALINOUS_COMPONENT_VIEWTYPE, ctx) || attrStr->equals(ALINOUS_COMPONENT_ROOT, ctx) || attrStr->equals(ALINOUS_ALINOUS_FORM, ctx);
}
void AlinousAttrs::__cleanUp(ThreadContext* ctx){
}
}}}

