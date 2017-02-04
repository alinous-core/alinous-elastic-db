#include "includes.h"


namespace alinous {namespace db {namespace trx {





bool ReadCommittedTransaction::__init_done = __init_static_variables();
bool ReadCommittedTransaction::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ReadCommittedTransaction", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ReadCommittedTransaction::ReadCommittedTransaction(DbTransactionManager* mgr, String* tmpDir, AlinousDatabase* database, AlinousCore* core, long long commitId, DbVersionContext* vctx, ThreadContext* ctx) throw()  : IObject(ctx), DbTransaction(mgr, tmpDir, database, core, commitId, vctx, ctx)
{
}
void ReadCommittedTransaction::__construct_impl(DbTransactionManager* mgr, String* tmpDir, AlinousDatabase* database, AlinousCore* core, long long commitId, DbVersionContext* vctx, ThreadContext* ctx) throw() 
{
}
 ReadCommittedTransaction::~ReadCommittedTransaction() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ReadCommittedTransaction::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	DbTransaction::__releaseRegerences(true, ctx);
}
bool ReadCommittedTransaction::isVisible(IDatabaseRecord* record, IDatabaseTable* tableStore, ThreadContext* ctx)
{
	{
		try
		{
			long long currentId = this->commitId;
			if(record->getDeletedCommitId(ctx) != (long long)0 || tableStore->hasLaterVersion(record->getOid(ctx), currentId, ctx))
			{
				return false;
			}
		}
		catch(VariableException* e)
		{
			throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1700(), e, ctx));
		}
		catch(InterruptedException* e)
		{
			throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1700(), e, ctx));
		}
		catch(IOException* e)
		{
			throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1700(), e, ctx));
		}
		catch(BTreeException* e)
		{
			throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1700(), e, ctx));
		}
	}
	return true;
}
}}}

