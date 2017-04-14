#ifndef ALINOUS_REMOTE_REGION_CLIENT_SCAN_REMOTECROSSJOINSCANNER_H_
#define ALINOUS_REMOTE_REGION_CLIENT_SCAN_REMOTECROSSJOINSCANNER_H_
namespace alinous {namespace remote {namespace region {namespace client {namespace scan {
class RemoteCrossJoinScanner;}}}}}

namespace alinous {namespace db {namespace trx {
class DbTransaction;}}}

namespace alinous {namespace db {namespace trx {namespace scan {
class ITableTargetScanner;}}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableMetadata;}}}}

namespace alinous {namespace runtime {namespace engine {
class ScriptMachine;}}}

namespace alinous {namespace db {namespace trx {namespace scan {
class ScanResultIndexKey;}}}}

namespace alinous {namespace db {namespace trx {namespace scan {
class ScanResultRecord;}}}}

namespace alinous {namespace system {
class ISystemLog;}}

namespace alinous {namespace remote {namespace region {namespace client {namespace scan {
class IRemoteJoinScanner;}}}}}

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
using ::alinous::compile::sql::analyze::ScanTableMetadata;
using ::alinous::db::table::DatabaseException;
using ::alinous::db::trx::DbTransaction;
using ::alinous::db::trx::scan::ITableTargetScanner;
using ::alinous::db::trx::scan::ScanException;
using ::alinous::db::trx::scan::ScanResultIndexKey;
using ::alinous::db::trx::scan::ScanResultRecord;
using ::alinous::runtime::engine::ScriptMachine;
using ::alinous::system::AlinousException;
using ::alinous::system::ISystemLog;



class RemoteCrossJoinScanner final : public IRemoteJoinScanner, public virtual IObject {
public:
	RemoteCrossJoinScanner(const RemoteCrossJoinScanner& base) = default;
public:
	RemoteCrossJoinScanner(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~RemoteCrossJoinScanner() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	RemoteCrossJoinScanner* init(DbTransaction* trx, ITableTargetScanner* left, ITableTargetScanner* right, ScanTableMetadata* leftMetadata, ScanTableMetadata* rightMetadata, ScriptMachine* machine, ThreadContext* ctx) throw() ;
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

#endif /* end of ALINOUS_REMOTE_REGION_CLIENT_SCAN_REMOTECROSSJOINSCANNER_H_ */
