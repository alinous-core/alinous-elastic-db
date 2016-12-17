#ifndef ALINOUS_REMOTE_REGION_CLIENT_REGIONCONNECTIONINFO_H_
#define ALINOUS_REMOTE_REGION_CLIENT_REGIONCONNECTIONINFO_H_
namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace remote {namespace region {namespace client {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;



class RegionConnectionInfo final : public virtual IObject {
public:
	RegionConnectionInfo(const RegionConnectionInfo& base) = default;
public:
	RegionConnectionInfo(String* host, int port, ThreadContext* ctx) throw() ;
	void __construct_impl(String* host, int port, ThreadContext* ctx) throw() ;
	virtual ~RegionConnectionInfo() throw();
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
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_REMOTE_REGION_CLIENT_REGIONCONNECTIONINFO_H_ */
