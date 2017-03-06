#ifndef ALINOUS_HTML_XPATH_IXPATHFUNCTION_H_
#define ALINOUS_HTML_XPATH_IXPATHFUNCTION_H_
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
class XpathFunctionArgument;}}}

namespace alinous {namespace html {namespace xpath {
class IXpathElement;}}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace html {namespace xpath {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::ArrayList;
using ::alinous::html::DomDocument;
using ::alinous::html::DomNode;



class IXpathFunction : public virtual IObject, public IXpathElement {
public:
	IXpathFunction(const IXpathFunction& base) = default;
public:
	IXpathFunction(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~IXpathFunction() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	virtual IVariableValue* getValue(DomDocument* document, DomNode* currentNode, ArrayList<XpathFunctionArgument>* arguments, ThreadContext* ctx) throw()  = 0;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_HTML_XPATH_IXPATHFUNCTION_H_ */
