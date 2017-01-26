#include "includes.h"


namespace alinous {namespace remote {namespace db {namespace command {





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
	default:
		throw (new(ctx) AlinousException(ConstStr::getCNST_STR_3552(), ctx));
		break;
	}
	cmd->readFromStream(stream, size, ctx);
	return cmd;
}
}}}}

