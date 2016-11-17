#ifndef ALINOUS_RUNTIME_DBIF_IDATABASECONNECTION_H_
#define ALINOUS_RUNTIME_DBIF_IDATABASECONNECTION_H_
namespace alinous{namespace annotation{
class OneSource;
}}
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
using ::alinous::system::AlinousException;



class IDatabaseConnection : public virtual IObject {
public:
	IDatabaseConnection(const IDatabaseConnection& base) = default;
public:
	IDatabaseConnection(ThreadContext* ctx) throw()  : IObject(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~IDatabaseConnection() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	virtual void close(ThreadContext* ctx) throw()  = 0;
	virtual bool isAutoCommit(ThreadContext* ctx) throw()  = 0;
	virtual void createSchema(String* schema, ScriptMachine* machine, bool debug, ThreadContext* ctx) throw()  = 0;
	virtual void dropSchema(String* schema, ScriptMachine* machine, bool debug, ThreadContext* ctx) throw()  = 0;
	virtual ArrayList<String>* showAllSchema(ThreadContext* ctx) throw()  = 0;
	virtual void createTable(CreateTableStatement* stmt, ScriptMachine* machine, bool debug, ThreadContext* ctx) = 0;
	virtual void dropTable(DropTableStatement* stmt, ScriptMachine* machine, bool debug, ThreadContext* ctx) throw()  = 0;
	virtual void createIndex(CreateIndexStatement* stmt, ScriptMachine* machine, bool debug, ThreadContext* ctx) = 0;
	virtual void dropIndex(DropIndexStatement* stmt, ScriptMachine* machine, bool debug, ThreadContext* ctx) throw()  = 0;
	virtual void commit(ThreadContext* ctx) = 0;
	virtual void rollback(ThreadContext* ctx) = 0;
	virtual ISQLSelectResult* selectSQL(SelectStatement* stmt, ScriptMachine* machine, bool debug, ThreadContext* ctx) = 0;
	virtual void insertSQL(InsertStatement* stmt, ScriptMachine* machine, bool debug, ThreadContext* ctx) = 0;
	virtual void updateSQL(UpdateStatement* stmt, ScriptMachine* machine, bool debug, ThreadContext* ctx) = 0;
	virtual void deleteSQL(DeleteStatement* stmt, ScriptMachine* machine, bool debug, ThreadContext* ctx) = 0;
	virtual void begin(int acid, ThreadContext* ctx) = 0;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_RUNTIME_DBIF_IDATABASECONNECTION_H_ */
