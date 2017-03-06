#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntry.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/IAlinousElementVisitor.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.db.table/DatabaseException.h"
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
#include "alinous.btree.scan/INodeIterator.h"
#include "alinous.buffer.storage/IFileStorage.h"
#include "alinous.buffer.storage/FileStorage.h"
#include "alinous.btree/BTreeNodeLoader.h"
#include "alinous.btree/IBTreeNode.h"
#include "alinous.btree/IBTree.h"
#include "alinous.btree/LongKey.h"
#include "alinous.btree/LongValue.h"
#include "alinous.btree.scan/BTreeScanner.h"
#include "alinous.compile.sql/TableAndSchema.h"
#include "alinous.compile.sql.analyze/ScanTableIdentifier.h"
#include "alinous.db.trx.scan/ScanResultIndexKey.h"
#include "alinous.db.table/IBtreeTableIndex.h"
#include "alinous.db.table/BTreeIndexKey.h"
#include "alinous.db.table.scan/IndexScannerLockRequirement.h"
#include "alinous.compile.sql.analyze/ScanTableColumnIdentifier.h"
#include "alinous.db.table/TableMetadata.h"
#include "alinous.compile.sql.analyze/ScanTableMetadata.h"
#include "alinous.btree/BTree.h"
#include "alinous.runtime.parallel/ThreadPool.h"
#include "alinous.db.table/IDatabaseTable.h"
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
#include "alinous.db.trx.scan/ScanException.h"
#include "alinous.db.trx.cache/TrxRecordCacheIndexScanner.h"
#include "alinous.db.trx.cache/TrxRecordCacheFullScanner.h"
#include "alinous.db.trx.cache/TrxRecordsCacheFactory.h"

