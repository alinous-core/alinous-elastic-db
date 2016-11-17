#ifndef ALINOUS_WEB_HTMLXML_BODYTEXT_H_
#define ALINOUS_WEB_HTMLXML_BODYTEXT_H_
namespace java {namespace lang {
class StringBuffer;}}

namespace alinous {namespace web {namespace htmlxml {namespace module {
class SerializeContext;}}}}

namespace alinous {namespace web {namespace htmlxml {namespace inner {
class IHtmlStringPart;}}}}

namespace alinous {namespace runtime {namespace engine {
class ScriptMachine;}}}

namespace alinous {namespace web {namespace parse {namespace htmlxml {
class Token;}}}}

namespace alinous {namespace web {namespace htmlxml {
class AbstractXHtmlElement;}}}

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
using ::alinous::web::parse::htmlxml::Token;



class BodyText final : public AbstractXHtmlElement {
public:
	BodyText(const BodyText& base) = default;
public:
	BodyText(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~BodyText() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	StringBuffer* body;
public:
	bool isDinamicAll(ThreadContext* ctx) throw()  final;
	void serialize(SerializeContext* context, ThreadContext* ctx) final;
	String* execute(ScriptMachine* machine, bool debug, ThreadContext* ctx) final;
	void addString(Token* token, ThreadContext* ctx) throw() ;
	void finishAdd(ThreadContext* ctx);
	String* getBody(ThreadContext* ctx) throw() ;
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

#endif /* end of ALINOUS_WEB_HTMLXML_BODYTEXT_H_ */
