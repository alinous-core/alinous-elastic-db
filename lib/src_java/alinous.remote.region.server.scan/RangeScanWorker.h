#ifndef ALINOUS_REMOTE_REGION_SERVER_SCAN_RANGESCANWORKER_H_
#define ALINOUS_REMOTE_REGION_SERVER_SCAN_RANGESCANWORKER_H_
namespace alinous {namespace remote {namespace region {namespace client {namespace command {namespace dml {
class ClientScanCommandData;}}}}}}

namespace alinous {namespace remote {namespace region {namespace server {namespace schema {namespace strategy {
class RegionPartitionTableAccess;}}}}}}

namespace alinous {namespace remote {namespace region {namespace server {namespace tpc {
class CommitClusterNodeListner;}}}}}

namespace alinous {namespace remote {namespace region {namespace server {namespace scan {
class ScanWorkerResult;}}}}}

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
using ::alinous::remote::region::client::command::dml::ClientScanCommandData;
using ::alinous::remote::region::server::schema::strategy::RegionPartitionTableAccess;
using ::alinous::remote::region::server::tpc::CommitClusterNodeListner;



class RangeScanWorker final : public IScanWorker, public virtual IObject {
public:
	RangeScanWorker(const RangeScanWorker& base) = default;
public:
	RangeScanWorker(ClientScanCommandData* data, RegionPartitionTableAccess* tableAccess, ThreadContext* ctx) throw() ;
	void __construct_impl(ClientScanCommandData* data, RegionPartitionTableAccess* tableAccess, ThreadContext* ctx) throw() ;
	virtual ~RangeScanWorker() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	void init(CommitClusterNodeListner* accessListner, ThreadContext* ctx) throw()  final;
	ScanWorkerResult* scan(ThreadContext* ctx) throw()  final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}}

#endif /* end of ALINOUS_REMOTE_REGION_SERVER_SCAN_RANGESCANWORKER_H_ */
