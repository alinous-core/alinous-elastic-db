#ifndef ALINOUS_HTML_XPATH_XPATHFUNCTION_H_
#define ALINOUS_HTML_XPATH_XPATHFUNCTION_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace html {namespace xpath {
class XpathFunctionArgument;}}}

namespace java {namespace lang {
class StringBuffer;}}

namespace java {namespace util {
template <typename  T> class Iterator;}}

namespace alinous {namespace html {namespace xpath {
class IVariableValue;}}}

namespace alinous {namespace html {
class DomDocument;}}

namespace alinous {namespace html {
class DomNode;}}

namespace alinous {namespace html {namespace xpath {
class IXpathFunction;}}}

namespace alinous {namespace html {namespace xpath {namespace function {
class First;}}}}

namespace alinous {namespace html {namespace xpath {namespace function {
class Last;}}}}

namespace alinous {namespace html {namespace xpath {
class IXpathStatement;}}}

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
using ::alinous::html::xpath::function::First;
using ::alinous::html::xpath::function::Last;



class XpathFunction final : public IXpathStatement, public virtual IObject {
public:
	XpathFunction(const XpathFunction& base) = default;
public:
	XpathFunction(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~XpathFunction() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	String* name;
	ArrayList<XpathFunctionArgument>* arguments;
public:
	void addArgument(XpathFunctionArgument* arg, ThreadContext* ctx) throw() ;
	String* getName(ThreadContext* ctx) throw() ;
	void setName(String* name, ThreadContext* ctx) throw() ;
	String* toString(ThreadContext* ctx) throw() ;
	IVariableValue* getValue(DomDocument* document, DomNode* currentNode, ThreadContext* ctx) throw()  final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_HTML_XPATH_XPATHFUNCTION_H_ */
