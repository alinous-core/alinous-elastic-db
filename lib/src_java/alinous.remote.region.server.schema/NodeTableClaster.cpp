#include "include/global.h"


#include "alinous.remote.socket/ICommandData.h"
#include "alinous.remote.db.client.command.data/StorageNodeData.h"
#include "alinous.remote.db.client.command.data/TableClusterData.h"
#include "alinous.db.table/TablePartitionRangeCollection.h"
#include "alinous.db.table/TableMetadata.h"
#include "alinous.remote.region.server.schema/NodeReference.h"
#include "alinous.remote.region.server.schema/NodeCluster.h"
#include "alinous.remote.region.server.schema/NodeTableReference.h"
#include "alinous.remote.region.server.schema/NodeTableClaster.h"

namespace alinous {namespace remote {namespace region {namespace server {namespace schema {





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
}}}}}

