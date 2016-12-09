#include "includes.h"


namespace alinous {namespace db {namespace trx {





bool SerializableTransaction::__init_done = __init_static_variables();
bool SerializableTransaction::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"SerializableTransaction", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 SerializableTransaction::SerializableTransaction(DbTransactionManager* mgr, String* tmpDir, AlinousDatabase* database, ISystemLog* logger, long long trxId, ThreadContext* ctx) throw()  : IObject(ctx), DbTransaction(mgr, tmpDir, database, logger, trxId, ctx)
{
}
void SerializableTransaction::__construct_impl(DbTransactionManager* mgr, String* tmpDir, AlinousDatabase* database, ISystemLog* logger, long long trxId, ThreadContext* ctx) throw() 
{
}
 SerializableTransaction::~SerializableTransaction() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void SerializableTransaction::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	DbTransaction::__releaseRegerences(true, ctx);
}
bool SerializableTransaction::isVisible(IDatabaseRecord* record, IDatabaseTable* tableStore, ThreadContext* ctx)
{
	{
		try
		{
			long long currentCommitId = this->commitId;
			long long oid = record->getOid(ctx);
			long long lastUpdated = record->getLastUpdateCommitId(ctx);
			if(record->getDeletedCommitId(ctx) > (long long)0 || record->getInsertedCommitId(ctx) > currentCommitId || (lastUpdated != (long long)0 && record->getLastUpdateCommitId(ctx) > currentCommitId) || tableStore->hasLaterVersionBefore(oid, record->getMaxCommitId(ctx), currentCommitId, ctx))
			{
				return false;
			}
		}
		catch(VariableException* e)
		{
			throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1614(), e, ctx));
		}
		catch(InterruptedException* e)
		{
			throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1614(), e, ctx));
		}
		catch(IOException* e)
		{
			throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1614(), e, ctx));
		}
		catch(BTreeException* e)
		{
			throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1614(), e, ctx));
		}
	}
	return true;
}
}}}

