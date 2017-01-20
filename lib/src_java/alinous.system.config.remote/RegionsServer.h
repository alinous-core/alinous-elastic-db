#ifndef ALINOUS_SYSTEM_CONFIG_REMOTE_REGIONSSERVER_H_
#define ALINOUS_SYSTEM_CONFIG_REMOTE_REGIONSSERVER_H_
namespace alinous {namespace system {namespace config {namespace remote {
class RegionsServer;}}}}

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

namespace alinous {namespace html {namespace xpath {namespace match {
class MatchCandidatesCollection;}}}}

namespace alinous {namespace system {namespace config {namespace remote {
class MonitorRef;}}}}

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
using ::java::util::ArrayList;
using ::alinous::html::DomDocument;
using ::alinous::html::DomNode;
using ::alinous::html::xpath::IVariableValue;
using ::alinous::html::xpath::match::MatchCandidate;
using ::alinous::html::xpath::match::MatchCandidatesCollection;
using ::alinous::html::xpath::match::Matcher;
using ::alinous::html::xpath::match::MatchingException;
using ::alinous::parser::xpath::ParseException;
using ::alinous::system::config::AlinousInitException;
using ::alinous::system::config::IAlinousConfigElement;



class RegionsServer final : public IAlinousConfigElement, public virtual IObject {
public:
	RegionsServer(const RegionsServer& base) = default;
public:
	RegionsServer(ThreadContext* ctx) throw()  : IObject(ctx), IAlinousConfigElement(ctx), port(0), maxCon(8), monitorRef(nullptr), region(nullptr)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~RegionsServer() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	int port;
	int maxCon;
	MonitorRef* monitorRef;
	String* region;
public:
	int getPort(ThreadContext* ctx) throw() ;
	void setPort(int port, ThreadContext* ctx) throw() ;
	int getMaxCon(ThreadContext* ctx) throw() ;
	void setMaxCon(int maxCon, ThreadContext* ctx) throw() ;
	MonitorRef* getMonitorRef(ThreadContext* ctx) throw() ;
	void setMonitorRef(MonitorRef* monitorRef, ThreadContext* ctx) throw() ;
	String* getRegion(ThreadContext* ctx) throw() ;
public:
	static RegionsServer* parseInstance(MatchCandidate* candidate, DomDocument* document, Matcher* matcher, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_SYSTEM_CONFIG_REMOTE_REGIONSSERVER_H_ */
