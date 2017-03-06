#include "include/global.h"


#include "alinous.runtime.parallel/IThreadAction.h"
#include "alinous.lock/LockObject.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.system/ISystemLog.h"
#include "alinous.remote.socket/SocketServer.h"
#include "alinous.remote.socket/ISocketActionFactory.h"
#include "alinous.db/AlinousDbException.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.remote.monitor/NodeInfo.h"
#include "alinous.remote.monitor/RegionNodeInfo.h"
#include "alinous.remote.monitor.client.command.data/RegionInfoData.h"
#include "alinous.system.config.remote/Monitor.h"
#include "alinous.remote.monitor/RegionNodeInfoManager.h"
#include "alinous.remote.monitor/TransactionMonitorServer.h"
#include "java.io/FilterInputStream.h"
#include "java.io/BufferedInputStream.h"
#include "java.io/FilterOutputStream.h"
#include "java.io/BufferedOutputStream.h"
#include "alinous.remote.monitor.client.command/AbstractMonitorCommand.h"
#include "alinous.remote.monitor/MonitorResponceAction.h"
#include "alinous.remote.monitor/MonitorResponseActionFactory.h"

namespace alinous {namespace remote {namespace monitor {





String* TransactionMonitorServer::THREAD_NAME = ConstStr::getCNST_STR_3578();
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
 TransactionMonitorServer::TransactionMonitorServer(int port, int maxthread, ThreadContext* ctx) throw()  : IObject(ctx), port(0), trxLock(__GC_INS(this, (new(ctx) LockObject(ctx)), LockObject)), trxId(1), commitIdLock(__GC_INS(this, (new(ctx) LockObject(ctx)), LockObject)), lastCommitId(0), lastOid(0), maxthread(0), socketServer(nullptr), nodeInfo(nullptr), schemaVersionLock(__GC_INS(this, (new(ctx) LockObject(ctx)), LockObject)), schemaVersion(1)
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
long long TransactionMonitorServer::getNextOid(ThreadContext* ctx) throw() 
{
	this->lastOid ++ ;
	return lastOid;
}
RegionNodeInfoManager* TransactionMonitorServer::getNodeInfo(ThreadContext* ctx) throw() 
{
	return nodeInfo;
}
long long TransactionMonitorServer::updateNodeClusterVersion(long long nodeClusterRevision, ThreadContext* ctx) throw() 
{
	return this->nodeInfo->updateNodeClusterRevision(nodeClusterRevision, ctx);
}
void TransactionMonitorServer::__cleanUp(ThreadContext* ctx){
}
}}}

