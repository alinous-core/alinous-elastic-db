#ifndef ALINOUS_REMOTE_REGION_CLIENT_SCAN_IREMOTESCANNER_H_
#define ALINOUS_REMOTE_REGION_CLIENT_SCAN_IREMOTESCANNER_H_
namespace alinous {namespace db {namespace trx {namespace scan {
class ITableTargetScanner;}}}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace remote {namespace region {namespace client {namespace scan {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::db::trx::scan::ITableTargetScanner;



class IRemoteScanner : public virtual IObject, public ITableTargetScanner {
public:
	IRemoteScanner(const IRemoteScanner& base) = default;
public:
	IRemoteScanner(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~IRemoteScanner() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}}

#endif /* end of ALINOUS_REMOTE_REGION_CLIENT_SCAN_IREMOTESCANNER_H_ */
