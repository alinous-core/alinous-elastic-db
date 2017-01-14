#ifndef ALINOUS_REMOTE_REGION_NODEREFERENCEMANAGER_H_
#define ALINOUS_REMOTE_REGION_NODEREFERENCEMANAGER_H_
namespace java {namespace util {
template <typename  T> class List;}}

namespace alinous {namespace remote {namespace db {namespace command {namespace data {
class SchemasStructureInfoData;}}}}}

namespace java {namespace util {
template <typename  T> class Iterator;}}

namespace alinous {namespace remote {namespace region {
class NodeCluster;}}}

namespace alinous {namespace remote {namespace monitor {namespace command {namespace data {
class RegionInfoData;}}}}}

namespace java {namespace util {
template <typename  T, typename V> class Map;}}

namespace alinous {namespace remote {namespace monitor {
class RegionNodeInfo;}}}

namespace alinous {namespace remote {namespace region {
class NodeTableClaster;}}}

namespace java {namespace util {
template <typename  T, typename V> class HashMap;}}

namespace alinous {namespace lock {
class LockObject;}}

namespace alinous {namespace system {
class AlinousException;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace remote {namespace region {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::ArrayList;
using ::java::util::HashMap;
using ::java::util::Iterator;
using ::java::util::List;
using ::java::util::Map;
using ::alinous::lock::LockObject;
using ::alinous::remote::db::command::data::SchemasStructureInfoData;
using ::alinous::remote::monitor::RegionNodeInfo;
using ::alinous::remote::monitor::command::data::RegionInfoData;
using ::alinous::system::AlinousException;



class NodeReferenceManager final : public virtual IObject {
public:
	NodeReferenceManager(const NodeReferenceManager& base) = default;
public:
	NodeReferenceManager(ThreadContext* ctx) throw()  : IObject(ctx), tablesDictinary(GCUtils<Map<String,NodeTableClaster> >::ins(this, (new(ctx) HashMap<String,NodeTableClaster>(ctx)), ctx, __FILEW__, __LINE__, L"")), revision(0), nodeReferences(GCUtils<HashMap<String,NodeCluster> >::ins(this, (new(ctx) HashMap<String,NodeCluster>(ctx)), ctx, __FILEW__, __LINE__, L"")), lock(__GC_INS(this, (new(ctx) LockObject(ctx)), LockObject))
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~NodeReferenceManager() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	Map<String,NodeTableClaster>* tablesDictinary;
	long long revision;
	HashMap<String,NodeCluster>* nodeReferences;
	LockObject* lock;
public:
	void syncSchemeTables(ThreadContext* ctx);
	void syncNodeReference(RegionInfoData* data, ThreadContext* ctx) throw() ;
	void dispose(ThreadContext* ctx) throw() ;
	Map<String,NodeTableClaster>* getTablesDictinary(ThreadContext* ctx) throw() ;
	long long getRevision(ThreadContext* ctx) throw() ;
private:
	void doSyncSchemeTables(ThreadContext* ctx);
	void doSyncRegionNodes(Map<String,RegionNodeInfo>* regionsMap, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_REMOTE_REGION_NODEREFERENCEMANAGER_H_ */
