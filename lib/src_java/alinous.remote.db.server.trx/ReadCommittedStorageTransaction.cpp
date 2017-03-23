#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.db.trx/DbVersionContext.h"
#include "alinous.db.table/IDatabaseTable.h"
#include "alinous.lock.unique/UniqueExclusiveLock.h"
#include "alinous.lock.unique/UniqueExclusiveLockManager.h"
#include "alinous.remote.region.client.command.data/ClientNetworkRecord.h"
#include "alinous.remote.db.server.commit/PrepareStorageManager.h"
#include "alinous.remote.region.server.schema.strategy/UniqueCheckOperation.h"
#include "alinous.remote.db.server.trx/UniqueChecker.h"
#include "alinous.remote.db.server.trx/StorageTransaction.h"
#include "alinous.remote.db.server/RemoteTableStorageServer.h"
#include "alinous.remote.db.server.trx/ReadCommittedStorageTransaction.h"

namespace alinous {namespace remote {namespace db {namespace server {namespace trx {





bool ReadCommittedStorageTransaction::__init_done = __init_static_variables();
bool ReadCommittedStorageTransaction::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ReadCommittedStorageTransaction", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ReadCommittedStorageTransaction::ReadCommittedStorageTransaction(int isolationLevel, DbVersionContext* vctx, String* datadir, RemoteTableStorageServer* server, ThreadContext* ctx) throw()  : IObject(ctx), StorageTransaction(isolationLevel, vctx, datadir, server, ctx)
{
}
void ReadCommittedStorageTransaction::__construct_impl(int isolationLevel, DbVersionContext* vctx, String* datadir, RemoteTableStorageServer* server, ThreadContext* ctx) throw() 
{
}
 ReadCommittedStorageTransaction::~ReadCommittedStorageTransaction() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ReadCommittedStorageTransaction::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	StorageTransaction::__releaseRegerences(true, ctx);
}
bool ReadCommittedStorageTransaction::isVisible(IDatabaseRecord* record, ThreadContext* ctx) throw() 
{
	long long deletedVer = record->getDeletedCommitId(ctx);
	long long updatedVer = record->getLastUpdateCommitId(ctx);
	long long inserted = record->getInsertedCommitId(ctx);
	long long currentVer = this->getVctx(ctx)->getCommitId(ctx);
	if(inserted <= currentVer && currentVer < updatedVer && (deletedVer == (long long)0 || deletedVer > currentVer))
	{
		return true;
	}
	return false;
}
void ReadCommittedStorageTransaction::__cleanUp(ThreadContext* ctx){
}
}}}}}

