#ifndef ALINOUS_WEB_HTMLXML_INNER_STATICHTMLSTRING_H_
#define ALINOUS_WEB_HTMLXML_INNER_STATICHTMLSTRING_H_
namespace alinous {namespace runtime {namespace engine {
class ScriptMachine;}}}

namespace alinous {namespace web {namespace htmlxml {namespace inner {
class IHtmlStringPart;}}}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace web {namespace htmlxml {namespace inner {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::runtime::engine::ScriptMachine;



class StaticHtmlString final : public IHtmlStringPart {
public:
	StaticHtmlString(const StaticHtmlString& base) = default;
public:
	StaticHtmlString(String* data, ThreadContext* ctx) throw() ;
	void __construct_impl(String* data, ThreadContext* ctx) throw() ;
	virtual ~StaticHtmlString() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	String* data;
public:
	String* toString(ThreadContext* ctx) throw() ;
	String* execute(ScriptMachine* machine, bool debug, ThreadContext* ctx) throw()  final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_WEB_HTMLXML_INNER_STATICHTMLSTRING_H_ */
