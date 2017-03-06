#ifndef ALINOUS_REMOTE_MONITOR_CLIENT_COMMAND_ABSTRACTMONITORCOMMAND_H_
#define ALINOUS_REMOTE_MONITOR_CLIENT_COMMAND_ABSTRACTMONITORCOMMAND_H_
namespace alinous {namespace remote {namespace monitor {namespace client {namespace command {
class AbstractMonitorCommand;}}}}}

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

namespace java {namespace lang {
class Throwable;}}

namespace java {namespace util {
template <typename  T> class List;}}

namespace alinous {namespace remote {namespace socket {
class NetworkBinaryBuffer;}}}

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

namespace alinous {namespace remote {namespace monitor {namespace client {namespace command {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::BufferedOutputStream;
using ::java::io::IOException;
using ::java::io::InputStream;
using ::java::io::OutputStream;
using ::java::util::ArrayList;
using ::java::util::List;
using ::alinous::net::AlinousSocket;
using ::alinous::remote::monitor::TransactionMonitorServer;
using ::alinous::remote::socket::NetworkBinaryBuffer;
using ::alinous::system::AlinousException;



class AbstractMonitorCommand : public virtual IObject {
public:
	AbstractMonitorCommand(const AbstractMonitorCommand& base) = default;
public:
	AbstractMonitorCommand(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~AbstractMonitorCommand() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	int type;
	List<String>* errorMessage;
	int retCode;
public:
	constexpr static const int TYPE_VOID{0};
	constexpr static const int TYPE_FINISH{1};
	constexpr static const int TYPE_CONNECT{2};
	constexpr static const int TYPE_GET_MAX_COMMIT_ID{101};
	constexpr static const int TYPE_NEW_MAX_COMMIT_ID{102};
	constexpr static const int TYPE_GET_REGION_INFO{103};
	constexpr static const int TYPE_NEW_TRANSACTION{104};
	constexpr static const int TYPE_REPORT_SCHEMA_UPDATED{105};
	constexpr static const int TYPE_REPORT_CLUSTER_UPDATED{106};
	constexpr static const int TYPE_TERMINATE{404};
public:
	int getType(ThreadContext* ctx) throw() ;
	AbstractMonitorCommand* sendCommand(AlinousSocket* socket, ThreadContext* ctx);
	virtual void executeOnServer(TransactionMonitorServer* monitorServer, BufferedOutputStream* outStream, ThreadContext* ctx) = 0;
	virtual void readFromStream(InputStream* stream, int remain, ThreadContext* ctx) = 0;
	bool hasError(ThreadContext* ctx) throw() ;
	List<String>* getErrorMessage(ThreadContext* ctx) throw() ;
	virtual void writeByteStream(OutputStream* out, ThreadContext* ctx) = 0;
	void handleError(Throwable* e, ThreadContext* ctx) throw() ;
	void writeErrorByteStream(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() ;
	void readErrorFromStream(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}}

#endif /* end of ALINOUS_REMOTE_MONITOR_CLIENT_COMMAND_ABSTRACTMONITORCOMMAND_H_ */
