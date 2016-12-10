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
const StaticArrayObject<UnicodeStringWrapper> AlinousXpathParserConstants::__tokenImage = {ConstStr::getCNST_STR_1252(), ConstStr::getCNST_STR_1253(), ConstStr::getCNST_STR_1254(), ConstStr::getCNST_STR_1255(), ConstStr::getCNST_STR_1256(), ConstStr::getCNST_STR_1257(), ConstStr::getCNST_STR_1258(), ConstStr::getCNST_STR_1259(), ConstStr::getCNST_STR_1260(), ConstStr::getCNST_STR_1273(), ConstStr::getCNST_STR_1274(), ConstStr::getCNST_STR_1275(), ConstStr::getCNST_STR_1276(), ConstStr::getCNST_STR_1277(), ConstStr::getCNST_STR_1278(), ConstStr::getCNST_STR_1279(), ConstStr::getCNST_STR_1280(), ConstStr::getCNST_STR_1281(), ConstStr::getCNST_STR_1282(), ConstStr::getCNST_STR_1283(), ConstStr::getCNST_STR_1284(), ConstStr::getCNST_STR_1285(), ConstStr::getCNST_STR_1286(), ConstStr::getCNST_STR_1287(), ConstStr::getCNST_STR_1288(), ConstStr::getCNST_STR_1289(), ConstStr::getCNST_STR_1290(), ConstStr::getCNST_STR_1291(), ConstStr::getCNST_STR_1292(), ConstStr::getCNST_STR_1458(), ConstStr::getCNST_STR_1293(), ConstStr::getCNST_STR_1294(), ConstStr::getCNST_STR_1295(), ConstStr::getCNST_STR_1296(), ConstStr::getCNST_STR_1297(), ConstStr::getCNST_STR_1298(), ConstStr::getCNST_STR_1299(), ConstStr::getCNST_STR_1300(), ConstStr::getCNST_STR_1301(), ConstStr::getCNST_STR_1302(), ConstStr::getCNST_STR_1303(), ConstStr::getCNST_STR_1304(), ConstStr::getCNST_STR_1692(), ConstStr::getCNST_STR_1693(), ConstStr::getCNST_STR_1694(), ConstStr::getCNST_STR_1438(), ConstStr::getCNST_STR_1695(), ConstStr::getCNST_STR_1696(), ConstStr::getCNST_STR_1697(), ConstStr::getCNST_STR_1698(), ConstStr::getCNST_STR_1697(), ConstStr::getCNST_STR_1699(), ConstStr::getCNST_STR_1700(), ConstStr::getCNST_STR_1701(), ConstStr::getCNST_STR_1698(), ConstStr::getCNST_STR_1702(), ConstStr::getCNST_STR_1699(), ConstStr::getCNST_STR_1703(), ConstStr::getCNST_STR_1704()};
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

