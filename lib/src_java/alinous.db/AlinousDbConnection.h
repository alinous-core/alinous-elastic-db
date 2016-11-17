#ifndef ALINOUS_DB_ALINOUSDBCONNECTION_H_
#define ALINOUS_DB_ALINOUSDBCONNECTION_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace db {
class AlinousDatabase;}}

namespace alinous {namespace db {
class ConnectInfo;}}

namespace alinous {namespace db {
class AlinousDbException;}}

namespace java {namespace lang {
class Throwable;}}

namespace alinous {namespace compile {namespace sql {
class CreateTableStatement;}}}

namespace alinous {namespace runtime {namespace engine {
class ScriptMachine;}}}

namespace alinous {namespace db {
class TableSchema;}}

namespace alinous {namespace compile {namespace sql {
class DropTableStatement;}}}

namespace alinous {namespace runtime {namespace dbif {
class ISQLSelectResult;}}}

namespace alinous {namespace compile {namespace sql {
class SelectStatement;}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class SQLAnalyseContext;}}}}

namespace alinous {namespace compile {namespace sql {
class InsertStatement;}}}

namespace alinous {namespace compile {namespace sql {
class UpdateStatement;}}}

namespace alinous {namespace compile {namespace sql {
class DeleteStatement;}}}

namespace alinous {namespace compile {namespace sql {
class CreateIndexStatement;}}}

namespace alinous {namespace compile {namespace sql {
class DropIndexStatement;}}}

namespace alinous {namespace db {namespace trx {
class DbTransaction;}}}

namespace alinous {namespace runtime {namespace dbif {
class IDatabaseConnection;}}}

namespace alinous {namespace db {namespace table {
class DatabaseException;}}}

namespace alinous {namespace runtime {namespace dbif {
class IDatabaseDriver;}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace db {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::ArrayList;
using ::alinous::compile::sql::CreateIndexStatement;
using ::alinous::compile::sql::CreateTableStatement;
using ::alinous::compile::sql::DeleteStatement;
using ::alinous::compile::sql::DropIndexStatement;
using ::alinous::compile::sql::DropTableStatement;
using ::alinous::compile::sql::InsertStatement;
using ::alinous::compile::sql::SelectStatement;
using ::alinous::compile::sql::UpdateStatement;
using ::alinous::compile::sql::analyze::SQLAnalyseContext;
using ::alinous::db::table::DatabaseException;
using ::alinous::db::trx::DbTransaction;
using ::alinous::runtime::dbif::IDatabaseConnection;
using ::alinous::runtime::dbif::IDatabaseDriver;
using ::alinous::runtime::dbif::ISQLSelectResult;
using ::alinous::runtime::engine::ScriptMachine;
using ::alinous::system::AlinousException;



class AlinousDbConnection final : public IDatabaseConnection, public virtual IObject {
public:
	AlinousDbConnection(const AlinousDbConnection& base) = default;
public:
	AlinousDbConnection(AlinousDatabase* database, ConnectInfo* info, ThreadContext* ctx) throw() ;
	void __construct_impl(AlinousDatabase* database, ConnectInfo* info, ThreadContext* ctx) throw() ;
	virtual ~AlinousDbConnection() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	bool autoCommit;
	AlinousDatabase* database;
	DbTransaction* trx;
public:
	void close(ThreadContext* ctx) throw()  final;
	bool isAutoCommit(ThreadContext* ctx) throw()  final;
	void begin(int acid, ThreadContext* ctx) final;
	void commit(ThreadContext* ctx) final;
	void rollback(ThreadContext* ctx) throw()  final;
	void createTable(CreateTableStatement* stmt, ScriptMachine* machine, bool debug, ThreadContext* ctx) final;
	void dropTable(DropTableStatement* stmt, ScriptMachine* machine, bool debug, ThreadContext* ctx) throw()  final;
	void createSchema(String* schema, ScriptMachine* machine, bool debug, ThreadContext* ctx) throw()  final;
	void dropSchema(String* schema, ScriptMachine* machine, bool debug, ThreadContext* ctx) throw()  final;
	ArrayList<String>* showAllSchema(ThreadContext* ctx) throw()  final;
	ISQLSelectResult* selectSQL(SelectStatement* stmt, ScriptMachine* machine, bool debug, ThreadContext* ctx) final;
	void insertSQL(InsertStatement* stmt, ScriptMachine* machine, bool debug, ThreadContext* ctx) final;
	void updateSQL(UpdateStatement* stmt, ScriptMachine* machine, bool debug, ThreadContext* ctx) final;
	void deleteSQL(DeleteStatement* stmt, ScriptMachine* machine, bool debug, ThreadContext* ctx) throw()  final;
	void createIndex(CreateIndexStatement* stmt, ScriptMachine* machine, bool debug, ThreadContext* ctx) final;
	void dropIndex(DropIndexStatement* stmt, ScriptMachine* machine, bool debug, ThreadContext* ctx) throw()  final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}

#endif /* end of ALINOUS_DB_ALINOUSDBCONNECTION_H_ */
