#ifndef COM_GOOGLE_RE2J_PATTERNSYNTAXEXCEPTION_H_
#define COM_GOOGLE_RE2J_PATTERNSYNTAXEXCEPTION_H_
namespace alinous{namespace annotation{
class HeaderOnly;
}}
namespace java {namespace lang {
class Exception;}}

namespace alinous {
class ThreadContext;
}

namespace com {namespace google {namespace re2j {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;



class PatternSyntaxException final : public Exception {
public:
	PatternSyntaxException(const PatternSyntaxException& base) = default;
public:
	PatternSyntaxException(String* error, String* input, ThreadContext* ctx) throw() ;
	void __construct_impl(String* error, String* input, ThreadContext* ctx) throw() ;
	PatternSyntaxException(String* error, ThreadContext* ctx) throw() ;
	void __construct_impl(String* error, ThreadContext* ctx) throw() ;
	virtual ~PatternSyntaxException() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	String* error;
	String* input;
private:
	constexpr static const long long serialVersionUID{1L};
public:
	int getIndex(ThreadContext* ctx) throw() ;
	String* getDescription(ThreadContext* ctx) throw() ;
	String* getPattern(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of COM_GOOGLE_RE2J_PATTERNSYNTAXEXCEPTION_H_ */
