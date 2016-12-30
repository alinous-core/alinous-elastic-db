#ifndef ALINOUS_REMOTE_MONITOR_NODEINFO_H_
#define ALINOUS_REMOTE_MONITOR_NODEINFO_H_
namespace alinous {namespace remote {namespace monitor {
class NodeInfo;}}}

namespace alinous {namespace db {
class AlinousDbException;}}

namespace java {namespace lang {
class NumberFormatException;}}

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



class NodeInfo final : public virtual IObject {
public:
	NodeInfo(const NodeInfo& base) = default;
public:
	NodeInfo(ThreadContext* ctx) throw()  : IObject(ctx), host(nullptr), port(0)
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
