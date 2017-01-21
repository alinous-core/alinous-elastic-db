#ifndef ALINOUS_REMOTE_REGION_COMMAND_DATA_CLIENTSCHEMADATA_H_
#define ALINOUS_REMOTE_REGION_COMMAND_DATA_CLIENTSCHEMADATA_H_
namespace alinous {namespace remote {namespace region {namespace command {namespace data {
class ClientTableData;}}}}}

namespace java {namespace util {
template <typename  T, typename V> class Map;}}

namespace alinous {namespace remote {namespace socket {
class NetworkBinaryBuffer;}}}

namespace java {namespace util {
template <typename  T> class Iterator;}}

namespace java {namespace util {
template <typename  T, typename V> class HashMap;}}

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

namespace alinous {namespace remote {namespace region {namespace command {namespace data {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::HashMap;
using ::java::util::Iterator;
using ::java::util::Map;
using ::alinous::remote::socket::ICommandData;
using ::alinous::remote::socket::NetworkBinaryBuffer;
using ::alinous::runtime::dom::VariableException;



class ClientSchemaData final : public ICommandData, public virtual IObject {
public:
	ClientSchemaData(const ClientSchemaData& base) = default;
public:
	ClientSchemaData(ThreadContext* ctx) throw()  : IObject(ctx), ICommandData(ctx), map(GCUtils<Map<String,ClientTableData> >::ins(this, (new(ctx) HashMap<String,ClientTableData>(ctx)), ctx, __FILEW__, __LINE__, L"")), name(nullptr)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~ClientSchemaData() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	Map<String,ClientTableData>* map;
	String* name;
public:
	void addTable(String* tableName, ClientTableData* tableData, ThreadContext* ctx) throw() ;
	Map<String,ClientTableData>* getMap(ThreadContext* ctx) throw() ;
	void readData(NetworkBinaryBuffer* buff, ThreadContext* ctx) final;
	void writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw()  final;
	String* getName(ThreadContext* ctx) throw() ;
	void setName(String* name, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}}

#endif /* end of ALINOUS_REMOTE_REGION_COMMAND_DATA_CLIENTSCHEMADATA_H_ */
