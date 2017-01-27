#ifndef ALINOUS_REMOTE_DB_COMMAND_DATA_SCHEMASSTRUCTUREINFODATA_H_
#define ALINOUS_REMOTE_DB_COMMAND_DATA_SCHEMASSTRUCTUREINFODATA_H_
namespace alinous {namespace remote {namespace db {namespace command {namespace data {
class SchemasStructureInfoData;}}}}}

namespace java {namespace util {
template <typename  T, typename V> class Map;}}

namespace alinous {namespace remote {namespace db {namespace command {namespace data {
class SchemaData;}}}}}

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



class SchemasStructureInfoData final : public ICommandData, public virtual IObject {
public:
	SchemasStructureInfoData(const SchemasStructureInfoData& base) = default;
public:
	SchemasStructureInfoData(ThreadContext* ctx) throw()  : IObject(ctx), ICommandData(ctx), schemas(GCUtils<Map<String,SchemaData> >::ins(this, (new(ctx) HashMap<String,SchemaData>(ctx)), ctx, __FILEW__, __LINE__, L"")), schemaVersion(0)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~SchemasStructureInfoData() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	Map<String,SchemaData>* schemas;
	long long schemaVersion;
public:
	void join(SchemasStructureInfoData* data, ThreadContext* ctx) throw() ;
	bool hasSchema(String* name, ThreadContext* ctx) throw() ;
	void addScheme(SchemaData* value, ThreadContext* ctx) throw() ;
	Map<String,SchemaData>* getSchemas(ThreadContext* ctx) throw() ;
	void readData(NetworkBinaryBuffer* buff, ThreadContext* ctx) final;
	void writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw()  final;
	long long getSchemaVersion(ThreadContext* ctx) throw() ;
	void setSchemaVersion(long long schemaVersion, ThreadContext* ctx) throw() ;
private:
	SchemaData* findLocalSchema(String* name, SchemaData* schemaData, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}}

#endif /* end of ALINOUS_REMOTE_DB_COMMAND_DATA_SCHEMASSTRUCTUREINFODATA_H_ */
