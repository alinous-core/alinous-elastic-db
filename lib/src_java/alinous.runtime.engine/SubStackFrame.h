#ifndef ALINOUS_RUNTIME_ENGINE_SUBSTACKFRAME_H_
#define ALINOUS_RUNTIME_ENGINE_SUBSTACKFRAME_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {
class AbstractSrcElement;}}

namespace alinous {namespace runtime {namespace dom {
class DomVariableContainer;}}}

namespace alinous {namespace runtime {namespace dom {namespace typed {
class TypedVariableContainer;}}}}

namespace alinous {namespace runtime {namespace engine {
class SubStackFrame;}}}

namespace alinous {namespace html {
class DomNode;}}

namespace alinous {namespace runtime {namespace engine {
class DebugMainFrameSrcElement;}}}

namespace alinous {namespace html {namespace xpath {
class IVariableValue;}}}

namespace alinous {namespace html {
class Attribute;}}

namespace alinous {namespace runtime {namespace dom {namespace typed {
class ITypedVariable;}}}}

namespace alinous {namespace runtime {namespace engine {
class ScriptMachine;}}}

namespace alinous {namespace compile {namespace expression {
class DomVariableDescriptor;}}}

namespace alinous {namespace runtime {namespace dom {
class IDomVariable;}}}

namespace alinous {namespace compile {namespace expression {
class IDomSegment;}}}

namespace alinous {namespace runtime {namespace dom {
class IDomVariableContainer;}}}

namespace alinous {namespace runtime {namespace dom {
class DomVariable;}}}

namespace alinous {namespace runtime {namespace dom {
class DomArray;}}}

namespace alinous {namespace runtime {namespace engine {
class AbstractStackFrame;}}}

namespace alinous {namespace db {namespace table {
class DatabaseException;}}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace runtime {namespace engine {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::ArrayList;
using ::alinous::compile::AbstractSrcElement;
using ::alinous::compile::expression::DomVariableDescriptor;
using ::alinous::compile::expression::IDomSegment;
using ::alinous::db::table::DatabaseException;
using ::alinous::html::Attribute;
using ::alinous::html::DomNode;
using ::alinous::html::xpath::IVariableValue;
using ::alinous::runtime::dom::DomArray;
using ::alinous::runtime::dom::DomVariable;
using ::alinous::runtime::dom::DomVariableContainer;
using ::alinous::runtime::dom::IDomVariable;
using ::alinous::runtime::dom::IDomVariableContainer;
using ::alinous::runtime::dom::VariableException;
using ::alinous::runtime::dom::typed::ITypedVariable;
using ::alinous::runtime::dom::typed::TypedVariableContainer;
using ::alinous::system::AlinousException;



class SubStackFrame final : public AbstractStackFrame {
public:
	SubStackFrame(const SubStackFrame& base) = default;
public:
	SubStackFrame(AbstractSrcElement* sourceElement, DomVariableContainer* container, ThreadContext* ctx) throw() ;
	void __construct_impl(AbstractSrcElement* sourceElement, DomVariableContainer* container, ThreadContext* ctx) throw() ;
	virtual ~SubStackFrame() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	static String* TAG_SUB_STACKFRAME;
	static String* ATTR_LINE;
	static String* ATTR_FILENAME;
public:
	void outDebugXml(DomNode* parentNode, ThreadContext* ctx) throw() ;
	ITypedVariable* getTypedVariable(String* name, ThreadContext* ctx) throw() ;
	void putTypedVariable(String* name, ITypedVariable* variable, ThreadContext* ctx) throw() ;
	void putVariable(ScriptMachine* machine, DomVariableDescriptor* desc, IDomVariable* variable, bool debug, ThreadContext* ctx) final;
private:
	IDomVariable* addBrankDom(IDomVariableContainer* lastcontainer, String* property, int newType, ThreadContext* ctx);
	IDomVariable* addBrankDom(IDomVariableContainer* lastcontainer, int index, int newType, ThreadContext* ctx) throw() ;
public:
	static SubStackFrame* importFromDebugXml(DomNode* node, DomVariableContainer* domContainer, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_RUNTIME_ENGINE_SUBSTACKFRAME_H_ */
