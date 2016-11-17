#ifndef ALINOUS_HTML_DOMTEXT_H_
#define ALINOUS_HTML_DOMTEXT_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace html {
class DomNode;}}

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



class DomText final : public IDomObject, public virtual IObject {
public:
	DomText(const DomText& base) = default;
public:
	DomText(ThreadContext* ctx) throw()  : IObject(ctx), IDomObject(ctx), text(nullptr), parent(nullptr)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~DomText() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	String* text;
	DomNode* parent;
public:
	DomNode* getParent(ThreadContext* ctx) throw()  final;
	void setParent(DomNode* parent, ThreadContext* ctx) throw()  final;
	String* getText(ThreadContext* ctx) throw() ;
	void setText(String* text, ThreadContext* ctx) throw() ;
	String* toString(ThreadContext* ctx) throw() ;
	IDomObject* getNextSibilingElement(ThreadContext* ctx) throw()  final;
	IDomObject* getNextElement(ThreadContext* ctx) throw()  final;
	int getType(ThreadContext* ctx) throw()  final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}

#endif /* end of ALINOUS_HTML_DOMTEXT_H_ */
