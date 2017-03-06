#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.db.table/TablePartitionRangeCollection.h"
#include "alinous.db.table/TableMetadata.h"
#include "alinous.remote.socket/ISocketConnection.h"
#include "alinous.lock/LockObject.h"
#include "alinous.remote.socket/SocketConnectionPool.h"
#include "alinous.remote.socket/ISocketConnectionFactory.h"
#include "alinous.remote.db.client/RemoteStorageConnectionInfo.h"
#include "alinous.remote.db.client/RemoteStorageClientConnectionFactory.h"
#include "java.io/FilterOutputStream.h"
#include "java.io/BufferedOutputStream.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.remote.db.client.command.data/SchemaData.h"
#include "alinous.remote.db.client.command.data/SchemasStructureInfoData.h"
#include "alinous.runtime.parallel/IThreadAction.h"
#include "alinous.system/ISystemLog.h"
#include "alinous.remote.socket/ISocketActionFactory.h"
#include "alinous.remote.socket/SocketServer.h"
#include "alinous.db.trx/DbVersionContext.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.remote.region.client.command.data/ClientNetworkRecord.h"
#include "alinous.remote.region.client.command.data/ClientSchemaData.h"
#include "alinous.remote.region.client.command.data/ClientStructureMetadata.h"
#include "alinous.system.config/IAlinousConfigElement.h"
#include "alinous.system.config.remote/MonitorRef.h"
#include "alinous.system.config.remote/RegionsServer.h"
#include "alinous.remote.region/NodeCluster.h"
#include "alinous.remote.region/NodeTableClaster.h"
#include "alinous.remote.region/NodeRegionSchema.h"
#include "alinous.remote.region/RegionShardPart.h"
#include "alinous.remote.region/RegionShardTable.h"
#include "alinous.remote.region/NodeReferenceManager.h"
#include "java.io/FilterInputStream.h"
#include "java.io/BufferedInputStream.h"
#include "alinous.remote.region/NodeRegionResponceAction.h"
#include "alinous.remote.region/NodeRegionResponceActionFactory.h"
#include "java.lang/Number.h"
#include "java.lang/Comparable.h"
#include "java.lang/Long.h"
#include "alinous.remote.region/RegionInsertExecutor.h"
#include "alinous.remote.region/RegionTpcExecutorPool.h"
#include "alinous.remote.region/NodeRegionServer.h"
#include "alinous.system/AlinousCore.h"
#include "alinous.remote.db/RemoteTableStorageServer.h"
#include "alinous.remote.db.client.command/AbstractRemoteStorageCommand.h"
#include "alinous.remote.db.client.command/GetTableSchemeCommand.h"
#include "alinous.remote.db.client.command.ddl/CreateSchemaCommand.h"
#include "alinous.remote.db.client.command.ddl/CreateTableCommand.h"
#include "alinous.remote.region/NodeReference.h"
#include "alinous.remote.region/NodeTableReference.h"
#include "alinous.remote.region/RegionTableLockManager.h"

