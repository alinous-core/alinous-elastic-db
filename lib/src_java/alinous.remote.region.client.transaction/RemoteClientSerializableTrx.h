#ifndef ALINOUS_REMOTE_REGION_CLIENT_TRANSACTION_REMOTECLIENTSERIALIZABLETRX_H_
#define ALINOUS_REMOTE_REGION_CLIENT_TRANSACTION_REMOTECLIENTSERIALIZABLETRX_H_
namespace alinous {namespace db {namespace trx {
class DbTransactionManager;}}}

namespace alinous {namespace db {
class AlinousDatabase;}}

namespace alinous {namespace system {
class AlinousCore;}}

namespace alinous {namespace db {namespace table {
class IDatabaseRecord;}}}

namespace alinous {namespace db {namespace table {
class IDatabaseTable;}}}

namespace alinous {namespace remote {namespace region {namespace client {namespace transaction {
class AbstractRemoteClientTransaction;}}}}}

namespace alinous {namespace db {namespace table {
class DatabaseException;}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace remote {namespace region {namespace client {namespace transaction {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::db::AlinousDatabase;
using ::alinous::db::table::DatabaseException;
using ::alinous::db::table::IDatabaseRecord;
using ::alinous::db::table::IDatabaseTable;
using ::alinous::db::trx::DbTransactionManager;
using ::alinous::system::AlinousCore;
using ::alinous::system::AlinousException;



class RemoteClientSerializableTrx final : public AbstractRemoteClientTransaction {
public:
	RemoteClientSerializableTrx(const RemoteClientSerializableTrx& base) = default;
public:
	RemoteClientSerializableTrx(DbTransactionManager* mgr, String* tmpDir, AlinousDatabase* database, AlinousCore* core, long long commitId, ThreadContext* ctx) throw() ;
	void __construct_impl(DbTransactionManager* mgr, String* tmpDir, AlinousDatabase* database, AlinousCore* core, long long commitId, ThreadContext* ctx) throw() ;
	virtual ~RemoteClientSerializableTrx() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	bool isVisible(IDatabaseRecord* record, IDatabaseTable* tableStore, ThreadContext* ctx) final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}}

#endif /* end of ALINOUS_REMOTE_REGION_CLIENT_TRANSACTION_REMOTECLIENTSERIALIZABLETRX_H_ */