namespace alinous {namespace db {namespace trx {namespace cache {





bool TrxRecordCacheIndexScanner::__init_done = __init_static_variables();
bool TrxRecordCacheIndexScanner::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"TrxRecordCacheIndexScanner", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 TrxRecordCacheIndexScanner::TrxRecordCacheIndexScanner(ScanTableIdentifier* tableId, DbTransaction* trx, TrxRecordCacheIndex* trxCacheIndex, TrxRecordsCache* storage, int kindOfCache, ThreadContext* ctx) throw()  : IObject(ctx), ITableTargetScanner(ctx), trxCacheIndex(nullptr), indexBTree(nullptr), storage(nullptr), scanner(nullptr), current(0), values(nullptr), kindOfCache(0), trx(nullptr), tableId(nullptr)
{
	__GC_MV(this, &(this->trx), trx, DbTransaction);
	__GC_MV(this, &(this->trxCacheIndex), trxCacheIndex, TrxRecordCacheIndex);
	__GC_MV(this, &(this->indexBTree), this->trxCacheIndex->getStorage(ctx), IBTree);
	__GC_MV(this, &(this->storage), storage, TrxRecordsCache);
	__GC_MV(this, &(this->scanner), nullptr, BTreeScanner);
	this->kindOfCache = kindOfCache;
	__GC_MV(this, &(this->tableId), tableId, ScanTableIdentifier);
}
void TrxRecordCacheIndexScanner::__construct_impl(ScanTableIdentifier* tableId, DbTransaction* trx, TrxRecordCacheIndex* trxCacheIndex, TrxRecordsCache* storage, int kindOfCache, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->trx), trx, DbTransaction);
	__GC_MV(this, &(this->trxCacheIndex), trxCacheIndex, TrxRecordCacheIndex);
	__GC_MV(this, &(this->indexBTree), this->trxCacheIndex->getStorage(ctx), IBTree);
	__GC_MV(this, &(this->storage), storage, TrxRecordsCache);
	__GC_MV(this, &(this->scanner), nullptr, BTreeScanner);
	this->kindOfCache = kindOfCache;
	__GC_MV(this, &(this->tableId), tableId, ScanTableIdentifier);
}
 TrxRecordCacheIndexScanner::~TrxRecordCacheIndexScanner() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void TrxRecordCacheIndexScanner::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"TrxRecordCacheIndexScanner", L"~TrxRecordCacheIndexScanner");
	__e_obj1.add(this->trxCacheIndex, this);
	trxCacheIndex = nullptr;
	__e_obj1.add(this->indexBTree, this);
	indexBTree = nullptr;
	__e_obj1.add(this->storage, this);
	storage = nullptr;
	__e_obj1.add(this->scanner, this);
	scanner = nullptr;
	__e_obj1.add(this->values, this);
	values = nullptr;
	__e_obj1.add(this->trx, this);
	trx = nullptr;
	__e_obj1.add(this->tableId, this);
	tableId = nullptr;
	if(!prepare){
		return;
	}
}
void TrxRecordCacheIndexScanner::startScan(ScanResultIndexKey* indexKeyValue, ThreadContext* ctx)
{
	{
		try
		{
			__GC_MV(this, &(this->scanner), (new(ctx) BTreeScanner(this->indexBTree, ctx)), BTreeScanner);
			if(indexKeyValue == nullptr)
			{
				this->scanner->startScan(false, ctx);
			}
						else 
			{
				BTreeIndexKey* indexKey = (new(ctx) BTreeIndexKey(indexKeyValue, ctx));
				this->scanner->startScan(indexKey, ctx);
			}
		}
		catch(IOException* e)
		{
			throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1715(), e, ctx));
		}
		catch(InterruptedException* e)
		{
			throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1715(), e, ctx));
		}
		catch(VariableException* e)
		{
			throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1715(), e, ctx));
		}
		catch(BTreeException* e)
		{
			throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1715(), e, ctx));
		}
		catch(AlinousException* e)
		{
			throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1715(), e, ctx));
		}
	}
}
void TrxRecordCacheIndexScanner::endScan(ThreadContext* ctx)
{
	{
		try
		{
			this->scanner->endScan(ctx);
		}
		catch(InterruptedException* e)
		{
			throw (new(ctx) ScanException(ConstStr::getCNST_STR_1716(), e, ctx));
		}
	}
}
bool TrxRecordCacheIndexScanner::hasNext(bool debug, ThreadContext* ctx)
{
	if(this->values != nullptr && this->values->size(ctx) > this->current)
	{
		return true;
	}
	{
		try
		{
			if(!this->scanner->hasNext(ctx))
			{
				return false;
			}
		}
		catch(VariableException* e)
		{
			throw (new(ctx) ScanException(ConstStr::getCNST_STR_1717(), e, ctx));
		}
		catch(InterruptedException* e)
		{
			throw (new(ctx) ScanException(ConstStr::getCNST_STR_1717(), e, ctx));
		}
		catch(IOException* e)
		{
			throw (new(ctx) ScanException(ConstStr::getCNST_STR_1717(), e, ctx));
		}
		catch(BTreeException* e)
		{
			throw (new(ctx) ScanException(ConstStr::getCNST_STR_1717(), e, ctx));
		}
		catch(AlinousException* e)
		{
			throw (new(ctx) ScanException(ConstStr::getCNST_STR_1717(), e, ctx));
		}
	}
	IBTreeNode* leafNode = nullptr;
	{
		try
		{
			leafNode = this->scanner->next(ctx);
		}
		catch(BTreeException* e)
		{
			throw (new(ctx) ScanException(e, ctx));
		}
	}
	GCUtils<ArrayList<IBTreeValue> >::mv(this, &(this->values), leafNode->getValues(ctx), ctx);
	this->current = 0;
	return true;
}
ScanResultRecord* TrxRecordCacheIndexScanner::next(bool debug, ThreadContext* ctx)
{
	LongValue* oidValue = static_cast<LongValue*>(this->values->get(this->current++, ctx));
	{
		try
		{
			return toScanResultRecord(oidValue->value, ctx);
		}
		catch(VariableException* e)
		{
			throw (new(ctx) ScanException(ConstStr::getCNST_STR_1717(), e, ctx));
		}
		catch(IOException* e)
		{
			throw (new(ctx) ScanException(ConstStr::getCNST_STR_1717(), e, ctx));
		}
		catch(InterruptedException* e)
		{
			throw (new(ctx) ScanException(ConstStr::getCNST_STR_1717(), e, ctx));
		}
		catch(BTreeException* e)
		{
			throw (new(ctx) ScanException(ConstStr::getCNST_STR_1717(), e, ctx));
		}
		catch(AlinousException* e)
		{
			throw (new(ctx) ScanException(ConstStr::getCNST_STR_1717(), e, ctx));
		}
	}
}
ArrayList<ScanResultRecord>* TrxRecordCacheIndexScanner::searchByIndexValue(ScanResultIndexKey* indexValue, ThreadContext* ctx)
{
	BTreeIndexKey* indexKey = (new(ctx) BTreeIndexKey(indexValue, ctx));
	ArrayList<ScanResultRecord>* list = (new(ctx) ArrayList<ScanResultRecord>(ctx));
	IBTreeNode* leafNode = nullptr;
	{
		try
		{
			leafNode = this->indexBTree->findByKey(indexKey, ctx);
			ArrayList<IBTreeValue>* values = leafNode->getValues(ctx);
			int maxLoop = values->size(ctx);
			for(int i = 0; i != maxLoop; ++i)
			{
				IBTreeValue* value = values->get(i, ctx);
				LongValue* lvalue = static_cast<LongValue*>(value);
				ScanResultRecord* record = toScanResultRecord(lvalue->value, ctx);
				list->add(record, ctx);
			}
		}
		catch(VariableException* e)
		{
			throw (new(ctx) ScanException(ConstStr::getCNST_STR_1719(), e, ctx));
		}
		catch(IOException* e)
		{
			throw (new(ctx) ScanException(ConstStr::getCNST_STR_1719(), e, ctx));
		}
		catch(InterruptedException* e)
		{
			throw (new(ctx) ScanException(ConstStr::getCNST_STR_1719(), e, ctx));
		}
		catch(BTreeException* e)
		{
			throw (new(ctx) ScanException(ConstStr::getCNST_STR_1719(), e, ctx));
		}
	}
	return list;
}
void TrxRecordCacheIndexScanner::dispose(ISystemLog* logger, ThreadContext* ctx)
{
}
ScanResultRecord* TrxRecordCacheIndexScanner::toScanResultRecord(long long oid, ThreadContext* ctx)
{
	LongKey* oidKey = (new(ctx) LongKey(oid, ctx));
	IBTreeNode* node = this->storage->findByKey(oidKey, ctx);
	ArrayList<IBTreeValue>* values = node->getValues(ctx);
	if(values->size(ctx) == 0)
	{
		throw (new(ctx) ScanException(ConstStr::getCNST_STR_1718(), ctx));
	}
	CachedRecord* record = static_cast<CachedRecord*>(values->get(0, ctx));
	ScanResultRecord* srecord = (new(ctx) ScanResultRecord(this->tableId, this->kindOfCache, record->getOid(ctx), this->trx, record, IndexScannerLockRequirement::NO_LOCK, ctx));
	return srecord;
}
void TrxRecordCacheIndexScanner::__cleanUp(ThreadContext* ctx){
}
}}}}

