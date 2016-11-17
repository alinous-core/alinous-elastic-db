#ifndef ALINOUS_DB_TABLE_CACHE_DBRECORDHASHMAINLIST_H_
#define ALINOUS_DB_TABLE_CACHE_DBRECORDHASHMAINLIST_H_
namespace alinous {namespace db {namespace table {namespace cache {
class DbRecordHashMainList;}}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace alinous {namespace db {namespace table {namespace cache {
class DbRecordHashArray;}}}}

namespace alinous {namespace db {namespace table {
class DatabaseRecord;}}}

namespace alinous {namespace db {namespace table {
class DataTableStorageSupport;}}}

namespace alinous {namespace db {namespace table {namespace cache {
class DbREcordHashListIterator;}}}}

namespace java {namespace util {
class BitSet;}}

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
using ::java::util::BitSet;
using ::alinous::db::table::DataTableStorageSupport;
using ::alinous::db::table::DatabaseRecord;
using ::alinous::system::AlinousException;



class DbRecordHashMainList final : public virtual IObject {
public:
	DbRecordHashMainList(const DbRecordHashMainList& base) = default;
public:
	DbRecordHashMainList(ThreadContext* ctx) throw()  : IObject(ctx), MAX_HASH(0), MAX_HASH_MASK(0), arrays(nullptr), bitset(__GC_INS(this, (new(ctx) BitSet(ctx)), BitSet)), numElements(0)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~DbRecordHashMainList() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	int MAX_HASH;
	int MAX_HASH_MASK;
private:
	IArrayObject<DbRecordHashArray>* arrays;
	BitSet* bitset;
	int numElements;
public:
	DbRecordHashMainList* init(int MAX_HASH, ThreadContext* ctx);
	int size(ThreadContext* ctx) throw() ;
	DatabaseRecord* addElement(DatabaseRecord* ptr, ThreadContext* ctx) throw() ;
	bool removeByObj(DatabaseRecord* obj, ThreadContext* ctx) throw() ;
	DatabaseRecord* search(DataTableStorageSupport* table, long long position, ThreadContext* ctx) throw() ;
	void reset(ThreadContext* ctx) throw() ;
	DbREcordHashListIterator* iterator(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_DB_TABLE_CACHE_DBRECORDHASHMAINLIST_H_ */
