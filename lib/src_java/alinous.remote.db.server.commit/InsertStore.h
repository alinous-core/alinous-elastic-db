#ifndef ALINOUS_REMOTE_DB_SERVER_COMMIT_INSERTSTORE_H_
#define ALINOUS_REMOTE_DB_SERVER_COMMIT_INSERTSTORE_H_
namespace alinous {namespace remote {namespace db {namespace server {namespace commit {
class InsertStore;}}}}}

namespace alinous {namespace btreememory {
class BTreeOnMemory;}}

namespace alinous {namespace db {namespace trx {
class DbVersionContext;}}}

namespace alinous {namespace remote {namespace db {namespace server {
class RemoteTableStorageServer;}}}}

namespace alinous {namespace btree {namespace scan {
class BTreeScanner;}}}

namespace alinous {namespace btree {
class IBTreeNode;}}

namespace alinous {namespace remote {namespace db {namespace server {namespace commit {
class TableFullNameKey;}}}}}

namespace alinous {namespace btree {
class IBTreeValue;}}

namespace alinous {namespace db {
class AlinousDbException;}}

namespace java {namespace io {
class IOException;}}

namespace java {namespace lang {
class InterruptedException;}}

namespace alinous {namespace btree {
class BTreeException;}}

namespace alinous {namespace system {
class AlinousException;}}

namespace alinous {namespace db {
class SchemaManager;}}

namespace alinous {namespace db {
class TableSchema;}}

namespace alinous {namespace db {namespace table {
class IDatabaseTable;}}}

namespace alinous {namespace system {
class AlinousCore;}}

namespace alinous {namespace system {
class ISystemLog;}}

namespace alinous {namespace runtime {namespace parallel {
class SequentialBackgroundJob;}}}

namespace alinous {namespace remote {namespace region {namespace client {namespace command {namespace data {
class ClientNetworkRecord;}}}}}}

namespace alinous {namespace remote {namespace db {
class MonitorAccess;}}}

namespace java {namespace lang {
class StringBuilder;}}

namespace java {namespace util {
template <typename  T> class List;}}

namespace alinous {namespace db {namespace table {
class TableMetadata;}}}

namespace alinous {namespace btree {
class IBTree;}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace remote {namespace db {namespace server {namespace commit {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::IOException;
using ::java::util::ArrayList;
using ::java::util::List;
using ::alinous::btree::BTreeException;
using ::alinous::btree::IBTree;
using ::alinous::btree::IBTreeNode;
using ::alinous::btree::IBTreeValue;
using ::alinous::btree::scan::BTreeScanner;
using ::alinous::btreememory::BTreeOnMemory;
using ::alinous::db::AlinousDbException;
using ::alinous::db::SchemaManager;
using ::alinous::db::TableSchema;
using ::alinous::db::table::IDatabaseTable;
using ::alinous::db::table::TableMetadata;
using ::alinous::db::trx::DbVersionContext;
using ::alinous::remote::db::MonitorAccess;
using ::alinous::remote::db::server::RemoteTableStorageServer;
using ::alinous::remote::region::client::command::data::ClientNetworkRecord;
using ::alinous::runtime::dom::VariableException;
using ::alinous::runtime::parallel::SequentialBackgroundJob;
using ::alinous::system::AlinousCore;
using ::alinous::system::AlinousException;
using ::alinous::system::ISystemLog;



class InsertStore final : public virtual IObject {
public:
	InsertStore(const InsertStore& base) = default;
public:
	InsertStore(String* filePath, ThreadContext* ctx) throw() ;
	void __construct_impl(String* filePath, ThreadContext* ctx) throw() ;
	virtual ~InsertStore() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	IBTree* store;
	String* baseDir;
public:
	InsertStore* init(ThreadContext* ctx) throw() ;
	void commitPrepared(long long newCommitId, DbVersionContext* vctx, RemoteTableStorageServer* server, ThreadContext* ctx);
	void add(IDatabaseTable* table, List<ClientNetworkRecord>* records, ThreadContext* ctx);
	IBTree* getStore(ThreadContext* ctx) throw() ;
	String* getBaseDir(ThreadContext* ctx) throw() ;
private:
	void handleCommitTable(long long newCommitId, DbVersionContext* vctx, TableFullNameKey* fullName, ArrayList<IBTreeValue>* values, RemoteTableStorageServer* server, ThreadContext* ctx);
	long long allocOids(RemoteTableStorageServer* server, TableFullNameKey* fullName, int allocNum, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}}

#endif /* end of ALINOUS_REMOTE_DB_SERVER_COMMIT_INSERTSTORE_H_ */
