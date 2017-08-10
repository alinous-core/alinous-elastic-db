#ifndef ALINOUS_REMOTE_REGION_SERVER_LOCK_REMOTETRXLOCKCONTEXT_H_
#define ALINOUS_REMOTE_REGION_SERVER_LOCK_REMOTETRXLOCKCONTEXT_H_
namespace alinous {namespace remote {namespace region {namespace server {namespace lock {
class IRemoteTableLock;}}}}}

namespace alinous {namespace remote {namespace region {namespace server {namespace lock {
class TrxLockContextLockHolder;}}}}}

namespace java {namespace util {
template <typename  T, typename V> class Map;}}

namespace java {namespace util {
template <typename  T> class Iterator;}}

namespace java {namespace util {
template <typename  T, typename V> class HashMap;}}

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
using ::java::util::Iterator;
using ::java::util::Map;
using ::alinous::db::AlinousDbException;
using ::alinous::db::table::scan::IndexScannerLockRequirement;



class RemoteTrxLockContext final : public virtual IObject {
public:
	RemoteTrxLockContext(const RemoteTrxLockContext& base) = default;
public:
	RemoteTrxLockContext(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~RemoteTrxLockContext() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	Map<String,TrxLockContextLockHolder>* tables;
public:
	void addLock(String* fullName, IRemoteTableLock* lock, int lockMode, ThreadContext* ctx);
	void releaseLock(String* fullName, int lockMode, ThreadContext* ctx);
	Map<String,TrxLockContextLockHolder>* getTables(ThreadContext* ctx) throw() ;
	void releaseAll(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}}

#endif /* end of ALINOUS_REMOTE_REGION_SERVER_LOCK_REMOTETRXLOCKCONTEXT_H_ */
