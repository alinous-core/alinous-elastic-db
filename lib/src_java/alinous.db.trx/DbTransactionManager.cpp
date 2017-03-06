#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile.sql/TableAndSchema.h"
#include "alinous.compile.sql.analyze/ScanTableIdentifier.h"
#include "alinous.compile.sql.analyze/ScanTableColumnIdentifier.h"
#include "alinous.compile/IAlinousElementVisitor.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.html/IDomObject.h"
#include "alinous.html/DomNode.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.runtime.dom/IDomVariableContainer.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.dom/IDomVariable.h"
#include "alinous.runtime.dom/DomArray.h"
#include "alinous.runtime.dom.typed/ITypedVariable.h"
#include "alinous.runtime.dom.typed/ITypedCaller.h"
#include "alinous.runtime.dom.typed/AbstractTypedVariable.h"
#include "alinous.runtime.dom.typed/TypedVariableArray.h"
#include "alinous.runtime.dom.typed/TimestampVariable.h"
#include "alinous.runtime.dom.typed/TimeVariable.h"
#include "alinous.runtime.dom.typed/ShortVariable.h"
#include "alinous.runtime.dom.typed/LongVariable.h"
#include "alinous.runtime.dom.typed/IntegerVariable.h"
#include "alinous.runtime.dom.typed/FloatVariable.h"
#include "alinous.runtime.dom.typed/DoubleVariable.h"
#include "alinous.runtime.dom.typed/CharVariable.h"
#include "alinous.runtime.dom.typed/ByteVariable.h"
#include "alinous.runtime.dom.typed/StringVariable.h"
#include "alinous.runtime.dom.typed/BoolVariable.h"
#include "alinous.runtime.variant/VariantValue.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.runtime.dom/DomVariable.h"
#include "alinous.runtime.dom.typed/BigDecimalVariable.h"
#include "alinous.compile.analyse/SourceValidator.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile/IStatement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.system/ISystemLog.h"
#include "alinous.system/AlinousCore.h"
#include "alinous.runtime.dom/DomVariableContainer.h"
#include "alinous.runtime.dom.typed/TypedVariableContainer.h"
#include "alinous.runtime.engine/IStackFrame.h"
#include "alinous.runtime.engine/AbstractStackFrame.h"
#include "alinous.runtime.engine/SubStackFrame.h"
#include "alinous.runtime.engine/MainStackFrame.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.compile.expression/DomVariableDescriptor.h"
#include "alinous.compile.declare/AlinousName.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile/Token.h"
#include "alinous.system/AlinousException.h"
#include "alinous.db/AlinousDbException.h"
#include "alinous.btree/IBTree.h"
#include "alinous.btree.scan/BTreeScanner.h"
#include "alinous.db.table/TableMetadata.h"
#include "alinous.compile.sql.analyze/ScanTableMetadata.h"
#include "alinous.lock/LockObject.h"
#include "alinous.runtime.parallel/ThreadPool.h"
#include "alinous.system.utils/FileUtils.h"
#include "alinous.db.trx/DbVersionContext.h"
#include "alinous.db.trx/DbTransactionManager.h"
#include "alinous.lock.unique/UniqueExclusiveLockClient.h"
#include "alinous.db/ITableSchema.h"
#include "alinous.db/TableSchemaCollection.h"
#include "alinous.db/AlinousDatabase.h"
#include "alinous.db.trx.scan/ScanResultRecord.h"
#include "alinous.compile.sql.expression/ISQLExpression.h"
#include "alinous.compile.sql.analyze/SQLAnalyseContext.h"
#include "alinous.compile.sql/ISqlStatement.h"
#include "alinous.compile.sql.select/SQLGroupBy.h"
#include "alinous.compile.sql.select/SQLLimitOffset.h"
#include "alinous.compile.sql.select/SQLWhere.h"
#include "alinous.db.trx.scan/ITableTargetScanner.h"
#include "alinous.compile.sql.analyze/IndexColumnMatchCondition.h"
#include "alinous.compile.sql.expression.blexp/ISQLBoolExpression.h"
#include "alinous.compile.sql.expression.blexp/AbstractSQLBooleanExpression.h"
#include "alinous.compile.sql.select.join/SQLJoinCondition.h"
#include "alinous.compile.sql.select.join/IJoin.h"
#include "alinous.compile.sql.select.join/IJoinTarget.h"
#include "alinous.compile.sql/AbstractSQLStatement.h"
#include "alinous.compile.sql/CreateIndexStatement.h"
#include "alinous.db.trx.cache/CachedRecord.h"
#include "alinous.db.trx.cache/TrxRecordsCache.h"
#include "alinous.db.trx/CreateIndexMetadata.h"
#include "alinous.db.trx.cache/TrxStorageManager.h"
#include "alinous.compile.sql/InsertStatement.h"
#include "alinous.compile.sql.result/SelectResultDescription.h"
#include "alinous.compile.sql/SelectStatement.h"
#include "alinous.compile.sql/UpdateSet.h"
#include "alinous.compile.sql/UpdateStatement.h"
#include "alinous.db/TableSchema.h"
#include "alinous.db.trx.ddl/TrxSchemeManager.h"
#include "alinous.db.trx.scan/ScanResultIndex.h"
#include "alinous.db.trx.scan/ScanResult.h"
#include "alinous.db.trx/DbTransaction.h"
#include "alinous.db.table/IDatabaseTable.h"
#include "alinous.db.trx/TrxLockContext.h"
#include "alinous.db.trx/TrxLockManager.h"
#include "alinous.db.trx/ReadCommittedTransaction.h"
#include "alinous.db.trx/RepeatableReadTransaction.h"
#include "alinous.db.trx/SerializableTransaction.h"
#include "alinous.db.trx/DbTransactionFactory.h"

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
void DbTransactionManager::__cleanUp(ThreadContext* ctx){
}
}}}

