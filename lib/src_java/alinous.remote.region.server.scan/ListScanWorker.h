#ifndef ALINOUS_REMOTE_REGION_SERVER_SCAN_LISTSCANWORKER_H_
#define ALINOUS_REMOTE_REGION_SERVER_SCAN_LISTSCANWORKER_H_
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



class ListScanWorker final : public IScanWorker, public virtual IObject {
public:
	ListScanWorker(const ListScanWorker& base) = default;
public:
	ListScanWorker(ClientScanCommandData* data, RegionPartitionTableAccess* tableAccess, CommitClusterNodeListner* accessListner, ThreadContext* ctx) throw() ;
	void __construct_impl(ClientScanCommandData* data, RegionPartitionTableAccess* tableAccess, CommitClusterNodeListner* accessListner, ThreadContext* ctx) throw() ;
	virtual ~ListScanWorker() throw();
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

#endif /* end of ALINOUS_REMOTE_REGION_SERVER_SCAN_LISTSCANWORKER_H_ */
