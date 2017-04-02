#ifndef ALINOUS_REMOTE_MONITOR_CLIENT_COMMAND_DATA_OIDSCHEMA_H_
#define ALINOUS_REMOTE_MONITOR_CLIENT_COMMAND_DATA_OIDSCHEMA_H_
namespace alinous {namespace remote {namespace monitor {namespace client {namespace command {namespace data {
class OidTable;}}}}}}

namespace java {namespace util {
template <typename  T, typename V> class Map;}}

namespace alinous {namespace remote {namespace monitor {namespace client {namespace command {namespace data {
class OidSchema;}}}}}}

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

namespace alinous {namespace remote {namespace monitor {namespace client {namespace command {namespace data {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::HashMap;
using ::java::util::Iterator;
using ::java::util::Map;
using ::alinous::remote::socket::ICommandData;
using ::alinous::remote::socket::NetworkBinaryBuffer;
using ::alinous::runtime::dom::VariableException;



class OidSchema final : public ICommandData, public virtual IObject {
public:
	OidSchema(const OidSchema& base) = default;
public:
	OidSchema(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~OidSchema() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	Map<String,OidTable>* tables;
public:
	void addOid(String* tableName, long long nextOid, ThreadContext* ctx) throw() ;
	Map<String,OidTable>* getTables(ThreadContext* ctx) throw() ;
	void readData(NetworkBinaryBuffer* buff, ThreadContext* ctx) final;
	void writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx) final;
public:
	static OidSchema* fromNetwork(NetworkBinaryBuffer* buff, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}}}

#endif /* end of ALINOUS_REMOTE_MONITOR_CLIENT_COMMAND_DATA_OIDSCHEMA_H_ */
