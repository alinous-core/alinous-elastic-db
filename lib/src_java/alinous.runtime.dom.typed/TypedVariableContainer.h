#ifndef ALINOUS_RUNTIME_DOM_TYPED_TYPEDVARIABLECONTAINER_H_
#define ALINOUS_RUNTIME_DOM_TYPED_TYPEDVARIABLECONTAINER_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace runtime {namespace dom {namespace typed {
class TypedVariableDomFactory;}}}}

namespace java {namespace util {
template <typename  T, typename V> class Map;}}

namespace alinous {namespace runtime {namespace dom {namespace typed {
class ITypedVariable;}}}}

namespace java {namespace util {
template <typename  T> class Iterator;}}

namespace alinous {namespace runtime {namespace dom {namespace typed {
class TypedVariableContainer;}}}}

namespace alinous {namespace html {
class DomNode;}}

namespace alinous {namespace runtime {namespace dom {namespace typed {
class AbstractTypedVariable;}}}}

namespace alinous {namespace html {namespace xpath {
class IVariableValue;}}}

namespace java {namespace util {
template <typename  T, typename V> class HashMap;}}

namespace alinous {namespace runtime {namespace dom {
class IAlinousVariable;}}}

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
using ::java::util::HashMap;
using ::java::util::Iterator;
using ::java::util::Map;
using ::alinous::html::DomNode;
using ::alinous::html::xpath::IVariableValue;
using ::alinous::runtime::dom::IAlinousVariable;



class TypedVariableContainer final : public virtual IObject {
public:
	TypedVariableContainer(const TypedVariableContainer& base) = default;
public:
	TypedVariableContainer(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~TypedVariableContainer() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	HashMap<String,ITypedVariable>* variables;
public:
	static String* TAG_TYPED_VARIABLE_CONTAINER;
public:
	void addVariablesToList(Map<String,ITypedVariable>* list, ThreadContext* ctx) throw() ;
	void outDebugXml(DomNode* parentNode, ThreadContext* ctx) throw() ;
	ITypedVariable* get(String* name, ThreadContext* ctx) throw() ;
	void put(String* name, ITypedVariable* variable, ThreadContext* ctx) throw() ;
public:
	static void includes(TypedVariableDomFactory* arg0, ThreadContext* ctx) throw() ;
	static TypedVariableContainer* importFromDebugXml(DomNode* node, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}

#endif /* end of ALINOUS_RUNTIME_DOM_TYPED_TYPEDVARIABLECONTAINER_H_ */
