#ifndef ALINOUS_COMPILE_EXPRESSION_LITERAL_H_
#define ALINOUS_COMPILE_EXPRESSION_LITERAL_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {
class IAlinousElementVisitor;}}

namespace alinous {namespace compile {
class AbstractSrcElement;}}

namespace alinous {namespace compile {namespace analyse {
class SrcAnalyseContext;}}}

namespace alinous {namespace compile {namespace expression {
class Literal;}}}

namespace alinous {namespace runtime {namespace dom {
class IAlinousVariable;}}}

namespace alinous {namespace runtime {namespace engine {
class ScriptMachine;}}}

namespace alinous {namespace runtime {namespace variant {
class VariantValue;}}}

namespace alinous {namespace compile {
class ExpressionSourceId;}}

namespace alinous {namespace compile {namespace analyse {
class AlinousType;}}}

namespace alinous {namespace remote {namespace socket {
class NetworkBinaryBuffer;}}}

namespace alinous {namespace compile {namespace expression {
class AbstractExpression;}}}

namespace alinous {namespace remote {namespace socket {
class ICommandData;}}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace compile {namespace expression {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::compile::AbstractSrcElement;
using ::alinous::compile::ExpressionSourceId;
using ::alinous::compile::IAlinousElementVisitor;
using ::alinous::compile::analyse::AlinousType;
using ::alinous::compile::analyse::SrcAnalyseContext;
using ::alinous::remote::socket::ICommandData;
using ::alinous::remote::socket::NetworkBinaryBuffer;
using ::alinous::runtime::dom::IAlinousVariable;
using ::alinous::runtime::dom::VariableException;
using ::alinous::runtime::engine::ScriptMachine;
using ::alinous::runtime::variant::VariantValue;
using ::alinous::system::AlinousException;

class __Literal__literalTypes : public EnumBase {
public:
	__Literal__literalTypes() = default;
	constexpr __Literal__literalTypes(const EnumBase& base) : EnumBase(base) {}
	constexpr explicit __Literal__literalTypes(const int ord) : EnumBase(ord) {}

	static constexpr EnumBase __DEFAULT_NULL{0};
	static constexpr EnumBase  INTEGER_LITERAL{1};
	static constexpr EnumBase  FLOATING_POINT_LITERAL{2};
	static constexpr EnumBase  CHARACTER_LITERAL{3};
	static constexpr EnumBase  STRING_LITERAL{4};
	static constexpr EnumBase  SQL_STRING_LITERAL{5};
	static constexpr EnumBase  BOOLEAN{6};
	static constexpr EnumBase  NULL_LITERAL{7};
};


class Literal : public AbstractExpression {
public:
	class literalTypes : public __Literal__literalTypes {
	public:
		literalTypes() = default;constexpr literalTypes(const EnumBase& base) :  __Literal__literalTypes(base) {};
	};
public:
	Literal(const Literal& base) = default;
public:
	Literal(Literal::literalTypes type, ThreadContext* ctx) throw() ;
	void __construct_impl(Literal::literalTypes type, ThreadContext* ctx) throw() ;
	Literal(ThreadContext* ctx) throw()  : IObject(ctx), AbstractExpression(ctx), value(nullptr)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~Literal() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	Literal::literalTypes litType;
private:
	String* value;
public:
	bool visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw()  final;
	bool isConstant(ThreadContext* ctx) throw()  final;
	bool analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw()  final;
	String* getValue(ThreadContext* ctx) throw() ;
	void setValue(String* value, ThreadContext* ctx) throw() ;
	Literal::literalTypes getLitType(ThreadContext* ctx) throw() ;
	IAlinousVariable* resolveExpression(ScriptMachine* machine, bool debug, ThreadContext* ctx) final;
	ExpressionSourceId* getSourceId(ThreadContext* ctx) throw()  final;
	bool isSQLExp(ThreadContext* ctx) throw()  final;
	virtual int getExpressionType(ThreadContext* ctx) throw() ;
	void readData(NetworkBinaryBuffer* buff, ThreadContext* ctx) final;
	void writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw()  final;
private:
	int fromEnum(ThreadContext* ctx) throw() ;
	void toEnum(int num, ThreadContext* ctx) throw() ;
public:
	static Literal* intLiteral(int value, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_COMPILE_EXPRESSION_LITERAL_H_ */
