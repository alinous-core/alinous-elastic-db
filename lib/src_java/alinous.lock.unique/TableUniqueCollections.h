#ifndef ALINOUS_LOCK_UNIQUE_TABLEUNIQUECOLLECTIONS_H_
#define ALINOUS_LOCK_UNIQUE_TABLEUNIQUECOLLECTIONS_H_
namespace alinous {namespace lock {namespace unique {
class UniqueExclusiveLock;}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanUnique;}}}}

namespace alinous {namespace db {namespace table {
class IDatabaseRecord;}}}

namespace alinous {namespace db {namespace table {
class TablePartitionKey;}}}

namespace alinous {namespace lock {namespace unique {
class ColumnsUniqueCollections;}}}

namespace java {namespace util {
template <typename  T> class Iterator;}}

namespace java {namespace util {
template <typename  T, typename V> class Map;}}

namespace java {namespace util {
template <typename  T, typename V> class HashMap;}}

namespace alinous {namespace lock {
class LockObject;}}

namespace java {namespace io {
class IOException;}}

namespace alinous {namespace btree {
class BTreeException;}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace lock {namespace unique {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::IOException;
using ::java::util::HashMap;
using ::java::util::Iterator;
using ::java::util::Map;
using ::alinous::btree::BTreeException;
using ::alinous::compile::sql::analyze::ScanUnique;
using ::alinous::db::table::IDatabaseRecord;
using ::alinous::db::table::TablePartitionKey;
using ::alinous::lock::LockObject;
using ::alinous::runtime::dom::VariableException;
using ::alinous::system::AlinousException;



class TableUniqueCollections final : public virtual IObject {
public:
	TableUniqueCollections(const TableUniqueCollections& base) = default;
public:
	TableUniqueCollections(ThreadContext* ctx) throw()  : IObject(ctx), uniqueLocks(GCUtils<Map<String,ColumnsUniqueCollections> >::ins(this, (new(ctx) HashMap<String,ColumnsUniqueCollections>(ctx)), ctx, __FILEW__, __LINE__, L"")), lock(__GC_INS(this, (new(ctx) LockObject(ctx)), LockObject))
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~TableUniqueCollections() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	Map<String,ColumnsUniqueCollections>* uniqueLocks;
	LockObject* lock;
public:
	UniqueExclusiveLock* lockWithCheck(ScanUnique* unique, IDatabaseRecord* record, bool throwex, ThreadContext* ctx);
	bool unlock(ScanUnique* unique, IDatabaseRecord* record, ThreadContext* ctx) throw() ;
	UniqueExclusiveLock* findLock(ScanUnique* unique, IDatabaseRecord* record, ThreadContext* ctx);
	void dispose(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_LOCK_UNIQUE_TABLEUNIQUECOLLECTIONS_H_ */
