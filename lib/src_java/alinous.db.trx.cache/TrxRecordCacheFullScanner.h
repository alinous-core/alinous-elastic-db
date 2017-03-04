#ifndef ALINOUS_DB_TRX_CACHE_TRXRECORDCACHEFULLSCANNER_H_
#define ALINOUS_DB_TRX_CACHE_TRXRECORDCACHEFULLSCANNER_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableMetadata;}}}}

namespace alinous {namespace btree {
class BTree;}}

namespace alinous {namespace db {namespace trx {
class DbTransaction;}}}

namespace alinous {namespace db {namespace trx {namespace scan {
class ScanResultIndexKey;}}}}

namespace alinous {namespace btree {namespace scan {
class BTreeScanner;}}}

namespace alinous {namespace btree {
class LongKey;}}

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

namespace alinous {namespace system {
class AlinousException;}}

namespace alinous {namespace db {namespace trx {namespace scan {
class ScanException;}}}}

namespace alinous {namespace btree {
class IBTreeNode;}}

namespace alinous {namespace db {namespace trx {namespace scan {
class ScanResultRecord;}}}}

namespace alinous {namespace db {namespace trx {namespace cache {
class CachedRecord;}}}}

namespace alinous {namespace runtime {namespace variant {
class VariantValue;}}}

namespace alinous {namespace btree {
class IBTreeValue;}}

namespace alinous {namespace system {
class ISystemLog;}}

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
using ::alinous::btree::BTree;
using ::alinous::btree::BTreeException;
using ::alinous::btree::IBTreeNode;
using ::alinous::btree::IBTreeValue;
using ::alinous::btree::LongKey;
using ::alinous::btree::scan::BTreeScanner;
using ::alinous::compile::sql::analyze::ScanTableMetadata;
using ::alinous::db::table::DatabaseException;
using ::alinous::db::table::scan::IndexScannerLockRequirement;
using ::alinous::db::trx::DbTransaction;
using ::alinous::db::trx::scan::ITableTargetScanner;
using ::alinous::db::trx::scan::ScanException;
using ::alinous::db::trx::scan::ScanResultIndexKey;
using ::alinous::db::trx::scan::ScanResultRecord;
using ::alinous::runtime::dom::VariableException;
using ::alinous::runtime::variant::VariantValue;
using ::alinous::system::AlinousException;
using ::alinous::system::ISystemLog;



class TrxRecordCacheFullScanner final : public ITableTargetScanner, public virtual IObject {
public:
	TrxRecordCacheFullScanner(const TrxRecordCacheFullScanner& base) = default;
public:
	TrxRecordCacheFullScanner(ScanTableMetadata* metadata, BTree* storage, int kindOfCache, DbTransaction* trx, ThreadContext* ctx) throw() ;
	void __construct_impl(ScanTableMetadata* metadata, BTree* storage, int kindOfCache, DbTransaction* trx, ThreadContext* ctx) throw() ;
	virtual ~TrxRecordCacheFullScanner() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	BTree* storage;
	BTreeScanner* scanner;
	int kindOfCache;
	int current;
	ArrayList<IBTreeValue>* values;
	DbTransaction* trx;
	ScanTableMetadata* metadata;
public:
	void startScan(ScanResultIndexKey* indexKeyValue, ThreadContext* ctx) final;
	void endScan(ThreadContext* ctx) final;
	bool hasNext(bool debug, ThreadContext* ctx) final;
	ScanResultRecord* next(bool debug, ThreadContext* ctx) final;
	ArrayList<ScanResultRecord>* searchByIndexValue(ScanResultIndexKey* indexValue, ThreadContext* ctx);
	void dispose(ISystemLog* logger, ThreadContext* ctx) final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_DB_TRX_CACHE_TRXRECORDCACHEFULLSCANNER_H_ */
