#ifndef ALINOUS_DB_TRX_SCAN_SCANNEDRESULTINDEXSCANNER_H_
#define ALINOUS_DB_TRX_SCAN_SCANNEDRESULTINDEXSCANNER_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace db {namespace trx {namespace scan {
class ScanResult;}}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableColumnIdentifier;}}}}

namespace alinous {namespace db {namespace trx {namespace scan {
class ScanResultIndex;}}}}

namespace alinous {namespace db {namespace trx {namespace scan {
class ScanException;}}}}

namespace alinous {namespace db {namespace trx {namespace scan {
class ScanResultIndexKey;}}}}

namespace alinous {namespace btree {namespace scan {
class BTreeScanner;}}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace java {namespace io {
class IOException;}}

namespace java {namespace lang {
class InterruptedException;}}

namespace alinous {namespace btree {
class BTreeException;}}

namespace alinous {namespace btree {
class IBTreeNode;}}

namespace alinous {namespace db {namespace trx {namespace scan {
class ScanResultRecord;}}}}

namespace alinous {namespace btree {
class LongValue;}}

namespace alinous {namespace system {
class ISystemLog;}}

namespace java {namespace lang {
class Throwable;}}

namespace alinous {namespace btree {
class IBTree;}}

namespace alinous {namespace btree {
class IBTreeValue;}}

namespace alinous {namespace db {namespace trx {namespace scan {
class ITableTargetScanner;}}}}

namespace alinous {namespace db {namespace table {
class DatabaseException;}}}

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
using ::java::io::IOException;
using ::java::util::ArrayList;
using ::alinous::btree::BTreeException;
using ::alinous::btree::IBTree;
using ::alinous::btree::IBTreeNode;
using ::alinous::btree::IBTreeValue;
using ::alinous::btree::LongValue;
using ::alinous::btree::scan::BTreeScanner;
using ::alinous::compile::sql::analyze::ScanTableColumnIdentifier;
using ::alinous::db::table::DatabaseException;
using ::alinous::runtime::dom::VariableException;
using ::alinous::system::ISystemLog;



class ScannedResultIndexScanner final : public ITableTargetScanner, public virtual IObject {
public:
	ScannedResultIndexScanner(const ScannedResultIndexScanner& base) = default;
public:
	ScannedResultIndexScanner(ScanResult* result, ArrayList<ScanTableColumnIdentifier>* indexColumns, ThreadContext* ctx);
	void __construct_impl(ScanResult* result, ArrayList<ScanTableColumnIdentifier>* indexColumns, ThreadContext* ctx);
	virtual ~ScannedResultIndexScanner() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	ScanResult* result;
	IBTree* btree;
	BTreeScanner* scanner;
	ArrayList<IBTreeValue>* values;
	int current;
public:
	void startScan(ScanResultIndexKey* indexKeyValue, ThreadContext* ctx) final;
	bool hasNext(bool debug, ThreadContext* ctx) final;
	ScanResultRecord* next(bool debug, ThreadContext* ctx) final;
	void endScan(ThreadContext* ctx) final;
	void dispose(ISystemLog* logger, ThreadContext* ctx) final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_DB_TRX_SCAN_SCANNEDRESULTINDEXSCANNER_H_ */
