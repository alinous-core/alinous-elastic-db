#ifndef ALINOUS_HTML_XPATH_IXPATHBOOLEANCONDITION_H_
#define ALINOUS_HTML_XPATH_IXPATHBOOLEANCONDITION_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace html {
class DomDocument;}}

namespace alinous {namespace html {
class DomNode;}}

namespace alinous {namespace html {namespace xpath {
class IXpathElement;}}}

namespace alinous {namespace html {namespace xpath {namespace match {
class MatchingException;}}}}

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



class IXpathBooleanCondition : public virtual IObject, public IXpathElement {
public:
	IXpathBooleanCondition(const IXpathBooleanCondition& base) = default;
public:
	IXpathBooleanCondition(ThreadContext* ctx) throw()  : IObject(ctx), IXpathElement(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~IXpathBooleanCondition() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	virtual bool getBooleanValue(DomDocument* document, DomNode* currentNode, ThreadContext* ctx) = 0;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_HTML_XPATH_IXPATHBOOLEANCONDITION_H_ */
