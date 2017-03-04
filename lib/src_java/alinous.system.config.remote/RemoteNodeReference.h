#ifndef ALINOUS_SYSTEM_CONFIG_REMOTE_REMOTENODEREFERENCE_H_
#define ALINOUS_SYSTEM_CONFIG_REMOTE_REMOTENODEREFERENCE_H_
namespace alinous {namespace system {namespace config {namespace remote {
class RemoteNodeReference;}}}}

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



class RemoteNodeReference final : public IAlinousConfigElement, public virtual IObject {
public:
	RemoteNodeReference(const RemoteNodeReference& base) = default;
public:
	RemoteNodeReference(ThreadContext* ctx) throw()  : IObject(ctx), IAlinousConfigElement(ctx), url(nullptr), ipv6(false)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~RemoteNodeReference() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	String* url;
	bool ipv6;
public:
	String* getUrl(ThreadContext* ctx) throw() ;
	void setUrl(String* url, ThreadContext* ctx) throw() ;
	bool isIpv6(ThreadContext* ctx) throw() ;
	void setIpv6(bool ipv6, ThreadContext* ctx) throw() ;
public:
	static RemoteNodeReference* parseInstance(DomNode* dom, DomDocument* document, Matcher* matcher, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_SYSTEM_CONFIG_REMOTE_REMOTENODEREFERENCE_H_ */
