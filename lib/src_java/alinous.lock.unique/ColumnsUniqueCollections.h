#ifndef ALINOUS_LOCK_UNIQUE_COLUMNSUNIQUECOLLECTIONS_H_
#define ALINOUS_LOCK_UNIQUE_COLUMNSUNIQUECOLLECTIONS_H_
namespace alinous {namespace btreememory {
class BTreeOnMemory;}}

namespace alinous {namespace lock {namespace unique {
class UniqueExclusiveLock;}}}

namespace alinous {namespace db {namespace trx {namespace scan {
class ScanResultIndexKey;}}}}

namespace alinous {namespace btree {
class IBTreeNode;}}

namespace alinous {namespace btree {
class IBTreeValue;}}

namespace java {namespace io {
class IOException;}}

namespace java {namespace lang {
class InterruptedException;}}

namespace alinous {namespace btree {
class IBTree;}}

namespace alinous {namespace lock {
class LockObject;}}

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
using ::java::util::ArrayList;
using ::alinous::btree::BTreeException;
using ::alinous::btree::IBTree;
using ::alinous::btree::IBTreeNode;
using ::alinous::btree::IBTreeValue;
using ::alinous::btreememory::BTreeOnMemory;
using ::alinous::db::trx::scan::ScanResultIndexKey;
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
	IBTree* lockStore;
	LockObject* lock;
public:
	UniqueExclusiveLock* getLock(ScanResultIndexKey* key, ThreadContext* ctx);
	void dispose(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_LOCK_UNIQUE_COLUMNSUNIQUECOLLECTIONS_H_ */
