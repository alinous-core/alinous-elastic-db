#ifndef ALINOUS_HTML_XPATH_MATCH_MATCHCANDIDATESCOLLECTION_H_
#define ALINOUS_HTML_XPATH_MATCH_MATCHCANDIDATESCOLLECTION_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace html {namespace xpath {namespace match {
class MatchCandidate;}}}}

namespace alinous {namespace html {
class DomNode;}}

namespace alinous {namespace html {namespace xpath {namespace match {
class MatchCandidatesCollection;}}}}

namespace alinous {namespace html {namespace xpath {
class IXpathStatement;}}}

namespace alinous {namespace html {
class DomDocument;}}

namespace alinous {namespace html {namespace xpath {
class XpathFunction;}}}

namespace alinous {namespace html {namespace xpath {
class IVariableValue;}}}

namespace alinous {namespace html {namespace xpath {
class NumberValue;}}}

namespace alinous {namespace html {namespace xpath {namespace match {
class MatchingException;}}}}

namespace java {namespace util {
template <typename  T> class Iterator;}}

namespace java {namespace lang {
class StringBuffer;}}

namespace java {namespace util {
template <typename  T, typename V> class Map;}}

namespace java {namespace util {
template <typename  T, typename V> class HashMap;}}

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
using ::java::util::ArrayList;
using ::java::util::HashMap;
using ::java::util::Iterator;
using ::java::util::Map;
using ::alinous::html::DomDocument;
using ::alinous::html::DomNode;
using ::alinous::html::xpath::IVariableValue;
using ::alinous::html::xpath::IXpathStatement;
using ::alinous::html::xpath::NumberValue;
using ::alinous::html::xpath::XpathFunction;



class MatchCandidatesCollection final : public virtual IObject {
public:
	MatchCandidatesCollection(const MatchCandidatesCollection& base) = default;
public:
	MatchCandidatesCollection(ThreadContext* ctx) throw()  : IObject(ctx), candidatesList(GCUtils<ArrayList<MatchCandidate> >::ins(this, (new(ctx) ArrayList<MatchCandidate>(ctx)), ctx, __FILEW__, __LINE__, L"")), domParents(GCUtils<Map<DomNode,ArrayList<MatchCandidate>> >::ins(this, (new(ctx) HashMap<DomNode,ArrayList<MatchCandidate>>(ctx)), ctx, __FILEW__, __LINE__, L""))
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~MatchCandidatesCollection() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	ArrayList<MatchCandidate>* candidatesList;
	Map<DomNode,ArrayList<MatchCandidate>>* domParents;
public:
	MatchCandidate* getFirstCandidate(ThreadContext* ctx) throw() ;
	void addCandidate(MatchCandidate* candidate, ThreadContext* ctx) throw() ;
	ArrayList<MatchCandidate>* getCandidatesList(ThreadContext* ctx) throw() ;
	MatchCandidatesCollection* filterByIndex(IXpathStatement* indexStmt, DomDocument* document, ThreadContext* ctx);
	String* toString(ThreadContext* ctx) throw() ;
private:
	MatchCandidatesCollection* filterByindex(int index, ThreadContext* ctx) throw() ;
	MatchCandidatesCollection* filterByLast(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_HTML_XPATH_MATCH_MATCHCANDIDATESCOLLECTION_H_ */
