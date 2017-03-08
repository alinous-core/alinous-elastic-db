#ifndef ALINOUS_DB_TABLE_DATATABLEUPDATECACHE_H_
#define ALINOUS_DB_TABLE_DATATABLEUPDATECACHE_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace db {namespace table {
class TableIndex;}}}

namespace alinous {namespace db {namespace table {
class DatatableConstants;}}}

namespace alinous {namespace db {namespace table {
class AbstractDatabaseTable;}}}

namespace alinous {namespace system {
class AlinousCore;}}

namespace alinous {namespace btree {
class BTreeGlobalCache;}}

namespace alinous {namespace btree {
class BTree;}}

namespace java {namespace io {
class File;}}

namespace alinous {namespace db {namespace table {
class DatabaseException;}}}

namespace java {namespace lang {
class Throwable;}}

namespace alinous {namespace db {namespace trx {namespace scan {
class ITableTargetScanner;}}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableIdentifier;}}}}

namespace alinous {namespace db {namespace trx {
class DbTransaction;}}}

namespace alinous {namespace db {namespace table {namespace scan {
class UpdateHistoryBTreeIndexScanner;}}}}

namespace alinous {namespace db {namespace table {
class DatabaseRecord;}}}

namespace alinous {namespace btree {
class LongKey;}}

namespace java {namespace io {
class IOException;}}

namespace java {namespace lang {
class InterruptedException;}}

namespace java {namespace lang {
class StringBuilder;}}

namespace alinous {namespace btree {
class IBTree;}}

namespace alinous {namespace btree {
class BTreeException;}}

namespace alinous {namespace btree {
class IBTreeValue;}}

namespace alinous {namespace system {
class AlinousException;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace db {namespace table {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::File;
using ::java::io::IOException;
using ::alinous::btree::BTree;
using ::alinous::btree::BTreeException;
using ::alinous::btree::BTreeGlobalCache;
using ::alinous::btree::IBTree;
using ::alinous::btree::IBTreeValue;
using ::alinous::btree::LongKey;
using ::alinous::compile::sql::analyze::ScanTableIdentifier;
using ::alinous::db::table::scan::UpdateHistoryBTreeIndexScanner;
using ::alinous::db::trx::DbTransaction;
using ::alinous::db::trx::scan::ITableTargetScanner;
using ::alinous::system::AlinousCore;
using ::alinous::system::AlinousException;



class DatatableUpdateCache final : public virtual IObject {
public:
	DatatableUpdateCache(const DatatableUpdateCache& base) = default;
public:
	DatatableUpdateCache(AbstractDatabaseTable* tableStore, ThreadContext* ctx) throw() ;
	void __construct_impl(AbstractDatabaseTable* tableStore, ThreadContext* ctx) throw() ;
	virtual ~DatatableUpdateCache() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	IBTree* store;
	String* name;
	String* baseDir;
	String* oidIndexPath;
public:
	void execCreateTable(AlinousCore* core, BTreeGlobalCache* cache, ThreadContext* ctx);
	void open(AlinousCore* core, BTreeGlobalCache* cache, ThreadContext* ctx);
	ITableTargetScanner* getScanner(ScanTableIdentifier* tableId, long long commitId, DbTransaction* trx, ThreadContext* ctx);
	void addHistory(DatabaseRecord* oldRecord, ThreadContext* ctx);
	void close(ThreadContext* ctx) throw() ;
private:
	String* getOidIndexName(ThreadContext* ctx) throw() ;
public:
	static void includes(TableIndex* arg0, DatatableConstants* arg2, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_DB_TABLE_DATATABLEUPDATECACHE_H_ */
