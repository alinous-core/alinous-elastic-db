#include "include/global.h"


#include "alinous.remote.socket/ICommandData.h"
#include "alinous.db.trx/DbVersionContext.h"
#include "alinous.lock/LockObject.h"
#include "alinous.remote.db.server/StorageTransaction.h"
#include "alinous.remote.db.server/RemoteTableStorageServer.h"
#include "java.lang/Number.h"
#include "java.lang/Comparable.h"
#include "java.lang/Long.h"
#include "alinous.remote.db.server/StorageTransactionManager.h"

namespace alinous {namespace remote {namespace db {namespace server {





bool StorageTransactionManager::__init_done = __init_static_variables();
bool StorageTransactionManager::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"StorageTransactionManager", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 StorageTransactionManager::StorageTransactionManager(String* datadir, RemoteTableStorageServer* server, ThreadContext* ctx) throw()  : IObject(ctx), lock(__GC_INS(this, (new(ctx) LockObject(ctx)), LockObject)), transactions(GCUtils<Map<Long,StorageTransaction> >::ins(this, (new(ctx) HashMap<Long,StorageTransaction>(ctx)), ctx, __FILEW__, __LINE__, L"")), datadir(nullptr), server(nullptr)
{
	__GC_MV(this, &(this->datadir), datadir, String);
	__GC_MV(this, &(this->server), server, RemoteTableStorageServer);
}
void StorageTransactionManager::__construct_impl(String* datadir, RemoteTableStorageServer* server, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->datadir), datadir, String);
	__GC_MV(this, &(this->server), server, RemoteTableStorageServer);
}
 StorageTransactionManager::~StorageTransactionManager() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void StorageTransactionManager::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"StorageTransactionManager", L"~StorageTransactionManager");
	__e_obj1.add(this->lock, this);
	lock = nullptr;
	__e_obj1.add(this->transactions, this);
	transactions = nullptr;
	__e_obj1.add(this->datadir, this);
	datadir = nullptr;
	__e_obj1.add(this->server, this);
	server = nullptr;
	if(!prepare){
		return;
	}
}
void StorageTransactionManager::dispose(ThreadContext* ctx) throw() 
{
}
StorageTransaction* StorageTransactionManager::getStorageTransaction(int isolationLevel, DbVersionContext* vctx, ThreadContext* ctx) throw() 
{
	Long* id = (new(ctx) Long(vctx->getTrxId(ctx), ctx));
	{
		SynchronizedBlockObj __synchronized_2(this->lock, ctx);
		StorageTransaction* strx = this->transactions->get(id, ctx);
		if(strx == nullptr)
		{
			strx = (new(ctx) StorageTransaction(isolationLevel, vctx, this->datadir, this->server, ctx));
			this->transactions->put(id, strx, ctx);
		}
		return strx;
	}
}
void StorageTransactionManager::finishTransaction(long long strxId, ThreadContext* ctx) throw() 
{
	Long* id = (new(ctx) Long(strxId, ctx));
	StorageTransaction* strx = this->transactions->get(id, ctx);
	if(strx == nullptr)
	{
		return;
	}
	strx->dispose(ctx);
	this->transactions->remove(id, ctx);
}
void StorageTransactionManager::__cleanUp(ThreadContext* ctx){
}
}}}}

