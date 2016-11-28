#include "includes.h"


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
const StaticArrayObject<UnicodeStringWrapper> AlinousXpathParserConstants::__tokenImage = {ConstStr::getCNST_STR_1222(), ConstStr::getCNST_STR_1223(), ConstStr::getCNST_STR_1224(), ConstStr::getCNST_STR_1225(), ConstStr::getCNST_STR_1226(), ConstStr::getCNST_STR_1227(), ConstStr::getCNST_STR_1228(), ConstStr::getCNST_STR_1229(), ConstStr::getCNST_STR_1230(), ConstStr::getCNST_STR_1243(), ConstStr::getCNST_STR_1244(), ConstStr::getCNST_STR_1245(), ConstStr::getCNST_STR_1246(), ConstStr::getCNST_STR_1247(), ConstStr::getCNST_STR_1248(), ConstStr::getCNST_STR_1249(), ConstStr::getCNST_STR_1250(), ConstStr::getCNST_STR_1251(), ConstStr::getCNST_STR_1252(), ConstStr::getCNST_STR_1253(), ConstStr::getCNST_STR_1254(), ConstStr::getCNST_STR_1255(), ConstStr::getCNST_STR_1256(), ConstStr::getCNST_STR_1257(), ConstStr::getCNST_STR_1258(), ConstStr::getCNST_STR_1259(), ConstStr::getCNST_STR_1260(), ConstStr::getCNST_STR_1261(), ConstStr::getCNST_STR_1262(), ConstStr::getCNST_STR_1428(), ConstStr::getCNST_STR_1263(), ConstStr::getCNST_STR_1264(), ConstStr::getCNST_STR_1265(), ConstStr::getCNST_STR_1266(), ConstStr::getCNST_STR_1267(), ConstStr::getCNST_STR_1268(), ConstStr::getCNST_STR_1269(), ConstStr::getCNST_STR_1270(), ConstStr::getCNST_STR_1271(), ConstStr::getCNST_STR_1272(), ConstStr::getCNST_STR_1273(), ConstStr::getCNST_STR_1274(), ConstStr::getCNST_STR_1662(), ConstStr::getCNST_STR_1663(), ConstStr::getCNST_STR_1664(), ConstStr::getCNST_STR_1408(), ConstStr::getCNST_STR_1665(), ConstStr::getCNST_STR_1666(), ConstStr::getCNST_STR_1667(), ConstStr::getCNST_STR_1668(), ConstStr::getCNST_STR_1667(), ConstStr::getCNST_STR_1669(), ConstStr::getCNST_STR_1670(), ConstStr::getCNST_STR_1671(), ConstStr::getCNST_STR_1668(), ConstStr::getCNST_STR_1672(), ConstStr::getCNST_STR_1669(), ConstStr::getCNST_STR_1673(), ConstStr::getCNST_STR_1674()};
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
}}}

