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




int IDatabaseLock::TABLE_LOCK = 0;
int IDatabaseLock::ROW_LOCK = 0;
bool IDatabaseLock::__init_done = __init_static_variables();
bool IDatabaseLock::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"IDatabaseLock", L"__init_static_variables");
		IDatabaseLock::TABLE_LOCK = 1;
		IDatabaseLock::ROW_LOCK = 2;
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 IDatabaseLock::IDatabaseLock(ThreadContext* ctx) throw()  : IObject(ctx)
{
}
void IDatabaseLock::__construct_impl(ThreadContext* ctx) throw() 
{
}
 IDatabaseLock::~IDatabaseLock() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void IDatabaseLock::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
void IDatabaseLock::__cleanUp(ThreadContext* ctx){
}
}}}}

