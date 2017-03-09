#ifndef ALINOUS_REMOTE_REGION_SERVER_SCHEMA_STRATEGY_REGIONPARTITIONTABLEACCESS_H_
#define ALINOUS_REMOTE_REGION_SERVER_SCHEMA_STRATEGY_REGIONPARTITIONTABLEACCESS_H_
namespace alinous {namespace remote {namespace region {namespace server {namespace schema {
class NodeTableClaster;}}}}}

namespace java {namespace util {
template <typename  T> class List;}}

namespace alinous {namespace remote {namespace region {namespace server {namespace schema {
class NodeTableReference;}}}}}

namespace alinous {namespace remote {namespace region {namespace server {namespace schema {namespace strategy {
class RegionShardPartAccess;}}}}}}

namespace alinous {namespace db {namespace table {
class TableMetadata;}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace remote {namespace region {namespace server {namespace schema {namespace strategy {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::ArrayList;
using ::java::util::List;
using ::alinous::db::table::TableMetadata;
using ::alinous::remote::region::server::schema::NodeTableClaster;
using ::alinous::remote::region::server::schema::NodeTableReference;



class RegionPartitionTableAccess final : public virtual IObject {
public:
	RegionPartitionTableAccess(const RegionPartitionTableAccess& base) = default;
public:
	RegionPartitionTableAccess(NodeTableClaster* table, ThreadContext* ctx) throw() ;
	void __construct_impl(NodeTableClaster* table, ThreadContext* ctx) throw() ;
	virtual ~RegionPartitionTableAccess() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	TableMetadata* metadata;
	List<RegionShardPartAccess>* shardParts;
public:
	TableMetadata* getMetadata(ThreadContext* ctx) throw() ;
	List<RegionShardPartAccess>* getShardParts(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}}}

#endif /* end of ALINOUS_REMOTE_REGION_SERVER_SCHEMA_STRATEGY_REGIONPARTITIONTABLEACCESS_H_ */
