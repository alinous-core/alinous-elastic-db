#ifndef ALINOUS_REMOTE_REGION_NODEREFERENCEMANAGER_H_
#define ALINOUS_REMOTE_REGION_NODEREFERENCEMANAGER_H_
namespace alinous {namespace remote {namespace region {namespace client {namespace command {namespace data {
class ClientStructureMetadata;}}}}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace java {namespace util {
template <typename  T> class Iterator;}}

namespace alinous {namespace remote {namespace region {
class NodeRegionSchema;}}}

namespace alinous {namespace remote {namespace region {namespace client {namespace command {namespace data {
class ClientSchemaData;}}}}}}

namespace alinous {namespace remote {namespace db {namespace client {namespace command {namespace data {
class SchemasStructureInfoData;}}}}}}

namespace java {namespace util {
template <typename  T, typename V> class Map;}}

namespace alinous {namespace remote {namespace db {namespace client {namespace command {namespace data {
class SchemaData;}}}}}}

namespace alinous {namespace remote {namespace monitor {namespace client {namespace command {namespace data {
class RegionInfoData;}}}}}}

namespace alinous {namespace remote {namespace monitor {
class RegionNodeInfo;}}}

namespace alinous {namespace remote {namespace region {
class NodeCluster;}}}

namespace java {namespace util {
template <typename  T> class List;}}

namespace alinous {namespace remote {namespace region {
class NodeReference;}}}

namespace alinous {namespace db {namespace table {
class TableMetadata;}}}

namespace alinous {namespace db {
class AlinousDbException;}}

namespace alinous {namespace remote {namespace region {
class RegionShardTable;}}}

namespace alinous {namespace remote {namespace region {
class NodeTableClaster;}}}

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
using ::java::util::List;
using ::java::util::Map;
using ::alinous::db::AlinousDbException;
using ::alinous::db::table::TableMetadata;
using ::alinous::lock::LockObject;
using ::alinous::remote::db::client::command::data::SchemaData;
using ::alinous::remote::db::client::command::data::SchemasStructureInfoData;
using ::alinous::remote::monitor::RegionNodeInfo;
using ::alinous::remote::monitor::client::command::data::RegionInfoData;
using ::alinous::remote::region::client::command::data::ClientSchemaData;
using ::alinous::remote::region::client::command::data::ClientStructureMetadata;
using ::alinous::system::AlinousException;



class NodeReferenceManager final : public virtual IObject {
public:
	NodeReferenceManager(const NodeReferenceManager& base) = default;
public:
	NodeReferenceManager(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~NodeReferenceManager() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	Map<String,NodeRegionSchema>* schemaDictinary;
	long long schemaVersion;
	NodeCluster* nodeReferences;
	LockObject* lock;
public:
	long long getClientData(ClientStructureMetadata* data, ThreadContext* ctx);
	void syncSchemeTables(String* regionName, ThreadContext* ctx);
	void syncNodeReference(RegionInfoData* data, ThreadContext* ctx) throw() ;
	void dispose(ThreadContext* ctx) throw() ;
	long long getSchemaVersion(ThreadContext* ctx) throw() ;
	void createSchema(String* schemaName, ThreadContext* ctx);
	void createTable(TableMetadata* meta, ThreadContext* ctx);
	RegionShardTable* getCluster(String* schemaName, String* tableName, ThreadContext* ctx) throw() ;
private:
	void doSyncScmema(SchemasStructureInfoData* data, ThreadContext* ctx) throw() ;
	NodeRegionSchema* getNodeRegionSchema(String* schemaName, ThreadContext* ctx) throw() ;
	void doSyncRegionNodes(RegionNodeInfo* nodeInfo, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_REMOTE_REGION_NODEREFERENCEMANAGER_H_ */
