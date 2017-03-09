#include "include/global.h"


#include "alinous.remote.socket/ICommandData.h"
#include "alinous.db.table/TableMetadata.h"
#include "alinous.remote.region.server.schema/NodeTableReference.h"
#include "alinous.remote.region.server.schema/NodeTableClaster.h"
#include "alinous.remote.region.server.schema.strategy/RegionShardPartAccess.h"
#include "alinous.remote.region.server.schema.strategy/RegionPartitionTableAccess.h"

namespace alinous {namespace remote {namespace region {namespace server {namespace schema {namespace strategy {





bool RegionPartitionTableAccess::__init_done = __init_static_variables();
bool RegionPartitionTableAccess::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"RegionPartitionTableAccess", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 RegionPartitionTableAccess::RegionPartitionTableAccess(NodeTableClaster* table, ThreadContext* ctx) throw()  : IObject(ctx), metadata(nullptr), shardParts(GCUtils<List<RegionShardPartAccess> >::ins(this, (new(ctx) ArrayList<RegionShardPartAccess>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
	__GC_MV(this, &(this->metadata), table->getMetadata(ctx), TableMetadata);
	List<NodeTableReference>* list = table->getNodes(ctx);
	int maxLoop = list->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		NodeTableReference* nodeRef = list->get(i, ctx);
		RegionShardPartAccess* part = (new(ctx) RegionShardPartAccess(nodeRef, ctx));
		this->shardParts->add(part, ctx);
	}
}
void RegionPartitionTableAccess::__construct_impl(NodeTableClaster* table, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->metadata), table->getMetadata(ctx), TableMetadata);
	List<NodeTableReference>* list = table->getNodes(ctx);
	int maxLoop = list->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		NodeTableReference* nodeRef = list->get(i, ctx);
		RegionShardPartAccess* part = (new(ctx) RegionShardPartAccess(nodeRef, ctx));
		this->shardParts->add(part, ctx);
	}
}
 RegionPartitionTableAccess::~RegionPartitionTableAccess() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void RegionPartitionTableAccess::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"RegionPartitionTableAccess", L"~RegionPartitionTableAccess");
	__e_obj1.add(this->metadata, this);
	metadata = nullptr;
	__e_obj1.add(this->shardParts, this);
	shardParts = nullptr;
	if(!prepare){
		return;
	}
}
TableMetadata* RegionPartitionTableAccess::getMetadata(ThreadContext* ctx) throw() 
{
	return metadata;
}
List<RegionShardPartAccess>* RegionPartitionTableAccess::getShardParts(ThreadContext* ctx) throw() 
{
	return shardParts;
}
void RegionPartitionTableAccess::__cleanUp(ThreadContext* ctx){
}
}}}}}}

