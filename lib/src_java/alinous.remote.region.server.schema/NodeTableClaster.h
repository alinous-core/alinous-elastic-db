#ifndef ALINOUS_REMOTE_REGION_SERVER_SCHEMA_NODETABLECLASTER_H_
#define ALINOUS_REMOTE_REGION_SERVER_SCHEMA_NODETABLECLASTER_H_
namespace alinous {namespace remote {namespace db {namespace client {namespace command {namespace data {
class TableClusterData;}}}}}}

namespace alinous {namespace remote {namespace region {namespace server {namespace schema {
class NodeCluster;}}}}}

namespace alinous {namespace remote {namespace db {namespace client {namespace command {namespace data {
class StorageNodeData;}}}}}}

namespace alinous {namespace remote {namespace region {namespace server {namespace schema {
class NodeReference;}}}}}

namespace alinous {namespace db {namespace table {
class TableMetadata;}}}

namespace alinous {namespace db {namespace table {
class TablePartitionRangeCollection;}}}

namespace alinous {namespace remote {namespace region {namespace server {namespace schema {
class NodeTableReference;}}}}}

namespace java {namespace util {
template <typename  T> class List;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace remote {namespace region {namespace server {namespace schema {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::ArrayList;
using ::java::util::List;
using ::alinous::db::table::TableMetadata;
using ::alinous::db::table::TablePartitionRangeCollection;
using ::alinous::remote::db::client::command::data::StorageNodeData;
using ::alinous::remote::db::client::command::data::TableClusterData;



class NodeTableClaster final : public virtual IObject {
public:
	NodeTableClaster(const NodeTableClaster& base) = default;
public:
	NodeTableClaster(String* clusterName, ThreadContext* ctx) throw() ;
	void __construct_impl(String* clusterName, ThreadContext* ctx) throw() ;
	virtual ~NodeTableClaster() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	List<NodeTableReference>* nodes;
	String* clusterName;
	TableMetadata* metadata;
public:
	void updateClusterNodes(TableClusterData* clusterData, NodeCluster* nodeAccessRef, ThreadContext* ctx) throw() ;
	void addNode(NodeTableReference* nodeRef, ThreadContext* ctx) throw() ;
	List<NodeTableReference>* getNodes(ThreadContext* ctx) throw() ;
	void dispose(ThreadContext* ctx) throw() ;
	String* getClusterName(ThreadContext* ctx) throw() ;
	TableMetadata* getMetadata(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}}

#endif /* end of ALINOUS_REMOTE_REGION_SERVER_SCHEMA_NODETABLECLASTER_H_ */
