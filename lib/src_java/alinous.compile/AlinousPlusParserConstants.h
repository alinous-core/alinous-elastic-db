#ifndef ALINOUS_COMPILE_ALINOUSPLUSPARSERCONSTANTS_H_
#define ALINOUS_COMPILE_ALINOUSPLUSPARSERCONSTANTS_H_
namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace compile {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;



class AlinousPlusParserConstants : public virtual IObject {
public:
	AlinousPlusParserConstants(const AlinousPlusParserConstants& base) = default;
public:
	AlinousPlusParserConstants(ThreadContext* ctx) throw()  : IObject(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~AlinousPlusParserConstants() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	constexpr static const long long EOF{0};
	constexpr static const long long NOTASCII{5};
	constexpr static const long long ASCILETTER{6};
	constexpr static const long long NUMBERLETTER{7};
	constexpr static const long long CHARACTOR{8};
	constexpr static const long long INTEGER_LITERAL{9};
	constexpr static const long long DECIMAL_LITERAL{10};
	constexpr static const long long HEX_LITERAL{11};
	constexpr static const long long OCTAL_LITERAL{12};
	constexpr static const long long FLOATING_POINT_LITERAL{13};
	constexpr static const long long DECIMAL_FLOATING_POINT_LITERAL{14};
	constexpr static const long long DECIMAL_EXPONENT{15};
	constexpr static const long long HEXADECIMAL_FLOATING_POINT_LITERAL{16};
	constexpr static const long long HEXADECIMAL_EXPONENT{17};
	constexpr static const long long STRING_LITERAL{18};
	constexpr static const long long CHARACTER_LITERAL{19};
	constexpr static const long long SQL_STRING_LITERAL{20};
	constexpr static const long long SEMI_COLON{21};
	constexpr static const long long EQUALS{22};
	constexpr static const long long ASTERISK{23};
	constexpr static const long long PLUSPLUS{24};
	constexpr static const long long PLUS{25};
	constexpr static const long long MINUSMINUS{26};
	constexpr static const long long MINUS{27};
	constexpr static const long long DIV{28};
	constexpr static const long long MODULO{29};
	constexpr static const long long LOGICAL_AND{30};
	constexpr static const long long LOGICAL_OR{31};
	constexpr static const long long BIT_AND{32};
	constexpr static const long long BIT_OR{33};
	constexpr static const long long L_PARENTHESIS{34};
	constexpr static const long long R_PARENTHESIS{35};
	constexpr static const long long L_BRACKET{36};
	constexpr static const long long R_BRACKET{37};
	constexpr static const long long DOLLAR{38};
	constexpr static const long long DOT{39};
	constexpr static const long long COMMA{40};
	constexpr static const long long AT_AT_MARK{41};
	constexpr static const long long AT_MARK{42};
	constexpr static const long long L_BRACE{43};
	constexpr static const long long R_BRACE{44};
	constexpr static const long long CMP_EQUALS{45};
	constexpr static const long long CMP_NOTEQUALS{46};
	constexpr static const long long GT{47};
	constexpr static const long long GEQ{48};
	constexpr static const long long LT{49};
	constexpr static const long long LEQ{50};
	constexpr static const long long NOT{51};
	constexpr static const long long COLON{52};
	constexpr static const long long RSIGNEDSHIFT{53};
	constexpr static const long long RUNSIGNEDSHIFT{54};
	constexpr static const long long IMPORT{55};
	constexpr static const long long PACKAGE{56};
	constexpr static const long long CLASS{57};
	constexpr static const long long CLASS_INTERFACE{58};
	constexpr static const long long ABSTRACT{59};
	constexpr static const long long BREAK{60};
	constexpr static const long long BYTE{61};
	constexpr static const long long CASE{62};
	constexpr static const long long CATCH{63};
	constexpr static const long long _CONST{64};
	constexpr static const long long CONTINUE{65};
	constexpr static const long long DO{66};
	constexpr static const long long ELSE{67};
	constexpr static const long long ENUM{68};
	constexpr static const long long EXTENDS{69};
	constexpr static const long long FINAL{70};
	constexpr static const long long FINALLY{71};
	constexpr static const long long FOR{72};
	constexpr static const long long GOTO{73};
	constexpr static const long long IF{74};
	constexpr static const long long IMPLEMENTS{75};
	constexpr static const long long INSTANCEOF{76};
	constexpr static const long long NATIVE{77};
	constexpr static const long long NEW{78};
	constexpr static const long long PRIVATE{79};
	constexpr static const long long PROTECTED{80};
	constexpr static const long long PUBLIC{81};
	constexpr static const long long RETURN{82};
	constexpr static const long long STATIC{83};
	constexpr static const long long SUPER{84};
	constexpr static const long long SWITCH{85};
	constexpr static const long long SYNCHRONIZED{86};
	constexpr static const long long THIS{87};
	constexpr static const long long THROW{88};
	constexpr static const long long THROWS{89};
	constexpr static const long long TRY{90};
	constexpr static const long long VOID{91};
	constexpr static const long long WHILE{92};
	constexpr static const long long INCLUDE{93};
	constexpr static const long long DOWNLOAD{94};
	constexpr static const long long REDIRECT{95};
	constexpr static const long long REFERER_FROM{96};
	constexpr static const long long VALIDATOR{97};
	constexpr static const long long PARALLEL{98};
	constexpr static const long long LOCAL{99};
	constexpr static const long long TRUE{100};
	constexpr static const long long FALSE{101};
	constexpr static const long long SELECT{102};
	constexpr static const long long INSERT{103};
	constexpr static const long long UPDATE{104};
	constexpr static const long long DELETE{105};
	constexpr static const long long INTO{106};
	constexpr static const long long FROM{107};
	constexpr static const long long WHERE{108};
	constexpr static const long long OR{109};
	constexpr static const long long SQLAND{110};
	constexpr static const long long LIKE{111};
	constexpr static const long long ESCAPE{112};
	constexpr static const long long LEFT{113};
	constexpr static const long long RIGHT{114};
	constexpr static const long long NATURAL{115};
	constexpr static const long long INNER{116};
	constexpr static const long long OUTER{117};
	constexpr static const long long FULL{118};
	constexpr static const long long JOIN{119};
	constexpr static const long long CROSS{120};
	constexpr static const long long SET{121};
	constexpr static const long long VALUES{122};
	constexpr static const long long GROUP{123};
	constexpr static const long long BY{124};
	constexpr static const long long HAVING{125};
	constexpr static const long long ORDER{126};
	constexpr static const long long ASC{127};
	constexpr static const long long DESC{128};
	constexpr static const long long LIMIT{129};
	constexpr static const long long OFFSET{130};
	constexpr static const long long ON{131};
	constexpr static const long long SQL_NOT{132};
	constexpr static const long long AS{133};
	constexpr static const long long DISTINCT{134};
	constexpr static const long long SHARE{135};
	constexpr static const long long NOWAIT{136};
	constexpr static const long long OF{137};
	constexpr static const long long IN{138};
	constexpr static const long long BETWEEN{139};
	constexpr static const long long IS{140};
	constexpr static const long long BEGIN{141};
	constexpr static const long long PREPARE{142};
	constexpr static const long long TRANSACTION{143};
	constexpr static const long long ISOLATION{144};
	constexpr static const long long LEVEL{145};
	constexpr static const long long COMMIT{146};
	constexpr static const long long PREPARED{147};
	constexpr static const long long END{148};
	constexpr static const long long ROLLBACK{149};
	constexpr static const long long CREATE{150};
	constexpr static const long long DROP{151};
	constexpr static const long long ALTER{152};
	constexpr static const long long TABLE{153};
	constexpr static const long long SQL_DEFAULT{154};
	constexpr static const long long ADD{155};
	constexpr static const long long RENAME{156};
	constexpr static const long long COLUMN{157};
	constexpr static const long long TO{158};
	constexpr static const long long PRIMARY{159};
	constexpr static const long long KEY{160};
	constexpr static const long long UNIQUE{161};
	constexpr static const long long CHECK{162};
	constexpr static const long long RETURNS{163};
	constexpr static const long long SETOF{164};
	constexpr static const long long LANGUAGE{165};
	constexpr static const long long REPLACE{166};
	constexpr static const long long INDEX{167};
	constexpr static const long long USING{168};
	constexpr static const long long EACH{169};
	constexpr static const long long ROW{170};
	constexpr static const long long STATEMENT{171};
	constexpr static const long long EXECUTE{172};
	constexpr static const long long PROCEDURE{173};
	constexpr static const long long EXISTS{174};
	constexpr static const long long TRIGGER{175};
	constexpr static const long long BEFORE{176};
	constexpr static const long long AFTER{177};
	constexpr static const long long FOREIGN{178};
	constexpr static const long long REFERENCES{179};
	constexpr static const long long ADJUST_WHERE{180};
	constexpr static const long long ADJUST_SET{181};
	constexpr static const long long BOOL{182};
	constexpr static const long long _NULL{183};
	constexpr static const long long FUNCTION{184};
	constexpr static const long long USE{185};
	constexpr static const long long REGION{186};
	constexpr static const long long SHARD{187};
	constexpr static const long long SUB{188};
	constexpr static const long long IDENTIFIER{189};
	constexpr static const long long DEFAULT{0};
	constexpr static const long long COMM{1};
	constexpr static const long long L_COMM{2};
	static const StaticArrayObject<UnicodeStringWrapper> __tokenImage;
	static IArrayObject<String>* tokenImage;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}

#endif /* end of ALINOUS_COMPILE_ALINOUSPLUSPARSERCONSTANTS_H_ */
