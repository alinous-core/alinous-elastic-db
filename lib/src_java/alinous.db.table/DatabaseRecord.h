#ifndef ALINOUS_DB_TABLE_DATABASERECORD_H_
#define ALINOUS_DB_TABLE_DATABASERECORD_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace runtime {namespace variant {
class VariantValue;}}}

namespace alinous {namespace db {namespace table {
class IDatabaseRecord;}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryBuilder;}}}

namespace alinous {namespace db {namespace table {
class DatabaseRecord;}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryFetcher;}}}

namespace alinous {namespace btree {
class IValueFetcher;}}

namespace java {namespace lang {
class StringBuilder;}}

namespace alinous {namespace db {namespace table {
class IDatabaseTable;}}}

namespace alinous {namespace btree {
class IBTreeValue;}}

namespace alinous {namespace db {namespace trx {namespace cache {
class CachedRecord;}}}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

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
using ::java::util::ArrayList;
using ::alinous::btree::IBTreeValue;
using ::alinous::btree::IValueFetcher;
using ::alinous::buffer::storage::FileStorageEntryBuilder;
using ::alinous::buffer::storage::FileStorageEntryFetcher;
using ::alinous::db::trx::cache::CachedRecord;
using ::alinous::runtime::dom::VariableException;
using ::alinous::runtime::variant::VariantValue;



class DatabaseRecord final : public IDatabaseRecord, public virtual IObject {
public:
	class ValueFetcher;
	DatabaseRecord(const DatabaseRecord& base) = default;
public:
	DatabaseRecord(long long oid, int numColumn, long long CommitId, ThreadContext* ctx) throw() ;
	void __construct_impl(long long oid, int numColumn, long long CommitId, ThreadContext* ctx) throw() ;
	DatabaseRecord(long long oid, int numColumn, long long CommitId, IDatabaseRecord* data, ThreadContext* ctx) throw() ;
	void __construct_impl(long long oid, int numColumn, long long CommitId, IDatabaseRecord* data, ThreadContext* ctx) throw() ;
	virtual ~DatabaseRecord() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	long long position;
	long long oid;
	long long lastUpdateCommitId;
	long long insertedCommitId;
	long long deletedCommitId;
	ArrayList<VariantValue>* values;
	IDatabaseTable* storageForCache;
	int hashcode;
public:
	int getNumValues(ThreadContext* ctx) throw()  final;
	VariantValue* getColumnValue(int index, ThreadContext* ctx) throw()  final;
	void setValue(int index, VariantValue* value, ThreadContext* ctx) throw()  final;
	void addValue(VariantValue* vv, ThreadContext* ctx) throw()  final;
	void appendToEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx) final;
	int diskSize(ThreadContext* ctx) final;
	IValueFetcher* getFetcher(ThreadContext* ctx) throw()  final;
	long long getOid(ThreadContext* ctx) throw()  final;
	void setOid(long long oid, ThreadContext* ctx) throw() ;
	long long getLastUpdateCommitId(ThreadContext* ctx) throw()  final;
	void setLastUpdateCommitId(long long lastUpdateCommitId, ThreadContext* ctx) throw()  final;
	long long getInsertedCommitId(ThreadContext* ctx) throw()  final;
	void setInsertedCommitId(long long insertedCommitId, ThreadContext* ctx) throw()  final;
	long long getDeletedCommitId(ThreadContext* ctx) throw()  final;
	void setDeletedCommitId(long long deletedCommitId, ThreadContext* ctx) throw() ;
	long long getMaxCommitId(ThreadContext* ctx) throw()  final;
	String* toString(ThreadContext* ctx) throw() ;
	long long getPosition(ThreadContext* ctx) throw() ;
	void setPosition(long long position, ThreadContext* ctx) throw() ;
	bool equals(IObject* obj, ThreadContext* ctx) throw()  final;
	int getHashKey(ThreadContext* ctx) throw() ;
	IDatabaseTable* getStorageForCache(ThreadContext* ctx) throw() ;
	void setStorageForCache(IDatabaseTable* storageForCache, ThreadContext* ctx) throw() ;
	ArrayList<VariantValue>* getValues(ThreadContext* ctx) throw()  final;
	int getKind(ThreadContext* ctx) throw()  final;
	int getNumColumn(ThreadContext* ctx) throw()  final;
public:
	static DatabaseRecord* valueFromFetcher(FileStorageEntryFetcher* fetcher, ThreadContext* ctx);
public:



	class ValueFetcher final : public IValueFetcher, public virtual IObject {
	public:
		ValueFetcher(const ValueFetcher& base) = default;
	public:
		ValueFetcher(ThreadContext* ctx) throw() ;
		void __construct_impl(ThreadContext* ctx) throw() ;
		virtual ~ValueFetcher() throw();
		virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
	public:
		IBTreeValue* valueFromFetcher(FileStorageEntryFetcher* fetcher, ThreadContext* ctx) final;
	public:
		static bool __init_done;
		static bool __init_static_variables();
	public:
		static void __cleanUp(ThreadContext* ctx);
	};

	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_DB_TABLE_DATABASERECORD_H_ */
