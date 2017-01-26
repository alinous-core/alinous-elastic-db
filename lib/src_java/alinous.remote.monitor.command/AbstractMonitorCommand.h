#ifndef ALINOUS_REMOTE_MONITOR_COMMAND_ABSTRACTMONITORCOMMAND_H_
#define ALINOUS_REMOTE_MONITOR_COMMAND_ABSTRACTMONITORCOMMAND_H_
namespace alinous {namespace remote {namespace monitor {namespace command {
class AbstractMonitorCommand;}}}}

namespace alinous {namespace net {
class AlinousSocket;}}

namespace java {namespace io {
class OutputStream;}}

namespace java {namespace io {
class InputStream;}}

namespace alinous {namespace remote {namespace monitor {
class TransactionMonitorServer;}}}

namespace java {namespace io {
class BufferedOutputStream;}}

namespace java {namespace io {
class IOException;}}

namespace alinous {namespace system {
class AlinousException;}}

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
using ::java::io::BufferedOutputStream;
using ::java::io::IOException;
using ::java::io::InputStream;
using ::java::io::OutputStream;
using ::alinous::net::AlinousSocket;
using ::alinous::remote::monitor::TransactionMonitorServer;
using ::alinous::system::AlinousException;



class AbstractMonitorCommand : public virtual IObject {
public:
	AbstractMonitorCommand(const AbstractMonitorCommand& base) = default;
public:
	AbstractMonitorCommand(ThreadContext* ctx) throw()  : IObject(ctx), type(0), retCode(0)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~AbstractMonitorCommand() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	int type;
	int retCode;
public:
	constexpr static const int TYPE_VOID{0};
	constexpr static const int TYPE_FINISH{1};
	constexpr static const int TYPE_CONNECT{2};
	constexpr static const int TYPE_GET_MAX_COMMIT_ID{101};
	constexpr static const int TYPE_NEW_MAX_COMMIT_ID{102};
	constexpr static const int TYPE_GET_REGION_INFO{103};
	constexpr static const int TYPE_NEW_TRANSACTION{104};
	constexpr static const int TYPE_TERMINATE{404};
public:
	int getType(ThreadContext* ctx) throw() ;
	AbstractMonitorCommand* sendCommand(AlinousSocket* socket, ThreadContext* ctx);
	virtual void executeOnServer(TransactionMonitorServer* monitorServer, BufferedOutputStream* outStream, ThreadContext* ctx) = 0;
	virtual void readFromStream(InputStream* stream, int remain, ThreadContext* ctx) = 0;
	virtual void writeByteStream(OutputStream* out, ThreadContext* ctx) = 0;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_REMOTE_MONITOR_COMMAND_ABSTRACTMONITORCOMMAND_H_ */
