#ifndef ALINOUS_DB_TABLE_LOCKMONITOR_IDATABASELOCK_H_
#define ALINOUS_DB_TABLE_LOCKMONITOR_IDATABASELOCK_H_
namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace db {namespace table {namespace lockmonitor {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;



class IDatabaseLock : public virtual IObject {
public:
	IDatabaseLock(const IDatabaseLock& base) = default;
public:
	IDatabaseLock(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~IDatabaseLock() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	static int TABLE_LOCK;
	static int ROW_LOCK;
public:
	virtual int getLockType(ThreadContext* ctx) throw()  = 0;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}

#endif /* end of ALINOUS_DB_TABLE_LOCKMONITOR_IDATABASELOCK_H_ */
