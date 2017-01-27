#include "includes.h"


namespace alinous {namespace remote {namespace db {namespace command {





constexpr const int AbstractRemoteStorageCommand::TYPE_VOID;
constexpr const int AbstractRemoteStorageCommand::TYPE_FINISH;
constexpr const int AbstractRemoteStorageCommand::TYPE_CONNECT;
constexpr const int AbstractRemoteStorageCommand::TYPE_TERMINATE;
constexpr const int AbstractRemoteStorageCommand::TYPE_GET_TABLE_SCHEME;
constexpr const int AbstractRemoteStorageCommand::TYPE_CREATE_SCHEMA;
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
	__e_obj1.add(this->errorMessage, this);
	errorMessage = nullptr;
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
bool AbstractRemoteStorageCommand::hasError(ThreadContext* ctx) throw() 
{
	return this->errorMessage != nullptr;
}
List<String>* AbstractRemoteStorageCommand::getErrorMessage(ThreadContext* ctx) throw() 
{
	return errorMessage;
}
void AbstractRemoteStorageCommand::handleError(Throwable* e, ThreadContext* ctx) throw() 
{
	GCUtils<List<String> >::mv(this, &(this->errorMessage), (new(ctx) ArrayList<String>(ctx)), ctx);
	Throwable* cur = e;
	while(cur != nullptr)
	{
		String* msg = e->getMessage(ctx);
		this->errorMessage->add(msg, ctx);
		cur = cur->getCause(ctx);
	}
}
void AbstractRemoteStorageCommand::writeErrorByteStream(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	bool er = hasError(ctx);
	buff->putBoolean(er, ctx);
	if(er)
	{
		int maxLoop = this->errorMessage->size(ctx);
		buff->putInt(maxLoop, ctx);
		for(int i = 0; i != maxLoop; ++i)
		{
			String* msg = this->errorMessage->get(i, ctx);
			buff->putString(msg, ctx);
		}
	}
}
void AbstractRemoteStorageCommand::readErrorFromStream(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() 
{
	GCUtils<List<String> >::mv(this, &(this->errorMessage), (new(ctx) ArrayList<String>(ctx)), ctx);
	bool er = buff->getBoolean(ctx);
	if(er)
	{
		int maxLoop = buff->getInt(ctx);
		for(int i = 0; i != maxLoop; ++i)
		{
			String* msg = buff->getString(ctx);
			this->errorMessage->add(msg, ctx);
		}
	}
}
}}}}

