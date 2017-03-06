#ifndef ALINOUS_COMPILE_EXPRESSION_EXPSTREAM_EXPSTREAMSEGMENT_H_
#define ALINOUS_COMPILE_EXPRESSION_EXPSTREAM_EXPSTREAMSEGMENT_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace runtime {namespace dom {
class IAlinousVariable;}}}

namespace alinous {namespace runtime {namespace engine {
class ScriptMachine;}}}

namespace alinous {namespace compile {namespace expression {namespace expstream {
class IdentifierVariable;}}}}

namespace alinous {namespace runtime {namespace dom {
class IDomVariable;}}}

namespace alinous {namespace runtime {namespace dom {namespace clazz {
class AlinousClassVariable;}}}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace alinous {namespace runtime {namespace dom {
class DocumentVariable;}}}

namespace alinous {namespace compile {namespace expression {
class IExpression;}}}

namespace alinous {namespace runtime {namespace dom {namespace typed {
class TypedVariableArray;}}}}

namespace alinous {namespace compile {namespace expression {
class DomVariableDescriptor;}}}

namespace alinous {namespace compile {namespace expression {
class DomNameSegment;}}}

namespace alinous {namespace compile {namespace expression {
class DomIndexSegment;}}}

namespace alinous {namespace runtime {namespace dom {namespace typed {
class ITypedVariable;}}}}

namespace alinous {namespace compile {
class IAlinousElementVisitor;}}

namespace alinous {namespace compile {
class AbstractSrcElement;}}

namespace alinous {namespace compile {namespace analyse {
class SrcAnalyseContext;}}}

namespace alinous {namespace compile {namespace analyse {
class ExpressionStreamResult;}}}

namespace alinous {namespace compile {namespace analyse {
class AlinousType;}}}

namespace alinous {namespace compile {
class ExpressionSourceId;}}

namespace alinous {namespace compile {namespace analyse {
class VariableDeclareHolder;}}}

namespace alinous {namespace compile {namespace declare {
class AlinousClass;}}}

namespace alinous {namespace compile {namespace declare {
class ClassMemberVariable;}}}

namespace alinous {namespace compile {namespace analyse {
class DomVariableDeclareSource;}}}

namespace alinous {namespace compile {namespace analyse {
class TypedVariableDeclareSource;}}}

namespace alinous {namespace compile {namespace declare {
class ClassMethodFunction;}}}

namespace alinous {namespace compile {namespace declare {
class AlinousName;}}}

namespace java {namespace lang {
class StringBuffer;}}

namespace alinous {namespace remote {namespace socket {
class NetworkBinaryBuffer;}}}

namespace alinous {namespace compile {
class IAlinousElement;}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryBuilder;}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryFetcher;}}}

namespace alinous {namespace compile {namespace stmt {
class TypedVariableDeclare;}}}

namespace alinous {namespace compile {namespace declare {namespace function {
class FunctionArgumentDefine;}}}}

namespace alinous {namespace compile {namespace expression {
class AbstractExpression;}}}

namespace alinous {namespace compile {
class AlinousElementNetworkFactory;}}

namespace alinous {namespace compile {namespace expression {
class IExpressionFactory;}}}

namespace alinous {namespace compile {namespace expression {
class Literal;}}}

namespace alinous {namespace db {namespace table {
class DatabaseException;}}}

namespace alinous {namespace remote {namespace socket {
class ICommandData;}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace compile {namespace expression {namespace expstream {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::ArrayList;
using ::alinous::buffer::storage::FileStorageEntryBuilder;
using ::alinous::buffer::storage::FileStorageEntryFetcher;
using ::alinous::compile::AbstractSrcElement;
using ::alinous::compile::AlinousElementNetworkFactory;
using ::alinous::compile::ExpressionSourceId;
using ::alinous::compile::IAlinousElement;
using ::alinous::compile::IAlinousElementVisitor;
using ::alinous::compile::analyse::AlinousType;
using ::alinous::compile::analyse::DomVariableDeclareSource;
using ::alinous::compile::analyse::ExpressionStreamResult;
using ::alinous::compile::analyse::SrcAnalyseContext;
using ::alinous::compile::analyse::TypedVariableDeclareSource;
using ::alinous::compile::analyse::VariableDeclareHolder;
using ::alinous::compile::declare::AlinousClass;
using ::alinous::compile::declare::AlinousName;
using ::alinous::compile::declare::ClassMemberVariable;
using ::alinous::compile::declare::ClassMethodFunction;
using ::alinous::compile::declare::function::FunctionArgumentDefine;
using ::alinous::compile::expression::AbstractExpression;
using ::alinous::compile::expression::DomIndexSegment;
using ::alinous::compile::expression::DomNameSegment;
using ::alinous::compile::expression::DomVariableDescriptor;
using ::alinous::compile::expression::IExpression;
using ::alinous::compile::expression::IExpressionFactory;
using ::alinous::compile::expression::Literal;
using ::alinous::compile::stmt::TypedVariableDeclare;
using ::alinous::db::table::DatabaseException;
using ::alinous::remote::socket::ICommandData;
using ::alinous::remote::socket::NetworkBinaryBuffer;
using ::alinous::runtime::dom::DocumentVariable;
using ::alinous::runtime::dom::IAlinousVariable;
using ::alinous::runtime::dom::IDomVariable;
using ::alinous::runtime::dom::VariableException;
using ::alinous::runtime::dom::clazz::AlinousClassVariable;
using ::alinous::runtime::dom::typed::ITypedVariable;
using ::alinous::runtime::dom::typed::TypedVariableArray;
using ::alinous::runtime::engine::ScriptMachine;
using ::alinous::system::AlinousException;

class __ExpStreamSegment__SegmentType : public EnumBase {
public:
	__ExpStreamSegment__SegmentType() = default;
	constexpr __ExpStreamSegment__SegmentType(const EnumBase& base) : EnumBase(base) {}
	constexpr explicit __ExpStreamSegment__SegmentType(const int ord) : EnumBase(ord) {}

