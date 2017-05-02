#include "include/global.h"


#include "alinous.remote.socket/ICommandData.h"
#include "alinous.remote.region.client.command.dml/ClientScanCommandData.h"
#include "alinous.remote.region.server.schema.strategy/RegionPartitionTableAccess.h"
#include "alinous.remote.region.server.scan/ScanWorkerResult.h"
#include "alinous.remote.region.server.scan/IScanWorker.h"
#include "alinous.remote.region.server.scan/RangeScanWorker.h"

namespace alinous {namespace remote {namespace region {namespace server {namespace scan {





bool RangeScanWorker::__init_done = __init_static_variables();
bool RangeScanWorker::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"RangeScanWorker", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 RangeScanWorker::RangeScanWorker(ClientScanCommandData* data, RegionPartitionTableAccess* tableAccess, ThreadContext* ctx) throw()  : IObject(ctx), IScanWorker(ctx)
{
}
void RangeScanWorker::__construct_impl(ClientScanCommandData* data, RegionPartitionTableAccess* tableAccess, ThreadContext* ctx) throw() 
{
}
 RangeScanWorker::~RangeScanWorker() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void RangeScanWorker::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
void RangeScanWorker::init(ThreadContext* ctx) throw() 
{
}
ScanWorkerResult* RangeScanWorker::scan(ThreadContext* ctx) throw() 
{
	return nullptr;
}
void RangeScanWorker::__cleanUp(ThreadContext* ctx){
}
}}}}}

