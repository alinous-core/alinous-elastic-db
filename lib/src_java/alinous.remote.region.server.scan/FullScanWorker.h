#ifndef ALINOUS_REMOTE_REGION_SERVER_SCAN_FULLSCANWORKER_H_
#define ALINOUS_REMOTE_REGION_SERVER_SCAN_FULLSCANWORKER_H_
namespace alinous {namespace remote {namespace region {namespace server {namespace scan {
class IScanWorker;}}}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace remote {namespace region {namespace server {namespace scan {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;



class FullScanWorker final : public IScanWorker, public virtual IObject {
public:
	FullScanWorker(const FullScanWorker& base) = default;
public:
	FullScanWorker(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~FullScanWorker() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}}

#endif /* end of ALINOUS_REMOTE_REGION_SERVER_SCAN_FULLSCANWORKER_H_ */
