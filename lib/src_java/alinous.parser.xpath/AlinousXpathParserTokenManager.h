#ifndef ALINOUS_PARSER_XPATH_ALINOUSXPATHPARSERTOKENMANAGER_H_
#define ALINOUS_PARSER_XPATH_ALINOUSXPATHPARSERTOKENMANAGER_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace java {namespace io {
class PrintStream;}}

namespace java {namespace io {
class IOException;}}

namespace java {namespace lang {
class Error;}}

namespace alinous {namespace parser {namespace xpath {
class Token;}}}

namespace alinous {namespace parser {namespace xpath {
class TokenMgrError;}}}

namespace alinous {namespace parser {namespace xpath {
class JavaCharStream;}}}

namespace java {namespace lang {
class StringBuilder;}}

namespace alinous {namespace parser {namespace xpath {
class AlinousXpathParserConstants;}}}

namespace alinous {namespace html {namespace xpath {
class AttributeIdentifier;}}}

namespace alinous {namespace html {namespace xpath {
class IXpathBooleanCondition;}}}

namespace alinous {namespace html {namespace xpath {
class IXpathElement;}}}

namespace alinous {namespace html {namespace xpath {
class IXpathStatement;}}}

namespace alinous {namespace html {namespace xpath {
class XPathParser;}}}

namespace alinous {namespace html {namespace xpath {
class Xpath;}}}

namespace alinous {namespace html {namespace xpath {
class Xpath2Compare;}}}

namespace alinous {namespace html {namespace xpath {
class XpathAndStatement;}}}

namespace alinous {namespace html {namespace xpath {
class XpathContext;}}}

namespace alinous {namespace html {namespace xpath {
class XpathContextLocation;}}}

namespace alinous {namespace html {namespace xpath {
class XpathContextLocationCtrl;}}}

namespace alinous {namespace html {namespace xpath {
class XpathFilter;}}}

namespace alinous {namespace html {namespace xpath {
class XpathFunction;}}}

namespace alinous {namespace html {namespace xpath {
class XpathFunctionArgument;}}}

namespace alinous {namespace html {namespace xpath {
class XpathIdentifier;}}}

namespace alinous {namespace html {namespace xpath {
class XpathNotStatement;}}}

namespace alinous {namespace html {namespace xpath {
class XpathNumber;}}}

namespace alinous {namespace html {namespace xpath {
class XpathOrStatement;}}}

namespace alinous {namespace html {namespace xpath {
class XpathReference;}}}

namespace alinous {namespace html {namespace xpath {
class XpathString;}}}

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
using ::alinous::html::xpath::AttributeIdentifier;
using ::alinous::html::xpath::IXpathBooleanCondition;
using ::alinous::html::xpath::IXpathElement;
using ::alinous::html::xpath::IXpathStatement;
using ::alinous::html::xpath::XPathParser;
using ::alinous::html::xpath::Xpath;
using ::alinous::html::xpath::Xpath2Compare;
using ::alinous::html::xpath::XpathAndStatement;
using ::alinous::html::xpath::XpathContext;
using ::alinous::html::xpath::XpathContextLocation;
using ::alinous::html::xpath::XpathContextLocationCtrl;
using ::alinous::html::xpath::XpathFilter;
using ::alinous::html::xpath::XpathFunction;
using ::alinous::html::xpath::XpathFunctionArgument;
using ::alinous::html::xpath::XpathIdentifier;
using ::alinous::html::xpath::XpathNotStatement;
using ::alinous::html::xpath::XpathNumber;
using ::alinous::html::xpath::XpathOrStatement;
using ::alinous::html::xpath::XpathReference;
using ::alinous::html::xpath::XpathString;



class AlinousXpathParserTokenManager final : public AlinousXpathParserConstants, public virtual IObject {
public:
	AlinousXpathParserTokenManager(const AlinousXpathParserTokenManager& base) = default;
public:
	AlinousXpathParserTokenManager(JavaCharStream* stream, ThreadContext* ctx);
	void __construct_impl(JavaCharStream* stream, ThreadContext* ctx);
	AlinousXpathParserTokenManager(JavaCharStream* stream, long long lexState, ThreadContext* ctx);
	void __construct_impl(JavaCharStream* stream, long long lexState, ThreadContext* ctx);
	virtual ~AlinousXpathParserTokenManager() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	java::io::PrintStream* debugStream;
	long long curLexState;
	long long defaultLexState;
	long long jjnewStateCnt;
	long long jjround;
	long long jjmatchedPos;
	long long jjmatchedKind;
	JavaCharStream* input_stream;
	wchar_t curChar;
private:
	IArrayObjectPrimitive<long long>* jjrounds;
	IArrayObjectPrimitive<long long>* jjstateSet;
	StringBuilder* jjimage;
	StringBuilder* image;
	long long jjimageLen;
	long long lengthOfMatch;
public:
	static const StaticArrayObject<UnicodeStringWrapper> __jjstrLiteralImages;
	static IArrayObject<String>* jjstrLiteralImages;
	static const StaticArrayObject<UnicodeStringWrapper> __lexStateNames;
	static IArrayObject<String>* lexStateNames;
	static const StaticArrayObjectPrimitive<long long> __jjnewLexState;
	static IArrayObjectPrimitive<long long>* jjnewLexState;
	static const StaticArrayObjectPrimitive<long long> __jjnextStates;
	static IArrayObjectPrimitive<long long>* jjnextStates;
	static const StaticArrayObjectPrimitive<long long> __jjtoToken;
	static IArrayObjectPrimitive<long long>* jjtoToken;
	static const StaticArrayObjectPrimitive<long long> __jjtoSkip;
	static IArrayObjectPrimitive<long long>* jjtoSkip;
	static const StaticArrayObjectPrimitive<long long> __jjtoMore;
	static IArrayObjectPrimitive<long long>* jjtoMore;
public:
	void setDebugStream(java::io::PrintStream* ds, ThreadContext* ctx);
	Token* getNextToken(ThreadContext* ctx);
	void ReInit(JavaCharStream* stream, ThreadContext* ctx);
	void ReInit(JavaCharStream* stream, long long lexState, ThreadContext* ctx);
	void SwitchTo(long long lexState, ThreadContext* ctx);
	Token* jjFillToken(ThreadContext* ctx);
	void TokenLexicalActions(Token* matchedToken, ThreadContext* ctx);
private:
	long long jjStopAtPos(long long pos, long long kind, ThreadContext* ctx);
	long long jjMoveStringLiteralDfa0_0(ThreadContext* ctx);
	long long jjMoveStringLiteralDfa1_0(long long active0, ThreadContext* ctx);
	long long jjMoveStringLiteralDfa2_0(long long old0, long long active0, ThreadContext* ctx);
	long long jjMoveNfa_0(long long startState, long long curPos, ThreadContext* ctx);
	long long jjMoveStringLiteralDfa0_1(ThreadContext* ctx);
	long long jjMoveStringLiteralDfa1_1(long long active0, ThreadContext* ctx);
	long long jjMoveStringLiteralDfa0_2(ThreadContext* ctx);
	long long jjMoveStringLiteralDfa1_2(long long active0, ThreadContext* ctx);
	void jjCheckNAdd(long long state, ThreadContext* ctx);
	void jjAddStates(long long start, long long end, ThreadContext* ctx);
	void jjCheckNAddTwoStates(long long state1, long long state2, ThreadContext* ctx);
	void jjCheckNAddStates(long long start, long long end, ThreadContext* ctx);
	void ReInitRounds(ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_PARSER_XPATH_ALINOUSXPATHPARSERTOKENMANAGER_H_ */
