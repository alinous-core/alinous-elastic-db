#ifndef ALINOUS_REMOTE_REGION_SERVER_SCAN_REGIONSCANMANAGER_H_
#define ALINOUS_REMOTE_REGION_SERVER_SCAN_REGIONSCANMANAGER_H_
namespace alinous {namespace remote {namespace region {namespace server {namespace scan {
class ScanSession;}}}}}

namespace alinous {namespace remote {namespace region {namespace client {namespace command {namespace dml {
class ClientScanCommandData;}}}}}}

namespace alinous {namespace remote {namespace region {namespace server {namespace schema {namespace strategy {
class RegionPartitionTableAccess;}}}}}}

namespace alinous {namespace remote {namespace region {namespace server {namespace tpc {
class CommitClusterNodeListner;}}}}}

namespace java {namespace lang {
class Long;}}

namespace java {namespace util {
template <typename  T, typename V> class Map;}}

namespace java {namespace util {
template <typename  T, typename V> class HashMap;}}

namespace alinous {namespace lock {
class LockObject;}}

namespace alinous {namespace db {
class AlinousDbException;}}

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
using ::java::util::HashMap;
using ::java::util::Map;
using ::alinous::db::AlinousDbException;
using ::alinous::lock::LockObject;
using ::alinous::remote::region::client::command::dml::ClientScanCommandData;
using ::alinous::remote::region::server::schema::strategy::RegionPartitionTableAccess;
using ::alinous::remote::region::server::tpc::CommitClusterNodeListner;



class RegionScanManager final : public virtual IObject {
public:
	RegionScanManager(const RegionScanManager& base) = default;
public:
	RegionScanManager(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~RegionScanManager() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	Map<Long,ScanSession>* sessions;
	LockObject* lock;
public:
	ScanSession* getScanSession(long long trxId, ClientScanCommandData* data, RegionPartitionTableAccess* tableAccess, CommitClusterNodeListner* accessListner, ThreadContext* ctx);
	void endSession(long long trxId, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}}

#endif /* end of ALINOUS_REMOTE_REGION_SERVER_SCAN_REGIONSCANMANAGER_H_ */
