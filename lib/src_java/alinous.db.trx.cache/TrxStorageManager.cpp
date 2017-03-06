#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/IAlinousElementVisitor.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.html/IDomObject.h"
#include "alinous.html/DomNode.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.runtime.dom/IDomVariableContainer.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.dom/IDomVariable.h"
#include "alinous.system/AlinousException.h"
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
#include "alinous.btree/IBTreeValue.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.runtime.dom/DomVariable.h"
#include "alinous.runtime.dom.typed/BigDecimalVariable.h"
#include "alinous.compile.analyse/SourceValidator.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile/IStatement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.db/AlinousDbException.h"
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
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.db.trx.cache/CachedRecord.h"
#include "alinous.btree/BTreeException.h"
#include "java.lang/Comparable.h"
#include "alinous.btree/IBTreeKey.h"
#include "alinous.btree/IBTree.h"
#include "alinous.btree.scan/BTreeScanner.h"
#include "alinous.compile.sql/TableAndSchema.h"
#include "alinous.compile.sql.analyze/ScanTableIdentifier.h"
#include "alinous.compile.sql.analyze/ScanTableColumnIdentifier.h"
#include "alinous.db.table/TableMetadata.h"
#include "alinous.compile.sql.analyze/ScanTableMetadata.h"
#include "alinous.btree/BTree.h"
#include "alinous.runtime.parallel/ThreadPool.h"
#include "alinous.db.table/IDatabaseTable.h"
#include "alinous.system.utils/FileUtils.h"
#include "alinous.db.trx/DbVersionContext.h"
#include "alinous.db.trx/DbTransactionManager.h"
#include "alinous.db.trx/TrxLockContext.h"
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
#include "alinous.db.trx.scan/ScanResultIndexKey.h"
#include "alinous.db.trx.scan/ITableTargetScanner.h"
#include "alinous.compile.sql.analyze/IndexColumnMatchCondition.h"
#include "alinous.compile.sql.expression.blexp/ISQLBoolExpression.h"
#include "alinous.compile.sql.expression.blexp/AbstractSQLBooleanExpression.h"
#include "alinous.compile.sql.select.join/SQLJoinCondition.h"
#include "alinous.compile.sql.select.join/IJoin.h"
#include "alinous.compile.sql.select.join/IJoinTarget.h"
#include "alinous.compile.sql/AbstractSQLStatement.h"
#include "alinous.compile.sql/CreateIndexStatement.h"
#include "alinous.db.trx.cache/CulumnOrder.h"
#include "alinous.db.table/IBtreeTableIndex.h"
#include "alinous.db.trx.cache/TrxRecordCacheIndex.h"
#include "alinous.db.trx.cache/TrxRecordsCache.h"
#include "alinous.db.trx/CreateIndexMetadata.h"
#include "alinous.db/TableSchema.h"
#include "alinous.db.trx/DbTransaction.h"
#include "alinous.remote.region.client.transaction/AbstractRemoteClientTransaction.h"
#include "alinous.db.trx.cache/TrxStorageManager.h"
#include "alinous.compile.sql/InsertStatement.h"
#include "alinous.compile.sql.result/SelectResultDescription.h"
#include "alinous.compile.sql/SelectStatement.h"
#include "alinous.compile.sql/UpdateSet.h"
#include "alinous.compile.sql/UpdateStatement.h"
#include "alinous.db.trx.ddl/TrxSchemeManager.h"
#include "alinous.db.trx.scan/ScanResultIndex.h"
#include "alinous.db.trx.scan/ScanResult.h"
#include "alinous.db.trx.cache/TrxRecordCacheIndexScanner.h"
#include "alinous.db.trx.cache/TrxRecordCacheFullScanner.h"
#include "alinous.db.trx.cache/TrxRecordsCacheFactory.h"

