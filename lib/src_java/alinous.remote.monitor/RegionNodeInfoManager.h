#ifndef ALINOUS_REMOTE_MONITOR_REGIONNODEINFOMANAGER_H_
#define ALINOUS_REMOTE_MONITOR_REGIONNODEINFOMANAGER_H_
namespace alinous {namespace remote {namespace monitor {namespace command {namespace data {
class RegionInfoData;}}}}}

namespace alinous {namespace remote {namespace monitor {
class RegionNodeInfo;}}}

namespace alinous {namespace remote {namespace monitor {
class RegionNodeInfoManager;}}}

namespace alinous {namespace system {namespace config {namespace remote {
class Monitor;}}}}

namespace alinous {namespace system {namespace config {namespace remote {
class Regions;}}}}

namespace java {namespace util {
template <typename  T> class List;}}

namespace alinous {namespace system {namespace config {namespace remote {
class Region;}}}}

namespace alinous {namespace db {
class AlinousDbException;}}

namespace java {namespace util {
template <typename  T, typename V> class Map;}}

namespace java {namespace util {
template <typename  T, typename V> class HashMap;}}

namespace alinous {namespace lock {
class LockObject;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace remote {namespace monitor {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::HashMap;
using ::java::util::List;
using ::java::util::Map;
using ::alinous::db::AlinousDbException;
using ::alinous::lock::LockObject;
using ::alinous::remote::monitor::command::data::RegionInfoData;
using ::alinous::system::config::remote::Monitor;
using ::alinous::system::config::remote::Region;
using ::alinous::system::config::remote::Regions;



class RegionNodeInfoManager final : public virtual IObject {
public:
	RegionNodeInfoManager(const RegionNodeInfoManager& base) = default;
public:
	RegionNodeInfoManager(ThreadContext* ctx) throw()  : IObject(ctx), regionsMap(GCUtils<Map<String,RegionNodeInfo> >::ins(this, (new(ctx) HashMap<String,RegionNodeInfo>(ctx)), ctx, __FILEW__, __LINE__, L"")), lock(__GC_INS(this, (new(ctx) LockObject(ctx)), LockObject)), nodeClusterRevision(0)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~RegionNodeInfoManager() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	Map<String,RegionNodeInfo>* regionsMap;
	LockObject* lock;
	long long nodeClusterRevision;
public:
	void getRegionInfoData(RegionInfoData* data, String* region, ThreadContext* ctx) throw() ;
	RegionNodeInfoManager* init(Monitor* monitorConf, ThreadContext* ctx);
	long long updateNodeClusterRevision(long long nodeClusterRevision, ThreadContext* ctx) throw() ;
	long long getNodeClusterRevision(ThreadContext* ctx) throw() ;
	void setNodeClusterRevision(long long nodeClusterRevision, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_REMOTE_MONITOR_REGIONNODEINFOMANAGER_H_ */
