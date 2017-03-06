#ifndef ALINOUS_HTML_XPATH_XPATHSTRING_H_
#define ALINOUS_HTML_XPATH_XPATHSTRING_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace java {namespace lang {
class StringBuffer;}}

namespace alinous {namespace html {namespace xpath {
class IVariableValue;}}}

namespace alinous {namespace html {
class DomDocument;}}

namespace alinous {namespace html {
class DomNode;}}

namespace alinous {namespace html {namespace xpath {
class StringValue;}}}

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



class XpathString final : public IXpathStatement, public virtual IObject {
public:
	XpathString(const XpathString& base) = default;
public:
	XpathString(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~XpathString() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	String* text;
public:
	String* getText(ThreadContext* ctx) throw() ;
	void setText(String* text, ThreadContext* ctx) throw() ;
	String* toString(ThreadContext* ctx) throw() ;
	IVariableValue* getValue(DomDocument* document, DomNode* currentNode, ThreadContext* ctx) throw()  final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_HTML_XPATH_XPATHSTRING_H_ */
