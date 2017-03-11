#ifndef ALINOUS_REMOTE_REGION_SERVER_SCHEMA_STRATEGY_INSERTNODEACCESSSTRATEGY_H_
#define ALINOUS_REMOTE_REGION_SERVER_SCHEMA_STRATEGY_INSERTNODEACCESSSTRATEGY_H_
namespace alinous {namespace remote {namespace region {namespace server {namespace schema {
class NodeReference;}}}}}

namespace java {namespace util {
template <typename  T> class List;}}

namespace alinous {namespace db {namespace table {
class TableColumnMetadata;}}}

namespace alinous {namespace runtime {namespace variant {
class VariantValue;}}}

namespace alinous {namespace remote {namespace region {namespace server {namespace schema {namespace strategy {
class UniqueCheckOperation;}}}}}}

namespace java {namespace util {
template <typename  T, typename V> class HashMap;}}

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
using ::java::util::HashMap;
using ::java::util::List;
using ::alinous::db::table::TableColumnMetadata;
using ::alinous::remote::region::server::schema::NodeReference;
using ::alinous::runtime::variant::VariantValue;



class InsertNodeAccessStrategy final : public virtual IObject {
public:
	InsertNodeAccessStrategy(const InsertNodeAccessStrategy& base) = default;
public:
	InsertNodeAccessStrategy(NodeReference* nodeAccessRef, ThreadContext* ctx) throw() ;
	void __construct_impl(NodeReference* nodeAccessRef, ThreadContext* ctx) throw() ;
	virtual ~InsertNodeAccessStrategy() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	NodeReference* nodeAccessRef;
	HashMap<String,UniqueCheckOperation>* uniqueCheckOps;
public:
	void addUniqueCheckOperation(List<TableColumnMetadata>* uniqueColList, List<VariantValue>* values, ThreadContext* ctx) throw() ;
	NodeReference* getNodeAccessRef(ThreadContext* ctx) throw() ;
private:
	UniqueCheckOperation* getOperation(List<TableColumnMetadata>* uniqueColList, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}}}

#endif /* end of ALINOUS_REMOTE_REGION_SERVER_SCHEMA_STRATEGY_INSERTNODEACCESSSTRATEGY_H_ */
