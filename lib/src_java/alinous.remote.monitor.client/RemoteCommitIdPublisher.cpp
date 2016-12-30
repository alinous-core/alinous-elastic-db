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
		throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_3488(), ctx));
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
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_3489(), e, ctx));
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
	{
		try
		{
			ISocketConnection* con = this->pool->getConnection(ctx);
			cmd->sendCommand(con->getSocket(ctx), ctx);
		}
		catch(UnknownHostException* e)
		{
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_3490(), e, ctx));
		}
		catch(IOException* e)
		{
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_3490(), e, ctx));
		}
	}
	return cmd->getCommitId(ctx);
}
long long RemoteCommitIdPublisher::newCommitId(ThreadContext* ctx)
{
	NewCommitIdCommand* cmd = (new(ctx) NewCommitIdCommand(ctx));
	{
		try
		{
			ISocketConnection* con = this->pool->getConnection(ctx);
			cmd->sendCommand(con->getSocket(ctx), ctx);
		}
		catch(UnknownHostException* e)
		{
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_3490(), e, ctx));
		}
		catch(IOException* e)
		{
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_3490(), e, ctx));
		}
	}
	return cmd->getCommitId(ctx);
}
}}}}

