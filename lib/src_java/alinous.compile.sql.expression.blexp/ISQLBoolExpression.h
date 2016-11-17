#ifndef ALINOUS_COMPILE_SQL_EXPRESSION_BLEXP_ISQLBOOLEXPRESSION_H_
#define ALINOUS_COMPILE_SQL_EXPRESSION_BLEXP_ISQLBOOLEXPRESSION_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {namespace sql {namespace expression {
class ISQLExpression;}}}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace compile {namespace sql {namespace expression {namespace blexp {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::compile::sql::expression::ISQLExpression;



class ISQLBoolExpression : public ISQLExpression {
public:
	ISQLBoolExpression(const ISQLBoolExpression& base) = default;
public:
	ISQLBoolExpression(ThreadContext* ctx) throw()  : IObject(ctx), ISQLExpression(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~ISQLBoolExpression() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}}

#endif /* end of ALINOUS_COMPILE_SQL_EXPRESSION_BLEXP_ISQLBOOLEXPRESSION_H_ */
