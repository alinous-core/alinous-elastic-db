#ifndef ALINOUS_RUNTIME_ENGINE_ISTACKFRAME_H_
#define ALINOUS_RUNTIME_ENGINE_ISTACKFRAME_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace runtime {namespace engine {
class IStackFrame;}}}

namespace alinous {namespace compile {
class AbstractSrcElement;}}

namespace alinous {namespace runtime {namespace engine {
class ScriptMachine;}}}

namespace alinous {namespace compile {namespace expression {
class DomVariableDescriptor;}}}

namespace alinous {namespace runtime {namespace dom {
class IDomVariable;}}}

namespace alinous {namespace db {namespace table {
class DatabaseException;}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace runtime {namespace engine {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::compile::AbstractSrcElement;
using ::alinous::compile::expression::DomVariableDescriptor;
using ::alinous::db::table::DatabaseException;
using ::alinous::runtime::dom::IDomVariable;
using ::alinous::system::AlinousException;



class IStackFrame : public virtual IObject {
public:
	IStackFrame(const IStackFrame& base) = default;
public:
	IStackFrame(ThreadContext* ctx) throw()  : IObject(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~IStackFrame() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	virtual IStackFrame* peek(ThreadContext* ctx) throw()  = 0;
	virtual IStackFrame* subFrame(AbstractSrcElement* sourceElement, ThreadContext* ctx) throw()  = 0;
	virtual IStackFrame* pop(ThreadContext* ctx) throw()  = 0;
	virtual bool hasSubStack(ThreadContext* ctx) throw()  = 0;
	virtual void putVariable(ScriptMachine* machine, DomVariableDescriptor* desc, IDomVariable* variable, bool debug, ThreadContext* ctx) = 0;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_RUNTIME_ENGINE_ISTACKFRAME_H_ */
