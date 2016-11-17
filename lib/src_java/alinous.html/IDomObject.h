#ifndef ALINOUS_HTML_IDOMOBJECT_H_
#define ALINOUS_HTML_IDOMOBJECT_H_
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



class IDomObject : public virtual IObject {
public:
	IDomObject(const IDomObject& base) = default;
public:
	IDomObject(ThreadContext* ctx) throw()  : IObject(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~IDomObject() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	constexpr static const int TYPE_ATTRIBUTE{1};
	constexpr static const int TYPE_DOM_NODE{2};
	constexpr static const int TYPE_DOC_TYPE{3};
	constexpr static const int TYPE_DOM_COMMENT{4};
	constexpr static const int TYPE_DOM_DOCUMENT{5};
	constexpr static const int TYPE_DOM_TEXT{6};
public:
	virtual DomNode* getParent(ThreadContext* ctx) throw()  = 0;
	virtual void setParent(DomNode* parent, ThreadContext* ctx) throw()  = 0;
	virtual int getType(ThreadContext* ctx) throw()  = 0;
	virtual IDomObject* getNextElement(ThreadContext* ctx) throw()  = 0;
	virtual IDomObject* getNextSibilingElement(ThreadContext* ctx) throw()  = 0;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}

#endif /* end of ALINOUS_HTML_IDOMOBJECT_H_ */
