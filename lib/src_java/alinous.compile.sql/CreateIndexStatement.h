#ifndef ALINOUS_COMPILE_SQL_CREATEINDEXSTATEMENT_H_
#define ALINOUS_COMPILE_SQL_CREATEINDEXSTATEMENT_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {namespace sql {namespace select {namespace join {
class TableJoinTarget;}}}}}

namespace alinous {namespace compile {namespace sql {
class TableAndSchema;}}}

namespace alinous {namespace compile {namespace analyse {
class SourceValidator;}}}

namespace alinous {namespace compile {
class IAlinousElementVisitor;}}

namespace alinous {namespace compile {
class AbstractSrcElement;}}

namespace alinous {namespace compile {namespace analyse {
class SrcAnalyseContext;}}}

namespace alinous {namespace compile {namespace sql {namespace select {namespace join {
class IJoinTarget;}}}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class SQLAnalyseContext;}}}}

namespace alinous {namespace remote {namespace socket {
class NetworkBinaryBuffer;}}}

namespace alinous {namespace compile {
class IAlinousElement;}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace alinous {namespace compile {namespace sql {
class AbstractSQLStatement;}}}

namespace alinous {namespace compile {
class AlinousElementNetworkFactory;}}

namespace alinous {namespace remote {namespace socket {
class ICommandData;}}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace compile {namespace sql {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::ArrayList;
using ::alinous::compile::AbstractSrcElement;
using ::alinous::compile::AlinousElementNetworkFactory;
using ::alinous::compile::IAlinousElement;
using ::alinous::compile::IAlinousElementVisitor;
using ::alinous::compile::analyse::SourceValidator;
using ::alinous::compile::analyse::SrcAnalyseContext;
using ::alinous::compile::sql::analyze::SQLAnalyseContext;
using ::alinous::compile::sql::select::join::IJoinTarget;
using ::alinous::compile::sql::select::join::TableJoinTarget;
using ::alinous::remote::socket::ICommandData;
using ::alinous::remote::socket::NetworkBinaryBuffer;
using ::alinous::runtime::dom::VariableException;



class CreateIndexStatement final : public AbstractSQLStatement {
public:
	CreateIndexStatement(const CreateIndexStatement& base) = default;
public:
	CreateIndexStatement(ThreadContext* ctx) throw()  : IObject(ctx), AbstractSQLStatement(ctx), name(nullptr), table(nullptr), columns(GCUtils<ArrayList<String> >::ins(this, (new(ctx) ArrayList<String>(ctx)), ctx, __FILEW__, __LINE__, L""))
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~CreateIndexStatement() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	IJoinTarget* name;
	IJoinTarget* table;
	ArrayList<String>* columns;
public:
	String* getIndexName(ThreadContext* ctx) throw() ;
	TableAndSchema* getTableAndSchema(ThreadContext* ctx) throw() ;
	IStatement::StatementType getType(ThreadContext* ctx) throw()  final;
	void validate(SourceValidator* validator, ThreadContext* ctx) throw()  final;
	bool visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw()  final;
	bool analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw()  final;
	void addColumn(String* column, ThreadContext* ctx) throw() ;
	IJoinTarget* getName(ThreadContext* ctx) throw() ;
	void setName(IJoinTarget* name, ThreadContext* ctx) throw() ;
	IJoinTarget* getTable(ThreadContext* ctx) throw() ;
	void setTable(IJoinTarget* table, ThreadContext* ctx) throw() ;
	ArrayList<String>* getColumns(ThreadContext* ctx) throw() ;
	void analyzeSQL(SQLAnalyseContext* context, bool debug, ThreadContext* ctx) throw()  final;
	void readData(NetworkBinaryBuffer* buff, ThreadContext* ctx) final;
	void writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw()  final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_COMPILE_SQL_CREATEINDEXSTATEMENT_H_ */
