#ifndef ALINOUS_DB_TABLE_TABLEPARTITIONRANGECOLLECTION_H_
#define ALINOUS_DB_TABLE_TABLEPARTITIONRANGECOLLECTION_H_
namespace alinous {namespace db {namespace table {
class TablePartitionRange;}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryBuilder;}}}

namespace alinous {namespace db {namespace table {
class TablePartitionRangeCollection;}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryFetcher;}}}

namespace alinous {namespace remote {namespace socket {
class NetworkBinaryBuffer;}}}

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
using ::alinous::buffer::storage::FileStorageEntryBuilder;
using ::alinous::buffer::storage::FileStorageEntryFetcher;
using ::alinous::db::AlinousDbException;
using ::alinous::remote::socket::ICommandData;
using ::alinous::remote::socket::NetworkBinaryBuffer;
using ::alinous::runtime::dom::VariableException;
using ::alinous::system::AlinousException;



class TablePartitionRangeCollection final : public ICommandData, public virtual IObject {
public:
	TablePartitionRangeCollection(const TablePartitionRangeCollection& base) = default;
public:
	TablePartitionRangeCollection(ThreadContext* ctx) throw()  : IObject(ctx), ICommandData(ctx), ranges(GCUtils<ArrayList<TablePartitionRange> >::ins(this, (new(ctx) ArrayList<TablePartitionRange>(ctx)), ctx, __FILEW__, __LINE__, L""))
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~TablePartitionRangeCollection() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	ArrayList<TablePartitionRange>* ranges;
public:
	void addRange(TablePartitionRange* value, ThreadContext* ctx) throw() ;
	ArrayList<TablePartitionRange>* getRanges(ThreadContext* ctx) throw() ;
	int fileSize(ThreadContext* ctx);
	void toFileEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx);
	void readData(NetworkBinaryBuffer* buff, ThreadContext* ctx) final;
	void writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) final;
public:
	static TablePartitionRangeCollection* loadFromFetcher(FileStorageEntryFetcher* fetcher, ThreadContext* ctx);
	static TablePartitionRangeCollection* fromNetwork(NetworkBinaryBuffer* buff, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_DB_TABLE_TABLEPARTITIONRANGECOLLECTION_H_ */
