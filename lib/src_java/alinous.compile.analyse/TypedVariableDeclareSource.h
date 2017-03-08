#ifndef ALINOUS_COMPILE_ANALYSE_TYPEDVARIABLEDECLARESOURCE_H_
#define ALINOUS_COMPILE_ANALYSE_TYPEDVARIABLEDECLARESOURCE_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {namespace declare {namespace function {
class FunctionArgumentDefine;}}}}

namespace alinous {namespace compile {namespace stmt {
class TypedVariableDeclare;}}}

namespace alinous {namespace compile {namespace declare {
class AlinousName;}}}

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
using ::alinous::compile::declare::AlinousName;
using ::alinous::compile::declare::function::FunctionArgumentDefine;
using ::alinous::compile::stmt::TypedVariableDeclare;



class TypedVariableDeclareSource final : public virtual IObject {
public:
	TypedVariableDeclareSource(const TypedVariableDeclareSource& base) = default;
public:
	TypedVariableDeclareSource(FunctionArgumentDefine* argumentDefine, ThreadContext* ctx) throw() ;
	void __construct_impl(FunctionArgumentDefine* argumentDefine, ThreadContext* ctx) throw() ;
	TypedVariableDeclareSource(TypedVariableDeclare* typedVariableDeclare, ThreadContext* ctx) throw() ;
	void __construct_impl(TypedVariableDeclare* typedVariableDeclare, ThreadContext* ctx) throw() ;
	virtual ~TypedVariableDeclareSource() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	FunctionArgumentDefine* argumentDefine;
	TypedVariableDeclare* typedVariableDeclare;
	int variableType;
public:
	constexpr static const int DOM_VARIABLE{1};
	constexpr static const int DOM_ARRAY_VARIABLE{2};
	constexpr static const int BOOL_TYPE{3};
	constexpr static const int BYTE_TYPE{4};
	constexpr static const int SHORT_TYPE{5};
	constexpr static const int CHAR_TYPE{6};
	constexpr static const int INT_TYPE{7};
	constexpr static const int LONG_TYPE{8};
	constexpr static const int FLOAT_TYPE{9};
	constexpr static const int DOUBLE_TYPE{10};
	constexpr static const int STRING_TYPE{11};
	constexpr static const int TIMESTAMP{12};
	constexpr static const int TIME{13};
	constexpr static const int BIGDECIMAL{14};
	constexpr static const int OBJECT_TYPE{15};
public:
	int getVariableType(ThreadContext* ctx) throw() ;
	String* getSearchId(ThreadContext* ctx) throw() ;
	TypedVariableDeclare* getTypedVariableDeclare(ThreadContext* ctx) throw() ;
	FunctionArgumentDefine* getArgumentDefine(ThreadContext* ctx) throw() ;
private:
	void argumentsTypedVriable(ThreadContext* ctx) throw() ;
	void initTypedVriable(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_COMPILE_ANALYSE_TYPEDVARIABLEDECLARESOURCE_H_ */
