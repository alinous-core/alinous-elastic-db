#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.system/AlinousException.h"
#include "alinous.db.table/TableMetadata.h"
#include "alinous.db.trx/DbVersionContext.h"
#include "alinous.lock/LockObject.h"
#include "alinous.remote.socket/ISocketConnection.h"
#include "alinous.remote.socket/SocketConnectionPool.h"
#include "alinous.remote.socket/ISocketConnectionFactory.h"
#include "alinous.remote.monitor.client/MonitorConnectionInfo.h"
#include "alinous.remote.monitor.client/MonitorClientConnectionFactory.h"
#include "java.io/FilterOutputStream.h"
#include "java.io/BufferedOutputStream.h"
#include "alinous.remote.monitor.client.command.data/RegionInfoData.h"
#include "alinous.system/ISystemLog.h"
#include "alinous.remote.socket/ISocketActionFactory.h"
#include "alinous.remote.socket/SocketServer.h"
#include "alinous.remote.monitor/TransactionMonitorServer.h"
#include "alinous.remote.monitor.client.command/AbstractMonitorCommand.h"
#include "alinous.remote.monitor.client.command.commitId/ReportClusterVersionUpCommand.h"
#include "alinous.remote.monitor.client.command/GetRegionNodeInfoCommand.h"
#include "alinous.remote.monitor.client.command/MinitorCommandReader.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.remote.region.client.command.data/ClientNetworkRecord.h"
#include "alinous.remote.region.client.command.data/ClientStructureMetadata.h"
#include "alinous.remote.region.server.schema/NodeReferenceManager.h"
#include "alinous.remote.region.server.tpc/RegionInsertExecutor.h"
#include "alinous.remote.region.server.tpc/RegionTpcExecutorPool.h"
#include "alinous.system.config/IAlinousConfigElement.h"
#include "alinous.system.config.remote/MonitorRef.h"
#include "alinous.system.config.remote/RegionsServer.h"
#include "alinous.system/AlinousCore.h"
#include "alinous.remote.region.server/NodeRegionResponceActionFactory.h"
#include "alinous.remote.region.server/NodeRegionServer.h"

