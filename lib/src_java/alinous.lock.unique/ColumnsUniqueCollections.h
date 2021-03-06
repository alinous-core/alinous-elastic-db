#ifndef ALINOUS_LOCK_UNIQUE_COLUMNSUNIQUECOLLECTIONS_H_
#define ALINOUS_LOCK_UNIQUE_COLUMNSUNIQUECOLLECTIONS_H_
namespace alinous {namespace lock {namespace unique {
class UniqueExclusiveLock;}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanUnique;}}}}

namespace alinous {namespace lock {namespace unique {
class UniqueExclusiveException;}}}

namespace java {namespace lang {
class InterruptedException;}}

namespace alinous {namespace lock {
class LockObject;}}

namespace java {namespace util {
template <typename  T, typename V> class Map;}}

namespace java {namespace util {
template <typename  T, typename V> class HashMap;}}

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
using ::java::util::Map;
using ::alinous::btree::BTreeException;
using ::alinous::compile::sql::analyze::ScanUnique;
using ::alinous::lock::LockObject;
using ::alinous::runtime::dom::VariableException;
using ::alinous::system::AlinousException;



class ColumnsUniqueCollections final : public virtual IObject {
public:
	ColumnsUniqueCollections(const ColumnsUniqueCollections& base) = default;
public:
	ColumnsUniqueCollections(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~ColumnsUniqueCollections() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	LockObject* lock;
	Map<String,UniqueExclusiveLock>* locks;
public:
	UniqueExclusiveLock* lockWithCheck(ScanUnique* unique, String* lockString, bool throwex, ThreadContext* ctx);
	bool unlock(ScanUnique* unique, String* lockString, ThreadContext* ctx) throw() ;
	UniqueExclusiveLock* getLock(ScanUnique* unique, String* lockString, ThreadContext* ctx);
	void dispose(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_LOCK_UNIQUE_COLUMNSUNIQUECOLLECTIONS_H_ */
