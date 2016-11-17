#ifndef ALINOUS_WEB_HTMLXML_MODULE_DYNAMICTAG_H_
#define ALINOUS_WEB_HTMLXML_MODULE_DYNAMICTAG_H_
namespace alinous {namespace web {namespace htmlxml {
class XMLTagBase;}}}

namespace alinous {namespace web {namespace htmlxml {namespace module {
class SerializeContext;}}}}

namespace alinous {namespace web {namespace htmlxml {
class XHtmlAttribute;}}}

namespace alinous {namespace web {namespace htmlxml {
class AbstractXHtmlElement;}}}

namespace alinous {namespace web {namespace htmlxml {
class AbstractXHtmlAttributeValue;}}}

namespace alinous {namespace web {namespace htmlxml {namespace module {
class DynamicExecutableAttributeValue;}}}}

namespace alinous {namespace compile {namespace analyse {
class SrcAnalyseContext;}}}

namespace java {namespace util {
template <typename  T> class Stack;}}

namespace alinous {namespace web {namespace htmlxml {namespace module {
class AbstractSerializedHtmlPart;}}}}

namespace alinous {namespace runtime {namespace engine {
class ScriptMachine;}}}

namespace java {namespace io {
class Writer;}}

namespace alinous {namespace runtime {namespace dom {
class IAlinousVariable;}}}

namespace alinous {namespace web {namespace htmlxml {namespace inner {
class IHtmlStringPart;}}}}

namespace java {namespace io {
class IOException;}}

namespace alinous {namespace db {namespace table {
class DatabaseException;}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace alinous {namespace web {namespace htmlxml {
class AlinousAttrs;}}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace web {namespace htmlxml {namespace module {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::IOException;
using ::java::io::Writer;
using ::java::util::ArrayList;
using ::java::util::Stack;
using ::alinous::compile::analyse::SrcAnalyseContext;
using ::alinous::db::table::DatabaseException;
using ::alinous::runtime::dom::IAlinousVariable;
using ::alinous::runtime::engine::ScriptMachine;
using ::alinous::system::AlinousException;
using ::alinous::web::htmlxml::AbstractXHtmlAttributeValue;
using ::alinous::web::htmlxml::AbstractXHtmlElement;
using ::alinous::web::htmlxml::AlinousAttrs;
using ::alinous::web::htmlxml::XHtmlAttribute;
using ::alinous::web::htmlxml::XMLTagBase;
using ::alinous::web::htmlxml::inner::IHtmlStringPart;



class DynamicTag final : public AbstractSerializedHtmlPart {
public:
	DynamicTag(const DynamicTag& base) = default;
public:
	DynamicTag(XMLTagBase* tagbase, ThreadContext* ctx);
	void __construct_impl(XMLTagBase* tagbase, ThreadContext* ctx);
	virtual ~DynamicTag() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	ArrayList<IHtmlStringPart>* nameParts;
	Stack<AbstractSerializedHtmlPart>* attrstack;
	Stack<AbstractSerializedHtmlPart>* innerStack;
	DynamicExecutableAttributeValue* dynValue;
	XHtmlAttribute* alnsIf;
	XHtmlAttribute* alnsInner;
	XHtmlAttribute* alnsTagId;
	XHtmlAttribute* alnsTarget;
	XHtmlAttribute* alnsIterate;
	XHtmlAttribute* alnsVariable;
	XHtmlAttribute* alnsIgnoreself;
	XHtmlAttribute* alnsMsgTarget;
	XHtmlAttribute* alnsForm;
	XHtmlAttribute* alnsValidate;
	XHtmlAttribute* alnsValidateif;
	XHtmlAttribute* alnsRegExp;
	XHtmlAttribute* alnsParam;
	XHtmlAttribute* alnsType;
public:
	void validate(ThreadContext* ctx) throw() ;
	void prepare(SrcAnalyseContext* context, ThreadContext* ctx) throw()  final;
	void execute(ScriptMachine* machine, Writer* writer, bool debug, ThreadContext* ctx) final;
	String* toString(ThreadContext* ctx) throw() ;
private:
	void setAlinoutAttributes(XHtmlAttribute* attr, ThreadContext* ctx);
	void writeInnerElements(ScriptMachine* machine, Writer* writer, bool debug, ThreadContext* ctx);
	void writeTag(ScriptMachine* machine, Writer* writer, bool debug, ThreadContext* ctx);
	void writeEndTag(ScriptMachine* machine, Writer* writer, bool debug, ThreadContext* ctx);
	void writeName(ScriptMachine* machine, Writer* writer, bool debug, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_WEB_HTMLXML_MODULE_DYNAMICTAG_H_ */
