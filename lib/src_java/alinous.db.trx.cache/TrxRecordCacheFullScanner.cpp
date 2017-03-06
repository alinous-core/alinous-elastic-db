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
#include "alinous.btree.scan/BTreeScanner.h"
#include "alinous.compile.sql/TableAndSchema.h"
#include "alinous.compile.sql.analyze/ScanTableIdentifier.h"
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
#include "alinous.db.trx.scan/ScanException.h"
#include "alinous.db.trx.cache/TrxRecordCacheIndexScanner.h"
#include "alinous.db.trx.cache/TrxRecordCacheFullScanner.h"
#include "alinous.db.trx.cache/TrxRecordsCacheFactory.h"

namespace alinous {namespace db {namespace trx {namespace cache {





bool TrxRecordCacheFullScanner::__init_done = __init_static_variables();
bool TrxRecordCacheFullScanner::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"TrxRecordCacheFullScanner", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 TrxRecordCacheFullScanner::TrxRecordCacheFullScanner(ScanTableMetadata* metadata, BTree* storage, int kindOfCache, DbTransaction* trx, ThreadContext* ctx) throw()  : IObject(ctx), ITableTargetScanner(ctx), storage(nullptr), scanner(nullptr), kindOfCache(0), current(0), values(nullptr), trx(nullptr), metadata(nullptr)
{
	__GC_MV(this, &(this->trx), trx, DbTransaction);
	__GC_MV(this, &(this->storage), storage, BTree);
	__GC_MV(this, &(this->scanner), nullptr, BTreeScanner);
	this->kindOfCache = kindOfCache;
	this->current = 0;
	GCUtils<ArrayList<IBTreeValue> >::mv(this, &(this->values), nullptr, ctx);
	__GC_MV(this, &(this->metadata), metadata, ScanTableMetadata);
}
void TrxRecordCacheFullScanner::__construct_impl(ScanTableMetadata* metadata, BTree* storage, int kindOfCache, DbTransaction* trx, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->trx), trx, DbTransaction);
	__GC_MV(this, &(this->storage), storage, BTree);
	__GC_MV(this, &(this->scanner), nullptr, BTreeScanner);
	this->kindOfCache = kindOfCache;
	this->current = 0;
	GCUtils<ArrayList<IBTreeValue> >::mv(this, &(this->values), nullptr, ctx);
	__GC_MV(this, &(this->metadata), metadata, ScanTableMetadata);
}
 TrxRecordCacheFullScanner::~TrxRecordCacheFullScanner() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void TrxRecordCacheFullScanner::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"TrxRecordCacheFullScanner", L"~TrxRecordCacheFullScanner");
	__e_obj1.add(this->storage, this);
	storage = nullptr;
	__e_obj1.add(this->scanner, this);
	scanner = nullptr;
	__e_obj1.add(this->values, this);
	values = nullptr;
	__e_obj1.add(this->trx, this);
	trx = nullptr;
	__e_obj1.add(this->metadata, this);
	metadata = nullptr;
	if(!prepare){
		return;
	}
}
void TrxRecordCacheFullScanner::startScan(ScanResultIndexKey* indexKeyValue, ThreadContext* ctx)
{
	{
		try
		{
			__GC_MV(this, &(this->scanner), (new(ctx) BTreeScanner(this->storage, ctx)), BTreeScanner);
			if(indexKeyValue == nullptr)
			{
				this->scanner->startScan(false, ctx);
			}
						else 
			{
				LongKey* oidKey = (new(ctx) LongKey(indexKeyValue->get(0, ctx)->getLong(ctx), ctx));
				this->scanner->startScan(oidKey, ctx);
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
void TrxRecordCacheFullScanner::endScan(ThreadContext* ctx)
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
bool TrxRecordCacheFullScanner::hasNext(bool debug, ThreadContext* ctx)
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
ScanResultRecord* TrxRecordCacheFullScanner::next(bool debug, ThreadContext* ctx)
{
	ScanResultRecord* srecord = nullptr;
	CachedRecord* cachedRecord = static_cast<CachedRecord*>(this->values->get(this->current++, ctx));
	{
		try
		{
			srecord = (new(ctx) ScanResultRecord(this->metadata->getFirstTableId(ctx), this->kindOfCache, cachedRecord->getOid(ctx), this->trx, cachedRecord, IndexScannerLockRequirement::NO_LOCK, ctx));
		}
		catch(VariableException* e)
		{
			throw (new(ctx) ScanException(ConstStr::getCNST_STR_1720(), e, ctx));
		}
	}
	return srecord;
}
ArrayList<ScanResultRecord>* TrxRecordCacheFullScanner::searchByIndexValue(ScanResultIndexKey* indexValue, ThreadContext* ctx)
{
	LongKey* oidKey = nullptr;
	if(indexValue != nullptr && indexValue->getNumCols(ctx) != 0)
	{
		VariantValue* vv = indexValue->get(0, ctx);
		{
			try
			{
				oidKey = (new(ctx) LongKey(vv->getLongValue(ctx), ctx));
			}
			catch(VariableException* e)
			{
				throw (new(ctx) ScanException(ConstStr::getCNST_STR_1720(), e, ctx));
			}
		}
	}
	IBTreeNode* leafNode = nullptr;
	{
		try
		{
			leafNode = this->storage->findByKey(oidKey, ctx);
		}
		catch(VariableException* e)
		{
			throw (new(ctx) ScanException(ConstStr::getCNST_STR_1720(), e, ctx));
		}
		catch(IOException* e)
		{
			throw (new(ctx) ScanException(ConstStr::getCNST_STR_1720(), e, ctx));
		}
		catch(InterruptedException* e)
		{
			throw (new(ctx) ScanException(ConstStr::getCNST_STR_1720(), e, ctx));
		}
		catch(BTreeException* e)
		{
			throw (new(ctx) ScanException(ConstStr::getCNST_STR_1720(), e, ctx));
		}
		catch(AlinousException* e)
		{
			throw (new(ctx) ScanException(ConstStr::getCNST_STR_1720(), e, ctx));
		}
	}
	ArrayList<ScanResultRecord>* list = (new(ctx) ArrayList<ScanResultRecord>(ctx));
	ArrayList<IBTreeValue>* values = leafNode->getValues(ctx);
	int maxLoop = values->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IBTreeValue* value = values->get(i, ctx);
		CachedRecord* record = static_cast<CachedRecord*>(value);
		{
			try
			{
				ScanResultRecord* srecord = (new(ctx) ScanResultRecord(this->metadata->getFirstTableId(ctx), this->kindOfCache, record->getOid(ctx), this->trx, record, IndexScannerLockRequirement::NO_LOCK, ctx));
				list->add(srecord, ctx);
			}
			catch(VariableException* e)
			{
				throw (new(ctx) ScanException(ConstStr::getCNST_STR_1720(), e, ctx));
			}
			catch(AlinousException* e)
			{
				throw (new(ctx) ScanException(ConstStr::getCNST_STR_1720(), e, ctx));
			}
		}
	}
	return list;
}
void TrxRecordCacheFullScanner::dispose(ISystemLog* logger, ThreadContext* ctx)
{
}
void TrxRecordCacheFullScanner::__cleanUp(ThreadContext* ctx){
}
}}}}

