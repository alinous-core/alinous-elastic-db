#include "include/global.h"


#include "alinous.btree/BTreeException.h"
#include "alinous.db.table/DatabaseException.h"
#include "alinous.db.table.lockmonitor/DatabaseLockException.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.db.table/IDatabaseTable.h"
#include "alinous.db.trx/TrxLockContext.h"
#include "alinous.db.trx.scan/ScanException.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.remote.region.client.command.dml/ClientScanCommandData.h"
#include "alinous.remote.region.server.scan/ScanWorkerResult.h"
#include "alinous.remote.db.server.scan/AbstractStorageScanSession.h"

namespace alinous {namespace remote {namespace db {namespace server {namespace scan {





bool AbstractStorageScanSession::__init_done = __init_static_variables();
bool AbstractStorageScanSession::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AbstractStorageScanSession", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AbstractStorageScanSession::AbstractStorageScanSession(IDatabaseTable* table, ClientScanCommandData* data, ThreadContext* ctx) throw()  : IObject(ctx), table(nullptr), data(nullptr), maxRecords(10000), locker(nullptr)
{
	__GC_MV(this, &(this->table), table, IDatabaseTable);
	__GC_MV(this, &(this->data), data, ClientScanCommandData);
	__GC_MV(this, &(this->locker), (new(ctx) TrxLockContext(ctx)), TrxLockContext);
}
void AbstractStorageScanSession::__construct_impl(IDatabaseTable* table, ClientScanCommandData* data, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->table), table, IDatabaseTable);
	__GC_MV(this, &(this->data), data, ClientScanCommandData);
	__GC_MV(this, &(this->locker), (new(ctx) TrxLockContext(ctx)), TrxLockContext);
}
 AbstractStorageScanSession::~AbstractStorageScanSession() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AbstractStorageScanSession::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"AbstractStorageScanSession", L"~AbstractStorageScanSession");
	__e_obj1.add(this->table, this);
	table = nullptr;
	__e_obj1.add(this->data, this);
	data = nullptr;
	__e_obj1.add(this->locker, this);
	locker = nullptr;
	if(!prepare){
		return;
	}
}
void AbstractStorageScanSession::dispose(ThreadContext* ctx) throw() 
{
	if(this->locker != nullptr)
	{
		{
			try
			{
				this->locker->reset(ctx);
			}
			catch(DatabaseLockException* e)
			{
				e->printStackTrace(ctx);
			}
		}
		__GC_MV(this, &(this->locker), nullptr, TrxLockContext);
	}
}
void AbstractStorageScanSession::clearRowLocks(ThreadContext* ctx) throw() 
{
	if(this->locker == nullptr)
	{
		return;
	}
	{
		try
		{
			this->locker->reset(ctx);
		}
		catch(DatabaseLockException* e)
		{
			e->printStackTrace(ctx);
		}
	}
}
void AbstractStorageScanSession::__cleanUp(ThreadContext* ctx){
}
}}}}}

