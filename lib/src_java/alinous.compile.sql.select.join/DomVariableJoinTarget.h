#ifndef ALINOUS_COMPILE_SQL_SELECT_JOIN_DOMVARIABLEJOINTARGET_H_
#define ALINOUS_COMPILE_SQL_SELECT_JOIN_DOMVARIABLEJOINTARGET_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {
class IAlinousElementVisitor;}}

namespace alinous {namespace compile {
class AbstractSrcElement;}}

namespace alinous {namespace compile {namespace analyse {
class SrcAnalyseContext;}}}

namespace alinous {namespace compile {namespace expression {
class DomVariableDescriptor;}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class SQLAnalyseContext;}}}}

namespace alinous {namespace runtime {namespace dom {
class IAlinousVariable;}}}

namespace alinous {namespace db {namespace table {
class DatabaseException;}}}

namespace alinous {namespace runtime {namespace dom {
class IDomVariable;}}}

namespace alinous {namespace runtime {namespace dom {
class DomVariable;}}}

namespace alinous {namespace runtime {namespace dom {
class DomArray;}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableIdentifier;}}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableMetadata;}}}}

namespace java {namespace util {
template <typename  T> class Iterator;}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableColumnMetadata;}}}}

namespace alinous {namespace compile {namespace sql {namespace select {
class SQLWhere;}}}}

namespace alinous {namespace compile {namespace sql {namespace select {
class SQLGroupBy;}}}}

namespace alinous {namespace compile {namespace sql {namespace select {
class SQLLimitOffset;}}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableColumnIdentifier;}}}}

namespace alinous {namespace db {namespace trx {namespace scan {
class ITableTargetScanner;}}}}

namespace alinous {namespace db {namespace trx {
class DbTransaction;}}}

namespace alinous {namespace runtime {namespace engine {
class ScriptMachine;}}}

namespace alinous {namespace compile {namespace sql {namespace select {namespace join {
class SQLJoinCondition;}}}}}

namespace alinous {namespace compile {namespace analyse {
class SourceValidator;}}}

namespace alinous {namespace remote {namespace socket {
class NetworkBinaryBuffer;}}}

namespace alinous {namespace compile {
class IAlinousElement;}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace alinous {namespace compile {namespace sql {namespace select {namespace join {
class AbstractJoinTarget;}}}}}

namespace alinous {namespace compile {
class AlinousElementNetworkFactory;}}

namespace alinous {namespace remote {namespace socket {
class ICommandData;}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace compile {namespace sql {namespace select {namespace join {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::ArrayList;
using ::java::util::Iterator;
using ::alinous::compile::AbstractSrcElement;
using ::alinous::compile::AlinousElementNetworkFactory;
using ::alinous::compile::IAlinousElement;
using ::alinous::compile::IAlinousElementVisitor;
using ::alinous::compile::analyse::SourceValidator;
using ::alinous::compile::analyse::SrcAnalyseContext;
using ::alinous::compile::expression::DomVariableDescriptor;
using ::alinous::compile::sql::analyze::SQLAnalyseContext;
using ::alinous::compile::sql::analyze::ScanTableColumnIdentifier;
using ::alinous::compile::sql::analyze::ScanTableColumnMetadata;
using ::alinous::compile::sql::analyze::ScanTableIdentifier;
using ::alinous::compile::sql::analyze::ScanTableMetadata;
using ::alinous::compile::sql::select::SQLGroupBy;
using ::alinous::compile::sql::select::SQLLimitOffset;
using ::alinous::compile::sql::select::SQLWhere;
using ::alinous::db::table::DatabaseException;
using ::alinous::db::trx::DbTransaction;
using ::alinous::db::trx::scan::ITableTargetScanner;
using ::alinous::remote::socket::ICommandData;
using ::alinous::remote::socket::NetworkBinaryBuffer;
using ::alinous::runtime::dom::DomArray;
using ::alinous::runtime::dom::DomVariable;
using ::alinous::runtime::dom::IAlinousVariable;
using ::alinous::runtime::dom::IDomVariable;
using ::alinous::runtime::dom::VariableException;
using ::alinous::runtime::engine::ScriptMachine;
using ::alinous::system::AlinousException;



class DomVariableJoinTarget final : public AbstractJoinTarget {
public:
	DomVariableJoinTarget(const DomVariableJoinTarget& base) = default;
public:
	DomVariableJoinTarget(ThreadContext* ctx) throw()  : IObject(ctx), AbstractJoinTarget(ctx), domDesc(nullptr), asName(nullptr), scanMeta(nullptr)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~DomVariableJoinTarget() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	DomVariableDescriptor* domDesc;
	String* asName;
	ScanTableMetadata* scanMeta;
public:
	bool visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw()  final;
	bool analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw()  final;
	DomVariableDescriptor* getDomDesc(ThreadContext* ctx) throw() ;
	void setDomDesc(DomVariableDescriptor* domDesc, ThreadContext* ctx) throw() ;
	String* getAsName(ThreadContext* ctx) throw() ;
	void setAsName(String* asName, ThreadContext* ctx) throw() ;
	bool analyseSQLTables(SQLAnalyseContext* context, bool leftValue, bool debug, ThreadContext* ctx) final;
	void analyzeSQL(SQLAnalyseContext* context, bool debug, ThreadContext* ctx) final;
	bool hasTable(ScanTableIdentifier* table, ThreadContext* ctx) throw()  final;
	void optimizeScan(SQLAnalyseContext* context, SQLWhere* where, SQLGroupBy* groupby, SQLLimitOffset* limit, ArrayList<ScanTableColumnIdentifier>* joinRequest, bool debug, ThreadContext* ctx) throw()  final;
	ScanTableMetadata* getScanTableMetadata(ThreadContext* ctx) throw()  final;
	bool isOptimizerCacheable(ThreadContext* ctx) throw()  final;
	ITableTargetScanner* getScanner(DbTransaction* trx, ScriptMachine* machine, ArrayList<ScanTableColumnIdentifier>* joinRequest, bool debug, ThreadContext* ctx) throw()  final;
	SQLJoinCondition* getCondition(ThreadContext* ctx) throw()  final;
	IStatement::StatementType getType(ThreadContext* ctx) throw()  final;
	void validate(SourceValidator* validator, ThreadContext* ctx) throw()  final;
	void readData(NetworkBinaryBuffer* buff, ThreadContext* ctx) final;
	void writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) final;
private:
	void analyseDomTable(SQLAnalyseContext* context, DomVariable* variable, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}}

#endif /* end of ALINOUS_COMPILE_SQL_SELECT_JOIN_DOMVARIABLEJOINTARGET_H_ */
