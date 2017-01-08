#ifndef ALINOUS_REMOTE_MONITOR_NODEINFO_H_
#define ALINOUS_REMOTE_MONITOR_NODEINFO_H_
namespace alinous {namespace remote {namespace monitor {
class NodeInfo;}}}

namespace alinous {namespace db {
class AlinousDbException;}}

namespace java {namespace lang {
class NumberFormatException;}}

namespace alinous {namespace remote {namespace socket {
class NetworkBinaryBuffer;}}}

namespace alinous {namespace remote {namespace socket {
class ICommandData;}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace remote {namespace monitor {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::db::AlinousDbException;
using ::alinous::remote::socket::ICommandData;
using ::alinous::remote::socket::NetworkBinaryBuffer;



class NodeInfo final : public ICommandData, public virtual IObject {
public:
	NodeInfo(const NodeInfo& base) = default;
public:
	NodeInfo(ThreadContext* ctx) throw()  : IObject(ctx), ICommandData(ctx), host(nullptr), port(0)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~NodeInfo() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	String* host;
	int port;
public:
	String* getHost(ThreadContext* ctx) throw() ;
	void setHost(String* host, ThreadContext* ctx) throw() ;
	int getPort(ThreadContext* ctx) throw() ;
	void setPort(int port, ThreadContext* ctx) throw() ;
	NodeInfo* copy(ThreadContext* ctx) throw() ;
	void readData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw()  final;
	void writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw()  final;
public:
	static NodeInfo* parseUrl(String* url, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_REMOTE_MONITOR_NODEINFO_H_ */
