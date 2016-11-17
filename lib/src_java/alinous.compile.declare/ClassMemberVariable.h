#ifndef ALINOUS_COMPILE_DECLARE_CLASSMEMBERVARIABLE_H_
#define ALINOUS_COMPILE_DECLARE_CLASSMEMBERVARIABLE_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace runtime {namespace engine {
class ScriptMachine;}}}

namespace alinous {namespace runtime {namespace dom {namespace clazz {
class AlinousClassVariable;}}}}

namespace alinous {namespace runtime {namespace dom {
class IAlinousVariable;}}}

namespace alinous {namespace compile {
class IAlinousElementVisitor;}}

namespace alinous {namespace compile {
class AbstractSrcElement;}}

namespace alinous {namespace compile {namespace declare {
class AlinousName;}}}

namespace alinous {namespace compile {namespace expression {
class DomVariableDescriptor;}}}

namespace alinous {namespace compile {namespace expression {
class IExpression;}}}

namespace alinous {namespace compile {namespace analyse {
class SrcAnalyseContext;}}}

namespace alinous {namespace compile {namespace analyse {
class AlinousType;}}}

namespace alinous {namespace compile {namespace declare {
class AbstractClassMember;}}}

namespace alinous {namespace db {namespace table {
class DatabaseException;}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace compile {namespace declare {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::compile::AbstractSrcElement;
using ::alinous::compile::IAlinousElementVisitor;
using ::alinous::compile::analyse::AlinousType;
using ::alinous::compile::analyse::SrcAnalyseContext;
using ::alinous::compile::expression::DomVariableDescriptor;
using ::alinous::compile::expression::IExpression;
using ::alinous::db::table::DatabaseException;
using ::alinous::runtime::dom::IAlinousVariable;
using ::alinous::runtime::dom::clazz::AlinousClassVariable;
using ::alinous::runtime::engine::ScriptMachine;
using ::alinous::system::AlinousException;



class ClassMemberVariable final : public AbstractClassMember {
public:
	ClassMemberVariable(const ClassMemberVariable& base) = default;
public:
	ClassMemberVariable(ThreadContext* ctx) throw()  : IObject(ctx), AbstractClassMember(ctx), type(nullptr), dimension(0), name(nullptr), domDescriptor(nullptr), init(nullptr), staticValue(nullptr), analysedType(nullptr)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~ClassMemberVariable() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	AlinousName* type;
	int dimension;
	AlinousName* name;
	DomVariableDescriptor* domDescriptor;
	IExpression* init;
	IAlinousVariable* staticValue;
	AlinousType* analysedType;
public:
	void initStatic(ScriptMachine* machine, bool debug, ThreadContext* ctx);
	void initMember(AlinousClassVariable* obj, ScriptMachine* machine, bool debug, ThreadContext* ctx);
	String* getMemberName(ThreadContext* ctx) throw() ;
	bool isSame(String* name, ThreadContext* ctx) throw() ;
	bool visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw()  final;
	int getMemberType(ThreadContext* ctx) throw()  final;
	AlinousName* getType(ThreadContext* ctx) throw() ;
	void setType(AlinousName* type, ThreadContext* ctx) throw() ;
	AlinousName* getName(ThreadContext* ctx) throw() ;
	void setName(AlinousName* name, ThreadContext* ctx) throw() ;
	DomVariableDescriptor* getDomDescriptor(ThreadContext* ctx) throw() ;
	void setDomDescriptor(DomVariableDescriptor* domDescriptor, ThreadContext* ctx) throw() ;
	IExpression* getInit(ThreadContext* ctx) throw() ;
	void setInit(IExpression* init, ThreadContext* ctx) throw() ;
	bool analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw()  final;
	AlinousType* getAnalysedType(ThreadContext* ctx) throw() ;
	IAlinousVariable* getStaticValue(ThreadContext* ctx) throw() ;
	int getDimension(ThreadContext* ctx) throw() ;
	void setDimension(int dimension, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_COMPILE_DECLARE_CLASSMEMBERVARIABLE_H_ */
