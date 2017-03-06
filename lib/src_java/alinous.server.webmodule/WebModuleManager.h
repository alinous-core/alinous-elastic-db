#ifndef ALINOUS_SERVER_WEBMODULE_WEBMODULEMANAGER_H_
#define ALINOUS_SERVER_WEBMODULE_WEBMODULEMANAGER_H_
namespace alinous{namespace annotation{
class ThreadMonitor;
}}
namespace alinous {namespace system {
class AlinousCore;}}

namespace alinous {namespace server {namespace webmodule {
class WebModuleHashList;}}}

namespace alinous {namespace system {namespace config {
class AlinousConfig;}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace alinous {namespace server {namespace webmodule {
class AbstractWebModule;}}}

namespace alinous {namespace buffer {
template <typename  T> class FifoElement;}}

namespace java {namespace lang {
class StringBuilder;}}

namespace java {namespace io {
class File;}}

namespace alinous {namespace runtime {
class AlinousModule;}}

namespace alinous {namespace server {namespace webmodule {
class DirectModule;}}}

namespace alinous {namespace web {namespace htmlxml {namespace module {
class AlinousWebHtmlXmlModule;}}}}

namespace java {namespace lang {
class Throwable;}}

namespace alinous {namespace server {namespace webmodule {
class StaticHtmlModule;}}}

namespace alinous {namespace server {namespace webmodule {
class DynamicWebPageModule;}}}

namespace alinous {namespace runtime {
class ModuleNotFoundException;}}

namespace alinous {namespace buffer {
template <typename  T> class FifoList;}}

namespace alinous {namespace system {namespace config {
class WebHandlerInfo;}}}

namespace alinous {namespace runtime {
class AlinousModuleRepository;}}

namespace alinous {namespace db {namespace table {
class DatabaseException;}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace server {namespace webmodule {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::File;
using ::alinous::buffer::FifoElement;
using ::alinous::buffer::FifoList;
using ::alinous::db::table::DatabaseException;
using ::alinous::runtime::AlinousModule;
using ::alinous::runtime::AlinousModuleRepository;
using ::alinous::runtime::ModuleNotFoundException;
using ::alinous::system::AlinousCore;
using ::alinous::system::AlinousException;
using ::alinous::system::config::AlinousConfig;
using ::alinous::system::config::WebHandlerInfo;
using ::alinous::web::htmlxml::module::AlinousWebHtmlXmlModule;



class WebModuleManager final : public ThreadMonitor, public virtual IObject {
public:
	WebModuleManager(const WebModuleManager& base) = default;
public:
	WebModuleManager(AlinousCore* core, ThreadContext* ctx);
	void __construct_impl(AlinousCore* core, ThreadContext* ctx);
	virtual ~WebModuleManager() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	FifoList<AbstractWebModule>* list;
	WebModuleHashList* hashList;
	WebHandlerInfo* webInfo;
	String* webRoot;
	AlinousModuleRepository* moduleLoader;
	AlinousCore* core;
public:
	AbstractWebModule* getModule(String* path, bool debug, ThreadContext* ctx);
private:
	AbstractWebModule* loadModule(String* path, bool debug, ThreadContext* ctx);
	AbstractWebModule* handleDirectModule(String* path, bool debug, ThreadContext* ctx);
	AbstractWebModule* handleWebXmlModule(String* path, bool debug, ThreadContext* ctx);
	AlinousWebHtmlXmlModule* handleXmlModule(String* path, ThreadContext* ctx);
	AbstractWebModule* handleWebModule(String* path, bool debug, ThreadContext* ctx);
	AlinousModule* loadAlinousModule(String* path, bool debug, ThreadContext* ctx);
	AlinousWebHtmlXmlModule* handleHtmlModule(String* path, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_SERVER_WEBMODULE_WEBMODULEMANAGER_H_ */
