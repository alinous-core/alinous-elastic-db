#ifndef ALINOUS_RUNTIME_DBIF_ALINOUSDATABASEHANDLER_H_
#define ALINOUS_RUNTIME_DBIF_ALINOUSDATABASEHANDLER_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace system {namespace config {
class AlinousDbInstanceInfo;}}}

namespace alinous {namespace system {
class AlinousCore;}}

namespace alinous {namespace db {
class AlinousDatabase;}}

namespace alinous {namespace runtime {namespace dbif {
class IDatabaseConnection;}}}

namespace alinous {namespace db {
class ConnectInfo;}}

namespace alinous {namespace db {
class AlinousDbConnection;}}

namespace alinous {namespace runtime {namespace engine {
class ScriptMachine;}}}

namespace alinous {namespace compile {namespace sql {
class CreateTableStatement;}}}

namespace alinous {namespace compile {namespace sql {
class DropTableStatement;}}}

namespace alinous {namespace runtime {namespace dbif {
class ISQLSelectResult;}}}

namespace alinous {namespace compile {namespace sql {
class SelectStatement;}}}

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

namespace alinous {namespace runtime {namespace dbif {
class IDatabaseDriver;}}}

namespace alinous {namespace db {
class AlinousDbException;}}

namespace alinous {namespace db {namespace table {
class DatabaseException;}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace runtime {namespace dbif {

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
using ::alinous::db::AlinousDatabase;
using ::alinous::db::AlinousDbConnection;
using ::alinous::db::AlinousDbException;
using ::alinous::db::ConnectInfo;
using ::alinous::db::table::DatabaseException;
using ::alinous::runtime::engine::ScriptMachine;
using ::alinous::system::AlinousCore;
using ::alinous::system::AlinousException;
using ::alinous::system::config::AlinousDbInstanceInfo;



class AlinousDatabaseHandler final : public IDatabaseDriver, public virtual IObject {
public:
	AlinousDatabaseHandler(const AlinousDatabaseHandler& base) = default;
public:
	AlinousDatabaseHandler(AlinousDbInstanceInfo* instanceConfig, ThreadContext* ctx) throw() ;
	void __construct_impl(AlinousDbInstanceInfo* instanceConfig, ThreadContext* ctx) throw() ;
	virtual ~AlinousDatabaseHandler() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	AlinousDatabase* database;
	AlinousDbInstanceInfo* instanceConfig;
	int defaultAcid;
public:
	int getDefaultAcid(ThreadContext* ctx) throw()  final;
	void initDriver(AlinousCore* core, ThreadContext* ctx) final;
	void dispose(ThreadContext* ctx) throw()  final;
	void createInstance(String* instanceName, ThreadContext* ctx) throw()  final;
	void dropInstance(String* instanceName, ThreadContext* ctx) throw()  final;
	IDatabaseConnection* connect(ThreadContext* ctx) throw()  final;
	void disconnect(IDatabaseConnection* con, bool debug, ThreadContext* ctx) throw()  final;
	void createSchema(IDatabaseConnection* con, String* schema, ScriptMachine* variables, bool debug, ThreadContext* ctx) throw()  final;
	void dropSchema(IDatabaseConnection* con, String* schema, ScriptMachine* variables, bool debug, ThreadContext* ctx) throw()  final;
	ArrayList<String>* showAllSchema(IDatabaseConnection* con, bool debug, ThreadContext* ctx) throw()  final;
	void createTable(IDatabaseConnection* con, CreateTableStatement* stmt, ScriptMachine* variables, bool debug, ThreadContext* ctx) final;
	void dropTable(IDatabaseConnection* con, DropTableStatement* stmt, ScriptMachine* variables, bool debug, ThreadContext* ctx) throw()  final;
	void begin(IDatabaseConnection* con, int acid, ThreadContext* ctx) final;
	void commit(IDatabaseConnection* con, ThreadContext* ctx) final;
	void rollback(IDatabaseConnection* con, ThreadContext* ctx) final;
	ISQLSelectResult* selectSQL(IDatabaseConnection* con, SelectStatement* stmt, ScriptMachine* variables, bool debug, ThreadContext* ctx) final;
	void insertSQL(IDatabaseConnection* con, InsertStatement* stmt, ScriptMachine* variables, bool debug, ThreadContext* ctx) final;
	void updateSQL(IDatabaseConnection* con, UpdateStatement* stmt, ScriptMachine* variables, bool debug, ThreadContext* ctx) final;
	void deleteSQL(IDatabaseConnection* con, DeleteStatement* stmt, ScriptMachine* variables, bool debug, ThreadContext* ctx) final;
	IObject* getDatabase(ThreadContext* ctx) throw()  final;
	void createIndex(IDatabaseConnection* con, CreateIndexStatement* stmt, ScriptMachine* machine, bool debug, ThreadContext* ctx) final;
	void dropIndex(IDatabaseConnection* con, DropIndexStatement* stmt, ScriptMachine* machine, bool debug, ThreadContext* ctx) throw()  final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_RUNTIME_DBIF_ALINOUSDATABASEHANDLER_H_ */
