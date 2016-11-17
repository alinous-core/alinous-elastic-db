#ifndef ALINOUS_WEB_PARSE_HTMLXML_HTMLXMLPARSERTOKENMANAGER_H_
#define ALINOUS_WEB_PARSE_HTMLXML_HTMLXMLPARSERTOKENMANAGER_H_
namespace java {namespace io {
class PrintStream;}}

namespace java {namespace io {
class IOException;}}

namespace java {namespace lang {
class Error;}}

namespace alinous {namespace web {namespace parse {namespace htmlxml {
class Token;}}}}

namespace alinous {namespace web {namespace parse {namespace htmlxml {
class TokenMgrError;}}}}

namespace alinous {namespace web {namespace parse {namespace htmlxml {
class JavaCharStream;}}}}

namespace java {namespace lang {
class StringBuilder;}}

namespace alinous {namespace web {namespace parse {namespace htmlxml {
class HtmlXmlParserConstants;}}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace alinous {namespace web {namespace htmlxml {
class AbstractXHtmlAttributeValue;}}}

namespace alinous {namespace web {namespace htmlxml {
class AbstractXHtmlElement;}}}

namespace alinous {namespace web {namespace htmlxml {
class BodyText;}}}

namespace alinous {namespace web {namespace htmlxml {
class HtmlDocType;}}}

namespace alinous {namespace web {namespace htmlxml {
class HtmlTopObject;}}}

namespace alinous {namespace web {namespace htmlxml {
class XHtmlAttribute;}}}

namespace alinous {namespace web {namespace htmlxml {
class XHtmlComment;}}}

namespace alinous {namespace web {namespace htmlxml {
class XHtmlDqString;}}}

namespace alinous {namespace web {namespace htmlxml {
class XHtmlSQString;}}}

namespace alinous {namespace web {namespace htmlxml {
class XMLTagBase;}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace web {namespace parse {namespace htmlxml {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::system::AlinousException;
using ::alinous::web::htmlxml::AbstractXHtmlAttributeValue;
using ::alinous::web::htmlxml::AbstractXHtmlElement;
using ::alinous::web::htmlxml::BodyText;
using ::alinous::web::htmlxml::HtmlDocType;
using ::alinous::web::htmlxml::HtmlTopObject;
using ::alinous::web::htmlxml::XHtmlAttribute;
using ::alinous::web::htmlxml::XHtmlComment;
using ::alinous::web::htmlxml::XHtmlDqString;
using ::alinous::web::htmlxml::XHtmlSQString;
using ::alinous::web::htmlxml::XMLTagBase;



class HtmlXmlParserTokenManager final : public HtmlXmlParserConstants, public virtual IObject {
public:
	HtmlXmlParserTokenManager(const HtmlXmlParserTokenManager& base) = default;
public:
	HtmlXmlParserTokenManager(JavaCharStream* stream, ThreadContext* ctx);
	void __construct_impl(JavaCharStream* stream, ThreadContext* ctx);
	HtmlXmlParserTokenManager(JavaCharStream* stream, long long lexState, ThreadContext* ctx);
	void __construct_impl(JavaCharStream* stream, long long lexState, ThreadContext* ctx);
	virtual ~HtmlXmlParserTokenManager() throw();
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
	IArrayObjectPrimitive<uint64_t>* jjrounds;
	IArrayObjectPrimitive<uint64_t>* jjstateSet;
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
	static const StaticArrayObjectPrimitive<uint64_t> __jjbitVec0;
	static IArrayObjectPrimitive<uint64_t>* jjbitVec0;
	static const StaticArrayObjectPrimitive<uint64_t> __jjbitVec2;
	static IArrayObjectPrimitive<uint64_t>* jjbitVec2;
	static const StaticArrayObjectPrimitive<uint64_t> __jjnextStates;
	static IArrayObjectPrimitive<uint64_t>* jjnextStates;
	static const StaticArrayObjectPrimitive<uint64_t> __jjtoToken;
	static IArrayObjectPrimitive<uint64_t>* jjtoToken;
	static const StaticArrayObjectPrimitive<uint64_t> __jjtoMore;
	static IArrayObjectPrimitive<uint64_t>* jjtoMore;
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
	long long jjMoveStringLiteralDfa3_0(long long old0, long long active0, ThreadContext* ctx);
	long long jjMoveStringLiteralDfa4_0(long long old0, long long active0, ThreadContext* ctx);
	long long jjMoveStringLiteralDfa5_0(long long old0, long long active0, ThreadContext* ctx);
	long long jjMoveStringLiteralDfa6_0(long long old0, long long active0, ThreadContext* ctx);
	long long jjMoveStringLiteralDfa7_0(long long old0, long long active0, ThreadContext* ctx);
	long long jjMoveStringLiteralDfa8_0(long long old0, long long active0, ThreadContext* ctx);
	long long jjMoveNfa_0(long long startState, long long curPos, ThreadContext* ctx);
	long long jjMoveStringLiteralDfa0_1(ThreadContext* ctx);
	long long jjMoveStringLiteralDfa1_1(long long active0, ThreadContext* ctx);
	long long jjMoveStringLiteralDfa2_1(long long old0, long long active0, ThreadContext* ctx);
	void jjCheckNAdd(long long state, ThreadContext* ctx);
	void jjAddStates(long long start, long long end, ThreadContext* ctx);
	void jjCheckNAddTwoStates(long long state1, long long state2, ThreadContext* ctx);
	void jjCheckNAddStates(long long start, long long end, ThreadContext* ctx);
	void ReInitRounds(ThreadContext* ctx);
private:
	static bool jjCanMove_0(long long hiByte, long long i1, long long i2, long long l1, long long l2, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_WEB_PARSE_HTMLXML_HTMLXMLPARSERTOKENMANAGER_H_ */
