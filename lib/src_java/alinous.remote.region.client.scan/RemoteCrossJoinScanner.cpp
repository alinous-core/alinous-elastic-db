#include "include/global.h"


#include "alinous.compile.sql.analyze/ScanTableMetadata.h"
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
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.db.trx/DbTransaction.h"
#include "alinous.db.trx.scan/ScanException.h"
#include "alinous.remote.region.client.scan/IRemoteScanner.h"
#include "alinous.remote.region.client.scan/IRemoteJoinScanner.h"
#include "alinous.remote.region.client.scan/RemoteCrossJoinScanner.h"

namespace alinous {namespace remote {namespace region {namespace client {namespace scan {





bool RemoteCrossJoinScanner::__init_done = __init_static_variables();
bool RemoteCrossJoinScanner::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"RemoteCrossJoinScanner", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 RemoteCrossJoinScanner::RemoteCrossJoinScanner(ThreadContext* ctx) throw()  : IObject(ctx), IRemoteJoinScanner(ctx)
{
}
void RemoteCrossJoinScanner::__construct_impl(ThreadContext* ctx) throw() 
{
}
 RemoteCrossJoinScanner::~RemoteCrossJoinScanner() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void RemoteCrossJoinScanner::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
RemoteCrossJoinScanner* RemoteCrossJoinScanner::init(DbTransaction* trx, ITableTargetScanner* left, ITableTargetScanner* right, ScanTableMetadata* leftMetadata, ScanTableMetadata* rightMetadata, ScriptMachine* machine, ThreadContext* ctx) throw() 
{
	return this;
}
void RemoteCrossJoinScanner::startScan(ScanResultIndexKey* indexKeyValue, ThreadContext* ctx)
{
}
void RemoteCrossJoinScanner::endScan(ThreadContext* ctx)
{
}
bool RemoteCrossJoinScanner::hasNext(bool debug, ThreadContext* ctx)
{
	return false;
}
ScanResultRecord* RemoteCrossJoinScanner::next(bool debug, ThreadContext* ctx)
{
	return nullptr;
}
void RemoteCrossJoinScanner::dispose(ISystemLog* logger, ThreadContext* ctx)
{
}
void RemoteCrossJoinScanner::__cleanUp(ThreadContext* ctx){
}
}}}}}

