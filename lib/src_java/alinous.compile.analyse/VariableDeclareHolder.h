#ifndef ALINOUS_COMPILE_ANALYSE_VARIABLEDECLAREHOLDER_H_
#define ALINOUS_COMPILE_ANALYSE_VARIABLEDECLAREHOLDER_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace java {namespace util {
template <typename  T, typename V> class HashMap;}}

namespace alinous {namespace compile {namespace analyse {
class DomVariableDeclareSource;}}}

namespace alinous {namespace compile {namespace analyse {
class SubVariableDeclareHolder;}}}

namespace alinous {namespace compile {namespace declare {namespace function {
class FunctionArgumentDefine;}}}}

namespace alinous {namespace compile {namespace stmt {
class TypedVariableDeclare;}}}

namespace alinous {namespace compile {namespace analyse {
class TypedVariableDeclareSource;}}}

namespace java {namespace util {
template <typename  T> class Stack;}}

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
using ::java::util::Stack;
using ::alinous::compile::declare::function::FunctionArgumentDefine;
using ::alinous::compile::stmt::TypedVariableDeclare;



class VariableDeclareHolder final : public virtual IObject {
public:
	VariableDeclareHolder(const VariableDeclareHolder& base) = default;
public:
	VariableDeclareHolder(ThreadContext* ctx) throw()  : IObject(ctx), variableDeclares(GCUtils<Stack<SubVariableDeclareHolder> >::ins(this, (new(ctx) Stack<SubVariableDeclareHolder>(ctx)), ctx, __FILEW__, __LINE__, L"")), domDeclare(GCUtils<HashMap<String,DomVariableDeclareSource> >::ins(this, (new(ctx) HashMap<String,DomVariableDeclareSource>(ctx)), ctx, __FILEW__, __LINE__, L""))
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~VariableDeclareHolder() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	Stack<SubVariableDeclareHolder>* variableDeclares;
	HashMap<String,DomVariableDeclareSource>* domDeclare;
public:
	HashMap<String,DomVariableDeclareSource>* getDomDeclare(ThreadContext* ctx) throw() ;
	void newSubStack(ThreadContext* ctx) throw() ;
	void endSubStack(ThreadContext* ctx) throw() ;
	SubVariableDeclareHolder* getCurrentSubStack(ThreadContext* ctx) throw() ;
	void addTypeVariableDeclare(FunctionArgumentDefine* argumentDefine, ThreadContext* ctx) throw() ;
	void addTypeVariableDeclare(TypedVariableDeclare* typedVariableDeclare, ThreadContext* ctx) throw() ;
	TypedVariableDeclareSource* getTypedVariableDeclare(String* name, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_COMPILE_ANALYSE_VARIABLEDECLAREHOLDER_H_ */
