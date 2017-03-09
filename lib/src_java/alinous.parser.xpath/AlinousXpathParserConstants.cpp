#include "include/global.h"


#include "alinous.parser.xpath/TokenMgrError.h"
#include "alinous.html.xpath/IVariableValue.h"
#include "alinous.html/IDomObject.h"
#include "alinous.html/Attribute.h"
#include "alinous.html/DomNode.h"
#include "alinous.html/DomDocument.h"
#include "alinous.html.xpath/IXpathElement.h"
#include "alinous.html.xpath/IXpathStatement.h"
#include "alinous.html.xpath/XpathIdentifier.h"
#include "alinous.html.xpath/AttributeIdentifier.h"
#include "alinous.html.xpath/IXpathBooleanCondition.h"
#include "alinous.html.xpath/XpathReference.h"
#include "alinous.html.xpath/Xpath2Compare.h"
#include "alinous.html.xpath/XpathNumber.h"
#include "alinous.html.xpath/XpathFunctionArgument.h"
#include "alinous.html.xpath/XpathFunction.h"
#include "alinous.html.xpath/XpathFilter.h"
#include "alinous.html.xpath/XpathContextLocationCtrl.h"
#include "alinous.html.xpath/XpathContextLocation.h"
#include "alinous.html.xpath/XpathContext.h"
#include "alinous.html.xpath/Xpath.h"
#include "alinous.html.xpath/AbstractContainerStatement.h"
#include "alinous.html.xpath/XpathAndStatement.h"
#include "alinous.html.xpath/XpathNotStatement.h"
#include "alinous.html.xpath/XpathOrStatement.h"
#include "alinous.html.xpath/XpathString.h"
#include "alinous.parser.xpath/Token.h"
#include "alinous.parser.xpath/ParseException.h"
#include "alinous.parser.xpath/JavaCharStream.h"
#include "alinous.parser.xpath/AlinousXpathParserConstants.h"
#include "alinous.parser.xpath/AlinousXpathParserTokenManager.h"
#include "alinous.parser.xpath/AlinousXpathParser.h"
#include "alinous.compile/JavaCharStream.h"
#include "alinous.compile/Token.h"
#include "alinous.compile/ParseException.h"

