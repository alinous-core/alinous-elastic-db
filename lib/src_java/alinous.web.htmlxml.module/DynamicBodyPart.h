#ifndef ALINOUS_WEB_HTMLXML_MODULE_DYNAMICBODYPART_H_
#define ALINOUS_WEB_HTMLXML_MODULE_DYNAMICBODYPART_H_
namespace java {namespace io {
class StringReader;}}

namespace alinous {namespace compile {
class AlinousPlusParser;}}

namespace alinous {namespace system {
class AlinousException;}}

namespace alinous {namespace compile {
class ParseException;}}

namespace alinous {namespace compile {namespace analyse {
class SrcAnalyseContext;}}}

namespace alinous {namespace runtime {namespace engine {
class ScriptMachine;}}}

namespace java {namespace io {
class Writer;}}

namespace alinous {namespace runtime {namespace dom {
class IAlinousVariable;}}}

namespace alinous {namespace compile {namespace expression {
class IExpression;}}}

namespace alinous {namespace web {namespace htmlxml {namespace module {
class AbstractSerializedHtmlPart;}}}}

namespace java {namespace io {
class IOException;}}

namespace alinous {namespace db {namespace table {
class DatabaseException;}}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace web {namespace htmlxml {namespace module {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::IOException;
using ::java::io::StringReader;
using ::java::io::Writer;
using ::alinous::compile::AlinousPlusParser;
using ::alinous::compile::ParseException;
using ::alinous::compile::analyse::SrcAnalyseContext;
using ::alinous::compile::expression::IExpression;
using ::alinous::db::table::DatabaseException;
using ::alinous::runtime::dom::IAlinousVariable;
using ::alinous::runtime::engine::ScriptMachine;
using ::alinous::system::AlinousException;



class DynamicBodyPart final : public AbstractSerializedHtmlPart {
public:
	DynamicBodyPart(const DynamicBodyPart& base) = default;
public:
	DynamicBodyPart(String* progCode, ThreadContext* ctx);
	void __construct_impl(String* progCode, ThreadContext* ctx);
	virtual ~DynamicBodyPart() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	IExpression* exp;
public:
	String* toString(ThreadContext* ctx) throw() ;
	void prepare(SrcAnalyseContext* context, ThreadContext* ctx) throw()  final;
	void execute(ScriptMachine* machine, Writer* writer, bool debug, ThreadContext* ctx) final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_WEB_HTMLXML_MODULE_DYNAMICBODYPART_H_ */
