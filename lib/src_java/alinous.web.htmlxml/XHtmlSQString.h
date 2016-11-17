#ifndef ALINOUS_WEB_HTMLXML_XHTMLSQSTRING_H_
#define ALINOUS_WEB_HTMLXML_XHTMLSQSTRING_H_
namespace alinous {namespace web {namespace htmlxml {namespace module {
class SerializeContext;}}}}

namespace alinous {namespace runtime {namespace engine {
class ScriptMachine;}}}

namespace java {namespace lang {
class StringBuffer;}}

namespace alinous {namespace web {namespace htmlxml {
class AbstractXHtmlAttributeValue;}}}

namespace alinous {namespace db {namespace table {
class DatabaseException;}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace web {namespace htmlxml {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::db::table::DatabaseException;
using ::alinous::runtime::engine::ScriptMachine;
using ::alinous::system::AlinousException;
using ::alinous::web::htmlxml::module::SerializeContext;



class XHtmlSQString final : public AbstractXHtmlAttributeValue {
public:
	XHtmlSQString(const XHtmlSQString& base) = default;
public:
	XHtmlSQString(ThreadContext* ctx) throw()  : IObject(ctx), AbstractXHtmlAttributeValue(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~XHtmlSQString() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	bool isDinamicAll(ThreadContext* ctx) throw()  final;
	void serialize(SerializeContext* context, ThreadContext* ctx) final;
	String* execute(ScriptMachine* machine, bool debug, ThreadContext* ctx) final;
	String* toString(ThreadContext* ctx) throw() ;
	AbstractXHtmlElement::ElementType getElementType(ThreadContext* ctx) throw()  final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_WEB_HTMLXML_XHTMLSQSTRING_H_ */
