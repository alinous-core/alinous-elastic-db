#ifndef ALINOUS_SYSTEM_CONFIG_ALINOUSCONFIG_H_
#define ALINOUS_SYSTEM_CONFIG_ALINOUSCONFIG_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace java {namespace io {
class File;}}

namespace alinous {namespace system {namespace config {
class AlinousInitException;}}}

namespace alinous {namespace html {
class AlinousDomReplacer;}}

namespace alinous {namespace html {
class DomConverter;}}

namespace alinous {namespace html {
class DomDocument;}}

namespace alinous {namespace html {namespace xpath {namespace match {
class Matcher;}}}}

namespace alinous {namespace html {namespace xpath {namespace match {
class MatchCandidatesCollection;}}}}

namespace alinous {namespace parser {namespace xpath {
class ParseException;}}}

namespace alinous {namespace html {namespace xpath {namespace match {
class MatchingException;}}}}

namespace alinous {namespace html {namespace xpath {namespace match {
class MatchCandidate;}}}}

namespace alinous {namespace system {namespace config {
class SystemInfo;}}}

namespace alinous {namespace system {namespace config {
class AlinousDbInfo;}}}

namespace java {namespace util {
template <typename  T> class Iterator;}}

namespace alinous {namespace html {
class DomNode;}}

namespace alinous {namespace html {namespace xpath {
class IVariableValue;}}}

namespace alinous {namespace system {namespace config {
class AlinousDbInstanceInfo;}}}

namespace alinous {namespace system {namespace config {namespace remote {
class RegionsRef;}}}}

namespace alinous {namespace system {namespace config {namespace remote {
class MonitorRef;}}}}

namespace alinous {namespace system {namespace config {
class WebHandlerInfo;}}}

namespace java {namespace lang {
class NumberFormatException;}}

namespace java {namespace lang {
class StringBuffer;}}

namespace alinous {namespace system {namespace config {
class DataSourceInfo;}}}

namespace alinous {namespace system {namespace config {
class MailInfo;}}}

namespace alinous {namespace system {namespace config {namespace remote {
class Regions;}}}}

namespace alinous {namespace system {namespace config {namespace remote {
class Nodes;}}}}

namespace alinous {namespace system {namespace config {namespace remote {
class Monitor;}}}}

namespace alinous {namespace system {namespace utils {
class ConfigFileUtiles;}}}

namespace alinous {namespace system {namespace utils {
class FileUtils;}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace system {namespace config {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::File;
using ::java::util::ArrayList;
using ::java::util::Iterator;
using ::alinous::html::AlinousDomReplacer;
using ::alinous::html::DomConverter;
using ::alinous::html::DomDocument;
using ::alinous::html::DomNode;
using ::alinous::html::xpath::IVariableValue;
using ::alinous::html::xpath::match::MatchCandidate;
using ::alinous::html::xpath::match::MatchCandidatesCollection;
using ::alinous::html::xpath::match::Matcher;
using ::alinous::html::xpath::match::MatchingException;
using ::alinous::parser::xpath::ParseException;
using ::alinous::system::config::remote::Monitor;
using ::alinous::system::config::remote::MonitorRef;
using ::alinous::system::config::remote::Nodes;
using ::alinous::system::config::remote::Regions;
using ::alinous::system::config::remote::RegionsRef;
using ::alinous::system::utils::ConfigFileUtiles;
using ::alinous::system::utils::FileUtils;



class AlinousConfig final : public virtual IObject {
public:
	AlinousConfig(const AlinousConfig& base) = default;
public:
	AlinousConfig(String* home, ThreadContext* ctx) throw() ;
	void __construct_impl(String* home, ThreadContext* ctx) throw() ;
	virtual ~AlinousConfig() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	StringBuffer* alinousHome;
	SystemInfo* system;
	DataSourceInfo* database;
	MailInfo* mail;
	AlinousDbInfo* alinousDb;
	WebHandlerInfo* webHandler;
	Regions* regions;
	Nodes* nodes;
	Monitor* monitor;
	String* alinousConfigPath;
	long long fileTimestamp;
public:
	void parseInitFile(ThreadContext* ctx);
	StringBuffer* getAlinousHome(ThreadContext* ctx) throw() ;
	void setAlinousHome(StringBuffer* alinousHome, ThreadContext* ctx) throw() ;
	SystemInfo* getSystem(ThreadContext* ctx) throw() ;
	DataSourceInfo* getDatabase(ThreadContext* ctx) throw() ;
	MailInfo* getMail(ThreadContext* ctx) throw() ;
	AlinousDbInfo* getAlinousDb(ThreadContext* ctx) throw() ;
	WebHandlerInfo* getWebHandler(ThreadContext* ctx) throw() ;
	String* getAlinousConfigPath(ThreadContext* ctx) throw() ;
	long long getFileTimestamp(ThreadContext* ctx) throw() ;
	Regions* getRegions(ThreadContext* ctx) throw() ;
	Nodes* getNodes(ThreadContext* ctx) throw() ;
	Monitor* getMonitor(ThreadContext* ctx) throw() ;
private:
	void handleSystem(MatchCandidatesCollection* result, DomDocument* document, Matcher* matcher, ThreadContext* ctx);
	void handleDistributedDbParts(DomDocument* document, Matcher* matcher, ThreadContext* ctx);
	void handleAlinousDbSetting(MatchCandidatesCollection* result, DomDocument* document, Matcher* matcher, ThreadContext* ctx);
	void handleRemoteRef(AlinousDbInstanceInfo* dbinfo, DomNode* alinousDb, DomDocument* document, Matcher* matcher, ThreadContext* ctx);
	void handleWebSetting(MatchCandidatesCollection* result, DomDocument* document, Matcher* matcher, ThreadContext* ctx);
	void handleSourceSetting(MatchCandidatesCollection* result, ThreadContext* ctx) throw() ;
	void handleMailSetting(MatchCandidatesCollection* result, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_SYSTEM_CONFIG_ALINOUSCONFIG_H_ */
