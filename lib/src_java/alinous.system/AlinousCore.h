#ifndef ALINOUS_SYSTEM_ALINOUSCORE_H_
#define ALINOUS_SYSTEM_ALINOUSCORE_H_
namespace java{namespace net{
class UnknownHostException;
}}
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace system {
class AlinousCoreLogger;}}

namespace alinous {namespace io {
class DiskCacheManager;}}

namespace alinous {namespace system {namespace config {
class AlinousConfig;}}}

namespace alinous {namespace system {namespace functions {
class AlinousFunctionManager;}}}

namespace alinous {namespace runtime {
class AlinousModuleRepository;}}

namespace alinous {namespace runtime {namespace engine {namespace debugger {
class AlinousScriptDebugger;}}}}

namespace alinous {namespace runtime {namespace engine {
class ScriptRunner;}}}

namespace alinous {namespace compile {namespace sql {namespace functions {
class SQLFunctionManager;}}}}

namespace alinous {namespace server {namespace webmodule {
class WebModuleManager;}}}

namespace alinous {namespace runtime {namespace dbif {
class DataSourceManager;}}}

namespace alinous {namespace system {namespace config {namespace remote {
class Monitor;}}}}

namespace alinous {namespace system {namespace config {
class AlinousInitException;}}}

namespace java {namespace lang {
class Throwable;}}

namespace alinous {namespace remote {namespace monitor {
class TransactionMonitorServer;}}}

namespace alinous {namespace system {namespace config {namespace remote {
class Nodes;}}}}

namespace java {namespace util {
template <typename  T> class List;}}

namespace alinous {namespace system {namespace config {namespace remote {
class Node;}}}}

namespace java {namespace util {
template <typename  T> class Iterator;}}

namespace alinous {namespace remote {namespace db {
class RemoteTableStorageServer;}}}

namespace alinous {namespace db {
class AlinousDbException;}}

namespace alinous {namespace system {namespace config {namespace remote {
class RegionsServer;}}}}

namespace alinous {namespace remote {namespace region {
class NodeRegionServer;}}}

namespace java {namespace io {
class IOException;}}

namespace alinous {namespace system {
class AlinousException;}}

namespace java {namespace lang {
class InterruptedException;}}

namespace alinous {namespace system {
class ISystemLog;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace system {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::IOException;
using ::java::net::UnknownHostException;
using ::java::util::ArrayList;
using ::java::util::Iterator;
using ::java::util::List;
using ::alinous::compile::sql::functions::SQLFunctionManager;
using ::alinous::db::AlinousDbException;
using ::alinous::io::DiskCacheManager;
using ::alinous::remote::db::RemoteTableStorageServer;
using ::alinous::remote::monitor::TransactionMonitorServer;
using ::alinous::remote::region::NodeRegionServer;
using ::alinous::runtime::AlinousModuleRepository;
using ::alinous::runtime::dbif::DataSourceManager;
using ::alinous::runtime::engine::ScriptRunner;
using ::alinous::runtime::engine::debugger::AlinousScriptDebugger;
using ::alinous::server::webmodule::WebModuleManager;
using ::alinous::system::config::AlinousConfig;
using ::alinous::system::config::AlinousInitException;
using ::alinous::system::config::remote::Monitor;
using ::alinous::system::config::remote::Node;
using ::alinous::system::config::remote::Nodes;
using ::alinous::system::config::remote::RegionsServer;
using ::alinous::system::functions::AlinousFunctionManager;



class AlinousCore final : public virtual IObject {
public:
	AlinousCore(const AlinousCore& base) = default;
public:
	AlinousCore(String* home, bool debug, ThreadContext* ctx) throw() ;
	void __construct_impl(String* home, bool debug, ThreadContext* ctx) throw() ;
	virtual ~AlinousCore() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	DiskCacheManager* diskCache;
	SQLFunctionManager* sqlFunctionManager;
	WebModuleManager* webModuleManager;
	bool debug;
private:
	String* alinousHome;
	AlinousConfig* config;
	AlinousCoreLogger* logger;
	AlinousFunctionManager* functionManager;
	AlinousModuleRepository* modulerepository;
	DataSourceManager* databaseManager;
	AlinousScriptDebugger* debugger;
	ScriptRunner* runner;
	TransactionMonitorServer* monitor;
	List<RemoteTableStorageServer>* storageServers;
	List<NodeRegionServer>* regionServers;
public:
	void init(int debugPort, ThreadContext* ctx);
	void initDatabase(ThreadContext* ctx);
	void dispose(ThreadContext* ctx) throw() ;
	String* getAlinousHome(ThreadContext* ctx) throw() ;
	AlinousConfig* getConfig(ThreadContext* ctx) throw() ;
	AlinousModuleRepository* getModulerepository(ThreadContext* ctx) throw() ;
	DataSourceManager* getDatabaseManager(ThreadContext* ctx) throw() ;
	ISystemLog* getLogger(ThreadContext* ctx) throw() ;
	ScriptRunner* getRunner(ThreadContext* ctx) throw() ;
	AlinousScriptDebugger* getDebugger(ThreadContext* ctx) throw() ;
	AlinousFunctionManager* getFunctionManager(ThreadContext* ctx) throw() ;
private:
	void initDistributedServerParts(ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}

#endif /* end of ALINOUS_SYSTEM_ALINOUSCORE_H_ */
