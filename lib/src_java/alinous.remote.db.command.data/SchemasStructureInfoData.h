#ifndef ALINOUS_REMOTE_DB_COMMAND_DATA_SCHEMASSTRUCTUREINFODATA_H_
#define ALINOUS_REMOTE_DB_COMMAND_DATA_SCHEMASSTRUCTUREINFODATA_H_
namespace alinous {namespace remote {namespace db {namespace command {namespace data {
class SchemaData;}}}}}

namespace java {namespace util {
template <typename  T, typename V> class Map;}}

namespace java {namespace util {
template <typename  T, typename V> class HashMap;}}

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
using ::java::util::Map;



class SchemasStructureInfoData final : public virtual IObject {
public:
	SchemasStructureInfoData(const SchemasStructureInfoData& base) = default;
public:
	SchemasStructureInfoData(ThreadContext* ctx) throw()  : IObject(ctx), schemas(GCUtils<Map<String,SchemaData> >::ins(this, (new(ctx) HashMap<String,SchemaData>(ctx)), ctx, __FILEW__, __LINE__, L""))
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~SchemasStructureInfoData() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	Map<String,SchemaData>* schemas;
public:
	void addScheme(SchemaData* value, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}}

#endif /* end of ALINOUS_REMOTE_DB_COMMAND_DATA_SCHEMASSTRUCTUREINFODATA_H_ */
