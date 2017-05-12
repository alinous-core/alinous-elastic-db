#ifndef ALINOUS_REMOTE_DB_SERVER_SCAN_ABSTRACTSTORAGESCANSESSION_H_
#define ALINOUS_REMOTE_DB_SERVER_SCAN_ABSTRACTSTORAGESCANSESSION_H_
namespace alinous {namespace db {namespace table {
class IDatabaseTable;}}}

namespace alinous {namespace remote {namespace region {namespace client {namespace command {namespace dml {
class ClientScanCommandData;}}}}}}

namespace alinous {namespace db {namespace trx {
class TrxLockContext;}}}

namespace alinous {namespace db {namespace table {namespace lockmonitor {
class DatabaseLockException;}}}}

namespace alinous {namespace remote {namespace region {namespace server {namespace scan {
class ScanWorkerResult;}}}}}

namespace java {namespace io {
class IOException;}}

namespace alinous {namespace btree {
class BTreeException;}}

namespace alinous {namespace db {namespace table {
class DatabaseException;}}}

namespace alinous {namespace db {namespace trx {namespace scan {
class ScanException;}}}}

namespace alinous {namespace system {
class AlinousException;}}

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
using ::java::io::IOException;
using ::alinous::btree::BTreeException;
using ::alinous::db::table::DatabaseException;
using ::alinous::db::table::IDatabaseTable;
using ::alinous::db::table::lockmonitor::DatabaseLockException;
using ::alinous::db::trx::TrxLockContext;
using ::alinous::db::trx::scan::ScanException;
using ::alinous::remote::region::client::command::dml::ClientScanCommandData;
using ::alinous::remote::region::server::scan::ScanWorkerResult;
using ::alinous::system::AlinousException;



class AbstractStorageScanSession : public virtual IObject {
public:
	AbstractStorageScanSession(const AbstractStorageScanSession& base) = default;
public:
	AbstractStorageScanSession(IDatabaseTable* table, ClientScanCommandData* data, ThreadContext* ctx) throw() ;
	void __construct_impl(IDatabaseTable* table, ClientScanCommandData* data, ThreadContext* ctx) throw() ;
	virtual ~AbstractStorageScanSession() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	IDatabaseTable* table;
	ClientScanCommandData* data;
	int maxRecords;
	TrxLockContext* locker;
public:
	void dispose(ThreadContext* ctx) throw() ;
	virtual void init(ThreadContext* ctx) = 0;
	virtual ScanWorkerResult* scan(ThreadContext* ctx) = 0;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}}

#endif /* end of ALINOUS_REMOTE_DB_SERVER_SCAN_ABSTRACTSTORAGESCANSESSION_H_ */
