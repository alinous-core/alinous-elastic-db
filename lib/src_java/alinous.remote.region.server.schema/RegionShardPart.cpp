#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.db.table/TablePartitionRangeCollection.h"
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
#include "alinous.remote.region.client.command.data/ClientSchemaData.h"
#include "alinous.remote.region.server.schema/NodeRegionSchema.h"
#include "alinous.lock/LockObject.h"
#include "alinous.remote.monitor.client.command.data/RegionInfoData.h"
#include "alinous.remote.region.client.command.data/ClientStructureMetadata.h"
#include "alinous.remote.region.server.schema/NodeReferenceManager.h"

namespace alinous {namespace remote {namespace region {namespace server {namespace schema {





bool RegionShardPart::__init_done = __init_static_variables();
bool RegionShardPart::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"RegionShardPart", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 RegionShardPart::RegionShardPart(NodeTableReference* nodeRef, ThreadContext* ctx) throw()  : IObject(ctx), partitionRange(nullptr), nodeAccessRef(nullptr)
{
	__GC_MV(this, &(this->partitionRange), nodeRef->getRange(ctx), TablePartitionRangeCollection);
	__GC_MV(this, &(this->nodeAccessRef), nodeRef->getNodeAccessRef(ctx), NodeReference);
}
void RegionShardPart::__construct_impl(NodeTableReference* nodeRef, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->partitionRange), nodeRef->getRange(ctx), TablePartitionRangeCollection);
	__GC_MV(this, &(this->nodeAccessRef), nodeRef->getNodeAccessRef(ctx), NodeReference);
}
 RegionShardPart::~RegionShardPart() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void RegionShardPart::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"RegionShardPart", L"~RegionShardPart");
	__e_obj1.add(this->partitionRange, this);
	partitionRange = nullptr;
	__e_obj1.add(this->nodeAccessRef, this);
	nodeAccessRef = nullptr;
	if(!prepare){
		return;
	}
}
TablePartitionRangeCollection* RegionShardPart::getPartitionRange(ThreadContext* ctx) throw() 
{
	return partitionRange;
}
NodeReference* RegionShardPart::getNodeAccessRef(ThreadContext* ctx) throw() 
{
	return nodeAccessRef;
}
void RegionShardPart::__cleanUp(ThreadContext* ctx){
}
}}}}}

