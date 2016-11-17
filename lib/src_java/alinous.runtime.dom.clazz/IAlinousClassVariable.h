#ifndef ALINOUS_RUNTIME_DOM_CLAZZ_IALINOUSCLASSVARIABLE_H_
#define ALINOUS_RUNTIME_DOM_CLAZZ_IALINOUSCLASSVARIABLE_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace runtime {namespace dom {namespace typed {
class ITypedVariable;}}}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace runtime {namespace dom {namespace clazz {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::runtime::dom::typed::ITypedVariable;



class IAlinousClassVariable : public virtual IObject, public ITypedVariable {
public:
	IAlinousClassVariable(const IAlinousClassVariable& base) = default;
public:
	IAlinousClassVariable(ThreadContext* ctx) throw()  : IObject(ctx), ITypedVariable(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~IAlinousClassVariable() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_RUNTIME_DOM_CLAZZ_IALINOUSCLASSVARIABLE_H_ */
