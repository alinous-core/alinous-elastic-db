#include "include/global.h"


#include "alinous.btree/BTreeException.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.db.table/IDatabaseTable.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.db.trx/DbVersionContext.h"
#include "alinous.lock.unique/UniqueExclusiveLock.h"
#include "alinous.lock.unique/UniqueExclusiveLockManager.h"
#include "alinous.remote.region.client.command.data/ClientNetworkRecord.h"
#include "alinous.remote.region.server.schema.strategy/UniqueCheckOperation.h"
#include "alinous.remote.db.server/RemoteTableStorageServer.h"
#include "alinous.remote.db.server.commit/PrepareStorageManager.h"
#include "alinous.remote.db.server.trx/UniqueChecker.h"
#include "alinous.remote.db.server.trx/StorageTransaction.h"

namespace alinous {namespace remote {namespace db {namespace server {namespace trx {





bool StorageTransaction::__init_done = __init_static_variables();
bool StorageTransaction::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"StorageTransaction", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 StorageTransaction::StorageTransaction(int isolationLevel, DbVersionContext* vctx, String* datadir, RemoteTableStorageServer* server, ThreadContext* ctx) throw()  : IObject(ctx), isolationLevel(0), vctx(nullptr), datadir(nullptr), tmpDir(nullptr), server(nullptr), uniqueLockMgr(nullptr), uniqueLocks(GCUtils<List<UniqueExclusiveLock> >::ins(this, (new(ctx) ArrayList<UniqueExclusiveLock>(ctx)), ctx, __FILEW__, __LINE__, L"")), uniqueChecker(nullptr), prepareManager(nullptr)
{
	this->isolationLevel = isolationLevel;
	__GC_MV(this, &(this->vctx), vctx, DbVersionContext);
	__GC_MV(this, &(this->datadir), datadir, String);
	__GC_MV(this, &(this->server), server, RemoteTableStorageServer);
	__GC_MV(this, &(this->uniqueLockMgr), server->getUniqueExclusiveLock(ctx), UniqueExclusiveLockManager);
	__GC_MV(this, &(this->uniqueChecker), (new(ctx) UniqueChecker(uniqueLockMgr, this, ctx)), UniqueChecker);
}
void StorageTransaction::__construct_impl(int isolationLevel, DbVersionContext* vctx, String* datadir, RemoteTableStorageServer* server, ThreadContext* ctx) throw() 
{
	this->isolationLevel = isolationLevel;
	__GC_MV(this, &(this->vctx), vctx, DbVersionContext);
	__GC_MV(this, &(this->datadir), datadir, String);
	__GC_MV(this, &(this->server), server, RemoteTableStorageServer);
	__GC_MV(this, &(this->uniqueLockMgr), server->getUniqueExclusiveLock(ctx), UniqueExclusiveLockManager);
	__GC_MV(this, &(this->uniqueChecker), (new(ctx) UniqueChecker(uniqueLockMgr, this, ctx)), UniqueChecker);
}
 StorageTransaction::~StorageTransaction() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void StorageTransaction::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"StorageTransaction", L"~StorageTransaction");
	__e_obj1.add(this->vctx, this);
	vctx = nullptr;
	__e_obj1.add(this->datadir, this);
	datadir = nullptr;
	__e_obj1.add(this->tmpDir, this);
	tmpDir = nullptr;
	__e_obj1.add(this->server, this);
	server = nullptr;
	__e_obj1.add(this->uniqueLockMgr, this);
	uniqueLockMgr = nullptr;
	__e_obj1.add(this->uniqueLocks, this);
	uniqueLocks = nullptr;
	__e_obj1.add(this->uniqueChecker, this);
	uniqueChecker = nullptr;
	__e_obj1.add(this->prepareManager, this);
	prepareManager = nullptr;
	if(!prepare){
		return;
	}
}
void StorageTransaction::prepareInsert(IDatabaseTable* table, List<UniqueCheckOperation>* uniqueCheckOps, List<ClientNetworkRecord>* records, ThreadContext* ctx)
{
	this->uniqueChecker->checkUnique(table, uniqueCheckOps, ctx);
}
void StorageTransaction::addUniqueExclusiveLock(UniqueExclusiveLock* lock, ThreadContext* ctx) throw() 
{
	this->uniqueLocks->add(lock, ctx);
}
void StorageTransaction::unlockUniqueAll(ThreadContext* ctx) throw() 
{
	int maxLoop = this->uniqueLocks->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		UniqueExclusiveLock* lock = this->uniqueLocks->get(i, ctx);
		this->uniqueLockMgr->unlock(lock, ctx);
	}
	this->uniqueLocks->clear(ctx);
}
String* StorageTransaction::getTmpDir(ThreadContext* ctx) throw() 
{
	if(this->tmpDir != nullptr)
	{
		return this->tmpDir;
	}
	StringBuilder* buff = (new(ctx) StringBuilder(256, ctx));
	buff->append(this->datadir, ctx);
	if(!this->datadir->endsWith(ConstStr::getCNST_STR_949(), ctx) && !this->datadir->endsWith(ConstStr::getCNST_STR_1789(), ctx))
	{
		buff->append(ConstStr::getCNST_STR_949(), ctx);
	}
	buff->append(ConstStr::getCNST_STR_3591(), ctx);
	String* strTrxId = Long::toString(this->vctx->getTrxId(ctx), ctx);
	buff->append(strTrxId, ctx);
	__GC_MV(this, &(this->tmpDir), buff->toString(ctx), String);
	return this->tmpDir;
}
int StorageTransaction::getIsolationLevel(ThreadContext* ctx) throw() 
{
	return isolationLevel;
}
DbVersionContext* StorageTransaction::getVctx(ThreadContext* ctx) throw() 
{
	return vctx;
}
void StorageTransaction::dispose(ThreadContext* ctx) throw() 
{
	unlockUniqueAll(ctx);
}
RemoteTableStorageServer* StorageTransaction::getServer(ThreadContext* ctx) throw() 
{
	return server;
}
void StorageTransaction::__cleanUp(ThreadContext* ctx){
}
}}}}}

