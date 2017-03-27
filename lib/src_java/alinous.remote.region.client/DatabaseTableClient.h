#ifndef ALINOUS_REMOTE_REGION_CLIENT_DATABASETABLECLIENT_H_
#define ALINOUS_REMOTE_REGION_CLIENT_DATABASETABLECLIENT_H_
namespace java{namespace net{
class UnknownHostException;
}}
namespace alinous {namespace db {namespace table {
class TableMetadata;}}}

namespace alinous {namespace remote {namespace socket {
class SocketConnectionPool;}}}

namespace java {namespace lang {
class Integer;}}

namespace alinous {namespace db {namespace table {
class IScannableIndex;}}}

namespace java {namespace util {
template <typename  T> class List;}}

namespace alinous {namespace db {namespace table {
class TableColumnMetadata;}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableColumnIdentifier;}}}}

namespace alinous {namespace db {namespace table {
class IDatabaseRecord;}}}

namespace alinous {namespace db {namespace table {namespace lockmonitor {
class IThreadLocker;}}}}

namespace alinous {namespace db {namespace table {namespace lockmonitor {
class ThreadLocker;}}}}

namespace alinous {namespace system {
class AlinousCore;}}

namespace alinous {namespace btree {
class BTreeGlobalCache;}}

namespace alinous {namespace runtime {namespace parallel {
class ThreadPool;}}}

namespace alinous {namespace db {namespace trx {
class DbTransaction;}}}

namespace alinous {namespace runtime {namespace parallel {
class SequentialBackgroundJob;}}}

namespace alinous {namespace system {
class ISystemLog;}}

namespace alinous {namespace remote {namespace region {namespace client {namespace command {namespace dml {
class ClientTpcCommitSessionCommand;}}}}}}

namespace alinous {namespace db {namespace trx {
class DbVersionContext;}}}

namespace alinous {namespace remote {namespace socket {
class ISocketConnection;}}}

namespace alinous {namespace net {
class AlinousSocket;}}

namespace alinous {namespace db {
class AlinousDbException;}}

namespace java {namespace io {
class IOException;}}

namespace alinous {namespace system {
class AlinousException;}}

namespace alinous {namespace remote {namespace region {namespace client {namespace command {namespace dml {
class ClientInsertDataCommand;}}}}}}

