#ifndef ALINOUS_LOCK_UNIQUE_UNIQUEEXCLUSIVELOCKCLIENT_H_
#define ALINOUS_LOCK_UNIQUE_UNIQUEEXCLUSIVELOCKCLIENT_H_
namespace alinous {namespace lock {namespace unique {
class UniqueExclusiveLockManager;}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanUnique;}}}}

namespace alinous {namespace db {namespace table {
class IDatabaseRecord;}}}

namespace alinous {namespace lock {namespace unique {
class UniqueExclusiveLock;}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace java {namespace io {
class IOException;}}

namespace java {namespace lang {
class InterruptedException;}}

namespace alinous {namespace btree {
class BTreeException;}}

namespace java {namespace util {
template <typename  T> class Iterator;}}

namespace alinous {namespace lock {
class LockObject;}}

namespace java {namespace util {
template <typename  T, typename V> class Map;}}

namespace java {namespace util {
template <typename  T, typename V> class HashMap;}}

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
using ::alinous::lock::LockObject;
using ::alinous::runtime::dom::VariableException;
using ::alinous::system::AlinousException;



class UniqueExclusiveLockClient final : public virtual IObject {
public:
	UniqueExclusiveLockClient(const UniqueExclusiveLockClient& base) = default;
public:
	UniqueExclusiveLockClient(UniqueExclusiveLockManager* mgr, ThreadContext* ctx) throw() ;
	void __construct_impl(UniqueExclusiveLockManager* mgr, ThreadContext* ctx) throw() ;
	virtual ~UniqueExclusiveLockClient() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	UniqueExclusiveLockManager* mgr;
	LockObject* lock;
	Map<String,UniqueExclusiveLock>* uniqueLocks;
public:
	void lockWithCheck(ScanUnique* unique, IDatabaseRecord* record, bool throwex, ThreadContext* ctx);
	bool checkLocking(ScanUnique* unique, IDatabaseRecord* value, ThreadContext* ctx);
	void reset(ThreadContext* ctx) throw() ;
	void dispose(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_LOCK_UNIQUE_UNIQUEEXCLUSIVELOCKCLIENT_H_ */
