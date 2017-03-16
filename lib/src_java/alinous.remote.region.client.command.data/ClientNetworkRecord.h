#ifndef ALINOUS_REMOTE_REGION_CLIENT_COMMAND_DATA_CLIENTNETWORKRECORD_H_
#define ALINOUS_REMOTE_REGION_CLIENT_COMMAND_DATA_CLIENTNETWORKRECORD_H_
namespace alinous {namespace runtime {namespace variant {
class VariantValue;}}}

namespace alinous {namespace db {namespace table {
class IDatabaseRecord;}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryBuilder;}}}

namespace alinous {namespace remote {namespace region {namespace client {namespace command {namespace data {
class ClientNetworkRecord;}}}}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryFetcher;}}}

namespace alinous {namespace btree {
class IValueFetcher;}}

namespace alinous {namespace remote {namespace socket {
class NetworkBinaryBuffer;}}}

namespace alinous {namespace runtime {namespace dom {
class IAlinousVariable;}}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace alinous {namespace remote {namespace socket {
class ICommandData;}}}

namespace alinous {namespace btree {
class IBTreeValue;}}

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

namespace alinous {namespace remote {namespace region {namespace client {namespace command {namespace data {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::ArrayList;
using ::alinous::btree::IBTreeValue;
using ::alinous::btree::IValueFetcher;
using ::alinous::buffer::storage::FileStorageEntryBuilder;
using ::alinous::buffer::storage::FileStorageEntryFetcher;
using ::alinous::db::table::IDatabaseRecord;
using ::alinous::remote::socket::ICommandData;
using ::alinous::remote::socket::NetworkBinaryBuffer;
using ::alinous::runtime::dom::IAlinousVariable;
using ::alinous::runtime::dom::NetworkAlinousVariableFactory;
using ::alinous::runtime::dom::VariableException;
using ::alinous::runtime::variant::VariantValue;
using ::alinous::system::AlinousException;



class ClientNetworkRecord final : public IDatabaseRecord, public ICommandData, public virtual IObject {
public:
	ClientNetworkRecord(const ClientNetworkRecord& base) = default;
public:
	ClientNetworkRecord(long long oid, int numColumn, ThreadContext* ctx) throw() ;
	void __construct_impl(long long oid, int numColumn, ThreadContext* ctx) throw() ;
	ClientNetworkRecord(IDatabaseRecord* databaseRecord, ThreadContext* ctx);
	void __construct_impl(IDatabaseRecord* databaseRecord, ThreadContext* ctx);
	ClientNetworkRecord(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~ClientNetworkRecord() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	long long oid;
	long long lastUpdateCommitId;
	long long insertedCommitId;
	ArrayList<VariantValue>* values;
public:
	void appendToEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx) final;
	int diskSize(ThreadContext* ctx) final;
	IValueFetcher* getFetcher(ThreadContext* ctx) throw()  final;
	int getKind(ThreadContext* ctx) throw()  final;
	VariantValue* getColumnValue(int index, ThreadContext* ctx) throw()  final;
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
	void readData(NetworkBinaryBuffer* buff, ThreadContext* ctx) final;
	void writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) final;
	bool equals(IObject* obj, ThreadContext* ctx) throw()  final;
public:
	static ClientNetworkRecord* valueFromFetcher(FileStorageEntryFetcher* fetcher, ThreadContext* ctx);
	static ClientNetworkRecord* fromNetwork(NetworkBinaryBuffer* buff, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}}}

#endif /* end of ALINOUS_REMOTE_REGION_CLIENT_COMMAND_DATA_CLIENTNETWORKRECORD_H_ */
