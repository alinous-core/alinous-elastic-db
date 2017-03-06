#ifndef ALINOUS_REMOTE_REGION_CLIENT_TRANSACTION_REMOTECLIENTREPEATABLEREADTRX_H_
#define ALINOUS_REMOTE_REGION_CLIENT_TRANSACTION_REMOTECLIENTREPEATABLEREADTRX_H_
namespace alinous {namespace db {namespace trx {
class DbTransactionManager;}}}

namespace alinous {namespace db {
class AlinousDatabase;}}

namespace alinous {namespace system {
class AlinousCore;}}

namespace alinous {namespace db {namespace trx {
class DbVersionContext;}}}

namespace alinous {namespace remote {namespace region {namespace client {namespace transaction {
class RemoteClientSerializableTrx;}}}}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace remote {namespace region {namespace client {namespace transaction {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::db::AlinousDatabase;
using ::alinous::db::trx::DbTransactionManager;
using ::alinous::db::trx::DbVersionContext;
using ::alinous::system::AlinousCore;



class RemoteClientRepeatableReadTrx final : public RemoteClientSerializableTrx {
public:
	RemoteClientRepeatableReadTrx(const RemoteClientRepeatableReadTrx& base) = default;
public:
	RemoteClientRepeatableReadTrx(DbTransactionManager* mgr, String* tmpDir, AlinousDatabase* database, AlinousCore* core, long long commitId, DbVersionContext* vctx, ThreadContext* ctx) throw() ;
	void __construct_impl(DbTransactionManager* mgr, String* tmpDir, AlinousDatabase* database, AlinousCore* core, long long commitId, DbVersionContext* vctx, ThreadContext* ctx) throw() ;
	virtual ~RemoteClientRepeatableReadTrx() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}}

#endif /* end of ALINOUS_REMOTE_REGION_CLIENT_TRANSACTION_REMOTECLIENTREPEATABLEREADTRX_H_ */
