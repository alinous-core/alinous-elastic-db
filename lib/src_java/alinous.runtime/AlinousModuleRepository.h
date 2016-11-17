#ifndef ALINOUS_RUNTIME_ALINOUSMODULEREPOSITORY_H_
#define ALINOUS_RUNTIME_ALINOUSMODULEREPOSITORY_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace system {
class AlinousCore;}}

namespace alinous {namespace system {namespace config {
class SystemInfo;}}}

namespace alinous {namespace system {namespace config {
class WebHandlerInfo;}}}

namespace alinous {namespace runtime {
class AlinousModule;}}

namespace java {namespace io {
class File;}}

namespace alinous {namespace runtime {
class ModuleNotFoundException;}}

namespace java {namespace io {
class FileInputStream;}}

namespace alinous {namespace compile {
class AlinousSrc;}}

namespace alinous {namespace compile {
class AlinousPlusParser;}}

namespace java {namespace io {
class IOException;}}

namespace alinous {namespace runtime {
class CompileErrorException;}}

namespace java {namespace lang {
class Throwable;}}

namespace java {namespace lang {
class StringBuffer;}}

namespace java {namespace util {
template <typename  T, typename V> class HashMap;}}

namespace java {namespace io {
class FileNotFoundException;}}

namespace alinous {namespace compile {
class IncludePreprocessor;}}

namespace alinous {namespace compile {
class ParseException;}}

namespace alinous {namespace db {
class AlinousDbException;}}

namespace alinous {namespace db {namespace table {
class DatabaseException;}}}

namespace alinous {namespace runtime {namespace engine {
class AlinousNullPointerException;}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace runtime {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::File;
using ::java::io::FileInputStream;
using ::java::io::FileNotFoundException;
using ::java::io::IOException;
using ::java::util::ArrayList;
using ::java::util::HashMap;
using ::alinous::compile::AlinousPlusParser;
using ::alinous::compile::AlinousSrc;
using ::alinous::compile::IncludePreprocessor;
using ::alinous::compile::ParseException;
using ::alinous::db::AlinousDbException;
using ::alinous::db::table::DatabaseException;
using ::alinous::runtime::engine::AlinousNullPointerException;
using ::alinous::system::AlinousCore;
using ::alinous::system::AlinousException;
using ::alinous::system::config::SystemInfo;
using ::alinous::system::config::WebHandlerInfo;



class AlinousModuleRepository final : public virtual IObject {
public:
	AlinousModuleRepository(const AlinousModuleRepository& base) = default;
public:
	AlinousModuleRepository(AlinousCore* core, ThreadContext* ctx) throw() ;
	void __construct_impl(AlinousCore* core, ThreadContext* ctx) throw() ;
	virtual ~AlinousModuleRepository() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	HashMap<String,AlinousModule>* modules;
	AlinousCore* core;
	ArrayList<String>* searchPath;
public:
	static String* encode;
public:
	AlinousModule* getModule(String* path, bool debug, ThreadContext* ctx);
	AlinousModule* getModule(String* path, ArrayList<String>* once, bool isInclude, bool debug, ThreadContext* ctx);
private:
	AlinousModule* loadModule(String* path, ArrayList<String>* once, bool isInclude, bool debug, ThreadContext* ctx);
	File* findModuleFile(String* path, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}

#endif /* end of ALINOUS_RUNTIME_ALINOUSMODULEREPOSITORY_H_ */
