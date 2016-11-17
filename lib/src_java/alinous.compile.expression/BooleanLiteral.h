#ifndef ALINOUS_COMPILE_EXPRESSION_BOOLEANLITERAL_H_
#define ALINOUS_COMPILE_EXPRESSION_BOOLEANLITERAL_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {namespace expression {
class Literal;}}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace compile {namespace expression {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;



class BooleanLiteral final : public Literal {
public:
	BooleanLiteral(const BooleanLiteral& base) = default;
public:
	BooleanLiteral(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~BooleanLiteral() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	int getExpressionType(ThreadContext* ctx) throw()  final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_COMPILE_EXPRESSION_BOOLEANLITERAL_H_ */
