#ifndef ALINOUS_COMPILE_DEBUGPROBE_H_
#define ALINOUS_COMPILE_DEBUGPROBE_H_
namespace alinous {namespace compile {
class DebugProbeSection;}}

namespace java {namespace util {
template <typename  T> class Iterator;}}

namespace alinous {namespace compile {
class DebugProbe;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace compile {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::ArrayList;
using ::java::util::Iterator;



class DebugProbe final : public virtual IObject {
public:
	DebugProbe(const DebugProbe& base) = default;
public:
	DebugProbe(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~DebugProbe() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	ArrayList<DebugProbeSection>* list;
private:
	static DebugProbe* inst;
public:
	DebugProbeSection* start(String* name, ThreadContext* ctx) throw() ;
	void print(ThreadContext* ctx) throw() ;
public:
	static DebugProbe* getInstance(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}

#endif /* end of ALINOUS_COMPILE_DEBUGPROBE_H_ */
