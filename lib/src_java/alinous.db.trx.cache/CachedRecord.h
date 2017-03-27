#ifndef ALINOUS_DB_TRX_CACHE_CACHEDRECORD_H_
#define ALINOUS_DB_TRX_CACHE_CACHEDRECORD_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace runtime {namespace variant {
class VariantValue;}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryBuilder;}}}

namespace alinous {namespace db {namespace trx {namespace cache {
class CachedRecord;}}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryFetcher;}}}

namespace alinous {namespace btree {
class IValueFetcher;}}

namespace java {namespace lang {
class StringBuilder;}}

namespace alinous {namespace db {namespace table {
class IDatabaseRecord;}}}

namespace alinous {namespace btree {
class IBTreeValue;}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace db {namespace trx {namespace cache {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::ArrayList;
using ::alinous::btree::IBTreeValue;
using ::alinous::btree::IValueFetcher;
using ::alinous::buffer::storage::FileStorageEntryBuilder;
using ::alinous::buffer::storage::FileStorageEntryFetcher;
using ::alinous::db::table::IDatabaseRecord;
using ::alinous::runtime::dom::VariableException;
using ::alinous::runtime::variant::VariantValue;



class CachedRecord final : public IDatabaseRecord, public virtual IObject {
public:
	class ValueFetcher;
	CachedRecord(const CachedRecord& base) = default;
public:
	CachedRecord(long long oid, int numColumn, ThreadContext* ctx) throw() ;
	void __construct_impl(long long oid, int numColumn, ThreadContext* ctx) throw() ;
	virtual ~CachedRecord() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	long long oid;
	long long lastUpdateCommitId;
	long long insertedCommitId;
	long long deletedCommitId;
	ArrayList<VariantValue>* values;
public:
	const static CachedRecord::ValueFetcher __fetcher;
	constexpr static CachedRecord::ValueFetcher* fetcher{const_cast<CachedRecord::ValueFetcher*>(&__fetcher)};
public:
	long long getOid(ThreadContext* ctx) throw()  final;
	void setValue(int index, VariantValue* value, ThreadContext* ctx) throw()  final;
	int getNumColumn(ThreadContext* ctx) throw()  final;
	VariantValue* getColumnValue(int index, ThreadContext* ctx) throw()  final;
	void set(int index, VariantValue* vv, ThreadContext* ctx) throw() ;
	void appendToEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx) final;
	int diskSize(ThreadContext* ctx) final;
	IValueFetcher* getFetcher(ThreadContext* ctx) throw()  final;
	bool equals(IObject* obj, ThreadContext* ctx) throw()  final;
	int getNumValues(ThreadContext* ctx) throw()  final;
	String* toString(ThreadContext* ctx) throw() ;
	long long getLastUpdateCommitId(ThreadContext* ctx) throw()  final;
	long long getInsertedCommitId(ThreadContext* ctx) throw()  final;
	long long getDeletedCommitId(ThreadContext* ctx) throw()  final;
	void setLastUpdateCommitId(long long lastUpdateCommitId, ThreadContext* ctx) throw()  final;
	void setInsertedCommitId(long long insertedCommitId, ThreadContext* ctx) throw()  final;
	void setDeletedCommitId(long long deletedCommitId, ThreadContext* ctx) throw() ;
	ArrayList<VariantValue>* getValues(ThreadContext* ctx) throw()  final;
	int getKind(ThreadContext* ctx) throw()  final;
	void addValue(VariantValue* vv, ThreadContext* ctx) throw()  final;
	long long getMaxCommitId(ThreadContext* ctx) throw()  final;
	void setOid(long long oid, ThreadContext* ctx) throw() ;
	long long getPosition(ThreadContext* ctx) throw()  final;
public:
	static CachedRecord* valueFromFetcher(FileStorageEntryFetcher* fetcher, ThreadContext* ctx);
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

}}}}

#endif /* end of ALINOUS_DB_TRX_CACHE_CACHEDRECORD_H_ */
