#ifndef ALINOUS_REMOTE_DB_SERVER_TRX_READCOMMITTEDSTORAGETRANSACTION_H_
#define ALINOUS_REMOTE_DB_SERVER_TRX_READCOMMITTEDSTORAGETRANSACTION_H_
namespace alinous {namespace db {namespace trx {
class DbVersionContext;}}}

namespace alinous {namespace remote {namespace db {namespace server {
class RemoteTableStorageServer;}}}}

namespace alinous {namespace db {namespace table {
class IDatabaseRecord;}}}

namespace alinous {namespace remote {namespace db {namespace server {namespace trx {
class StorageTransaction;}}}}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace remote {namespace db {namespace server {namespace trx {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::db::table::IDatabaseRecord;
using ::alinous::db::trx::DbVersionContext;
using ::alinous::remote::db::server::RemoteTableStorageServer;



class ReadCommittedStorageTransaction final : public StorageTransaction {
public:
	ReadCommittedStorageTransaction(const ReadCommittedStorageTransaction& base) = default;
public:
	ReadCommittedStorageTransaction(int isolationLevel, DbVersionContext* vctx, String* datadir, RemoteTableStorageServer* server, ThreadContext* ctx) throw() ;
	void __construct_impl(int isolationLevel, DbVersionContext* vctx, String* datadir, RemoteTableStorageServer* server, ThreadContext* ctx) throw() ;
	virtual ~ReadCommittedStorageTransaction() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	bool isVisible(IDatabaseRecord* record, ThreadContext* ctx) throw()  final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}}

#endif /* end of ALINOUS_REMOTE_DB_SERVER_TRX_READCOMMITTEDSTORAGETRANSACTION_H_ */
