#ifndef ALINOUS_COMPILE_PARSEEXCEPTION_H_
#define ALINOUS_COMPILE_PARSEEXCEPTION_H_
namespace alinous {namespace compile {
class Token;}}

namespace java {namespace lang {
class StringBuffer;}}

namespace java {namespace lang {
class Exception;}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace compile {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;



class ParseException final : public Exception {
public:
	ParseException(const ParseException& base) = default;
public:
	ParseException(Token* currentTokenVal, IArrayObject<IArrayObjectPrimitive<long long>>* expectedTokenSequencesVal, IArrayObject<String>* tokenImageVal, ThreadContext* ctx) throw() ;
	void __construct_impl(Token* currentTokenVal, IArrayObject<IArrayObjectPrimitive<long long>>* expectedTokenSequencesVal, IArrayObject<String>* tokenImageVal, ThreadContext* ctx) throw() ;
	ParseException(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	ParseException(String* message, ThreadContext* ctx) throw() ;
	void __construct_impl(String* message, ThreadContext* ctx) throw() ;
	virtual ~ParseException() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	Token* currentToken;
	IArrayObject<IArrayObjectPrimitive<long long>>* expectedTokenSequences;
	IArrayObject<String>* tokenImage;
	String* eol;
private:
	constexpr static const long long serialVersionUID{1L};
public:
	static String* add_escapes(String* str, ThreadContext* ctx) throw() ;
private:
	static String* initialise(Token* currentToken, IArrayObject<IArrayObjectPrimitive<long long>>* expectedTokenSequences, IArrayObject<String>* tokenImage, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}

#endif /* end of ALINOUS_COMPILE_PARSEEXCEPTION_H_ */
