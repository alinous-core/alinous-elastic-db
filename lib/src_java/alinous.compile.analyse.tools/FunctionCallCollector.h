#ifndef ALINOUS_COMPILE_ANALYSE_TOOLS_FUNCTIONCALLCOLLECTOR_H_
#define ALINOUS_COMPILE_ANALYSE_TOOLS_FUNCTIONCALLCOLLECTOR_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {
class AbstractSrcElement;}}

namespace alinous {namespace compile {namespace expression {namespace expstream {
class FunctionCallExpression;}}}}

namespace alinous {namespace compile {
class IAlinousElementVisitor;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace compile {namespace analyse {namespace tools {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::ArrayList;
using ::alinous::compile::AbstractSrcElement;
using ::alinous::compile::IAlinousElementVisitor;
using ::alinous::compile::expression::expstream::FunctionCallExpression;



class FunctionCallCollector final : public IAlinousElementVisitor, public virtual IObject {
public:
	FunctionCallCollector(const FunctionCallCollector& base) = default;
public:
	FunctionCallCollector(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~FunctionCallCollector() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	ArrayList<FunctionCallExpression>* list;
public:
	bool visit(AbstractSrcElement* element, AbstractSrcElement* parent, ThreadContext* ctx) throw()  final;
	ArrayList<FunctionCallExpression>* getList(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}

#endif /* end of ALINOUS_COMPILE_ANALYSE_TOOLS_FUNCTIONCALLCOLLECTOR_H_ */
