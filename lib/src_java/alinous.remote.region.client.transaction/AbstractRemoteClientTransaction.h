#ifndef ALINOUS_REMOTE_REGION_CLIENT_TRANSACTION_ABSTRACTREMOTECLIENTTRANSACTION_H_
#define ALINOUS_REMOTE_REGION_CLIENT_TRANSACTION_ABSTRACTREMOTECLIENTTRANSACTION_H_
namespace alinous {namespace db {namespace trx {
class DbTransactionManager;}}}

namespace alinous {namespace db {
class AlinousDatabase;}}

namespace alinous {namespace system {
class AlinousCore;}}

namespace alinous {namespace db {namespace trx {
class DbVersionContext;}}}

namespace alinous {namespace remote {namespace region {namespace client {
class TableAccessStatusListner;}}}}

namespace alinous {namespace db {
class TableSchema;}}

namespace alinous {namespace db {
class AlinousDbException;}}

namespace java {namespace io {
class IOException;}}

namespace java {namespace lang {
class InterruptedException;}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace alinous {namespace btree {
class BTreeException;}}

namespace java {namespace util {
template <typename  T> class List;}}

namespace alinous {namespace db {namespace table {
class IDatabaseTable;}}}

namespace alinous {namespace db {
class TableSchemaCollection;}}

namespace alinous {namespace db {namespace trx {
class DbTransaction;}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace remote {namespace region {namespace client {namespace transaction {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::IOException;
using ::java::util::List;
using ::alinous::btree::BTreeException;
using ::alinous::db::AlinousDatabase;
using ::alinous::db::AlinousDbException;
using ::alinous::db::TableSchema;
using ::alinous::db::TableSchemaCollection;
using ::alinous::db::table::IDatabaseTable;
using ::alinous::db::trx::DbTransaction;
using ::alinous::db::trx::DbTransactionManager;
using ::alinous::db::trx::DbVersionContext;
using ::alinous::remote::region::client::TableAccessStatusListner;
using ::alinous::runtime::dom::VariableException;
using ::alinous::system::AlinousCore;
using ::alinous::system::AlinousException;



class AbstractRemoteClientTransaction : public DbTransaction {
public:
	AbstractRemoteClientTransaction(const AbstractRemoteClientTransaction& base) = default;
public:
	AbstractRemoteClientTransaction(DbTransactionManager* mgr, String* tmpDir, AlinousDatabase* database, AlinousCore* core, long long commitId, DbVersionContext* vctx, ThreadContext* ctx) throw() ;
	void __construct_impl(DbTransactionManager* mgr, String* tmpDir, AlinousDatabase* database, AlinousCore* core, long long commitId, DbVersionContext* vctx, ThreadContext* ctx) throw() ;
	virtual ~AbstractRemoteClientTransaction() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	TableAccessStatusListner* accessListner;
public:
	bool isRemote(ThreadContext* ctx) throw()  final;
	void createTable(TableSchema* schema, ThreadContext* ctx) final;
	TableAccessStatusListner* getAccessListner(ThreadContext* ctx) throw()  final;
	void commitUpdateInsert(long long newCommitId, ThreadContext* ctx) final;
private:
	IDatabaseTable* getTable(String* fullName, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}}

#endif /* end of ALINOUS_REMOTE_REGION_CLIENT_TRANSACTION_ABSTRACTREMOTECLIENTTRANSACTION_H_ */
