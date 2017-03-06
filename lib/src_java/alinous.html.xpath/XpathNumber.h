#ifndef ALINOUS_HTML_XPATH_XPATHNUMBER_H_
#define ALINOUS_HTML_XPATH_XPATHNUMBER_H_
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
class NumberValue;}}}

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
using ::alinous::html::DomDocument;
using ::alinous::html::DomNode;



class XpathNumber final : public IXpathStatement, public virtual IObject {
public:
	XpathNumber(const XpathNumber& base) = default;
public:
	XpathNumber(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~XpathNumber() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	String* number;
public:
	String* getNumber(ThreadContext* ctx) throw() ;
	void setNumber(String* number, ThreadContext* ctx) throw() ;
	String* toString(ThreadContext* ctx) throw() ;
	IVariableValue* getValue(DomDocument* document, DomNode* currentNode, ThreadContext* ctx) throw()  final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_HTML_XPATH_XPATHNUMBER_H_ */
