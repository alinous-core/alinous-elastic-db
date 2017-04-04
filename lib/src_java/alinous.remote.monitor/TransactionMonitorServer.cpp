#include "include/global.h"


#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.db/AlinousDbException.h"
#include "alinous.lock/LockObject.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.remote.monitor.client.command.data/OidTable.h"
#include "alinous.remote.monitor.client.command.data/OidSchema.h"
#include "alinous.remote.monitor.client.command.data/OidSchemaContainer.h"
#include "alinous.remote.monitor.client.command.data/RegionInfoData.h"
#include "alinous.system/ISystemLog.h"
#include "alinous.remote.socket/ISocketActionFactory.h"
#include "alinous.remote.socket/SocketServer.h"
#include "alinous.system.config.remote/Monitor.h"
#include "alinous.remote.monitor/RegionNodeInfoManager.h"
#include "alinous.remote.monitor/MonitorResponseActionFactory.h"
#include "alinous.remote.monitor/TableOidHolder.h"
#include "alinous.remote.monitor/TransactionMonitorServer.h"

namespace alinous {namespace remote {namespace monitor {





String* TransactionMonitorServer::THREAD_NAME = ConstStr::getCNST_STR_3574();
bool TransactionMonitorServer::__init_done = __init_static_variables();
bool TransactionMonitorServer::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"TransactionMonitorServer", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 TransactionMonitorServer::TransactionMonitorServer(int port, int maxthread, ThreadContext* ctx) throw()  : IObject(ctx), port(0), trxLock(__GC_INS(this, (new(ctx) LockObject(ctx)), LockObject)), trxId(1), commitIdLock(__GC_INS(this, (new(ctx) LockObject(ctx)), LockObject)), lastCommitId(0), oidHolder(__GC_INS(this, (new(ctx) TableOidHolder(ctx)), TableOidHolder)), maxthread(0), socketServer(nullptr), nodeInfo(nullptr), schemaVersionLock(__GC_INS(this, (new(ctx) LockObject(ctx)), LockObject)), schemaVersion(1)
{
	this->port = port;
	this->maxthread = maxthread;
}
void TransactionMonitorServer::__construct_impl(int port, int maxthread, ThreadContext* ctx) throw() 
{
	this->port = port;
	this->maxthread = maxthread;
}
 TransactionMonitorServer::~TransactionMonitorServer() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void TransactionMonitorServer::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"TransactionMonitorServer", L"~TransactionMonitorServer");
	__e_obj1.add(this->trxLock, this);
	trxLock = nullptr;
	__e_obj1.add(this->commitIdLock, this);
	commitIdLock = nullptr;
	__e_obj1.add(this->oidHolder, this);
	oidHolder = nullptr;
	__e_obj1.add(this->socketServer, this);
	socketServer = nullptr;
	__e_obj1.add(this->nodeInfo, this);
	nodeInfo = nullptr;
	__e_obj1.add(this->schemaVersionLock, this);
	schemaVersionLock = nullptr;
	if(!prepare){
		return;
	}
}
void TransactionMonitorServer::getRegionInfo(RegionInfoData* data, String* region, ThreadContext* ctx) throw() 
{
	this->nodeInfo->getRegionInfoData(data, region, ctx);
}
TransactionMonitorServer* TransactionMonitorServer::init(Monitor* monitorConf, ThreadContext* ctx)
{
	__GC_MV(this, &(this->nodeInfo), (new(ctx) RegionNodeInfoManager(ctx))->init(monitorConf, ctx), RegionNodeInfoManager);
	return this;
}
void TransactionMonitorServer::start(ISystemLog* logger, ThreadContext* ctx) throw() 
{
	MonitorResponseActionFactory* factory = (new(ctx) MonitorResponseActionFactory(this, ctx));
	__GC_MV(this, &(this->socketServer), (new(ctx) SocketServer(this->port, logger, factory, ctx)), SocketServer);
	this->socketServer->start(this->maxthread, TransactionMonitorServer::THREAD_NAME, ctx);
}
void TransactionMonitorServer::dispose(ThreadContext* ctx) throw() 
{
	this->socketServer->dispose(ctx);
}
int TransactionMonitorServer::getPort(ThreadContext* ctx) throw() 
{
	return port;
}
long long TransactionMonitorServer::getNextCommitId(ThreadContext* ctx) throw() 
{
	{
		SynchronizedBlockObj __synchronized_2(this->commitIdLock, ctx);
		this->lastCommitId ++ ;
		return lastCommitId;
	}
}
long long TransactionMonitorServer::getCommitId(ThreadContext* ctx) throw() 
{
	{
		SynchronizedBlockObj __synchronized_2(this->commitIdLock, ctx);
		return lastCommitId;
	}
}
long long TransactionMonitorServer::newTransactionId(ThreadContext* ctx) throw() 
{
	{
		SynchronizedBlockObj __synchronized_2(this->trxLock, ctx);
		long long cur = this->trxId;
		this->trxId ++ ;
		return cur;
	}
}
long long TransactionMonitorServer::getNodeClusterVersion(ThreadContext* ctx) throw() 
{
	return this->nodeInfo->getNodeClusterRevision(ctx);
}
long long TransactionMonitorServer::getSchemaVersion(ThreadContext* ctx) throw() 
{
	{
		SynchronizedBlockObj __synchronized_2(this->schemaVersionLock, ctx);
		return this->schemaVersion;
	}
}
void TransactionMonitorServer::updateSchemaVersion(ThreadContext* ctx) throw() 
{
	{
		SynchronizedBlockObj __synchronized_2(this->schemaVersionLock, ctx);
		this->schemaVersion ++ ;
	}
}
long long TransactionMonitorServer::getNextOid(String* tableFullName, int length, ThreadContext* ctx) throw() 
{
	return this->oidHolder->getNextOid(tableFullName, length, ctx);
}
void TransactionMonitorServer::syncNextOids(OidSchemaContainer* container, ThreadContext* ctx) throw() 
{
	Map<String,OidSchema>* schemaMap = container->getSchemas(ctx);
	Iterator<String>* it = schemaMap->keySet(ctx)->iterator(ctx);
	while(it->hasNext(ctx))
	{
		String* schemaName = it->next(ctx);
		OidSchema* sc = schemaMap->get(schemaName, ctx);
		syncNextOidTable(sc, schemaName, ctx);
	}
}
RegionNodeInfoManager* TransactionMonitorServer::getNodeInfo(ThreadContext* ctx) throw() 
{
	return nodeInfo;
}
long long TransactionMonitorServer::updateNodeClusterVersion(long long nodeClusterRevision, ThreadContext* ctx) throw() 
{
	return this->nodeInfo->updateNodeClusterRevision(nodeClusterRevision, ctx);
}
void TransactionMonitorServer::syncNextOidTable(OidSchema* sc, String* schemaName, ThreadContext* ctx) throw() 
{
	Map<String,OidTable>* tablesMap = sc->getTables(ctx);
	Iterator<String>* it = tablesMap->keySet(ctx)->iterator(ctx);
	while(it->hasNext(ctx))
	{
		String* tableName = it->next(ctx);
		OidTable* table = tablesMap->get(tableName, ctx);
		long long nextOidTable = table->getNextOid(ctx);
		StringBuilder* buff = (new(ctx) StringBuilder(ctx));
		buff->append(schemaName, ctx)->append(ConstStr::getCNST_STR_953(), ctx)->append(tableName, ctx);
		String* tableFullName = buff->toString(ctx);
		this->oidHolder->syncNextOid(tableFullName, nextOidTable, ctx);
	}
}
void TransactionMonitorServer::__cleanUp(ThreadContext* ctx){
}
}}}

