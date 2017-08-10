#ifndef ALINOUS_REMOTE_REGION_SERVER_LOCK_REGIONTABLELOCKMANAGER_H_
#define ALINOUS_REMOTE_REGION_SERVER_LOCK_REGIONTABLELOCKMANAGER_H_
namespace alinous {namespace remote {namespace region {namespace server {
class NodeRegionServer;}}}}

namespace java {namespace lang {
class StringBuilder;}}

namespace java {namespace lang {
class Long;}}

namespace alinous {namespace remote {namespace region {namespace server {namespace lock {
class RemoteTrxLockContext;}}}}}

namespace alinous {namespace remote {namespace region {namespace server {namespace lock {
class IRemoteTableLock;}}}}}

namespace alinous {namespace remote {namespace region {namespace server {namespace lock {
class RemoteTableLock;}}}}}

namespace java {namespace util {
template <typename  T, typename V> class Map;}}

namespace java {namespace util {
template <typename  T, typename V> class HashMap;}}

namespace alinous {namespace lock {
class LockObject;}}

namespace alinous {namespace db {
class AlinousDbException;}}

namespace alinous {namespace db {namespace table {namespace scan {
class IndexScannerLockRequirement;}}}}

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
using ::java::util::HashMap;
using ::java::util::Map;
using ::alinous::db::AlinousDbException;
using ::alinous::db::table::scan::IndexScannerLockRequirement;
using ::alinous::lock::LockObject;
using ::alinous::remote::region::server::NodeRegionServer;



class RegionTableLockManager final : public virtual IObject {
public:
	RegionTableLockManager(const RegionTableLockManager& base) = default;
public:
	RegionTableLockManager(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~RegionTableLockManager() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	Map<Long,RemoteTrxLockContext>* lockContext;
	LockObject* ctxlock;
	Map<String,IRemoteTableLock>* locks;
public:
	void lockTable(String* schema, String* table, int lockMode, long long trxId, NodeRegionServer* server, ThreadContext* ctx);
	void unlockShared(String* schema, String* table, long long trxId, NodeRegionServer* server, ThreadContext* ctx);
	void clearLocks(long long trxId, ThreadContext* ctx) throw() ;
private:
	IRemoteTableLock* getLock(String* fullName, NodeRegionServer* server, bool create, ThreadContext* ctx) throw() ;
	IRemoteTableLock* createTableLock(NodeRegionServer* server, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}}

#endif /* end of ALINOUS_REMOTE_REGION_SERVER_LOCK_REGIONTABLELOCKMANAGER_H_ */
