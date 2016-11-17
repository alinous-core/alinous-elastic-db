#ifndef ALINOUS_HTML_DOMNODE_H_
#define ALINOUS_HTML_DOMNODE_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace html {
class IDomObject;}}

namespace alinous {namespace html {
class DomNode;}}

namespace alinous {namespace html {
class Attribute;}}

namespace alinous {namespace html {namespace xpath {
class IVariableValue;}}}

namespace java {namespace util {
template <typename  T> class Iterator;}}

namespace alinous {namespace html {namespace xpath {
class StringValue;}}}

namespace java {namespace lang {
class RuntimeException;}}

namespace java {namespace lang {
class StringBuffer;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace html {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::ArrayList;
using ::java::util::Iterator;
using ::alinous::html::xpath::IVariableValue;
using ::alinous::html::xpath::StringValue;



class DomNode : public IDomObject, public virtual IObject {
public:
	DomNode(const DomNode& base) = default;
public:
	DomNode(String* name, ThreadContext* ctx) throw() ;
	void __construct_impl(String* name, ThreadContext* ctx) throw() ;
	virtual ~DomNode() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	ArrayList<Attribute>* attributes;
	ArrayList<IDomObject>* children;
	ArrayList<DomNode>* childNodes;
private:
	String* name;
	DomNode* parent;
	bool singleEnd;
	bool xmlHeader;
public:
	void removeElement(IDomObject* element, ThreadContext* ctx) throw() ;
	int getNumChildElement(ThreadContext* ctx) throw() ;
	IDomObject* getChildElementAt(int index, ThreadContext* ctx) throw() ;
	int getChildElementIndexOf(IDomObject* element, ThreadContext* ctx) throw() ;
	DomNode* getChildNodeAt(int index, ThreadContext* ctx) throw() ;
	int getChildNodeIndexOf(DomNode* node, ThreadContext* ctx) throw() ;
	int getNumChildern(ThreadContext* ctx) throw() ;
	IDomObject* getNextSibilingElement(ThreadContext* ctx) throw()  final;
	IDomObject* getNextElement(ThreadContext* ctx) throw()  final;
	DomNode* getNextSibilingNode(ThreadContext* ctx) throw() ;
	DomNode* getNextNode(ThreadContext* ctx) throw() ;
	void clearChildren(ThreadContext* ctx) throw() ;
	void clearAttributes(ThreadContext* ctx) throw() ;
	void addAttribute(String* key, String* value, ThreadContext* ctx) throw() ;
	void handleUnclosed(ThreadContext* ctx) throw() ;
	void addChild(IDomObject* element, ThreadContext* ctx) throw() ;
	void addAttribute(Attribute* attr, ThreadContext* ctx) throw() ;
	IVariableValue* getAttributeValue(String* name, ThreadContext* ctx) throw() ;
	DomNode* getParent(ThreadContext* ctx) throw()  final;
	void setParent(DomNode* parent, ThreadContext* ctx) throw()  final;
	String* getName(ThreadContext* ctx) throw() ;
	void setName(String* name, ThreadContext* ctx) throw() ;
	bool isSingleEnd(ThreadContext* ctx) throw() ;
	void setSingleEnd(bool singleEnd, ThreadContext* ctx) throw() ;
	IArrayObject<Attribute>* getAttributes(ThreadContext* ctx) throw() ;
	void setAttributes(IArrayObject<Attribute>* attributes, ThreadContext* ctx) throw() ;
	bool isXmlHeader(ThreadContext* ctx) throw() ;
	void setXmlHeader(bool xmlHeader, ThreadContext* ctx) throw() ;
	virtual String* getPathString(ThreadContext* ctx) throw() ;
	String* getInnerHtml(ThreadContext* ctx) throw() ;
	virtual String* toString(ThreadContext* ctx) throw() ;
	virtual int getType(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}

#endif /* end of ALINOUS_HTML_DOMNODE_H_ */
