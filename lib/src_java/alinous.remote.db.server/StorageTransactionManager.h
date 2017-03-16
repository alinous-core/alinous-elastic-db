#ifndef ALINOUS_REMOTE_DB_SERVER_STORAGETRANSACTIONMANAGER_H_
#define ALINOUS_REMOTE_DB_SERVER_STORAGETRANSACTIONMANAGER_H_
namespace alinous {namespace remote {namespace db {namespace server {
class RemoteTableStorageServer;}}}}

namespace alinous {namespace remote {namespace db {namespace server {
class StorageTransaction;}}}}

namespace alinous {namespace db {namespace trx {
class DbVersionContext;}}}

namespace java {namespace lang {
class Long;}}

namespace alinous {namespace lock {
class LockObject;}}

namespace java {namespace util {
template <typename  T, typename V> class Map;}}

namespace java {namespace util {
template <typename  T, typename V> class HashMap;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace remote {namespace db {namespace server {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::HashMap;
using ::java::util::Map;
using ::alinous::db::trx::DbVersionContext;
using ::alinous::lock::LockObject;



class StorageTransactionManager final : public virtual IObject {
public:
	StorageTransactionManager(const StorageTransactionManager& base) = default;
public:
	StorageTransactionManager(String* datadir, RemoteTableStorageServer* server, ThreadContext* ctx) throw() ;
	void __construct_impl(String* datadir, RemoteTableStorageServer* server, ThreadContext* ctx) throw() ;
	virtual ~StorageTransactionManager() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	LockObject* lock;
	Map<Long,StorageTransaction>* transactions;
	String* datadir;
	RemoteTableStorageServer* server;
public:
	void dispose(ThreadContext* ctx) throw() ;
	StorageTransaction* getStorageTransaction(int isolationLevel, DbVersionContext* vctx, ThreadContext* ctx) throw() ;
	void finishTransaction(long long strxId, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}

#endif /* end of ALINOUS_REMOTE_DB_SERVER_STORAGETRANSACTIONMANAGER_H_ */
