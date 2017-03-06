#ifndef ALINOUS_DB_TRX_DBTRANSACTIONFACTORY_H_
#define ALINOUS_DB_TRX_DBTRANSACTIONFACTORY_H_
namespace alinous {namespace db {namespace trx {
class DbTransaction;}}}

namespace alinous {namespace db {namespace trx {
class DbTransactionManager;}}}

namespace alinous {namespace db {
class AlinousDatabase;}}

namespace alinous {namespace system {
class AlinousCore;}}

namespace alinous {namespace db {namespace trx {
class DbVersionContext;}}}

namespace alinous {namespace db {namespace trx {
class ReadCommittedTransaction;}}}

namespace alinous {namespace db {namespace trx {
class RepeatableReadTransaction;}}}

namespace alinous {namespace db {namespace trx {
class SerializableTransaction;}}}

namespace alinous {namespace remote {namespace region {namespace client {namespace transaction {
class RemoteClientReadCommittedTrx;}}}}}

namespace alinous {namespace remote {namespace region {namespace client {namespace transaction {
class RemoteClientRepeatableReadTrx;}}}}}

namespace alinous {namespace remote {namespace region {namespace client {namespace transaction {
class RemoteClientSerializableTrx;}}}}}

namespace alinous {namespace runtime {namespace dbif {
class IDatabaseDriver;}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace db {namespace trx {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::db::AlinousDatabase;
using ::alinous::remote::region::client::transaction::RemoteClientReadCommittedTrx;
using ::alinous::remote::region::client::transaction::RemoteClientRepeatableReadTrx;
using ::alinous::remote::region::client::transaction::RemoteClientSerializableTrx;
using ::alinous::runtime::dbif::IDatabaseDriver;
using ::alinous::system::AlinousCore;



class DbTransactionFactory final : public virtual IObject {
public:
	DbTransactionFactory(const DbTransactionFactory& base) = default;
public:
	DbTransactionFactory(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~DbTransactionFactory() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	static DbTransaction* newTransaction(int acid, DbTransactionManager* mgr, String* tmpDir, AlinousDatabase* database, AlinousCore* core, long long commitId, DbVersionContext* vctx, ThreadContext* ctx) throw() ;
	static DbTransaction* newRemoteTransaction(int acid, DbTransactionManager* mgr, String* tmpDir, AlinousDatabase* database, AlinousCore* core, long long commitId, DbVersionContext* vctx, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_DB_TRX_DBTRANSACTIONFACTORY_H_ */
