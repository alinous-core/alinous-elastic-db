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
#include "alinous.remote.db.server.commit/PrepareStorageManager.h"
#include "alinous.remote.region.client.command.data/ClientNetworkRecord.h"
#include "alinous.remote.region.server.schema.strategy/UniqueCheckOperation.h"
#include "alinous.remote.db.server.trx/UniqueChecker.h"
#include "alinous.remote.db.server.trx/StorageTransaction.h"
#include "alinous.remote.db.server/RemoteTableStorageServer.h"
#include "alinous.remote.db.server.trx/SerializableStorageTransaction.h"

namespace alinous {namespace remote {namespace db {namespace server {namespace trx {





bool SerializableStorageTransaction::__init_done = __init_static_variables();
bool SerializableStorageTransaction::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"SerializableStorageTransaction", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 SerializableStorageTransaction::SerializableStorageTransaction(int isolationLevel, DbVersionContext* vctx, String* datadir, RemoteTableStorageServer* server, ThreadContext* ctx) throw()  : IObject(ctx), StorageTransaction(isolationLevel, vctx, datadir, server, ctx)
{
}
void SerializableStorageTransaction::__construct_impl(int isolationLevel, DbVersionContext* vctx, String* datadir, RemoteTableStorageServer* server, ThreadContext* ctx) throw() 
{
}
 SerializableStorageTransaction::~SerializableStorageTransaction() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void SerializableStorageTransaction::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	StorageTransaction::__releaseRegerences(true, ctx);
}
bool SerializableStorageTransaction::isVisible(IDatabaseRecord* record, ThreadContext* ctx) throw() 
{
	if(record->getLastUpdateCommitId(ctx) != (long long)0 || record->getDeletedCommitId(ctx) != (long long)0)
	{
		return false;
	}
	return true;
}
void SerializableStorageTransaction::__cleanUp(ThreadContext* ctx){
}
}}}}}

