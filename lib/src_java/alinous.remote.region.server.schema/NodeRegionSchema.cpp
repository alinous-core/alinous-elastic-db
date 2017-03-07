#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.db.table/TablePartitionRangeCollection.h"
#include "alinous.remote.db.client.command.data/StorageNodeData.h"
#include "alinous.remote.db.client.command.data/TableClusterData.h"
#include "alinous.db.table/TableMetadata.h"
#include "alinous.remote.db.client.command.data/SchemaData.h"
#include "alinous.remote.db.client.command.data/SchemasStructureInfoData.h"
#include "alinous.remote.region.server.schema/NodeReference.h"
#include "alinous.remote.region.server.schema/NodeTableReference.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.remote.region.client.command.data/ClientNetworkRecord.h"
#include "alinous.remote.monitor/RegionNodeInfo.h"
#include "alinous.remote.region.server.schema/NodeCluster.h"
#include "alinous.remote.region.server.schema/NodeTableClaster.h"
#include "alinous.remote.region.server.schema/RegionShardPart.h"
#include "alinous.remote.region.server.schema/RegionShardTable.h"
#include "alinous.remote.region.client.command.data/ClientTableData.h"
#include "alinous.remote.region.client.command.data/ClientSchemaData.h"
#include "alinous.remote.region.server.schema/NodeRegionSchema.h"
#include "alinous.lock/LockObject.h"
#include "alinous.remote.monitor.client.command.data/RegionInfoData.h"
#include "alinous.remote.region.client.command.data/ClientStructureMetadata.h"
#include "alinous.remote.region.server.schema/NodeReferenceManager.h"

namespace alinous {namespace remote {namespace region {namespace server {namespace schema {





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
}}}}}

