#include "includes.h"


namespace alinous {namespace remote {namespace monitor {





bool MonitorResponceAction::__init_done = __init_static_variables();
bool MonitorResponceAction::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"MonitorResponceAction", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 MonitorResponceAction::MonitorResponceAction(TransactionMonitorServer* monitorServer, Socket* socket, SocketServer* server, ThreadContext* ctx) throw()  : IObject(ctx), IThreadAction(ctx), socket(nullptr), server(nullptr), monitorServer(nullptr)
{
	__GC_MV(this, &(this->monitorServer), monitorServer, TransactionMonitorServer);
	__GC_MV(this, &(this->socket), socket, Socket);
	__GC_MV(this, &(this->server), server, SocketServer);
}
void MonitorResponceAction::__construct_impl(TransactionMonitorServer* monitorServer, Socket* socket, SocketServer* server, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->monitorServer), monitorServer, TransactionMonitorServer);
	__GC_MV(this, &(this->socket), socket, Socket);
	__GC_MV(this, &(this->server), server, SocketServer);
}
 MonitorResponceAction::~MonitorResponceAction() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void MonitorResponceAction::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"MonitorResponceAction", L"~MonitorResponceAction");
	__e_obj1.add(this->socket, this);
	socket = nullptr;
	__e_obj1.add(this->server, this);
	server = nullptr;
	__e_obj1.add(this->monitorServer, this);
	monitorServer = nullptr;
	if(!prepare){
		return;
	}
}
void MonitorResponceAction::execute(ThreadContext* ctx)
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
void MonitorResponceAction::handleCommand(BufferedInputStream* stream, BufferedOutputStream* outStream, ThreadContext* ctx)
{
	bool loop = true;
	AbstractMonitorCommand* cmd = nullptr;
	while(loop)
	{
		cmd = parseCommand(stream, ctx);
		if(cmd == nullptr)
		{
			throw (new(ctx) AlinousException(ConstStr::getCNST_STR_3544(), ctx));
		}
		int type = cmd->getType(ctx);
		switch(type) {
		case AbstractMonitorCommand::TYPE_FINISH:
			loop = false;
			handleCommand(cmd, outStream, ctx);
			break ;
		case AbstractMonitorCommand::TYPE_TERMINATE:
			loop = false;
			handleCommand(cmd, outStream, ctx);
			break ;
		case AbstractMonitorCommand::TYPE_CONNECT:
		case AbstractMonitorCommand::TYPE_GET_MAX_COMMIT_ID:
		case AbstractMonitorCommand::TYPE_NEW_MAX_COMMIT_ID:
		case AbstractMonitorCommand::TYPE_GET_REGION_INFO:
		case AbstractMonitorCommand::TYPE_NEW_TRANSACTION:
		case AbstractMonitorCommand::TYPE_VOID:
			handleCommand(cmd, outStream, ctx);
			break ;
		default:
			loop = false;
			break ;
		}
	}
}
void MonitorResponceAction::handleCommand(AbstractMonitorCommand* cmd, BufferedOutputStream* outStream, ThreadContext* ctx)
{
	cmd->executeOnServer(this->monitorServer, outStream, ctx);
}
AbstractMonitorCommand* MonitorResponceAction::parseCommand(BufferedInputStream* stream, ThreadContext* ctx)
{
	AbstractMonitorCommand* cmd = MinitorCommandReader::readFromStream(stream, ctx);
	return cmd;
}
}}}

