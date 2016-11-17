#ifndef ALINOUS_COMPILE_DECLARE_FUNCTION_FUNCTIONARGUMENTSLISTDEFINE_H_
#define ALINOUS_COMPILE_DECLARE_FUNCTION_FUNCTIONARGUMENTSLISTDEFINE_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {
class IAlinousElementVisitor;}}

namespace alinous {namespace compile {
class AbstractSrcElement;}}

namespace alinous {namespace compile {namespace declare {namespace function {
class FunctionArgumentsListDefine;}}}}

namespace alinous {namespace compile {namespace declare {namespace function {
class FunctionArgumentDefine;}}}}

namespace alinous {namespace compile {namespace analyse {
class SrcAnalyseContext;}}}

namespace java {namespace lang {
class StringBuffer;}}

namespace alinous {namespace compile {namespace declare {
class IDeclare;}}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace compile {namespace declare {namespace function {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::ArrayList;
using ::alinous::compile::AbstractSrcElement;
using ::alinous::compile::IAlinousElementVisitor;
using ::alinous::compile::analyse::SrcAnalyseContext;
using ::alinous::compile::declare::IDeclare;



class FunctionArgumentsListDefine final : public IDeclare {
public:
	FunctionArgumentsListDefine(const FunctionArgumentsListDefine& base) = default;
public:
	FunctionArgumentsListDefine(ThreadContext* ctx) throw()  : IObject(ctx), IDeclare(ctx), list(GCUtils<ArrayList<FunctionArgumentDefine> >::ins(this, (new(ctx) ArrayList<FunctionArgumentDefine>(ctx)), ctx, __FILEW__, __LINE__, L""))
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~FunctionArgumentsListDefine() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	ArrayList<FunctionArgumentDefine>* list;
public:
	bool visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw()  final;
	bool same(FunctionArgumentsListDefine* other, ThreadContext* ctx) throw() ;
	bool analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw()  final;
	String* toString(ThreadContext* ctx) throw() ;
	void addArgument(FunctionArgumentDefine* arg, ThreadContext* ctx) throw() ;
	ArrayList<FunctionArgumentDefine>* getList(ThreadContext* ctx) throw() ;
	int getLine(ThreadContext* ctx) throw()  final;
	int getStartPosition(ThreadContext* ctx) throw()  final;
	int getEndLine(ThreadContext* ctx) throw()  final;
	int getEndPosition(ThreadContext* ctx) throw()  final;
	AbstractSrcElement* getParent(ThreadContext* ctx) throw()  final;
	void setParent(AbstractSrcElement* parent, ThreadContext* ctx) throw()  final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_COMPILE_DECLARE_FUNCTION_FUNCTIONARGUMENTSLISTDEFINE_H_ */