namespace alinous {namespace parser {namespace xpath {




constexpr const long long AlinousXpathParserConstants::EOF;
constexpr const long long AlinousXpathParserConstants::NOTASCII;
constexpr const long long AlinousXpathParserConstants::ASCILETTER;
constexpr const long long AlinousXpathParserConstants::NUMBERLETTER;
constexpr const long long AlinousXpathParserConstants::CHARACTOR;
constexpr const long long AlinousXpathParserConstants::SEMI_COLON;
constexpr const long long AlinousXpathParserConstants::EQUALS;
constexpr const long long AlinousXpathParserConstants::ASTERISK;
constexpr const long long AlinousXpathParserConstants::PLUSPLUS;
constexpr const long long AlinousXpathParserConstants::PLUS;
constexpr const long long AlinousXpathParserConstants::MINUSMINUS;
constexpr const long long AlinousXpathParserConstants::MINUS;
constexpr const long long AlinousXpathParserConstants::DIV;
constexpr const long long AlinousXpathParserConstants::MODULO;
constexpr const long long AlinousXpathParserConstants::LOGICAL_AND;
constexpr const long long AlinousXpathParserConstants::LOGICAL_OR;
constexpr const long long AlinousXpathParserConstants::BIT_AND;
constexpr const long long AlinousXpathParserConstants::BIT_OR;
constexpr const long long AlinousXpathParserConstants::L_PARENTHESIS;
constexpr const long long AlinousXpathParserConstants::R_PARENTHESIS;
constexpr const long long AlinousXpathParserConstants::L_BRACKET;
constexpr const long long AlinousXpathParserConstants::R_BRACKET;
constexpr const long long AlinousXpathParserConstants::DOLLAR;
constexpr const long long AlinousXpathParserConstants::DOT;
constexpr const long long AlinousXpathParserConstants::COMMA;
constexpr const long long AlinousXpathParserConstants::SQL_NOT_EQUALS;
constexpr const long long AlinousXpathParserConstants::AT_AT_MARK;
constexpr const long long AlinousXpathParserConstants::AT_MARK;
constexpr const long long AlinousXpathParserConstants::L_BRACE;
constexpr const long long AlinousXpathParserConstants::R_BRACE;
constexpr const long long AlinousXpathParserConstants::CMP_EQUALS;
constexpr const long long AlinousXpathParserConstants::CMP_NOTEQUALS;
constexpr const long long AlinousXpathParserConstants::GT;
constexpr const long long AlinousXpathParserConstants::GEQ;
constexpr const long long AlinousXpathParserConstants::LT;
constexpr const long long AlinousXpathParserConstants::LEQ;
constexpr const long long AlinousXpathParserConstants::NOT;
constexpr const long long AlinousXpathParserConstants::COLON;
constexpr const long long AlinousXpathParserConstants::XPATH_AND;
constexpr const long long AlinousXpathParserConstants::XPATH_OR;
constexpr const long long AlinousXpathParserConstants::NOT_LIT;
constexpr const long long AlinousXpathParserConstants::IDENTIFIER;
constexpr const long long AlinousXpathParserConstants::NUMERIC;
constexpr const long long AlinousXpathParserConstants::DOUBLE;
constexpr const long long AlinousXpathParserConstants::DQSTRLIT;
constexpr const long long AlinousXpathParserConstants::SQSTRLIT;
constexpr const long long AlinousXpathParserConstants::DEFAULT;
constexpr const long long AlinousXpathParserConstants::SQ_STR;
constexpr const long long AlinousXpathParserConstants::DQ_STR;
const StaticArrayObject<UnicodeStringWrapper> AlinousXpathParserConstants::__tokenImage = {ConstStr::getCNST_STR_1336(), ConstStr::getCNST_STR_1337(), ConstStr::getCNST_STR_1338(), ConstStr::getCNST_STR_1339(), ConstStr::getCNST_STR_1340(), ConstStr::getCNST_STR_1341(), ConstStr::getCNST_STR_1342(), ConstStr::getCNST_STR_1343(), ConstStr::getCNST_STR_1344(), ConstStr::getCNST_STR_1357(), ConstStr::getCNST_STR_1358(), ConstStr::getCNST_STR_1359(), ConstStr::getCNST_STR_1360(), ConstStr::getCNST_STR_1361(), ConstStr::getCNST_STR_1362(), ConstStr::getCNST_STR_1363(), ConstStr::getCNST_STR_1364(), ConstStr::getCNST_STR_1365(), ConstStr::getCNST_STR_1366(), ConstStr::getCNST_STR_1367(), ConstStr::getCNST_STR_1368(), ConstStr::getCNST_STR_1369(), ConstStr::getCNST_STR_1370(), ConstStr::getCNST_STR_1371(), ConstStr::getCNST_STR_1372(), ConstStr::getCNST_STR_1373(), ConstStr::getCNST_STR_1374(), ConstStr::getCNST_STR_1375(), ConstStr::getCNST_STR_1376(), ConstStr::getCNST_STR_1548(), ConstStr::getCNST_STR_1377(), ConstStr::getCNST_STR_1378(), ConstStr::getCNST_STR_1379(), ConstStr::getCNST_STR_1380(), ConstStr::getCNST_STR_1381(), ConstStr::getCNST_STR_1382(), ConstStr::getCNST_STR_1383(), ConstStr::getCNST_STR_1384(), ConstStr::getCNST_STR_1385(), ConstStr::getCNST_STR_1386(), ConstStr::getCNST_STR_1387(), ConstStr::getCNST_STR_1388(), ConstStr::getCNST_STR_1766(), ConstStr::getCNST_STR_1767(), ConstStr::getCNST_STR_1768(), ConstStr::getCNST_STR_1528(), ConstStr::getCNST_STR_1769(), ConstStr::getCNST_STR_1770(), ConstStr::getCNST_STR_1771(), ConstStr::getCNST_STR_1772(), ConstStr::getCNST_STR_1771(), ConstStr::getCNST_STR_1773(), ConstStr::getCNST_STR_1774(), ConstStr::getCNST_STR_1775(), ConstStr::getCNST_STR_1772(), ConstStr::getCNST_STR_1776(), ConstStr::getCNST_STR_1773(), ConstStr::getCNST_STR_1777(), ConstStr::getCNST_STR_1778()};
IArrayObject<String>* AlinousXpathParserConstants::tokenImage = (IArrayObject<String>*)const_cast<StaticArrayObject<UnicodeStringWrapper>*>(&__tokenImage);
bool AlinousXpathParserConstants::__init_done = __init_static_variables();
bool AlinousXpathParserConstants::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AlinousXpathParserConstants", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AlinousXpathParserConstants::AlinousXpathParserConstants(ThreadContext* ctx) throw()  : IObject(ctx)
{
}
void AlinousXpathParserConstants::__construct_impl(ThreadContext* ctx) throw() 
{
}
 AlinousXpathParserConstants::~AlinousXpathParserConstants() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AlinousXpathParserConstants::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
void AlinousXpathParserConstants::__cleanUp(ThreadContext* ctx){
}
}}}

