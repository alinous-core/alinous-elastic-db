#ifndef ALINOUS_LOCK_UNIQUE_UNIQUEEXCLUSIVELOCKMANAGER_H_
#define ALINOUS_LOCK_UNIQUE_UNIQUEEXCLUSIVELOCKMANAGER_H_
namespace alinous {namespace lock {namespace unique {
class UniqueExclusiveLock;}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanUnique;}}}}

namespace alinous {namespace db {namespace table {
class IDatabaseRecord;}}}

namespace alinous {namespace lock {namespace unique {
class TableUniqueCollections;}}}

namespace java {namespace lang {
class StringBuilder;}}

namespace java {namespace util {
template <typename  T> class List;}}

namespace alinous {namespace db {namespace table {
class TableColumnMetadata;}}}

namespace alinous {namespace runtime {namespace variant {
class VariantValue;}}}

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
using ::java::util::List;
using ::java::util::Map;
using ::alinous::btree::BTreeException;
using ::alinous::compile::sql::analyze::ScanUnique;
using ::alinous::db::table::IDatabaseRecord;
using ::alinous::db::table::TableColumnMetadata;
using ::alinous::lock::LockObject;
using ::alinous::runtime::dom::VariableException;
using ::alinous::runtime::variant::VariantValue;
using ::alinous::system::AlinousException;



class UniqueExclusiveLockManager final : public virtual IObject {
public:
	UniqueExclusiveLockManager(const UniqueExclusiveLockManager& base) = default;
public:
	UniqueExclusiveLockManager(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~UniqueExclusiveLockManager() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	Map<String,TableUniqueCollections>* tables;
	LockObject* lock;
public:
	UniqueExclusiveLock* lockWithCheck(ScanUnique* unique, IDatabaseRecord* record, bool throwex, ThreadContext* ctx);
	UniqueExclusiveLock* lockWithCheck(ScanUnique* unique, String* lockString, bool throwex, ThreadContext* ctx);
	void unlock(UniqueExclusiveLock* lock, ThreadContext* ctx) throw() ;
	UniqueExclusiveLock* findLock(ScanUnique* unique, IDatabaseRecord* record, ThreadContext* ctx);
	void dispose(ThreadContext* ctx) throw() ;
private:
	String* getLockValueString(ScanUnique* unique, IDatabaseRecord* value, ThreadContext* ctx) throw() ;
	TableUniqueCollections* getTableUnique(String* fullName, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_LOCK_UNIQUE_UNIQUEEXCLUSIVELOCKMANAGER_H_ */
