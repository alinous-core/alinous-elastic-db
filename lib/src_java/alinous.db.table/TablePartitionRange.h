#ifndef ALINOUS_DB_TABLE_TABLEPARTITIONRANGE_H_
#define ALINOUS_DB_TABLE_TABLEPARTITIONRANGE_H_
namespace alinous {namespace db {namespace table {
class TablePartitionKey;}}}

namespace alinous {namespace runtime {namespace variant {
class VariantValue;}}}

namespace java {namespace util {
template <typename  T> class List;}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryBuilder;}}}

namespace alinous {namespace db {namespace table {
class TablePartitionRange;}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryFetcher;}}}

namespace alinous {namespace remote {namespace socket {
class NetworkBinaryBuffer;}}}

namespace alinous {namespace runtime {namespace dom {
class IAlinousVariable;}}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace alinous {namespace remote {namespace socket {
class ICommandData;}}}

namespace alinous {namespace db {
class AlinousDbException;}}

namespace alinous {namespace runtime {namespace dom {
class NetworkAlinousVariableFactory;}}}

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
using ::java::util::ArrayList;
using ::java::util::List;
using ::alinous::buffer::storage::FileStorageEntryBuilder;
using ::alinous::buffer::storage::FileStorageEntryFetcher;
using ::alinous::db::AlinousDbException;
using ::alinous::remote::socket::ICommandData;
using ::alinous::remote::socket::NetworkBinaryBuffer;
using ::alinous::runtime::dom::IAlinousVariable;
using ::alinous::runtime::dom::NetworkAlinousVariableFactory;
using ::alinous::runtime::dom::VariableException;
using ::alinous::runtime::variant::VariantValue;
using ::alinous::system::AlinousException;



class TablePartitionRange final : public ICommandData, public virtual IObject {
public:
	TablePartitionRange(const TablePartitionRange& base) = default;
public:
	TablePartitionRange(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	TablePartitionRange(TablePartitionKey* key, ThreadContext* ctx) throw() ;
	void __construct_impl(TablePartitionKey* key, ThreadContext* ctx) throw() ;
	virtual ~TablePartitionRange() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	TablePartitionKey* key;
	List<VariantValue>* max;
	List<VariantValue>* min;
public:
	void addMaxKeyValue(VariantValue* value, ThreadContext* ctx) throw() ;
	void addMinKeyValue(VariantValue* value, ThreadContext* ctx) throw() ;
	TablePartitionKey* getKey(ThreadContext* ctx) throw() ;
	List<VariantValue>* getMax(ThreadContext* ctx) throw() ;
	List<VariantValue>* getMin(ThreadContext* ctx) throw() ;
	int fileSize(ThreadContext* ctx);
	void toFileEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx);
	void readData(NetworkBinaryBuffer* buff, ThreadContext* ctx) final;
	void writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) final;
public:
	static TablePartitionRange* loadFromFetcher(FileStorageEntryFetcher* fetcher, ThreadContext* ctx);
	static TablePartitionRange* fromNetwork(NetworkBinaryBuffer* buff, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_DB_TABLE_TABLEPARTITIONRANGE_H_ */
