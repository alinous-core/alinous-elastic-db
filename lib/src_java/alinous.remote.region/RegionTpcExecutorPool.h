#ifndef ALINOUS_REMOTE_REGION_REGIONTPCEXECUTORPOOL_H_
#define ALINOUS_REMOTE_REGION_REGIONTPCEXECUTORPOOL_H_
namespace alinous {namespace remote {namespace region {
class RegionInsertExecutor;}}}

namespace alinous {namespace db {namespace trx {
class DbVersionContext;}}}

namespace alinous {namespace remote {namespace region {
class NodeReferenceManager;}}}

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
using ::alinous::db::trx::DbVersionContext;
using ::alinous::lock::LockObject;



class RegionTpcExecutorPool final : public virtual IObject {
public:
	RegionTpcExecutorPool(const RegionTpcExecutorPool& base) = default;
public:
	RegionTpcExecutorPool(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~RegionTpcExecutorPool() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	Map<Long,RegionInsertExecutor>* insertSessions;
	LockObject* lock;
public:
	void putInsertSession(RegionInsertExecutor* exec, ThreadContext* ctx) throw() ;
	RegionInsertExecutor* getInsertSession(long long trxId, long long commitId, DbVersionContext* vctx, NodeReferenceManager* refs, ThreadContext* ctx) throw() ;
	void removeInsertSession(long long trxId, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_REMOTE_REGION_REGIONTPCEXECUTORPOOL_H_ */
