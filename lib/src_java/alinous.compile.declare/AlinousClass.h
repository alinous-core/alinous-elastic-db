#ifndef ALINOUS_COMPILE_DECLARE_ALINOUSCLASS_H_
#define ALINOUS_COMPILE_DECLARE_ALINOUSCLASS_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace runtime {namespace engine {
class ScriptMachine;}}}

namespace alinous {namespace compile {namespace declare {
class ClassMemberVariable;}}}

namespace alinous {namespace compile {namespace declare {
class AlinousClass;}}}

namespace alinous {namespace compile {namespace declare {
class ClassMethodFunction;}}}

namespace alinous {namespace compile {namespace expression {
class FunctionArguments;}}}

namespace alinous {namespace compile {namespace analyse {namespace tools {
class ClassMethodArgumentMatcher;}}}}

namespace alinous {namespace compile {namespace analyse {namespace tools {
class MatchingMethodCandidate;}}}}

namespace alinous {namespace compile {namespace declare {namespace function {
class AlinousFunction;}}}}

namespace alinous {namespace runtime {namespace engine {
class MainStackFrame;}}}

namespace alinous {namespace runtime {namespace dom {
class IAlinousVariable;}}}

namespace alinous {namespace compile {namespace declare {namespace function {
class FunctionArgumentDefine;}}}}

namespace alinous {namespace compile {namespace expression {
class IExpression;}}}

namespace alinous {namespace compile {namespace stmt {
class StatementList;}}}

namespace java {namespace lang {
class Throwable;}}

namespace alinous {namespace runtime {namespace dom {namespace clazz {
class AlinousClassVariable;}}}}

namespace alinous {namespace compile {
class IAlinousElementVisitor;}}

namespace alinous {namespace compile {
class AbstractSrcElement;}}

namespace alinous {namespace compile {namespace analyse {
class SrcAnalyseContext;}}}

namespace java {namespace util {
template <typename  T> class Iterator;}}

namespace alinous {namespace compile {namespace declare {
class ClassExtends;}}}

namespace alinous {namespace compile {namespace declare {
class ClassImplements;}}}

namespace alinous {namespace compile {namespace declare {
class VirtualTable;}}}

namespace alinous {namespace compile {namespace declare {
class AlinousName;}}}

namespace alinous {namespace runtime {
class AlinousModulePackage;}}

namespace java {namespace lang {
class StringBuffer;}}

namespace alinous {namespace remote {namespace socket {
class NetworkBinaryBuffer;}}}

