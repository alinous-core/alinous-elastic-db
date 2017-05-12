#ifndef ALINOUS_REMOTE_DB_SERVER_SCAN_STORAGESCANSESSIONMANAGER_H_
#define ALINOUS_REMOTE_DB_SERVER_SCAN_STORAGESCANSESSIONMANAGER_H_
namespace alinous {namespace remote {namespace db {namespace server {namespace scan {
class AbstractStorageScanSession;}}}}}

namespace alinous {namespace db {namespace table {
class IDatabaseTable;}}}

namespace alinous {namespace db {namespace trx {
class DbVersionContext;}}}

namespace alinous {namespace remote {namespace region {namespace client {namespace command {namespace dml {
class ClientScanCommandData;}}}}}}

namespace java {namespace lang {
class Long;}}

namespace alinous {namespace remote {namespace db {namespace server {namespace scan {
class FullScanSession;}}}}}

namespace alinous {namespace remote {namespace db {namespace server {namespace scan {
class EqKeyScanSession;}}}}}

namespace alinous {namespace remote {namespace db {namespace server {namespace scan {
class ListScanSession;}}}}}

namespace alinous {namespace remote {namespace db {namespace server {namespace scan {
class RangeScanSession;}}}}}

namespace alinous {namespace db {
class AlinousDbException;}}

namespace alinous {namespace lock {
class LockObject;}}

namespace java {namespace util {
template <typename  T, typename V> class Map;}}

namespace java {namespace util {
template <typename  T, typename V> class HashMap;}}

namespace alinous {namespace db {namespace trx {namespace scan {
class ScanException;}}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace remote {namespace db {namespace server {namespace scan {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::HashMap;
using ::java::util::Map;
using ::alinous::db::AlinousDbException;
using ::alinous::db::table::IDatabaseTable;
using ::alinous::db::trx::DbVersionContext;
using ::alinous::db::trx::scan::ScanException;
using ::alinous::lock::LockObject;
using ::alinous::remote::region::client::command::dml::ClientScanCommandData;



class StorageScanSessionManager final : public virtual IObject {
public:
	StorageScanSessionManager(const StorageScanSessionManager& base) = default;
public:
	StorageScanSessionManager(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~StorageScanSessionManager() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	LockObject* lock;
	Map<Long,AbstractStorageScanSession>* sessions;
public:
	AbstractStorageScanSession* getScanSession(IDatabaseTable* table, DbVersionContext* vctx, ClientScanCommandData* data, ThreadContext* ctx);
	void removeSession(DbVersionContext* vctx, ThreadContext* ctx) throw() ;
private:
	AbstractStorageScanSession* newSession(IDatabaseTable* table, ClientScanCommandData* data, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}}

#endif /* end of ALINOUS_REMOTE_DB_SERVER_SCAN_STORAGESCANSESSIONMANAGER_H_ */
