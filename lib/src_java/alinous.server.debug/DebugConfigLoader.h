#ifndef ALINOUS_SERVER_DEBUG_DEBUGCONFIGLOADER_H_
#define ALINOUS_SERVER_DEBUG_DEBUGCONFIGLOADER_H_
namespace alinous {namespace server {namespace debug {
class DebugConfigLoader;}}}

namespace alinous {namespace system {namespace config {
class AlinousConfig;}}}

namespace java {namespace io {
class File;}}

namespace alinous {namespace system {namespace config {
class SystemInfo;}}}

namespace alinous {namespace system {namespace config {
class WebHandlerInfo;}}}

namespace java {namespace lang {
class StringBuffer;}}

namespace alinous {namespace system {namespace config {
class AlinousInitException;}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace server {namespace debug {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::File;
using ::alinous::system::config::AlinousConfig;
using ::alinous::system::config::AlinousInitException;
using ::alinous::system::config::SystemInfo;
using ::alinous::system::config::WebHandlerInfo;



class DebugConfigLoader final : public virtual IObject {
public:
	DebugConfigLoader(const DebugConfigLoader& base) = default;
public:
	DebugConfigLoader(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	DebugConfigLoader(AlinousConfig* config, ThreadContext* ctx) throw() ;
	void __construct_impl(AlinousConfig* config, ThreadContext* ctx) throw() ;
	virtual ~DebugConfigLoader() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	String* home;
	long long lastUpdate;
	AlinousConfig* config;
	String* moduleDir;
	String* webDir;
public:
	constexpr static const int MOD_DIR{1};
	constexpr static const int WEB_DIR{2};
public:
	DebugConfigLoader* init(String* path, ThreadContext* ctx);
	String* getAbsFromDebugPath(String* dpath, ThreadContext* ctx) throw() ;
	String* getDebugFilePath(String* absPath, ThreadContext* ctx);
private:
	void load(ThreadContext* ctx);
	int getHeader(String* absPath, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_SERVER_DEBUG_DEBUGCONFIGLOADER_H_ */
