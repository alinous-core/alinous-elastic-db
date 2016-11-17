#ifndef ALINOUS_HTML_XPATH_XPATHCONTEXTLOCATION_H_
#define ALINOUS_HTML_XPATH_XPATHCONTEXTLOCATION_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace html {namespace xpath {
class XpathContextLocationCtrl;}}}

namespace alinous {namespace html {namespace xpath {namespace match {
class MatchCursor;}}}}

namespace java {namespace util {
template <typename  T> class Iterator;}}

namespace java {namespace lang {
class StringBuffer;}}

namespace alinous {namespace html {namespace xpath {
class IXpathElement;}}}

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
using ::alinous::html::xpath::match::MatchCursor;
using ::alinous::html::xpath::match::MatchingException;



class XpathContextLocation final : public IXpathElement, public virtual IObject {
public:
	XpathContextLocation(const XpathContextLocation& base) = default;
public:
	XpathContextLocation(ThreadContext* ctx) throw()  : IObject(ctx), IXpathElement(ctx), ctrls(GCUtils<ArrayList<XpathContextLocationCtrl> >::ins(this, (new(ctx) ArrayList<XpathContextLocationCtrl>(ctx)), ctx, __FILEW__, __LINE__, L""))
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~XpathContextLocation() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	ArrayList<XpathContextLocationCtrl>* ctrls;
public:
	void addCtrl(XpathContextLocationCtrl* ctrl, ThreadContext* ctx) throw() ;
	void setupLocation(MatchCursor* cursor, ThreadContext* ctx);
	String* toString(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_HTML_XPATH_XPATHCONTEXTLOCATION_H_ */
