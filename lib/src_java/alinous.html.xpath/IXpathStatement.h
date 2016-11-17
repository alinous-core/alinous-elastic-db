#ifndef ALINOUS_HTML_XPATH_IXPATHSTATEMENT_H_
#define ALINOUS_HTML_XPATH_IXPATHSTATEMENT_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace html {namespace xpath {
class IVariableValue;}}}

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



class IXpathStatement : public virtual IObject, public IXpathElement {
public:
	IXpathStatement(const IXpathStatement& base) = default;
public:
	IXpathStatement(ThreadContext* ctx) throw()  : IObject(ctx), IXpathElement(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~IXpathStatement() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	virtual IVariableValue* getValue(DomDocument* document, DomNode* currentNode, ThreadContext* ctx) = 0;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_HTML_XPATH_IXPATHSTATEMENT_H_ */
