#ifndef ALINOUS_DB_TABLE_SCAN_SCANNERFACTORY_H_
#define ALINOUS_DB_TABLE_SCAN_SCANNERFACTORY_H_
namespace alinous {namespace db {namespace trx {namespace scan {
class ITableTargetScanner;}}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableIdentifier;}}}}

namespace alinous {namespace db {namespace trx {
class DbTransaction;}}}

namespace alinous {namespace db {namespace table {
class IDatabaseTable;}}}

namespace alinous {namespace remote {namespace region {namespace client {namespace scan {
class RemoteTableFullScanner;}}}}}

namespace alinous {namespace db {namespace table {namespace scan {
class TableFullScanner;}}}}

namespace alinous {namespace db {namespace table {
class IScannableIndex;}}}

namespace alinous {namespace remote {namespace region {namespace client {namespace scan {
class RemoteTableIndexScanner;}}}}}

namespace alinous {namespace db {namespace table {namespace scan {
class TableIndexScanner;}}}}

namespace alinous {namespace db {namespace trx {namespace cache {
class TrxRecordCacheIndex;}}}}

namespace alinous {namespace db {namespace trx {namespace scan {
class ScanResultIndexKey;}}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class InnerNecessaryCondition;}}}}

namespace alinous {namespace runtime {namespace engine {
class ScriptMachine;}}}

namespace alinous {namespace remote {namespace region {namespace client {namespace scan {
class RemoteIndexEqScanner;}}}}}

namespace alinous {namespace db {namespace table {namespace scan {
class IndexEqScanner;}}}}

namespace alinous {namespace db {namespace table {namespace scan {
class IndexRangeScannerParam;}}}}

namespace alinous {namespace remote {namespace region {namespace client {namespace scan {
class RemoteIndexRangeScanner;}}}}}

namespace alinous {namespace db {namespace table {namespace scan {
class IndexRangeScanner;}}}}

namespace alinous {namespace db {namespace table {namespace scan {
class IndexListScannerParam;}}}}

namespace alinous {namespace remote {namespace region {namespace client {namespace scan {
class RemoteIndexListScanner;}}}}}

namespace alinous {namespace db {namespace table {namespace scan {
class IndexListScanner;}}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableMetadata;}}}}

namespace alinous {namespace remote {namespace region {namespace client {namespace scan {
class RemoteCrossJoinScanner;}}}}}

namespace alinous {namespace compile {namespace sql {namespace select {namespace join {namespace scan {
class CrossJoinScanner;}}}}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class JoinMatchExpression;}}}}

namespace alinous {namespace compile {namespace sql {namespace select {namespace join {
class SQLJoinCondition;}}}}}

namespace alinous {namespace remote {namespace region {namespace client {namespace scan {
class RemoteRightindexJoinScanner;}}}}}

namespace alinous {namespace compile {namespace sql {namespace select {namespace join {namespace scan {
class RightindexJoinScanner;}}}}}}

namespace alinous {namespace remote {namespace region {namespace client {
class RemoteReverseIndexScanner;}}}}

namespace alinous {namespace compile {namespace sql {namespace select {namespace join {namespace scan {
class ReverseIndexScanner;}}}}}}

namespace java {namespace io {
class IOException;}}

