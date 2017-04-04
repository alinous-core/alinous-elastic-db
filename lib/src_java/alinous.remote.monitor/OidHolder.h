#ifndef ALINOUS_REMOTE_MONITOR_OIDHOLDER_H_
#define ALINOUS_REMOTE_MONITOR_OIDHOLDER_H_
namespace alinous {namespace lock {
class LockObject;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace remote {namespace monitor {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::lock::LockObject;



class OidHolder final : public virtual IObject {
public:
	OidHolder(const OidHolder& base) = default;
public:
	OidHolder(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~OidHolder() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	LockObject* oidLock;
	long long nextOid;
public:
	void setNextOid(long long lastOid, ThreadContext* ctx) throw() ;
	long long getNextOid(int length, ThreadContext* ctx) throw() ;
	void syncNextOid(long long nextOid, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_REMOTE_MONITOR_OIDHOLDER_H_ */
