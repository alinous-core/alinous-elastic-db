#include "include/global.h"


#include "alinous.system/AlinousException.h"
#include "alinous.remote.socket/ISocketConnection.h"
#include "alinous.remote.socket/SocketConnectionPool.h"
#include "alinous.remote.socket/ISocketConnectionFactory.h"
#include "alinous.remote.monitor.client/MonitorConnectionInfo.h"
#include "alinous.remote.monitor.client/MonitorClientConnectionFactory.h"
#include "java.io/FilterOutputStream.h"
#include "java.io/BufferedOutputStream.h"
#include "alinous.remote.monitor/TransactionMonitorServer.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.monitor.client.command/AbstractMonitorCommand.h"
#include "alinous.remote.monitor.client.command.commitId/ReportSchemaVersionCommand.h"
#include "alinous.remote.monitor.client.command/MinitorCommandReader.h"
#include "alinous.system.config/IAlinousConfigElement.h"
#include "alinous.system.config.remote/MonitorRef.h"
#include "alinous.remote.db/MonitorAccess.h"

namespace alinous {namespace remote {namespace db {





bool MonitorAccess::__init_done = __init_static_variables();
bool MonitorAccess::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"MonitorAccess", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 MonitorAccess::MonitorAccess(MonitorRef* monitorRef, ThreadContext* ctx) throw()  : IObject(ctx), monitorRef(nullptr), pool(nullptr)
{
	__GC_MV(this, &(this->monitorRef), monitorRef, MonitorRef);
}
void MonitorAccess::__construct_impl(MonitorRef* monitorRef, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->monitorRef), monitorRef, MonitorRef);
}
 MonitorAccess::~MonitorAccess() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void MonitorAccess::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"MonitorAccess", L"~MonitorAccess");
	__e_obj1.add(this->monitorRef, this);
	monitorRef = nullptr;
	__e_obj1.add(this->pool, this);
	pool = nullptr;
	if(!prepare){
		return;
	}
}
void MonitorAccess::init(ThreadContext* ctx) throw() 
{
	MonitorConnectionInfo* info = (new(ctx) MonitorConnectionInfo(this->monitorRef->getHost(ctx), this->monitorRef->getPort(ctx), ctx));
	MonitorClientConnectionFactory* factory = (new(ctx) MonitorClientConnectionFactory(info, ctx));
	__GC_MV(this, &(this->pool), (new(ctx) SocketConnectionPool(factory, ctx)), SocketConnectionPool);
}
void MonitorAccess::reportSchemaUpdated(ThreadContext* ctx)
{
	ReportSchemaVersionCommand* cmd = (new(ctx) ReportSchemaVersionCommand(ctx));
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
			AlinousSocket* socket = con->getSocket(ctx);
			AbstractMonitorCommand* retcmd = cmd->sendCommand(socket, ctx);
			if(retcmd->getType(ctx) != AbstractMonitorCommand::TYPE_REPORT_SCHEMA_UPDATED)
			{
				throw (new(ctx) AlinousException(ConstStr::getCNST_STR_3584(), ctx));
			}
		}
		catch(UnknownHostException* e)
		{
			throw (new(ctx) AlinousException(ConstStr::getCNST_STR_3584(), e, ctx));
		}
		catch(IOException* e)
		{
			throw (new(ctx) AlinousException(ConstStr::getCNST_STR_3584(), e, ctx));
		}
		catch(AlinousException* e)
		{
			throw (new(ctx) AlinousException(ConstStr::getCNST_STR_3584(), e, ctx));
		}
	}
}
void MonitorAccess::dispose(ThreadContext* ctx) throw() 
{
	if(this->pool != nullptr)
	{
		this->pool->dispose(ctx);
	}
}
void MonitorAccess::__cleanUp(ThreadContext* ctx){
}
}}}

