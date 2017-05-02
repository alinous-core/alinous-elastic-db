#ifndef ALINOUS_REMOTE_REGION_SERVER_SCAN_SCANSESSION_H_
#define ALINOUS_REMOTE_REGION_SERVER_SCAN_SCANSESSION_H_
namespace alinous {namespace remote {namespace region {namespace client {namespace command {namespace dml {
class ClientScanCommandData;}}}}}}

namespace alinous {namespace remote {namespace region {namespace server {namespace scan {
class ScanSession;}}}}}

namespace alinous {namespace remote {namespace region {namespace server {namespace schema {namespace strategy {
class RegionPartitionTableAccess;}}}}}}

namespace alinous {namespace remote {namespace region {namespace server {namespace scan {
class FullScanWorker;}}}}}

namespace alinous {namespace remote {namespace region {namespace server {namespace scan {
class EqKeyScanWorker;}}}}}

namespace alinous {namespace remote {namespace region {namespace server {namespace scan {
class ListScanWorker;}}}}}

namespace alinous {namespace remote {namespace region {namespace server {namespace scan {
class RangeScanWorker;}}}}}

namespace alinous {namespace db {
class AlinousDbException;}}

namespace alinous {namespace remote {namespace region {namespace server {namespace scan {
class ScanWorkerResult;}}}}}

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
using ::alinous::db::AlinousDbException;
using ::alinous::remote::region::client::command::dml::ClientScanCommandData;
using ::alinous::remote::region::server::schema::strategy::RegionPartitionTableAccess;
using ::alinous::system::AlinousException;



class ScanSession final : public virtual IObject {
public:
	ScanSession(const ScanSession& base) = default;
public:
	ScanSession(ClientScanCommandData* data, ThreadContext* ctx) throw() ;
	void __construct_impl(ClientScanCommandData* data, ThreadContext* ctx) throw() ;
	virtual ~ScanSession() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	ClientScanCommandData* data;
	IScanWorker* worker;
public:
	ScanSession* init(RegionPartitionTableAccess* tableAccess, ThreadContext* ctx);
	ScanWorkerResult* scan(ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}}

#endif /* end of ALINOUS_REMOTE_REGION_SERVER_SCAN_SCANSESSION_H_ */
