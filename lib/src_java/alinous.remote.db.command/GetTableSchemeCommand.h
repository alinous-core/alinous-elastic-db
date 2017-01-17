#ifndef ALINOUS_REMOTE_DB_COMMAND_GETTABLESCHEMECOMMAND_H_
#define ALINOUS_REMOTE_DB_COMMAND_GETTABLESCHEMECOMMAND_H_
namespace alinous {namespace remote {namespace db {namespace command {namespace data {
class SchemasStructureInfoData;}}}}}

namespace alinous {namespace remote {namespace db {
class RemoteTableStorageServer;}}}

namespace java {namespace io {
class BufferedOutputStream;}}

namespace java {namespace io {
class OutputStream;}}

namespace alinous {namespace remote {namespace socket {
class NetworkBinaryBuffer;}}}

namespace java {namespace io {
class InputStream;}}

namespace alinous {namespace remote {namespace db {namespace command {
class AbstractRemoteStorageCommand;}}}}

namespace java {namespace io {
class IOException;}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace remote {namespace db {namespace command {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::BufferedOutputStream;
using ::java::io::IOException;
using ::java::io::InputStream;
using ::java::io::OutputStream;
using ::alinous::remote::db::RemoteTableStorageServer;
using ::alinous::remote::db::command::data::SchemasStructureInfoData;
using ::alinous::remote::socket::NetworkBinaryBuffer;
using ::alinous::runtime::dom::VariableException;



class GetTableSchemeCommand final : public AbstractRemoteStorageCommand {
public:
	GetTableSchemeCommand(const GetTableSchemeCommand& base) = default;
public:
	GetTableSchemeCommand(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~GetTableSchemeCommand() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	SchemasStructureInfoData* data;
	String* region;
public:
	SchemasStructureInfoData* getData(ThreadContext* ctx) throw() ;
	void executeOnServer(RemoteTableStorageServer* tableStorageServer, BufferedOutputStream* outStream, ThreadContext* ctx) final;
	void readFromStream(InputStream* stream, int remain, ThreadContext* ctx) final;
	String* getRegion(ThreadContext* ctx) throw() ;
	void setRegion(String* region, ThreadContext* ctx) throw() ;
	void writeByteStream(OutputStream* out, ThreadContext* ctx) final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_REMOTE_DB_COMMAND_GETTABLESCHEMECOMMAND_H_ */
