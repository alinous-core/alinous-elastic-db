#ifndef ALINOUS_DB_TABLE_CACHE_DBRECORDHASHLISTITERATOR_H_
#define ALINOUS_DB_TABLE_CACHE_DBRECORDHASHLISTITERATOR_H_
namespace alinous {namespace db {namespace table {namespace cache {
class DbRecordHashArray;}}}}

namespace java {namespace util {
class BitSet;}}

namespace alinous {namespace db {namespace table {
class DatabaseRecord;}}}

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
using ::alinous::db::table::DatabaseRecord;



class DbREcordHashListIterator final : public virtual IObject {
public:
	DbREcordHashListIterator(const DbREcordHashListIterator& base) = default;
public:
	DbREcordHashListIterator(IArrayObject<DbRecordHashArray>* arrays, BitSet* bitset, long long MAX_HASH, ThreadContext* ctx) throw() ;
	void __construct_impl(IArrayObject<DbRecordHashArray>* arrays, BitSet* bitset, long long MAX_HASH, ThreadContext* ctx) throw() ;
	virtual ~DbREcordHashListIterator() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	long long MAX_HASH;
	int hashCode;
	int index;
	IArrayObject<DbRecordHashArray>* arrays;
	BitSet* bitset;
public:
	bool hasNext(ThreadContext* ctx) throw() ;
	DatabaseRecord* next(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}

#endif /* end of ALINOUS_DB_TABLE_CACHE_DBRECORDHASHLISTITERATOR_H_ */
