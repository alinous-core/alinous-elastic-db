#ifndef ALINOUS_REMOTE_MONITOR_VOIDCOMMAND_H_
#define ALINOUS_REMOTE_MONITOR_VOIDCOMMAND_H_
namespace alinous {namespace remote {namespace monitor {
class AbstractMonitorCommand;}}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace remote {namespace monitor {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;



class VoidCommand final : public AbstractMonitorCommand {
public:
	VoidCommand(const VoidCommand& base) = default;
public:
	VoidCommand(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~VoidCommand() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_REMOTE_MONITOR_VOIDCOMMAND_H_ */
