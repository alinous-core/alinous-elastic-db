#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.html/IDomObject.h"
#include "alinous.html/DomNode.h"
#include "alinous.system/AlinousException.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.runtime.dom/IDomVariableContainer.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.dom/IDomVariable.h"
#include "alinous.db/AlinousDbException.h"
#include "alinous.runtime.dom.typed/ITypedVariable.h"
#include "alinous.system/AlinousCore.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile.expression/DomVariableDescriptor.h"
#include "alinous.system/AlinousNotSupportedException.h"
#include "alinous.runtime.dom/DomArray.h"
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
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile/Token.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "java.lang/Comparable.h"
#include "alinous.btree/IBTreeKey.h"
#include "alinous.btree/IBTreeNode.h"
#include "alinous.btree/BTreeException.h"
#include "alinous.btree/IBTree.h"
#include "alinous.btree/BTree.h"
#include "alinous.btree/LongKey.h"
#include "alinous.btree.scan/BTreeScanner.h"
#include "alinous.btreememory/BTreeOnMemory.h"
#include "alinous.compile.sql.analyze/ScanTableColumnIdentifier.h"
#include "alinous.db.table/TableColumnMetadata.h"
#include "alinous.db.table/TableMetadataUnique.h"
#include "alinous.compile.sql.analyze/ScanUnique.h"
#include "alinous.compile.sql.analyze/TableMetadataUniqueCollection.h"
#include "alinous.db.table/TableIndexMetadata.h"
#include "alinous.db.table/TableMetadata.h"
#include "alinous.db.trx.cache/CachedRecord.h"
#include "alinous.db.trx.cache/CulumnOrder.h"
#include "alinous.db.trx.scan/ScanResultRecord.h"
#include "alinous.lock.unique/UniqueExclusiveLockClient.h"
#include "alinous.db.trx/DbTransaction.h"
#include "alinous.runtime.parallel/IThreadAction.h"
#include "alinous.runtime.parallel/SequentialBackgroundJob.h"
#include "alinous.db.table/IDatabaseTable.h"
#include "alinous.db.table/IOidPublisher.h"
#include "alinous.db/AlinousDatabase.h"
#include "alinous.db.table/IBtreeTableIndex.h"
#include "alinous.db.trx.cache/TrxRecordCacheIndex.h"
#include "alinous.db.trx.cache/TrxRecordsCache.h"

