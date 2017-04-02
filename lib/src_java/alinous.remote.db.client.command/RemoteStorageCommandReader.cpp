#include "include/global.h"


#include "java.io/FilterOutputStream.h"
#include "java.io/BufferedOutputStream.h"
#include "alinous.system/AlinousException.h"
#include "alinous.remote.db.server/RemoteTableStorageServer.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.db.client.command/AbstractRemoteStorageCommand.h"
#include "alinous.remote.db.client.command/RemoteStorageConnectCommand.h"
#include "alinous.remote.db.client.command.ddl/CreateSchemaCommand.h"
#include "alinous.remote.db.client.command.ddl/CreateTableCommand.h"
#include "alinous.remote.db.client.command.dml/CommitDMLCommand.h"
#include "alinous.remote.db.client.command.dml/InsertPrepareCommand.h"
#include "alinous.remote.socket/NetworkBinalyUtils.h"
#include "alinous.remote.db.client.command/FinishRemoteStorageConnectionCommand.h"
#include "alinous.remote.db.client.command/TerminateRemoteStorageCommand.h"
#include "alinous.remote.db.client.command/VoidRemoteStorageCommand.h"
#include "alinous.remote.db.client.command/GetTableSchemeCommand.h"
#include "alinous.remote.db.client.command/RequestSyncOidCommand.h"
#include "alinous.remote.db.client.command/RemoteStorageCommandReader.h"

namespace alinous {namespace remote {namespace db {namespace client {namespace command {





bool RemoteStorageCommandReader::__init_done = __init_static_variables();
bool RemoteStorageCommandReader::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"RemoteStorageCommandReader", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 RemoteStorageCommandReader::RemoteStorageCommandReader(ThreadContext* ctx) throw()  : IObject(ctx)
{
}
void RemoteStorageCommandReader::__construct_impl(ThreadContext* ctx) throw() 
{
}
 RemoteStorageCommandReader::~RemoteStorageCommandReader() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void RemoteStorageCommandReader::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
AbstractRemoteStorageCommand* RemoteStorageCommandReader::readFromStream(InputStream* stream, ThreadContext* ctx)
{
	int size = NetworkBinalyUtils::readInt(stream, ctx) - 4 * 2;
	int type = NetworkBinalyUtils::readInt(stream, ctx);
	AbstractRemoteStorageCommand* cmd = nullptr;
	switch(type) {
	case AbstractRemoteStorageCommand::TYPE_FINISH:
		cmd = (new(ctx) FinishRemoteStorageConnectionCommand(ctx));
		break ;
	case AbstractRemoteStorageCommand::TYPE_TERMINATE:
		cmd = (new(ctx) TerminateRemoteStorageCommand(ctx));
		break ;
	case AbstractRemoteStorageCommand::TYPE_VOID:
		cmd = (new(ctx) VoidRemoteStorageCommand(ctx));
		break ;
	case AbstractRemoteStorageCommand::TYPE_CONNECT:
		cmd = (new(ctx) RemoteStorageConnectCommand(ctx));
		break ;
	case AbstractRemoteStorageCommand::TYPE_GET_TABLE_SCHEME:
		cmd = (new(ctx) GetTableSchemeCommand(ctx));
		break ;
	case AbstractRemoteStorageCommand::TYPE_CREATE_SCHEMA:
		cmd = (new(ctx) CreateSchemaCommand(ctx));
		break ;
	case AbstractRemoteStorageCommand::TYPE_CREATE_TABLE:
		cmd = (new(ctx) CreateTableCommand(ctx));
		break ;
	case AbstractRemoteStorageCommand::TYPE_INSERT_PREPARE:
		cmd = (new(ctx) InsertPrepareCommand(ctx));
		break ;
	case AbstractRemoteStorageCommand::TYPE_COMMIT_DML:
		cmd = (new(ctx) CommitDMLCommand(ctx));
		break ;
	case AbstractRemoteStorageCommand::TYPE_REQUEST_SYNC_OID:
		cmd = (new(ctx) RequestSyncOidCommand(ctx));
		break ;
	default:
		throw (new(ctx) AlinousException(ConstStr::getCNST_STR_3585(), ctx));
		break;
	}
	cmd->readFromStream(stream, size, ctx);
	return cmd;
}
void RemoteStorageCommandReader::__cleanUp(ThreadContext* ctx){
}
}}}}}

