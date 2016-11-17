#ifndef ALINOUS_DB_TRX_SCAN_SCANRESULT_H_
#define ALINOUS_DB_TRX_SCAN_SCANRESULT_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableMetadata;}}}}

namespace alinous {namespace db {namespace table {namespace lockmonitor {
class ThreadLocker;}}}}

namespace alinous {namespace btreememory {
class BTreeOnMemory;}}

namespace alinous {namespace db {
class AlinousDatabase;}}

namespace java {namespace io {
class File;}}

namespace alinous {namespace btree {
class BTree;}}

namespace alinous {namespace system {
class AlinousException;}}

namespace java {namespace io {
class IOException;}}

namespace java {namespace lang {
class InterruptedException;}}

namespace alinous {namespace btree {
class BTreeException;}}

namespace alinous {namespace db {namespace trx {namespace scan {
class ScanResultIndex;}}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableColumnIdentifier;}}}}

namespace java {namespace lang {
class StringBuilder;}}

namespace alinous {namespace db {namespace trx {namespace scan {
class ScanResultRecord;}}}}

namespace alinous {namespace btree {
class IBTreeNode;}}

namespace alinous {namespace btree {
class LongKey;}}

namespace alinous {namespace btree {
class IBTreeValue;}}

namespace alinous {namespace db {namespace trx {
class DbTransaction;}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableIdentifier;}}}}

namespace alinous {namespace db {namespace table {
class DatabaseRecord;}}}

namespace alinous {namespace runtime {namespace dom {
class DomVariable;}}}

namespace alinous {namespace system {
class ISystemLog;}}

namespace java {namespace lang {
class Throwable;}}

namespace alinous {namespace btree {
class IBTree;}}

namespace alinous {namespace db {namespace table {
class DatatableConstants;}}}

namespace alinous {namespace db {namespace table {
class IDatabaseRecord;}}}

namespace alinous {namespace db {namespace table {namespace scan {
class IndexScannerLockRequirement;}}}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

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
using ::java::io::File;
using ::java::io::IOException;
using ::java::util::ArrayList;
using ::alinous::btree::BTree;
using ::alinous::btree::BTreeException;
using ::alinous::btree::IBTree;
using ::alinous::btree::IBTreeNode;
using ::alinous::btree::IBTreeValue;
using ::alinous::btree::LongKey;
using ::alinous::btreememory::BTreeOnMemory;
using ::alinous::compile::sql::analyze::ScanTableColumnIdentifier;
using ::alinous::compile::sql::analyze::ScanTableIdentifier;
using ::alinous::compile::sql::analyze::ScanTableMetadata;
using ::alinous::db::AlinousDatabase;
using ::alinous::db::table::DatabaseRecord;
using ::alinous::db::table::DatatableConstants;
using ::alinous::db::table::IDatabaseRecord;
using ::alinous::db::table::lockmonitor::ThreadLocker;
using ::alinous::db::table::scan::IndexScannerLockRequirement;
using ::alinous::db::trx::DbTransaction;
using ::alinous::runtime::dom::DomVariable;
using ::alinous::runtime::dom::VariableException;
using ::alinous::system::AlinousException;
using ::alinous::system::ISystemLog;



class ScanResult final : public virtual IObject {
public:
	ScanResult(const ScanResult& base) = default;
public:
	ScanResult(ScanTableMetadata* metadata, String* trxDir, int serial, ThreadLocker* lockContext, ThreadContext* ctx);
	void __construct_impl(ScanTableMetadata* metadata, String* trxDir, int serial, ThreadLocker* lockContext, ThreadContext* ctx);
	virtual ~ScanResult() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	IBTree* store;
	int serial;
	String* storagePath;
	String* trxDir;
	ArrayList<ScanResultIndex>* indexes;
	ScanTableMetadata* metadata;
public:
	void switchToDisk(AlinousDatabase* database, ThreadContext* ctx);
	ScanResultIndex* getIndex(ArrayList<ScanTableColumnIdentifier>* indexColumns, ThreadContext* ctx) throw() ;
	ScanResultIndex* addIndex(ArrayList<ScanTableColumnIdentifier>* columns, ThreadContext* ctx);
	ScanResultRecord* getRecord(long long soid, ThreadContext* ctx);
	void addGroupByRecord(ScanResultRecord* record, DbTransaction* trx, ThreadContext* ctx) throw() ;
	void addRecord(ScanResultRecord* record, DbTransaction* trx, ThreadContext* ctx);
	void addRecord(ScanTableIdentifier* tableId, DatabaseRecord* record, DbTransaction* trx, ThreadContext* ctx);
	void addRecord(ScanTableIdentifier* tableId, DomVariable* domVariable, DbTransaction* trx, ThreadContext* ctx);
	void dispose(ISystemLog* logger, ThreadContext* ctx);
	IBTree* getStore(ThreadContext* ctx) throw() ;
private:
	String* getOidIndexName(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_DB_TRX_SCAN_SCANRESULT_H_ */
