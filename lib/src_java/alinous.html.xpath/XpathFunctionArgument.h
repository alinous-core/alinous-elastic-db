#ifndef ALINOUS_HTML_XPATH_XPATHFUNCTIONARGUMENT_H_
#define ALINOUS_HTML_XPATH_XPATHFUNCTIONARGUMENT_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace html {namespace xpath {
class IXpathElement;}}}

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



class XpathFunctionArgument final : public IXpathElement, public virtual IObject {
public:
	XpathFunctionArgument(const XpathFunctionArgument& base) = default;
public:
	XpathFunctionArgument(IXpathElement* element, ThreadContext* ctx) throw() ;
	void __construct_impl(IXpathElement* element, ThreadContext* ctx) throw() ;
	virtual ~XpathFunctionArgument() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	IXpathElement* element;
public:
	IXpathElement* getElement(ThreadContext* ctx) throw() ;
	void setElement(IXpathElement* element, ThreadContext* ctx) throw() ;
	String* toString(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_HTML_XPATH_XPATHFUNCTIONARGUMENT_H_ */