namespace alinous {namespace remote {namespace region {namespace server {





String* NodeRegionServer::THREAD_NAME = ConstStr::getCNST_STR_3606();
bool NodeRegionServer::__init_done = __init_static_variables();
bool NodeRegionServer::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"NodeRegionServer", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 NodeRegionServer::NodeRegionServer(int port, int maxthread, AlinousCore* core, ThreadContext* ctx) throw()  : IObject(ctx), port(0), maxthread(0), refs(nullptr), socketServer(nullptr), monitorConnectionPool(nullptr), nodeClusterRevisionLock(__GC_INS(this, (new(ctx) LockObject(ctx)), LockObject)), nodeClusterRevision(1), region(nullptr), core(nullptr), insertSessions(__GC_INS(this, (new(ctx) RegionTpcExecutorPool(ctx)), RegionTpcExecutorPool))
{
	this->port = port;
	this->maxthread = maxthread;
	__GC_MV(this, &(this->refs), (new(ctx) NodeReferenceManager(ctx)), NodeReferenceManager);
	__GC_MV(this, &(this->core), core, AlinousCore);
}
void NodeRegionServer::__construct_impl(int port, int maxthread, AlinousCore* core, ThreadContext* ctx) throw() 
{
	this->port = port;
	this->maxthread = maxthread;
	__GC_MV(this, &(this->refs), (new(ctx) NodeReferenceManager(ctx)), NodeReferenceManager);
	__GC_MV(this, &(this->core), core, AlinousCore);
}
 NodeRegionServer::~NodeRegionServer() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void NodeRegionServer::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"NodeRegionServer", L"~NodeRegionServer");
	__e_obj1.add(this->refs, this);
	refs = nullptr;
	__e_obj1.add(this->socketServer, this);
	socketServer = nullptr;
	__e_obj1.add(this->monitorConnectionPool, this);
	monitorConnectionPool = nullptr;
	__e_obj1.add(this->nodeClusterRevisionLock, this);
	nodeClusterRevisionLock = nullptr;
	__e_obj1.add(this->region, this);
	region = nullptr;
	__e_obj1.add(this->core, this);
	core = nullptr;
	__e_obj1.add(this->insertSessions, this);
	insertSessions = nullptr;
	if(!prepare){
		return;
	}
}
AlinousCore* NodeRegionServer::getCore(ThreadContext* ctx) throw() 
{
	return core;
}
void NodeRegionServer::logError(Throwable* e, ThreadContext* ctx) throw() 
{
	ISystemLog* log = this->core->getLogger(ctx);
	log->logError(e, ctx);
}
void NodeRegionServer::initNodes(RegionsServer* srvconf, ThreadContext* ctx)
{
	__GC_MV(this, &(this->region), srvconf->getRegion(ctx), String);
	MonitorRef* monRef = srvconf->getMonitorRef(ctx);
	initMonitorRef(monRef, ctx);
	syncNodes(ctx);
	syncScheme(ctx);
}
long long NodeRegionServer::getClientData(ClientStructureMetadata* data, ThreadContext* ctx)
{
	return this->refs->getClientData(data, ctx);
}
void NodeRegionServer::syncScheme(ThreadContext* ctx)
{
	this->refs->syncSchemeTables(this->region, ctx);
}
void NodeRegionServer::syncNodes(ThreadContext* ctx)
{
	GetRegionNodeInfoCommand* cmd = (new(ctx) GetRegionNodeInfoCommand(ctx));
	cmd->setRegion(this->region, ctx);
	cmd->setNodeClusterRevision(this->nodeClusterRevision, ctx);
	ISocketConnection* con = nullptr;
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			this->monitorConnectionPool->returnConnection(con, ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			con = this->monitorConnectionPool->getConnection(ctx);
			AlinousSocket* socket = con->getSocket(ctx);
			AbstractMonitorCommand* retcmd = cmd->sendCommand(socket, ctx);
			if(retcmd->getType(ctx) != AbstractMonitorCommand::TYPE_GET_REGION_INFO)
			{
				throw (new(ctx) AlinousException(ConstStr::getCNST_STR_3605(), ctx));
			}
			cmd = static_cast<GetRegionNodeInfoCommand*>(retcmd);
			RegionInfoData* data = cmd->getRegionData(ctx);
			this->refs->syncNodeReference(data, ctx);
			this->nodeClusterRevision = cmd->getNodeClusterRevision(ctx);
		}
		catch(...){throw;}
	}
}
void NodeRegionServer::start(ISystemLog* logger, ThreadContext* ctx) throw() 
{
	NodeRegionResponceActionFactory* factory = (new(ctx) NodeRegionResponceActionFactory(this, ctx));
	__GC_MV(this, &(this->socketServer), (new(ctx) SocketServer(this->port, logger, factory, ctx)), SocketServer);
	this->socketServer->start(this->maxthread, NodeRegionServer::THREAD_NAME, ctx);
}
void NodeRegionServer::dispose(ThreadContext* ctx) throw() 
{
	this->socketServer->dispose(ctx);
	if(this->monitorConnectionPool != nullptr)
	{
		this->monitorConnectionPool->dispose(ctx);
	}
	this->refs->dispose(ctx);
}
NodeReferenceManager* NodeRegionServer::getRefs(ThreadContext* ctx) throw() 
{
	return refs;
}
void NodeRegionServer::createSchema(String* schemaName, ThreadContext* ctx)
{
	this->refs->createSchema(schemaName, ctx);
}
void NodeRegionServer::createTable(TableMetadata* metadata, ThreadContext* ctx)
{
	{
		SynchronizedBlockObj __synchronized_2(this->nodeClusterRevisionLock, ctx);
		this->refs->createTable(metadata, ctx);
		this->nodeClusterRevision ++ ;
		reportClusterUpdate(ctx);
	}
	syncScheme(ctx);
}
void NodeRegionServer::insertData(ArrayList<ClientNetworkRecord>* list, long long newCommitId, String* schema, String* table, DbVersionContext* vctx, int isolationLevel, ThreadContext* ctx)
{
	checkVersion(vctx, ctx);
	RegionInsertExecutor* exec = this->insertSessions->getInsertSession(vctx->getTrxId(ctx), newCommitId, vctx, this->refs, ctx);
	exec->prepareInsert(list, schema, table, vctx, newCommitId, isolationLevel, ctx);
}
void NodeRegionServer::commitUpdateData(long long trxId, ThreadContext* ctx) throw() 
{
	this->insertSessions->removeInsertSession(trxId, ctx);
}
void NodeRegionServer::initMonitorRef(MonitorRef* monRef, ThreadContext* ctx) throw() 
{
	MonitorConnectionInfo* monInfo = (new(ctx) MonitorConnectionInfo(monRef->getHost(ctx), monRef->getPort(ctx), ctx));
	MonitorClientConnectionFactory* factory = (new(ctx) MonitorClientConnectionFactory(monInfo, ctx));
	__GC_MV(this, &(this->monitorConnectionPool), (new(ctx) SocketConnectionPool(factory, ctx)), SocketConnectionPool);
}
void NodeRegionServer::checkVersion(DbVersionContext* vctx, ThreadContext* ctx)
{
	long long clusterVer = 0;
	{
		SynchronizedBlockObj __synchronized_2(this->nodeClusterRevisionLock, ctx);
		clusterVer = this->nodeClusterRevision;
		if(clusterVer < vctx->getNodeClusterVersion(ctx))
		{
			syncNodes(ctx);
		}
		long long schemeVer = this->refs->getSchemaVersion(ctx);
		if(schemeVer < vctx->getSchemaVersion(ctx))
		{
			syncScheme(ctx);
		}
	}
}
void NodeRegionServer::reportClusterUpdate(ThreadContext* ctx)
{
	ReportClusterVersionUpCommand* cmd = (new(ctx) ReportClusterVersionUpCommand(ctx));
	cmd->setNodeClusterRevision(this->nodeClusterRevision, ctx);
	ISocketConnection* con = nullptr;
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			this->monitorConnectionPool->returnConnection(con, ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			con = this->monitorConnectionPool->getConnection(ctx);
			AlinousSocket* socket = con->getSocket(ctx);
			AbstractMonitorCommand* retcmd = cmd->sendCommand(socket, ctx);
			if(retcmd->getType(ctx) != AbstractMonitorCommand::TYPE_REPORT_CLUSTER_UPDATED)
			{
				throw (new(ctx) AlinousException(ConstStr::getCNST_STR_3605(), ctx));
			}
			cmd = static_cast<ReportClusterVersionUpCommand*>(retcmd);
		}
		catch(UnknownHostException* e)
		{
			throw (new(ctx) AlinousException(ConstStr::getCNST_STR_3605(), ctx));
		}
		catch(IOException* e)
		{
			throw (new(ctx) AlinousException(ConstStr::getCNST_STR_3605(), ctx));
		}
	}
}
void NodeRegionServer::__cleanUp(ThreadContext* ctx){
}
}}}}

