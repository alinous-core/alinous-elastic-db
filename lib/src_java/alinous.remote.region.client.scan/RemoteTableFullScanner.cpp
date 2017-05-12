#include "include/global.h"


#include "alinous.compile.sql.analyze/ScanTableIdentifier.h"
#include "alinous.db.table/DatabaseException.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.system/ISystemLog.h"
#include "java.lang/Comparable.h"
#include "alinous.btree/IBTreeKey.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.db.trx.scan/ScanResultIndexKey.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.db.trx.scan/ScanResultRecord.h"
#include "alinous.db.trx.scan/ITableTargetScanner.h"
#include "alinous.remote.region.client/TableAccessStatus.h"
#include "alinous.remote.region.client/TableAccessStatusListner.h"
#include "alinous.db.trx/DbTransaction.h"
#include "alinous.db.table/IDatabaseTable.h"
#include "alinous.db.trx.scan/ScanException.h"
#include "alinous.remote.region.client.scan/IRemoteScanner.h"
#include "alinous.remote.region.client.scan/RemoteTableFullScanner.h"

namespace alinous {namespace remote {namespace region {namespace client {namespace scan {





bool RemoteTableFullScanner::__init_done = __init_static_variables();
bool RemoteTableFullScanner::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"RemoteTableFullScanner", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 RemoteTableFullScanner::RemoteTableFullScanner(ThreadContext* ctx) throw()  : IObject(ctx), IRemoteScanner(ctx)
{
}
void RemoteTableFullScanner::__construct_impl(ThreadContext* ctx) throw() 
{
}
 RemoteTableFullScanner::~RemoteTableFullScanner() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void RemoteTableFullScanner::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
RemoteTableFullScanner* RemoteTableFullScanner::init(ScanTableIdentifier* tableId, DbTransaction* trx, IDatabaseTable* tableStore, int lockMode, ThreadContext* ctx)
{
	TableAccessStatusListner* listner = trx->getAccessListner(ctx);
	listner->setStatus(tableStore->getFullName(ctx), TableAccessStatus::STAT_COMMITTED_NEEDED, ctx);
	return this;
}
void RemoteTableFullScanner::startScan(ScanResultIndexKey* indexKeyValue, ThreadContext* ctx)
{
}
void RemoteTableFullScanner::endScan(ThreadContext* ctx)
{
}
bool RemoteTableFullScanner::hasNext(bool debug, ThreadContext* ctx)
{
	return false;
}
ScanResultRecord* RemoteTableFullScanner::next(bool debug, ThreadContext* ctx)
{
	return nullptr;
}
void RemoteTableFullScanner::dispose(ISystemLog* logger, ThreadContext* ctx)
{
}
void RemoteTableFullScanner::__cleanUp(ThreadContext* ctx){
}
}}}}}

