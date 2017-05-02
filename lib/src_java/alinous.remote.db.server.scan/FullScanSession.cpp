#include "include/global.h"


#include "alinous.db.table/IDatabaseTable.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.remote.region.client.command.dml/ClientScanCommandData.h"
#include "alinous.remote.region.server.scan/ScanWorkerResult.h"
#include "alinous.remote.db.server.scan/AbstractStorageScanSession.h"
#include "alinous.remote.db.server.scan/FullScanSession.h"

namespace alinous {namespace remote {namespace db {namespace server {namespace scan {





bool FullScanSession::__init_done = __init_static_variables();
bool FullScanSession::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"FullScanSession", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 FullScanSession::FullScanSession(IDatabaseTable* table, ClientScanCommandData* data, ThreadContext* ctx) throw()  : IObject(ctx), AbstractStorageScanSession(table, data, ctx)
{
}
void FullScanSession::__construct_impl(IDatabaseTable* table, ClientScanCommandData* data, ThreadContext* ctx) throw() 
{
}
 FullScanSession::~FullScanSession() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void FullScanSession::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	AbstractStorageScanSession::__releaseRegerences(true, ctx);
}
ScanWorkerResult* FullScanSession::scan(ThreadContext* ctx) throw() 
{
	return nullptr;
}
void FullScanSession::init(ThreadContext* ctx) throw() 
{
}
void FullScanSession::__cleanUp(ThreadContext* ctx){
}
}}}}}