namespace alinous {namespace db {
class AlinousDbException;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace db {namespace table {namespace scan {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::IOException;
using ::alinous::compile::sql::analyze::InnerNecessaryCondition;
using ::alinous::compile::sql::analyze::JoinMatchExpression;
using ::alinous::compile::sql::analyze::ScanTableIdentifier;
using ::alinous::compile::sql::analyze::ScanTableMetadata;
using ::alinous::compile::sql::select::join::SQLJoinCondition;
using ::alinous::compile::sql::select::join::scan::CrossJoinScanner;
using ::alinous::compile::sql::select::join::scan::ReverseIndexScanner;
using ::alinous::compile::sql::select::join::scan::RightindexJoinScanner;
using ::alinous::db::AlinousDbException;
using ::alinous::db::table::IDatabaseTable;
using ::alinous::db::table::IScannableIndex;
using ::alinous::db::trx::DbTransaction;
using ::alinous::db::trx::cache::TrxRecordCacheIndex;
using ::alinous::db::trx::scan::ITableTargetScanner;
using ::alinous::db::trx::scan::ScanResultIndexKey;
using ::alinous::remote::region::client::RemoteReverseIndexScanner;
using ::alinous::remote::region::client::scan::RemoteCrossJoinScanner;
using ::alinous::remote::region::client::scan::RemoteIndexEqScanner;
using ::alinous::remote::region::client::scan::RemoteIndexListScanner;
using ::alinous::remote::region::client::scan::RemoteIndexRangeScanner;
using ::alinous::remote::region::client::scan::RemoteRightindexJoinScanner;
using ::alinous::remote::region::client::scan::RemoteTableFullScanner;
using ::alinous::remote::region::client::scan::RemoteTableIndexScanner;
using ::alinous::runtime::engine::ScriptMachine;



class ScannerFactory final : public virtual IObject {
public:
	ScannerFactory(const ScannerFactory& base) = default;
public:
	ScannerFactory(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~ScannerFactory() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	static ITableTargetScanner* getTableFullScanner(ScanTableIdentifier* tableId, DbTransaction* trx, IDatabaseTable* tableStore, int lockMode, ThreadContext* ctx);
	static ITableTargetScanner* getTableIndexScanner(ScanTableIdentifier* tableId, DbTransaction* trx, IScannableIndex* index, IDatabaseTable* tableStore, int lockMode, ThreadContext* ctx);
	static ITableTargetScanner* getIndexEqScanner(ScanTableIdentifier* tableId, DbTransaction* trx, IScannableIndex* index, IDatabaseTable* tableStore, TrxRecordCacheIndex* insertCacheindex, TrxRecordCacheIndex* updateCacheindex, int lockMode, ScanResultIndexKey* eqKey, int effectiveKeyLength, InnerNecessaryCondition* necessaryCondition, ScriptMachine* machine, ThreadContext* ctx);
	static ITableTargetScanner* getIndexRangeScanner(ScanTableIdentifier* tableId, DbTransaction* trx, IScannableIndex* index, IDatabaseTable* tableStore, TrxRecordCacheIndex* insertCacheindex, TrxRecordCacheIndex* updateCacheindex, int lockMode, IndexRangeScannerParam* param, int effectiveKeyLength, InnerNecessaryCondition* necessaryCondition, ScriptMachine* machine, ThreadContext* ctx);
	static ITableTargetScanner* getIndexListScanner(ScanTableIdentifier* tableId, DbTransaction* trx, IScannableIndex* index, IDatabaseTable* tableStore, TrxRecordCacheIndex* insertCacheindex, TrxRecordCacheIndex* updateCacheindex, int lockMode, IndexListScannerParam* param, int effectiveKeyLength, InnerNecessaryCondition* necessaryCondition, ScriptMachine* machine, ThreadContext* ctx);
	static ITableTargetScanner* getCrossJoinScanner(DbTransaction* trx, ITableTargetScanner* left, ITableTargetScanner* right, ScanTableMetadata* leftMetadata, ScanTableMetadata* rightMetadata, ScriptMachine* machine, ThreadContext* ctx) throw() ;
	static ITableTargetScanner* getRightindexJoinScanner(DbTransaction* trx, ITableTargetScanner* left, ITableTargetScanner* right, ScanTableMetadata* leftMetadata, ScanTableMetadata* rightMetadata, bool inner, JoinMatchExpression* match, SQLJoinCondition* condition, ScriptMachine* machine, ThreadContext* ctx) throw() ;
	static ITableTargetScanner* getReverseIndexScanner(DbTransaction* trx, ITableTargetScanner* left, ITableTargetScanner* right, ScanTableMetadata* leftMetadata, ScanTableMetadata* rightMetadata, bool inner, JoinMatchExpression* match, SQLJoinCondition* condition, ScriptMachine* machine, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}

#endif /* end of ALINOUS_DB_TABLE_SCAN_SCANNERFACTORY_H_ */
