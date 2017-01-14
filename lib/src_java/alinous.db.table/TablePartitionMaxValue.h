#ifndef ALINOUS_DB_TABLE_TABLEPARTITIONMAXVALUE_H_
#define ALINOUS_DB_TABLE_TABLEPARTITIONMAXVALUE_H_
namespace alinous {namespace runtime {namespace variant {
class VariantValue;}}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryBuilder;}}}

namespace alinous {namespace db {namespace table {
class TablePartitionMaxValue;}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryFetcher;}}}

namespace java {namespace util {
template <typename  T> class List;}}

namespace alinous {namespace db {
class AlinousDbException;}}

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
using ::java::util::List;
using ::alinous::buffer::storage::FileStorageEntryBuilder;
using ::alinous::buffer::storage::FileStorageEntryFetcher;
using ::alinous::db::AlinousDbException;
using ::alinous::runtime::dom::VariableException;
using ::alinous::runtime::variant::VariantValue;



class TablePartitionMaxValue final : public virtual IObject {
public:
	TablePartitionMaxValue(const TablePartitionMaxValue& base) = default;
public:
	TablePartitionMaxValue(ThreadContext* ctx) throw()  : IObject(ctx), values(GCUtils<List<VariantValue> >::ins(this, (new(ctx) ArrayList<VariantValue>(ctx)), ctx, __FILEW__, __LINE__, L""))
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~TablePartitionMaxValue() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	List<VariantValue>* values;
public:
	void addValue(VariantValue* value, ThreadContext* ctx) throw() ;
	int fileSize(ThreadContext* ctx) throw() ;
	void toFileEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx);
public:
	static TablePartitionMaxValue* loadFromFetcher(FileStorageEntryFetcher* fetcher, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_DB_TABLE_TABLEPARTITIONMAXVALUE_H_ */
