#ifndef ALINOUS_SYSTEM_ALINOUSCORE_H_
#define ALINOUS_SYSTEM_ALINOUSCORE_H_
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

namespace alinous {namespace runtime {namespace dbif {
class DataSourceManager;}}}

namespace alinous {namespace runtime {namespace engine {namespace debugger {
class AlinousScriptDebugger;}}}}

namespace alinous {namespace runtime {namespace engine {
class ScriptRunner;}}}

namespace alinous {namespace compile {namespace sql {namespace functions {
class SQLFunctionManager;}}}}

namespace alinous {namespace server {namespace webmodule {
class WebModuleManager;}}}

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
using ::alinous::compile::sql::functions::SQLFunctionManager;
using ::alinous::io::DiskCacheManager;
using ::alinous::runtime::AlinousModuleRepository;
using ::alinous::runtime::dbif::DataSourceManager;
using ::alinous::runtime::engine::ScriptRunner;
using ::alinous::runtime::engine::debugger::AlinousScriptDebugger;
using ::alinous::server::webmodule::WebModuleManager;
using ::alinous::system::config::AlinousConfig;
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
public:
	void init(int debugPort, ThreadContext* ctx);
	void dispose(ThreadContext* ctx) throw() ;
	String* getAlinousHome(ThreadContext* ctx) throw() ;
	AlinousConfig* getConfig(ThreadContext* ctx) throw() ;
	AlinousModuleRepository* getModulerepository(ThreadContext* ctx) throw() ;
	DataSourceManager* getDatabaseManager(ThreadContext* ctx) throw() ;
	ISystemLog* getLogger(ThreadContext* ctx) throw() ;
	ScriptRunner* getRunner(ThreadContext* ctx) throw() ;
	AlinousScriptDebugger* getDebugger(ThreadContext* ctx) throw() ;
	AlinousFunctionManager* getFunctionManager(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}

#endif /* end of ALINOUS_SYSTEM_ALINOUSCORE_H_ */
