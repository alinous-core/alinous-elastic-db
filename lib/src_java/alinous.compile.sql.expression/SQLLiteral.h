#ifndef ALINOUS_COMPILE_SQL_EXPRESSION_SQLLITERAL_H_
#define ALINOUS_COMPILE_SQL_EXPRESSION_SQLLITERAL_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {
class IAlinousElementVisitor;}}

namespace alinous {namespace compile {
class AbstractSrcElement;}}

namespace alinous {namespace runtime {namespace dom {
class IAlinousVariable;}}}

namespace alinous {namespace runtime {namespace engine {
class ScriptMachine;}}}

namespace alinous {namespace compile {namespace analyse {
class SrcAnalyseContext;}}}

namespace alinous {namespace runtime {namespace variant {
class VariantValue;}}}

namespace alinous {namespace compile {
class ExpressionSourceId;}}

namespace alinous {namespace compile {namespace analyse {
class AlinousType;}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class SQLAnalyseContext;}}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableIdentifier;}}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableColumnIdentifier;}}}}

namespace alinous {namespace compile {namespace sql {namespace expression {
class ISQLExpression;}}}}

namespace alinous {namespace db {namespace trx {namespace scan {
class ScanResultRecord;}}}}

namespace alinous {namespace db {namespace table {
class DatabaseException;}}}

namespace alinous {namespace remote {namespace socket {
class NetworkBinaryBuffer;}}}

namespace alinous {namespace compile {namespace sql {namespace expression {
class AbstractSQLExpression;}}}}

namespace alinous {namespace compile {namespace expression {
class IExpression;}}}

namespace alinous {namespace remote {namespace socket {
class ICommandData;}}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

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
using ::alinous::compile::ExpressionSourceId;
using ::alinous::compile::IAlinousElementVisitor;
using ::alinous::compile::analyse::AlinousType;
using ::alinous::compile::analyse::SrcAnalyseContext;
using ::alinous::compile::expression::IExpression;
using ::alinous::compile::sql::analyze::SQLAnalyseContext;
using ::alinous::compile::sql::analyze::ScanTableIdentifier;
using ::alinous::db::table::DatabaseException;
using ::alinous::db::trx::scan::ScanResultRecord;
using ::alinous::remote::socket::ICommandData;
using ::alinous::remote::socket::NetworkBinaryBuffer;
using ::alinous::compile::sql::analyze::ScanTableColumnIdentifier;
using ::alinous::runtime::dom::IAlinousVariable;
using ::alinous::runtime::dom::VariableException;
using ::alinous::runtime::engine::ScriptMachine;
using ::alinous::runtime::variant::VariantValue;
using ::alinous::system::AlinousException;

class __SQLLiteral__sqlliteralType : public EnumBase {
public:
	__SQLLiteral__sqlliteralType() = default;
	constexpr __SQLLiteral__sqlliteralType(const EnumBase& base) : EnumBase(base) {}
	constexpr explicit __SQLLiteral__sqlliteralType(const int ord) : EnumBase(ord) {}

	static constexpr EnumBase __DEFAULT_NULL{0};
	static constexpr EnumBase  INTEGER_LITERAL{1};
	static constexpr EnumBase  FLOATING_POINT_LITERAL{2};
	static constexpr EnumBase  CHARACTER_LITERAL{3};
	static constexpr EnumBase  STRING_LITERAL{4};
	static constexpr EnumBase  BOOLEAN{5};
	static constexpr EnumBase  NULL_LITERAL{6};
};


class SQLLiteral final : public AbstractSQLExpression {
public:
	class sqlliteralType : public __SQLLiteral__sqlliteralType {
	public:
		sqlliteralType() = default;constexpr sqlliteralType(const EnumBase& base) :  __SQLLiteral__sqlliteralType(base) {};
	};
public:
	SQLLiteral(const SQLLiteral& base) = default;
public:
	SQLLiteral(SQLLiteral::sqlliteralType type, ThreadContext* ctx) throw() ;
	void __construct_impl(SQLLiteral::sqlliteralType type, ThreadContext* ctx) throw() ;
	SQLLiteral(ThreadContext* ctx) throw()  : IObject(ctx), AbstractSQLExpression(ctx), vvalue(nullptr), value(nullptr)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~SQLLiteral() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	SQLLiteral::sqlliteralType litType;
	VariantValue* vvalue;
private:
	String* value;
public:
	bool visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw()  final;
	bool isConstant(ThreadContext* ctx) throw()  final;
	String* getValue(ThreadContext* ctx) throw() ;
	void setValue(String* value, ThreadContext* ctx) throw() ;
	SQLLiteral::sqlliteralType getLitType(ThreadContext* ctx) throw() ;
	IAlinousVariable* resolveExpression(ScriptMachine* machine, bool debug, ThreadContext* ctx) final;
	bool analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw()  final;
	ExpressionSourceId* getSourceId(ThreadContext* ctx) throw()  final;
	bool analyseSQL(SQLAnalyseContext* context, bool leftValue, bool debug, ThreadContext* ctx) throw()  final;
	bool hasTable(ScanTableIdentifier* table, ThreadContext* ctx) throw()  final;
	ArrayList<ScanTableColumnIdentifier>* getColumns(ThreadContext* ctx) throw()  final;
	bool hasSubExp(ThreadContext* ctx) throw()  final;
	bool isJoinCondition(ThreadContext* ctx) throw()  final;
	void collectJoinCondition(ArrayList<ISQLExpression>* list, ThreadContext* ctx) throw()  final;
	bool isColumnIdentifier(ThreadContext* ctx) throw()  final;
	ScanTableColumnIdentifier* toColumnIdentifier(ThreadContext* ctx) throw()  final;
	VariantValue* resolveSQLExpression(ScanResultRecord* record, ScriptMachine* machine, bool debug, ThreadContext* ctx) final;
	bool hasArrayResult(ThreadContext* ctx) throw()  final;
	ArrayList<VariantValue>* resolveSQLExpressionAsArray(ScanResultRecord* record, ScriptMachine* machine, bool debug, ThreadContext* ctx) final;
	int getExpressionType(ThreadContext* ctx) throw()  final;
	void readData(NetworkBinaryBuffer* buff, ThreadContext* ctx) final;
	void writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw()  final;
private:
	int fromEnum(ThreadContext* ctx) throw() ;
	void toEnum(int num, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_COMPILE_SQL_EXPRESSION_SQLLITERAL_H_ */
