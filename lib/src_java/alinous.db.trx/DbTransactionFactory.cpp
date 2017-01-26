#include "includes.h"


namespace alinous {namespace db {namespace trx {





bool DbTransactionFactory::__init_done = __init_static_variables();
bool DbTransactionFactory::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DbTransactionFactory", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 DbTransactionFactory::~DbTransactionFactory() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void DbTransactionFactory::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
DbTransaction* DbTransactionFactory::newTransaction(int acid, DbTransactionManager* mgr, String* tmpDir, AlinousDatabase* database, AlinousCore* core, long long commitId, DbVersionContext* vctx, ThreadContext* ctx) throw() 
{
	if(database->isRemote(ctx))
	{
		return newRemoteTransaction(acid, mgr, tmpDir, database, core, commitId, vctx, ctx);
	}
	DbTransaction* trx = nullptr;
	switch(acid) {
	case IDatabaseDriver::READ_COMMITTED:
		trx = (new(ctx) ReadCommittedTransaction(mgr, tmpDir, database, core, commitId, ctx));
		break ;
	case IDatabaseDriver::REPEATABLE_READ:
		trx = (new(ctx) RepeatableReadTransaction(mgr, tmpDir, database, core, commitId, ctx));
		break ;
	case IDatabaseDriver::SERIALIZABLE:
	default:
		trx = (new(ctx) SerializableTransaction(mgr, tmpDir, database, core, commitId, ctx));
		break ;
	}
	return trx;
}
DbTransaction* DbTransactionFactory::newRemoteTransaction(int acid, DbTransactionManager* mgr, String* tmpDir, AlinousDatabase* database, AlinousCore* core, long long commitId, DbVersionContext* vctx, ThreadContext* ctx) throw() 
{
	DbTransaction* trx = nullptr;
	switch(acid) {
	case IDatabaseDriver::READ_COMMITTED:
		trx = (new(ctx) RemoteClientReadCommittedTrx(mgr, tmpDir, database, core, commitId, ctx));
		break ;
	case IDatabaseDriver::REPEATABLE_READ:
		trx = (new(ctx) RemoteClientRepeatableReadTrx(mgr, tmpDir, database, core, commitId, ctx));
		break ;
	case IDatabaseDriver::SERIALIZABLE:
	default:
		trx = (new(ctx) RemoteClientSerializableTrx(mgr, tmpDir, database, core, commitId, ctx));
		break ;
	}
	return trx;
}
}}}

