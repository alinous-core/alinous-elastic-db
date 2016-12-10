#ifndef ALINOUS_REMOTE_MONITOR_COMMAND_TERMINATECOMMAND_H_
#define ALINOUS_REMOTE_MONITOR_COMMAND_TERMINATECOMMAND_H_
namespace alinous {namespace net {
class AlinousSocket;}}

namespace java {namespace io {
class OutputStream;}}

namespace alinous {namespace remote {namespace monitor {namespace command {
class AbstractMonitorCommand;}}}}

namespace java {namespace io {
class IOException;}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace remote {namespace monitor {namespace command {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::IOException;
using ::java::io::OutputStream;
using ::alinous::net::AlinousSocket;



class TerminateCommand final : public AbstractMonitorCommand {
public:
	TerminateCommand(const TerminateCommand& base) = default;
public:
	TerminateCommand(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~TerminateCommand() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	void sendCommand(AlinousSocket* socket, ThreadContext* ctx);
	void toByteStream(OutputStream* out, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_REMOTE_MONITOR_COMMAND_TERMINATECOMMAND_H_ */
