#ifndef ALINOUS_RUNTIME_DOM_DOMVARIABLEDEBUGXMLFACTORY_H_
#define ALINOUS_RUNTIME_DOM_DOMVARIABLEDEBUGXMLFACTORY_H_
namespace alinous {namespace runtime {namespace dom {
class IDomVariable;}}}

namespace alinous {namespace html {
class DomNode;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace runtime {namespace dom {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::html::DomNode;



class DomVariableDebugXmlFactory final : public virtual IObject {
public:
	DomVariableDebugXmlFactory(const DomVariableDebugXmlFactory& base) = default;
public:
	DomVariableDebugXmlFactory(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~DomVariableDebugXmlFactory() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	static IDomVariable* getDom(DomNode* node, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_RUNTIME_DOM_DOMVARIABLEDEBUGXMLFACTORY_H_ */
