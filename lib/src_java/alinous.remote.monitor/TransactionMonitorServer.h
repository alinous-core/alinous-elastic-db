#ifndef ALINOUS_REMOTE_MONITOR_TRANSACTIONMONITORSERVER_H_
#define ALINOUS_REMOTE_MONITOR_TRANSACTIONMONITORSERVER_H_
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



class TransactionMonitorServer final : public virtual IObject {
public:
	TransactionMonitorServer(const TransactionMonitorServer& base) = default;
public:
	TransactionMonitorServer(int port, ThreadContext* ctx) throw() ;
	void __construct_impl(int port, ThreadContext* ctx) throw() ;
	virtual ~TransactionMonitorServer() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	int port;
	long long lastCommitId;
	long long lastOid;
public:
	void start(ThreadContext* ctx) throw() ;
	void dispose(ThreadContext* ctx) throw() ;
	int getPort(ThreadContext* ctx) throw() ;
	long long getNextCommitId(ThreadContext* ctx) throw() ;
	long long getNextOid(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_REMOTE_MONITOR_TRANSACTIONMONITORSERVER_H_ */
