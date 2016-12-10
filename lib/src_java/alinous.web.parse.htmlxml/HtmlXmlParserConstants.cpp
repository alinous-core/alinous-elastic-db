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
const StaticArrayObject<UnicodeStringWrapper> HtmlXmlParserConstants::__tokenImage = {ConstStr::getCNST_STR_1252(), ConstStr::getCNST_STR_1742(), ConstStr::getCNST_STR_1743(), ConstStr::getCNST_STR_1744(), ConstStr::getCNST_STR_1745(), ConstStr::getCNST_STR_1746(), ConstStr::getCNST_STR_1747(), ConstStr::getCNST_STR_1748(), ConstStr::getCNST_STR_1749(), ConstStr::getCNST_STR_1750(), ConstStr::getCNST_STR_1751(), ConstStr::getCNST_STR_1299(), ConstStr::getCNST_STR_1301(), ConstStr::getCNST_STR_1752(), ConstStr::getCNST_STR_1753(), ConstStr::getCNST_STR_1274(), ConstStr::getCNST_STR_1754(), ConstStr::getCNST_STR_1755(), ConstStr::getCNST_STR_1756(), ConstStr::getCNST_STR_1757(), ConstStr::getCNST_STR_1758(), ConstStr::getCNST_STR_1759(), ConstStr::getCNST_STR_1760(), ConstStr::getCNST_STR_1761(), ConstStr::getCNST_STR_1762(), ConstStr::getCNST_STR_1270(), ConstStr::getCNST_STR_1763(), ConstStr::getCNST_STR_1764(), ConstStr::getCNST_STR_1438(), ConstStr::getCNST_STR_1765(), ConstStr::getCNST_STR_1697(), ConstStr::getCNST_STR_1698()};
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

