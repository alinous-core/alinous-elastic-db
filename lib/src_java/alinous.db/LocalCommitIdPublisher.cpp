#include "includes.h"


namespace alinous {namespace db {





bool LocalCommitIdPublisher::__init_done = __init_static_variables();
bool LocalCommitIdPublisher::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"LocalCommitIdPublisher", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 LocalCommitIdPublisher::LocalCommitIdPublisher(AlinousDatabase* database, ThreadContext* ctx) throw()  : IObject(ctx), ICommidIdPublisher(ctx), maxCommitId(0), lock(__GC_INS(this, (new(ctx) LockObject(ctx)), LockObject)), database(nullptr), trxId(1), schemaVersion(1)
{
	__GC_MV(this, &(this->database), database, AlinousDatabase);
}
void LocalCommitIdPublisher::__construct_impl(AlinousDatabase* database, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->database), database, AlinousDatabase);
}
 LocalCommitIdPublisher::~LocalCommitIdPublisher() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void LocalCommitIdPublisher::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"LocalCommitIdPublisher", L"~LocalCommitIdPublisher");
	__e_obj1.add(this->lock, this);
	lock = nullptr;
	__e_obj1.add(this->database, this);
	database = nullptr;
	if(!prepare){
		return;
	}
}
void LocalCommitIdPublisher::setMaxCommitId(long long maxCommitId, ThreadContext* ctx) throw() 
{
	{
		SynchronizedBlockObj __synchronized_2(this->lock, ctx);
		this->maxCommitId = maxCommitId;
	}
}
long long LocalCommitIdPublisher::getMaxCommitId(ThreadContext* ctx) throw() 
{
	{
		SynchronizedBlockObj __synchronized_2(this->lock, ctx);
		return maxCommitId;
	}
}
long long LocalCommitIdPublisher::newCommitId(ThreadContext* ctx)
{
	{
		SynchronizedBlockObj __synchronized_2(this->lock, ctx);
		this->maxCommitId ++ ;
		this->database->syncScheme(ctx);
		return this->maxCommitId;
	}
}
void LocalCommitIdPublisher::addSchemaVersion(ThreadContext* ctx) throw() 
{
	{
		SynchronizedBlockObj __synchronized_2(this->lock, ctx);
		this->schemaVersion ++ ;
	}
}
long long LocalCommitIdPublisher::getSchemaVersion(ThreadContext* ctx) throw() 
{
	{
		SynchronizedBlockObj __synchronized_2(this->lock, ctx);
		return this->schemaVersion;
	}
}
DbVersionContext* LocalCommitIdPublisher::newTransactionContext(ThreadContext* ctx) throw() 
{
	DbVersionContext* context = (new(ctx) DbVersionContext(ctx));
	context->setCommitId(getMaxCommitId(ctx), ctx);
	context->setTrxId(getNextTrxId(ctx), ctx);
	context->setSchemaVersion(this->schemaVersion, ctx);
	context->setNodeClusterVersion((long long)1, ctx);
	return context;
}
void LocalCommitIdPublisher::dispose(ThreadContext* ctx) throw() 
{
}
long long LocalCommitIdPublisher::getNextTrxId(ThreadContext* ctx) throw() 
{
	{
		SynchronizedBlockObj __synchronized_2(this->lock, ctx);
		long long trx = this->trxId;
		this->trxId ++ ;
		return trx;
	}
}
}}

