#ifndef ALINOUS_COMPILE_SQL_EXPRESSION_ABSTRACTSQLCOLLECTIONEXPRESSION_H_
#define ALINOUS_COMPILE_SQL_EXPRESSION_ABSTRACTSQLCOLLECTIONEXPRESSION_H_
namespace alinous{namespace annotation{
class NoBlankConstructor;
}}
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {namespace sql {namespace expression {
class ISQLExpression;}}}}

namespace alinous {namespace compile {namespace sql {namespace expression {
class SQLSubExpression;}}}}

namespace alinous {namespace compile {
class IAlinousElementVisitor;}}

namespace alinous {namespace compile {
class AbstractSrcElement;}}

namespace alinous {namespace compile {namespace analyse {
class SrcAnalyseContext;}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class SQLAnalyseContext;}}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableIdentifier;}}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableColumnIdentifier;}}}}

namespace alinous {namespace remote {namespace socket {
class NetworkBinaryBuffer;}}}

namespace alinous {namespace compile {
class IAlinousElement;}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace alinous {namespace compile {
class AlinousElementNetworkFactory;}}

namespace alinous {namespace db {namespace table {
class DatabaseException;}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace compile {namespace sql {namespace expression {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::ArrayList;
using ::alinous::compile::AbstractSrcElement;
using ::alinous::compile::AlinousElementNetworkFactory;
using ::alinous::compile::IAlinousElement;
using ::alinous::compile::IAlinousElementVisitor;
using ::alinous::compile::analyse::SrcAnalyseContext;
using ::alinous::compile::sql::analyze::SQLAnalyseContext;
using ::alinous::compile::sql::analyze::ScanTableIdentifier;
using ::alinous::compile::sql::analyze::ScanTableColumnIdentifier;
using ::alinous::db::table::DatabaseException;
using ::alinous::remote::socket::NetworkBinaryBuffer;
using ::alinous::runtime::dom::VariableException;
using ::alinous::system::AlinousException;



class AbstractSQLCollectionExpression : public ISQLExpression {
public:
	AbstractSQLCollectionExpression(const AbstractSQLCollectionExpression& base) = default;
public:
	AbstractSQLCollectionExpression(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~AbstractSQLCollectionExpression() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	ISQLExpression* first;
	ArrayList<SQLSubExpression>* expressions;
	String* asName;
public:
	ISQLExpression* getFirst(ThreadContext* ctx) throw() ;
	void setFirst(ISQLExpression* first, ThreadContext* ctx) throw() ;
	ArrayList<SQLSubExpression>* getExpressions(ThreadContext* ctx) throw() ;
	void addSubExpression(SQLSubExpression* exp, ThreadContext* ctx) throw() ;
	bool visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw()  final;
	bool isConstant(ThreadContext* ctx) throw()  final;
	bool analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw()  final;
	bool analyseSQL(SQLAnalyseContext* context, bool leftValue, bool debug, ThreadContext* ctx) final;
	bool hasTable(ScanTableIdentifier* table, ThreadContext* ctx) throw()  final;
	ArrayList<ScanTableColumnIdentifier>* getColumns(ThreadContext* ctx) throw()  final;
	int getLine(ThreadContext* ctx) throw()  final;
	int getStartPosition(ThreadContext* ctx) throw()  final;
	int getEndLine(ThreadContext* ctx) throw()  final;
	int getEndPosition(ThreadContext* ctx) throw()  final;
	AbstractSrcElement* getParent(ThreadContext* ctx) throw()  final;
	void setParent(AbstractSrcElement* parent, ThreadContext* ctx) throw()  final;
	bool isSQLExp(ThreadContext* ctx) throw()  final;
	String* getAsName(ThreadContext* ctx) throw()  final;
	void setAsName(String* name, ThreadContext* ctx) throw()  final;
	void __readData(NetworkBinaryBuffer* buff, ThreadContext* ctx);
	void __writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_COMPILE_SQL_EXPRESSION_ABSTRACTSQLCOLLECTIONEXPRESSION_H_ */
