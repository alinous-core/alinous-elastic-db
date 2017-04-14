#ifndef ALINOUS_REMOTE_REGION_CLIENT_SCAN_REMOTETABLEFULLSCANNER_H_
#define ALINOUS_REMOTE_REGION_CLIENT_SCAN_REMOTETABLEFULLSCANNER_H_
namespace alinous {namespace remote {namespace region {namespace client {namespace scan {
class RemoteTableFullScanner;}}}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableIdentifier;}}}}

namespace alinous {namespace db {namespace trx {
class DbTransaction;}}}

namespace alinous {namespace db {namespace table {
class IDatabaseTable;}}}

namespace alinous {namespace db {namespace trx {namespace scan {
class ScanResultIndexKey;}}}}

namespace alinous {namespace db {namespace trx {namespace scan {
class ScanResultRecord;}}}}

namespace alinous {namespace system {
class ISystemLog;}}

namespace alinous {namespace remote {namespace region {namespace client {namespace scan {
class IRemoteScanner;}}}}}

namespace java {namespace io {
class IOException;}}

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

namespace alinous {namespace remote {namespace region {namespace client {namespace scan {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::IOException;
using ::alinous::compile::sql::analyze::ScanTableIdentifier;
using ::alinous::db::table::DatabaseException;
using ::alinous::db::table::IDatabaseTable;
using ::alinous::db::trx::DbTransaction;
using ::alinous::db::trx::scan::ScanException;
using ::alinous::db::trx::scan::ScanResultIndexKey;
using ::alinous::db::trx::scan::ScanResultRecord;
using ::alinous::system::AlinousException;
using ::alinous::system::ISystemLog;



class RemoteTableFullScanner final : public IRemoteScanner, public virtual IObject {
public:
	RemoteTableFullScanner(const RemoteTableFullScanner& base) = default;
public:
	RemoteTableFullScanner(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~RemoteTableFullScanner() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	RemoteTableFullScanner* init(ScanTableIdentifier* tableId, DbTransaction* trx, IDatabaseTable* tableStore, int lockMode, ThreadContext* ctx);
	void startScan(ScanResultIndexKey* indexKeyValue, ThreadContext* ctx) final;
	void endScan(ThreadContext* ctx) final;
	bool hasNext(bool debug, ThreadContext* ctx) final;
	ScanResultRecord* next(bool debug, ThreadContext* ctx) final;
	void dispose(ISystemLog* logger, ThreadContext* ctx) final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}}

#endif /* end of ALINOUS_REMOTE_REGION_CLIENT_SCAN_REMOTETABLEFULLSCANNER_H_ */
