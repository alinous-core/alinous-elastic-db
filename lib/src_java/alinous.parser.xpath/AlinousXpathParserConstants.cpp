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
const StaticArrayObject<UnicodeStringWrapper> AlinousXpathParserConstants::__tokenImage = {ConstStr::getCNST_STR_1261(), ConstStr::getCNST_STR_1262(), ConstStr::getCNST_STR_1263(), ConstStr::getCNST_STR_1264(), ConstStr::getCNST_STR_1265(), ConstStr::getCNST_STR_1266(), ConstStr::getCNST_STR_1267(), ConstStr::getCNST_STR_1268(), ConstStr::getCNST_STR_1269(), ConstStr::getCNST_STR_1282(), ConstStr::getCNST_STR_1283(), ConstStr::getCNST_STR_1284(), ConstStr::getCNST_STR_1285(), ConstStr::getCNST_STR_1286(), ConstStr::getCNST_STR_1287(), ConstStr::getCNST_STR_1288(), ConstStr::getCNST_STR_1289(), ConstStr::getCNST_STR_1290(), ConstStr::getCNST_STR_1291(), ConstStr::getCNST_STR_1292(), ConstStr::getCNST_STR_1293(), ConstStr::getCNST_STR_1294(), ConstStr::getCNST_STR_1295(), ConstStr::getCNST_STR_1296(), ConstStr::getCNST_STR_1297(), ConstStr::getCNST_STR_1298(), ConstStr::getCNST_STR_1299(), ConstStr::getCNST_STR_1300(), ConstStr::getCNST_STR_1301(), ConstStr::getCNST_STR_1467(), ConstStr::getCNST_STR_1302(), ConstStr::getCNST_STR_1303(), ConstStr::getCNST_STR_1304(), ConstStr::getCNST_STR_1305(), ConstStr::getCNST_STR_1306(), ConstStr::getCNST_STR_1307(), ConstStr::getCNST_STR_1308(), ConstStr::getCNST_STR_1309(), ConstStr::getCNST_STR_1310(), ConstStr::getCNST_STR_1311(), ConstStr::getCNST_STR_1312(), ConstStr::getCNST_STR_1313(), ConstStr::getCNST_STR_1702(), ConstStr::getCNST_STR_1703(), ConstStr::getCNST_STR_1704(), ConstStr::getCNST_STR_1447(), ConstStr::getCNST_STR_1705(), ConstStr::getCNST_STR_1706(), ConstStr::getCNST_STR_1707(), ConstStr::getCNST_STR_1708(), ConstStr::getCNST_STR_1707(), ConstStr::getCNST_STR_1709(), ConstStr::getCNST_STR_1710(), ConstStr::getCNST_STR_1711(), ConstStr::getCNST_STR_1708(), ConstStr::getCNST_STR_1712(), ConstStr::getCNST_STR_1709(), ConstStr::getCNST_STR_1713(), ConstStr::getCNST_STR_1714()};
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

