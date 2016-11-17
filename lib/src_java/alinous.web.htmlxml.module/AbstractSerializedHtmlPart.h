#ifndef ALINOUS_WEB_HTMLXML_MODULE_ABSTRACTSERIALIZEDHTMLPART_H_
#define ALINOUS_WEB_HTMLXML_MODULE_ABSTRACTSERIALIZEDHTMLPART_H_
namespace alinous {namespace compile {namespace analyse {
class SrcAnalyseContext;}}}

namespace alinous {namespace runtime {namespace engine {
class ScriptMachine;}}}

namespace java {namespace io {
class Writer;}}

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
using ::java::io::IOException;
using ::java::io::Writer;
using ::alinous::compile::analyse::SrcAnalyseContext;
using ::alinous::db::table::DatabaseException;
using ::alinous::runtime::engine::ScriptMachine;
using ::alinous::system::AlinousException;



class AbstractSerializedHtmlPart : public virtual IObject {
public:
	AbstractSerializedHtmlPart(const AbstractSerializedHtmlPart& base) = default;
public:
	AbstractSerializedHtmlPart(ThreadContext* ctx) throw()  : IObject(ctx), type(0)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~AbstractSerializedHtmlPart() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	int type;
public:
	constexpr static const int TYPE_DYNAMIC_BODY{0};
	constexpr static const int TYPE_DYNAMIC_TAG{1};
	constexpr static const int TYPE_STATIC_PART{2};
public:
	virtual void prepare(SrcAnalyseContext* context, ThreadContext* ctx) throw()  = 0;
	virtual void execute(ScriptMachine* machine, Writer* writer, bool debug, ThreadContext* ctx) = 0;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_WEB_HTMLXML_MODULE_ABSTRACTSERIALIZEDHTMLPART_H_ */
