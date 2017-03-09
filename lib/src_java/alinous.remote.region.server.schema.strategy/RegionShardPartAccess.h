#ifndef ALINOUS_REMOTE_REGION_SERVER_SCHEMA_STRATEGY_REGIONSHARDPARTACCESS_H_
#define ALINOUS_REMOTE_REGION_SERVER_SCHEMA_STRATEGY_REGIONSHARDPARTACCESS_H_
namespace alinous {namespace remote {namespace region {namespace server {namespace schema {
class NodeTableReference;}}}}}

namespace alinous {namespace db {namespace table {
class TablePartitionRangeCollection;}}}

namespace alinous {namespace remote {namespace region {namespace server {namespace schema {
class NodeReference;}}}}}

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
using ::alinous::db::table::TablePartitionRangeCollection;
using ::alinous::remote::region::server::schema::NodeReference;
using ::alinous::remote::region::server::schema::NodeTableReference;



class RegionShardPartAccess final : public virtual IObject {
public:
	RegionShardPartAccess(const RegionShardPartAccess& base) = default;
public:
	RegionShardPartAccess(NodeTableReference* nodeRef, ThreadContext* ctx) throw() ;
	void __construct_impl(NodeTableReference* nodeRef, ThreadContext* ctx) throw() ;
	virtual ~RegionShardPartAccess() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	TablePartitionRangeCollection* partitionRange;
	NodeReference* nodeAccessRef;
public:
	TablePartitionRangeCollection* getPartitionRange(ThreadContext* ctx) throw() ;
	NodeReference* getNodeAccessRef(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}}}

#endif /* end of ALINOUS_REMOTE_REGION_SERVER_SCHEMA_STRATEGY_REGIONSHARDPARTACCESS_H_ */
