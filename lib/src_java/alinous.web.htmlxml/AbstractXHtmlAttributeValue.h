#ifndef ALINOUS_WEB_HTMLXML_ABSTRACTXHTMLATTRIBUTEVALUE_H_
#define ALINOUS_WEB_HTMLXML_ABSTRACTXHTMLATTRIBUTEVALUE_H_
namespace alinous {namespace web {namespace htmlxml {namespace inner {
class IHtmlStringPart;}}}}

namespace alinous {namespace web {namespace htmlxml {
class AbstractXHtmlElement;}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace alinous {namespace web {namespace htmlxml {namespace inner {
class InnerStringParser;}}}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace web {namespace htmlxml {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::system::AlinousException;
using ::alinous::web::htmlxml::inner::IHtmlStringPart;
using ::alinous::web::htmlxml::inner::InnerStringParser;



class AbstractXHtmlAttributeValue : public AbstractXHtmlElement {
public:
	AbstractXHtmlAttributeValue(const AbstractXHtmlAttributeValue& base) = default;
public:
	AbstractXHtmlAttributeValue(ThreadContext* ctx) throw()  : IObject(ctx), AbstractXHtmlElement(ctx), value(nullptr)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~AbstractXHtmlAttributeValue() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	String* value;
public:
	String* getValue(ThreadContext* ctx) throw() ;
	void setValue(String* value, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_WEB_HTMLXML_ABSTRACTXHTMLATTRIBUTEVALUE_H_ */
