#ifndef ALINOUS_WEB_HTMLXML_MODULE_STATICHTMLPART_H_
#define ALINOUS_WEB_HTMLXML_MODULE_STATICHTMLPART_H_
namespace alinous {namespace compile {namespace analyse {
class SrcAnalyseContext;}}}

namespace alinous {namespace runtime {namespace engine {
class ScriptMachine;}}}

namespace java {namespace io {
class Writer;}}

namespace java {namespace lang {
class StringBuilder;}}

namespace alinous {namespace web {namespace htmlxml {namespace module {
class AbstractSerializedHtmlPart;}}}}

namespace java {namespace io {
class IOException;}}

namespace alinous {namespace db {namespace table {
class DatabaseException;}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace web {namespace htmlxml {namespace module {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::IOException;
using ::java::io::Writer;
using ::alinous::compile::analyse::SrcAnalyseContext;
using ::alinous::db::table::DatabaseException;
using ::alinous::runtime::engine::ScriptMachine;
using ::alinous::system::AlinousException;



class StaticHtmlPart final : public AbstractSerializedHtmlPart {
public:
	StaticHtmlPart(const StaticHtmlPart& base) = default;
public:
	StaticHtmlPart(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~StaticHtmlPart() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	StringBuilder* buff;
	String* text;
public:
	void add(String* str, ThreadContext* ctx) throw() ;
	String* toString(ThreadContext* ctx) throw() ;
	void prepare(SrcAnalyseContext* context, ThreadContext* ctx) throw()  final;
	void execute(ScriptMachine* machine, Writer* writer, bool debug, ThreadContext* ctx) final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}

#endif /* end of ALINOUS_WEB_HTMLXML_MODULE_STATICHTMLPART_H_ */
