#include "include/global.h"


#include "alinous.remote.socket/ICommandData.h"
#include "alinous.remote.region.client.command.dml/ClientScanCommandData.h"
#include "alinous.remote.region.server.schema.strategy/RegionPartitionTableAccess.h"
#include "alinous.remote.region.server.tpc/CommitClusterNodeListner.h"
#include "alinous.remote.region.server.scan/ScanWorkerResult.h"
#include "alinous.remote.region.server.scan/IScanWorker.h"
#include "alinous.remote.region.server.scan/ListScanWorker.h"

namespace alinous {namespace remote {namespace region {namespace server {namespace scan {





bool ListScanWorker::__init_done = __init_static_variables();
bool ListScanWorker::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ListScanWorker", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ListScanWorker::ListScanWorker(ClientScanCommandData* data, RegionPartitionTableAccess* tableAccess, CommitClusterNodeListner* accessListner, ThreadContext* ctx) throw()  : IObject(ctx), IScanWorker(ctx)
{
}
void ListScanWorker::__construct_impl(ClientScanCommandData* data, RegionPartitionTableAccess* tableAccess, CommitClusterNodeListner* accessListner, ThreadContext* ctx) throw() 
{
}
 ListScanWorker::~ListScanWorker() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ListScanWorker::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
void ListScanWorker::init(CommitClusterNodeListner* accessListner, ThreadContext* ctx) throw() 
{
}
ScanWorkerResult* ListScanWorker::scan(ThreadContext* ctx) throw() 
{
	return nullptr;
}
void ListScanWorker::__cleanUp(ThreadContext* ctx){
}
}}}}}

