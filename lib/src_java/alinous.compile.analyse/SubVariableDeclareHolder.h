#ifndef ALINOUS_COMPILE_ANALYSE_SUBVARIABLEDECLAREHOLDER_H_
#define ALINOUS_COMPILE_ANALYSE_SUBVARIABLEDECLAREHOLDER_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace java {namespace util {
template <typename  T, typename V> class HashMap;}}

namespace alinous {namespace compile {namespace analyse {
class TypedVariableDeclareSource;}}}

namespace alinous {namespace compile {namespace stmt {
class TypedVariableDeclare;}}}

namespace alinous {namespace compile {namespace declare {namespace function {
class FunctionArgumentDefine;}}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace compile {namespace analyse {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::HashMap;
using ::alinous::compile::declare::function::FunctionArgumentDefine;
using ::alinous::compile::stmt::TypedVariableDeclare;



class SubVariableDeclareHolder final : public virtual IObject {
public:
	SubVariableDeclareHolder(const SubVariableDeclareHolder& base) = default;
public:
	SubVariableDeclareHolder(ThreadContext* ctx) throw()  : IObject(ctx), typedVariableDeclare(GCUtils<HashMap<String,TypedVariableDeclareSource> >::ins(this, (new(ctx) HashMap<String,TypedVariableDeclareSource>(ctx)), ctx, __FILEW__, __LINE__, L""))
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~SubVariableDeclareHolder() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	HashMap<String,TypedVariableDeclareSource>* typedVariableDeclare;
public:
	HashMap<String,TypedVariableDeclareSource>* getTypedVariableDeclare(ThreadContext* ctx) throw() ;
	void addTypedVariableDeclare(TypedVariableDeclare* typedVariableDeclare, ThreadContext* ctx) throw() ;
	void addFunctionArgumentDefine(FunctionArgumentDefine* argumentDefine, ThreadContext* ctx) throw() ;
	TypedVariableDeclareSource* getTypedVariableDeclareSource(String* name, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_COMPILE_ANALYSE_SUBVARIABLEDECLAREHOLDER_H_ */
