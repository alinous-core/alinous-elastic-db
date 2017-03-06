#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.db.table/TablePartitionRangeCollection.h"
#include "alinous.remote.db.client.command.data/StorageNodeData.h"
#include "alinous.remote.db.client.command.data/TableClusterData.h"
#include "alinous.db.table/TableMetadata.h"
#include "alinous.lock/LockObject.h"
#include "alinous.remote.socket/SocketConnectionPool.h"
#include "alinous.remote.region/NodeReference.h"
#include "alinous.remote.region/NodeTableReference.h"
#include "alinous.db.trx/DbVersionContext.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.remote.region.client.command.data/ClientNetworkRecord.h"
#include "alinous.remote.region.client.command.data/ClientTableData.h"
#include "alinous.remote.region.client.command.data/ClientSchemaData.h"
#include "alinous.remote.region.client.command.data/ClientStructureMetadata.h"
#include "alinous.runtime.parallel/IThreadAction.h"
#include "alinous.system/ISystemLog.h"
#include "alinous.remote.socket/ISocketActionFactory.h"
#include "alinous.remote.socket/SocketServer.h"
#include "alinous.system.config/IAlinousConfigElement.h"
#include "alinous.system.config.remote/MonitorRef.h"
#include "alinous.system.config.remote/RegionsServer.h"
#include "alinous.system/AlinousCore.h"
#include "alinous.remote.db.client.command.data/SchemaData.h"
#include "alinous.remote.region/NodeCluster.h"
#include "alinous.remote.region/NodeTableClaster.h"
#include "alinous.remote.region/NodeRegionSchema.h"
#include "alinous.remote.region/RegionShardPart.h"
#include "alinous.remote.region/RegionShardTable.h"
#include "alinous.remote.region/NodeReferenceManager.h"
#include "java.io/FilterInputStream.h"
#include "java.io/BufferedInputStream.h"
#include "java.io/FilterOutputStream.h"
#include "java.io/BufferedOutputStream.h"
#include "alinous.remote.region/NodeRegionResponceAction.h"
#include "alinous.remote.region/NodeRegionResponceActionFactory.h"
#include "java.lang/Number.h"
#include "java.lang/Comparable.h"
#include "java.lang/Long.h"
#include "alinous.remote.region/RegionInsertExecutor.h"
#include "alinous.remote.region/RegionTpcExecutorPool.h"
#include "alinous.remote.region/NodeRegionServer.h"
#include "alinous.remote.region/RegionTableLockManager.h"

namespace alinous {namespace remote {namespace region {





bool NodeRegionSchema::__init_done = __init_static_variables();
bool NodeRegionSchema::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"NodeRegionSchema", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 NodeRegionSchema::NodeRegionSchema(String* schemaName, ThreadContext* ctx) throw()  : IObject(ctx), tablesDictinary(GCUtils<Map<String,NodeTableClaster> >::ins(this, (new(ctx) HashMap<String,NodeTableClaster>(ctx)), ctx, __FILEW__, __LINE__, L"")), schemaName(nullptr)
{
	__GC_MV(this, &(this->schemaName), schemaName, String);
}
void NodeRegionSchema::__construct_impl(String* schemaName, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->schemaName), schemaName, String);
}
 NodeRegionSchema::~NodeRegionSchema() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void NodeRegionSchema::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"NodeRegionSchema", L"~NodeRegionSchema");
	__e_obj1.add(this->tablesDictinary, this);
	tablesDictinary = nullptr;
	__e_obj1.add(this->schemaName, this);
	schemaName = nullptr;
	if(!prepare){
		return;
	}
}
ClientSchemaData* NodeRegionSchema::toClientData(ThreadContext* ctx) throw() 
{
	ClientSchemaData* data = (new(ctx) ClientSchemaData(ctx));
	data->setName(this->schemaName, ctx);
	Iterator<String>* it = this->tablesDictinary->keySet(ctx)->iterator(ctx);
	while(it->hasNext(ctx))
	{
		String* tableName = it->next(ctx);
		NodeTableClaster* tableCluster = this->tablesDictinary->get(tableName, ctx);
		TableMetadata* metadata = tableCluster->getMetadata(ctx);
		ClientTableData* tableData = (new(ctx) ClientTableData(tableName, metadata, ctx));
		data->addTable(tableName, tableData, ctx);
	}
	return data;
}
void NodeRegionSchema::updateTableClusters(SchemaData* scdata, NodeCluster* nodeAccessRefs, ThreadContext* ctx) throw() 
{
	Map<String,TableClusterData>* clusterMap = scdata->getTablesMap(ctx);
	Iterator<String>* it = clusterMap->keySet(ctx)->iterator(ctx);
	while(it->hasNext(ctx))
	{
		String* clusterName = it->next(ctx);
		TableClusterData* clusterData = clusterMap->get(clusterName, ctx);
		NodeTableClaster* cluster = getNodeClusterOrInit(clusterName, ctx);
		cluster->updateClusterNodes(clusterData, nodeAccessRefs, ctx);
	}
}
void NodeRegionSchema::dispose(ThreadContext* ctx) throw() 
{
	Iterator<String>* it = this->tablesDictinary->keySet(ctx)->iterator(ctx);
	while(it->hasNext(ctx))
	{
		String* key = it->next(ctx);
		NodeTableClaster* cluster = this->tablesDictinary->get(key, ctx);
		cluster->dispose(ctx);
	}
}
NodeTableClaster* NodeRegionSchema::getNodeTableCluster(String* tableName, ThreadContext* ctx) throw() 
{
	return this->tablesDictinary->get(tableName, ctx);
}
String* NodeRegionSchema::getSchemaName(ThreadContext* ctx) throw() 
{
	return schemaName;
}
NodeTableClaster* NodeRegionSchema::getNodeClusterOrInit(String* clusterName, ThreadContext* ctx) throw() 
{
	NodeTableClaster* cluster = this->tablesDictinary->get(clusterName, ctx);
	if(cluster == nullptr)
	{
		cluster = (new(ctx) NodeTableClaster(clusterName, ctx));
		this->tablesDictinary->put(clusterName, cluster, ctx);
	}
	return cluster;
}
void NodeRegionSchema::__cleanUp(ThreadContext* ctx){
}
}}}

