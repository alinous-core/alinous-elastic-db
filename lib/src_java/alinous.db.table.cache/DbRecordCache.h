#ifndef ALINOUS_DB_TABLE_CACHE_DBRECORDCACHE_H_
#define ALINOUS_DB_TABLE_CACHE_DBRECORDCACHE_H_
namespace alinous {namespace buffer {
template <typename  T> class FifoIterator;}}

namespace alinous {namespace db {namespace table {
class DatabaseRecord;}}}

namespace alinous {namespace buffer {
template <typename  T> class FifoElement;}}

namespace alinous {namespace db {namespace table {namespace cache {
class DbRecordCache;}}}}

namespace alinous {namespace db {namespace table {namespace cache {
class DbRecordHashMainList;}}}}

namespace alinous {namespace db {namespace table {
class IDatabaseTable;}}}

namespace alinous {namespace db {namespace table {
class DataTableStorageSupport;}}}

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
using ::alinous::buffer::FifoElement;
using ::alinous::buffer::FifoIterator;
using ::alinous::buffer::FifoList;
using ::alinous::concurrent::SpinMutex;
using ::alinous::db::table::DataTableStorageSupport;
using ::alinous::db::table::DatabaseRecord;
using ::alinous::db::table::IDatabaseTable;
using ::alinous::system::AlinousException;



class DbRecordCache final : public virtual IObject {
public:
	DbRecordCache(const DbRecordCache& base) = default;
public:
	DbRecordCache(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
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
	void addCachedRecord(IDatabaseTable* table, DatabaseRecord* record, ThreadContext* ctx);
	DatabaseRecord* loadRecord(DataTableStorageSupport* table, long long position, ThreadContext* ctx);
public:
	static void includes(FifoIterator<DatabaseRecord>* arg0, FifoElement<DatabaseRecord>* arg2, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}

#endif /* end of ALINOUS_DB_TABLE_CACHE_DBRECORDCACHE_H_ */
