#ifndef ALINOUS_DB_TRX_SERIALIZABLETRANSACTION_H_
#define ALINOUS_DB_TRX_SERIALIZABLETRANSACTION_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace db {namespace trx {
class DbTransactionManager;}}}

namespace alinous {namespace db {
class AlinousDatabase;}}

namespace alinous {namespace system {
class ISystemLog;}}

namespace alinous {namespace db {namespace table {
class DatabaseRecord;}}}

namespace alinous {namespace db {namespace table {
class DatabaseTable;}}}

namespace alinous {namespace db {namespace table {
class DatabaseException;}}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace java {namespace lang {
class InterruptedException;}}

namespace java {namespace io {
class IOException;}}

namespace alinous {namespace btree {
class BTreeException;}}

namespace alinous {namespace db {namespace trx {
class DbTransaction;}}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace db {namespace trx {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::IOException;
using ::alinous::btree::BTreeException;
using ::alinous::db::AlinousDatabase;
using ::alinous::db::table::DatabaseException;
using ::alinous::db::table::DatabaseRecord;
using ::alinous::db::table::DatabaseTable;
using ::alinous::runtime::dom::VariableException;
using ::alinous::system::ISystemLog;



class SerializableTransaction final : public DbTransaction {
public:
	SerializableTransaction(const SerializableTransaction& base) = default;
public:
	SerializableTransaction(DbTransactionManager* mgr, String* tmpDir, AlinousDatabase* database, ISystemLog* logger, long long trxId, ThreadContext* ctx) throw() ;
	void __construct_impl(DbTransactionManager* mgr, String* tmpDir, AlinousDatabase* database, ISystemLog* logger, long long trxId, ThreadContext* ctx) throw() ;
	virtual ~SerializableTransaction() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	bool isVisible(DatabaseRecord* record, DatabaseTable* tableStore, ThreadContext* ctx) final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_DB_TRX_SERIALIZABLETRANSACTION_H_ */
