#ifndef ALINOUS_REMOTE_REGION_REGIONINSERTEXECUTORPOOL_H_
#define ALINOUS_REMOTE_REGION_REGIONINSERTEXECUTORPOOL_H_
namespace alinous {namespace remote {namespace region {
class RegionInsertExecutor;}}}

namespace java {namespace lang {
class Long;}}

namespace java {namespace util {
template <typename  T, typename V> class Map;}}

namespace java {namespace util {
template <typename  T, typename V> class HashMap;}}

namespace alinous {namespace lock {
class LockObject;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace remote {namespace region {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::HashMap;
using ::java::util::Map;
using ::alinous::lock::LockObject;



class RegionInsertExecutorPool final : public virtual IObject {
public:
	RegionInsertExecutorPool(const RegionInsertExecutorPool& base) = default;
public:
	RegionInsertExecutorPool(ThreadContext* ctx) throw()  : IObject(ctx), sessions(GCUtils<Map<Long,RegionInsertExecutor> >::ins(this, (new(ctx) HashMap<Long,RegionInsertExecutor>(ctx)), ctx, __FILEW__, __LINE__, L"")), lock(__GC_INS(this, (new(ctx) LockObject(ctx)), LockObject))
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~RegionInsertExecutorPool() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	Map<Long,RegionInsertExecutor>* sessions;
	LockObject* lock;
public:
	void putSession(RegionInsertExecutor* exec, ThreadContext* ctx) throw() ;
	RegionInsertExecutor* getSession(long long trxId, ThreadContext* ctx) throw() ;
	void removeSession(long long trxId, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_REMOTE_REGION_REGIONINSERTEXECUTORPOOL_H_ */
