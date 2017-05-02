#ifndef ALINOUS_REMOTE_REGION_SERVER_SCAN_ISCANWORKER_H_
#define ALINOUS_REMOTE_REGION_SERVER_SCAN_ISCANWORKER_H_
namespace alinous {namespace remote {namespace region {namespace server {namespace scan {
class ScanWorkerResult;}}}}}

namespace alinous {namespace system {
class AlinousException;}}

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
using ::alinous::system::AlinousException;



class IScanWorker : public virtual IObject {
public:
	IScanWorker(const IScanWorker& base) = default;
public:
	IScanWorker(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~IScanWorker() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	virtual void init(ThreadContext* ctx) throw()  = 0;
	virtual ScanWorkerResult* scan(ThreadContext* ctx) = 0;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}}

#endif /* end of ALINOUS_REMOTE_REGION_SERVER_SCAN_ISCANWORKER_H_ */
