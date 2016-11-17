#ifndef ALINOUS_WEB_PARSE_HTMLXML_TOKENMGRERROR_H_
#define ALINOUS_WEB_PARSE_HTMLXML_TOKENMGRERROR_H_
namespace java {namespace lang {
class StringBuffer;}}

namespace java {namespace lang {
class Error;}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace web {namespace parse {namespace htmlxml {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;



class TokenMgrError final : public Error {
public:
	TokenMgrError(const TokenMgrError& base) = default;
public:
	TokenMgrError(ThreadContext* ctx) throw()  : IObject(ctx), Error(ctx), errorCode(0)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	TokenMgrError(String* message, int reason, ThreadContext* ctx) throw() ;
	void __construct_impl(String* message, int reason, ThreadContext* ctx) throw() ;
	TokenMgrError(bool EOFSeen, int lexState, int errorLine, int errorColumn, String* errorAfter, wchar_t curChar, int reason, ThreadContext* ctx) throw() ;
	void __construct_impl(bool EOFSeen, int lexState, int errorLine, int errorColumn, String* errorAfter, wchar_t curChar, int reason, ThreadContext* ctx) throw() ;
	virtual ~TokenMgrError() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	int errorCode;
public:
	constexpr static const int LEXICAL_ERROR{0};
	constexpr static const int STATIC_LEXER_ERROR{1};
	constexpr static const int INVALID_LEXICAL_STATE{2};
	constexpr static const int LOOP_DETECTED{3};
private:
	constexpr static const long long serialVersionUID{1L};
public:
	String* getMessage(ThreadContext* ctx) throw()  final;
public:
	static String* addEscapes(String* str, ThreadContext* ctx) throw() ;
	static String* LexicalError(bool EOFSeen, int lexState, int errorLine, int errorColumn, String* errorAfter, wchar_t curChar, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_WEB_PARSE_HTMLXML_TOKENMGRERROR_H_ */
