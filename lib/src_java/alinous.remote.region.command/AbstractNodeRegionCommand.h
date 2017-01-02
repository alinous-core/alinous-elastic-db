#ifndef ALINOUS_REMOTE_REGION_COMMAND_ABSTRACTNODEREGIONCOMMAND_H_
#define ALINOUS_REMOTE_REGION_COMMAND_ABSTRACTNODEREGIONCOMMAND_H_
namespace alinous {namespace remote {namespace region {namespace command {
class AbstractNodeRegionCommand;}}}}

namespace alinous {namespace net {
class AlinousSocket;}}

namespace java {namespace io {
class OutputStream;}}

namespace java {namespace io {
class InputStream;}}

namespace alinous {namespace remote {namespace region {
class NodeRegionServer;}}}

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

namespace alinous {namespace remote {namespace region {namespace command {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::BufferedOutputStream;
using ::java::io::IOException;
using ::java::io::InputStream;
using ::java::io::OutputStream;
using ::alinous::net::AlinousSocket;
using ::alinous::remote::region::NodeRegionServer;
using ::alinous::system::AlinousException;



class AbstractNodeRegionCommand : public virtual IObject {
public:
	AbstractNodeRegionCommand(const AbstractNodeRegionCommand& base) = default;
public:
	AbstractNodeRegionCommand(ThreadContext* ctx) throw()  : IObject(ctx), type(0)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~AbstractNodeRegionCommand() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	int type;
public:
	constexpr static const int TYPE_VOID{0};
	constexpr static const int TYPE_FINISH{1};
	constexpr static const int TYPE_CONNECT{2};
	constexpr static const int TYPE_TERMINATE{404};
public:
	int getType(ThreadContext* ctx) throw() ;
	AbstractNodeRegionCommand* sendCommand(AlinousSocket* socket, ThreadContext* ctx);
	virtual void executeOnServer(NodeRegionServer* nodeRegionServer, BufferedOutputStream* outStream, ThreadContext* ctx) = 0;
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

#endif /* end of ALINOUS_REMOTE_REGION_COMMAND_ABSTRACTNODEREGIONCOMMAND_H_ */
