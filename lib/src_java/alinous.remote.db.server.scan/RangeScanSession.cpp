#include "include/global.h"


#include "alinous.db.table/IDatabaseTable.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.remote.region.client.command.dml/ClientScanCommandData.h"
#include "alinous.remote.region.server.scan/ScanWorkerResult.h"
#include "alinous.db.trx/TrxLockContext.h"
#include "alinous.remote.db.server.scan/AbstractStorageScanSession.h"
#include "alinous.remote.db.server.scan/RangeScanSession.h"

namespace alinous {namespace remote {namespace db {namespace server {namespace scan {





bool RangeScanSession::__init_done = __init_static_variables();
bool RangeScanSession::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"RangeScanSession", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 RangeScanSession::RangeScanSession(IDatabaseTable* table, ClientScanCommandData* data, ThreadContext* ctx) throw()  : IObject(ctx), AbstractStorageScanSession(table, data, ctx)
{
}
void RangeScanSession::__construct_impl(IDatabaseTable* table, ClientScanCommandData* data, ThreadContext* ctx) throw() 
{
}
 RangeScanSession::~RangeScanSession() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void RangeScanSession::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	AbstractStorageScanSession::__releaseRegerences(true, ctx);
}
ScanWorkerResult* RangeScanSession::scan(ThreadContext* ctx) throw() 
{
	return nullptr;
}
void RangeScanSession::init(ThreadContext* ctx) throw() 
{
}
void RangeScanSession::__cleanUp(ThreadContext* ctx){
}
}}}}}

