#ifndef ALINOUS_REMOTE_REGION_CLIENT_SCAN_IREMOTEJOINSCANNER_H_
#define ALINOUS_REMOTE_REGION_CLIENT_SCAN_IREMOTEJOINSCANNER_H_
namespace alinous {namespace remote {namespace region {namespace client {namespace scan {
class IRemoteScanner;}}}}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace remote {namespace region {namespace client {namespace scan {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;



class IRemoteJoinScanner : public virtual IObject, public IRemoteScanner {
public:
	IRemoteJoinScanner(const IRemoteJoinScanner& base) = default;
public:
	IRemoteJoinScanner(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~IRemoteJoinScanner() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}}

#endif /* end of ALINOUS_REMOTE_REGION_CLIENT_SCAN_IREMOTEJOINSCANNER_H_ */
