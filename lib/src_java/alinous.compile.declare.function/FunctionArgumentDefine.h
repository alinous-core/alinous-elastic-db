#ifndef ALINOUS_COMPILE_DECLARE_FUNCTION_FUNCTIONARGUMENTDEFINE_H_
#define ALINOUS_COMPILE_DECLARE_FUNCTION_FUNCTIONARGUMENTDEFINE_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {namespace declare {namespace function {
class FunctionArgumentDefine;}}}}

namespace alinous {namespace runtime {namespace engine {
class ScriptMachine;}}}

namespace alinous {namespace runtime {namespace engine {
class MainStackFrame;}}}

namespace alinous {namespace runtime {namespace dom {
class IAlinousVariable;}}}

namespace alinous {namespace runtime {namespace dom {
class IDomVariable;}}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace alinous {namespace runtime {namespace dom {namespace clazz {
class IAlinousClassVariable;}}}}

namespace alinous {namespace runtime {namespace dom {namespace typed {
class ITypedVariable;}}}}

namespace alinous {namespace compile {
class IAlinousElementVisitor;}}

namespace alinous {namespace compile {
class AbstractSrcElement;}}

namespace alinous {namespace compile {namespace analyse {
class SrcAnalyseContext;}}}

namespace alinous {namespace compile {namespace analyse {
class VariableDeclareHolder;}}}

namespace alinous {namespace compile {namespace analyse {
class SubVariableDeclareHolder;}}}

namespace alinous {namespace compile {namespace analyse {
class AlinousType;}}}

namespace java {namespace lang {
class StringBuffer;}}

namespace alinous {namespace compile {namespace declare {
class AlinousName;}}}

namespace alinous {namespace compile {namespace expression {
class DomVariableDescriptor;}}}

namespace alinous {namespace remote {namespace socket {
class NetworkBinaryBuffer;}}}

namespace alinous {namespace compile {
class IAlinousElement;}}

namespace alinous {namespace compile {namespace declare {
class IDeclare;}}}

namespace alinous {namespace compile {
class AlinousElementNetworkFactory;}}

namespace alinous {namespace db {namespace table {
class DatabaseException;}}}

namespace alinous {namespace remote {namespace socket {
class ICommandData;}}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace compile {namespace declare {namespace function {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::compile::AbstractSrcElement;
using ::alinous::compile::AlinousElementNetworkFactory;
using ::alinous::compile::IAlinousElement;
using ::alinous::compile::IAlinousElementVisitor;
using ::alinous::compile::analyse::AlinousType;
using ::alinous::compile::analyse::SrcAnalyseContext;
using ::alinous::compile::analyse::SubVariableDeclareHolder;
using ::alinous::compile::analyse::VariableDeclareHolder;
using ::alinous::compile::declare::AlinousName;
using ::alinous::compile::declare::IDeclare;
using ::alinous::compile::expression::DomVariableDescriptor;
using ::alinous::db::table::DatabaseException;
using ::alinous::remote::socket::ICommandData;
using ::alinous::remote::socket::NetworkBinaryBuffer;
using ::alinous::runtime::dom::IAlinousVariable;
using ::alinous::runtime::dom::IDomVariable;
using ::alinous::runtime::dom::VariableException;
using ::alinous::runtime::dom::clazz::IAlinousClassVariable;
using ::alinous::runtime::dom::typed::ITypedVariable;
using ::alinous::runtime::engine::MainStackFrame;
using ::alinous::runtime::engine::ScriptMachine;
using ::alinous::system::AlinousException;

class __FunctionArgumentDefine__FunctionArgumentType : public EnumBase {
public:
	__FunctionArgumentDefine__FunctionArgumentType() = default;
	constexpr __FunctionArgumentDefine__FunctionArgumentType(const EnumBase& base) : EnumBase(base) {}
	constexpr explicit __FunctionArgumentDefine__FunctionArgumentType(const int ord) : EnumBase(ord) {}

	static constexpr EnumBase __DEFAULT_NULL{0};
	static constexpr EnumBase  DOM_VARIABLE{1};
	static constexpr EnumBase  DOM_ARRAY_VARIABLE{2};
	static constexpr EnumBase  BOOL_TYPE{3};
	static constexpr EnumBase  BYTE_TYPE{4};
	static constexpr EnumBase  SHORT_TYPE{5};
	static constexpr EnumBase  CHAR_TYPE{6};
	static constexpr EnumBase  INT_TYPE{7};
	static constexpr EnumBase  LONG_TYPE{8};
	static constexpr EnumBase  FLOAT_TYPE{9};
	static constexpr EnumBase  DOUBLE_TYPE{10};
	static constexpr EnumBase  STRING_TYPE{11};
	static constexpr EnumBase  TIMESTAMP{12};
	static constexpr EnumBase  TIME{13};
	static constexpr EnumBase  BIGDECIMAL{14};
	static constexpr EnumBase  OBJECT_TYPE{15};
};


class FunctionArgumentDefine final : public IDeclare {
public:
	class FunctionArgumentType : public __FunctionArgumentDefine__FunctionArgumentType {
	public:
		FunctionArgumentType() = default;constexpr FunctionArgumentType(const EnumBase& base) :  __FunctionArgumentDefine__FunctionArgumentType(base) {};
	};
public:
	FunctionArgumentDefine(const FunctionArgumentDefine& base) = default;
public:
	FunctionArgumentDefine(ThreadContext* ctx) throw()  : IObject(ctx), IDeclare(ctx), type(nullptr), name(nullptr), domDescriptor(nullptr), analysedType(nullptr)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~FunctionArgumentDefine() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	AlinousName* type;
	AlinousName* name;
	DomVariableDescriptor* domDescriptor;
	AlinousType* analysedType;
public:
	bool sameMethodSig(FunctionArgumentDefine* other, ThreadContext* ctx) throw() ;
	void putArgument(ScriptMachine* machine, MainStackFrame* frame, IAlinousVariable* variable, bool debug, ThreadContext* ctx);
	FunctionArgumentDefine::FunctionArgumentType getVariableType(ThreadContext* ctx) throw() ;
	bool visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw()  final;
	bool analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw()  final;
	String* toString(ThreadContext* ctx) throw() ;
	AlinousName* getType(ThreadContext* ctx) throw() ;
	void setType(AlinousName* type, ThreadContext* ctx) throw() ;
	AlinousName* getName(ThreadContext* ctx) throw() ;
	void setName(AlinousName* name, ThreadContext* ctx) throw() ;
	DomVariableDescriptor* getDomDescriptor(ThreadContext* ctx) throw() ;
	void setDomDescriptor(DomVariableDescriptor* domDescriptor, ThreadContext* ctx) throw() ;
	AlinousType* getAnalysedType(ThreadContext* ctx) throw() ;
	int getLine(ThreadContext* ctx) throw()  final;
	int getStartPosition(ThreadContext* ctx) throw()  final;
	int getEndLine(ThreadContext* ctx) throw()  final;
	int getEndPosition(ThreadContext* ctx) throw()  final;
	AbstractSrcElement* getParent(ThreadContext* ctx) throw()  final;
	void setParent(AbstractSrcElement* parent, ThreadContext* ctx) throw()  final;
	void readData(NetworkBinaryBuffer* buff, ThreadContext* ctx) final;
	void writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw()  final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_COMPILE_DECLARE_FUNCTION_FUNCTIONARGUMENTDEFINE_H_ */
