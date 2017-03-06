#ifndef ALINOUS_WEB_HTMLXML_MODULE_DYNAMICEXECUTABLEATTRIBUTEVALUE_H_
#define ALINOUS_WEB_HTMLXML_MODULE_DYNAMICEXECUTABLEATTRIBUTEVALUE_H_
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

namespace alinous {namespace runtime {namespace dom {
class IAlinousVariable;}}}

namespace alinous {namespace runtime {namespace engine {
class ScriptMachine;}}}

namespace alinous {namespace compile {namespace expression {
class IExpression;}}}

namespace alinous {namespace db {namespace table {
class DatabaseException;}}}

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
using ::java::io::StringReader;
using ::alinous::compile::AlinousPlusParser;
using ::alinous::compile::ParseException;
using ::alinous::compile::analyse::SrcAnalyseContext;
using ::alinous::compile::expression::IExpression;
using ::alinous::db::table::DatabaseException;
using ::alinous::runtime::dom::IAlinousVariable;
using ::alinous::runtime::engine::ScriptMachine;
using ::alinous::system::AlinousException;



class DynamicExecutableAttributeValue final : public virtual IObject {
public:
	DynamicExecutableAttributeValue(const DynamicExecutableAttributeValue& base) = default;
public:
	DynamicExecutableAttributeValue(String* value, ThreadContext* ctx);
	void __construct_impl(String* value, ThreadContext* ctx);
	virtual ~DynamicExecutableAttributeValue() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	IExpression* exp;
public:
	void prepare(SrcAnalyseContext* context, ThreadContext* ctx) throw() ;
	IAlinousVariable* execute(ScriptMachine* machine, bool debug, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}

#endif /* end of ALINOUS_WEB_HTMLXML_MODULE_DYNAMICEXECUTABLEATTRIBUTEVALUE_H_ */
