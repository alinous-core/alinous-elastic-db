#ifndef ALINOUS_DB_TRX_SCAN_PADDDINGRECORD_H_
#define ALINOUS_DB_TRX_SCAN_PADDDINGRECORD_H_
namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryBuilder;}}}

namespace alinous {namespace db {namespace trx {namespace scan {
class PadddingRecord;}}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryFetcher;}}}

namespace alinous {namespace btree {
class IValueFetcher;}}

namespace alinous {namespace runtime {namespace variant {
class VariantValue;}}}

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

namespace alinous {namespace db {namespace trx {namespace scan {

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



class PadddingRecord final : public IDatabaseRecord, public virtual IObject {
public:
	PadddingRecord(const PadddingRecord& base) = default;
public:
	PadddingRecord(int paddingSize, ThreadContext* ctx) throw() ;
	void __construct_impl(int paddingSize, ThreadContext* ctx) throw() ;
	virtual ~PadddingRecord() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	int paddingSize;
	VariantValue* nullValue;
public:
	void appendToEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx) final;
	int diskSize(ThreadContext* ctx) final;
	bool equals(IObject* obj, ThreadContext* ctx) throw()  final;
	IValueFetcher* getFetcher(ThreadContext* ctx) throw()  final;
	int getKind(ThreadContext* ctx) throw()  final;
	VariantValue* getColumnValue(int colOrder, ThreadContext* ctx) throw()  final;
	int getNumValues(ThreadContext* ctx) throw()  final;
	long long getInsertedCommitId(ThreadContext* ctx) throw()  final;
	long long getLastUpdateCommitId(ThreadContext* ctx) throw()  final;
	long long getDeletedCommitId(ThreadContext* ctx) throw()  final;
	ArrayList<VariantValue>* getValues(ThreadContext* ctx) throw()  final;
	void setValue(int index, VariantValue* value, ThreadContext* ctx) throw()  final;
	void addValue(VariantValue* vv, ThreadContext* ctx) throw()  final;
	long long getOid(ThreadContext* ctx) throw()  final;
	long long getMaxCommitId(ThreadContext* ctx) throw()  final;
	int getNumColumn(ThreadContext* ctx) throw()  final;
	void setLastUpdateCommitId(long long commitId, ThreadContext* ctx) throw()  final;
	void setInsertedCommitId(long long insertedCommitId, ThreadContext* ctx) throw()  final;
public:
	static PadddingRecord* fromFetcher(FileStorageEntryFetcher* fetcher, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_DB_TRX_SCAN_PADDDINGRECORD_H_ */
