#ifndef ALINOUS_SYSTEM_CONFIG_REMOTE_MONITOR_H_
#define ALINOUS_SYSTEM_CONFIG_REMOTE_MONITOR_H_
namespace alinous {namespace system {namespace config {namespace remote {
class Monitor;}}}}

namespace alinous {namespace html {namespace xpath {namespace match {
class MatchCandidate;}}}}

namespace alinous {namespace html {
class DomDocument;}}

namespace alinous {namespace html {namespace xpath {namespace match {
class Matcher;}}}}

namespace alinous {namespace html {
class DomNode;}}

namespace alinous {namespace html {namespace xpath {
class IVariableValue;}}}

namespace alinous {namespace system {namespace config {
class AlinousInitException;}}}

namespace java {namespace lang {
class Throwable;}}

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
using ::alinous::html::xpath::match::MatchCandidate;
using ::alinous::html::xpath::match::Matcher;
using ::alinous::system::config::AlinousInitException;



class Monitor final : public virtual IObject {
public:
	Monitor(const Monitor& base) = default;
public:
	Monitor(ThreadContext* ctx) throw()  : IObject(ctx), port(nullptr), maxConnection(8)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~Monitor() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	String* port;
	int maxConnection;
public:
	String* getPort(ThreadContext* ctx) throw() ;
	void setPort(String* port, ThreadContext* ctx) throw() ;
	int getMaxConnection(ThreadContext* ctx) throw() ;
	void setMaxConnection(int maxConnection, ThreadContext* ctx) throw() ;
public:
	static Monitor* parseInstance(MatchCandidate* candidate, DomDocument* document, Matcher* matcher, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_SYSTEM_CONFIG_REMOTE_MONITOR_H_ */
