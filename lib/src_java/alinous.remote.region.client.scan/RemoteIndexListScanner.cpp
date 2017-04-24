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
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.db.trx/DbTransaction.h"
#include "alinous.db.table/IScannableIndex.h"
#include "alinous.db.table/IDatabaseTable.h"
#include "alinous.db.table.scan/IndexListScannerParam.h"
#include "alinous.db.table/IBtreeTableIndex.h"
#include "alinous.db.trx.cache/TrxRecordCacheIndex.h"
#include "alinous.db.trx.scan/ScanException.h"
#include "alinous.remote.region.client.scan/IRemoteScanner.h"
#include "alinous.remote.region.client.scan/RemoteIndexListScanner.h"

namespace alinous {namespace remote {namespace region {namespace client {namespace scan {





bool RemoteIndexListScanner::__init_done = __init_static_variables();
bool RemoteIndexListScanner::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"RemoteIndexListScanner", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 RemoteIndexListScanner::RemoteIndexListScanner(ThreadContext* ctx) throw()  : IObject(ctx), IRemoteScanner(ctx)
{
}
void RemoteIndexListScanner::__construct_impl(ThreadContext* ctx) throw() 
{
}
 RemoteIndexListScanner::~RemoteIndexListScanner() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void RemoteIndexListScanner::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
RemoteIndexListScanner* RemoteIndexListScanner::init(ScanTableIdentifier* tableId, DbTransaction* trx, IScannableIndex* index, IDatabaseTable* tableStore, TrxRecordCacheIndex* insertCacheindex, TrxRecordCacheIndex* updateCacheindex, int lockMode, IndexListScannerParam* param, int effectiveKeyLength, InnerNecessaryCondition* necessaryCondition, ScriptMachine* machine, ThreadContext* ctx)
{
	return this;
}
void RemoteIndexListScanner::startScan(ScanResultIndexKey* indexKeyValue, ThreadContext* ctx)
{
}
void RemoteIndexListScanner::endScan(ThreadContext* ctx)
{
}
bool RemoteIndexListScanner::hasNext(bool debug, ThreadContext* ctx)
{
	return false;
}
ScanResultRecord* RemoteIndexListScanner::next(bool debug, ThreadContext* ctx)
{
	return nullptr;
}
void RemoteIndexListScanner::dispose(ISystemLog* logger, ThreadContext* ctx)
{
}
void RemoteIndexListScanner::__cleanUp(ThreadContext* ctx){
}
}}}}}

