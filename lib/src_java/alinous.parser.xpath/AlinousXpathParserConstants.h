#ifndef ALINOUS_PARSER_XPATH_ALINOUSXPATHPARSERCONSTANTS_H_
#define ALINOUS_PARSER_XPATH_ALINOUSXPATHPARSERCONSTANTS_H_
namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace parser {namespace xpath {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;



class AlinousXpathParserConstants : public virtual IObject {
public:
	AlinousXpathParserConstants(const AlinousXpathParserConstants& base) = default;
public:
	AlinousXpathParserConstants(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~AlinousXpathParserConstants() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	constexpr static const long long EOF{0};
	constexpr static const long long NOTASCII{5};
	constexpr static const long long ASCILETTER{6};
	constexpr static const long long NUMBERLETTER{7};
	constexpr static const long long CHARACTOR{8};
	constexpr static const long long SEMI_COLON{9};
	constexpr static const long long EQUALS{10};
	constexpr static const long long ASTERISK{11};
	constexpr static const long long PLUSPLUS{12};
	constexpr static const long long PLUS{13};
	constexpr static const long long MINUSMINUS{14};
	constexpr static const long long MINUS{15};
	constexpr static const long long DIV{16};
	constexpr static const long long MODULO{17};
	constexpr static const long long LOGICAL_AND{18};
	constexpr static const long long LOGICAL_OR{19};
	constexpr static const long long BIT_AND{20};
	constexpr static const long long BIT_OR{21};
	constexpr static const long long L_PARENTHESIS{22};
	constexpr static const long long R_PARENTHESIS{23};
	constexpr static const long long L_BRACKET{24};
	constexpr static const long long R_BRACKET{25};
	constexpr static const long long DOLLAR{26};
	constexpr static const long long DOT{27};
	constexpr static const long long COMMA{28};
	constexpr static const long long SQL_NOT_EQUALS{29};
	constexpr static const long long AT_AT_MARK{30};
	constexpr static const long long AT_MARK{31};
	constexpr static const long long L_BRACE{32};
	constexpr static const long long R_BRACE{33};
	constexpr static const long long CMP_EQUALS{34};
	constexpr static const long long CMP_NOTEQUALS{35};
	constexpr static const long long GT{36};
	constexpr static const long long GEQ{37};
	constexpr static const long long LT{38};
	constexpr static const long long LEQ{39};
	constexpr static const long long NOT{40};
	constexpr static const long long COLON{41};
	constexpr static const long long XPATH_AND{42};
	constexpr static const long long XPATH_OR{43};
	constexpr static const long long NOT_LIT{44};
	constexpr static const long long IDENTIFIER{45};
	constexpr static const long long NUMERIC{46};
	constexpr static const long long DOUBLE{47};
	constexpr static const long long DQSTRLIT{50};
	constexpr static const long long SQSTRLIT{54};
	constexpr static const long long DEFAULT{0};
	constexpr static const long long SQ_STR{1};
	constexpr static const long long DQ_STR{2};
	static const StaticArrayObject<UnicodeStringWrapper> __tokenImage;
	static IArrayObject<String>* tokenImage;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_PARSER_XPATH_ALINOUSXPATHPARSERCONSTANTS_H_ */
