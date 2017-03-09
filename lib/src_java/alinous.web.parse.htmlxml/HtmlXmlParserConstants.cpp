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
const StaticArrayObject<UnicodeStringWrapper> HtmlXmlParserConstants::__tokenImage = {ConstStr::getCNST_STR_1336(), ConstStr::getCNST_STR_1812(), ConstStr::getCNST_STR_1813(), ConstStr::getCNST_STR_1814(), ConstStr::getCNST_STR_1815(), ConstStr::getCNST_STR_1816(), ConstStr::getCNST_STR_1817(), ConstStr::getCNST_STR_1818(), ConstStr::getCNST_STR_1819(), ConstStr::getCNST_STR_1820(), ConstStr::getCNST_STR_1821(), ConstStr::getCNST_STR_1383(), ConstStr::getCNST_STR_1385(), ConstStr::getCNST_STR_1822(), ConstStr::getCNST_STR_1823(), ConstStr::getCNST_STR_1358(), ConstStr::getCNST_STR_1824(), ConstStr::getCNST_STR_1825(), ConstStr::getCNST_STR_1826(), ConstStr::getCNST_STR_1827(), ConstStr::getCNST_STR_1828(), ConstStr::getCNST_STR_1829(), ConstStr::getCNST_STR_1830(), ConstStr::getCNST_STR_1831(), ConstStr::getCNST_STR_1832(), ConstStr::getCNST_STR_1354(), ConstStr::getCNST_STR_1833(), ConstStr::getCNST_STR_1834(), ConstStr::getCNST_STR_1528(), ConstStr::getCNST_STR_1835(), ConstStr::getCNST_STR_1771(), ConstStr::getCNST_STR_1772()};
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

