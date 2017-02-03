#include "includes.h"


namespace alinous {namespace remote {namespace region {





bool NodeRegionResponceAction::__init_done = __init_static_variables();
bool NodeRegionResponceAction::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"NodeRegionResponceAction", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 NodeRegionResponceAction::NodeRegionResponceAction(NodeRegionServer* nodeRegionServer, Socket* socket, SocketServer* server, ThreadContext* ctx) throw()  : IObject(ctx), IThreadAction(ctx), socket(nullptr), server(nullptr), nodeRegionServer(nullptr)
{
	__GC_MV(this, &(this->socket), socket, Socket);
	__GC_MV(this, &(this->server), server, SocketServer);
	__GC_MV(this, &(this->nodeRegionServer), nodeRegionServer, NodeRegionServer);
}
void NodeRegionResponceAction::__construct_impl(NodeRegionServer* nodeRegionServer, Socket* socket, SocketServer* server, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->socket), socket, Socket);
	__GC_MV(this, &(this->server), server, SocketServer);
	__GC_MV(this, &(this->nodeRegionServer), nodeRegionServer, NodeRegionServer);
}
 NodeRegionResponceAction::~NodeRegionResponceAction() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void NodeRegionResponceAction::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"NodeRegionResponceAction", L"~NodeRegionResponceAction");
	__e_obj1.add(this->socket, this);
	socket = nullptr;
	__e_obj1.add(this->server, this);
	server = nullptr;
	__e_obj1.add(this->nodeRegionServer, this);
	nodeRegionServer = nullptr;
	if(!prepare){
		return;
	}
}
void NodeRegionResponceAction::execute(ThreadContext* ctx)
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
void NodeRegionResponceAction::handleCommand(BufferedInputStream* stream, BufferedOutputStream* outStream, ThreadContext* ctx)
{
	bool loop = true;
	AbstractNodeRegionCommand* cmd = nullptr;
	while(loop)
	{
		cmd = NodeRegionCommandReader::readFromStream(stream, ctx);
		if(cmd == nullptr)
		{
			throw (new(ctx) AlinousException(ConstStr::getCNST_STR_3549(), ctx));
		}
		int type = cmd->getType(ctx);
		switch(type) {
		case AbstractNodeRegionCommand::TYPE_FINISH:
			loop = false;
			break ;
		case AbstractNodeRegionCommand::TYPE_TERMINATE:
			loop = false;
			break ;
		case AbstractNodeRegionCommand::TYPE_CONNECT:
			cmd->executeOnServer(this->nodeRegionServer, outStream, ctx);
			break ;
		case AbstractNodeRegionCommand::TYPE_VOID:
		case AbstractNodeRegionCommand::TYPE_GET_SCHEMA_FROM_REGION:
		case AbstractNodeRegionCommand::TYPE_CREATE_SCHEMA:
		case AbstractNodeRegionCommand::TYPE_CREATE_TABLE:
		case AbstractNodeRegionCommand::TYPE_INSERT_DATA:
		case AbstractNodeRegionCommand::TYPE_FINISH_COMMIT_SESSION:
		default:
			cmd->executeOnServer(this->nodeRegionServer, outStream, ctx);
			break ;
		}
	}
}
}}}