namespace alinous {namespace db {namespace trx {namespace cache {





constexpr const long long TrxRecordsCache::BLOCK_SIZE;
bool TrxRecordsCache::__init_done = __init_static_variables();
bool TrxRecordsCache::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"TrxRecordsCache", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 TrxRecordsCache::TrxRecordsCache(ThreadContext* ctx) throw()  : IObject(ctx), insert(0), tmpDir(nullptr), schema(nullptr), tableName(nullptr), storagePath(nullptr), storage(nullptr), metadata(nullptr), serial(0), trx(nullptr), indexList(GCUtils<ArrayList<TrxRecordCacheIndex> >::ins(this, (new(ctx) ArrayList<TrxRecordCacheIndex>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
}
void TrxRecordsCache::__construct_impl(ThreadContext* ctx) throw() 
{
}
 TrxRecordsCache::~TrxRecordsCache() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void TrxRecordsCache::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"TrxRecordsCache", L"~TrxRecordsCache");
	__e_obj1.add(this->tmpDir, this);
	tmpDir = nullptr;
	__e_obj1.add(this->schema, this);
	schema = nullptr;
	__e_obj1.add(this->tableName, this);
	tableName = nullptr;
	__e_obj1.add(this->storagePath, this);
	storagePath = nullptr;
	__e_obj1.add(this->storage, this);
	storage = nullptr;
	__e_obj1.add(this->metadata, this);
	metadata = nullptr;
	__e_obj1.add(this->trx, this);
	trx = nullptr;
	__e_obj1.add(this->indexList, this);
	indexList = nullptr;
	if(!prepare){
		return;
	}
}
TrxRecordsCache* TrxRecordsCache::init(String* tmpDir, String* schema, String* tableName, TableMetadata* metadata, DbTransaction* trx, bool insert, ThreadContext* ctx)
{
	this->insert = insert;
	__GC_MV(this, &(this->tmpDir), tmpDir, String);
	__GC_MV(this, &(this->schema), schema, String);
	__GC_MV(this, &(this->tableName), tableName, String);
	__GC_MV(this, &(this->metadata), metadata, TableMetadata);
	__GC_MV(this, &(this->trx), trx, DbTransaction);
	this->serial = 1;
	__GC_MV(this, &(this->storage), (new(ctx) BTreeOnMemory(4, ctx)), IBTree);
	ArrayList<TableIndexMetadata>* indexMetadatas = this->metadata->getIndexes(ctx);
	int maxLoop = indexMetadatas->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		TableIndexMetadata* imeta = indexMetadatas->get(i, ctx);
		String* indexName = imeta->getName(ctx);
		ArrayList<String>* idxCols = imeta->getColumns(ctx);
		{
			try
			{
				createIndex(indexName, idxCols, this->metadata, trx->getDatabase(ctx), ctx);
			}
			catch(VariableException* e)
			{
				throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1715(), ctx));
			}
			catch(InterruptedException* e)
			{
				throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1715(), ctx));
			}
			catch(IOException* e)
			{
				throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1715(), ctx));
			}
			catch(BTreeException* e)
			{
				throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1715(), ctx));
			}
			catch(AlinousException* e)
			{
				throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1715(), ctx));
			}
		}
	}
	return this;
}
void TrxRecordsCache::switchToDisk(AlinousDatabase* database, ThreadContext* ctx)
{
	setStorageFilePath(ctx);
	File* file = (new(ctx) File(this->storagePath, ctx));
	{
		try
		{
			if(file->exists(ctx))
			{
				file->_delete(ctx);
			}
			AlinousCore* core = database->getCore(ctx);
			__GC_MV(this, &(this->storage), (new(ctx) BTree(ctx))->init(file, database->getBtreeCache(ctx), core->diskCache, ctx), IBTree);
			long long capacity = 1024;
			int valueType = 8;
			int keyType = IBTreeKey::TYPE_LONG;
			int nodeCapacity = 8;
			this->storage->initTreeStorage(nodeCapacity, keyType, valueType, capacity, BLOCK_SIZE, ctx);
			this->storage->open(ctx);
		}
		catch(IOException* e)
		{
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1716(), ctx));
		}
		catch(InterruptedException* e)
		{
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1716(), ctx));
		}
		catch(BTreeException* e)
		{
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1716(), ctx));
		}
	}
}
void TrxRecordsCache::dispose(ThreadContext* ctx)
{
	int maxLoop = this->indexList->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		TrxRecordCacheIndex* cacheIndex = this->indexList->get(i, ctx);
		cacheIndex->dispose(ctx);
	}
	this->indexList->clear(ctx);
	{
		try
		{
			this->storage->close(ctx);
		}
		catch(IOException* e)
		{
			throw (new(ctx) AlinousException(ConstStr::getCNST_STR_1717(), e, ctx));
		}
		catch(InterruptedException* e)
		{
			throw (new(ctx) AlinousException(ConstStr::getCNST_STR_1718(), e, ctx));
		}
	}
}
TrxRecordCacheIndex* TrxRecordsCache::getCachedIndex(ArrayList<ScanTableColumnIdentifier>* colIdList, ThreadContext* ctx) throw() 
{
	int maxLoop = this->indexList->size(ctx);
	TrxRecordCacheIndex* retIndex = nullptr;
	for(int i = 0; i != maxLoop; ++i)
	{
		TrxRecordCacheIndex* cachedindex = this->indexList->get(i, ctx);
		bool match = matchIndexByIdList(cachedindex->getColumns(ctx), colIdList, ctx);
		if(colIdList->size(ctx) == cachedindex->getColumns(ctx)->size(ctx) && match)
		{
			return cachedindex;
		}
				else 
		{
			if(match)
			{
				retIndex = cachedindex;
			}
		}
	}
	return retIndex;
}
bool TrxRecordsCache::commitUpdateRecord(AlinousDatabase* db, IDatabaseTable* table, long long newCommitId, ThreadContext* ctx)
{
	table->lockStorage(ctx);
	int slotSize = table->getIndexes(ctx)->size(ctx) + 2;
	IArrayObject<SequentialBackgroundJob>* jobs = ArrayAllocator<SequentialBackgroundJob>::allocate(ctx, slotSize);
	for(int i = 0; i != slotSize; ++i)
	{
		jobs->set((new(ctx) SequentialBackgroundJob(ctx))->init(this->trx->getThreadPool(ctx), ctx),i, ctx);
	}
	BTreeScanner* scanner = nullptr;
	{
		try
		{
			scanner = (new(ctx) BTreeScanner(this->storage, ctx));
			scanner->startScan(false, ctx);
			while(scanner->hasNext(ctx))
			{
				IBTreeNode* lnode = scanner->next(ctx);
				ArrayList<IBTreeValue>* values = lnode->getValues(ctx);
				CachedRecord* record = static_cast<CachedRecord*>(values->get(0, ctx));
				table->updateData(record, newCommitId, jobs, this->trx->getLogger(ctx), ctx);
			}
		}
		catch(Throwable* e)
		{
			for(int i = 0; i != slotSize; ++i)
			{
				jobs->get(i)->joinAndEnd(ctx);
			}
			if(scanner != nullptr)
			{
				scanner->endScan(ctx);
			}
			table->unlockStorage(ctx);
			throw e;
		}
	}
	for(int i = 0; i != slotSize; ++i)
	{
		jobs->get(i)->joinAndEnd(ctx);
	}
	if(scanner != nullptr)
	{
		scanner->endScan(ctx);
	}
	table->unlockStorage(ctx);
	return true;
}
bool TrxRecordsCache::commitInsertRecord(DbTransaction* trx, AlinousDatabase* db, IDatabaseTable* table, long long newCommitId, ThreadContext* ctx)
{
	table->lockStorage(ctx);
	{
		try
		{
			checkInsertUnique(trx, table, ctx);
			int slotSize = table->getIndexes(ctx)->size(ctx) + 2;
			IArrayObject<SequentialBackgroundJob>* jobs = ArrayAllocator<SequentialBackgroundJob>::allocate(ctx, slotSize);
			for(int i = 0; i != slotSize; ++i)
			{
				jobs->set((new(ctx) SequentialBackgroundJob(ctx))->init(this->trx->getThreadPool(ctx), ctx),i, ctx);
			}
			IOidPublisher* oidPublisher = db->getOidPublisher(ctx);
			BTreeScanner* scanner = (new(ctx) BTreeScanner(this->storage, ctx));
			scanner->startScan(false, ctx);
			while(scanner->hasNext(ctx))
			{
				IBTreeNode* lnode = scanner->next(ctx);
				ArrayList<IBTreeValue>* values = lnode->getValues(ctx);
				CachedRecord* record = static_cast<CachedRecord*>(values->get(0, ctx));
				long long oid = oidPublisher->newOid(table->getFullName(ctx), ctx);
				record->setOid(oid, ctx);
				table->insertData(this->trx, record, newCommitId, jobs, this->trx->getLogger(ctx), ctx);
			}
			scanner->endScan(ctx);
			for(int i = 0; i != slotSize; ++i)
			{
				jobs->get(i)->joinAndEnd(ctx);
			}
		}
		catch(Throwable* e)
		{
			table->unlockStorage(ctx);
			throw e;
		}
	}
	table->unlockStorage(ctx);
	return true;
}
CachedRecord* TrxRecordsCache::getRecordByOid(long long oid, ThreadContext* ctx)
{
	LongKey* key = (new(ctx) LongKey(oid, ctx));
	IBTreeNode* node = nullptr;
	{
		try
		{
			node = this->storage->findByKey(key, ctx);
		}
		catch(VariableException* e)
		{
			throw (new(ctx) AlinousException(ConstStr::getCNST_STR_1723(), e, ctx));
		}
		catch(IOException* e)
		{
			throw (new(ctx) AlinousException(ConstStr::getCNST_STR_1724(), e, ctx));
		}
		catch(InterruptedException* e)
		{
			throw (new(ctx) AlinousException(ConstStr::getCNST_STR_1725(), e, ctx));
		}
		catch(BTreeException* e)
		{
			throw (new(ctx) AlinousException(ConstStr::getCNST_STR_1726(), e, ctx));
		}
	}
	if(node == nullptr)
	{
		return nullptr;
	}
	ArrayList<IBTreeValue>* values = node->getValues(ctx);
	if(values->size(ctx) == 0)
	{
		return nullptr;
	}
	return static_cast<CachedRecord*>(values->get(0, ctx));
}
void TrxRecordsCache::insertUpdateRecord(ScanResultRecord* srecord, ThreadContext* ctx)
{
	int maxLoop = srecord->numColumns(ctx);
	int maxIndexes = this->indexList->size(ctx);
	CachedRecord* record = (new(ctx) CachedRecord(this->serial++, maxLoop, ctx));
	for(int i = 0; i != maxLoop; ++i)
	{
		record->set(i, srecord->get(i, ctx), ctx);
	}
	record->setInsertedCommitId(srecord->getInsertedCommitId(ctx), ctx);
	record->setLastUpdateCommitId(srecord->getLastUpdateCommitId(ctx), ctx);
	record->setDeletedCommitId(srecord->getDeletedCommitId(ctx), ctx);
	LongKey* key = (new(ctx) LongKey(srecord->getOid(ctx), ctx));
	{
		try
		{
			this->storage->putKeyValue(key, record, ctx);
		}
		catch(InterruptedException* e)
		{
			throw (new(ctx) AlinousException(ConstStr::getCNST_STR_1727(), e, ctx));
		}
		catch(IOException* e)
		{
			throw (new(ctx) AlinousException(ConstStr::getCNST_STR_1728(), e, ctx));
		}
		catch(BTreeException* e)
		{
			throw (new(ctx) AlinousException(ConstStr::getCNST_STR_1729(), e, ctx));
		}
	}
	for(int i = 0; i != maxIndexes; ++i)
	{
		TrxRecordCacheIndex* cacheIndex = this->indexList->get(i, ctx);
		{
			try
			{
				cacheIndex->addIndexValue(record, record->getOid(ctx), ctx);
			}
			catch(InterruptedException* e)
			{
				throw (new(ctx) AlinousException(ConstStr::getCNST_STR_1730(), e, ctx));
			}
			catch(IOException* e)
			{
				throw (new(ctx) AlinousException(ConstStr::getCNST_STR_1731(), e, ctx));
			}
			catch(BTreeException* e)
			{
				throw (new(ctx) AlinousException(ConstStr::getCNST_STR_1732(), e, ctx));
			}
		}
	}
}
void TrxRecordsCache::insertRecord(ArrayList<IDomVariable>* values, ArrayList<CulumnOrder>* columns, ThreadContext* ctx)
{
	int maxLoop = columns->size(ctx);
	int maxIndexes = this->indexList->size(ctx);
	int maxRecords = values->size(ctx);
	for(int index = 0; index != maxRecords; ++index)
	{
		IDomVariable* domValue = values->get(index, ctx);
		CachedRecord* record = (new(ctx) CachedRecord((this->serial++) * -1, maxLoop, ctx));
		for(int i = 0; i != maxLoop; ++i)
		{
			CulumnOrder* ord = columns->get(i, ctx);
			int columnOrder = this->metadata->getColumnOrder(ord->getColumnName(ctx), ctx);
			ord->setColumnOrder(columnOrder, ctx);
			if(domValue->getVariableClass(ctx) == IDomVariable::TYPE_ARRAY)
			{
				IDomVariable* dom = static_cast<IDomVariable*>((static_cast<DomArray*>(domValue))->get(i, ctx));
				record->setValue(columnOrder, dom->toVariantValue(ctx), ctx);
			}
						else 
			{
				throw (new(ctx) AlinousNotSupportedException(ctx));
			}
		}
		LongKey* key = (new(ctx) LongKey(record->getOid(ctx), ctx));
		{
			try
			{
				this->storage->putKeyValue(key, record, ctx);
			}
			catch(InterruptedException* e)
			{
				throw (new(ctx) AlinousException(ConstStr::getCNST_STR_1727(), e, ctx));
			}
			catch(IOException* e)
			{
				throw (new(ctx) AlinousException(ConstStr::getCNST_STR_1728(), e, ctx));
			}
			catch(BTreeException* e)
			{
				throw (new(ctx) AlinousException(ConstStr::getCNST_STR_1729(), e, ctx));
			}
		}
		for(int i = 0; i != maxIndexes; ++i)
		{
			TrxRecordCacheIndex* cacheIndex = this->indexList->get(i, ctx);
			{
				try
				{
					cacheIndex->addIndexValue(record, record->getOid(ctx), ctx);
				}
				catch(InterruptedException* e)
				{
					throw (new(ctx) AlinousException(ConstStr::getCNST_STR_1730(), e, ctx));
				}
				catch(IOException* e)
				{
					throw (new(ctx) AlinousException(ConstStr::getCNST_STR_1731(), e, ctx));
				}
				catch(BTreeException* e)
				{
					throw (new(ctx) AlinousException(ConstStr::getCNST_STR_1732(), e, ctx));
				}
			}
		}
	}
}
void TrxRecordsCache::createIndex(String* indexName, ArrayList<String>* columns, TableMetadata* tblMetadata, AlinousDatabase* database, ThreadContext* ctx)
{
	TableIndexMetadata* metadata = (new(ctx) TableIndexMetadata(indexName, columns, ctx));
	metadata->setupColumnMetadata(tblMetadata, ctx);
	TrxRecordCacheIndex* newIndex = (new(ctx) TrxRecordCacheIndex(indexName, this->tmpDir, metadata->getMetadata(ctx), ctx));
	newIndex->createIndex(ctx);
	this->indexList->add(newIndex, ctx);
	newIndex->open(database, ctx);
	buildFirstIndex(newIndex, ctx);
}
DbTransaction* TrxRecordsCache::getTrx(ThreadContext* ctx) throw() 
{
	return trx;
}
IBTreeNode* TrxRecordsCache::findByKey(LongKey* oidKey, ThreadContext* ctx)
{
	return this->storage->findByKey(oidKey, ctx);
}
void TrxRecordsCache::setStorageFilePath(ThreadContext* ctx) throw() 
{
	StringBuilder* buff = (new(ctx) StringBuilder(ctx));
	String* postfix = ConstStr::getCNST_STR_1719();
	if(!this->insert)
	{
		postfix = ConstStr::getCNST_STR_1720();
	}
	buff->append(this->tmpDir, ctx)->append(this->schema, ctx)->append(ConstStr::getCNST_STR_1721(), ctx)->append(this->tableName, ctx)->append(postfix, ctx)->append(ConstStr::getCNST_STR_1722(), ctx);
	__GC_MV(this, &(this->storagePath), buff->toString(ctx), String);
}
bool TrxRecordsCache::matchIndexByIdList(ArrayList<TableColumnMetadata>* cachedIndexCols, ArrayList<ScanTableColumnIdentifier>* colIdList, ThreadContext* ctx) throw() 
{
	int maxLoop = colIdList->size(ctx);
	if(maxLoop > cachedIndexCols->size(ctx))
	{
		return false;
	}
	for(int i = 0; i != maxLoop; ++i)
	{
		TableColumnMetadata* indexColMeta = cachedIndexCols->get(i, ctx);
		ScanTableColumnIdentifier* colId = colIdList->get(i, ctx);
		if(!indexColMeta->name->equals(colId->getColumn(ctx), ctx))
		{
			return false;
		}
	}
	return true;
}
void TrxRecordsCache::checkInsertUnique(DbTransaction* trx, IDatabaseTable* table, ThreadContext* ctx)
{
	UniqueExclusiveLockClient* uniqueLock = trx->getUniqueExclusiveLock(ctx);
	TableMetadata* meta = table->getMetadata(ctx);
	TableMetadataUniqueCollection* uniques = meta->getUniques(ctx);
	BTreeScanner* scanner = (new(ctx) BTreeScanner(this->storage, ctx));
	scanner->startScan(false, ctx);
	while(scanner->hasNext(ctx))
	{
		IBTreeNode* lnode = scanner->next(ctx);
		ArrayList<IBTreeValue>* values = lnode->getValues(ctx);
		CachedRecord* record = static_cast<CachedRecord*>(values->get(0, ctx));
		ckeckUniques(uniqueLock, uniques, record, ctx);
	}
}
void TrxRecordsCache::ckeckUniques(UniqueExclusiveLockClient* uniqueLock, TableMetadataUniqueCollection* uniques, CachedRecord* record, ThreadContext* ctx)
{
	ArrayList<ScanUnique>* list = uniques->getUniqueList(ctx);
	int maxLoop = list->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ScanUnique* unique = list->get(i, ctx);
		uniqueLock->lockWithCheck(unique, record, true, ctx);
	}
}
void TrxRecordsCache::buildFirstIndex(TrxRecordCacheIndex* newIndex, ThreadContext* ctx)
{
	BTreeScanner* scanner = (new(ctx) BTreeScanner(this->storage, ctx));
	scanner->startScan(false, ctx);
	while(scanner->hasNext(ctx))
	{
		IBTreeNode* node = scanner->next(ctx);
		CachedRecord* record = getLastCommitedRecord(node, ctx);
		newIndex->addIndexValue(record, record->getOid(ctx), ctx);
	}
}
CachedRecord* TrxRecordsCache::getLastCommitedRecord(IBTreeNode* node, ThreadContext* ctx) throw() 
{
	ArrayList<IBTreeValue>* values = node->getValues(ctx);
	int idx = values->size(ctx) - 1;
	return static_cast<CachedRecord*>(values->get(idx, ctx));
}
void TrxRecordsCache::__cleanUp(ThreadContext* ctx){
}
}}}}

