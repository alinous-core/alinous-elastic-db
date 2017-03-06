#include "include/global.h"


#include "alinous.lock/LockObject.h"
#include "alinous.btree/BTreeGlobalCache.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile.declare/AlinousName.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile/Token.h"
#include "alinous.system/AlinousException.h"
#include "alinous.db/AlinousDbException.h"
#include "alinous.runtime.parallel/AlinousThread.h"
#include "alinous.runtime.parallel/ThreadPool.h"
#include "alinous.system/ISystemLog.h"
#include "alinous.system/AlinousCore.h"
#include "alinous.db.table/TableMetadata.h"
#include "alinous.db.table/IDatabaseTable.h"
#include "alinous.db/ITableSchema.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "java.lang/Comparable.h"
#include "alinous.btree/IBTreeKey.h"
#include "alinous.btree/IBTree.h"
#include "alinous.btree/BTree.h"
#include "alinous.btree/IntKey.h"
#include "alinous.db.table/IOidPublisher.h"
#include "alinous.db.trx/DbVersionContext.h"
#include "alinous.db.trx/DbTransactionManager.h"
#include "alinous.db.trx/TrxLockContext.h"
#include "alinous.db.trx/TrxLockManager.h"
#include "alinous.lock.unique/UniqueExclusiveLockManager.h"
#include "alinous.lock.unique/UniqueExclusiveLockClient.h"
#include "alinous.system.config/IAlinousConfigElement.h"
#include "alinous.system.config/AlinousDbInstanceInfo.h"
#include "alinous.db/ICommidIdPublisher.h"
#include "alinous.db/LocalCommitIdPublisher.h"
#include "alinous.remote.db.client.command.data/SchemaData.h"
#include "alinous.db/TableSchema.h"
#include "alinous.db/SchemaManager.h"
#include "alinous.db/ITableRegion.h"
#include "alinous.db/LocalTableRegion.h"
#include "alinous.db/TableSchemaCollection.h"
#include "alinous.db/TableRegionManager.h"
#include "alinous.runtime.dbif/IDatabaseConnection.h"
#include "alinous.db/ConnectInfo.h"
#include "alinous.db/AlinousDbConnection.h"
#include "alinous.db/AlinousDatabase.h"

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
void LocalCommitIdPublisher::__cleanUp(ThreadContext* ctx){
}
}}

