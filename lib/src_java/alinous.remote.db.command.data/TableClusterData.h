#ifndef ALINOUS_REMOTE_DB_COMMAND_DATA_TABLECLUSTERDATA_H_
#define ALINOUS_REMOTE_DB_COMMAND_DATA_TABLECLUSTERDATA_H_
namespace alinous {namespace remote {namespace db {namespace command {namespace data {
class TableClusterData;}}}}}

namespace alinous {namespace remote {namespace db {namespace command {namespace data {
class StorageNodeData;}}}}}

namespace alinous {namespace remote {namespace socket {
class NetworkBinaryBuffer;}}}

namespace alinous {namespace remote {namespace socket {
class ICommandData;}}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace remote {namespace db {namespace command {namespace data {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::ArrayList;
using ::alinous::remote::socket::ICommandData;
using ::alinous::remote::socket::NetworkBinaryBuffer;
using ::alinous::runtime::dom::VariableException;



class TableClusterData final : public ICommandData, public virtual IObject {
public:
	TableClusterData(const TableClusterData& base) = default;
public:
	TableClusterData(String* name, String* region, ThreadContext* ctx) throw() ;
	void __construct_impl(String* name, String* region, ThreadContext* ctx) throw() ;
	TableClusterData(ThreadContext* ctx) throw()  : IObject(ctx), ICommandData(ctx), name(nullptr), region(nullptr), nodesList(GCUtils<ArrayList<StorageNodeData> >::ins(this, (new(ctx) ArrayList<StorageNodeData>(ctx)), ctx, __FILEW__, __LINE__, L""))
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~TableClusterData() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	String* name;
	String* region;
	ArrayList<StorageNodeData>* nodesList;
public:
	void join(TableClusterData* data, ThreadContext* ctx) throw() ;
	void addNode(StorageNodeData* node, ThreadContext* ctx) throw() ;
	ArrayList<StorageNodeData>* getNodesList(ThreadContext* ctx) throw() ;
	String* getName(ThreadContext* ctx) throw() ;
	void setName(String* name, ThreadContext* ctx) throw() ;
	String* getRegion(ThreadContext* ctx) throw() ;
	void setRegion(String* region, ThreadContext* ctx) throw() ;
	void readData(NetworkBinaryBuffer* buff, ThreadContext* ctx) final;
	void writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw()  final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}}

#endif /* end of ALINOUS_REMOTE_DB_COMMAND_DATA_TABLECLUSTERDATA_H_ */