	static constexpr EnumBase __DEFAULT_NULL{0};
	static constexpr EnumBase  SEG_FUNC_PREFIX{1};
	static constexpr EnumBase  SEG_STATIC_CLASS_PREFIX{2};
	static constexpr EnumBase  SEG_DOM_PROPERTY{3};
	static constexpr EnumBase  SEG_VARIABLE{4};
	static constexpr EnumBase  SEG_STATIC_VARIABLE{5};
	static constexpr EnumBase  SEG_MEMBER_VARIABLE{6};
	static constexpr EnumBase  SEG_MEMBER_DOM_VARIABLE{7};
	static constexpr EnumBase  SEG_THIS{8};
	static constexpr EnumBase  SEG_SQL{9};
};


class ExpStreamSegment final : public AbstractExpression {
public:
	class SegmentType : public __ExpStreamSegment__SegmentType {
	public:
		SegmentType() = default;constexpr SegmentType(const EnumBase& base) :  __ExpStreamSegment__SegmentType(base) {};
	};
public:
	ExpStreamSegment(const ExpStreamSegment& base) = default;
public:
	ExpStreamSegment(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~ExpStreamSegment() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	DomVariableDescriptor* domPath;
private:
	String* prefix;
	String* name;
	ArrayList<IExpression>* arrayIndexes;
	ExpStreamSegment::SegmentType segmentType;
	AlinousType* analysedType;
	DomVariableDeclareSource* domDeclare;
	TypedVariableDeclare* typedDeclare;
	FunctionArgumentDefine* argumentDeclare;
	ClassMemberVariable* memberVariableDef;
	ClassMemberVariable* staticVariableDef;
public:
	IAlinousVariable* resolveExpression(ScriptMachine* machine, bool debug, ThreadContext* ctx) final;
	bool visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw()  final;
	bool isConstant(ThreadContext* ctx) throw()  final;
	bool analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw()  final;
	ExpressionSourceId* getSourceId(ThreadContext* ctx) throw()  final;
	void addArrayIndex(IExpression* exp, ThreadContext* ctx) throw() ;
	String* getPrefix(ThreadContext* ctx) throw() ;
	void setPrefix(String* prefix, ThreadContext* ctx) throw() ;
	String* getName(ThreadContext* ctx) throw() ;
	void setName(String* name, ThreadContext* ctx) throw() ;
	ArrayList<IExpression>* getArrayIndexes(ThreadContext* ctx) throw() ;
	AlinousType* getAnalysedType(ThreadContext* ctx) throw() ;
	DomVariableDescriptor* getDomPath(ThreadContext* ctx) throw() ;
	DomVariableDeclareSource* getDomDeclare(ThreadContext* ctx) throw() ;
	ExpStreamSegment::SegmentType getSegmentType(ThreadContext* ctx) throw() ;
	String* toString(ThreadContext* ctx) throw() ;
	ClassMemberVariable* getMemberVariableDef(ThreadContext* ctx) throw() ;
	int getExpressionType(ThreadContext* ctx) throw()  final;
	void readData(NetworkBinaryBuffer* buff, ThreadContext* ctx) final;
	void writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) final;
	int fileSize(ThreadContext* ctx) final;
	void toFileEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx) final;
	void fromFileEntry(FileStorageEntryFetcher* fetcher, ThreadContext* ctx) final;
private:
	IAlinousVariable* returnMemberDomVariable(ScriptMachine* machine, bool debug, ThreadContext* ctx);
	IAlinousVariable* returnMemberDomVariableArray(ScriptMachine* machine, bool debug, ThreadContext* ctx);
	IAlinousVariable* returnMemberVariable(ScriptMachine* machine, bool debug, ThreadContext* ctx);
	IAlinousVariable* addDescriptor(ScriptMachine* machine, IdentifierVariable* lastIdentifier, bool debug, ThreadContext* ctx);
	IAlinousVariable* getClassMemberVariable(ScriptMachine* machine, AlinousClassVariable* classVariable, ThreadContext* ctx) throw() ;
	IAlinousVariable* getDomProperty(ScriptMachine* machine, IDomVariable* lastSegmentVariable, bool debug, ThreadContext* ctx);
	IDomVariable* handleDomArrayIndexes(ScriptMachine* machine, IDomVariable* prop, bool debug, ThreadContext* ctx);
	IAlinousVariable* handleFirstSegment(ScriptMachine* machine, bool debug, ThreadContext* ctx);
	DomVariableDescriptor* createDomDescriptor(ScriptMachine* machine, bool debug, ThreadContext* ctx);
	IAlinousVariable* handleTypedObjectOrPrefix(ScriptMachine* machine, bool debug, ThreadContext* ctx);
	IAlinousVariable* handleTypedArrayIndexes(ScriptMachine* machine, ITypedVariable* variable, bool debug, ThreadContext* ctx);
	bool analyseAfterDom(ExpressionStreamResult* result, SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() ;
	bool memberDomVariable(ExpressionStreamResult* result, SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() ;
	bool analyseAfterClassObject(ExpressionStreamResult* result, SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() ;
	bool analyseFirstSegment(ExpressionStreamResult* result, SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() ;
	bool analyseFirstObject(ExpressionStreamResult* result, SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}

#endif /* end of ALINOUS_COMPILE_EXPRESSION_EXPSTREAM_EXPSTREAMSEGMENT_H_ */
