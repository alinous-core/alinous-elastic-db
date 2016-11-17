#ifndef ALINOUS_WEB_HTMLXML_HTMLDOCTYPE_H_
#define ALINOUS_WEB_HTMLXML_HTMLDOCTYPE_H_
namespace alinous {namespace web {namespace htmlxml {namespace module {
class SerializeContext;}}}}

namespace alinous {namespace runtime {namespace engine {
class ScriptMachine;}}}

namespace alinous {namespace web {namespace htmlxml {
class AbstractXHtmlElement;}}}

namespace java {namespace lang {
class StringBuffer;}}

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
using ::java::util::ArrayList;
using ::alinous::db::table::DatabaseException;
using ::alinous::runtime::engine::ScriptMachine;
using ::alinous::system::AlinousException;
using ::alinous::web::htmlxml::module::SerializeContext;



class HtmlDocType final : public AbstractXHtmlElement {
public:
	HtmlDocType(const HtmlDocType& base) = default;
public:
	HtmlDocType(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~HtmlDocType() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	ArrayList<AbstractXHtmlElement>* elements;
public:
	void serialize(SerializeContext* context, ThreadContext* ctx) throw()  final;
	String* execute(ScriptMachine* machine, bool debug, ThreadContext* ctx) final;
	void addElement(AbstractXHtmlElement* element, ThreadContext* ctx) throw() ;
	ArrayList<AbstractXHtmlElement>* getElements(ThreadContext* ctx) throw() ;
	String* toString(ThreadContext* ctx) throw() ;
	AbstractXHtmlElement::ElementType getElementType(ThreadContext* ctx) throw()  final;
	bool isDinamicAll(ThreadContext* ctx) throw()  final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_WEB_HTMLXML_HTMLDOCTYPE_H_ */
