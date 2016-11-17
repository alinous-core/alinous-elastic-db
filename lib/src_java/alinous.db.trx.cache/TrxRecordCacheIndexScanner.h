#ifndef ALINOUS_DB_TRX_CACHE_TRXRECORDCACHEINDEXSCANNER_H_
#define ALINOUS_DB_TRX_CACHE_TRXRECORDCACHEINDEXSCANNER_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableIdentifier;}}}}

namespace alinous {namespace db {namespace trx {
class DbTransaction;}}}

namespace alinous {namespace db {namespace trx {namespace cache {
class TrxRecordCacheIndex;}}}}

namespace alinous {namespace db {namespace trx {namespace cache {
class TrxRecordsCache;}}}}

namespace alinous {namespace db {namespace trx {namespace scan {
class ScanResultIndexKey;}}}}

namespace alinous {namespace btree {namespace scan {
class BTreeScanner;}}}

namespace alinous {namespace db {namespace table {
class BTreeIndexKey;}}}

namespace alinous {namespace db {namespace table {
class DatabaseException;}}}

namespace java {namespace io {
class IOException;}}

namespace java {namespace lang {
class InterruptedException;}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace alinous {namespace btree {
class BTreeException;}}

namespace alinous {namespace db {namespace trx {namespace scan {
class ScanException;}}}}

namespace alinous {namespace btree {
class IBTreeNode;}}

namespace alinous {namespace db {namespace trx {namespace scan {
class ScanResultRecord;}}}}

namespace alinous {namespace btree {
class LongValue;}}

namespace alinous {namespace system {
class AlinousException;}}

namespace alinous {namespace btree {
class LongKey;}}

namespace alinous {namespace btree {
class IBTreeValue;}}

namespace alinous {namespace db {namespace trx {namespace cache {
class CachedRecord;}}}}

namespace alinous {namespace system {
class ISystemLog;}}

namespace alinous {namespace btree {
class IBTree;}}

namespace alinous {namespace db {namespace trx {namespace scan {
class ITableTargetScanner;}}}}

namespace alinous {namespace db {namespace table {namespace scan {
class IndexScannerLockRequirement;}}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace db {namespace trx {namespace cache {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::IOException;
using ::java::util::ArrayList;
using ::alinous::btree::BTreeException;
using ::alinous::btree::IBTree;
using ::alinous::btree::IBTreeNode;
using ::alinous::btree::IBTreeValue;
using ::alinous::btree::LongKey;
using ::alinous::btree::LongValue;
using ::alinous::btree::scan::BTreeScanner;
using ::alinous::compile::sql::analyze::ScanTableIdentifier;
using ::alinous::db::table::BTreeIndexKey;
using ::alinous::db::table::DatabaseException;
using ::alinous::db::table::scan::IndexScannerLockRequirement;
using ::alinous::db::trx::DbTransaction;
using ::alinous::db::trx::scan::ITableTargetScanner;
using ::alinous::db::trx::scan::ScanException;
using ::alinous::db::trx::scan::ScanResultIndexKey;
using ::alinous::db::trx::scan::ScanResultRecord;
using ::alinous::runtime::dom::VariableException;
using ::alinous::system::AlinousException;
using ::alinous::system::ISystemLog;



class TrxRecordCacheIndexScanner final : public ITableTargetScanner, public virtual IObject {
public:
	TrxRecordCacheIndexScanner(const TrxRecordCacheIndexScanner& base) = default;
public:
	TrxRecordCacheIndexScanner(ScanTableIdentifier* tableId, DbTransaction* trx, TrxRecordCacheIndex* trxCacheIndex, TrxRecordsCache* storage, int kindOfCache, ThreadContext* ctx) throw() ;
	void __construct_impl(ScanTableIdentifier* tableId, DbTransaction* trx, TrxRecordCacheIndex* trxCacheIndex, TrxRecordsCache* storage, int kindOfCache, ThreadContext* ctx) throw() ;
	virtual ~TrxRecordCacheIndexScanner() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	TrxRecordCacheIndex* trxCacheIndex;
	IBTree* indexBTree;
	TrxRecordsCache* storage;
	BTreeScanner* scanner;
	int current;
	ArrayList<IBTreeValue>* values;
	int kindOfCache;
	DbTransaction* trx;
	ScanTableIdentifier* tableId;
public:
	void startScan(ScanResultIndexKey* indexKeyValue, ThreadContext* ctx) final;
	void endScan(ThreadContext* ctx) final;
	bool hasNext(bool debug, ThreadContext* ctx) final;
	ScanResultRecord* next(bool debug, ThreadContext* ctx) final;
	ArrayList<ScanResultRecord>* searchByIndexValue(ScanResultIndexKey* indexValue, ThreadContext* ctx);
	void dispose(ISystemLog* logger, ThreadContext* ctx) final;
private:
	ScanResultRecord* toScanResultRecord(long long oid, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_DB_TRX_CACHE_TRXRECORDCACHEINDEXSCANNER_H_ */
