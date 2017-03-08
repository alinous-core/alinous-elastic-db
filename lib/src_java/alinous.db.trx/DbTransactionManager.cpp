#include "include/global.h"


#include "alinous.remote.socket/ICommandData.h"
#include "alinous.db.trx/DbVersionContext.h"
#include "alinous.lock/LockObject.h"
#include "alinous.runtime.parallel/ThreadPool.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.db/AlinousDbException.h"
#include "alinous.system/AlinousCore.h"
#include "alinous.system.utils/FileUtils.h"
#include "alinous.db/AlinousDatabase.h"
#include "alinous.db.trx/DbTransaction.h"
#include "alinous.db.trx/DbTransactionFactory.h"
#include "alinous.db.trx/DbTransactionManager.h"

namespace alinous {namespace db {namespace trx {





bool DbTransactionManager::__init_done = __init_static_variables();
bool DbTransactionManager::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DbTransactionManager", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 DbTransactionManager::DbTransactionManager(AlinousDatabase* database, String* trxTmpDir, int maxConnection, AlinousCore* core, ThreadPool* workerThreadsPool, ThreadContext* ctx) throw()  : IObject(ctx), trxTmpDir(nullptr), maxConnection(0), trxCount(0), database(nullptr), lock(__GC_INS(this, (new(ctx) LockObject(ctx)), LockObject)), core(nullptr), trxReady(GCUtils<ArrayList<DbTransaction> >::ins(this, (new(ctx) ArrayList<DbTransaction>(ctx)), ctx, __FILEW__, __LINE__, L"")), workerThreadsPool(nullptr)
{
	__GC_MV(this, &(this->workerThreadsPool), workerThreadsPool, ThreadPool);
	__GC_MV(this, &(this->trxTmpDir), trxTmpDir, String);
	__GC_MV(this, &(this->database), database, AlinousDatabase);
	__GC_MV(this, &(this->core), core, AlinousCore);
	File* file = (new(ctx) File(this->trxTmpDir, ctx));
	if(!file->exists(ctx))
	{
		file->mkdirs(ctx);
	}
		else 
	{
		FileUtils::removeAll(file, ctx);
		file->mkdirs(ctx);
	}
	this->maxConnection = maxConnection;
	this->trxCount = 0;
}
void DbTransactionManager::__construct_impl(AlinousDatabase* database, String* trxTmpDir, int maxConnection, AlinousCore* core, ThreadPool* workerThreadsPool, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->workerThreadsPool), workerThreadsPool, ThreadPool);
	__GC_MV(this, &(this->trxTmpDir), trxTmpDir, String);
	__GC_MV(this, &(this->database), database, AlinousDatabase);
	__GC_MV(this, &(this->core), core, AlinousCore);
	File* file = (new(ctx) File(this->trxTmpDir, ctx));
	if(!file->exists(ctx))
	{
		file->mkdirs(ctx);
	}
		else 
	{
		FileUtils::removeAll(file, ctx);
		file->mkdirs(ctx);
	}
	this->maxConnection = maxConnection;
	this->trxCount = 0;
}
 DbTransactionManager::~DbTransactionManager() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void DbTransactionManager::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"DbTransactionManager", L"~DbTransactionManager");
	__e_obj1.add(this->trxTmpDir, this);
	trxTmpDir = nullptr;
	__e_obj1.add(this->database, this);
	database = nullptr;
	__e_obj1.add(this->lock, this);
	lock = nullptr;
	__e_obj1.add(this->core, this);
	core = nullptr;
	__e_obj1.add(this->trxReady, this);
	trxReady = nullptr;
	__e_obj1.add(this->workerThreadsPool, this);
	workerThreadsPool = nullptr;
	if(!prepare){
		return;
	}
}
DbTransaction* DbTransactionManager::borrowTransaction(int acid, ThreadContext* ctx)
{
	{
		SynchronizedBlockObj __synchronized_2(this->lock, ctx);
		while(this->trxCount > this->maxConnection)
		{
			{
				try
				{
					this->lock->wait(ctx);
				}
				catch(InterruptedException* e)
				{
					e->printStackTrace(ctx);
					throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1713(), e, ctx));
				}
			}
		}
	}
	DbVersionContext* vctx = this->database->newTransactionContext(ctx);
	long long commitId = vctx->getCommitId(ctx);
	long long trxId = vctx->getTrxId(ctx);
	String* tmpDir = this->trxTmpDir->clone(ctx)->append(trxId, ctx)->append(ConstStr::getCNST_STR_1007(), ctx);
	DbTransaction* trx = DbTransactionFactory::newTransaction(acid, this, tmpDir, this->database, this->core, commitId, vctx, ctx);
	{
		SynchronizedBlockObj __synchronized_2(this->lock, ctx);
		this->trxReady->add(trx, ctx);
	}
	return trx;
}
void DbTransactionManager::returnTransaction(DbTransaction* trx, ThreadContext* ctx) throw() 
{
	{
		SynchronizedBlockObj __synchronized_2(this->lock, ctx);
		this->trxReady->remove(trx, ctx);
		this->trxCount -- ;
		if(this->trxCount >= this->maxConnection)
		{
			this->lock->notify(ctx);
		}
	}
}
void DbTransactionManager::dispose(ThreadContext* ctx) throw() 
{
	int maxLoop = this->trxReady->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		DbTransaction* trx = this->trxReady->get(i, ctx);
		trx->dispose(ctx);
	}
	this->trxReady->clear(ctx);
}
ThreadPool* DbTransactionManager::getWorkerThreadsPool(ThreadContext* ctx) throw() 
{
	return workerThreadsPool;
}
void DbTransactionManager::includes(DbTransactionFactory* arg0, ThreadContext* ctx) throw() 
{
}
void DbTransactionManager::__cleanUp(ThreadContext* ctx){
}
}}}

