#ifndef ALINOUS_HTML_XPATH_XPATHPARSER_H_
#define ALINOUS_HTML_XPATH_XPATHPARSER_H_
namespace alinous{namespace annotation{
class HeaderOnly;
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



class XPathParser final : public IXpathElement, public virtual IObject {
public:
	XPathParser(const XPathParser& base) = default;
public:
	XPathParser(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~XPathParser() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_HTML_XPATH_XPATHPARSER_H_ */
