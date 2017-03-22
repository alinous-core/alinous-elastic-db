#ifndef ALINOUS_REMOTE_DB_SERVER_TRX_STORAGETRANSACTION_H_
#define ALINOUS_REMOTE_DB_SERVER_TRX_STORAGETRANSACTION_H_
namespace alinous {namespace db {namespace trx {
class DbVersionContext;}}}

namespace alinous {namespace remote {namespace db {namespace server {
class RemoteTableStorageServer;}}}}

namespace alinous {namespace remote {namespace db {namespace server {namespace trx {
class UniqueChecker;}}}}}

namespace alinous {namespace db {namespace table {
class IDatabaseRecord;}}}

namespace alinous {namespace db {namespace table {
class IDatabaseTable;}}}

namespace java {namespace util {
template <typename  T> class List;}}

namespace alinous {namespace remote {namespace region {namespace server {namespace schema {namespace strategy {
class UniqueCheckOperation;}}}}}}

namespace alinous {namespace remote {namespace region {namespace client {namespace command {namespace data {
class ClientNetworkRecord;}}}}}}

namespace alinous {namespace lock {namespace unique {
class UniqueExclusiveLock;}}}

namespace java {namespace lang {
class StringBuilder;}}

namespace alinous {namespace lock {namespace unique {
class UniqueExclusiveLockManager;}}}

namespace alinous {namespace remote {namespace db {namespace server {namespace commit {
class PrepareStorageManager;}}}}}

namespace java {namespace io {
class IOException;}}

namespace alinous {namespace btree {
class BTreeException;}}

namespace alinous {namespace system {
class AlinousException;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace remote {namespace db {namespace server {namespace trx {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::IOException;
using ::java::util::ArrayList;
using ::java::util::List;
using ::alinous::btree::BTreeException;
using ::alinous::db::table::IDatabaseRecord;
using ::alinous::db::table::IDatabaseTable;
using ::alinous::db::trx::DbVersionContext;
using ::alinous::lock::unique::UniqueExclusiveLock;
using ::alinous::lock::unique::UniqueExclusiveLockManager;
using ::alinous::remote::db::server::RemoteTableStorageServer;
using ::alinous::remote::db::server::commit::PrepareStorageManager;
using ::alinous::remote::region::client::command::data::ClientNetworkRecord;
using ::alinous::remote::region::server::schema::strategy::UniqueCheckOperation;
using ::alinous::system::AlinousException;



class StorageTransaction : public virtual IObject {
public:
	StorageTransaction(const StorageTransaction& base) = default;
public:
	StorageTransaction(int isolationLevel, DbVersionContext* vctx, String* datadir, RemoteTableStorageServer* server, ThreadContext* ctx) throw() ;
	void __construct_impl(int isolationLevel, DbVersionContext* vctx, String* datadir, RemoteTableStorageServer* server, ThreadContext* ctx) throw() ;
	virtual ~StorageTransaction() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	int isolationLevel;
	DbVersionContext* vctx;
	String* datadir;
	String* tmpDir;
	RemoteTableStorageServer* server;
	UniqueExclusiveLockManager* uniqueLockMgr;
	List<UniqueExclusiveLock>* uniqueLocks;
	UniqueChecker* uniqueChecker;
	PrepareStorageManager* prepareManager;
public:
	virtual bool isVisible(IDatabaseRecord* record, ThreadContext* ctx) throw()  = 0;
	void prepareInsert(IDatabaseTable* table, List<UniqueCheckOperation>* uniqueCheckOps, List<ClientNetworkRecord>* records, ThreadContext* ctx);
	void addUniqueExclusiveLock(UniqueExclusiveLock* lock, ThreadContext* ctx) throw() ;
	void unlockUniqueAll(ThreadContext* ctx) throw() ;
	String* getTmpDir(ThreadContext* ctx) throw() ;
	int getIsolationLevel(ThreadContext* ctx) throw() ;
	DbVersionContext* getVctx(ThreadContext* ctx) throw() ;
	void dispose(ThreadContext* ctx) throw() ;
	RemoteTableStorageServer* getServer(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}}

#endif /* end of ALINOUS_REMOTE_DB_SERVER_TRX_STORAGETRANSACTION_H_ */
