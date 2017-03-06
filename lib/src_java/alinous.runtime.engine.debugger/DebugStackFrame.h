#ifndef ALINOUS_RUNTIME_ENGINE_DEBUGGER_DEBUGSTACKFRAME_H_
#define ALINOUS_RUNTIME_ENGINE_DEBUGGER_DEBUGSTACKFRAME_H_
namespace alinous {namespace runtime {namespace engine {
class MainStackFrame;}}}

namespace alinous {namespace compile {
class AbstractSrcElement;}}

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
using ::alinous::compile::AbstractSrcElement;
using ::alinous::runtime::engine::MainStackFrame;



class DebugStackFrame final : public virtual IObject {
public:
	DebugStackFrame(const DebugStackFrame& base) = default;
public:
	DebugStackFrame(MainStackFrame* frame, bool peek, long long stackId, ThreadContext* ctx) throw() ;
	void __construct_impl(MainStackFrame* frame, bool peek, long long stackId, ThreadContext* ctx) throw() ;
	virtual ~DebugStackFrame() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	int line;
	String* fileName;
	bool peek;
	long long stackId;
	MainStackFrame* frame;
public:
	String* getFileName(ThreadContext* ctx) throw() ;
	void setFileName(String* fileName, ThreadContext* ctx) throw() ;
	int getLine(ThreadContext* ctx) throw() ;
	void setLine(int line, ThreadContext* ctx) throw() ;
	bool isPeek(ThreadContext* ctx) throw() ;
	void setPeek(bool peek, ThreadContext* ctx) throw() ;
	long long getStackId(ThreadContext* ctx) throw() ;
	void setStackId(long long stackId, ThreadContext* ctx) throw() ;
	MainStackFrame* getFrame(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}

#endif /* end of ALINOUS_RUNTIME_ENGINE_DEBUGGER_DEBUGSTACKFRAME_H_ */
