#ifndef ALINOUS_SYSTEM_CONFIG_REMOTE_NODEREF_H_
#define ALINOUS_SYSTEM_CONFIG_REMOTE_NODEREF_H_
namespace alinous {namespace system {namespace config {namespace remote {
class NodeRef;}}}}

namespace alinous {namespace html {
class DomNode;}}

namespace alinous {namespace html {
class DomDocument;}}

namespace alinous {namespace html {namespace xpath {namespace match {
class Matcher;}}}}

namespace alinous {namespace html {namespace xpath {
class IVariableValue;}}}

namespace alinous {namespace system {namespace config {
class AlinousInitException;}}}

namespace alinous {namespace system {namespace config {
class IAlinousConfigElement;}}}

namespace alinous {namespace html {namespace xpath {namespace match {
class MatchingException;}}}}

namespace alinous {namespace parser {namespace xpath {
class ParseException;}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace system {namespace config {namespace remote {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::html::DomDocument;
using ::alinous::html::DomNode;
using ::alinous::html::xpath::IVariableValue;
using ::alinous::html::xpath::match::Matcher;
using ::alinous::html::xpath::match::MatchingException;
using ::alinous::parser::xpath::ParseException;
using ::alinous::system::config::AlinousInitException;
using ::alinous::system::config::IAlinousConfigElement;



class NodeRef final : public IAlinousConfigElement, public virtual IObject {
public:
	NodeRef(const NodeRef& base) = default;
public:
	NodeRef(ThreadContext* ctx) throw()  : IObject(ctx), IAlinousConfigElement(ctx), url(nullptr)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~NodeRef() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	String* url;
public:
	String* getUrl(ThreadContext* ctx) throw() ;
	void setUrl(String* url, ThreadContext* ctx) throw() ;
public:
	static NodeRef* parseInstance(DomNode* dom, DomDocument* document, Matcher* matcher, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_SYSTEM_CONFIG_REMOTE_NODEREF_H_ */