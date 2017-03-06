#ifndef ALINOUS_RUNTIME_DOM_DOMVARIABLECONTAINER_H_
#define ALINOUS_RUNTIME_DOM_DOMVARIABLECONTAINER_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace runtime {namespace dom {
class IDomVariable;}}}

namespace java {namespace util {
template <typename  T, typename V> class Map;}}

namespace java {namespace util {
template <typename  T> class Iterator;}}

namespace alinous {namespace runtime {namespace dom {
class DomVariableContainer;}}}

namespace alinous {namespace html {
class DomNode;}}

namespace alinous {namespace html {namespace xpath {
class IVariableValue;}}}

namespace alinous {namespace compile {namespace expression {
class DomVariableDescriptor;}}}

namespace alinous {namespace runtime {namespace dom {
class IDomVariableContainer;}}}

namespace java {namespace util {
template <typename  T, typename V> class HashMap;}}

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
using ::java::util::HashMap;
using ::java::util::Iterator;
using ::java::util::Map;
using ::alinous::compile::expression::DomVariableDescriptor;
using ::alinous::html::DomNode;
using ::alinous::html::xpath::IVariableValue;



class DomVariableContainer final : public IDomVariableContainer, public virtual IObject {
public:
	DomVariableContainer(const DomVariableContainer& base) = default;
public:
	DomVariableContainer(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~DomVariableContainer() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	HashMap<String,IDomVariable>* variables;
public:
	static String* TAG_DOM_VARIABLE_CONTAINER;
public:
	IDomVariable* get(String* key, ThreadContext* ctx) throw() ;
	void addVariablesToList(Map<String,IDomVariable>* list, ThreadContext* ctx) throw() ;
	void outDebugXml(DomNode* parentNode, ThreadContext* ctx) throw() ;
	void putVariable(DomVariableDescriptor* desc, IDomVariable* variable, ThreadContext* ctx) throw() ;
	IDomVariable* getByDescriptor(DomVariableDescriptor* desc, ThreadContext* ctx) throw()  final;
	void setProperty(String* key, IDomVariable* value, ThreadContext* ctx) throw()  final;
	IDomVariableContainer* getProperty(String* key, ThreadContext* ctx) throw()  final;
	IDomVariableContainer* get(int index, ThreadContext* ctx) throw()  final;
	void set(IDomVariable* val, int index, ThreadContext* ctx) throw()  final;
public:
	static DomVariableContainer* importFromDebugXml(DomNode* node, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_RUNTIME_DOM_DOMVARIABLECONTAINER_H_ */
