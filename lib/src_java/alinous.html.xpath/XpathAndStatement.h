#ifndef ALINOUS_HTML_XPATH_XPATHANDSTATEMENT_H_
#define ALINOUS_HTML_XPATH_XPATHANDSTATEMENT_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace java {namespace lang {
class StringBuffer;}}

namespace java {namespace util {
template <typename  T> class Iterator;}}

namespace alinous {namespace html {namespace xpath {
class IXpathBooleanCondition;}}}

namespace alinous {namespace html {
class DomDocument;}}

namespace alinous {namespace html {
class DomNode;}}

namespace alinous {namespace html {namespace xpath {
class AbstractContainerStatement;}}}

namespace alinous {namespace html {namespace xpath {namespace match {
class MatchingException;}}}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace html {namespace xpath {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::Iterator;
using ::alinous::html::DomDocument;
using ::alinous::html::DomNode;
using ::alinous::html::xpath::match::MatchingException;



class XpathAndStatement final : public AbstractContainerStatement {
public:
	XpathAndStatement(const XpathAndStatement& base) = default;
public:
	XpathAndStatement(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~XpathAndStatement() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	String* toString(ThreadContext* ctx) throw() ;
	bool getBooleanValue(DomDocument* document, DomNode* currentNode, ThreadContext* ctx) final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_HTML_XPATH_XPATHANDSTATEMENT_H_ */
