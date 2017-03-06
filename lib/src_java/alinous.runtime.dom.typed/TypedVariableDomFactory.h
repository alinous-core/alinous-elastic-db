#ifndef ALINOUS_RUNTIME_DOM_TYPED_TYPEDVARIABLEDOMFACTORY_H_
#define ALINOUS_RUNTIME_DOM_TYPED_TYPEDVARIABLEDOMFACTORY_H_
namespace alinous {namespace runtime {namespace dom {namespace typed {
class AbstractTypedVariable;}}}}

namespace alinous {namespace html {
class DomNode;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace runtime {namespace dom {namespace typed {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::html::DomNode;



class TypedVariableDomFactory final : public virtual IObject {
public:
	TypedVariableDomFactory(const TypedVariableDomFactory& base) = default;
public:
	TypedVariableDomFactory(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~TypedVariableDomFactory() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	static AbstractTypedVariable* importFromDomNode(DomNode* node, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}

#endif /* end of ALINOUS_RUNTIME_DOM_TYPED_TYPEDVARIABLEDOMFACTORY_H_ */
