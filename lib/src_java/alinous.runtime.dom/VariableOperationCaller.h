#ifndef ALINOUS_RUNTIME_DOM_VARIABLEOPERATIONCALLER_H_
#define ALINOUS_RUNTIME_DOM_VARIABLEOPERATIONCALLER_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace runtime {namespace dom {
class IVariableClassOperationCaller;}}}

namespace alinous {namespace runtime {namespace dom {
class IAlinousVariable;}}}

namespace alinous {namespace runtime {namespace variant {
class VariantValue;}}}

namespace alinous {namespace runtime {namespace dom {
class DomVariable;}}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace alinous {namespace runtime {namespace dom {namespace typed {
class ITypedVariable;}}}}

namespace alinous {namespace runtime {namespace dom {namespace typed {
class AbstractTypedVariable;}}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace runtime {namespace dom {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::runtime::dom::typed::AbstractTypedVariable;
using ::alinous::runtime::dom::typed::ITypedVariable;
using ::alinous::runtime::variant::VariantValue;
using ::alinous::system::AlinousException;



class VariableOperationCaller final : public virtual IObject {
public:
	class VariantCaller;
	class DomCaller;
	class ObjectCaller;
	class TypedVariableCaller;
	VariableOperationCaller(const VariableOperationCaller& base) = default;
public:
	VariableOperationCaller(ThreadContext* ctx) throw()  : IObject(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~VariableOperationCaller() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	static IArrayObject<IVariableClassOperationCaller>* callers;
public:
	static IArrayObject<IVariableClassOperationCaller>* createCallers(ThreadContext* ctx) throw() ;
	static IAlinousVariable* add(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx);
	static IAlinousVariable* minus(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx);
	static IAlinousVariable* multiply(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx);
	static IAlinousVariable* div(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx);
	static IAlinousVariable* shiftLeft(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx);
	static IAlinousVariable* shiftRight(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx);
	static IAlinousVariable* shiftRightUnsigned(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx);
	static IAlinousVariable* modulo(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx);
	static IAlinousVariable* substitute(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx);
	static int compareTo(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx);
	static IAlinousVariable* bitOr(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx);
	static IAlinousVariable* bitAnd(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx);
	static IAlinousVariable* bitExor(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx);
public:



	class VariantCaller final : public IVariableClassOperationCaller, public virtual IObject {
	public:
		VariantCaller(const VariantCaller& base) = default;
	public:
		VariantCaller(ThreadContext* ctx) throw()  : IObject(ctx), IVariableClassOperationCaller(ctx)
		{
		}
		void __construct_impl(ThreadContext* ctx) throw() 
		{
		}
		virtual ~VariantCaller() throw();
		virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
	public:
		IAlinousVariable* add(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* minus(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* multiply(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* div(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* shiftLeft(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* shiftRight(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* modulo(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* substitute(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		int compareTo(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* bitOr(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* bitAnd(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* bitExor(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* shiftRightUnsigned(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
	public:
		static bool __init_done;
		static bool __init_static_variables();
	public:
		static void __cleanUp(ThreadContext* ctx){
		}
	};




	class DomCaller final : public IVariableClassOperationCaller, public virtual IObject {
	public:
		DomCaller(const DomCaller& base) = default;
	public:
		DomCaller(ThreadContext* ctx) throw()  : IObject(ctx), IVariableClassOperationCaller(ctx)
		{
		}
		void __construct_impl(ThreadContext* ctx) throw() 
		{
		}
		virtual ~DomCaller() throw();
		virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
	public:
		IAlinousVariable* add(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* minus(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* multiply(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* div(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* shiftLeft(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* shiftRight(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* modulo(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* substitute(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		int compareTo(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* bitOr(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* bitAnd(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* bitExor(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* shiftRightUnsigned(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
	public:
		static bool __init_done;
		static bool __init_static_variables();
	public:
		static void __cleanUp(ThreadContext* ctx){
		}
	};




	class ObjectCaller final : public IVariableClassOperationCaller, public virtual IObject {
	public:
		ObjectCaller(const ObjectCaller& base) = default;
	public:
		ObjectCaller(ThreadContext* ctx) throw()  : IObject(ctx), IVariableClassOperationCaller(ctx)
		{
		}
		void __construct_impl(ThreadContext* ctx) throw() 
		{
		}
		virtual ~ObjectCaller() throw();
		virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
	public:
		IAlinousVariable* add(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* minus(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* multiply(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* div(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* shiftLeft(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* shiftRight(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* modulo(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* substitute(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		int compareTo(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* bitOr(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* bitAnd(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* bitExor(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* shiftRightUnsigned(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
	public:
		static bool __init_done;
		static bool __init_static_variables();
	public:
		static void __cleanUp(ThreadContext* ctx){
		}
	};




	class TypedVariableCaller final : public IVariableClassOperationCaller, public virtual IObject {
	public:
		TypedVariableCaller(const TypedVariableCaller& base) = default;
	public:
		TypedVariableCaller(ThreadContext* ctx) throw()  : IObject(ctx), IVariableClassOperationCaller(ctx)
		{
		}
		void __construct_impl(ThreadContext* ctx) throw() 
		{
		}
		virtual ~TypedVariableCaller() throw();
		virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
	public:
		IAlinousVariable* add(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* minus(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* multiply(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* div(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* shiftLeft(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* shiftRight(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* modulo(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* substitute(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		int compareTo(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* bitOr(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* bitAnd(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* bitExor(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
		IAlinousVariable* shiftRightUnsigned(IAlinousVariable* variable, IAlinousVariable* operand, ThreadContext* ctx) final;
	public:
		static bool __init_done;
		static bool __init_static_variables();
	public:
		static void __cleanUp(ThreadContext* ctx){
		}
	};

	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
		GCUtils<IArrayObject<IVariableClassOperationCaller>>::dec(nullptr, VariableOperationCaller::callers, ctx, __FILEW__, __LINE__, L"IArrayObject<IVariableClassOperationCaller>");
	}
};

}}}

#endif /* end of ALINOUS_RUNTIME_DOM_VARIABLEOPERATIONCALLER_H_ */
