#ifndef ALINOUS_HTML_XPATH_XPATH2COMPARE_H_
#define ALINOUS_HTML_XPATH_XPATH2COMPARE_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace java {namespace lang {
class StringBuffer;}}

namespace alinous {namespace html {namespace xpath {
class IXpathElement;}}}

namespace alinous {namespace html {namespace xpath {
class IXpathStatement;}}}

namespace alinous {namespace html {
class DomDocument;}}

namespace alinous {namespace html {
class DomNode;}}

namespace alinous {namespace html {namespace xpath {
class IVariableValue;}}}

namespace alinous {namespace html {namespace xpath {
class NumberValue;}}}

namespace alinous {namespace html {namespace xpath {
class XpathReference;}}}

namespace alinous {namespace html {namespace xpath {namespace match {
class MatchingException;}}}}

namespace alinous {namespace html {namespace xpath {
class Xpath;}}}

namespace alinous {namespace html {namespace xpath {namespace match {
class Matcher;}}}}

namespace alinous {namespace html {namespace xpath {namespace match {
class MatchCandidatesCollection;}}}}

namespace alinous {namespace html {namespace xpath {
class IXpathBooleanCondition;}}}

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
using ::alinous::html::xpath::match::MatchCandidatesCollection;
using ::alinous::html::xpath::match::Matcher;
using ::alinous::html::xpath::match::MatchingException;



class Xpath2Compare final : public IXpathBooleanCondition, public virtual IObject {
public:
	Xpath2Compare(const Xpath2Compare& base) = default;
public:
	Xpath2Compare(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~Xpath2Compare() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	IXpathStatement* lparam;
	IXpathStatement* rparam;
	String* ope;
public:
	String* toString(ThreadContext* ctx) throw() ;
	IXpathElement* getLparam(ThreadContext* ctx) throw() ;
	void setLparam(IXpathStatement* lparam, ThreadContext* ctx) throw() ;
	IXpathElement* getRparam(ThreadContext* ctx) throw() ;
	void setRparam(IXpathStatement* rparam, ThreadContext* ctx) throw() ;
	String* getOperator(ThreadContext* ctx) throw() ;
	void setOperator(String* opeStr, ThreadContext* ctx) throw() ;
	bool getBooleanValue(DomDocument* document, DomNode* currentNode, ThreadContext* ctx) final;
private:
	bool checkExists(DomDocument* document, DomNode* currentNode, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_HTML_XPATH_XPATH2COMPARE_H_ */
