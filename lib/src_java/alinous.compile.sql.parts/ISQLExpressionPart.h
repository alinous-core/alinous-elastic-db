#ifndef ALINOUS_COMPILE_SQL_PARTS_ISQLEXPRESSIONPART_H_
#define ALINOUS_COMPILE_SQL_PARTS_ISQLEXPRESSIONPART_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {namespace sql {namespace expression {
class ISQLExpression;}}}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace compile {namespace sql {namespace parts {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::compile::sql::expression::ISQLExpression;



class ISQLExpressionPart : public ISQLExpression {
public:
	ISQLExpressionPart(const ISQLExpressionPart& base) = default;
public:
	ISQLExpressionPart(ThreadContext* ctx) throw()  : IObject(ctx), ISQLExpression(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~ISQLExpressionPart() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_COMPILE_SQL_PARTS_ISQLEXPRESSIONPART_H_ */
