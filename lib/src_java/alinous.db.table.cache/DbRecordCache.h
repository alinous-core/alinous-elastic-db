#ifndef ALINOUS_DB_TABLE_CACHE_DBRECORDCACHE_H_
#define ALINOUS_DB_TABLE_CACHE_DBRECORDCACHE_H_
namespace alinous {namespace db {namespace table {namespace cache {
class DbRecordCache;}}}}

namespace alinous {namespace db {namespace table {namespace cache {
class DbRecordHashMainList;}}}}

namespace alinous {namespace db {namespace table {
class DataTableStorageSupport;}}}

namespace alinous {namespace db {namespace table {
class DatabaseRecord;}}}

namespace alinous {namespace buffer {
template <typename  T> class FifoList;}}

namespace alinous {namespace concurrent {
class SpinMutex;}}

namespace alinous {namespace system {
class AlinousException;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace db {namespace table {namespace cache {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::buffer::FifoList;
using ::alinous::concurrent::SpinMutex;
using ::alinous::db::table::DataTableStorageSupport;
using ::alinous::db::table::DatabaseRecord;
using ::alinous::system::AlinousException;



class DbRecordCache final : public virtual IObject {
public:
	DbRecordCache(const DbRecordCache& base) = default;
public:
	DbRecordCache(ThreadContext* ctx) throw()  : IObject(ctx), fifo(GCUtils<FifoList<DatabaseRecord> >::ins(this, (new(ctx) FifoList<DatabaseRecord>(ctx)), ctx, __FILEW__, __LINE__, L"")), mainList(nullptr), spin(__GC_INS(this, (new(ctx) SpinMutex(ctx)), SpinMutex)), num(0), MAX_HASH(0)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~DbRecordCache() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	FifoList<DatabaseRecord>* fifo;
	DbRecordHashMainList* mainList;
	SpinMutex* spin;
	int num;
	int MAX_HASH;
public:
	DbRecordCache* init(int MAX_HASH, ThreadContext* ctx);
	void addCachedRecord(DataTableStorageSupport* table, DatabaseRecord* record, ThreadContext* ctx);
	DatabaseRecord* loadRecord(DataTableStorageSupport* table, long long position, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_DB_TABLE_CACHE_DBRECORDCACHE_H_ */
