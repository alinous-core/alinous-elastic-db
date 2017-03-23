#ifndef ALINOUS_REMOTE_DB_CLIENT_COMMAND_DML_COMMITDMLCOMMAND_H_
#define ALINOUS_REMOTE_DB_CLIENT_COMMAND_DML_COMMITDMLCOMMAND_H_
namespace alinous {namespace remote {namespace db {namespace server {
class RemoteTableStorageServer;}}}}

namespace java {namespace io {
class BufferedOutputStream;}}

namespace java {namespace io {
class OutputStream;}}

namespace java {namespace io {
class InputStream;}}

namespace alinous {namespace remote {namespace db {namespace client {namespace command {
class AbstractRemoteStorageCommand;}}}}}

namespace java {namespace io {
class IOException;}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace remote {namespace db {namespace client {namespace command {namespace dml {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::BufferedOutputStream;
using ::java::io::IOException;
using ::java::io::InputStream;
using ::java::io::OutputStream;
using ::alinous::remote::db::client::command::AbstractRemoteStorageCommand;
using ::alinous::remote::db::server::RemoteTableStorageServer;
using ::alinous::runtime::dom::VariableException;



class CommitDMLCommand final : public AbstractRemoteStorageCommand {
public:
	CommitDMLCommand(const CommitDMLCommand& base) = default;
public:
	CommitDMLCommand(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~CommitDMLCommand() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	void executeOnServer(RemoteTableStorageServer* tableStorageServer, BufferedOutputStream* outStream, ThreadContext* ctx) final;
	void readFromStream(InputStream* stream, int remain, ThreadContext* ctx) final;
	void writeByteStream(OutputStream* outStream, ThreadContext* ctx) final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}}}

#endif /* end of ALINOUS_REMOTE_DB_CLIENT_COMMAND_DML_COMMITDMLCOMMAND_H_ */