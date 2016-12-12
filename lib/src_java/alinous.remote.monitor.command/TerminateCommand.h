#ifndef ALINOUS_REMOTE_MONITOR_COMMAND_TERMINATECOMMAND_H_
#define ALINOUS_REMOTE_MONITOR_COMMAND_TERMINATECOMMAND_H_
namespace java {namespace io {
class InputStream;}}

namespace java {namespace io {
class OutputStream;}}

namespace java {namespace nio {
class ByteBuffer;}}

namespace java {namespace io {
class BufferedOutputStream;}}

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
using ::java::io::BufferedOutputStream;
using ::java::io::IOException;
using ::java::io::InputStream;
using ::java::io::OutputStream;
using ::java::nio::ByteBuffer;



class TerminateCommand final : public AbstractMonitorCommand {
public:
	TerminateCommand(const TerminateCommand& base) = default;
public:
	TerminateCommand(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~TerminateCommand() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	void readFromStream(InputStream* stream, ThreadContext* ctx) final;
	void writeByteStream(OutputStream* out, ThreadContext* ctx) final;
	void executeOnServer(BufferedOutputStream* outStream, ThreadContext* ctx) final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_REMOTE_MONITOR_COMMAND_TERMINATECOMMAND_H_ */
