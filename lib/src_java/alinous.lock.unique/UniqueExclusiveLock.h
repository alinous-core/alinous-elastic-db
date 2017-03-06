#ifndef ALINOUS_LOCK_UNIQUE_UNIQUEEXCLUSIVELOCK_H_
#define ALINOUS_LOCK_UNIQUE_UNIQUEEXCLUSIVELOCK_H_
namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanUnique;}}}}

namespace alinous {namespace db {namespace table {
class IDatabaseRecord;}}}

namespace alinous {namespace lock {
class ConcurrentGate;}}

namespace java {namespace lang {
class StringBuffer;}}

namespace alinous {namespace db {namespace table {
class TableColumnMetadata;}}}

namespace alinous {namespace runtime {namespace variant {
class VariantValue;}}}

namespace java {namespace lang {
class InterruptedException;}}

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
using ::java::util::ArrayList;
using ::alinous::compile::sql::analyze::ScanUnique;
using ::alinous::db::table::IDatabaseRecord;
using ::alinous::db::table::TableColumnMetadata;
using ::alinous::lock::ConcurrentGate;
using ::alinous::runtime::variant::VariantValue;



class UniqueExclusiveLock final : public virtual IObject {
public:
	UniqueExclusiveLock(const UniqueExclusiveLock& base) = default;
public:
	UniqueExclusiveLock(ScanUnique* unique, IDatabaseRecord* record, ThreadContext* ctx) throw() ;
	void __construct_impl(ScanUnique* unique, IDatabaseRecord* record, ThreadContext* ctx) throw() ;
	virtual ~UniqueExclusiveLock() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	ConcurrentGate* gate;
	ScanUnique* unique;
	IDatabaseRecord* record;
	int count;
public:
	String* toString(ThreadContext* ctx) throw() ;
	void lock(ThreadContext* ctx);
	void unlock(ThreadContext* ctx) throw() ;
	ScanUnique* getUnique(ThreadContext* ctx) throw() ;
	IDatabaseRecord* getRecord(ThreadContext* ctx) throw() ;
	int getCount(ThreadContext* ctx) throw() ;
public:
	static String* makeString(ScanUnique* unique, IDatabaseRecord* record, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_LOCK_UNIQUE_UNIQUEEXCLUSIVELOCK_H_ */
