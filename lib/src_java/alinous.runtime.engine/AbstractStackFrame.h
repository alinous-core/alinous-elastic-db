#ifndef ALINOUS_RUNTIME_ENGINE_ABSTRACTSTACKFRAME_H_
#define ALINOUS_RUNTIME_ENGINE_ABSTRACTSTACKFRAME_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace html {
class DomNode;}}

namespace alinous {namespace runtime {namespace engine {
class AbstractStackFrame;}}}

namespace alinous {namespace runtime {namespace engine {
class SubStackFrame;}}}

namespace alinous {namespace runtime {namespace engine {
class IStackFrame;}}}

namespace alinous {namespace compile {
class AbstractSrcElement;}}

namespace java {namespace util {
template <typename  T, typename V> class Map;}}

namespace alinous {namespace runtime {namespace dom {
class IDomVariable;}}}

namespace java {namespace util {
template <typename  T, typename V> class HashMap;}}

namespace alinous {namespace runtime {namespace dom {
class DomVariableContainer;}}}

namespace alinous {namespace runtime {namespace dom {namespace typed {
class ITypedVariable;}}}}

namespace alinous {namespace runtime {namespace dom {namespace typed {
class TypedVariableContainer;}}}}

namespace java {namespace util {
template <typename  T> class Stack;}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace runtime {namespace engine {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::HashMap;
using ::java::util::Map;
using ::java::util::Stack;
using ::alinous::compile::AbstractSrcElement;
using ::alinous::html::DomNode;
using ::alinous::runtime::dom::DomVariableContainer;
using ::alinous::runtime::dom::IDomVariable;
using ::alinous::runtime::dom::typed::ITypedVariable;
using ::alinous::runtime::dom::typed::TypedVariableContainer;



class AbstractStackFrame : public AbstractSrcElement, public IStackFrame {
public:
	AbstractStackFrame(const AbstractStackFrame& base) = default;
public:
	AbstractStackFrame(ThreadContext* ctx) throw()  : IObject(ctx), AbstractSrcElement(ctx), IStackFrame(ctx), sourceElement(nullptr), container(nullptr), typedContainer(nullptr), stackFrames(GCUtils<Stack<SubStackFrame> >::ins(this, (new(ctx) Stack<SubStackFrame>(ctx)), ctx, __FILEW__, __LINE__, L""))
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~AbstractStackFrame() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	AbstractSrcElement* sourceElement;
	DomVariableContainer* container;
	TypedVariableContainer* typedContainer;
	Stack<SubStackFrame>* stackFrames;
public:
	IStackFrame* subFrame(AbstractSrcElement* sourceElement, ThreadContext* ctx) throw()  final;
	Map<String,IDomVariable>* getDebugSideDomvariables(ThreadContext* ctx) throw() ;
	Map<String,ITypedVariable>* getDebugSideTypedVariables(ThreadContext* ctx) throw() ;
	bool hasSubStack(ThreadContext* ctx) throw()  final;
	IStackFrame* pop(ThreadContext* ctx) throw()  final;
	IStackFrame* peek(ThreadContext* ctx) throw()  final;
	DomVariableContainer* getVariableContainer(ThreadContext* ctx) throw() ;
	TypedVariableContainer* getTypedContainer(ThreadContext* ctx) throw() ;
	void outSubframeDebugXml(DomNode* parentNode, ThreadContext* ctx) throw() ;
public:
	static void importInnerFromXml(DomNode* node, AbstractStackFrame* frame, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_RUNTIME_ENGINE_ABSTRACTSTACKFRAME_H_ */
