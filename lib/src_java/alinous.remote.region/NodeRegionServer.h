#ifndef ALINOUS_REMOTE_REGION_NODEREGIONSERVER_H_
#define ALINOUS_REMOTE_REGION_NODEREGIONSERVER_H_
namespace alinous {namespace remote {namespace region {
class NodeReferenceManager;}}}

namespace alinous {namespace system {
class ISystemLog;}}

namespace alinous {namespace remote {namespace region {
class NodeRegionResponceActionFactory;}}}

namespace alinous {namespace remote {namespace socket {
class SocketServer;}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace remote {namespace region {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::remote::socket::SocketServer;
using ::alinous::system::ISystemLog;



class NodeRegionServer final : public virtual IObject {
public:
	NodeRegionServer(const NodeRegionServer& base) = default;
public:
	NodeRegionServer(int port, int maxthread, ThreadContext* ctx) throw() ;
	void __construct_impl(int port, int maxthread, ThreadContext* ctx) throw() ;
	virtual ~NodeRegionServer() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	int port;
	int maxthread;
	NodeReferenceManager* refs;
	SocketServer* socketServer;
private:
	static String* THREAD_NAME;
public:
	void start(ISystemLog* logger, ThreadContext* ctx) throw() ;
	void dispose(ThreadContext* ctx) throw() ;
	NodeReferenceManager* getRefs(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_REMOTE_REGION_NODEREGIONSERVER_H_ */
