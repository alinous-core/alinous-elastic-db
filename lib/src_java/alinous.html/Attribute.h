#ifndef ALINOUS_HTML_ATTRIBUTE_H_
#define ALINOUS_HTML_ATTRIBUTE_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace html {
class DomNode;}}

namespace java {namespace lang {
class StringBuffer;}}

namespace alinous {namespace html {
class IDomObject;}}

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



class Attribute final : public IDomObject, public virtual IObject {
public:
	Attribute(const Attribute& base) = default;
public:
	Attribute(String* name, String* value, DomNode* parent, ThreadContext* ctx) throw() ;
	void __construct_impl(String* name, String* value, DomNode* parent, ThreadContext* ctx) throw() ;
	Attribute(ThreadContext* ctx) throw()  : IObject(ctx), IDomObject(ctx), name(nullptr), value(nullptr), parent(nullptr)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~Attribute() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	String* name;
	String* value;
	DomNode* parent;
public:
	DomNode* getParent(ThreadContext* ctx) throw()  final;
	void setParent(DomNode* parent, ThreadContext* ctx) throw()  final;
	String* getName(ThreadContext* ctx) throw() ;
	void setName(String* name, ThreadContext* ctx) throw() ;
	String* getValue(ThreadContext* ctx) throw() ;
	void setValue(String* value, ThreadContext* ctx) throw() ;
	String* toString(ThreadContext* ctx) throw() ;
	IDomObject* getNextElement(ThreadContext* ctx) throw()  final;
	IDomObject* getNextSibilingElement(ThreadContext* ctx) throw()  final;
	int getType(ThreadContext* ctx) throw()  final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}

#endif /* end of ALINOUS_HTML_ATTRIBUTE_H_ */
