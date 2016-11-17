#ifndef ALINOUS_COMPILE_EXPRESSION_ABSTRACTEXPRESSION_H_
#define ALINOUS_COMPILE_EXPRESSION_ABSTRACTEXPRESSION_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {
class AbstractSrcElement;}}

namespace alinous {namespace compile {namespace expression {
class IExpression;}}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace compile {namespace expression {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::compile::AbstractSrcElement;



class AbstractExpression : public IExpression {
public:
	AbstractExpression(const AbstractExpression& base) = default;
public:
	AbstractExpression(ThreadContext* ctx) throw()  : IObject(ctx), IExpression(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~AbstractExpression() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	constexpr static const int SHIFT_LEFT{1};
	constexpr static const int SHIFT_RIGHT{2};
	constexpr static const int SHIFT_RIGHT_UNSIGNED{3};
	constexpr static const int PLUS{4};
	constexpr static const int MINUS{5};
	constexpr static const int MUL{6};
	constexpr static const int DIV{7};
	constexpr static const int MOD{8};
public:
	int getLine(ThreadContext* ctx) throw()  final;
	int getStartPosition(ThreadContext* ctx) throw()  final;
	int getEndLine(ThreadContext* ctx) throw()  final;
	int getEndPosition(ThreadContext* ctx) throw()  final;
	AbstractSrcElement* getParent(ThreadContext* ctx) throw()  final;
	void setParent(AbstractSrcElement* parent, ThreadContext* ctx) throw()  final;
	virtual bool isSQLExp(ThreadContext* ctx) throw() ;
public:
	static int operatorFromString(String* opStr, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_COMPILE_EXPRESSION_ABSTRACTEXPRESSION_H_ */
