#ifndef ALINOUS_COMPILE_SQL_CREATETABLESTATEMENT_H_
#define ALINOUS_COMPILE_SQL_CREATETABLESTATEMENT_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace db {
class TableSchema;}}

namespace alinous {namespace runtime {namespace engine {
class ScriptMachine;}}}

namespace alinous {namespace compile {namespace sql {namespace select {namespace join {
class TableJoinTarget;}}}}}

namespace alinous {namespace db {namespace table {
class TableMetadata;}}}

namespace alinous {namespace compile {namespace sql {namespace ddl {
class DdlColumnDescriptor;}}}}

namespace alinous {namespace db {namespace table {
class TableColumnMetadata;}}}

namespace alinous {namespace compile {namespace sql {namespace ddl {
class ShardKeys;}}}}

namespace alinous {namespace db {namespace table {
class TablePartitionKeyCollection;}}}

namespace alinous {namespace db {namespace table {
class TablePartitionRangeCollection;}}}

namespace alinous {namespace db {namespace table {
class TablePartitionKey;}}}

namespace alinous {namespace db {namespace table {
class TablePartitionRange;}}}

namespace alinous {namespace db {namespace table {
class DatabaseException;}}}

namespace alinous {namespace runtime {namespace variant {
class VariantValue;}}}

namespace alinous {namespace compile {namespace analyse {
class SourceValidator;}}}

namespace alinous {namespace compile {
class IAlinousElementVisitor;}}

namespace alinous {namespace compile {
class AbstractSrcElement;}}

namespace alinous {namespace compile {namespace analyse {
class SrcAnalyseContext;}}}

namespace alinous {namespace compile {namespace sql {namespace ddl {
class Unique;}}}}

namespace alinous {namespace compile {namespace sql {namespace ddl {
class CheckDefinition;}}}}

namespace alinous {namespace compile {namespace sql {namespace select {namespace join {
class IJoinTarget;}}}}}

namespace alinous {namespace compile {namespace sql {namespace ddl {
class PrimaryKeys;}}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class SQLAnalyseContext;}}}}

namespace alinous {namespace remote {namespace socket {
class NetworkBinaryBuffer;}}}

namespace alinous {namespace compile {
class IAlinousElement;}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace java {namespace util {
template <typename  T> class List;}}

namespace alinous {namespace compile {namespace sql {
class AbstractSQLStatement;}}}

namespace alinous {namespace compile {
class AlinousElementNetworkFactory;}}

namespace alinous {namespace compile {namespace sql {namespace ddl {
class ColumnTypeDescriptor;}}}}

namespace alinous {namespace remote {namespace socket {
class ICommandData;}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace compile {namespace sql {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::ArrayList;
using ::java::util::List;
using ::alinous::compile::AbstractSrcElement;
using ::alinous::compile::AlinousElementNetworkFactory;
using ::alinous::compile::IAlinousElement;
using ::alinous::compile::IAlinousElementVisitor;
using ::alinous::compile::analyse::SourceValidator;
using ::alinous::compile::analyse::SrcAnalyseContext;
using ::alinous::compile::sql::analyze::SQLAnalyseContext;
using ::alinous::compile::sql::ddl::CheckDefinition;
using ::alinous::compile::sql::ddl::ColumnTypeDescriptor;
using ::alinous::compile::sql::ddl::DdlColumnDescriptor;
using ::alinous::compile::sql::ddl::PrimaryKeys;
using ::alinous::compile::sql::ddl::ShardKeys;
using ::alinous::compile::sql::ddl::Unique;
using ::alinous::compile::sql::select::join::IJoinTarget;
using ::alinous::compile::sql::select::join::TableJoinTarget;
using ::alinous::db::TableSchema;
using ::alinous::db::table::DatabaseException;
using ::alinous::db::table::TableColumnMetadata;
using ::alinous::db::table::TableMetadata;
using ::alinous::db::table::TablePartitionKey;
using ::alinous::db::table::TablePartitionKeyCollection;
using ::alinous::db::table::TablePartitionRange;
using ::alinous::db::table::TablePartitionRangeCollection;
using ::alinous::remote::socket::ICommandData;
using ::alinous::remote::socket::NetworkBinaryBuffer;
using ::alinous::runtime::dom::VariableException;
using ::alinous::runtime::engine::ScriptMachine;
using ::alinous::runtime::variant::VariantValue;
using ::alinous::system::AlinousException;



class CreateTableStatement final : public AbstractSQLStatement {
public:
	CreateTableStatement(const CreateTableStatement& base) = default;
public:
	CreateTableStatement(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~CreateTableStatement() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	IJoinTarget* table;
	ArrayList<DdlColumnDescriptor>* columns;
	ArrayList<Unique>* uniques;
	ArrayList<CheckDefinition>* checks;
	PrimaryKeys* primaryKeys;
	String* region;
	List<ShardKeys>* partitionKeys;
	TableMetadata* metadata;
public:
	TableSchema* createMetadata(ScriptMachine* machine, bool debug, ThreadContext* ctx);
	void validate(SourceValidator* validator, ThreadContext* ctx) throw()  final;
	TableMetadata* getMetadata(ThreadContext* ctx) throw() ;
	bool visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw()  final;
	bool analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw()  final;
	void addColumn(DdlColumnDescriptor* col, ThreadContext* ctx) throw() ;
	void addUnique(Unique* unique, ThreadContext* ctx) throw() ;
	void addCheckDef(CheckDefinition* def, ThreadContext* ctx) throw() ;
	IJoinTarget* getTable(ThreadContext* ctx) throw() ;
	void setTable(IJoinTarget* table, ThreadContext* ctx) throw() ;
	PrimaryKeys* getPrimaryKeys(ThreadContext* ctx) throw() ;
	void setPrimaryKeys(PrimaryKeys* primaryKeys, ThreadContext* ctx) throw() ;
	ArrayList<DdlColumnDescriptor>* getColumns(ThreadContext* ctx) throw() ;
	ArrayList<Unique>* getUniques(ThreadContext* ctx) throw() ;
	ArrayList<CheckDefinition>* getChecks(ThreadContext* ctx) throw() ;
	String* getRegion(ThreadContext* ctx) throw() ;
	void setRegion(String* region, ThreadContext* ctx) throw() ;
	IStatement::StatementType getType(ThreadContext* ctx) throw()  final;
	void analyzeSQL(SQLAnalyseContext* context, bool debug, ThreadContext* ctx) throw()  final;
	void readData(NetworkBinaryBuffer* buff, ThreadContext* ctx) final;
	void writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) final;
	void addPartitionKey(ShardKeys* key, ThreadContext* ctx) throw() ;
private:
	TablePartitionKey* toPartitionKeys(TableMetadata* meta, ArrayList<String>* cols, ThreadContext* ctx);
	TablePartitionRange* makeDefaultRange(TableMetadata* meta, TablePartitionKey* key, ThreadContext* ctx) throw() ;
	int ddlColumnType2VariantType(int coltype, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_COMPILE_SQL_CREATETABLESTATEMENT_H_ */
