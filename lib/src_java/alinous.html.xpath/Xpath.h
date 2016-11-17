#ifndef ALINOUS_HTML_XPATH_XPATH_H_
#define ALINOUS_HTML_XPATH_XPATH_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace html {namespace xpath {
class XpathContext;}}}

namespace alinous {namespace html {namespace xpath {
class IVariableValue;}}}

namespace alinous {namespace html {
class DomDocument;}}

namespace alinous {namespace html {
class DomNode;}}

namespace alinous {namespace html {namespace xpath {namespace match {
class Matcher;}}}}

namespace alinous {namespace html {namespace xpath {namespace match {
class MatchCandidatesCollection;}}}}

namespace alinous {namespace html {namespace xpath {namespace match {
class MatchCandidate;}}}}

namespace java {namespace lang {
class StringBuffer;}}

namespace java {namespace util {
template <typename  T> class Iterator;}}

namespace alinous {namespace html {namespace xpath {
class IXpathStatement;}}}

namespace alinous {namespace html {namespace xpath {namespace match {
class MatchingException;}}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace html {namespace xpath {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::ArrayList;
using ::java::util::Iterator;
using ::alinous::html::DomDocument;
using ::alinous::html::DomNode;
using ::alinous::html::xpath::match::MatchCandidate;
using ::alinous::html::xpath::match::MatchCandidatesCollection;
using ::alinous::html::xpath::match::Matcher;
using ::alinous::html::xpath::match::MatchingException;



class Xpath final : public IXpathStatement, public virtual IObject {
public:
	Xpath(const Xpath& base) = default;
public:
	Xpath(ThreadContext* ctx) throw()  : IObject(ctx), IXpathStatement(ctx), contexts(GCUtils<ArrayList<XpathContext> >::ins(this, (new(ctx) ArrayList<XpathContext>(ctx)), ctx, __FILEW__, __LINE__, L""))
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~Xpath() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	ArrayList<XpathContext>* contexts;
public:
	void addContext(XpathContext* context, ThreadContext* ctx) throw() ;
	ArrayList<XpathContext>* getContexts(ThreadContext* ctx) throw() ;
	IVariableValue* getValue(DomDocument* document, DomNode* currentNode, ThreadContext* ctx) final;
	String* toString(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_HTML_XPATH_XPATH_H_ */
