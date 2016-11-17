#ifndef ALINOUS_HTML_XPATH_XPATHNOTSTATEMENT_H_
#define ALINOUS_HTML_XPATH_XPATHNOTSTATEMENT_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace html {namespace xpath {
class IXpathBooleanCondition;}}}

namespace java {namespace lang {
class StringBuffer;}}

namespace alinous {namespace html {
class DomDocument;}}

namespace alinous {namespace html {
class DomNode;}}

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
using ::alinous::html::DomDocument;
using ::alinous::html::DomNode;
using ::alinous::html::xpath::match::MatchingException;



class XpathNotStatement final : public IXpathBooleanCondition, public virtual IObject {
public:
	XpathNotStatement(const XpathNotStatement& base) = default;
public:
	XpathNotStatement(ThreadContext* ctx) throw()  : IObject(ctx), IXpathBooleanCondition(ctx), notFlag(0), stmt(nullptr)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~XpathNotStatement() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	bool notFlag;
	IXpathBooleanCondition* stmt;
public:
	bool isNot(ThreadContext* ctx) throw() ;
	void setNot(bool notFlag, ThreadContext* ctx) throw() ;
	IXpathBooleanCondition* getStmt(ThreadContext* ctx) throw() ;
	void setStmt(IXpathBooleanCondition* stmt, ThreadContext* ctx) throw() ;
	String* toString(ThreadContext* ctx) throw() ;
	bool getBooleanValue(DomDocument* document, DomNode* currentNode, ThreadContext* ctx) final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_HTML_XPATH_XPATHNOTSTATEMENT_H_ */
