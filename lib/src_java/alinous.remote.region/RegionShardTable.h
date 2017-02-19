#ifndef ALINOUS_REMOTE_REGION_REGIONSHARDTABLE_H_
#define ALINOUS_REMOTE_REGION_REGIONSHARDTABLE_H_
namespace alinous {namespace remote {namespace region {
class NodeTableClaster;}}}

namespace java {namespace util {
template <typename  T> class List;}}

namespace alinous {namespace remote {namespace region {
class NodeTableReference;}}}

namespace alinous {namespace remote {namespace region {
class RegionShardPart;}}}

namespace alinous {namespace remote {namespace region {namespace command {namespace data {
class ClientNetworkRecord;}}}}}

namespace alinous {namespace db {namespace table {
class TableMetadata;}}}

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
using ::java::util::List;
using ::alinous::db::table::TableMetadata;
using ::alinous::remote::region::command::data::ClientNetworkRecord;



class RegionShardTable final : public virtual IObject {
public:
	RegionShardTable(const RegionShardTable& base) = default;
public:
	RegionShardTable(NodeTableClaster* table, ThreadContext* ctx) throw() ;
	void __construct_impl(NodeTableClaster* table, ThreadContext* ctx) throw() ;
	virtual ~RegionShardTable() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	TableMetadata* metadata;
	List<RegionShardPart>* shardParts;
	long long commitId;
public:
	long long getCommitId(ThreadContext* ctx) throw() ;
	void setCommitId(long long commitId, ThreadContext* ctx) throw() ;
	void putRecords(ArrayList<ClientNetworkRecord>* list, ThreadContext* ctx) throw() ;
	TableMetadata* getMetadata(ThreadContext* ctx) throw() ;
private:
	void handleRecord(ClientNetworkRecord* record, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_REMOTE_REGION_REGIONSHARDTABLE_H_ */
