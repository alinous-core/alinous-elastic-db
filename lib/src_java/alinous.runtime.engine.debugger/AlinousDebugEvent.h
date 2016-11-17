#ifndef ALINOUS_RUNTIME_ENGINE_DEBUGGER_ALINOUSDEBUGEVENT_H_
#define ALINOUS_RUNTIME_ENGINE_DEBUGGER_ALINOUSDEBUGEVENT_H_
namespace alinous {namespace runtime {namespace engine {namespace debugger {
class DebugThread;}}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace runtime {namespace engine {namespace debugger {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;



class AlinousDebugEvent final : public virtual IObject {
public:
	AlinousDebugEvent(const AlinousDebugEvent& base) = default;
public:
	AlinousDebugEvent(int eventType, int line, String* filePath, String* debugFilePath, DebugThread* thread, ThreadContext* ctx) throw() ;
	void __construct_impl(int eventType, int line, String* filePath, String* debugFilePath, DebugThread* thread, ThreadContext* ctx) throw() ;
	virtual ~AlinousDebugEvent() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	int eventType;
	int line;
	String* filePath;
	String* debugFilePath;
	DebugThread* thread;
public:
	constexpr static const int STARTED{0};
	constexpr static const int BEFORE_SENTENCE{1};
	constexpr static const int BEFORE_EXPRESSION{2};
public:
	int getEventType(ThreadContext* ctx) throw() ;
	String* getFilePath(ThreadContext* ctx) throw() ;
	int getLine(ThreadContext* ctx) throw() ;
	DebugThread* getThread(ThreadContext* ctx) throw() ;
	String* getDebugFilePath(ThreadContext* ctx) throw() ;
public:
	static String* forceUnixPath(String* path, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_RUNTIME_ENGINE_DEBUGGER_ALINOUSDEBUGEVENT_H_ */
