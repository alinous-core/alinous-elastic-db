#ifndef ALINOUS_HTML_XPATH_XPATHREFERENCE_H_
#define ALINOUS_HTML_XPATH_XPATHREFERENCE_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace html {namespace xpath {
class Xpath;}}}

namespace alinous {namespace html {namespace xpath {
class IVariableValue;}}}

namespace alinous {namespace html {
class DomDocument;}}

namespace alinous {namespace html {
class DomNode;}}

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
using ::alinous::html::DomDocument;
using ::alinous::html::DomNode;
using ::alinous::html::xpath::match::MatchingException;



class XpathReference final : public IXpathStatement, public virtual IObject {
public:
	XpathReference(const XpathReference& base) = default;
public:
	XpathReference(ThreadContext* ctx) throw()  : IObject(ctx), IXpathStatement(ctx), xpath(nullptr)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~XpathReference() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	Xpath* xpath;
public:
	Xpath* getXpath(ThreadContext* ctx) throw() ;
	void setXpath(Xpath* xpath, ThreadContext* ctx) throw() ;
	String* toString(ThreadContext* ctx) throw() ;
	IVariableValue* getValue(DomDocument* document, DomNode* currentNode, ThreadContext* ctx) final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_HTML_XPATH_XPATHREFERENCE_H_ */
