#ifndef ALINOUS_COMPILE_SQL_EXPRESSION_ABSTRACTSQLEXPRESSION_H_
#define ALINOUS_COMPILE_SQL_EXPRESSION_ABSTRACTSQLEXPRESSION_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {
class AbstractSrcElement;}}

namespace alinous {namespace compile {namespace sql {namespace expression {
class ISQLExpression;}}}}

namespace alinous {namespace compile {namespace expression {namespace blexp {
class AbstractBooleanExpression;}}}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace compile {namespace sql {namespace expression {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::compile::AbstractSrcElement;
using ::alinous::compile::expression::blexp::AbstractBooleanExpression;



class AbstractSQLExpression : public ISQLExpression {
public:
	AbstractSQLExpression(const AbstractSQLExpression& base) = default;
public:
	AbstractSQLExpression(ThreadContext* ctx) throw()  : IObject(ctx), ISQLExpression(ctx), asName(nullptr)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~AbstractSQLExpression() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	String* asName;
public:
	constexpr static const int PLUS{1};
	constexpr static const int MINUS{2};
	constexpr static const int MUL{3};
	constexpr static const int DIV{4};
	constexpr static const int MOD{5};
public:
	int getLine(ThreadContext* ctx) throw()  final;
	int getStartPosition(ThreadContext* ctx) throw()  final;
	int getEndLine(ThreadContext* ctx) throw()  final;
	int getEndPosition(ThreadContext* ctx) throw()  final;
	AbstractSrcElement* getParent(ThreadContext* ctx) throw()  final;
	void setParent(AbstractSrcElement* parent, ThreadContext* ctx) throw()  final;
	virtual bool isSQLExp(ThreadContext* ctx) throw() ;
	virtual String* getAsName(ThreadContext* ctx) throw() ;
	virtual void setAsName(String* name, ThreadContext* ctx) throw() ;
public:
	static int operatorFromString(String* opStr, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_COMPILE_SQL_EXPRESSION_ABSTRACTSQLEXPRESSION_H_ */
