#ifndef ALINOUS_REMOTE_DB_COMMAND_DATA_SCHEMADATA_H_
#define ALINOUS_REMOTE_DB_COMMAND_DATA_SCHEMADATA_H_
namespace alinous {namespace remote {namespace db {namespace command {namespace data {
class TableClusterData;}}}}}

namespace alinous {namespace remote {namespace db {namespace command {namespace data {
class SchemaData;}}}}}

namespace java {namespace util {
template <typename  T, typename V> class Map;}}

namespace java {namespace util {
template <typename  T> class Iterator;}}

namespace alinous {namespace remote {namespace socket {
class NetworkBinaryBuffer;}}}

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

namespace alinous {namespace remote {namespace db {namespace command {namespace data {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::HashMap;
using ::java::util::Iterator;
using ::java::util::Map;
using ::alinous::remote::socket::ICommandData;
using ::alinous::remote::socket::NetworkBinaryBuffer;
using ::alinous::runtime::dom::VariableException;



class SchemaData final : public ICommandData, public virtual IObject {
public:
	SchemaData(const SchemaData& base) = default;
public:
	SchemaData(ThreadContext* ctx) throw()  : IObject(ctx), ICommandData(ctx), name(nullptr), tablesMap(GCUtils<Map<String,TableClusterData> >::ins(this, (new(ctx) HashMap<String,TableClusterData>(ctx)), ctx, __FILEW__, __LINE__, L""))
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~SchemaData() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	String* name;
	Map<String,TableClusterData>* tablesMap;
public:
	void addTable(TableClusterData* value, ThreadContext* ctx) throw() ;
	void join(SchemaData* schemaData, ThreadContext* ctx) throw() ;
	String* getName(ThreadContext* ctx) throw() ;
	void setName(String* name, ThreadContext* ctx) throw() ;
	Map<String,TableClusterData>* getTablesMap(ThreadContext* ctx) throw() ;
	void readData(NetworkBinaryBuffer* buff, ThreadContext* ctx) final;
	void writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw()  final;
private:
	TableClusterData* findTableCluster(String* tableName, TableClusterData* cluster, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}}

#endif /* end of ALINOUS_REMOTE_DB_COMMAND_DATA_SCHEMADATA_H_ */
