#ifndef ALINOUS_RUNTIME_DOM_IDOMVARIABLECONTAINER_H_
#define ALINOUS_RUNTIME_DOM_IDOMVARIABLECONTAINER_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace runtime {namespace dom {
class IDomVariable;}}}

namespace alinous {namespace compile {namespace expression {
class DomVariableDescriptor;}}}

namespace alinous {namespace runtime {namespace dom {
class IDomVariableContainer;}}}

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
using ::alinous::compile::expression::DomVariableDescriptor;



class IDomVariableContainer : public virtual IObject {
public:
	IDomVariableContainer(const IDomVariableContainer& base) = default;
public:
	IDomVariableContainer(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~IDomVariableContainer() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	virtual IDomVariable* getByDescriptor(DomVariableDescriptor* desc, ThreadContext* ctx) = 0;
	virtual void setProperty(String* key, IDomVariable* value, ThreadContext* ctx) = 0;
	virtual IDomVariableContainer* getProperty(String* key, ThreadContext* ctx) = 0;
	virtual IDomVariableContainer* get(int index, ThreadContext* ctx) throw()  = 0;
	virtual void set(IDomVariable* val, int index, ThreadContext* ctx) throw()  = 0;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_RUNTIME_DOM_IDOMVARIABLECONTAINER_H_ */