namespace alinous {namespace db {namespace trx {namespace cache {





bool TrxStorageManager::__init_done = __init_static_variables();
bool TrxStorageManager::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"TrxStorageManager", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 TrxStorageManager::TrxStorageManager(String* tmpDir, DbTransaction* trx, ThreadContext* ctx) throw()  : IObject(ctx), tmpDir(nullptr), hasOperation(0), insertStorages(GCUtils<HashMap<String,HashMap<String,TrxRecordsCache>> >::ins(this, (new(ctx) HashMap<String,HashMap<String,TrxRecordsCache>>(ctx)), ctx, __FILEW__, __LINE__, L"")), updateStorages(GCUtils<HashMap<String,HashMap<String,TrxRecordsCache>> >::ins(this, (new(ctx) HashMap<String,HashMap<String,TrxRecordsCache>>(ctx)), ctx, __FILEW__, __LINE__, L"")), trx(nullptr)
{
	__GC_MV(this, &(this->tmpDir), tmpDir, String);
	__GC_MV(this, &(this->trx), trx, DbTransaction);
	initStorage(ctx);
}
void TrxStorageManager::__construct_impl(String* tmpDir, DbTransaction* trx, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->tmpDir), tmpDir, String);
	__GC_MV(this, &(this->trx), trx, DbTransaction);
	initStorage(ctx);
}
 TrxStorageManager::~TrxStorageManager() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void TrxStorageManager::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"TrxStorageManager", L"~TrxStorageManager");
	__e_obj1.add(this->tmpDir, this);
	tmpDir = nullptr;
	__e_obj1.add(this->insertStorages, this);
	insertStorages = nullptr;
	__e_obj1.add(this->updateStorages, this);
	updateStorages = nullptr;
	__e_obj1.add(this->trx, this);
	trx = nullptr;
	if(!prepare){
		return;
	}
}
TrxRecordsCache* TrxStorageManager::getInsertCache(String* schema, String* table, ThreadContext* ctx)
{
	TableMetadata* metadata = this->trx->getMetadata(schema, table, ctx);
	if(metadata == nullptr)
	{
		throw (new(ctx) AlinousDbException(schema->clone(ctx)->append(ConstStr::getCNST_STR_948(), ctx)->append(table, ctx)->append(ConstStr::getCNST_STR_1045(), ctx), ctx));
	}
	HashMap<String,TrxRecordsCache>* tblcache = this->insertStorages->get(schema, ctx);
	if(tblcache == nullptr)
	{
		return nullptr;
	}
	TrxRecordsCache* cache = tblcache->get(table, ctx);
	return cache;
}
TrxRecordsCache* TrxStorageManager::getUpdateCache(String* schema, String* table, ThreadContext* ctx)
{
	TableMetadata* metadata = this->trx->getMetadata(schema, table, ctx);
	if(metadata == nullptr)
	{
		throw (new(ctx) AlinousDbException(schema->clone(ctx)->append(ConstStr::getCNST_STR_948(), ctx)->append(table, ctx)->append(ConstStr::getCNST_STR_1045(), ctx), ctx));
	}
	HashMap<String,TrxRecordsCache>* tblcache = this->updateStorages->get(schema, ctx);
	if(tblcache == nullptr)
	{
		return nullptr;
	}
	TrxRecordsCache* cache = tblcache->get(table, ctx);
	return cache;
}
TrxRecordsCache* TrxStorageManager::getUpdateCacheWithCreate(String* schema, String* table, ThreadContext* ctx)
{
	TableMetadata* metadata = this->trx->getMetadata(schema, table, ctx);
	if(metadata == nullptr)
	{
		throw (new(ctx) AlinousDbException(schema->clone(ctx)->append(ConstStr::getCNST_STR_948(), ctx)->append(table, ctx)->append(ConstStr::getCNST_STR_1045(), ctx), ctx));
	}
	HashMap<String,TrxRecordsCache>* tblcache = this->updateStorages->get(schema, ctx);
	if(tblcache == nullptr)
	{
		tblcache = (new(ctx) HashMap<String,TrxRecordsCache>(ctx));
		this->updateStorages->put(schema, tblcache, ctx);
		TrxRecordsCache* cache = TrxRecordsCacheFactory::createCache(this->tmpDir, schema, table, metadata, this->trx, false, ctx);
		tblcache->put(table, cache, ctx);
		return cache;
	}
	TrxRecordsCache* cache = tblcache->get(table, ctx);
	if(cache == nullptr)
	{
		cache = (new(ctx) TrxRecordsCache(ctx))->init(this->tmpDir, schema, table, metadata, this->trx, false, ctx);
		tblcache->put(table, cache, ctx);
	}
	return cache;
}
TrxRecordsCache* TrxStorageManager::getInsertCacheWithCreate(String* schema, String* table, ThreadContext* ctx)
{
	TableMetadata* metadata = this->trx->getMetadata(schema, table, ctx);
	if(metadata == nullptr)
	{
		throw (new(ctx) AlinousDbException(schema->clone(ctx)->append(ConstStr::getCNST_STR_948(), ctx)->append(table, ctx)->append(ConstStr::getCNST_STR_1045(), ctx), ctx));
	}
	this->hasOperation = true;
	HashMap<String,TrxRecordsCache>* tblcache = this->insertStorages->get(schema, ctx);
	if(tblcache == nullptr)
	{
		tblcache = (new(ctx) HashMap<String,TrxRecordsCache>(ctx));
		this->insertStorages->put(schema, tblcache, ctx);
		TrxRecordsCache* cache = TrxRecordsCacheFactory::createCache(this->tmpDir, schema, table, metadata, this->trx, true, ctx);
		tblcache->put(table, cache, ctx);
		return cache;
	}
	TrxRecordsCache* cache = tblcache->get(table, ctx);
	if(cache == nullptr)
	{
		cache = (new(ctx) TrxRecordsCache(ctx))->init(this->tmpDir, schema, table, metadata, this->trx, true, ctx);
		tblcache->put(table, cache, ctx);
	}
	return cache;
}
void TrxStorageManager::commitRemote(AbstractRemoteClientTransaction* trx, long long newCommitId, ThreadContext* ctx)
{
	AlinousDatabase* db = this->trx->getDatabase(ctx);
	HashMap<String,IDatabaseTable>* tables = (new(ctx) HashMap<String,IDatabaseTable>(ctx));
	commitRemoteInsert(db, newCommitId, tables, ctx);
	commitRemoteUpdate(db, newCommitId, tables, ctx);
	commitRemoteDelete(db, newCommitId, tables, ctx);
	tpcCommitAll(trx, tables, newCommitId, ctx);
}
void TrxStorageManager::commitLocal(long long newCommitId, ThreadContext* ctx)
{
	AlinousDatabase* db = this->trx->getDatabase(ctx);
	commitInsertLocal(newCommitId, db, ctx);
	Iterator<String>* scit = this->updateStorages->keySet(ctx)->iterator(ctx);
	while(scit->hasNext(ctx))
	{
		String* sckey = scit->next(ctx);
		TableSchemaCollection* schema = db->getSchema(sckey, ctx);
		HashMap<String,TrxRecordsCache>* cacheMap = this->updateStorages->get(sckey, ctx);
		Iterator<String>* it = cacheMap->keySet(ctx)->iterator(ctx);
		while(it->hasNext(ctx))
		{
			String* key = it->next(ctx);
			TrxRecordsCache* cache = cacheMap->get(key, ctx);
			IDatabaseTable* table = schema->getTableStore(key, ctx);
			cache->commitUpdateRecord(db, table, newCommitId, ctx);
		}
	}
}
bool TrxStorageManager::isHasOperation(ThreadContext* ctx) throw() 
{
	return hasOperation;
}
void TrxStorageManager::setHasOperation(bool hasOperation, ThreadContext* ctx) throw() 
{
	this->hasOperation = hasOperation;
}
void TrxStorageManager::reset(ThreadContext* ctx) throw() 
{
	Iterator<String>* scit = this->insertStorages->keySet(ctx)->iterator(ctx);
	while(scit->hasNext(ctx))
	{
		String* sckey = scit->next(ctx);
		HashMap<String,TrxRecordsCache>* cacheMap = this->insertStorages->get(sckey, ctx);
		Iterator<String>* it = cacheMap->keySet(ctx)->iterator(ctx);
		while(it->hasNext(ctx))
		{
			String* key = it->next(ctx);
			TrxRecordsCache* cache = cacheMap->get(key, ctx);
			{
				try
				{
					cache->dispose(ctx);
				}
				catch(AlinousException* e)
				{
					ISystemLog* log = this->trx->getLogger(ctx);
					log->logError(e, ctx);
				}
			}
		}
		cacheMap->clear(ctx);
	}
	this->insertStorages->clear(ctx);
	this->hasOperation = false;
}
void TrxStorageManager::dispose(ThreadContext* ctx) throw() 
{
	reset(ctx);
}
void TrxStorageManager::addIndex(CreateIndexMetadata* createMeta, TableMetadata* tblmetadata, AlinousDatabase* database, ThreadContext* ctx)
{
	TableAndSchema* tableAndSchema = createMeta->getTas(ctx);
	TrxRecordsCache* cache = getInsertCacheWithCreate(tableAndSchema->getSchema(ctx), tableAndSchema->getTable(ctx), ctx);
	if(cache != nullptr)
	{
		{
			try
			{
				cache->createIndex(createMeta->getindexName(ctx), createMeta->getColumns(ctx), tblmetadata, database, ctx);
			}
			catch(InterruptedException* e)
			{
				throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1721(), e, ctx));
			}
			catch(VariableException* e)
			{
				throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1722(), e, ctx));
			}
			catch(AlinousException* e)
			{
				throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1723(), e, ctx));
			}
		}
	}
}
void TrxStorageManager::initStorage(ThreadContext* ctx) throw() 
{
	File* file = (new(ctx) File(this->tmpDir, ctx));
	if(file->exists(ctx))
	{
		FileUtils::removeAll(file, ctx);
	}
	file->mkdirs(ctx);
}
void TrxStorageManager::tpcCommitAll(AbstractRemoteClientTransaction* trx, HashMap<String,IDatabaseTable>* tables, long long newCommitId, ThreadContext* ctx)
{
	Iterator<String>* it = tables->keySet(ctx)->iterator(ctx);
	while(it->hasNext(ctx))
	{
		String* key = it->next(ctx);
		IDatabaseTable* table = tables->get(key, ctx);
		table->finishCommitSession(trx, newCommitId, ctx);
	}
}
void TrxStorageManager::commitRemoteInsert(AlinousDatabase* db, long long newCommitId, HashMap<String,IDatabaseTable>* tables, ThreadContext* ctx)
{
	Iterator<String>* scit = this->insertStorages->keySet(ctx)->iterator(ctx);
	while(scit->hasNext(ctx))
	{
		String* sckey = scit->next(ctx);
		TableSchemaCollection* schema = db->getSchema(sckey, ctx);
		HashMap<String,TrxRecordsCache>* cacheMap = this->insertStorages->get(sckey, ctx);
		Iterator<String>* it = cacheMap->keySet(ctx)->iterator(ctx);
		while(it->hasNext(ctx))
		{
			String* key = it->next(ctx);
			TrxRecordsCache* cache = cacheMap->get(key, ctx);
			IDatabaseTable* table = schema->getTableStore(key, ctx);
			bool updated = cache->commitInsertRecord(this->trx, db, table, newCommitId, ctx);
			if(updated)
			{
				String* fullName = table->getFullName(ctx);
				IDatabaseTable* oldtable = tables->get(fullName, ctx);
				if(oldtable == nullptr)
				{
					tables->put(fullName, table, ctx);
				}
			}
		}
	}
}
void TrxStorageManager::commitRemoteUpdate(AlinousDatabase* db, long long newCommitId, HashMap<String,IDatabaseTable>* tables, ThreadContext* ctx)
{
	Iterator<String>* scit = this->updateStorages->keySet(ctx)->iterator(ctx);
	while(scit->hasNext(ctx))
	{
		String* sckey = scit->next(ctx);
		TableSchemaCollection* schema = db->getSchema(sckey, ctx);
		HashMap<String,TrxRecordsCache>* cacheMap = this->updateStorages->get(sckey, ctx);
		Iterator<String>* it = cacheMap->keySet(ctx)->iterator(ctx);
		while(it->hasNext(ctx))
		{
			String* key = it->next(ctx);
			TrxRecordsCache* cache = cacheMap->get(key, ctx);
			IDatabaseTable* table = schema->getTableStore(key, ctx);
			bool updated = cache->commitUpdateRecord(db, table, newCommitId, ctx);
			if(updated)
			{
				String* fullName = table->getFullName(ctx);
				IDatabaseTable* oldtable = tables->get(fullName, ctx);
				if(oldtable == nullptr)
				{
					tables->put(fullName, table, ctx);
				}
			}
		}
	}
}
void TrxStorageManager::commitRemoteDelete(AlinousDatabase* db, long long newCommitId, HashMap<String,IDatabaseTable>* tables, ThreadContext* ctx) throw() 
{
}
void TrxStorageManager::commitInsertLocal(long long newCommitId, AlinousDatabase* db, ThreadContext* ctx)
{
	Iterator<String>* scit = this->insertStorages->keySet(ctx)->iterator(ctx);
	while(scit->hasNext(ctx))
	{
		String* sckey = scit->next(ctx);
		TableSchemaCollection* schema = db->getSchema(sckey, ctx);
		HashMap<String,TrxRecordsCache>* cacheMap = this->insertStorages->get(sckey, ctx);
		Iterator<String>* it = cacheMap->keySet(ctx)->iterator(ctx);
		while(it->hasNext(ctx))
		{
			String* key = it->next(ctx);
			TrxRecordsCache* cache = cacheMap->get(key, ctx);
			IDatabaseTable* table = schema->getTableStore(key, ctx);
			cache->commitInsertRecord(this->trx, db, table, newCommitId, ctx);
		}
	}
}
void TrxStorageManager::__cleanUp(ThreadContext* ctx){
}
}}}}

