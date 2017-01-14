#include "includes.h"


namespace alinous {namespace remote {namespace db {namespace command {





constexpr const int AbstractRemoteStorageCommand::TYPE_VOID;
constexpr const int AbstractRemoteStorageCommand::TYPE_FINISH;
constexpr const int AbstractRemoteStorageCommand::TYPE_CONNECT;
constexpr const int AbstractRemoteStorageCommand::TYPE_TERMINATE;
constexpr const int AbstractRemoteStorageCommand::TYPE_GET_TABLE_SCHEME;
bool AbstractRemoteStorageCommand::__init_done = __init_static_variables();
bool AbstractRemoteStorageCommand::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AbstractRemoteStorageCommand", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AbstractRemoteStorageCommand::~AbstractRemoteStorageCommand() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AbstractRemoteStorageCommand::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"AbstractRemoteStorageCommand", L"~AbstractRemoteStorageCommand");
	if(!prepare){
		return;
	}
}
int AbstractRemoteStorageCommand::getType(ThreadContext* ctx) throw() 
{
	return type;
}
AbstractRemoteStorageCommand* AbstractRemoteStorageCommand::sendCommand(AlinousSocket* socket, ThreadContext* ctx)
{
	OutputStream* out = socket->getOutputStream(ctx);
	writeByteStream(out, ctx);
	out->flush(ctx);
	InputStream* stream = socket->getInputStream(ctx);
	AbstractRemoteStorageCommand* cmd = RemoteStorageCommandReader::readFromStream(stream, ctx);
	return cmd;
}
}}}}

