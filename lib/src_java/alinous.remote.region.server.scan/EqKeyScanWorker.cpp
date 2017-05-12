#include "include/global.h"


#include "alinous.remote.socket/ICommandData.h"
#include "alinous.remote.region.client.command.dml/ClientScanCommandData.h"
#include "alinous.remote.region.server.schema.strategy/RegionPartitionTableAccess.h"
#include "alinous.remote.region.server.tpc/CommitClusterNodeListner.h"
#include "alinous.remote.region.server.scan/ScanWorkerResult.h"
#include "alinous.remote.region.server.scan/IScanWorker.h"
#include "alinous.remote.region.server.scan/EqKeyScanWorker.h"

namespace alinous {namespace remote {namespace region {namespace server {namespace scan {





bool EqKeyScanWorker::__init_done = __init_static_variables();
bool EqKeyScanWorker::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"EqKeyScanWorker", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 EqKeyScanWorker::EqKeyScanWorker(ClientScanCommandData* data, RegionPartitionTableAccess* tableAccess, CommitClusterNodeListner* accessListner, ThreadContext* ctx) throw()  : IObject(ctx), IScanWorker(ctx)
{
}
void EqKeyScanWorker::__construct_impl(ClientScanCommandData* data, RegionPartitionTableAccess* tableAccess, CommitClusterNodeListner* accessListner, ThreadContext* ctx) throw() 
{
}
 EqKeyScanWorker::~EqKeyScanWorker() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void EqKeyScanWorker::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
void EqKeyScanWorker::init(CommitClusterNodeListner* accessListner, ThreadContext* ctx) throw() 
{
}
ScanWorkerResult* EqKeyScanWorker::scan(ThreadContext* ctx) throw() 
{
	return nullptr;
}
void EqKeyScanWorker::__cleanUp(ThreadContext* ctx){
}
}}}}}

