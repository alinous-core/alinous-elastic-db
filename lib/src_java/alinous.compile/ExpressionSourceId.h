#ifndef ALINOUS_COMPILE_EXPRESSIONSOURCEID_H_
#define ALINOUS_COMPILE_EXPRESSIONSOURCEID_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {namespace expression {
class IExpression;}}}

namespace alinous {namespace compile {namespace analyse {
class AlinousType;}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace compile {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::compile::analyse::AlinousType;
using ::alinous::compile::expression::IExpression;



class ExpressionSourceId final : public virtual IObject {
public:
	ExpressionSourceId(const ExpressionSourceId& base) = default;
public:
	ExpressionSourceId(String* id, IExpression* exp, AlinousType* alinousType, ThreadContext* ctx) throw() ;
	void __construct_impl(String* id, IExpression* exp, AlinousType* alinousType, ThreadContext* ctx) throw() ;
	virtual ~ExpressionSourceId() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	String* id;
	IExpression* exp;
	AlinousType* type;
public:
	String* getId(ThreadContext* ctx) throw() ;
	void setId(String* id, ThreadContext* ctx) throw() ;
	String* toString(ThreadContext* ctx) throw() ;
	IExpression* getExp(ThreadContext* ctx) throw() ;
	AlinousType* getType(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}

#endif /* end of ALINOUS_COMPILE_EXPRESSIONSOURCEID_H_ */