namespace alinous {namespace remote {namespace region {namespace client {namespace command {namespace data {
class ClientNetworkRecord;}}}}}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace alinous {namespace db {namespace table {
class IDatabaseTable;}}}

namespace alinous {namespace btree {
class BTreeException;}}

namespace alinous {namespace db {namespace table {
class DatabaseException;}}}

namespace alinous {namespace db {namespace table {
class DatabaseTableIdPublisher;}}}

namespace alinous {namespace db {namespace table {namespace lockmonitor {
class DatabaseLockException;}}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace remote {namespace region {namespace client {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::IOException;
using ::java::net::UnknownHostException;
using ::java::util::ArrayList;
using ::java::util::List;
using ::alinous::btree::BTreeException;
using ::alinous::btree::BTreeGlobalCache;
using ::alinous::compile::sql::analyze::ScanTableColumnIdentifier;
using ::alinous::db::AlinousDbException;
using ::alinous::db::table::DatabaseException;
using ::alinous::db::table::DatabaseTableIdPublisher;
using ::alinous::db::table::IDatabaseRecord;
using ::alinous::db::table::IDatabaseTable;
using ::alinous::db::table::IScannableIndex;
using ::alinous::db::table::TableColumnMetadata;
using ::alinous::db::table::TableMetadata;
using ::alinous::db::table::lockmonitor::DatabaseLockException;
using ::alinous::db::table::lockmonitor::IThreadLocker;
using ::alinous::db::table::lockmonitor::ThreadLocker;
using ::alinous::db::trx::DbTransaction;
using ::alinous::db::trx::DbVersionContext;
using ::alinous::net::AlinousSocket;
using ::alinous::remote::region::client::command::data::ClientNetworkRecord;
using ::alinous::remote::region::client::command::dml::ClientInsertDataCommand;
using ::alinous::remote::region::client::command::dml::ClientTpcCommitSessionCommand;
using ::alinous::remote::socket::ISocketConnection;
using ::alinous::remote::socket::SocketConnectionPool;
using ::alinous::runtime::dom::VariableException;
using ::alinous::runtime::parallel::SequentialBackgroundJob;
using ::alinous::runtime::parallel::ThreadPool;
using ::alinous::system::AlinousCore;
using ::alinous::system::AlinousException;
using ::alinous::system::ISystemLog;



class DatabaseTableClient final : public IDatabaseTable, public virtual IObject {
public:
	DatabaseTableClient(const DatabaseTableClient& base) = default;
public:
	DatabaseTableClient(String* schema, String* name, TableMetadata* metadata, SocketConnectionPool* regionAccessPool, ThreadContext* ctx) throw() ;
	void __construct_impl(String* schema, String* name, TableMetadata* metadata, SocketConnectionPool* regionAccessPool, ThreadContext* ctx) throw() ;
	virtual ~DatabaseTableClient() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	Integer* tableId;
	SocketConnectionPool* regionAccessPool;
private:
	TableMetadata* metadata;
	String* schema;
	String* name;
	String* fullName;
	ArrayList<IScannableIndex>* indexes;
	IScannableIndex* primaryIndex;
public:
	void updateMetadata(TableMetadata* metadata, ThreadContext* ctx) throw() ;
	Integer* getTableId(ThreadContext* ctx) throw()  final;
	int getColumnCount(ThreadContext* ctx) throw()  final;
	IScannableIndex* getTableUniqueIndexByCols(List<TableColumnMetadata>* columns, ThreadContext* ctx) throw()  final;
	IScannableIndex* getTableIndexByColIds(ArrayList<ScanTableColumnIdentifier>* columns, ThreadContext* ctx) throw()  final;
	IScannableIndex* getPrimaryIndex(ThreadContext* ctx) throw()  final;
	TableMetadata* getMetadata(ThreadContext* ctx) throw()  final;
	IDatabaseRecord* loadRecord(long long position, ThreadContext* ctx) final;
	IScannableIndex* getAbailableIndex(ArrayList<String>* columns, ThreadContext* ctx) throw()  final;
	IScannableIndex* getAbailableIndexByScanColId(ArrayList<ScanTableColumnIdentifier>* columns, ThreadContext* ctx) throw()  final;
	IScannableIndex* getTableIndex(ArrayList<String>* columns, ThreadContext* ctx) throw()  final;
	IThreadLocker* newThreadLocker(String* fullName, ThreadContext* ctx) throw()  final;
	void updateUnlockRow(long long oid, IThreadLocker* locker, ThreadContext* ctx) final;
	void updateLockRow(long long oid, IThreadLocker* locker, ThreadContext* ctx) final;
	void shareUnlockRow(long long oid, IThreadLocker* locker, ThreadContext* ctx) final;
	void shareLockRow(long long oid, IThreadLocker* locker, ThreadContext* ctx) final;
	void shareUnlockTable(IThreadLocker* locker, ThreadContext* ctx) final;
	void shareLockTable(IThreadLocker* locker, ThreadContext* ctx) final;
	void updateUnlockTable(IThreadLocker* locker, ThreadContext* ctx) final;
	void updateLockTable(IThreadLocker* locker, ThreadContext* ctx) final;
	bool hasLaterVersion(long long oid, long long currentId, ThreadContext* ctx) final;
	bool hasLaterVersionBefore(long long oid, long long maxCommitId, long long currentCommitId, ThreadContext* ctx) final;
	String* getName(ThreadContext* ctx) throw()  final;
	void open(AlinousCore* core, BTreeGlobalCache* cache, ThreadContext* ctx) final;
	void createTable(TableMetadata* metadata, ThreadPool* threadPool, AlinousCore* core, BTreeGlobalCache* cache, ThreadContext* ctx) final;
	void lockStorage(ThreadContext* ctx) final;
	void unlockStorage(ThreadContext* ctx) final;
	ArrayList<IScannableIndex>* getIndexes(ThreadContext* ctx) throw()  final;
	void insertData(DbTransaction* trx, IDatabaseRecord* record, long long newCommitId, IArrayObject<SequentialBackgroundJob>* jobs, ISystemLog* logger, ThreadContext* ctx) final;
	void insertData(DbTransaction* trx, List<IDatabaseRecord>* records, long long newCommitId, IArrayObject<SequentialBackgroundJob>* jobs, ISystemLog* logger, ThreadContext* ctx) final;
	void finishCommitSession(DbTransaction* trx, long long newCommitId, ThreadContext* ctx) final;
	void updateData(IDatabaseRecord* record, long long newCommitId, IArrayObject<SequentialBackgroundJob>* jobs, ISystemLog* logger, ThreadContext* ctx) final;
	void createIndex(String* getindexName, ArrayList<String>* columns, AlinousCore* core, BTreeGlobalCache* cache, ThreadContext* ctx) final;
	void close(ThreadContext* ctx) throw()  final;
	String* getFullName(ThreadContext* ctx) throw()  final;
	void tcpInsertCommit(IDatabaseRecord* data, ThreadPool* pool, ISystemLog* log, ThreadContext* ctx) throw()  final;
private:
	bool matchUniqueIndexByIdList(ArrayList<TableColumnMetadata>* columnsMetadataList, List<TableColumnMetadata>* columns, ThreadContext* ctx) throw() ;
	bool matchIndexByIdList(ArrayList<TableColumnMetadata>* columnsMetadataList, ArrayList<ScanTableColumnIdentifier>* columns, ThreadContext* ctx) throw() ;
	bool matchIndexByStrList(ArrayList<TableColumnMetadata>* columnsMetadataList, ArrayList<String>* columns, ThreadContext* ctx) throw() ;
	void doInsertData(DbTransaction* trx, List<IDatabaseRecord>* records, long long newCommitId, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}

#endif /* end of ALINOUS_REMOTE_REGION_CLIENT_DATABASETABLECLIENT_H_ */
