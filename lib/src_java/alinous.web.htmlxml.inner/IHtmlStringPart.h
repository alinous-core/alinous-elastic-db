#ifndef ALINOUS_WEB_HTMLXML_INNER_IHTMLSTRINGPART_H_
#define ALINOUS_WEB_HTMLXML_INNER_IHTMLSTRINGPART_H_
namespace alinous {namespace runtime {namespace engine {
class ScriptMachine;}}}

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

namespace alinous {namespace web {namespace htmlxml {namespace inner {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::db::table::DatabaseException;
using ::alinous::runtime::engine::ScriptMachine;
using ::alinous::system::AlinousException;



class IHtmlStringPart : public virtual IObject {
public:
	IHtmlStringPart(const IHtmlStringPart& base) = default;
public:
	IHtmlStringPart(ThreadContext* ctx) throw()  : IObject(ctx), isDynamic(0)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~IHtmlStringPart() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	bool isDynamic;
public:
	virtual String* execute(ScriptMachine* machine, bool debug, ThreadContext* ctx) = 0;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_WEB_HTMLXML_INNER_IHTMLSTRINGPART_H_ */
