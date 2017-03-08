#include "include/global.h"


#include "alinous.web.parse.htmlxml/TokenMgrError.h"
#include "alinous.web.parse.htmlxml/Token.h"
#include "alinous.web.parse.htmlxml/ParseException.h"
#include "alinous.compile/Token.h"
#include "alinous.web.parse.htmlxml/JavaCharStream.h"
#include "alinous.web.parse.htmlxml/HtmlXmlParserConstants.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.web.htmlxml.inner/IHtmlStringPart.h"
#include "alinous.web.htmlxml/AbstractXHtmlElement.h"
#include "alinous.web.htmlxml/XHtmlAttribute.h"
#include "alinous.web.htmlxml/XMLTagBase.h"
#include "alinous.web.htmlxml.module/SerializeContext.h"
#include "alinous.web.htmlxml/AbstractXHtmlAttributeValue.h"
#include "alinous.web.htmlxml/BodyText.h"
#include "alinous.web.htmlxml/HtmlDocType.h"
#include "alinous.web.htmlxml/HtmlTopObject.h"
#include "alinous.web.htmlxml/XHtmlComment.h"
#include "alinous.web.htmlxml/XHtmlDqString.h"
#include "alinous.web.htmlxml/XHtmlSQString.h"
#include "alinous.web.parse.htmlxml/HtmlXmlParserTokenManager.h"
#include "alinous.compile/JavaCharStream.h"
#include "alinous.compile/TokenMgrError.h"
#include "alinous.web.parse.htmlxml/HtmlXmlParser.h"
#include "alinous.compile/ParseException.h"

namespace alinous {namespace web {namespace parse {namespace htmlxml {




constexpr const long long HtmlXmlParserConstants::EOF;
constexpr const long long HtmlXmlParserConstants::br;
constexpr const long long HtmlXmlParserConstants::img;
constexpr const long long HtmlXmlParserConstants::link;
constexpr const long long HtmlXmlParserConstants::meta;
constexpr const long long HtmlXmlParserConstants::col;
constexpr const long long HtmlXmlParserConstants::param;
constexpr const long long HtmlXmlParserConstants::base;
constexpr const long long HtmlXmlParserConstants::area;
constexpr const long long HtmlXmlParserConstants::hr;
constexpr const long long HtmlXmlParserConstants::input;
constexpr const long long HtmlXmlParserConstants::GT;
constexpr const long long HtmlXmlParserConstants::LT;
constexpr const long long HtmlXmlParserConstants::LT_SLASH;
constexpr const long long HtmlXmlParserConstants::GT_SLASH;
constexpr const long long HtmlXmlParserConstants::EQUALS;
constexpr const long long HtmlXmlParserConstants::CDATA_START;
constexpr const long long HtmlXmlParserConstants::CDATA_END;
constexpr const long long HtmlXmlParserConstants::XML_HEADER_START;
constexpr const long long HtmlXmlParserConstants::XML_HEADER_END;
constexpr const long long HtmlXmlParserConstants::DOCTYPE;
constexpr const long long HtmlXmlParserConstants::COM_START;
constexpr const long long HtmlXmlParserConstants::COMMENT;
constexpr const long long HtmlXmlParserConstants::WHITE_SPACE;
constexpr const long long HtmlXmlParserConstants::STRING_LITERAL;
constexpr const long long HtmlXmlParserConstants::SQ_STRING_LITERAL;
constexpr const long long HtmlXmlParserConstants::IDENTIFIER_BASE;
constexpr const long long HtmlXmlParserConstants::IDENTIFIER;
constexpr const long long HtmlXmlParserConstants::HTML_BODY_STRING;
constexpr const long long HtmlXmlParserConstants::DEFAULT;
constexpr const long long HtmlXmlParserConstants::COMM;
const StaticArrayObject<UnicodeStringWrapper> HtmlXmlParserConstants::__tokenImage = {ConstStr::getCNST_STR_1332(), ConstStr::getCNST_STR_1842(), ConstStr::getCNST_STR_1843(), ConstStr::getCNST_STR_1844(), ConstStr::getCNST_STR_1845(), ConstStr::getCNST_STR_1846(), ConstStr::getCNST_STR_1847(), ConstStr::getCNST_STR_1848(), ConstStr::getCNST_STR_1849(), ConstStr::getCNST_STR_1850(), ConstStr::getCNST_STR_1851(), ConstStr::getCNST_STR_1379(), ConstStr::getCNST_STR_1381(), ConstStr::getCNST_STR_1852(), ConstStr::getCNST_STR_1853(), ConstStr::getCNST_STR_1354(), ConstStr::getCNST_STR_1854(), ConstStr::getCNST_STR_1855(), ConstStr::getCNST_STR_1856(), ConstStr::getCNST_STR_1857(), ConstStr::getCNST_STR_1858(), ConstStr::getCNST_STR_1859(), ConstStr::getCNST_STR_1860(), ConstStr::getCNST_STR_1861(), ConstStr::getCNST_STR_1862(), ConstStr::getCNST_STR_1350(), ConstStr::getCNST_STR_1863(), ConstStr::getCNST_STR_1864(), ConstStr::getCNST_STR_1524(), ConstStr::getCNST_STR_1865(), ConstStr::getCNST_STR_1797(), ConstStr::getCNST_STR_1798()};
IArrayObject<String>* HtmlXmlParserConstants::tokenImage = (IArrayObject<String>*)const_cast<StaticArrayObject<UnicodeStringWrapper>*>(&__tokenImage);
bool HtmlXmlParserConstants::__init_done = __init_static_variables();
bool HtmlXmlParserConstants::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"HtmlXmlParserConstants", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 HtmlXmlParserConstants::HtmlXmlParserConstants(ThreadContext* ctx) throw()  : IObject(ctx)
{
}
void HtmlXmlParserConstants::__construct_impl(ThreadContext* ctx) throw() 
{
}
 HtmlXmlParserConstants::~HtmlXmlParserConstants() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void HtmlXmlParserConstants::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
void HtmlXmlParserConstants::__cleanUp(ThreadContext* ctx){
}
}}}}

