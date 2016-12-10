#ifndef ALINOUS_REMOTE_MONITOR_COMMAND_FINISHCONNECTIONCOMMAND_H_
#define ALINOUS_REMOTE_MONITOR_COMMAND_FINISHCONNECTIONCOMMAND_H_
namespace alinous {namespace remote {namespace monitor {namespace command {
class AbstractMonitorCommand;}}}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace remote {namespace monitor {namespace command {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;



class FinishConnectionCommand final : public AbstractMonitorCommand {
public:
	FinishConnectionCommand(const FinishConnectionCommand& base) = default;
public:
	FinishConnectionCommand(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~FinishConnectionCommand() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	void sendCommand(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_REMOTE_MONITOR_COMMAND_FINISHCONNECTIONCOMMAND_H_ */
