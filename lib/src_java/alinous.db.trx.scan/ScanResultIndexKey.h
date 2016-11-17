#ifndef ALINOUS_DB_TRX_SCAN_SCANRESULTINDEXKEY_H_
#define ALINOUS_DB_TRX_SCAN_SCANRESULTINDEXKEY_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace runtime {namespace variant {
class VariantValue;}}}

namespace alinous {namespace btree {
class IBTreeKey;}}

namespace alinous {namespace db {namespace trx {namespace scan {
class ScanResultIndexKey;}}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryBuilder;}}}

namespace alinous {namespace db {namespace table {
class BTreeIndexKey;}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryFetcher;}}}

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
using ::alinous::btree::IBTreeKey;
using ::alinous::buffer::storage::FileStorageEntryBuilder;
using ::alinous::buffer::storage::FileStorageEntryFetcher;
using ::alinous::db::table::BTreeIndexKey;
using ::alinous::runtime::dom::VariableException;
using ::alinous::runtime::variant::VariantValue;



class ScanResultIndexKey final : public IBTreeKey, public virtual IObject {
public:
	ScanResultIndexKey(const ScanResultIndexKey& base) = default;
public:
	ScanResultIndexKey(ThreadContext* ctx) throw()  : IObject(ctx), IBTreeKey(ctx), values(GCUtils<ArrayList<VariantValue> >::ins(this, (new(ctx) ArrayList<VariantValue>(ctx)), ctx, __FILEW__, __LINE__, L""))
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~ScanResultIndexKey() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	ArrayList<VariantValue>* values;
public:
	void addKeyValue(VariantValue* vv, ThreadContext* ctx) throw() ;
	int compareTo(IBTreeKey* another, ThreadContext* ctx) throw() ;
	int getNumCols(ThreadContext* ctx) throw() ;
	VariantValue* get(int index, ThreadContext* ctx) throw() ;
	bool equals(IObject* obj, ThreadContext* ctx) throw() ;
	void appendToEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx) final;
	int size(ThreadContext* ctx) final;
public:
	static BTreeIndexKey* fetchFromEntry(FileStorageEntryFetcher* fetcher, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
	class ValueCompare {
	public:
		int operator() (IBTreeKey* _this, IBTreeKey* another, ThreadContext* ctx) const throw();
	};
};

}}}}

#endif /* end of ALINOUS_DB_TRX_SCAN_SCANRESULTINDEXKEY_H_ */
