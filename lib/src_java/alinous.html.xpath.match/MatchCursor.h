#ifndef ALINOUS_HTML_XPATH_MATCH_MATCHCURSOR_H_
#define ALINOUS_HTML_XPATH_MATCH_MATCHCURSOR_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace html {
class DomNode;}}

namespace alinous {namespace html {namespace xpath {
class IXpathElement;}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace html {namespace xpath {namespace match {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::html::DomNode;
using ::alinous::html::xpath::IXpathElement;



class MatchCursor final : public IXpathElement, public virtual IObject {
public:
	MatchCursor(const MatchCursor& base) = default;
public:
	MatchCursor(DomNode* baseObj, ThreadContext* ctx) throw() ;
	void __construct_impl(DomNode* baseObj, ThreadContext* ctx) throw() ;
	virtual ~MatchCursor() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	DomNode* baseObj;
	DomNode* ptr;
	DomNode* last_ptr;
	DomNode* stopNode;
	IXpathElement::ScanPolicy scanPolicy;
public:
	void gotoParent(ThreadContext* ctx) throw() ;
	IXpathElement::ScanPolicy getScanPolicy(ThreadContext* ctx) throw() ;
	void setScanPolicy(IXpathElement::ScanPolicy scanPolicy, ThreadContext* ctx) throw() ;
	void caluculateStopNode(ThreadContext* ctx) throw() ;
	void caluculateScanPolicy(IXpathElement::ScanPolicy scanPolicy, ThreadContext* ctx);
	DomNode* getNext(ThreadContext* ctx) throw() ;
private:
	DomNode* getNextNode(DomNode* node, ThreadContext* ctx) throw() ;
	void setupFirstPtr(ThreadContext* ctx) throw() ;
	DomNode* scanAllInheritedChildren(ThreadContext* ctx) throw() ;
	DomNode* scanChildren(ThreadContext* ctx) throw() ;
	DomNode* scanThis(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}

#endif /* end of ALINOUS_HTML_XPATH_MATCH_MATCHCURSOR_H_ */
