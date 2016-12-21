#include "includes.h"


namespace alinous {namespace remote {namespace db {





bool RemoteStorageResponceAction::__init_done = __init_static_variables();
bool RemoteStorageResponceAction::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"RemoteStorageResponceAction", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 RemoteStorageResponceAction::RemoteStorageResponceAction(RemoteTableStorageServer* tableStorageServer, Socket* socket, SocketServer* server, ThreadContext* ctx) throw()  : IObject(ctx), IThreadAction(ctx), socket(nullptr), server(nullptr), tableStorageServer(nullptr)
{
	__GC_MV(this, &(this->socket), socket, Socket);
	__GC_MV(this, &(this->server), server, SocketServer);
}
void RemoteStorageResponceAction::__construct_impl(RemoteTableStorageServer* tableStorageServer, Socket* socket, SocketServer* server, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->socket), socket, Socket);
	__GC_MV(this, &(this->server), server, SocketServer);
}
 RemoteStorageResponceAction::~RemoteStorageResponceAction() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void RemoteStorageResponceAction::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"RemoteStorageResponceAction", L"~RemoteStorageResponceAction");
	__e_obj1.add(this->socket, this);
	socket = nullptr;
	__e_obj1.add(this->server, this);
	server = nullptr;
	__e_obj1.add(this->tableStorageServer, this);
	tableStorageServer = nullptr;
	if(!prepare){
		return;
	}
}
void RemoteStorageResponceAction::execute(ThreadContext* ctx)
{
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			this->server->dec(ctx);
			this->socket->close(ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			InputStream* sockstream = this->socket->getInputStream(ctx);
			BufferedInputStream* stream = (new(ctx) BufferedInputStream(sockstream, ctx));
			OutputStream* sockStream = socket->getOutputStream(ctx);
			BufferedOutputStream* outStream = (new(ctx) BufferedOutputStream(sockStream, ctx));
			handleCommand(stream, outStream, ctx);
		}
		catch(Throwable* e)
		{
			this->socket->close(ctx);
			e->printStackTrace(ctx);
			return;
		}
	}
}
void RemoteStorageResponceAction::handleCommand(BufferedInputStream* stream, BufferedOutputStream* outStream, ThreadContext* ctx)
{
	bool loop = true;
	AbstractRemoteStorageCommand* cmd = nullptr;
	while(loop)
	{
		cmd = RemoteStorageCommandReader::readFromStream(stream, ctx);
		if(cmd == nullptr)
		{
			throw (new(ctx) AlinousException(ConstStr::getCNST_STR_3474(), ctx));
		}
		int type = cmd->getType(ctx);
		switch(type) {
		case AbstractRemoteStorageCommand::TYPE_FINISH:
			loop = false;
			break ;
		case AbstractRemoteStorageCommand::TYPE_TERMINATE:
			loop = false;
			break ;
		case AbstractRemoteStorageCommand::TYPE_CONNECT:
			cmd->executeOnServer(this->tableStorageServer, outStream, ctx);
			break ;
		case AbstractRemoteStorageCommand::TYPE_VOID:
		default:
			break ;
		}
	}
}
}}}

