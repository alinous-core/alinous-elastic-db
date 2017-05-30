#ifndef ALINOUS_REMOTE_REGION_SERVER_LOCK_REMOTETABLELOCK_H_
#define ALINOUS_REMOTE_REGION_SERVER_LOCK_REMOTETABLELOCK_H_
namespace alinous {namespace lock {
class ConcurrentGate;}}

namespace alinous {namespace remote {namespace region {namespace server {namespace lock {
class IRemoteTableLock;}}}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace remote {namespace region {namespace server {namespace lock {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::lock::ConcurrentGate;



class RemoteTableLock final : public IRemoteTableLock, public virtual IObject {
public:
	RemoteTableLock(const RemoteTableLock& base) = default;
public:
	RemoteTableLock(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~RemoteTableLock() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	ConcurrentGate* gate;
public:
	void shareLock(ThreadContext* ctx) final;
	void shareUnlock(ThreadContext* ctx) throw()  final;
	void updateLock(ThreadContext* ctx) final;
	void updateUnlock(ThreadContext* ctx) final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}}

#endif /* end of ALINOUS_REMOTE_REGION_SERVER_LOCK_REMOTETABLELOCK_H_ */
