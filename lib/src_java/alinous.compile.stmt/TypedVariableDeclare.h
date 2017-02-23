#ifndef ALINOUS_COMPILE_STMT_TYPEDVARIABLEDECLARE_H_
#define ALINOUS_COMPILE_STMT_TYPEDVARIABLEDECLARE_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {namespace declare {
class AlinousName;}}}

namespace alinous {namespace compile {namespace analyse {
class SourceValidator;}}}

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

namespace alinous {namespace compile {namespace declare {
class AlinousClass;}}}

namespace alinous {namespace compile {namespace analyse {
class AlinousType;}}}

namespace alinous {namespace compile {namespace expression {
class IExpression;}}}

namespace alinous {namespace remote {namespace socket {
class NetworkBinaryBuffer;}}}

namespace alinous {namespace compile {
class IAlinousElement;}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace alinous {namespace compile {namespace stmt {
class AbstractAlinousStatement;}}}

namespace alinous {namespace compile {
class AlinousElementNetworkFactory;}}

namespace alinous {namespace remote {namespace socket {
class ICommandData;}}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace compile {namespace stmt {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::compile::AbstractSrcElement;
using ::alinous::compile::AlinousElementNetworkFactory;
using ::alinous::compile::IAlinousElement;
using ::alinous::compile::IAlinousElementVisitor;
using ::alinous::compile::analyse::AlinousType;
using ::alinous::compile::analyse::SourceValidator;
using ::alinous::compile::analyse::SrcAnalyseContext;
using ::alinous::compile::analyse::SubVariableDeclareHolder;
using ::alinous::compile::analyse::VariableDeclareHolder;
using ::alinous::compile::declare::AlinousClass;
using ::alinous::compile::declare::AlinousName;
using ::alinous::compile::expression::IExpression;
using ::alinous::remote::socket::ICommandData;
using ::alinous::remote::socket::NetworkBinaryBuffer;
using ::alinous::runtime::dom::VariableException;

class __TypedVariableDeclare__VariableType : public EnumBase {
public:
	__TypedVariableDeclare__VariableType() = default;
	constexpr __TypedVariableDeclare__VariableType(const EnumBase& base) : EnumBase(base) {}
	constexpr explicit __TypedVariableDeclare__VariableType(const int ord) : EnumBase(ord) {}

	static constexpr EnumBase __DEFAULT_NULL{0};
	static constexpr EnumBase  BOOL_TYPE{1};
	static constexpr EnumBase  BYTE_TYPE{2};
	static constexpr EnumBase  SHORT_TYPE{3};
	static constexpr EnumBase  CHAR_TYPE{4};
	static constexpr EnumBase  INT_TYPE{5};
	static constexpr EnumBase  LONG_TYPE{6};
	static constexpr EnumBase  FLOAT_TYPE{7};
	static constexpr EnumBase  DOUBLE_TYPE{8};
	static constexpr EnumBase  STRING_TYPE{9};
	static constexpr EnumBase  TIMESTAMP{10};
	static constexpr EnumBase  TIME{11};
	static constexpr EnumBase  BIGDECIMAL{12};
	static constexpr EnumBase  OBJECT_TYPE{13};
};


class TypedVariableDeclare final : public AbstractAlinousStatement {
public:
	class VariableType : public __TypedVariableDeclare__VariableType {
	public:
		VariableType() = default;constexpr VariableType(const EnumBase& base) :  __TypedVariableDeclare__VariableType(base) {};
	};
public:
	TypedVariableDeclare(const TypedVariableDeclare& base) = default;
public:
	TypedVariableDeclare(ThreadContext* ctx) throw()  : IObject(ctx), AbstractAlinousStatement(ctx), typeName(nullptr), name(nullptr), dimension(0), initExp(nullptr), analysedType(nullptr)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~TypedVariableDeclare() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	AlinousName* typeName;
	AlinousName* name;
	int dimension;
	IExpression* initExp;
	TypedVariableDeclare::VariableType typeEnum;
	AlinousType* analysedType;
public:
	void setTypeName(AlinousName* typeName, ThreadContext* ctx) throw() ;
	void setName(AlinousName* name, ThreadContext* ctx) throw() ;
	IStatement::StatementType getType(ThreadContext* ctx) throw()  final;
	void validate(SourceValidator* validator, ThreadContext* ctx) throw()  final;
	bool visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw()  final;
	bool analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw()  final;
	AlinousName* getTypeName(ThreadContext* ctx) throw() ;
	AlinousName* getName(ThreadContext* ctx) throw() ;
	TypedVariableDeclare::VariableType getTypeEnum(ThreadContext* ctx) throw() ;
	IExpression* getInitExp(ThreadContext* ctx) throw() ;
	void setInitExp(IExpression* initExp, ThreadContext* ctx) throw() ;
	AlinousType* getAnalysedType(ThreadContext* ctx) throw() ;
	int getDimension(ThreadContext* ctx) throw() ;
	void setDimension(int dimension, ThreadContext* ctx) throw() ;
	void readData(NetworkBinaryBuffer* buff, ThreadContext* ctx) final;
	void writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) final;
private:
	int enum2Int(ThreadContext* ctx) throw() ;
	void int2enum(int num, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_COMPILE_STMT_TYPEDVARIABLEDECLARE_H_ */
