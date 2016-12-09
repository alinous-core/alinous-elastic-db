#ifndef ALINOUS_REMOTE_MONITOR_TERMINATECOMMAND_H_
#define ALINOUS_REMOTE_MONITOR_TERMINATECOMMAND_H_
namespace alinous {namespace remote {namespace monitor {
class AbstractMonitorCommand;}}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace remote {namespace monitor {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;



class TerminateCommand final : public AbstractMonitorCommand {
public:
	TerminateCommand(const TerminateCommand& base) = default;
public:
	TerminateCommand(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~TerminateCommand() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_REMOTE_MONITOR_TERMINATECOMMAND_H_ */
