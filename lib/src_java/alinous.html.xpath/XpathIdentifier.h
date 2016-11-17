#ifndef ALINOUS_HTML_XPATH_XPATHIDENTIFIER_H_
#define ALINOUS_HTML_XPATH_XPATHIDENTIFIER_H_
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



class XpathIdentifier : public IXpathStatement, public virtual IObject {
public:
	XpathIdentifier(const XpathIdentifier& base) = default;
public:
	XpathIdentifier(String* id, ThreadContext* ctx) throw() ;
	void __construct_impl(String* id, ThreadContext* ctx) throw() ;
	virtual ~XpathIdentifier() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	String* id;
public:
	String* getId(ThreadContext* ctx) throw() ;
	void setId(String* id, ThreadContext* ctx) throw() ;
	virtual String* toString(ThreadContext* ctx) throw() ;
	IVariableValue* getValue(DomDocument* document, DomNode* currentNode, ThreadContext* ctx) throw()  final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_HTML_XPATH_XPATHIDENTIFIER_H_ */
