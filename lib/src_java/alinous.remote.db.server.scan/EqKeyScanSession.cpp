#include "include/global.h"


#include "alinous.db.table/IDatabaseTable.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.remote.region.client.command.dml/ClientScanCommandData.h"
#include "alinous.remote.region.server.scan/ScanWorkerResult.h"
#include "alinous.remote.db.server.scan/AbstractStorageScanSession.h"
#include "alinous.remote.db.server.scan/EqKeyScanSession.h"

namespace alinous {namespace remote {namespace db {namespace server {namespace scan {





bool EqKeyScanSession::__init_done = __init_static_variables();
bool EqKeyScanSession::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"EqKeyScanSession", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 EqKeyScanSession::EqKeyScanSession(IDatabaseTable* table, ClientScanCommandData* data, ThreadContext* ctx) throw()  : IObject(ctx), AbstractStorageScanSession(table, data, ctx)
{
}
void EqKeyScanSession::__construct_impl(IDatabaseTable* table, ClientScanCommandData* data, ThreadContext* ctx) throw() 
{
}
 EqKeyScanSession::~EqKeyScanSession() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void EqKeyScanSession::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	AbstractStorageScanSession::__releaseRegerences(true, ctx);
}
ScanWorkerResult* EqKeyScanSession::scan(ThreadContext* ctx) throw() 
{
	return nullptr;
}
void EqKeyScanSession::init(ThreadContext* ctx) throw() 
{
}
void EqKeyScanSession::__cleanUp(ThreadContext* ctx){
}
}}}}}