namespace alinous {namespace compile {
class IAlinousElement;}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace alinous {namespace compile {namespace declare {
class IDeclare;}}}

namespace alinous {namespace compile {
class AlinousElementNetworkFactory;}}

namespace alinous {namespace db {namespace table {
class DatabaseException;}}}

namespace alinous {namespace remote {namespace socket {
class ICommandData;}}}

namespace alinous {namespace runtime {namespace engine {
class ScriptRunner;}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace compile {namespace declare {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::ArrayList;
using ::java::util::Iterator;
using ::alinous::compile::AbstractSrcElement;
using ::alinous::compile::AlinousElementNetworkFactory;
using ::alinous::compile::IAlinousElement;
using ::alinous::compile::IAlinousElementVisitor;
using ::alinous::compile::analyse::SrcAnalyseContext;
using ::alinous::compile::analyse::tools::ClassMethodArgumentMatcher;
using ::alinous::compile::analyse::tools::MatchingMethodCandidate;
using ::alinous::compile::declare::function::AlinousFunction;
using ::alinous::compile::declare::function::FunctionArgumentDefine;
using ::alinous::compile::expression::FunctionArguments;
using ::alinous::compile::expression::IExpression;
using ::alinous::compile::stmt::StatementList;
using ::alinous::db::table::DatabaseException;
using ::alinous::remote::socket::ICommandData;
using ::alinous::remote::socket::NetworkBinaryBuffer;
using ::alinous::runtime::AlinousModulePackage;
using ::alinous::runtime::dom::IAlinousVariable;
using ::alinous::runtime::dom::VariableException;
using ::alinous::runtime::dom::clazz::AlinousClassVariable;
using ::alinous::runtime::engine::MainStackFrame;
using ::alinous::runtime::engine::ScriptMachine;
using ::alinous::runtime::engine::ScriptRunner;
using ::alinous::system::AlinousException;



class AlinousClass final : public IDeclare {
public:
	AlinousClass(const AlinousClass& base) = default;
public:
	AlinousClass(ThreadContext* ctx) throw()  : IObject(ctx), IDeclare(ctx), packageName(nullptr), name(nullptr), extendsClasses(nullptr), implementsClass(nullptr), interfaceClass(0), constructors(GCUtils<ArrayList<ClassMethodFunction> >::ins(this, (new(ctx) ArrayList<ClassMethodFunction>(ctx)), ctx, __FILEW__, __LINE__, L"")), members(GCUtils<ArrayList<ClassMemberVariable> >::ins(this, (new(ctx) ArrayList<ClassMemberVariable>(ctx)), ctx, __FILEW__, __LINE__, L"")), methods(GCUtils<ArrayList<ClassMethodFunction> >::ins(this, (new(ctx) ArrayList<ClassMethodFunction>(ctx)), ctx, __FILEW__, __LINE__, L"")), staticMembers(GCUtils<ArrayList<ClassMemberVariable> >::ins(this, (new(ctx) ArrayList<ClassMemberVariable>(ctx)), ctx, __FILEW__, __LINE__, L"")), staticMethods(GCUtils<ArrayList<ClassMethodFunction> >::ins(this, (new(ctx) ArrayList<ClassMethodFunction>(ctx)), ctx, __FILEW__, __LINE__, L"")), delivedClasses(GCUtils<ArrayList<AlinousClass> >::ins(this, (new(ctx) ArrayList<AlinousClass>(ctx)), ctx, __FILEW__, __LINE__, L""))
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~AlinousClass() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	AlinousModulePackage* packageName;
	AlinousName* name;
	ClassExtends* extendsClasses;
	ArrayList<ClassImplements>* implementsClass;
	bool interfaceClass;
	ArrayList<ClassMethodFunction>* constructors;
	ArrayList<ClassMemberVariable>* members;
	ArrayList<ClassMethodFunction>* methods;
	ArrayList<ClassMemberVariable>* staticMembers;
	ArrayList<ClassMethodFunction>* staticMethods;
	ArrayList<AlinousClass>* delivedClasses;
public:
	void initStatic(ScriptMachine* machine, bool debug, ThreadContext* ctx);
	bool hasBaseClass(AlinousClass* other, ThreadContext* ctx) throw() ;
	bool equals(IObject* obj, ThreadContext* ctx) throw() ;
	ClassMemberVariable* getStaticMemberVariable(String* name, ThreadContext* ctx) throw() ;
	ClassMethodFunction* getMemberMethod(String* functionName, FunctionArguments* arguments, ThreadContext* ctx) throw() ;
	ClassMethodFunction* getStaticMemberMethod(String* functionName, FunctionArguments* arguments, ThreadContext* ctx) throw() ;
	ClassMethodFunction* getConstructorFunction(FunctionArguments* arguments, ThreadContext* ctx) throw() ;
	void invokeStaticMemberMethod(ClassMethodFunction* method, FunctionArguments* arguments, ScriptMachine* machine, bool debug, ThreadContext* ctx);
	void invokeMemberMethod(AlinousClassVariable* obj, ClassMethodFunction* method, FunctionArguments* arguments, ScriptMachine* machine, bool debug, ThreadContext* ctx);
	void invokeConstructorMethod(AlinousClassVariable* obj, ClassMethodFunction* method, FunctionArguments* arguments, ScriptMachine* machine, bool debug, ThreadContext* ctx);
	bool visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw()  final;
	void analyseVirtualMethods(SrcAnalyseContext* context, ThreadContext* ctx) throw() ;
	ClassMethodFunction* getOverrodeMethod(ClassMethodFunction* method, ThreadContext* ctx) throw() ;
	void analyseDependency(SrcAnalyseContext* context, ThreadContext* ctx) throw() ;
	bool analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw()  final;
	AlinousName* getName(ThreadContext* ctx) throw() ;
	void setName(AlinousName* name, ThreadContext* ctx) throw() ;
	ClassExtends* getExtendsClasses(ThreadContext* ctx) throw() ;
	void setExtendsClasses(ClassExtends* extendsClasses, ThreadContext* ctx) throw() ;
	void addVariable(ClassMemberVariable* val, ThreadContext* ctx) throw() ;
	void addMethod(ClassMethodFunction* val, ThreadContext* ctx) throw() ;
	void addStaticVariable(ClassMemberVariable* val, ThreadContext* ctx) throw() ;
	void addStaticMethod(ClassMethodFunction* val, ThreadContext* ctx) throw() ;
	ClassMemberVariable* getMember(String* name, ThreadContext* ctx) throw() ;
	ArrayList<ClassMemberVariable>* getMembers(ThreadContext* ctx) throw() ;
	ArrayList<ClassMethodFunction>* getMethods(ThreadContext* ctx) throw() ;
	ArrayList<ClassMemberVariable>* getStaticMembers(ThreadContext* ctx) throw() ;
	ArrayList<ClassMethodFunction>* getStaticMethods(ThreadContext* ctx) throw() ;
	AlinousModulePackage* getPackageName(ThreadContext* ctx) throw() ;
	void setPackageName(AlinousModulePackage* packageName, ThreadContext* ctx) throw() ;
	String* toString(ThreadContext* ctx) throw() ;
	int getLine(ThreadContext* ctx) throw()  final;
	int getStartPosition(ThreadContext* ctx) throw()  final;
	int getEndLine(ThreadContext* ctx) throw()  final;
	int getEndPosition(ThreadContext* ctx) throw()  final;
	AbstractSrcElement* getParent(ThreadContext* ctx) throw()  final;
	void setParent(AbstractSrcElement* parent, ThreadContext* ctx) throw()  final;
	bool isInterfaceClass(ThreadContext* ctx) throw() ;
	void setInterfaceClass(bool interfaceClass, ThreadContext* ctx) throw() ;
	ArrayList<ClassImplements>* getImplementsClass(ThreadContext* ctx) throw() ;
	void setImplementsClass(ArrayList<ClassImplements>* implementsClass, ThreadContext* ctx) throw() ;
	void readData(NetworkBinaryBuffer* buff, ThreadContext* ctx) final;
	void writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) final;
private:
	void initMembers(AlinousClassVariable* obj, ScriptMachine* machine, bool debug, ThreadContext* ctx);
	void analyzeMethodVirtual(SrcAnalyseContext* context, ClassMethodFunction* method, ThreadContext* ctx) throw() ;
	bool findInterfaces(ClassImplements* impls, SrcAnalyseContext* context, ClassMethodFunction* method, ThreadContext* ctx) throw() ;
	void createVirtualTable(SrcAnalyseContext* context, ClassMethodFunction* method, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_COMPILE_DECLARE_ALINOUSCLASS_H_ */
