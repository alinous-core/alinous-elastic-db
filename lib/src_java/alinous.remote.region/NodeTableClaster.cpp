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





bool NodeTableClaster::__init_done = __init_static_variables();
bool NodeTableClaster::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"NodeTableClaster", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 NodeTableClaster::NodeTableClaster(String* clusterName, ThreadContext* ctx) throw()  : IObject(ctx), nodes(GCUtils<List<NodeTableReference> >::ins(this, (new(ctx) ArrayList<NodeTableReference>(ctx)), ctx, __FILEW__, __LINE__, L"")), clusterName(nullptr), metadata(nullptr)
{
	__GC_MV(this, &(this->clusterName), clusterName, String);
}
void NodeTableClaster::__construct_impl(String* clusterName, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->clusterName), clusterName, String);
}
 NodeTableClaster::~NodeTableClaster() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void NodeTableClaster::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"NodeTableClaster", L"~NodeTableClaster");
	__e_obj1.add(this->nodes, this);
	nodes = nullptr;
	__e_obj1.add(this->clusterName, this);
	clusterName = nullptr;
	__e_obj1.add(this->metadata, this);
	metadata = nullptr;
	if(!prepare){
		return;
	}
}
void NodeTableClaster::updateClusterNodes(TableClusterData* clusterData, NodeCluster* nodeAccessRef, ThreadContext* ctx) throw() 
{
	ArrayList<StorageNodeData>* list = clusterData->getNodesList(ctx);
	int maxLoop = list->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		StorageNodeData* nodeData = list->get(i, ctx);
		NodeReference* ref = nodeAccessRef->getNode(nodeData->getHost(ctx), nodeData->getPort(ctx), nodeData->isIpv6(ctx), ctx);
		TableMetadata* metadata = nodeData->getMetadata(ctx);
		TablePartitionRangeCollection* ranges = metadata->getPartitionValueRanges(ctx);
		NodeTableReference* nodeRef = (new(ctx) NodeTableReference(nodeData->getHost(ctx), nodeData->getPort(ctx), nodeData->isIpv6(ctx), ref, ranges, ctx));
		this->nodes->add(nodeRef, ctx);
		if(this->metadata == nullptr)
		{
			__GC_MV(this, &(this->metadata), metadata, TableMetadata);
			this->metadata->setPartitionValueRanges(nullptr, ctx);
		}
	}
}
void NodeTableClaster::addNode(NodeTableReference* nodeRef, ThreadContext* ctx) throw() 
{
	this->nodes->add(nodeRef, ctx);
}
List<NodeTableReference>* NodeTableClaster::getNodes(ThreadContext* ctx) throw() 
{
	return nodes;
}
void NodeTableClaster::dispose(ThreadContext* ctx) throw() 
{
	int maxLoop = this->nodes->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		NodeTableReference* ref = this->nodes->get(i, ctx);
		ref->dispose(ctx);
	}
}
String* NodeTableClaster::getClusterName(ThreadContext* ctx) throw() 
{
	return clusterName;
}
TableMetadata* NodeTableClaster::getMetadata(ThreadContext* ctx) throw() 
{
	return metadata;
}
void NodeTableClaster::__cleanUp(ThreadContext* ctx){
}
}}}

