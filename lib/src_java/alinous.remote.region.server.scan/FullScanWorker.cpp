#include "include/global.h"


#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.db/AlinousDbException.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.remote.region.client.command.dml/ClientScanCommandData.h"
#include "alinous.remote.region.server.scan/ScanWorkerResult.h"
#include "alinous.remote.region.server.schema/NodeReference.h"
#include "alinous.remote.region.server.schema.strategy/RegionShardPartAccess.h"
#include "alinous.remote.region.server.schema.strategy/RegionPartitionTableAccess.h"
#include "alinous.remote.region.server.tpc/CommitClusterNodeListner.h"
#include "alinous.remote.region.server.scan/IScanWorker.h"
#include "alinous.remote.region.server.scan/FullScanWorker.h"

namespace alinous {namespace remote {namespace region {namespace server {namespace scan {





bool FullScanWorker::__init_done = __init_static_variables();
bool FullScanWorker::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"FullScanWorker", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 FullScanWorker::FullScanWorker(ClientScanCommandData* data, RegionPartitionTableAccess* tableAccess, CommitClusterNodeListner* accessListner, ThreadContext* ctx) throw()  : IObject(ctx), IScanWorker(ctx), tableAccess(nullptr), shardParts(nullptr), index(0), data(nullptr), accessListner(nullptr)
{
	__GC_MV(this, &(this->tableAccess), tableAccess, RegionPartitionTableAccess);
	__GC_MV(this, &(this->data), data, ClientScanCommandData);
	__GC_MV(this, &(this->accessListner), accessListner, CommitClusterNodeListner);
}
void FullScanWorker::__construct_impl(ClientScanCommandData* data, RegionPartitionTableAccess* tableAccess, CommitClusterNodeListner* accessListner, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->tableAccess), tableAccess, RegionPartitionTableAccess);
	__GC_MV(this, &(this->data), data, ClientScanCommandData);
	__GC_MV(this, &(this->accessListner), accessListner, CommitClusterNodeListner);
}
 FullScanWorker::~FullScanWorker() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void FullScanWorker::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"FullScanWorker", L"~FullScanWorker");
	__e_obj1.add(this->tableAccess, this);
	tableAccess = nullptr;
	__e_obj1.add(this->shardParts, this);
	shardParts = nullptr;
	__e_obj1.add(this->data, this);
	data = nullptr;
	__e_obj1.add(this->accessListner, this);
	accessListner = nullptr;
	if(!prepare){
		return;
	}
}
void FullScanWorker::init(CommitClusterNodeListner* accessListner, ThreadContext* ctx) throw() 
{
	GCUtils<List<RegionShardPartAccess> >::mv(this, &(this->shardParts), this->tableAccess->getShardParts(ctx), ctx);
}
ScanWorkerResult* FullScanWorker::scan(ThreadContext* ctx)
{
	if(this->shardParts->size(ctx) <= index)
	{
		throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_3616(), ctx));
	}
	RegionShardPartAccess* access = this->shardParts->get(this->index, ctx);
	this->index ++ ;
	NodeReference* refAccess = access->getNodeAccessRef(ctx);
	this->accessListner->addNode(refAccess, ctx);
	ScanWorkerResult* result = refAccess->scan(this->data->getVctx(ctx), this->data, ctx);
	return result;
}
void FullScanWorker::__cleanUp(ThreadContext* ctx){
}
}}}}}

