#ifndef ALINOUS_REMOTE_REGION_NODEREGIONSCHEMA_H_
#define ALINOUS_REMOTE_REGION_NODEREGIONSCHEMA_H_
namespace alinous {namespace remote {namespace region {namespace client {namespace command {namespace data {
class ClientSchemaData;}}}}}}

namespace java {namespace util {
template <typename  T> class Iterator;}}

namespace alinous {namespace remote {namespace region {
class NodeTableClaster;}}}

namespace alinous {namespace db {namespace table {
class TableMetadata;}}}

namespace alinous {namespace remote {namespace region {namespace client {namespace command {namespace data {
class ClientTableData;}}}}}}

namespace alinous {namespace remote {namespace db {namespace client {namespace command {namespace data {
class SchemaData;}}}}}}

namespace alinous {namespace remote {namespace region {
class NodeCluster;}}}

namespace java {namespace util {
template <typename  T, typename V> class Map;}}

namespace alinous {namespace remote {namespace db {namespace client {namespace command {namespace data {
class TableClusterData;}}}}}}

namespace java {namespace util {
template <typename  T, typename V> class HashMap;}}

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
using ::alinous::db::table::TableMetadata;
using ::alinous::remote::db::client::command::data::SchemaData;
using ::alinous::remote::db::client::command::data::TableClusterData;
using ::alinous::remote::region::client::command::data::ClientSchemaData;
using ::alinous::remote::region::client::command::data::ClientTableData;



class NodeRegionSchema final : public virtual IObject {
public:
	NodeRegionSchema(const NodeRegionSchema& base) = default;
public:
	NodeRegionSchema(String* schemaName, ThreadContext* ctx) throw() ;
	void __construct_impl(String* schemaName, ThreadContext* ctx) throw() ;
	virtual ~NodeRegionSchema() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	Map<String,NodeTableClaster>* tablesDictinary;
	String* schemaName;
public:
	ClientSchemaData* toClientData(ThreadContext* ctx) throw() ;
	void updateTableClusters(SchemaData* scdata, NodeCluster* nodeAccessRefs, ThreadContext* ctx) throw() ;
	void dispose(ThreadContext* ctx) throw() ;
	NodeTableClaster* getNodeTableCluster(String* tableName, ThreadContext* ctx) throw() ;
	String* getSchemaName(ThreadContext* ctx) throw() ;
private:
	NodeTableClaster* getNodeClusterOrInit(String* clusterName, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_REMOTE_REGION_NODEREGIONSCHEMA_H_ */
