#ifndef ALINOUS_REMOTE_REGION_SERVER_SCHEMA_STRATEGY_INSERTTABLESTRATEGY_H_
#define ALINOUS_REMOTE_REGION_SERVER_SCHEMA_STRATEGY_INSERTTABLESTRATEGY_H_
namespace alinous {namespace remote {namespace region {namespace server {namespace schema {namespace strategy {
class RegionPartitionTableAccess;}}}}}}

namespace alinous {namespace remote {namespace region {namespace server {namespace schema {namespace strategy {
class NodeListBinarySearcher;}}}}}}

namespace java {namespace util {
template <typename  T> class List;}}

namespace alinous {namespace remote {namespace db {namespace client {namespace command {namespace dml {
class InsertPrepareCommand;}}}}}}

namespace alinous {namespace db {namespace trx {
class DbVersionContext;}}}

namespace java {namespace util {
template <typename  T> class Iterator;}}

namespace alinous {namespace remote {namespace region {namespace server {namespace schema {namespace strategy {
class InsertNodeAccessStrategy;}}}}}}

namespace alinous {namespace remote {namespace region {namespace client {namespace command {namespace data {
class ClientNetworkRecord;}}}}}}

namespace alinous {namespace db {namespace table {
class TableMetadata;}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class TableMetadataUniqueCollection;}}}}

namespace alinous {namespace remote {namespace region {namespace server {namespace schema {namespace strategy {
class RegionShardPartAccess;}}}}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanUnique;}}}}

namespace alinous {namespace remote {namespace region {namespace server {namespace schema {
class NodeReference;}}}}}

namespace alinous {namespace db {namespace table {
class TablePartitionRangeCollection;}}}

namespace alinous {namespace db {namespace table {
class TablePartitionKey;}}}

namespace alinous {namespace runtime {namespace variant {
class VariantValue;}}}

namespace java {namespace util {
template <typename  T, typename V> class HashMap;}}

namespace alinous {namespace db {
class AlinousDbException;}}

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
using ::java::util::HashMap;
using ::java::util::Iterator;
using ::java::util::List;
using ::alinous::compile::sql::analyze::ScanUnique;
using ::alinous::compile::sql::analyze::TableMetadataUniqueCollection;
using ::alinous::db::AlinousDbException;
using ::alinous::db::table::TableMetadata;
using ::alinous::db::table::TablePartitionKey;
using ::alinous::db::table::TablePartitionRangeCollection;
using ::alinous::db::trx::DbVersionContext;
using ::alinous::remote::db::client::command::dml::InsertPrepareCommand;
using ::alinous::remote::region::client::command::data::ClientNetworkRecord;
using ::alinous::remote::region::server::schema::NodeReference;
using ::alinous::runtime::variant::VariantValue;



class InsertTableStrategy final : public virtual IObject {
public:
	InsertTableStrategy(const InsertTableStrategy& base) = default;
public:
	InsertTableStrategy(long long commitId, RegionPartitionTableAccess* tableAccess, ThreadContext* ctx) throw() ;
	void __construct_impl(long long commitId, RegionPartitionTableAccess* tableAccess, ThreadContext* ctx) throw() ;
	virtual ~InsertTableStrategy() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	long long commitId;
	RegionPartitionTableAccess* tableAccess;
	NodeListBinarySearcher* nodeSearcher;
	HashMap<String,InsertNodeAccessStrategy>* nodeStrategy;
public:
	List<InsertPrepareCommand>* toPrepareCommand(DbVersionContext* vctx, long long newCommitId, ThreadContext* ctx) throw() ;
	void build(ArrayList<ClientNetworkRecord>* list, ThreadContext* ctx);
	long long getCommitId(ThreadContext* ctx) throw() ;
private:
	void buildNodeStrategy(ClientNetworkRecord* record, TableMetadataUniqueCollection* uniqueCollection, ThreadContext* ctx);
	void buildRecordStrategy(List<RegionShardPartAccess>* nodeList, ClientNetworkRecord* record, ThreadContext* ctx);
	void addUniqueCheck(RegionShardPartAccess* node, ClientNetworkRecord* record, TableMetadataUniqueCollection* uniqueCollection, ThreadContext* ctx) throw() ;
	void buildUniqueStrategy(RegionShardPartAccess* node, ClientNetworkRecord* record, TableMetadataUniqueCollection* uniqueCollection, ThreadContext* ctx) throw() ;
	InsertNodeAccessStrategy* getInsertNodeAccessStorategy(NodeReference* nodeAccessRef, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}}}

#endif /* end of ALINOUS_REMOTE_REGION_SERVER_SCHEMA_STRATEGY_INSERTTABLESTRATEGY_H_ */
