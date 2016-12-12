#ifndef ALINOUS_RUNTIME_DBIF_IDATABASEDRIVER_H_
#define ALINOUS_RUNTIME_DBIF_IDATABASEDRIVER_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace system {
class AlinousCore;}}

namespace alinous {namespace system {namespace config {
class AlinousDbInstanceInfo;}}}

namespace alinous {namespace runtime {namespace dbif {
class IDatabaseConnection;}}}

namespace alinous {namespace runtime {namespace engine {
class ScriptMachine;}}}

namespace alinous {namespace compile {namespace sql {
class CreateTableStatement;}}}

namespace alinous {namespace compile {namespace sql {
class DropTableStatement;}}}

namespace alinous {namespace compile {namespace sql {
class CreateIndexStatement;}}}

namespace alinous {namespace compile {namespace sql {
class DropIndexStatement;}}}

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
using ::alinous::db::AlinousDbException;
using ::alinous::db::table::DatabaseException;
using ::alinous::runtime::engine::ScriptMachine;
using ::alinous::system::AlinousCore;
using ::alinous::system::AlinousException;
using ::alinous::system::config::AlinousDbInstanceInfo;



class IDatabaseDriver : public virtual IObject {
public:
	IDatabaseDriver(const IDatabaseDriver& base) = default;
public:
	IDatabaseDriver(ThreadContext* ctx) throw()  : IObject(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~IDatabaseDriver() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	constexpr static const int UNREAD_COMMITTED{0};
	constexpr static const int READ_COMMITTED{1};
	constexpr static const int REPEATABLE_READ{2};
	constexpr static const int SERIALIZABLE{3};
public:
	virtual IObject* getDatabase(ThreadContext* ctx) throw()  = 0;
	virtual int getDefaultAcid(ThreadContext* ctx) throw()  = 0;
	virtual void initDriver(AlinousCore* core, AlinousDbInstanceInfo* instanceConfig, ThreadContext* ctx) = 0;
	virtual void dispose(ThreadContext* ctx) throw()  = 0;
	virtual void createInstance(String* instanceName, ThreadContext* ctx) throw()  = 0;
	virtual void dropInstance(String* instanceName, ThreadContext* ctx) throw()  = 0;
	virtual IDatabaseConnection* connect(ThreadContext* ctx) throw()  = 0;
	virtual void disconnect(IDatabaseConnection* con, bool debug, ThreadContext* ctx) throw()  = 0;
	virtual void createSchema(IDatabaseConnection* con, String* schema, ScriptMachine* machine, bool debug, ThreadContext* ctx) throw()  = 0;
	virtual void dropSchema(IDatabaseConnection* con, String* schema, ScriptMachine* machine, bool debug, ThreadContext* ctx) throw()  = 0;
	virtual ArrayList<String>* showAllSchema(IDatabaseConnection* con, bool debug, ThreadContext* ctx) throw()  = 0;
	virtual void createTable(IDatabaseConnection* con, CreateTableStatement* stmt, ScriptMachine* machine, bool debug, ThreadContext* ctx) = 0;
	virtual void dropTable(IDatabaseConnection* con, DropTableStatement* stmt, ScriptMachine* machine, bool debug, ThreadContext* ctx) throw()  = 0;
	virtual void createIndex(IDatabaseConnection* con, CreateIndexStatement* stmt, ScriptMachine* machine, bool debug, ThreadContext* ctx) = 0;
	virtual void dropIndex(IDatabaseConnection* con, DropIndexStatement* stmt, ScriptMachine* machine, bool debug, ThreadContext* ctx) throw()  = 0;
	virtual void commit(IDatabaseConnection* con, ThreadContext* ctx) = 0;
	virtual void rollback(IDatabaseConnection* con, ThreadContext* ctx) = 0;
	virtual ISQLSelectResult* selectSQL(IDatabaseConnection* con, SelectStatement* stmt, ScriptMachine* machine, bool debug, ThreadContext* ctx) = 0;
	virtual void insertSQL(IDatabaseConnection* con, InsertStatement* stmt, ScriptMachine* machine, bool debug, ThreadContext* ctx) = 0;
	virtual void updateSQL(IDatabaseConnection* con, UpdateStatement* stmt, ScriptMachine* machine, bool debug, ThreadContext* ctx) = 0;
	virtual void deleteSQL(IDatabaseConnection* con, DeleteStatement* stmt, ScriptMachine* machine, bool debug, ThreadContext* ctx) = 0;
	virtual void begin(IDatabaseConnection* con, int acid, ThreadContext* ctx) = 0;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_RUNTIME_DBIF_IDATABASEDRIVER_H_ */
