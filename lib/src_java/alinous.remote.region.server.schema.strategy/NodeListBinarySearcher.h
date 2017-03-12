#ifndef ALINOUS_REMOTE_REGION_SERVER_SCHEMA_STRATEGY_NODELISTBINARYSEARCHER_H_
#define ALINOUS_REMOTE_REGION_SERVER_SCHEMA_STRATEGY_NODELISTBINARYSEARCHER_H_
namespace java {namespace util {
template <typename  T> class List;}}

namespace alinous {namespace remote {namespace region {namespace server {namespace schema {namespace strategy {
class RegionShardPartAccess;}}}}}}

namespace alinous {namespace db {namespace table {
class IDatabaseRecord;}}}

namespace alinous {namespace db {
class AlinousDbException;}}

namespace alinous {namespace db {namespace table {
class TablePartitionRangeCollection;}}}

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
using ::java::util::List;
using ::alinous::db::AlinousDbException;
using ::alinous::db::table::IDatabaseRecord;
using ::alinous::db::table::TablePartitionRangeCollection;



class NodeListBinarySearcher final : public virtual IObject {
public:
	NodeListBinarySearcher(const NodeListBinarySearcher& base) = default;
public:
	NodeListBinarySearcher(List<RegionShardPartAccess>* nodeList, ThreadContext* ctx) throw() ;
	void __construct_impl(List<RegionShardPartAccess>* nodeList, ThreadContext* ctx) throw() ;
	virtual ~NodeListBinarySearcher() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	List<RegionShardPartAccess>* nodeList;
public:
	RegionShardPartAccess* searchNode(IDatabaseRecord* record, ThreadContext* ctx);
private:
	RegionShardPartAccess* binarySearch(List<RegionShardPartAccess>* nodeList, IDatabaseRecord* record, ThreadContext* ctx) throw() ;
	int compareTo(TablePartitionRangeCollection* collectionValue, IDatabaseRecord* record, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}}}

#endif /* end of ALINOUS_REMOTE_REGION_SERVER_SCHEMA_STRATEGY_NODELISTBINARYSEARCHER_H_ */
