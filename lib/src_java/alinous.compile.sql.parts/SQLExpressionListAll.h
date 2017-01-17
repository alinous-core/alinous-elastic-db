#ifndef ALINOUS_COMPILE_SQL_PARTS_SQLEXPRESSIONLISTALL_H_
#define ALINOUS_COMPILE_SQL_PARTS_SQLEXPRESSIONLISTALL_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {namespace sql {namespace analyze {
class SQLAnalyseContext;}}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableIdentifier;}}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableColumnIdentifier;}}}}

namespace alinous {namespace compile {namespace sql {namespace expression {
class ISQLExpression;}}}}

namespace alinous {namespace runtime {namespace variant {
class VariantValue;}}}

namespace alinous {namespace db {namespace trx {namespace scan {
class ScanResultRecord;}}}}

namespace alinous {namespace runtime {namespace engine {
class ScriptMachine;}}}

namespace alinous {namespace runtime {namespace dom {
class IAlinousVariable;}}}

namespace alinous {namespace compile {
class ExpressionSourceId;}}

namespace alinous {namespace compile {namespace analyse {
class SrcAnalyseContext;}}}

namespace alinous {namespace compile {
class IAlinousElementVisitor;}}

namespace alinous {namespace compile {
class AbstractSrcElement;}}

namespace alinous {namespace db {namespace table {
class DatabaseException;}}}

namespace alinous {namespace remote {namespace socket {
class NetworkBinaryBuffer;}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryBuilder;}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryFetcher;}}}

namespace alinous {namespace compile {namespace sql {namespace parts {
class AbstractExpressionPart;}}}}

namespace alinous {namespace compile {namespace expression {
class IExpression;}}}

namespace alinous {namespace compile {namespace expression {
class IExpressionFactory;}}}

namespace alinous {namespace remote {namespace socket {
class ICommandData;}}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace compile {namespace sql {namespace parts {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::ArrayList;
using ::alinous::buffer::storage::FileStorageEntryBuilder;
using ::alinous::buffer::storage::FileStorageEntryFetcher;
using ::alinous::compile::AbstractSrcElement;
using ::alinous::compile::ExpressionSourceId;
using ::alinous::compile::IAlinousElementVisitor;
using ::alinous::compile::analyse::SrcAnalyseContext;
using ::alinous::compile::expression::IExpression;
using ::alinous::compile::expression::IExpressionFactory;
using ::alinous::compile::sql::analyze::SQLAnalyseContext;
using ::alinous::compile::sql::analyze::ScanTableColumnIdentifier;
using ::alinous::compile::sql::analyze::ScanTableIdentifier;
using ::alinous::compile::sql::expression::ISQLExpression;
using ::alinous::db::table::DatabaseException;
using ::alinous::db::trx::scan::ScanResultRecord;
using ::alinous::remote::socket::ICommandData;
using ::alinous::remote::socket::NetworkBinaryBuffer;
using ::alinous::runtime::dom::IAlinousVariable;
using ::alinous::runtime::dom::VariableException;
using ::alinous::runtime::engine::ScriptMachine;
using ::alinous::runtime::variant::VariantValue;
using ::alinous::system::AlinousException;



class SQLExpressionListAll final : public AbstractExpressionPart {
public:
	SQLExpressionListAll(const SQLExpressionListAll& base) = default;
public:
	SQLExpressionListAll(ThreadContext* ctx) throw()  : IObject(ctx), AbstractExpressionPart(ctx), asName(nullptr)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~SQLExpressionListAll() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	String* asName;
public:
	bool hasSubExp(ThreadContext* ctx) throw()  final;
	bool analyseSQL(SQLAnalyseContext* context, bool leftValue, bool debug, ThreadContext* ctx) final;
	bool hasTable(ScanTableIdentifier* table, ThreadContext* ctx) throw()  final;
	ArrayList<ScanTableColumnIdentifier>* getColumns(ThreadContext* ctx) throw()  final;
	bool isJoinCondition(ThreadContext* ctx) throw()  final;
	void collectJoinCondition(ArrayList<ISQLExpression>* list, ThreadContext* ctx) throw()  final;
	bool isColumnIdentifier(ThreadContext* ctx) throw()  final;
	ScanTableColumnIdentifier* toColumnIdentifier(ThreadContext* ctx) throw()  final;
	VariantValue* resolveSQLExpression(ScanResultRecord* record, ScriptMachine* machine, bool debug, ThreadContext* ctx) final;
	IAlinousVariable* resolveExpression(ScriptMachine* machine, bool debug, ThreadContext* ctx) final;
	ExpressionSourceId* getSourceId(ThreadContext* ctx) throw()  final;
	bool isConstant(ThreadContext* ctx) throw()  final;
	bool analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw()  final;
	bool visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw()  final;
	bool hasArrayResult(ThreadContext* ctx) throw()  final;
	ArrayList<VariantValue>* resolveSQLExpressionAsArray(ScanResultRecord* record, ScriptMachine* machine, bool debug, ThreadContext* ctx) final;
	String* getAsName(ThreadContext* ctx) throw()  final;
	void setAsName(String* name, ThreadContext* ctx) throw()  final;
	int getExpressionType(ThreadContext* ctx) throw()  final;
	void readData(NetworkBinaryBuffer* buff, ThreadContext* ctx) final;
	void writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw()  final;
	int fileSize(ThreadContext* ctx) final;
	void toFileEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx) final;
	void fromFileEntry(FileStorageEntryFetcher* fetcher, ThreadContext* ctx) final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_COMPILE_SQL_PARTS_SQLEXPRESSIONLISTALL_H_ */
