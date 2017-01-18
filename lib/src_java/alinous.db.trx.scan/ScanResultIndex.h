#ifndef ALINOUS_DB_TRX_SCAN_SCANRESULTINDEX_H_
#define ALINOUS_DB_TRX_SCAN_SCANRESULTINDEX_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableMetadata;}}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableColumnIdentifier;}}}}

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

namespace java {namespace lang {
class StringBuilder;}}

namespace alinous {namespace db {namespace trx {namespace scan {
class ScanResultRecord;}}}}

namespace alinous {namespace btree {
class LongValue;}}

namespace alinous {namespace db {namespace trx {namespace scan {
class ScanResultIndexKey;}}}}

namespace alinous {namespace runtime {namespace variant {
class VariantValue;}}}

namespace alinous {namespace btree {
class IBTree;}}

namespace alinous {namespace system {
class ISystemLog;}}

namespace java {namespace lang {
class Throwable;}}

namespace alinous {namespace btree {
class IBTreeValue;}}

namespace alinous {namespace db {namespace table {
class DatatableConstants;}}}

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
using ::alinous::btree::IBTreeValue;
using ::alinous::btree::LongValue;
using ::alinous::btreememory::BTreeOnMemory;
using ::alinous::compile::sql::analyze::ScanTableColumnIdentifier;
using ::alinous::compile::sql::analyze::ScanTableMetadata;
using ::alinous::db::AlinousDatabase;
using ::alinous::db::table::DatatableConstants;
using ::alinous::runtime::variant::VariantValue;
using ::alinous::system::AlinousException;
using ::alinous::system::ISystemLog;



class ScanResultIndex final : public virtual IObject {
public:
	ScanResultIndex(const ScanResultIndex& base) = default;
public:
	ScanResultIndex(ScanTableMetadata* metadata, ArrayList<ScanTableColumnIdentifier>* columns, String* trxDir, int indexSerial, ThreadContext* ctx);
	void __construct_impl(ScanTableMetadata* metadata, ArrayList<ScanTableColumnIdentifier>* columns, String* trxDir, int indexSerial, ThreadContext* ctx);
	virtual ~ScanResultIndex() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	ScanTableMetadata* metadata;
	IArrayObjectPrimitive<int>* colsOrders;
	ArrayList<ScanTableColumnIdentifier>* columns;
	IBTree* btree;
	String* storagePath;
	String* trxDir;
	int indexSerial;
public:
	void switchToDisk(AlinousDatabase* database, ThreadContext* ctx);
	bool hasColumns(ArrayList<ScanTableColumnIdentifier>* indexColumns, ThreadContext* ctx) throw() ;
	void addIndex(ScanResultRecord* scanedRecord, ThreadContext* ctx);
	IBTree* getBtree(ThreadContext* ctx) throw() ;
	void dispose(ISystemLog* logger, ThreadContext* ctx) throw() ;
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

#endif /* end of ALINOUS_DB_TRX_SCAN_SCANRESULTINDEX_H_ */
