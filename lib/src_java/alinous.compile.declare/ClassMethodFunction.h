#ifndef ALINOUS_COMPILE_DECLARE_CLASSMETHODFUNCTION_H_
#define ALINOUS_COMPILE_DECLARE_CLASSMETHODFUNCTION_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {namespace declare {
class ClassMethodFunction;}}}

namespace alinous {namespace compile {
class IAlinousElementVisitor;}}

namespace alinous {namespace compile {
class AbstractSrcElement;}}

namespace alinous {namespace compile {namespace declare {namespace function {
class FunctionArgumentsListDefine;}}}}

namespace alinous {namespace compile {namespace declare {namespace function {
class FunctionArgumentDefine;}}}}

namespace alinous {namespace compile {namespace declare {namespace function {
class AlinousFunction;}}}}

namespace alinous {namespace compile {namespace analyse {
class SrcAnalyseContext;}}}

namespace alinous {namespace compile {namespace expression {namespace expstream {
class FunctionCallExpression;}}}}

namespace alinous {namespace compile {namespace declare {
class AlinousClass;}}}

namespace alinous {namespace compile {namespace expression {
class FunctionArguments;}}}

namespace java {namespace lang {
class StringBuffer;}}

namespace alinous {namespace compile {namespace declare {
class VirtualTable;}}}

namespace alinous {namespace compile {namespace declare {
class AbstractClassMember;}}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace compile {namespace declare {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::ArrayList;
using ::alinous::compile::AbstractSrcElement;
using ::alinous::compile::IAlinousElementVisitor;
using ::alinous::compile::analyse::SrcAnalyseContext;
using ::alinous::compile::declare::function::AlinousFunction;
using ::alinous::compile::declare::function::FunctionArgumentDefine;
using ::alinous::compile::declare::function::FunctionArgumentsListDefine;
using ::alinous::compile::expression::FunctionArguments;
using ::alinous::compile::expression::expstream::FunctionCallExpression;



class ClassMethodFunction final : public AbstractClassMember {
public:
	ClassMethodFunction(const ClassMethodFunction& base) = default;
public:
	ClassMethodFunction(ThreadContext* ctx) throw()  : IObject(ctx), AbstractClassMember(ctx), func(nullptr), constructorMethod(0), virtualMethod(0), vtable(nullptr), superConstructor(nullptr)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~ClassMethodFunction() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	AlinousFunction* func;
	bool constructorMethod;
	bool virtualMethod;
	VirtualTable* vtable;
	ClassMethodFunction* superConstructor;
public:
	bool sameSig(ClassMethodFunction* other, ThreadContext* ctx) throw() ;
	bool visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw()  final;
	int getMemberType(ThreadContext* ctx) throw()  final;
	int getArgumentsSize(ThreadContext* ctx) throw() ;
	ArrayList<FunctionArgumentDefine>* getArgumentsDefine(ThreadContext* ctx) throw() ;
	AlinousFunction* getFunc(ThreadContext* ctx) throw() ;
	void setFunc(AlinousFunction* func, ThreadContext* ctx) throw() ;
	bool analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw()  final;
	ClassMethodFunction* getConstructorCall(ThreadContext* ctx) throw() ;
	String* toString(ThreadContext* ctx) throw() ;
	AlinousClass* getAlinousClass(ThreadContext* ctx) throw()  final;
	bool isConstructorMethod(ThreadContext* ctx) throw() ;
	void setConstructorMethod(bool constructorMethod, ThreadContext* ctx) throw() ;
	ClassMethodFunction* getSuperConstructor(ThreadContext* ctx) throw() ;
	bool isVirtualMethod(ThreadContext* ctx) throw() ;
	void setVirtualMethod(bool virtualMethod, ThreadContext* ctx) throw() ;
	ClassMethodFunction* resolveVirtual(AlinousClass* clazz, ThreadContext* ctx) throw() ;
	VirtualTable* getVtable(ThreadContext* ctx) throw() ;
	void setVtable(VirtualTable* vtable, ThreadContext* ctx) throw() ;
private:
	bool analyseConstructorMethod(SrcAnalyseContext* context, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_COMPILE_DECLARE_CLASSMETHODFUNCTION_H_ */
