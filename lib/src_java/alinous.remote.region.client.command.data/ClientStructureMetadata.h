#ifndef ALINOUS_REMOTE_REGION_CLIENT_COMMAND_DATA_CLIENTSTRUCTUREMETADATA_H_
#define ALINOUS_REMOTE_REGION_CLIENT_COMMAND_DATA_CLIENTSTRUCTUREMETADATA_H_
namespace alinous {namespace remote {namespace region {namespace client {namespace command {namespace data {
class ClientSchemaData;}}}}}}

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

namespace alinous {namespace remote {namespace region {namespace client {namespace command {namespace data {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::HashMap;
using ::java::util::Iterator;
using ::java::util::Map;
using ::alinous::remote::socket::ICommandData;
using ::alinous::remote::socket::NetworkBinaryBuffer;
using ::alinous::runtime::dom::VariableException;



class ClientStructureMetadata final : public ICommandData, public virtual IObject {
public:
	ClientStructureMetadata(const ClientStructureMetadata& base) = default;
public:
	ClientStructureMetadata(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~ClientStructureMetadata() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	Map<String,ClientSchemaData>* map;
public:
	void addSchema(String* name, ClientSchemaData* data, ThreadContext* ctx) throw() ;
	Map<String,ClientSchemaData>* getMap(ThreadContext* ctx) throw() ;
	void readData(NetworkBinaryBuffer* buff, ThreadContext* ctx) final;
	void writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}}}

#endif /* end of ALINOUS_REMOTE_REGION_CLIENT_COMMAND_DATA_CLIENTSTRUCTUREMETADATA_H_ */
