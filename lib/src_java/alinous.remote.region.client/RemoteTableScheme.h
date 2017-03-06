#ifndef ALINOUS_REMOTE_REGION_CLIENT_REMOTETABLESCHEME_H_
#define ALINOUS_REMOTE_REGION_CLIENT_REMOTETABLESCHEME_H_
namespace alinous {namespace remote {namespace region {namespace client {namespace command {namespace data {
class ClientSchemaData;}}}}}}

namespace alinous {namespace remote {namespace socket {
class SocketConnectionPool;}}}

namespace java {namespace util {
template <typename  T, typename V> class Map;}}

namespace alinous {namespace remote {namespace region {namespace client {namespace command {namespace data {
class ClientTableData;}}}}}}

namespace java {namespace util {
template <typename  T> class Iterator;}}

namespace alinous {namespace remote {namespace region {namespace client {
class DatabaseTableClient;}}}}

namespace alinous {namespace db {namespace table {
class IDatabaseTable;}}}

namespace alinous {namespace lock {
class LockObject;}}

namespace java {namespace util {
template <typename  T, typename V> class HashMap;}}

namespace alinous {namespace db {
class ITableSchema;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace remote {namespace region {namespace client {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::ArrayList;
using ::java::util::HashMap;
using ::java::util::Iterator;
using ::java::util::Map;
using ::alinous::db::ITableSchema;
using ::alinous::db::table::IDatabaseTable;
using ::alinous::lock::LockObject;
using ::alinous::remote::region::client::command::data::ClientSchemaData;
using ::alinous::remote::region::client::command::data::ClientTableData;
using ::alinous::remote::socket::SocketConnectionPool;



class RemoteTableScheme final : public ITableSchema, public virtual IObject {
public:
	RemoteTableScheme(const RemoteTableScheme& base) = default;
public:
	RemoteTableScheme(String* name, ThreadContext* ctx) throw() ;
	void __construct_impl(String* name, ThreadContext* ctx) throw() ;
	virtual ~RemoteTableScheme() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	String* name;
	LockObject* lock;
	Map<String,DatabaseTableClient>* tables;
public:
	void updateInfo(ClientSchemaData* scdata, SocketConnectionPool* regionAccessPool, ThreadContext* ctx) throw() ;
	IDatabaseTable* getTableStore(String* tableName, ThreadContext* ctx) throw()  final;
	String* getName(ThreadContext* ctx) throw() ;
private:
	void doUpdateInfo(Map<String,ClientTableData>* map, SocketConnectionPool* regionAccessPool, ThreadContext* ctx) throw() ;
	DatabaseTableClient* getOrInitDatabaseTableClient(String* tableName, ClientTableData* tableData, SocketConnectionPool* regionAccessPool, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}

#endif /* end of ALINOUS_REMOTE_REGION_CLIENT_REMOTETABLESCHEME_H_ */
