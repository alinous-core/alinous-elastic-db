#ifndef ALINOUS_RUNTIME_ENGINE_DEBUGGER_SERVER_FILEBREAKPOINTCONTAINER_H_
#define ALINOUS_RUNTIME_ENGINE_DEBUGGER_SERVER_FILEBREAKPOINTCONTAINER_H_
namespace alinous {namespace runtime {namespace engine {namespace debugger {namespace server {
class ServerBreakPoint;}}}}}

namespace java {namespace util {
template <typename  T> class Iterator;}}

namespace java {namespace lang {
class StringBuffer;}}

namespace java {namespace util {
template <typename  T> class List;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace runtime {namespace engine {namespace debugger {namespace server {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::ArrayList;
using ::java::util::Iterator;
using ::java::util::List;



class FileBreakpointContainer final : public virtual IObject {
public:
	FileBreakpointContainer(const FileBreakpointContainer& base) = default;
public:
	FileBreakpointContainer(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~FileBreakpointContainer() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	List<ServerBreakPoint>* breakpoints;
public:
	void addBreakpoint(ServerBreakPoint* breakpoint, ThreadContext* ctx) throw() ;
	void removeBreakpoint(int line, ThreadContext* ctx) throw() ;
	Iterator<ServerBreakPoint>* iterator(ThreadContext* ctx) throw() ;
	void clear(ThreadContext* ctx) throw() ;
	String* toString(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}}

#endif /* end of ALINOUS_RUNTIME_ENGINE_DEBUGGER_SERVER_FILEBREAKPOINTCONTAINER_H_ */
