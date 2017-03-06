#ifndef ALINOUS_COMPILE_EXPRESSION_BLEXP_ABSTRACTBOOLEANEXPRESSION_H_
#define ALINOUS_COMPILE_EXPRESSION_BLEXP_ABSTRACTBOOLEANEXPRESSION_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {namespace expression {
class AbstractExpression;}}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace compile {namespace expression {namespace blexp {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::compile::expression::AbstractExpression;



class AbstractBooleanExpression : public AbstractExpression {
public:
	AbstractBooleanExpression(const AbstractBooleanExpression& base) = default;
public:
	AbstractBooleanExpression(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~AbstractBooleanExpression() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	constexpr static const int CONDITIONAL_OR{1};
	constexpr static const int CONDITIONAL_AND{2};
	constexpr static const int INCLUSIVE_OR{3};
	constexpr static const int INCLUSIVE_AND{4};
	constexpr static const int EXCUSIVE_OR{5};
public:
	bool isSQLExp(ThreadContext* ctx) throw()  final;
public:
	static int operatorFromString(String* opStr, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}

#endif /* end of ALINOUS_COMPILE_EXPRESSION_BLEXP_ABSTRACTBOOLEANEXPRESSION_H_ */
