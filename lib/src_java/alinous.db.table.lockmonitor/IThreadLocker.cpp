#include "include/global.h"


#include "alinous.db.table/DatabaseException.h"
#include "alinous.db.table.lockmonitor/DatabaseLockException.h"
#include "alinous.lock/ConcurrentGate.h"
#include "alinous.db.table.lockmonitor/ConcurrentGatePool.h"
#include "alinous.db.table.lockmonitor/IDatabaseLock.h"
#include "alinous.db.table.lockmonitor/TableLock.h"
#include "alinous.db.table.lockmonitor/RowLock.h"
#include "alinous.db.table.lockmonitor/IThreadLocker.h"
#include "alinous.runtime.parallel/ThreadPool.h"
#include "alinous.db.table/IDatabaseTable.h"
#include "alinous.db.table.lockmonitor/ThreadLocker.h"
#include "alinous.db.table.lockmonitor.db/RowLockDb.h"
#include "alinous.db.table.lockmonitor.db/TableLockHashDb.h"
#include "alinous.db.table.lockmonitor/DBThreadMonitor.h"
#include "alinous.runtime.parallel/IThreadAction.h"
#include "alinous.db.table.lockmonitor/RowLockReleaser.h"

namespace alinous {namespace db {namespace table {namespace lockmonitor {




bool IThreadLocker::__init_done = __init_static_variables();
bool IThreadLocker::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"IThreadLocker", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 IThreadLocker::IThreadLocker(ThreadContext* ctx) throw()  : IObject(ctx)
{
}
void IThreadLocker::__construct_impl(ThreadContext* ctx) throw() 
{
}
 IThreadLocker::~IThreadLocker() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void IThreadLocker::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
void IThreadLocker::__cleanUp(ThreadContext* ctx){
}
}}}}

