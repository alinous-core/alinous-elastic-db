#ifndef ALINOUS_REMOTE_REGION_CLIENT_SCAN_ABSTRACTREMOTESCANNER_H_
#define ALINOUS_REMOTE_REGION_CLIENT_SCAN_ABSTRACTREMOTESCANNER_H_
namespace alinous {namespace db {namespace trx {namespace scan {
class ITableTargetScanner;}}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace remote {namespace region {namespace client {namespace scan {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::db::trx::scan::ITableTargetScanner;



class AbstractRemoteScanner : public ITableTargetScanner, public virtual IObject {
public:
	AbstractRemoteScanner(const AbstractRemoteScanner& base) = default;
public:
	AbstractRemoteScanner(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~AbstractRemoteScanner() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}}

#endif /* end of ALINOUS_REMOTE_REGION_CLIENT_SCAN_ABSTRACTREMOTESCANNER_H_ */
