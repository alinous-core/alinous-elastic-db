#ifndef ALINOUS_WEB_HTMLXML_HTMLTOPOBJECT_H_
#define ALINOUS_WEB_HTMLXML_HTMLTOPOBJECT_H_
namespace alinous {namespace web {namespace htmlxml {
class AbstractXHtmlElement;}}}

namespace alinous {namespace web {namespace htmlxml {namespace module {
class SerializeContext;}}}}

namespace alinous {namespace web {namespace htmlxml {
class HtmlDocType;}}}

namespace java {namespace lang {
class StringBuffer;}}

namespace alinous {namespace system {
class AlinousException;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace web {namespace htmlxml {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::ArrayList;
using ::alinous::system::AlinousException;
using ::alinous::web::htmlxml::module::SerializeContext;



class HtmlTopObject final : public virtual IObject {
public:
	HtmlTopObject(const HtmlTopObject& base) = default;
public:
	HtmlTopObject(ThreadContext* ctx) throw()  : IObject(ctx), elements(GCUtils<ArrayList<AbstractXHtmlElement> >::ins(this, (new(ctx) ArrayList<AbstractXHtmlElement>(ctx)), ctx, __FILEW__, __LINE__, L"")), docType(nullptr)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~HtmlTopObject() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	ArrayList<AbstractXHtmlElement>* elements;
	HtmlDocType* docType;
public:
	void addElement(AbstractXHtmlElement* element, ThreadContext* ctx) throw() ;
	void serialize(SerializeContext* context, ThreadContext* ctx);
	HtmlDocType* getDocType(ThreadContext* ctx) throw() ;
	void setDocType(HtmlDocType* docType, ThreadContext* ctx) throw() ;
	String* toString(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_WEB_HTMLXML_HTMLTOPOBJECT_H_ */
