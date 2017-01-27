#ifndef ALINOUS_REMOTE_MONITOR_COMMAND_MINITORCOMMANDREADER_H_
#define ALINOUS_REMOTE_MONITOR_COMMAND_MINITORCOMMANDREADER_H_
namespace alinous {namespace remote {namespace monitor {namespace command {
class AbstractMonitorCommand;}}}}

namespace java {namespace io {
class InputStream;}}

namespace alinous {namespace remote {namespace monitor {namespace command {
class FinishConnectionCommand;}}}}

namespace alinous {namespace remote {namespace monitor {namespace command {
class TerminateCommand;}}}}

namespace alinous {namespace remote {namespace monitor {namespace command {
class VoidCommand;}}}}

namespace alinous {namespace remote {namespace monitor {namespace command {
class MonitorConnectCommand;}}}}

namespace alinous {namespace remote {namespace monitor {namespace command {namespace commitId {
class GetMaxCommitIdCommand;}}}}}

namespace alinous {namespace remote {namespace monitor {namespace command {namespace commitId {
class NewCommitIdCommand;}}}}}

namespace alinous {namespace remote {namespace monitor {namespace command {
class GetRegionNodeInfoCommand;}}}}

namespace alinous {namespace remote {namespace monitor {namespace command {namespace commitId {
class NewTransactionCommand;}}}}}

namespace alinous {namespace remote {namespace monitor {namespace command {namespace commitId {
class ReportSchemaVersionCommand;}}}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace java {namespace io {
class IOException;}}

namespace alinous {namespace remote {namespace socket {
class NetworkBinalyUtils;}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace remote {namespace monitor {namespace command {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::IOException;
using ::java::io::InputStream;
using ::alinous::remote::monitor::command::commitId::GetMaxCommitIdCommand;
using ::alinous::remote::monitor::command::commitId::NewCommitIdCommand;
using ::alinous::remote::monitor::command::commitId::NewTransactionCommand;
using ::alinous::remote::monitor::command::commitId::ReportSchemaVersionCommand;
using ::alinous::remote::socket::NetworkBinalyUtils;
using ::alinous::system::AlinousException;



class MinitorCommandReader final : public virtual IObject {
public:
	MinitorCommandReader(const MinitorCommandReader& base) = default;
public:
	MinitorCommandReader(ThreadContext* ctx) throw()  : IObject(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~MinitorCommandReader() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	static AbstractMonitorCommand* readFromStream(InputStream* stream, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_REMOTE_MONITOR_COMMAND_MINITORCOMMANDREADER_H_ */
