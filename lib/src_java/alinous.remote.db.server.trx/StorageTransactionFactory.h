#ifndef ALINOUS_REMOTE_DB_SERVER_TRX_STORAGETRANSACTIONFACTORY_H_
#define ALINOUS_REMOTE_DB_SERVER_TRX_STORAGETRANSACTIONFACTORY_H_
namespace alinous {namespace remote {namespace db {namespace server {namespace trx {
class SerializableStorageTransaction;}}}}}

namespace alinous {namespace remote {namespace db {namespace server {namespace trx {
class ReadCommittedStorageTransaction;}}}}}

namespace alinous {namespace remote {namespace db {namespace server {namespace trx {
class StorageTransaction;}}}}}

namespace alinous {namespace db {namespace trx {
class DbVersionContext;}}}

namespace alinous {namespace remote {namespace db {namespace server {
class RemoteTableStorageServer;}}}}

namespace alinous {namespace runtime {namespace dbif {
class IDatabaseDriver;}}}

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
using ::alinous::db::trx::DbVersionContext;
using ::alinous::remote::db::server::RemoteTableStorageServer;
using ::alinous::runtime::dbif::IDatabaseDriver;



class StorageTransactionFactory final : public virtual IObject {
public:
	StorageTransactionFactory(const StorageTransactionFactory& base) = default;
public:
	StorageTransactionFactory(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~StorageTransactionFactory() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	static StorageTransaction* createTrx(int isolationLevel, DbVersionContext* vctx, String* datadir, RemoteTableStorageServer* server, ThreadContext* ctx) throw() ;
	static void includes(SerializableStorageTransaction* arg0, ReadCommittedStorageTransaction* arg1, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}}

#endif /* end of ALINOUS_REMOTE_DB_SERVER_TRX_STORAGETRANSACTIONFACTORY_H_ */
