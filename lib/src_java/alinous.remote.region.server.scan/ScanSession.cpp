#include "include/global.h"


#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.db/AlinousDbException.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.remote.region.client.command.dml/ClientScanCommandData.h"
#include "alinous.remote.region.server.schema.strategy/RegionPartitionTableAccess.h"
#include "alinous.remote.region.server.scan/ScanWorkerResult.h"
#include "alinous.remote.region.server.scan/IScanWorker.h"
#include "alinous.remote.region.server.scan/FullScanWorker.h"
#include "alinous.remote.region.server.scan/EqKeyScanWorker.h"
#include "alinous.remote.region.server.scan/ListScanWorker.h"
#include "alinous.remote.region.server.scan/RangeScanWorker.h"
#include "alinous.remote.region.server.scan/ScanSession.h"

namespace alinous {namespace remote {namespace region {namespace server {namespace scan {





bool ScanSession::__init_done = __init_static_variables();
bool ScanSession::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ScanSession", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ScanSession::ScanSession(ClientScanCommandData* data, ThreadContext* ctx) throw()  : IObject(ctx), data(nullptr), worker(nullptr)
{
	__GC_MV(this, &(this->data), data, ClientScanCommandData);
}
void ScanSession::__construct_impl(ClientScanCommandData* data, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->data), data, ClientScanCommandData);
}
 ScanSession::~ScanSession() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ScanSession::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ScanSession", L"~ScanSession");
	__e_obj1.add(this->data, this);
	data = nullptr;
	__e_obj1.add(this->worker, this);
	worker = nullptr;
	if(!prepare){
		return;
	}
}
ScanSession* ScanSession::init(RegionPartitionTableAccess* tableAccess, ThreadContext* ctx)
{
	if(this->data->isFullscan(ctx))
	{
		__GC_MV(this, &(this->worker), (new(ctx) FullScanWorker(this->data, tableAccess, ctx)), IScanWorker);
	}
		else 
	{
		if(this->data->getEqKey(ctx) != nullptr)
		{
			__GC_MV(this, &(this->worker), (new(ctx) EqKeyScanWorker(this->data, tableAccess, ctx)), IScanWorker);
		}
				else 
		{
			if(this->data->getListParam(ctx) != nullptr)
			{
				__GC_MV(this, &(this->worker), (new(ctx) ListScanWorker(this->data, tableAccess, ctx)), IScanWorker);
			}
						else 
			{
				if(this->data->getRangeParam(ctx) != nullptr)
				{
					__GC_MV(this, &(this->worker), (new(ctx) RangeScanWorker(this->data, tableAccess, ctx)), IScanWorker);
				}
								else 
				{
					throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_3597(), ctx));
				}
			}
		}
	}
	this->worker->init(ctx);
	return this;
}
ScanWorkerResult* ScanSession::scan(ThreadContext* ctx)
{
	return this->worker->scan(ctx);
}
void ScanSession::__cleanUp(ThreadContext* ctx){
}
}}}}}

