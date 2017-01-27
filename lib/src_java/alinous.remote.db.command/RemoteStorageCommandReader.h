#ifndef ALINOUS_REMOTE_DB_COMMAND_REMOTESTORAGECOMMANDREADER_H_
#define ALINOUS_REMOTE_DB_COMMAND_REMOTESTORAGECOMMANDREADER_H_
namespace alinous {namespace remote {namespace db {namespace command {
class AbstractRemoteStorageCommand;}}}}

namespace java {namespace io {
class InputStream;}}

namespace alinous {namespace remote {namespace db {namespace command {
class FinishRemoteStorageConnectionCommand;}}}}

namespace alinous {namespace remote {namespace db {namespace command {
class TerminateRemoteStorageCommand;}}}}

namespace alinous {namespace remote {namespace db {namespace command {
class VoidRemoteStorageCommand;}}}}

namespace alinous {namespace remote {namespace db {namespace command {
class RemoteStorageConnectCommand;}}}}

namespace alinous {namespace remote {namespace db {namespace command {
class GetTableSchemeCommand;}}}}

namespace alinous {namespace remote {namespace db {namespace command {namespace ddl {
class CreateSchemaCommand;}}}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace java {namespace io {
class IOException;}}

namespace alinous {namespace remote {namespace socket {
class NetworkBinalyUtils;}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace remote {namespace db {namespace command {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::IOException;
using ::java::io::InputStream;
using ::alinous::remote::db::command::ddl::CreateSchemaCommand;
using ::alinous::remote::socket::NetworkBinalyUtils;
using ::alinous::system::AlinousException;



class RemoteStorageCommandReader final : public virtual IObject {
public:
	RemoteStorageCommandReader(const RemoteStorageCommandReader& base) = default;
public:
	RemoteStorageCommandReader(ThreadContext* ctx) throw()  : IObject(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~RemoteStorageCommandReader() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	static AbstractRemoteStorageCommand* readFromStream(InputStream* stream, ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_REMOTE_DB_COMMAND_REMOTESTORAGECOMMANDREADER_H_ */
