#ifndef ALINOUS_WEB_HTMLXML_INNER_HTMLPROGRAMSTRING_H_
#define ALINOUS_WEB_HTMLXML_INNER_HTMLPROGRAMSTRING_H_
namespace java {namespace io {
class StringReader;}}

namespace alinous {namespace compile {
class AlinousPlusParser;}}

namespace alinous {namespace system {
class AlinousException;}}

namespace alinous {namespace compile {
class ParseException;}}

namespace alinous {namespace runtime {namespace engine {
class ScriptMachine;}}}

namespace alinous {namespace runtime {namespace dom {
class IAlinousVariable;}}}

namespace alinous {namespace compile {namespace expression {
class IExpression;}}}

namespace alinous {namespace web {namespace htmlxml {namespace inner {
class IHtmlStringPart;}}}}

namespace alinous {namespace db {namespace table {
class DatabaseException;}}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace web {namespace htmlxml {namespace inner {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::StringReader;
using ::alinous::compile::AlinousPlusParser;
using ::alinous::compile::ParseException;
using ::alinous::compile::expression::IExpression;
using ::alinous::db::table::DatabaseException;
using ::alinous::runtime::dom::IAlinousVariable;
using ::alinous::runtime::engine::ScriptMachine;
using ::alinous::system::AlinousException;



class HTmlProgramString final : public IHtmlStringPart {
public:
	HTmlProgramString(const HTmlProgramString& base) = default;
public:
	HTmlProgramString(String* prog, ThreadContext* ctx);
	void __construct_impl(String* prog, ThreadContext* ctx);
	virtual ~HTmlProgramString() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	IExpression* exp;
	String* prog;
public:
	String* toString(ThreadContext* ctx) throw() ;
	String* execute(ScriptMachine* machine, bool debug, ThreadContext* ctx) final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}

#endif /* end of ALINOUS_WEB_HTMLXML_INNER_HTMLPROGRAMSTRING_H_ */
