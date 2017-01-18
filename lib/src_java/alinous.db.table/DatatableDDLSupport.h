#ifndef ALINOUS_DB_TABLE_DATATABLEDDLSUPPORT_H_
#define ALINOUS_DB_TABLE_DATATABLEDDLSUPPORT_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace db {namespace table {
class TableMetadata;}}}

namespace alinous {namespace runtime {namespace parallel {
class ThreadPool;}}}

namespace alinous {namespace system {
class AlinousCore;}}

namespace alinous {namespace btree {
class BTreeGlobalCache;}}

namespace java {namespace io {
class File;}}

namespace alinous {namespace buffer {namespace storage {
class FileStorage;}}}

namespace alinous {namespace btree {
class BTree;}}

namespace java {namespace lang {
class StringBuilder;}}

namespace alinous {namespace db {namespace table {
class TableIndex;}}}

namespace alinous {namespace db {namespace table {
class DatatableUpdateCache;}}}

namespace java {namespace sql {
class Timestamp;}}

namespace java {namespace io {
class IOException;}}

namespace java {namespace lang {
class InterruptedException;}}

namespace alinous {namespace btree {
class BTreeException;}}

namespace alinous {namespace db {namespace table {
class DatabaseException;}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace alinous {namespace db {namespace table {
class TableIndexMetadata;}}}

namespace alinous {namespace db {
class AlinousDbException;}}

namespace java {namespace lang {
class Throwable;}}

namespace alinous {namespace btree {namespace scan {
class BTreeScanner;}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryReader;}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntry;}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryFetcher;}}}

namespace alinous {namespace btree {
class IBTreeNode;}}

namespace alinous {namespace btree {
class IBTreeValue;}}

namespace alinous {namespace btree {
class LongValue;}}

namespace alinous {namespace db {namespace table {
class DatabaseRecord;}}}

namespace alinous {namespace db {namespace table {
class DatatableLockSupport;}}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace db {namespace table {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::File;
using ::java::io::IOException;
using ::java::sql::Timestamp;
using ::java::util::ArrayList;
using ::alinous::btree::BTree;
using ::alinous::btree::BTreeException;
using ::alinous::btree::BTreeGlobalCache;
using ::alinous::btree::IBTreeNode;
using ::alinous::btree::IBTreeValue;
using ::alinous::btree::LongValue;
using ::alinous::btree::scan::BTreeScanner;
using ::alinous::buffer::storage::FileStorage;
using ::alinous::buffer::storage::FileStorageEntry;
using ::alinous::buffer::storage::FileStorageEntryFetcher;
using ::alinous::buffer::storage::FileStorageEntryReader;
using ::alinous::db::AlinousDbException;
using ::alinous::runtime::parallel::ThreadPool;
using ::alinous::system::AlinousCore;
using ::alinous::system::AlinousException;



class DatatableDDLSupport : public DatatableLockSupport {
public:
	DatatableDDLSupport(const DatatableDDLSupport& base) = default;
public:
	DatatableDDLSupport(String* schema, String* name, String* baseDir, ThreadContext* ctx) throw() ;
	void __construct_impl(String* schema, String* name, String* baseDir, ThreadContext* ctx) throw() ;
	virtual ~DatatableDDLSupport() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	void createTable(TableMetadata* metadata, ThreadPool* threadPool, AlinousCore* core, BTreeGlobalCache* cache, ThreadContext* ctx) final;
	void createIndex(String* indexName, ArrayList<String>* columns, AlinousCore* core, BTreeGlobalCache* cache, ThreadContext* ctx) final;
private:
	void buildFirstindexValue(TableIndex* newindex, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_DB_TABLE_DATATABLEDDLSUPPORT_H_ */
