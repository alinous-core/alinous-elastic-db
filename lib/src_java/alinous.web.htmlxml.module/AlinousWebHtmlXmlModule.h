#ifndef ALINOUS_WEB_HTMLXML_MODULE_ALINOUSWEBHTMLXMLMODULE_H_
#define ALINOUS_WEB_HTMLXML_MODULE_ALINOUSWEBHTMLXMLMODULE_H_
namespace java {namespace io {
class File;}}

namespace java {namespace io {
class FileReader;}}

namespace alinous {namespace web {namespace parse {namespace htmlxml {
class HtmlXmlParser;}}}}

namespace java {namespace lang {
class Throwable;}}

namespace alinous {namespace web {namespace htmlxml {namespace module {
class SerializeContext;}}}}

namespace alinous {namespace compile {namespace analyse {
class SrcAnalyseContext;}}}

namespace java {namespace util {
template <typename  T> class Stack;}}

namespace alinous {namespace web {namespace htmlxml {namespace module {
class AbstractSerializedHtmlPart;}}}}

namespace java {namespace lang {
class StringBuffer;}}

namespace alinous {namespace runtime {namespace engine {
class ScriptMachine;}}}

namespace alinous {namespace runtime {
class AlinousModule;}}

namespace java {namespace io {
class Writer;}}

namespace alinous {namespace web {namespace htmlxml {
class HtmlTopObject;}}}

namespace java {namespace io {
class IOException;}}

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

namespace alinous {namespace web {namespace htmlxml {namespace module {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::File;
using ::java::io::FileReader;
using ::java::io::IOException;
using ::java::io::Writer;
using ::java::util::Stack;
using ::alinous::compile::analyse::SrcAnalyseContext;
using ::alinous::db::table::DatabaseException;
using ::alinous::runtime::AlinousModule;
using ::alinous::runtime::engine::ScriptMachine;
using ::alinous::system::AlinousException;
using ::alinous::web::htmlxml::HtmlTopObject;
using ::alinous::web::parse::htmlxml::HtmlXmlParser;



class AlinousWebHtmlXmlModule final : public virtual IObject {
public:
	AlinousWebHtmlXmlModule(const AlinousWebHtmlXmlModule& base) = default;
public:
	AlinousWebHtmlXmlModule(String* path, ThreadContext* ctx) throw() ;
	void __construct_impl(String* path, ThreadContext* ctx) throw() ;
	AlinousWebHtmlXmlModule(File* file, ThreadContext* ctx) throw() ;
	void __construct_impl(File* file, ThreadContext* ctx) throw() ;
	virtual ~AlinousWebHtmlXmlModule() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	File* file;
	HtmlTopObject* obj;
	Stack<AbstractSerializedHtmlPart>* stack;
public:
	void compile(ThreadContext* ctx);
	void prepare(SrcAnalyseContext* context, ThreadContext* ctx) throw() ;
	String* toStaticString(ThreadContext* ctx) throw() ;
	void execute(ScriptMachine* machine, AlinousModule* alnsModule, Writer* writer, bool debug, ThreadContext* ctx);
	File* getFile(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_WEB_HTMLXML_MODULE_ALINOUSWEBHTMLXMLMODULE_H_ */
