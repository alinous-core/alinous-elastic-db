#ifndef ALINOUS_RUNTIME_ENGINE_MAINSTACKFRAME_H_
#define ALINOUS_RUNTIME_ENGINE_MAINSTACKFRAME_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {
class AbstractSrcElement;}}

namespace alinous {namespace runtime {namespace dom {
class DomVariableContainer;}}}

namespace alinous {namespace runtime {namespace engine {
class MainStackFrame;}}}

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
class SubStackFrame;}}}

namespace alinous {namespace runtime {namespace dom {
class IDomVariable;}}}

namespace alinous {namespace runtime {namespace engine {
class ScriptMachine;}}}

namespace alinous {namespace compile {namespace expression {
class DomVariableDescriptor;}}}

namespace alinous {namespace compile {namespace expression {
class IDomSegment;}}}

namespace alinous {namespace runtime {namespace dom {
class IDomVariableContainer;}}}

namespace alinous {namespace runtime {namespace dom {namespace clazz {
class AlinousClassVariable;}}}}

namespace alinous {namespace runtime {namespace engine {
class AbstractStackFrame;}}}

namespace alinous {namespace db {namespace table {
class DatabaseException;}}}

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
using ::alinous::runtime::dom::DomVariableContainer;
using ::alinous::runtime::dom::IDomVariable;
using ::alinous::runtime::dom::IDomVariableContainer;
using ::alinous::runtime::dom::clazz::AlinousClassVariable;
using ::alinous::runtime::dom::typed::ITypedVariable;
using ::alinous::system::AlinousException;



class MainStackFrame final : public AbstractStackFrame {
public:
	MainStackFrame(const MainStackFrame& base) = default;
public:
	MainStackFrame(AbstractSrcElement* sourceElement, long long stackId, ThreadContext* ctx) throw() ;
	void __construct_impl(AbstractSrcElement* sourceElement, long long stackId, ThreadContext* ctx) throw() ;
	virtual ~MainStackFrame() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	AlinousClassVariable* thisPtr;
	long long stackId;
	int currentLine;
public:
	static String* TAG_STACKFRAME;
	static String* ATTR_LINE;
	static String* ATTR_FILENAME;
	static String* ATTR_PEEK;
	static String* ATTR_NAME;
	static String* ATTR_STACKID;
	static String* ATTR_STEPIN_CANDIDATES;
	static String* ATTR_STEPIN_EXECUTED;
public:
	void outDebugXml(DomNode* parentNode, ThreadContext* ctx) throw() ;
	void putTypedVariable(String* name, ITypedVariable* variable, ThreadContext* ctx);
	ITypedVariable* getTypedVariable(String* name, ThreadContext* ctx) throw() ;
	IDomVariable* getDomVariable(ScriptMachine* machine, DomVariableDescriptor* desc, bool debug, ThreadContext* ctx);
	void putVariable(ScriptMachine* machine, DomVariableDescriptor* desc, IDomVariable* variable, bool debug, ThreadContext* ctx) final;
	AlinousClassVariable* getThisPtr(ThreadContext* ctx) throw() ;
	void setThisPtr(AlinousClassVariable* thisPtr, ThreadContext* ctx) throw() ;
	long long getStackId(ThreadContext* ctx) throw() ;
	int getCurrentLine(ThreadContext* ctx) throw() ;
	void setCurrentLine(int currentLine, ThreadContext* ctx) throw() ;
private:
	IDomVariable* findInSubFrame(ScriptMachine* machine, SubStackFrame* subframe, DomVariableDescriptor* desc, int offset, bool debug, ThreadContext* ctx);
public:
	static MainStackFrame* importFromDebugXml(DomNode* node, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_RUNTIME_ENGINE_MAINSTACKFRAME_H_ */
