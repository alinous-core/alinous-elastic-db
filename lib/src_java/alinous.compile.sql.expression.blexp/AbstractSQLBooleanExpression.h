#ifndef ALINOUS_COMPILE_SQL_EXPRESSION_BLEXP_ABSTRACTSQLBOOLEANEXPRESSION_H_
#define ALINOUS_COMPILE_SQL_EXPRESSION_BLEXP_ABSTRACTSQLBOOLEANEXPRESSION_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableColumnIdentifier;}}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class IndexColumnMatchCondition;}}}}

namespace alinous {namespace compile {
class AbstractSrcElement;}}

namespace alinous {namespace remote {namespace socket {
class NetworkBinaryBuffer;}}}

namespace alinous {namespace compile {namespace sql {namespace expression {namespace blexp {
class ISQLBoolExpression;}}}}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace compile {namespace sql {namespace expression {namespace blexp {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::ArrayList;
using ::alinous::compile::AbstractSrcElement;
using ::alinous::compile::sql::analyze::IndexColumnMatchCondition;
using ::alinous::compile::sql::analyze::ScanTableColumnIdentifier;
using ::alinous::remote::socket::NetworkBinaryBuffer;
using ::alinous::runtime::dom::VariableException;



class AbstractSQLBooleanExpression : public ISQLBoolExpression {
public:
	AbstractSQLBooleanExpression(const AbstractSQLBooleanExpression& base) = default;
public:
	AbstractSQLBooleanExpression(ThreadContext* ctx) throw()  : IObject(ctx), ISQLBoolExpression(ctx), asName(nullptr)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~AbstractSQLBooleanExpression() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	String* asName;
public:
	constexpr static const int SQL_OR{1};
	constexpr static const int SQL_AND{2};
public:
	virtual ArrayList<ScanTableColumnIdentifier>* getIndexTargetColumn(ThreadContext* ctx) throw()  = 0;
	virtual IndexColumnMatchCondition* getIndexScanPart(ThreadContext* ctx) throw()  = 0;
	int getLine(ThreadContext* ctx) throw()  final;
	int getStartPosition(ThreadContext* ctx) throw()  final;
	int getEndLine(ThreadContext* ctx) throw()  final;
	int getEndPosition(ThreadContext* ctx) throw()  final;
	AbstractSrcElement* getParent(ThreadContext* ctx) throw()  final;
	void setParent(AbstractSrcElement* parent, ThreadContext* ctx) throw()  final;
	virtual bool isSQLExp(ThreadContext* ctx) throw() ;
	virtual String* getAsName(ThreadContext* ctx) throw() ;
	virtual void setAsName(String* name, ThreadContext* ctx) throw() ;
	void __readData(NetworkBinaryBuffer* buff, ThreadContext* ctx);
	void __writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() ;
public:
	static int operatorFromString(String* opStr, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}}

#endif /* end of ALINOUS_COMPILE_SQL_EXPRESSION_BLEXP_ABSTRACTSQLBOOLEANEXPRESSION_H_ */
