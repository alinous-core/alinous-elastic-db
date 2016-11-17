#ifndef ALINOUS_DB_TABLE_CACHE_DBRECORDHASHARRAY_H_
#define ALINOUS_DB_TABLE_CACHE_DBRECORDHASHARRAY_H_
namespace alinous {namespace db {namespace table {
class DatabaseRecord;}}}

namespace alinous {namespace db {namespace table {
class DataTableStorageSupport;}}}

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
using ::java::util::ArrayList;
using ::alinous::db::table::DataTableStorageSupport;
using ::alinous::db::table::DatabaseRecord;



class DbRecordHashArray final : public virtual IObject {
public:
	DbRecordHashArray(const DbRecordHashArray& base) = default;
public:
	DbRecordHashArray(int i, ThreadContext* ctx) throw() ;
	void __construct_impl(int i, ThreadContext* ctx) throw() ;
	virtual ~DbRecordHashArray() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	ArrayList<DatabaseRecord>* list;
public:
	void add(DatabaseRecord* ptr, ThreadContext* ctx) throw() ;
	bool removeByObj(DatabaseRecord* obj, ThreadContext* ctx) throw() ;
	int size(ThreadContext* ctx) throw() ;
	DatabaseRecord* search(DataTableStorageSupport* table, long long position, ThreadContext* ctx) throw() ;
	void reset(ThreadContext* ctx) throw() ;
	DatabaseRecord* get(int i, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_DB_TABLE_CACHE_DBRECORDHASHARRAY_H_ */
