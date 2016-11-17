#ifndef ALINOUS_LOCK_UPGREADABLEGATE_H_
#define ALINOUS_LOCK_UPGREADABLEGATE_H_
namespace java {namespace lang {
class Thread;}}

namespace java {namespace lang {
class InterruptedException;}}

namespace alinous {namespace lock {
class LockObject;}}

namespace java {namespace util {
template <typename  T> class LinkedList;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace lock {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::ArrayList;
using ::java::util::LinkedList;



class UpgreadableGate final : public virtual IObject {
public:
	UpgreadableGate(const UpgreadableGate& base) = default;
public:
	UpgreadableGate(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~UpgreadableGate() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	LockObject* upgradeLock;
private:
	LockObject* stateLock;
	int counter;
	bool isOpened;
	bool disposed;
	LinkedList<Thread>* list;
	ArrayList<Thread>* cancelList;
	LockObject* listLock;
	Thread* executingUpdate;
public:
	void dispose(ThreadContext* ctx) throw() ;
	void enter(ThreadContext* ctx);
	void exit(ThreadContext* ctx) throw() ;
	void upgrade(ThreadContext* ctx);
	void reserve(ThreadContext* ctx) throw() ;
	void downgrade(ThreadContext* ctx);
	void close(ThreadContext* ctx);
	void open(ThreadContext* ctx);
private:
	void reserveShare(ThreadContext* ctx) throw() ;
	void execClose(bool added, ThreadContext* ctx);
	bool doclose(Thread* currentthread, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}

#endif /* end of ALINOUS_LOCK_UPGREADABLEGATE_H_ */
