#ifndef ALINOUS_DB_TABLE_CACHE_RECORDCACHEENGINE_H_
#define ALINOUS_DB_TABLE_CACHE_RECORDCACHEENGINE_H_
namespace alinous {namespace db {namespace table {namespace cache {
class RecordCacheEngine;}}}}

namespace alinous {namespace db {namespace table {namespace cache {
class DbRecordCache;}}}}

namespace alinous {namespace db {namespace table {
class DatatableUpdateSupport;}}}

namespace alinous {namespace db {namespace table {
class DatabaseRecord;}}}

namespace alinous {namespace runtime {namespace parallel {
class SequentialBackgroundJob;}}}

namespace alinous {namespace system {
class ISystemLog;}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryWriter;}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryBuilder;}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntry;}}}

namespace alinous {namespace db {namespace table {
class OidIndexJob;}}}

namespace alinous {namespace db {namespace table {
class IndexInsertJob;}}}

namespace alinous {namespace db {namespace table {
class TableIndex;}}}

namespace alinous {namespace db {
class AlinousDbException;}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace java {namespace lang {
class Throwable;}}

namespace alinous {namespace db {namespace table {
class IDatabaseRecord;}}}

namespace alinous {namespace db {namespace table {
class DataTableStorageSupport;}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorage;}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryReader;}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryFetcher;}}}

namespace java {namespace io {
class IOException;}}

namespace alinous {namespace btree {
class BTreeException;}}

namespace alinous {namespace system {
class AlinousException;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace db {namespace table {namespace cache {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::IOException;
using ::java::util::ArrayList;
using ::alinous::btree::BTreeException;
using ::alinous::buffer::storage::FileStorage;
using ::alinous::buffer::storage::FileStorageEntry;
using ::alinous::buffer::storage::FileStorageEntryBuilder;
using ::alinous::buffer::storage::FileStorageEntryFetcher;
using ::alinous::buffer::storage::FileStorageEntryReader;
using ::alinous::buffer::storage::FileStorageEntryWriter;
using ::alinous::db::AlinousDbException;
using ::alinous::db::table::DataTableStorageSupport;
using ::alinous::db::table::DatabaseRecord;
using ::alinous::db::table::DatatableUpdateSupport;
using ::alinous::db::table::IDatabaseRecord;
using ::alinous::db::table::IndexInsertJob;
using ::alinous::db::table::OidIndexJob;
using ::alinous::db::table::TableIndex;
using ::alinous::runtime::dom::VariableException;
using ::alinous::runtime::parallel::SequentialBackgroundJob;
using ::alinous::system::AlinousException;
using ::alinous::system::ISystemLog;



class RecordCacheEngine final : public virtual IObject {
public:
	RecordCacheEngine(const RecordCacheEngine& base) = default;
public:
	RecordCacheEngine(ThreadContext* ctx) throw()  : IObject(ctx), maxCache(0), cache(nullptr)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~RecordCacheEngine() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	int maxCache;
	DbRecordCache* cache;
public:
	RecordCacheEngine* init(int maxCache, ThreadContext* ctx);
	void insertData(DatatableUpdateSupport* table, DatabaseRecord* dbrecord, long long commitId, IArrayObject<SequentialBackgroundJob>* jobs, ISystemLog* log, ThreadContext* ctx);
	IDatabaseRecord* loadRecord(DataTableStorageSupport* table, long long filePointer, ThreadContext* ctx);
	int getMaxCache(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_DB_TABLE_CACHE_RECORDCACHEENGINE_H_ */
