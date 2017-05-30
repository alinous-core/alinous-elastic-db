#ifndef ALINOUS_REMOTE_REGION_SERVER_LOCK_IREMOTETABLELOCK_H_
#define ALINOUS_REMOTE_REGION_SERVER_LOCK_IREMOTETABLELOCK_H_
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



class IRemoteTableLock : public virtual IObject {
public:
	IRemoteTableLock(const IRemoteTableLock& base) = default;
public:
	IRemoteTableLock(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~IRemoteTableLock() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	virtual void shareLock(ThreadContext* ctx) = 0;
	virtual void shareUnlock(ThreadContext* ctx) throw()  = 0;
	virtual void updateLock(ThreadContext* ctx) = 0;
	virtual void updateUnlock(ThreadContext* ctx) = 0;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}}

#endif /* end of ALINOUS_REMOTE_REGION_SERVER_LOCK_IREMOTETABLELOCK_H_ */
