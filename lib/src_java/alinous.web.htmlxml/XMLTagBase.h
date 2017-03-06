#ifndef ALINOUS_WEB_HTMLXML_XMLTAGBASE_H_
#define ALINOUS_WEB_HTMLXML_XMLTAGBASE_H_
namespace alinous {namespace web {namespace htmlxml {
class XHtmlAttribute;}}}

namespace alinous {namespace web {namespace htmlxml {
class AbstractXHtmlElement;}}}

namespace alinous {namespace web {namespace htmlxml {namespace module {
class SerializeContext;}}}}

namespace java {namespace lang {
class StringBuffer;}}

namespace alinous {namespace runtime {namespace engine {
class ScriptMachine;}}}

namespace alinous {namespace web {namespace htmlxml {namespace inner {
class IHtmlStringPart;}}}}

namespace alinous {namespace db {namespace table {
class DatabaseException;}}}

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
using ::java::util::ArrayList;
using ::alinous::db::table::DatabaseException;
using ::alinous::runtime::engine::ScriptMachine;
using ::alinous::system::AlinousException;
using ::alinous::web::htmlxml::inner::IHtmlStringPart;
using ::alinous::web::htmlxml::inner::InnerStringParser;
using ::alinous::web::htmlxml::module::SerializeContext;



class XMLTagBase final : public AbstractXHtmlElement {
public:
	XMLTagBase(const XMLTagBase& base) = default;
public:
	XMLTagBase(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~XMLTagBase() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	ArrayList<XHtmlAttribute>* attributes;
	ArrayList<AbstractXHtmlElement>* innerElements;
private:
	String* tagName;
	bool isDynamicTagName;
public:
	bool isDinamicAll(ThreadContext* ctx) throw()  final;
	void serialize(SerializeContext* context, ThreadContext* ctx) final;
	String* execute(ScriptMachine* machine, bool debug, ThreadContext* ctx) final;
	void addInnerElement(AbstractXHtmlElement* element, ThreadContext* ctx) throw() ;
	ArrayList<AbstractXHtmlElement>* getInnerElements(ThreadContext* ctx) throw() ;
	void addAttribute(XHtmlAttribute* attr, ThreadContext* ctx) throw() ;
	ArrayList<XHtmlAttribute>* getAttributes(ThreadContext* ctx) throw() ;
	String* getTagName(ThreadContext* ctx) throw() ;
	void setTagName(String* tagName, ThreadContext* ctx);
	String* toString(ThreadContext* ctx) throw() ;
	AbstractXHtmlElement::ElementType getElementType(ThreadContext* ctx) throw()  final;
private:
	bool isSingleEnd(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_WEB_HTMLXML_XMLTAGBASE_H_ */
