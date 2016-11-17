#ifndef ALINOUS_RUNTIME_ENGINE_DEBUGGER_SERVER_SERVERBREAKPOINT_H_
#define ALINOUS_RUNTIME_ENGINE_DEBUGGER_SERVER_SERVERBREAKPOINT_H_
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



class ServerBreakPoint final : public virtual IObject {
public:
	ServerBreakPoint(const ServerBreakPoint& base) = default;
public:
	ServerBreakPoint(String* filePath, int line, ThreadContext* ctx) throw() ;
	void __construct_impl(String* filePath, int line, ThreadContext* ctx) throw() ;
	ServerBreakPoint(String* source, ThreadContext* ctx) throw() ;
	void __construct_impl(String* source, ThreadContext* ctx) throw() ;
	virtual ~ServerBreakPoint() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	String* filePath;
	int line;
public:
	String* getFilePath(ThreadContext* ctx) throw() ;
	int getLine(ThreadContext* ctx) throw() ;
	String* toString(ThreadContext* ctx) throw() ;
	void setupFromString(String* source, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}}

#endif /* end of ALINOUS_RUNTIME_ENGINE_DEBUGGER_SERVER_SERVERBREAKPOINT_H_ */
