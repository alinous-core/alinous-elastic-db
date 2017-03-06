#ifndef ALINOUS_RUNTIME_DBIF_DATASOURCEMANAGER_H_
#define ALINOUS_RUNTIME_DBIF_DATASOURCEMANAGER_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace system {
class AlinousCore;}}

namespace alinous {namespace system {namespace config {
class AlinousConfig;}}}

namespace alinous {namespace system {namespace config {
class AlinousDbInfo;}}}

namespace java {namespace util {
template <typename  T> class Iterator;}}

namespace alinous {namespace system {namespace config {
class AlinousDbInstanceInfo;}}}

namespace alinous {namespace runtime {namespace dbif {
class IDatabaseDriver;}}}

namespace alinous {namespace runtime {namespace dbif {
class AlinousDatabaseHandler;}}}

namespace alinous {namespace system {
class ISystemLog;}}

namespace alinous {namespace db {
class AlinousDbException;}}

namespace java {namespace util {
template <typename  T, typename V> class HashMap;}}

namespace alinous {namespace system {
class AlinousException;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace runtime {namespace dbif {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::HashMap;
using ::java::util::Iterator;
using ::alinous::db::AlinousDbException;
using ::alinous::system::AlinousCore;
using ::alinous::system::AlinousException;
using ::alinous::system::ISystemLog;
using ::alinous::system::config::AlinousConfig;
using ::alinous::system::config::AlinousDbInfo;
using ::alinous::system::config::AlinousDbInstanceInfo;



class DataSourceManager final : public virtual IObject {
public:
	DataSourceManager(const DataSourceManager& base) = default;
public:
	DataSourceManager(AlinousCore* core, ThreadContext* ctx);
	void __construct_impl(AlinousCore* core, ThreadContext* ctx);
	virtual ~DataSourceManager() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	HashMap<String,IDatabaseDriver>* drivers;
	AlinousCore* core;
public:
	void init(ThreadContext* ctx);
	IDatabaseDriver* get(String* id, ThreadContext* ctx) throw() ;
	void dispose(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_RUNTIME_DBIF_DATASOURCEMANAGER_H_ */
