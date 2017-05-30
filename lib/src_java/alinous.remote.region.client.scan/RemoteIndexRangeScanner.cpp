#include "include/global.h"


#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.compile.sql.analyze/InnerNecessaryCondition.h"
#include "alinous.compile.sql.analyze/ScanTableIdentifier.h"
#include "alinous.db/AlinousDbException.h"
#include "alinous.db.table/DatabaseException.h"
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
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.db.trx/DbTransaction.h"
#include "alinous.db.table/IScannableIndex.h"
#include "alinous.db.table/IDatabaseTable.h"
#include "alinous.db.table.scan/IndexRangeScannerParam.h"
#include "alinous.db.table/IBtreeTableIndex.h"
#include "alinous.db.trx.cache/TrxRecordCacheIndex.h"
#include "alinous.db.trx.scan/ScanException.h"
#include "alinous.remote.region.client.scan/AbstractRemoteScanner.h"
#include "alinous.remote.region.client.scan/RemoteIndexRangeScanner.h"

namespace alinous {namespace remote {namespace region {namespace client {namespace scan {





bool RemoteIndexRangeScanner::__init_done = __init_static_variables();
bool RemoteIndexRangeScanner::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"RemoteIndexRangeScanner", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 RemoteIndexRangeScanner::RemoteIndexRangeScanner(ThreadContext* ctx) throw()  : IObject(ctx), AbstractRemoteScanner(ctx)
{
}
void RemoteIndexRangeScanner::__construct_impl(ThreadContext* ctx) throw() 
{
}
 RemoteIndexRangeScanner::~RemoteIndexRangeScanner() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void RemoteIndexRangeScanner::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	AbstractRemoteScanner::__releaseRegerences(true, ctx);
}
RemoteIndexRangeScanner* RemoteIndexRangeScanner::init(ScanTableIdentifier* tableId, DbTransaction* trx, IScannableIndex* index, IDatabaseTable* tableStore, TrxRecordCacheIndex* insertCacheindex, TrxRecordCacheIndex* updateCacheindex, int lockMode, IndexRangeScannerParam* param, int effectiveKeyLength, InnerNecessaryCondition* necessaryCondition, ScriptMachine* machine, ThreadContext* ctx)
{
	TableAccessStatusListner* listner = trx->getAccessListner(ctx);
	listner->setStatus(tableStore->getFullName(ctx), TableAccessStatus::STAT_COMMITTED_NEEDED, ctx);
	return this;
}
void RemoteIndexRangeScanner::startScan(ScanResultIndexKey* indexKeyValue, ThreadContext* ctx)
{
}
void RemoteIndexRangeScanner::endScan(ThreadContext* ctx)
{
}
bool RemoteIndexRangeScanner::hasNext(bool debug, ThreadContext* ctx)
{
	return false;
}
ScanResultRecord* RemoteIndexRangeScanner::next(bool debug, ThreadContext* ctx)
{
	return nullptr;
}
void RemoteIndexRangeScanner::dispose(ISystemLog* logger, ThreadContext* ctx)
{
}
void RemoteIndexRangeScanner::__cleanUp(ThreadContext* ctx){
}
}}}}}

