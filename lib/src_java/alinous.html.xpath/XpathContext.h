#ifndef ALINOUS_HTML_XPATH_XPATHCONTEXT_H_
#define ALINOUS_HTML_XPATH_XPATHCONTEXT_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace html {namespace xpath {
class AttributeIdentifier;}}}

namespace alinous {namespace html {namespace xpath {
class XpathFilter;}}}

namespace alinous {namespace html {
class DomNode;}}

namespace alinous {namespace html {namespace xpath {
class XpathIdentifier;}}}

namespace alinous {namespace html {
class Attribute;}}

namespace alinous {namespace html {namespace xpath {namespace match {
class MatchCursor;}}}}

namespace alinous {namespace html {namespace xpath {
class IXpathElement;}}}

namespace alinous {namespace html {namespace xpath {
class IXpathStatement;}}}

namespace alinous {namespace html {namespace xpath {
class XpathContextLocation;}}}

namespace java {namespace lang {
class StringBuffer;}}

namespace java {namespace util {
template <typename  T> class Iterator;}}

namespace alinous {namespace html {namespace xpath {
class Xpath;}}}

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
using ::java::util::ArrayList;
using ::java::util::Iterator;
using ::alinous::html::Attribute;
using ::alinous::html::DomNode;
using ::alinous::html::xpath::match::MatchCursor;
using ::alinous::html::xpath::match::MatchingException;



class XpathContext final : public IXpathElement, public virtual IObject {
public:
	XpathContext(const XpathContext& base) = default;
public:
	XpathContext(ThreadContext* ctx) throw()  : IObject(ctx), IXpathElement(ctx), filters(GCUtils<ArrayList<XpathFilter> >::ins(this, (new(ctx) ArrayList<XpathFilter>(ctx)), ctx, __FILEW__, __LINE__, L"")), location(nullptr), identifier(nullptr), index(nullptr), xpath(nullptr)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~XpathContext() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	ArrayList<XpathFilter>* filters;
	XpathContextLocation* location;
	IXpathStatement* identifier;
	IXpathStatement* index;
	Xpath* xpath;
public:
	IXpathElement::ScanTarget getScanTarget(ThreadContext* ctx) throw() ;
	String* getAttributeName(ThreadContext* ctx) throw() ;
	XpathFilter* getConditionFilter(ThreadContext* ctx) throw() ;
	bool isFirstContext(ThreadContext* ctx) throw() ;
	bool matchPath(DomNode* node, ThreadContext* ctx) throw() ;
	void setupCurserLocationPolicy(MatchCursor* cursor, ThreadContext* ctx);
	IXpathElement* getIdentifier(ThreadContext* ctx) throw() ;
	void setIdentifier(IXpathStatement* identifier, ThreadContext* ctx) throw() ;
	XpathContextLocation* getLocation(ThreadContext* ctx) throw() ;
	void setLocation(XpathContextLocation* location, ThreadContext* ctx) throw() ;
	void addFilter(XpathFilter* filter, ThreadContext* ctx) throw() ;
	IXpathStatement* getIndex(ThreadContext* ctx) throw() ;
	void setIndex(IXpathStatement* index, ThreadContext* ctx) throw() ;
	ArrayList<XpathFilter>* getFilters(ThreadContext* ctx) throw() ;
	String* toString(ThreadContext* ctx) throw() ;
	Xpath* getXpath(ThreadContext* ctx) throw() ;
	void setXpath(Xpath* xpath, ThreadContext* ctx) throw() ;
private:
	bool matchIdentifier(XpathIdentifier* xpathId, DomNode* node, ThreadContext* ctx) throw() ;
	bool hasAttribute(AttributeIdentifier* attrId, DomNode* node, ThreadContext* ctx) throw() ;
	void setupRelationalScan(MatchCursor* cursor, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_HTML_XPATH_XPATHCONTEXT_H_ */
