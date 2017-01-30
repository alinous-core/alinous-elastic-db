#include "includes.h"


namespace alinous {namespace remote {namespace monitor {namespace client {





bool RemoteCommitIdPublisher::__init_done = __init_static_variables();
bool RemoteCommitIdPublisher::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"RemoteCommitIdPublisher", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 RemoteCommitIdPublisher::RemoteCommitIdPublisher(MonitorRef* monitorRef, ThreadContext* ctx) throw()  : IObject(ctx), ICommidIdPublisher(ctx), url(nullptr), info(nullptr), pool(nullptr)
{
	__GC_MV(this, &(this->url), monitorRef->getUrl(ctx), String);
}
void RemoteCommitIdPublisher::__construct_impl(MonitorRef* monitorRef, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->url), monitorRef->getUrl(ctx), String);
}
 RemoteCommitIdPublisher::~RemoteCommitIdPublisher() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void RemoteCommitIdPublisher::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"RemoteCommitIdPublisher", L"~RemoteCommitIdPublisher");
	__e_obj1.add(this->url, this);
	url = nullptr;
	__e_obj1.add(this->info, this);
	info = nullptr;
	__e_obj1.add(this->pool, this);
	pool = nullptr;
	if(!prepare){
		return;
	}
}
RemoteCommitIdPublisher* RemoteCommitIdPublisher::init(ThreadContext* ctx)
{
	IArrayObject<String>* segs = this->url->split(ConstStr::getCNST_STR_381(), ctx);
	if(segs->length != 2)
	{
		throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_3560(), ctx));
	}
	String* host = segs->get(0);
	int port = 0;
	{
		try
		{
			port = Integer::parseInt(segs->get(1), ctx);
		}
		catch(NumberFormatException* e)
		{
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_3561(), e, ctx));
		}
	}
	__GC_MV(this, &(this->info), (new(ctx) MonitorConnectionInfo(host, port, ctx)), MonitorConnectionInfo);
	MonitorClientConnectionFactory* factory = (new(ctx) MonitorClientConnectionFactory(info, ctx));
	__GC_MV(this, &(this->pool), (new(ctx) SocketConnectionPool(factory, ctx)), SocketConnectionPool);
	return this;
}
void RemoteCommitIdPublisher::setMaxCommitId(long long maxCommitId, ThreadContext* ctx) throw() 
{
}
long long RemoteCommitIdPublisher::getMaxCommitId(ThreadContext* ctx)
{
	GetMaxCommitIdCommand* cmd = (new(ctx) GetMaxCommitIdCommand(ctx));
	ISocketConnection* con = nullptr;
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			this->pool->returnConnection(con, ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			con = this->pool->getConnection(ctx);
			cmd->sendCommand(con->getSocket(ctx), ctx);
			AbstractMonitorCommand* retcmd = cmd->sendCommand(con->getSocket(ctx), ctx);
			if(retcmd->getType(ctx) != AbstractMonitorCommand::TYPE_GET_MAX_COMMIT_ID)
			{
				throw (new(ctx) AlinousException(ConstStr::getCNST_STR_3562(), ctx));
			}
			cmd = static_cast<GetMaxCommitIdCommand*>(retcmd);
		}
		catch(UnknownHostException* e)
		{
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_3563(), e, ctx));
		}
		catch(IOException* e)
		{
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_3563(), e, ctx));
		}
	}
	return cmd->getCommitId(ctx);
}
long long RemoteCommitIdPublisher::newCommitId(ThreadContext* ctx)
{
	NewCommitIdCommand* cmd = (new(ctx) NewCommitIdCommand(ctx));
	ISocketConnection* con = nullptr;
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			this->pool->returnConnection(con, ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			con = this->pool->getConnection(ctx);
			AbstractMonitorCommand* retcmd = cmd->sendCommand(con->getSocket(ctx), ctx);
			if(retcmd->getType(ctx) != AbstractMonitorCommand::TYPE_NEW_MAX_COMMIT_ID)
			{
				throw (new(ctx) AlinousException(ConstStr::getCNST_STR_3562(), ctx));
			}
			cmd = static_cast<NewCommitIdCommand*>(retcmd);
		}
		catch(UnknownHostException* e)
		{
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_3563(), e, ctx));
		}
		catch(IOException* e)
		{
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_3563(), e, ctx));
		}
	}
	return cmd->getCommitId(ctx);
}
DbVersionContext* RemoteCommitIdPublisher::newTransactionContext(ThreadContext* ctx)
{
	DbVersionContext* vctx = (new(ctx) DbVersionContext(ctx));
	NewTransactionCommand* cmd = (new(ctx) NewTransactionCommand(ctx));
	ISocketConnection* con = nullptr;
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			this->pool->returnConnection(con, ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			con = this->pool->getConnection(ctx);
			AbstractMonitorCommand* retcmd = cmd->sendCommand(con->getSocket(ctx), ctx);
			if(retcmd->getType(ctx) != AbstractMonitorCommand::TYPE_NEW_TRANSACTION)
			{
				throw (new(ctx) AlinousException(ConstStr::getCNST_STR_3562(), ctx));
			}
			cmd = static_cast<NewTransactionCommand*>(retcmd);
		}
		catch(UnknownHostException* e)
		{
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_3563(), e, ctx));
		}
		catch(IOException* e)
		{
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_3563(), e, ctx));
		}
	}
	long long trxId = cmd->getTrxId(ctx);
	long long commitId = cmd->getCommitId(ctx);
	long long nodeClusterVersion = cmd->getNodeClusterVersion(ctx);
	long long schemaVersion = cmd->getSchemaVersion(ctx);
	vctx->setTrxId(trxId, ctx);
	vctx->setCommitId(commitId, ctx);
	vctx->setNodeClusterVersion(nodeClusterVersion, ctx);
	vctx->setSchemaVersion(schemaVersion, ctx);
	return vctx;
}
void RemoteCommitIdPublisher::dispose(ThreadContext* ctx) throw() 
{
	if(this->pool != nullptr)
	{
		this->pool->dispose(ctx);
	}
}
}}}}

