#ifndef ALINOUS_HTML_XPATH_MATCH_MATCHINGEXCEPTION_H_
#define ALINOUS_HTML_XPATH_MATCH_MATCHINGEXCEPTION_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace java {namespace lang {
class Exception;}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace html {namespace xpath {namespace match {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;



class MatchingException final : public Exception {
public:
	MatchingException(const MatchingException& base) = default;
public:
	MatchingException(String* messaString, ThreadContext* ctx) throw() ;
	void __construct_impl(String* messaString, ThreadContext* ctx) throw() ;
	virtual ~MatchingException() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	constexpr static const long long serialVersionUID{739456594526888156L};
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_HTML_XPATH_MATCH_MATCHINGEXCEPTION_H_ */
