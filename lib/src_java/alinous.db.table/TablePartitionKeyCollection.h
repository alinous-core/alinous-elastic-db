#ifndef ALINOUS_DB_TABLE_TABLEPARTITIONKEYCOLLECTION_H_
#define ALINOUS_DB_TABLE_TABLEPARTITIONKEYCOLLECTION_H_
namespace alinous {namespace db {namespace table {
class TablePartitionKey;}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryBuilder;}}}

namespace alinous {namespace db {namespace table {
class TablePartitionKeyCollection;}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryFetcher;}}}

namespace alinous {namespace remote {namespace socket {
class NetworkBinaryBuffer;}}}

namespace java {namespace util {
template <typename  T> class List;}}

namespace alinous {namespace remote {namespace socket {
class ICommandData;}}}

namespace alinous {namespace db {
class AlinousDbException;}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

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
using ::alinous::runtime::dom::VariableException;
using ::alinous::system::AlinousException;



class TablePartitionKeyCollection final : public ICommandData, public virtual IObject {
public:
	TablePartitionKeyCollection(const TablePartitionKeyCollection& base) = default;
public:
	TablePartitionKeyCollection(ThreadContext* ctx) throw()  : IObject(ctx), ICommandData(ctx), keys(GCUtils<List<TablePartitionKey> >::ins(this, (new(ctx) ArrayList<TablePartitionKey>(ctx)), ctx, __FILEW__, __LINE__, L""))
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~TablePartitionKeyCollection() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	List<TablePartitionKey>* keys;
public:
	void addPartitionKey(TablePartitionKey* key, ThreadContext* ctx) throw() ;
	int fileSize(ThreadContext* ctx);
	void toFileEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx);
	void readData(NetworkBinaryBuffer* buff, ThreadContext* ctx) final;
	void writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) final;
public:
	static TablePartitionKeyCollection* loadFromFetcher(FileStorageEntryFetcher* fetcher, ThreadContext* ctx);
	static TablePartitionKeyCollection* fromNetwork(NetworkBinaryBuffer* buff, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_DB_TABLE_TABLEPARTITIONKEYCOLLECTION_H_ */
