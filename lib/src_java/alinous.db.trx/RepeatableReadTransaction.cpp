#include "includes.h"


namespace alinous {namespace db {namespace trx {





bool RepeatableReadTransaction::__init_done = __init_static_variables();
bool RepeatableReadTransaction::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"RepeatableReadTransaction", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 RepeatableReadTransaction::RepeatableReadTransaction(DbTransactionManager* mgr, String* tmpDir, AlinousDatabase* database, AlinousCore* core, long long commitId, ThreadContext* ctx) throw()  : IObject(ctx), DbTransaction(mgr, tmpDir, database, core, commitId, ctx)
{
}
void RepeatableReadTransaction::__construct_impl(DbTransactionManager* mgr, String* tmpDir, AlinousDatabase* database, AlinousCore* core, long long commitId, ThreadContext* ctx) throw() 
{
}
 RepeatableReadTransaction::~RepeatableReadTransaction() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void RepeatableReadTransaction::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	DbTransaction::__releaseRegerences(true, ctx);
}
bool RepeatableReadTransaction::isVisible(IDatabaseRecord* record, IDatabaseTable* tableStore, ThreadContext* ctx)
{
	{
		try
		{
			long long currentCommitId = this->commitId;
			long long oid = record->getOid(ctx);
			long long lastUpdated = record->getLastUpdateCommitId(ctx);
			if(record->getDeletedCommitId(ctx) > (long long)0 || (lastUpdated != (long long)0 && record->getLastUpdateCommitId(ctx) > currentCommitId) || tableStore->hasLaterVersionBefore(oid, record->getMaxCommitId(ctx), currentCommitId, ctx))
			{
				return false;
			}
		}
		catch(VariableException* e)
		{
			throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1693(), e, ctx));
		}
		catch(InterruptedException* e)
		{
			throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1693(), e, ctx));
		}
		catch(IOException* e)
		{
			throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1693(), e, ctx));
		}
		catch(BTreeException* e)
		{
			throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1693(), e, ctx));
		}
		catch(AlinousException* e)
		{
			throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1693(), e, ctx));
		}
	}
	return true;
}
}}}

