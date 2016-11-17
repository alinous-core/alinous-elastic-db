#ifndef ALINOUS_HTML_XPATH_MATCH_MATCHCANDIDATE_H_
#define ALINOUS_HTML_XPATH_MATCH_MATCHCANDIDATE_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace html {
class DomNode;}}

namespace alinous {namespace html {namespace xpath {namespace match {
class MatchCursor;}}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace html {namespace xpath {namespace match {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::html::DomNode;



class MatchCandidate final : public virtual IObject {
public:
	MatchCandidate(const MatchCandidate& base) = default;
public:
	MatchCandidate(DomNode* candidateDom, ThreadContext* ctx) throw() ;
	void __construct_impl(DomNode* candidateDom, ThreadContext* ctx) throw() ;
	virtual ~MatchCandidate() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	DomNode* candidateDom;
public:
	MatchCursor* getCursor(ThreadContext* ctx) throw() ;
	DomNode* getCandidateDom(ThreadContext* ctx) throw() ;
	String* toString(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_HTML_XPATH_MATCH_MATCHCANDIDATE_H_ */
