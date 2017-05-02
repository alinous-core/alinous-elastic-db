#ifndef ALINOUS_REMOTE_REGION_SERVER_SCAN_FULLSCANWORKER_H_
#define ALINOUS_REMOTE_REGION_SERVER_SCAN_FULLSCANWORKER_H_
namespace alinous {namespace remote {namespace region {namespace client {namespace command {namespace dml {
class ClientScanCommandData;}}}}}}

namespace alinous {namespace remote {namespace region {namespace server {namespace schema {namespace strategy {
class RegionPartitionTableAccess;}}}}}}

namespace alinous {namespace remote {namespace region {namespace server {namespace scan {
class ScanWorkerResult;}}}}}

namespace alinous {namespace db {
class AlinousDbException;}}

namespace alinous {namespace remote {namespace region {namespace server {namespace schema {namespace strategy {
class RegionShardPartAccess;}}}}}}

namespace alinous {namespace remote {namespace region {namespace server {namespace schema {
class NodeReference;}}}}}

namespace java {namespace util {
template <typename  T> class List;}}

namespace alinous {namespace remote {namespace region {namespace server {namespace scan {
class IScanWorker;}}}}}

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
using ::java::util::List;
using ::alinous::db::AlinousDbException;
using ::alinous::remote::region::client::command::dml::ClientScanCommandData;
using ::alinous::remote::region::server::schema::NodeReference;
using ::alinous::remote::region::server::schema::strategy::RegionPartitionTableAccess;
using ::alinous::remote::region::server::schema::strategy::RegionShardPartAccess;
using ::alinous::system::AlinousException;



class FullScanWorker final : public IScanWorker, public virtual IObject {
public:
	FullScanWorker(const FullScanWorker& base) = default;
public:
	FullScanWorker(ClientScanCommandData* data, RegionPartitionTableAccess* tableAccess, ThreadContext* ctx) throw() ;
	void __construct_impl(ClientScanCommandData* data, RegionPartitionTableAccess* tableAccess, ThreadContext* ctx) throw() ;
	virtual ~FullScanWorker() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	RegionPartitionTableAccess* tableAccess;
	List<RegionShardPartAccess>* shardParts;
	int index;
	ClientScanCommandData* data;
public:
	void init(ThreadContext* ctx) throw()  final;
	ScanWorkerResult* scan(ThreadContext* ctx) final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}}

#endif /* end of ALINOUS_REMOTE_REGION_SERVER_SCAN_FULLSCANWORKER_H_ */
