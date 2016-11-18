#ifndef ALINOUS_DB_TRX_SCAN_SCANRESULTRECORD_H_
#define ALINOUS_DB_TRX_SCAN_SCANRESULTRECORD_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableIdentifier;}}}}

namespace alinous {namespace db {namespace trx {
class DbTransaction;}}}

namespace alinous {namespace db {namespace table {
class IDatabaseRecord;}}}

namespace java {namespace lang {
class Integer;}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableMetadata;}}}}

namespace alinous {namespace runtime {namespace dom {
class DomVariable;}}}

namespace alinous {namespace db {namespace trx {namespace scan {
class ScanResultRecord;}}}}

namespace alinous {namespace db {
class AlinousDatabase;}}

namespace alinous {namespace db {namespace table {namespace lockmonitor {
class ThreadLocker;}}}}

namespace alinous {namespace compile {namespace sql {
class TableAndSchema;}}}

namespace alinous {namespace db {namespace table {
class IDatabaseTable;}}}

namespace alinous {namespace runtime {namespace variant {
class VariantValue;}}}

namespace alinous {namespace db {namespace trx {namespace scan {
class PadddingRecord;}}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryBuilder;}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryFetcher;}}}

namespace alinous {namespace btree {
class IBTreeValue;}}

namespace alinous {namespace btree {
class IValueFetcher;}}

namespace java {namespace lang {
class StringBuilder;}}

namespace alinous {namespace btree {
class KeyValueFactory;}}

namespace alinous {namespace db {namespace table {namespace lockmonitor {
class DatabaseLockException;}}}}

namespace alinous {namespace db {namespace table {namespace scan {
class IndexScannerLockRequirement;}}}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace db {namespace trx {namespace scan {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::ArrayList;
using ::alinous::btree::IBTreeValue;
using ::alinous::btree::IValueFetcher;
using ::alinous::btree::KeyValueFactory;
using ::alinous::buffer::storage::FileStorageEntryBuilder;
using ::alinous::buffer::storage::FileStorageEntryFetcher;
using ::alinous::compile::sql::TableAndSchema;
using ::alinous::compile::sql::analyze::ScanTableIdentifier;
using ::alinous::compile::sql::analyze::ScanTableMetadata;
using ::alinous::db::AlinousDatabase;
using ::alinous::db::table::IDatabaseRecord;
using ::alinous::db::table::IDatabaseTable;
using ::alinous::db::table::lockmonitor::DatabaseLockException;
using ::alinous::db::table::lockmonitor::ThreadLocker;
using ::alinous::db::table::scan::IndexScannerLockRequirement;
using ::alinous::db::trx::DbTransaction;
using ::alinous::runtime::dom::DomVariable;
using ::alinous::runtime::dom::VariableException;
using ::alinous::runtime::variant::VariantValue;
using ::alinous::system::AlinousException;



class ScanResultRecord : public IBTreeValue, public virtual IObject {
public:
	ScanResultRecord(const ScanResultRecord& base) = default;
public:
	ScanResultRecord(ThreadContext* ctx) throw()  : IObject(ctx), IBTreeValue(ctx), records(GCUtils<ArrayList<IDatabaseRecord> >::ins(this, (new(ctx) ArrayList<IDatabaseRecord>(ctx)), ctx, __FILEW__, __LINE__, L"")), tables(GCUtils<ArrayList<ScanTableIdentifier> >::ins(this, (new(ctx) ArrayList<ScanTableIdentifier>(ctx)), ctx, __FILEW__, __LINE__, L"")), lockingModeList(GCUtils<ArrayList<Integer> >::ins(this, (new(ctx) ArrayList<Integer>(ctx)), ctx, __FILEW__, __LINE__, L"")), soid(0)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	ScanResultRecord(ScanTableIdentifier* tableId, int kind, long long oid, DbTransaction* trx, IDatabaseRecord* record, int lockingMode, ThreadContext* ctx);
	void __construct_impl(ScanTableIdentifier* tableId, int kind, long long oid, DbTransaction* trx, IDatabaseRecord* record, int lockingMode, ThreadContext* ctx);
	ScanResultRecord(ScanTableIdentifier* tableId, long long oid, DbTransaction* trx, ScanTableMetadata* metadata, DomVariable* domVariable, ThreadContext* ctx);
	void __construct_impl(ScanTableIdentifier* tableId, long long oid, DbTransaction* trx, ScanTableMetadata* metadata, DomVariable* domVariable, ThreadContext* ctx);
	virtual ~ScanResultRecord() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	ArrayList<IDatabaseRecord>* records;
	ArrayList<ScanTableIdentifier>* tables;
	ArrayList<Integer>* lockingModeList;
private:
	long long soid;
public:
	ScanResultRecord* copy(DbTransaction* trx, ThreadContext* ctx);
	void unlock(DbTransaction* trx, ThreadContext* ctx);
	VariantValue* getValueOfTable(ScanTableIdentifier* tableId, int columnOrder, ThreadContext* ctx) throw() ;
	VariantValue* get(int index, ThreadContext* ctx) throw() ;
	int numColumns(ThreadContext* ctx) throw() ;
	void setValue(int index, VariantValue* vv, ThreadContext* ctx) throw() ;
	void addNullRecord(int colSize, ThreadContext* ctx) throw() ;
	long long getLastUpdateCommitId(ThreadContext* ctx) throw() ;
	long long getInsertedCommitId(ThreadContext* ctx) throw() ;
	long long getDeletedCommitId(ThreadContext* ctx) throw() ;
	long long getOid(ThreadContext* ctx) throw() ;
	void releaseLocks(ThreadLocker* lockContext, ThreadContext* ctx) throw() ;
	ScanTableIdentifier* getTableId(ThreadContext* ctx) throw() ;
	int diskSize(ThreadContext* ctx) final;
	void appendToEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx) final;
	IValueFetcher* getFetcher(ThreadContext* ctx) throw()  final;
	ScanResultRecord* join(ScanResultRecord* rightRecord, DbTransaction* trx, ThreadContext* ctx);
	long long getSoid(ThreadContext* ctx) throw() ;
	void setSoid(long long soid, ThreadContext* ctx) throw() ;
	ArrayList<IDatabaseRecord>* getRecords(ThreadContext* ctx) throw() ;
	String* toString(ThreadContext* ctx) throw() ;
	bool equals(IObject* other, ThreadContext* ctx) throw()  final;
public:
	static ScanResultRecord* valueFromFetcher(FileStorageEntryFetcher* fetcher, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_DB_TRX_SCAN_SCANRESULTRECORD_H_ */
