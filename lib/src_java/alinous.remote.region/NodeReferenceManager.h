#ifndef ALINOUS_REMOTE_REGION_NODEREFERENCEMANAGER_H_
#define ALINOUS_REMOTE_REGION_NODEREFERENCEMANAGER_H_
namespace alinous {namespace remote {namespace region {namespace command {namespace data {
class ClientStructureMetadata;}}}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace java {namespace util {
template <typename  T> class Iterator;}}

namespace alinous {namespace remote {namespace region {
class NodeRegionSchema;}}}

namespace alinous {namespace remote {namespace region {namespace command {namespace data {
class ClientSchemaData;}}}}}

namespace alinous {namespace remote {namespace db {namespace command {namespace data {
class SchemasStructureInfoData;}}}}}

namespace java {namespace util {
template <typename  T, typename V> class Map;}}

namespace alinous {namespace remote {namespace db {namespace command {namespace data {
class SchemaData;}}}}}

namespace alinous {namespace remote {namespace monitor {namespace command {namespace data {
class RegionInfoData;}}}}}

namespace alinous {namespace remote {namespace monitor {
class RegionNodeInfo;}}}

namespace alinous {namespace remote {namespace region {
class NodeCluster;}}}

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

namespace alinous {namespace remote {namespace region {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::HashMap;
using ::java::util::Iterator;
using ::java::util::Map;
using ::alinous::lock::LockObject;
using ::alinous::remote::db::command::data::SchemaData;
using ::alinous::remote::db::command::data::SchemasStructureInfoData;
using ::alinous::remote::monitor::RegionNodeInfo;
using ::alinous::remote::monitor::command::data::RegionInfoData;
using ::alinous::remote::region::command::data::ClientSchemaData;
using ::alinous::remote::region::command::data::ClientStructureMetadata;
using ::alinous::system::AlinousException;



class NodeReferenceManager final : public virtual IObject {
public:
	NodeReferenceManager(const NodeReferenceManager& base) = default;
public:
	NodeReferenceManager(ThreadContext* ctx) throw()  : IObject(ctx), schemaDictinary(GCUtils<Map<String,NodeRegionSchema> >::ins(this, (new(ctx) HashMap<String,NodeRegionSchema>(ctx)), ctx, __FILEW__, __LINE__, L"")), revision(0), nodeReferences(nullptr), lock(__GC_INS(this, (new(ctx) LockObject(ctx)), LockObject))
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~NodeReferenceManager() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	Map<String,NodeRegionSchema>* schemaDictinary;
	long long revision;
	NodeCluster* nodeReferences;
	LockObject* lock;
public:
	long long getClientData(ClientStructureMetadata* data, ThreadContext* ctx);
	void syncSchemeTables(String* regionName, ThreadContext* ctx);
	void syncNodeReference(RegionInfoData* data, ThreadContext* ctx) throw() ;
	void dispose(ThreadContext* ctx) throw() ;
	long long getRevision(ThreadContext* ctx) throw() ;
private:
	void doSyncScmema(SchemasStructureInfoData* data, ThreadContext* ctx) throw() ;
	NodeRegionSchema* getNodeRegionSchema(String* schemaName, ThreadContext* ctx) throw() ;
	void doSyncRegionNodes(RegionNodeInfo* nodeInfo, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_REMOTE_REGION_NODEREFERENCEMANAGER_H_ */
