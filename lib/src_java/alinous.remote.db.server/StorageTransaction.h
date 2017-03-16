#ifndef ALINOUS_REMOTE_DB_SERVER_STORAGETRANSACTION_H_
#define ALINOUS_REMOTE_DB_SERVER_STORAGETRANSACTION_H_
namespace alinous {namespace db {namespace trx {
class DbVersionContext;}}}

namespace alinous {namespace remote {namespace db {namespace server {
class RemoteTableStorageServer;}}}}

namespace alinous {namespace db {namespace table {
class IDatabaseTable;}}}

namespace java {namespace util {
template <typename  T> class List;}}

namespace alinous {namespace remote {namespace region {namespace server {namespace schema {namespace strategy {
class UniqueCheckOperation;}}}}}}

namespace alinous {namespace remote {namespace region {namespace client {namespace command {namespace data {
class ClientNetworkRecord;}}}}}}

namespace alinous {namespace lock {namespace unique {
class UniqueExclusiveLockManager;}}}

namespace java {namespace lang {
class StringBuilder;}}

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
using ::java::util::List;
using ::alinous::db::table::IDatabaseTable;
using ::alinous::db::trx::DbVersionContext;
using ::alinous::lock::unique::UniqueExclusiveLockManager;
using ::alinous::remote::region::client::command::data::ClientNetworkRecord;
using ::alinous::remote::region::server::schema::strategy::UniqueCheckOperation;



class StorageTransaction final : public virtual IObject {
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
public:
	void prepareInsert(IDatabaseTable* table, List<UniqueCheckOperation>* uniqueCheckOps, List<ClientNetworkRecord>* records, ThreadContext* ctx) throw() ;
	String* getTmpDir(ThreadContext* ctx) throw() ;
	int getIsolationLevel(ThreadContext* ctx) throw() ;
	DbVersionContext* getVctx(ThreadContext* ctx) throw() ;
	void dispose(ThreadContext* ctx) throw() ;
private:
	void checkUnique(UniqueExclusiveLockManager* uniqueLockMgr, List<UniqueCheckOperation>* uniqueCheckOps, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}

#endif /* end of ALINOUS_REMOTE_DB_SERVER_STORAGETRANSACTION_H_ */
