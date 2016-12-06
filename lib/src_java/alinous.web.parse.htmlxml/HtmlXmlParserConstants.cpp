#include "includes.h"


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
const StaticArrayObject<UnicodeStringWrapper> HtmlXmlParserConstants::__tokenImage = {ConstStr::getCNST_STR_1233(), ConstStr::getCNST_STR_1723(), ConstStr::getCNST_STR_1724(), ConstStr::getCNST_STR_1725(), ConstStr::getCNST_STR_1726(), ConstStr::getCNST_STR_1727(), ConstStr::getCNST_STR_1728(), ConstStr::getCNST_STR_1729(), ConstStr::getCNST_STR_1730(), ConstStr::getCNST_STR_1731(), ConstStr::getCNST_STR_1732(), ConstStr::getCNST_STR_1280(), ConstStr::getCNST_STR_1282(), ConstStr::getCNST_STR_1733(), ConstStr::getCNST_STR_1734(), ConstStr::getCNST_STR_1255(), ConstStr::getCNST_STR_1735(), ConstStr::getCNST_STR_1736(), ConstStr::getCNST_STR_1737(), ConstStr::getCNST_STR_1738(), ConstStr::getCNST_STR_1739(), ConstStr::getCNST_STR_1740(), ConstStr::getCNST_STR_1741(), ConstStr::getCNST_STR_1742(), ConstStr::getCNST_STR_1743(), ConstStr::getCNST_STR_1251(), ConstStr::getCNST_STR_1744(), ConstStr::getCNST_STR_1745(), ConstStr::getCNST_STR_1419(), ConstStr::getCNST_STR_1746(), ConstStr::getCNST_STR_1678(), ConstStr::getCNST_STR_1679()};
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
}}}}