namespace alinous {namespace remote {namespace region {





bool NodeReference::__init_done = __init_static_variables();
bool NodeReference::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"NodeReference", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 NodeReference::NodeReference(String* host, int port, bool ipv6, ThreadContext* ctx) throw()  : IObject(ctx), host(nullptr), port(0), ipv6(0), nodeConnectionPool(nullptr)
{
	__GC_MV(this, &(this->host), host, String);
	this->port = port;
	this->ipv6 = ipv6;
}
void NodeReference::__construct_impl(String* host, int port, bool ipv6, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->host), host, String);
	this->port = port;
	this->ipv6 = ipv6;
}
 NodeReference::~NodeReference() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void NodeReference::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"NodeReference", L"~NodeReference");
	__e_obj1.add(this->host, this);
	host = nullptr;
	__e_obj1.add(this->nodeConnectionPool, this);
	nodeConnectionPool = nullptr;
	if(!prepare){
		return;
	}
}
void NodeReference::initConnectionPool(ThreadContext* ctx) throw() 
{
	RemoteStorageConnectionInfo* info = (new(ctx) RemoteStorageConnectionInfo(this->host, this->port, ctx));
	RemoteStorageClientConnectionFactory* factory = (new(ctx) RemoteStorageClientConnectionFactory(info, ctx));
	__GC_MV(this, &(this->nodeConnectionPool), (new(ctx) SocketConnectionPool(factory, ctx)), SocketConnectionPool);
}
void NodeReference::dispose(ThreadContext* ctx) throw() 
{
	if(this->nodeConnectionPool != nullptr)
	{
		this->nodeConnectionPool->dispose(ctx);
	}
}
SchemasStructureInfoData* NodeReference::getSchemeInfo(String* region, ThreadContext* ctx)
{
	GetTableSchemeCommand* cmd = (new(ctx) GetTableSchemeCommand(ctx));
	cmd->setRegion(region, ctx);
	cmd->setHost(this->host, ctx);
	cmd->setPort(this->port, ctx);
	cmd->setIpv6(this->ipv6, ctx);
	ISocketConnection* con = nullptr;
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			this->nodeConnectionPool->returnConnection(con, ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			con = this->nodeConnectionPool->getConnection(ctx);
			AlinousSocket* socket = con->getSocket(ctx);
			AbstractRemoteStorageCommand* retcmd = cmd->sendCommand(socket, ctx);
			if(retcmd->getType(ctx) != AbstractRemoteStorageCommand::TYPE_GET_TABLE_SCHEME)
			{
				throw (new(ctx) AlinousException(ConstStr::getCNST_STR_3588(), ctx));
			}
			cmd = static_cast<GetTableSchemeCommand*>(retcmd);
		}
		catch(UnknownHostException* e)
		{
			throw (new(ctx) AlinousException(ConstStr::getCNST_STR_3589(), e, ctx));
		}
		catch(IOException* e)
		{
			throw (new(ctx) AlinousException(ConstStr::getCNST_STR_3590(), e, ctx));
		}
	}
	return cmd->getData(ctx);
}
void NodeReference::createSchema(String* schemaName, ThreadContext* ctx)
{
	CreateSchemaCommand* cmd = (new(ctx) CreateSchemaCommand(ctx));
	ISocketConnection* con = nullptr;
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			this->nodeConnectionPool->returnConnection(con, ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			con = this->nodeConnectionPool->getConnection(ctx);
			AlinousSocket* socket = con->getSocket(ctx);
			AbstractRemoteStorageCommand* retcmd = cmd->sendCommand(socket, ctx);
			if(retcmd->getType(ctx) != AbstractRemoteStorageCommand::TYPE_CREATE_SCHEMA)
			{
				throw (new(ctx) AlinousException(ConstStr::getCNST_STR_3588(), ctx));
			}
			cmd = static_cast<CreateSchemaCommand*>(retcmd);
		}
		catch(UnknownHostException* e)
		{
			throw (new(ctx) AlinousException(ConstStr::getCNST_STR_3591(), e, ctx));
		}
		catch(IOException* e)
		{
			throw (new(ctx) AlinousException(ConstStr::getCNST_STR_3591(), e, ctx));
		}
		catch(AlinousException* e)
		{
			throw (new(ctx) AlinousException(ConstStr::getCNST_STR_3591(), e, ctx));
		}
	}
}
void NodeReference::createTable(TableMetadata* meta, ThreadContext* ctx)
{
	CreateTableCommand* cmd = (new(ctx) CreateTableCommand(ctx));
	cmd->setMetadaata(meta, ctx);
	ISocketConnection* con = nullptr;
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			this->nodeConnectionPool->returnConnection(con, ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			con = this->nodeConnectionPool->getConnection(ctx);
			AlinousSocket* socket = con->getSocket(ctx);
			AbstractRemoteStorageCommand* retcmd = cmd->sendCommand(socket, ctx);
			if(retcmd->getType(ctx) != AbstractRemoteStorageCommand::TYPE_CREATE_TABLE)
			{
				throw (new(ctx) AlinousException(ConstStr::getCNST_STR_3588(), ctx));
			}
		}
		catch(UnknownHostException* e)
		{
			throw (new(ctx) AlinousException(ConstStr::getCNST_STR_3592(), e, ctx));
		}
		catch(IOException* e)
		{
			throw (new(ctx) AlinousException(ConstStr::getCNST_STR_3592(), e, ctx));
		}
		catch(AlinousException* e)
		{
			throw (new(ctx) AlinousException(ConstStr::getCNST_STR_3592(), e, ctx));
		}
	}
}
String* NodeReference::getHost(ThreadContext* ctx) throw() 
{
	return host;
}
int NodeReference::getPort(ThreadContext* ctx) throw() 
{
	return port;
}
bool NodeReference::isIpv6(ThreadContext* ctx) throw() 
{
	return ipv6;
}
bool NodeReference::equals(String* host, int port, bool ipv6, ThreadContext* ctx) throw() 
{
	return this->ipv6 == ipv6 && this->port == port && this->host->equals(host, ctx);
}
bool NodeReference::equals(IObject* obj, ThreadContext* ctx) throw() 
{
	NodeReference* ref = dynamic_cast<NodeReference*>(obj);
	return this->ipv6 == ref->isIpv6(ctx) && this->port == ref->getPort(ctx) && this->host->equals(ref->getHost(ctx), ctx);
}
void NodeReference::__cleanUp(ThreadContext* ctx){
}
}}}

