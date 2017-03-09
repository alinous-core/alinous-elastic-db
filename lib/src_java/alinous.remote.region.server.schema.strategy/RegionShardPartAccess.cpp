#include "include/global.h"


#include "alinous.remote.socket/ICommandData.h"
#include "alinous.db.table/TablePartitionRangeCollection.h"
#include "alinous.remote.region.server.schema/NodeReference.h"
#include "alinous.remote.region.server.schema/NodeTableReference.h"
#include "alinous.remote.region.server.schema.strategy/RegionShardPartAccess.h"

namespace alinous {namespace remote {namespace region {namespace server {namespace schema {namespace strategy {





bool RegionShardPartAccess::__init_done = __init_static_variables();
bool RegionShardPartAccess::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"RegionShardPartAccess", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 RegionShardPartAccess::RegionShardPartAccess(NodeTableReference* nodeRef, ThreadContext* ctx) throw()  : IObject(ctx), partitionRange(nullptr), nodeAccessRef(nullptr)
{
	__GC_MV(this, &(this->partitionRange), nodeRef->getRange(ctx), TablePartitionRangeCollection);
	__GC_MV(this, &(this->nodeAccessRef), nodeRef->getNodeAccessRef(ctx), NodeReference);
}
void RegionShardPartAccess::__construct_impl(NodeTableReference* nodeRef, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->partitionRange), nodeRef->getRange(ctx), TablePartitionRangeCollection);
	__GC_MV(this, &(this->nodeAccessRef), nodeRef->getNodeAccessRef(ctx), NodeReference);
}
 RegionShardPartAccess::~RegionShardPartAccess() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void RegionShardPartAccess::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"RegionShardPartAccess", L"~RegionShardPartAccess");
	__e_obj1.add(this->partitionRange, this);
	partitionRange = nullptr;
	__e_obj1.add(this->nodeAccessRef, this);
	nodeAccessRef = nullptr;
	if(!prepare){
		return;
	}
}
TablePartitionRangeCollection* RegionShardPartAccess::getPartitionRange(ThreadContext* ctx) throw() 
{
	return partitionRange;
}
NodeReference* RegionShardPartAccess::getNodeAccessRef(ThreadContext* ctx) throw() 
{
	return nodeAccessRef;
}
void RegionShardPartAccess::__cleanUp(ThreadContext* ctx){
}
}}}}}}

