#include "include/global.h"


#include "alinous.compile.sql.analyze/ScanTableIdentifier.h"
#include "alinous.db.table/DatabaseException.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.system/ISystemLog.h"
#include "java.lang/Comparable.h"
#include "alinous.btree/IBTreeKey.h"
#include "alinous.db.trx.scan/ScanResultIndexKey.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.db.trx.scan/ScanResultRecord.h"
#include "alinous.db.trx.scan/ITableTargetScanner.h"
#include "alinous.db.trx/DbTransaction.h"
#include "alinous.db.table/IScannableIndex.h"
#include "alinous.db.table/IDatabaseTable.h"
#include "alinous.db.trx.scan/ScanException.h"
#include "alinous.remote.region.client.scan/IRemoteScanner.h"
#include "alinous.remote.region.client.scan/RemoteTableIndexScanner.h"

namespace alinous {namespace remote {namespace region {namespace client {namespace scan {





bool RemoteTableIndexScanner::__init_done = __init_static_variables();
bool RemoteTableIndexScanner::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"RemoteTableIndexScanner", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 RemoteTableIndexScanner::RemoteTableIndexScanner(ThreadContext* ctx) throw()  : IObject(ctx), IRemoteScanner(ctx)
{
}
void RemoteTableIndexScanner::__construct_impl(ThreadContext* ctx) throw() 
{
}
 RemoteTableIndexScanner::~RemoteTableIndexScanner() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void RemoteTableIndexScanner::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
RemoteTableIndexScanner* RemoteTableIndexScanner::init(ScanTableIdentifier* tableId, DbTransaction* trx, IScannableIndex* index, IDatabaseTable* tableStore, int lockMode, ThreadContext* ctx)
{
	return this;
}
void RemoteTableIndexScanner::startScan(ScanResultIndexKey* indexKeyValue, ThreadContext* ctx)
{
}
void RemoteTableIndexScanner::endScan(ThreadContext* ctx)
{
}
bool RemoteTableIndexScanner::hasNext(bool debug, ThreadContext* ctx)
{
	return false;
}
ScanResultRecord* RemoteTableIndexScanner::next(bool debug, ThreadContext* ctx)
{
	return nullptr;
}
void RemoteTableIndexScanner::dispose(ISystemLog* logger, ThreadContext* ctx)
{
}
void RemoteTableIndexScanner::__cleanUp(ThreadContext* ctx){
}
}}}}}

