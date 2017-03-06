#ifndef ALINOUS_WEB_HTMLXML_ABSTRACTXHTMLELEMENT_H_
#define ALINOUS_WEB_HTMLXML_ABSTRACTXHTMLELEMENT_H_
namespace alinous {namespace web {namespace htmlxml {namespace module {
class SerializeContext;}}}}

namespace alinous {namespace runtime {namespace engine {
class ScriptMachine;}}}

namespace alinous {namespace web {namespace parse {namespace htmlxml {
class Token;}}}}

namespace alinous {namespace web {namespace htmlxml {
class AbstractXHtmlElement;}}}

namespace alinous {namespace web {namespace htmlxml {namespace inner {
class IHtmlStringPart;}}}}

namespace alinous {namespace db {namespace table {
class DatabaseException;}}}

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
using ::alinous::db::table::DatabaseException;
using ::alinous::runtime::engine::ScriptMachine;
using ::alinous::system::AlinousException;
using ::alinous::web::htmlxml::inner::IHtmlStringPart;
using ::alinous::web::htmlxml::module::SerializeContext;
using ::alinous::web::parse::htmlxml::Token;

class __AbstractXHtmlElement__ElementType : public EnumBase {
public:
	__AbstractXHtmlElement__ElementType() = default;
	constexpr __AbstractXHtmlElement__ElementType(const EnumBase& base) : EnumBase(base) {}
	constexpr explicit __AbstractXHtmlElement__ElementType(const int ord) : EnumBase(ord) {}

	static constexpr EnumBase __DEFAULT_NULL{0};
	static constexpr EnumBase  HtmlDocType{1};
	static constexpr EnumBase  XmlHeader{2};
	static constexpr EnumBase  BodyText{3};
	static constexpr EnumBase  Attribute{4};
	static constexpr EnumBase  Comment{5};
	static constexpr EnumBase  DqString{6};
	static constexpr EnumBase  SqString{7};
	static constexpr EnumBase  Tag{8};
};


class AbstractXHtmlElement : public virtual IObject {
public:
	class ElementType : public __AbstractXHtmlElement__ElementType {
	public:
		ElementType() = default;constexpr ElementType(const EnumBase& base) :  __AbstractXHtmlElement__ElementType(base) {};
	};
public:
	AbstractXHtmlElement(const AbstractXHtmlElement& base) = default;
public:
	AbstractXHtmlElement(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~AbstractXHtmlElement() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	ArrayList<IHtmlStringPart>* parts;
	bool isDynamic;
	int line;
	int startPosition;
	int endLine;
	int _endPosition;
public:
	virtual AbstractXHtmlElement::ElementType getElementType(ThreadContext* ctx) throw()  = 0;
	virtual void serialize(SerializeContext* context, ThreadContext* ctx) = 0;
	virtual bool isDinamicAll(ThreadContext* ctx) throw()  = 0;
	virtual String* execute(ScriptMachine* machine, bool debug, ThreadContext* ctx) = 0;
	void position(Token* start, Token* end, ThreadContext* ctx) throw() ;
	void position(AbstractXHtmlElement* start, AbstractXHtmlElement* end, ThreadContext* ctx) throw() ;
	void position(AbstractXHtmlElement* start, Token* end, ThreadContext* ctx) throw() ;
	void position(Token* start, AbstractXHtmlElement* end, ThreadContext* ctx) throw() ;
	int getLine(ThreadContext* ctx) throw() ;
	void setLine(int line, ThreadContext* ctx) throw() ;
	int getStartPosition(ThreadContext* ctx) throw() ;
	void setStartPosition(int startPosition, ThreadContext* ctx) throw() ;
	int getEndLine(ThreadContext* ctx) throw() ;
	void setEndLine(int endLine, ThreadContext* ctx) throw() ;
	int get_endPosition(ThreadContext* ctx) throw() ;
	void set_endPosition(int _endPosition, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_WEB_HTMLXML_ABSTRACTXHTMLELEMENT_H_ */
