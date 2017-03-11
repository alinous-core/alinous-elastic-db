#ifndef ALINOUS_REMOTE_REGION_SERVER_SCHEMA_STRATEGY_UNIQUECHECKOPERATION_H_
#define ALINOUS_REMOTE_REGION_SERVER_SCHEMA_STRATEGY_UNIQUECHECKOPERATION_H_
namespace java {namespace util {
template <typename  T> class List;}}

namespace alinous {namespace db {namespace table {
class TableColumnMetadata;}}}

namespace alinous {namespace runtime {namespace variant {
class VariantValue;}}}

namespace alinous {namespace remote {namespace region {namespace server {namespace schema {namespace strategy {
class UniqueOpValue;}}}}}}

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
using ::alinous::db::table::TableColumnMetadata;
using ::alinous::runtime::variant::VariantValue;



class UniqueCheckOperation final : public virtual IObject {
public:
	UniqueCheckOperation(const UniqueCheckOperation& base) = default;
public:
	UniqueCheckOperation(List<TableColumnMetadata>* uniqueColList, ThreadContext* ctx) throw() ;
	void __construct_impl(List<TableColumnMetadata>* uniqueColList, ThreadContext* ctx) throw() ;
	virtual ~UniqueCheckOperation() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	List<TableColumnMetadata>* uniqueColList;
	List<UniqueOpValue>* values;
public:
	void addValue(List<VariantValue>* values, ThreadContext* ctx) throw() ;
	List<TableColumnMetadata>* getUniqueColList(ThreadContext* ctx) throw() ;
	List<UniqueOpValue>* getValues(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}}}

#endif /* end of ALINOUS_REMOTE_REGION_SERVER_SCHEMA_STRATEGY_UNIQUECHECKOPERATION_H_ */
