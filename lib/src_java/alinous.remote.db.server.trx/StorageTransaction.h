#ifndef ALINOUS_REMOTE_DB_SERVER_TRX_STORAGETRANSACTION_H_
#define ALINOUS_REMOTE_DB_SERVER_TRX_STORAGETRANSACTION_H_
namespace alinous {namespace db {namespace trx {
class DbVersionContext;}}}

namespace alinous {namespace remote {namespace db {namespace server {
class RemoteTableStorageServer;}}}}

namespace alinous {namespace db {namespace table {
class IDatabaseRecord;}}}

namespace alinous {namespace db {namespace table {
class IDatabaseTable;}}}

namespace java {namespace util {
template <typename  T> class List;}}

namespace alinous {namespace remote {namespace region {namespace server {namespace schema {namespace strategy {
class UniqueCheckOperation;}}}}}}

namespace alinous {namespace remote {namespace region {namespace client {namespace command {namespace data {
class ClientNetworkRecord;}}}}}}

namespace alinous {namespace remote {namespace region {namespace server {namespace schema {namespace strategy {
class UniqueOpValue;}}}}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanUnique;}}}}

namespace alinous {namespace lock {namespace unique {
class UniqueExclusiveLock;}}}

namespace alinous {namespace lock {namespace unique {
class UniqueExclusiveException;}}}

namespace alinous {namespace db {namespace table {
class TableColumnMetadata;}}}

namespace alinous {namespace db {namespace table {
class IScannableIndex;}}}

namespace alinous {namespace btree {
class BTree;}}

namespace alinous {namespace btree {namespace scan {
class BTreeScanner;}}}

namespace alinous {namespace runtime {namespace variant {
class VariantValue;}}}

namespace alinous {namespace btree {
class IBTreeKey;}}

namespace alinous {namespace db {namespace table {
class BTreeIndexKey;}}}

namespace alinous {namespace btree {
class IBTreeNode;}}

namespace alinous {namespace btree {
class IBTreeValue;}}

namespace alinous {namespace db {namespace table {
class TableIndexValue;}}}

namespace java {namespace lang {
class StringBuilder;}}

namespace alinous {namespace lock {namespace unique {
class UniqueExclusiveLockManager;}}}

namespace java {namespace io {
class IOException;}}

namespace alinous {namespace btree {
class BTreeException;}}

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

namespace alinous {namespace remote {namespace db {namespace server {namespace trx {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::IOException;
using ::java::util::ArrayList;
using ::java::util::List;
using ::alinous::btree::BTree;
using ::alinous::btree::BTreeException;
using ::alinous::btree::IBTreeKey;
using ::alinous::btree::IBTreeNode;
using ::alinous::btree::IBTreeValue;
using ::alinous::btree::scan::BTreeScanner;
using ::alinous::compile::sql::analyze::ScanUnique;
using ::alinous::db::table::BTreeIndexKey;
using ::alinous::db::table::IDatabaseRecord;
using ::alinous::db::table::IDatabaseTable;
using ::alinous::db::table::IScannableIndex;
using ::alinous::db::table::TableColumnMetadata;
using ::alinous::db::table::TableIndexValue;
using ::alinous::db::trx::DbVersionContext;
using ::alinous::lock::unique::UniqueExclusiveException;
using ::alinous::lock::unique::UniqueExclusiveLock;
using ::alinous::lock::unique::UniqueExclusiveLockManager;
using ::alinous::remote::db::server::RemoteTableStorageServer;
using ::alinous::remote::region::client::command::data::ClientNetworkRecord;
using ::alinous::remote::region::server::schema::strategy::UniqueCheckOperation;
using ::alinous::remote::region::server::schema::strategy::UniqueOpValue;
using ::alinous::runtime::dom::VariableException;
using ::alinous::runtime::variant::VariantValue;
using ::alinous::system::AlinousException;



class StorageTransaction : public virtual IObject {
public:
	StorageTransaction(const StorageTransaction& base) = default;
public:
	StorageTransaction(int isolationLevel, DbVersionContext* vctx, String* datadir, RemoteTableStorageServer* server, ThreadContext* ctx) throw() ;
	void __construct_impl(int isolationLevel, DbVersionContext* vctx, String* datadir, RemoteTableStorageServer* server, ThreadContext* ctx) throw() ;
	virtual ~StorageTransaction() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	int isolationLevel;
	DbVersionContext* vctx;
	String* datadir;
	String* tmpDir;
	RemoteTableStorageServer* server;
	UniqueExclusiveLockManager* uniqueLockMgr;
	List<UniqueExclusiveLock>* uniqueLocks;
public:
	virtual bool isVisible(IDatabaseRecord* record, ThreadContext* ctx) throw()  = 0;
	void prepareInsert(IDatabaseTable* table, List<UniqueCheckOperation>* uniqueCheckOps, List<ClientNetworkRecord>* records, ThreadContext* ctx);
	void unlockUniqueAll(ThreadContext* ctx) throw() ;
	String* getTmpDir(ThreadContext* ctx) throw() ;
	int getIsolationLevel(ThreadContext* ctx) throw() ;
	DbVersionContext* getVctx(ThreadContext* ctx) throw() ;
	void dispose(ThreadContext* ctx) throw() ;
	RemoteTableStorageServer* getServer(ThreadContext* ctx) throw() ;
private:
	void checkUnique(IDatabaseTable* table, List<UniqueCheckOperation>* uniqueCheckOps, ThreadContext* ctx);
	void handleUniqueOp(IDatabaseTable* table, UniqueCheckOperation* op, ThreadContext* ctx);
	bool findUnique(IDatabaseTable* table, List<TableColumnMetadata>* cols, List<VariantValue>* valuesList, BTreeScanner* scanner, ThreadContext* ctx);
	bool checkUniqueValueWithBtreeValues(ArrayList<IBTreeValue>* values, IDatabaseTable* table, List<TableColumnMetadata>* cols, List<VariantValue>* valuesList, ThreadContext* ctx);
	bool checkEquals(IDatabaseRecord* record, List<TableColumnMetadata>* cols, List<VariantValue>* valuesList, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}}

#endif /* end of ALINOUS_REMOTE_DB_SERVER_TRX_STORAGETRANSACTION_H_ */
