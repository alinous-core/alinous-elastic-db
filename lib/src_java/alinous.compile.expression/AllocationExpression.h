#ifndef ALINOUS_COMPILE_EXPRESSION_ALLOCATIONEXPRESSION_H_
#define ALINOUS_COMPILE_EXPRESSION_ALLOCATIONEXPRESSION_H_
namespace alinous{namespace annotation{
class NoBlankConstructor;
}}
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace runtime {namespace dom {
class IAlinousVariable;}}}

namespace alinous {namespace runtime {namespace engine {
class ScriptMachine;}}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace alinous {namespace compile {namespace declare {
class AlinousClass;}}}

namespace alinous {namespace runtime {namespace dom {namespace clazz {
class AlinousClassVariable;}}}}

namespace alinous {namespace compile {namespace expression {
class IExpression;}}}

namespace alinous {namespace runtime {namespace dom {namespace typed {
class StringVariable;}}}}

namespace alinous {namespace runtime {namespace dom {namespace typed {
class TypedVariableArray;}}}}

namespace alinous {namespace compile {namespace analyse {
class SrcAnalyseContext;}}}

namespace alinous {namespace compile {
class IAlinousElementVisitor;}}

namespace alinous {namespace compile {
class AbstractSrcElement;}}

namespace alinous {namespace compile {namespace declare {
class AlinousName;}}}

namespace alinous {namespace compile {
class ExpressionSourceId;}}

namespace alinous {namespace compile {namespace expression {
class FunctionArguments;}}}

namespace alinous {namespace compile {namespace analyse {
class AlinousType;}}}

namespace alinous {namespace remote {namespace socket {
class NetworkBinaryBuffer;}}}

namespace alinous {namespace compile {
class IAlinousElement;}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryBuilder;}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryFetcher;}}}

namespace alinous {namespace compile {namespace declare {
class ClassMethodFunction;}}}

namespace alinous {namespace compile {namespace expression {
class AbstractExpression;}}}

namespace alinous {namespace compile {
class AlinousElementNetworkFactory;}}

namespace alinous {namespace db {namespace table {
class DatabaseException;}}}

namespace alinous {namespace remote {namespace socket {
class ICommandData;}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace compile {namespace expression {

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
using ::alinous::compile::analyse::SrcAnalyseContext;
using ::alinous::compile::declare::AlinousClass;
using ::alinous::compile::declare::AlinousName;
using ::alinous::compile::declare::ClassMethodFunction;
using ::alinous::db::table::DatabaseException;
using ::alinous::remote::socket::ICommandData;
using ::alinous::remote::socket::NetworkBinaryBuffer;
using ::alinous::runtime::dom::IAlinousVariable;
using ::alinous::runtime::dom::VariableException;
using ::alinous::runtime::dom::clazz::AlinousClassVariable;
using ::alinous::runtime::dom::typed::StringVariable;
using ::alinous::runtime::dom::typed::TypedVariableArray;
using ::alinous::runtime::engine::ScriptMachine;
using ::alinous::system::AlinousException;



class AllocationExpression final : public AbstractExpression {
public:
	AllocationExpression(const AllocationExpression& base) = default;
public:
	AllocationExpression(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~AllocationExpression() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	AlinousName* objectClassName;
	FunctionArguments* arguments;
	ArrayList<IExpression>* arrayCapacity;
	int newType;
	AlinousType* analysedType;
	ClassMethodFunction* constructor;
public:
	constexpr static const int NEW_CLASS{1};
	constexpr static const int NEW_ARRAY{2};
public:
	IAlinousVariable* resolveExpression(ScriptMachine* machine, bool debug, ThreadContext* ctx) final;
	bool analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw()  final;
	bool isConstant(ThreadContext* ctx) throw()  final;
	bool visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw()  final;
	AlinousName* getObjectClassName(ThreadContext* ctx) throw() ;
	void setObjectClassName(AlinousName* objectClassName, ThreadContext* ctx) throw() ;
	ArrayList<IExpression>* getArrayCapacity(ThreadContext* ctx) throw() ;
	void addArrayCapacity(IExpression* arrayCapacity, ThreadContext* ctx) throw() ;
	ExpressionSourceId* getSourceId(ThreadContext* ctx) throw()  final;
	FunctionArguments* getArguments(ThreadContext* ctx) throw() ;
	void setArguments(FunctionArguments* arguments, ThreadContext* ctx) throw() ;
	AlinousType* getAnalysedType(ThreadContext* ctx) throw() ;
	bool isSQLExp(ThreadContext* ctx) throw()  final;
	int getExpressionType(ThreadContext* ctx) throw()  final;
	void readData(NetworkBinaryBuffer* buff, ThreadContext* ctx) final;
	void writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw()  final;
	int fileSize(ThreadContext* ctx) final;
	void toFileEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx) final;
	void fromFileEntry(FileStorageEntryFetcher* fetcher, ThreadContext* ctx) final;
private:
	IAlinousVariable* newClassObject(ScriptMachine* machine, bool debug, ThreadContext* ctx);
	IAlinousVariable* newStandardType(ScriptMachine* machine, bool debug, ThreadContext* ctx);
	IAlinousVariable* newArrayObject(ScriptMachine* machine, bool debug, ThreadContext* ctx);
	bool analyseConstructors(SrcAnalyseContext* context, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_COMPILE_EXPRESSION_ALLOCATIONEXPRESSION_H_ */
