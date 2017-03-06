#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntry.h"
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
#include "alinous.system/AlinousException.h"
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
#include "alinous.db.trx.cache/CachedRecord.h"
#include "alinous.btree/BTreeException.h"
#include "java.lang/Comparable.h"
#include "alinous.btree/IBTreeKey.h"
#include "alinous.btree/IBTreeNode.h"
#include "alinous.btree/IBTree.h"
#include "alinous.btree/LongValue.h"
#include "alinous.btree.scan/BTreeScanner.h"
#include "alinous.compile.sql/TableAndSchema.h"
#include "alinous.compile.sql.analyze/ScanTableIdentifier.h"
#include "alinous.db.trx.scan/ScanResultIndexKey.h"
#include "alinous.btree/BTree.h"
#include "alinous.compile.sql.analyze/ScanTableColumnIdentifier.h"
#include "alinous.compile.sql/ISqlStatement.h"
#include "alinous.db.table/TableMetadata.h"
#include "alinous.compile.sql.analyze/ScanTableMetadata.h"
#include "alinous.db.trx/TrxLockContext.h"
#include "alinous.db.trx.scan/ScanResultRecord.h"
#include "alinous.compile.sql.expression/ISQLExpression.h"
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
#include "alinous.db.trx/DbVersionContext.h"
#include "alinous.db.trx.cache/CulumnOrder.h"
#include "alinous.btreememory/AbstractMemoryNode.h"
#include "alinous.btreememory/MBTreeLeafNode.h"
#include "alinous.btreememory/MemoryBTreeMachine.h"
#include "alinous.btreememory/BTreeOnMemory.h"
#include "alinous.lock.unique/UniqueExclusiveLockClient.h"
#include "alinous.db.table/IBtreeTableIndex.h"
#include "alinous.db.trx.cache/TrxRecordCacheIndex.h"
#include "alinous.db.trx.cache/TrxRecordsCache.h"
#include "alinous.db/ITableSchema.h"
#include "alinous.db/TableSchemaCollection.h"
#include "alinous.db.trx/CreateIndexMetadata.h"
#include "alinous.runtime.parallel/ThreadPool.h"
#include "alinous.db/TableSchema.h"
#include "alinous.db.trx/DbTransactionManager.h"
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
#include "alinous.db.table/IDatabaseTable.h"
#include "alinous.db/AlinousDatabase.h"
#include "alinous.compile.sql.analyze/SQLAnalyseContext.h"
#include "alinous.compile.sql.ddl/CheckDefinition.h"
#include "alinous.db.table/TableColumnMetadata.h"
#include "alinous.db.table/BTreeIndexKey.h"
#include "alinous.db.trx.cache/TrxRecordCacheIndexScanner.h"
#include "alinous.db.trx.cache/TrxRecordCacheFullScanner.h"
#include "alinous.db.trx.cache/TrxRecordsCacheFactory.h"

namespace alinous {namespace db {namespace trx {namespace cache {





constexpr const int TrxRecordCacheIndex::capacity;
constexpr const int TrxRecordCacheIndex::BLOCK_SIZE;
constexpr const int TrxRecordCacheIndex::maxCache;
bool TrxRecordCacheIndex::__init_done = __init_static_variables();
bool TrxRecordCacheIndex::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"TrxRecordCacheIndex", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 TrxRecordCacheIndex::TrxRecordCacheIndex(String* name, String* baseDir, ArrayList<TableColumnMetadata>* metadata, ThreadContext* ctx) throw()  : IObject(ctx), IBtreeTableIndex(ctx), name(nullptr), baseDir(nullptr), columns(GCUtils<ArrayList<TableColumnMetadata> >::ins(this, (new(ctx) ArrayList<TableColumnMetadata>(ctx)), ctx, __FILEW__, __LINE__, L"")), filePath(nullptr), storage(nullptr)
{
	__GC_MV(this, &(this->name), name, String);
	__GC_MV(this, &(this->baseDir), baseDir, String);
	GCUtils<ArrayList<TableColumnMetadata> >::mv(this, &(this->columns), metadata, ctx);
	setPath(ctx);
}
void TrxRecordCacheIndex::__construct_impl(String* name, String* baseDir, ArrayList<TableColumnMetadata>* metadata, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->name), name, String);
	__GC_MV(this, &(this->baseDir), baseDir, String);
	GCUtils<ArrayList<TableColumnMetadata> >::mv(this, &(this->columns), metadata, ctx);
	setPath(ctx);
}
 TrxRecordCacheIndex::~TrxRecordCacheIndex() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void TrxRecordCacheIndex::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"TrxRecordCacheIndex", L"~TrxRecordCacheIndex");
	__e_obj1.add(this->name, this);
	name = nullptr;
	__e_obj1.add(this->baseDir, this);
	baseDir = nullptr;
	__e_obj1.add(this->columns, this);
	columns = nullptr;
	__e_obj1.add(this->filePath, this);
	filePath = nullptr;
	__e_obj1.add(this->storage, this);
	storage = nullptr;
	if(!prepare){
		return;
	}
}
void TrxRecordCacheIndex::createIndex(ThreadContext* ctx)
{
	__GC_MV(this, &(this->storage), (new(ctx) BTreeOnMemory(4, ctx)), IBTree);
}
void TrxRecordCacheIndex::switchToDisk(AlinousDatabase* database, ThreadContext* ctx)
{
	File* file = (new(ctx) File(this->filePath, ctx));
	if(file->exists(ctx))
	{
		file->_delete(ctx);
	}
	{
		try
		{
			AlinousCore* core = database->getCore(ctx);
			__GC_MV(this, &(this->storage), (new(ctx) BTree(ctx))->init(file, database->getBtreeCache(ctx), core->diskCache, ctx), IBTree);
			this->storage->initTreeStorage(32, IBTreeValue::TYPE_LONG, IBTreeValue::TYPE_LONG, (long long)capacity, (long long)64, ctx);
		}
		catch(IOException* e)
		{
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1701(), e, ctx));
		}
		catch(InterruptedException* e)
		{
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1701(), e, ctx));
		}
		catch(BTreeException* e)
		{
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1701(), e, ctx));
		}
	}
}
bool TrxRecordCacheIndex::isOpened(ThreadContext* ctx) throw() 
{
	return this->storage->isOpened(ctx);
}
void TrxRecordCacheIndex::addIndexValue(IDatabaseRecord* record, long long oid, ThreadContext* ctx)
{
	BTreeIndexKey* indexKey = (new(ctx) BTreeIndexKey(this, record, ctx));
	LongValue* oidValue = (new(ctx) LongValue(oid, ctx));
	this->storage->putKeyValue(indexKey, oidValue, ctx);
}
void TrxRecordCacheIndex::open(AlinousDatabase* database, ThreadContext* ctx)
{
	if(this->storage == nullptr)
	{
		File* file = (new(ctx) File(this->filePath, ctx));
		__GC_MV(this, &(this->storage), (new(ctx) BTree(ctx))->init(file, database->getBtreeCache(ctx), database->getCore(ctx)->diskCache, ctx), IBTree);
	}
	if(!this->storage->isOpened(ctx))
	{
		this->storage->open(ctx);
	}
}
void TrxRecordCacheIndex::close(ThreadContext* ctx)
{
	if(this->storage != nullptr && this->storage->isOpened(ctx))
	{
		this->storage->close(ctx);
	}
}
void TrxRecordCacheIndex::dispose(ThreadContext* ctx) throw() 
{
	{
		try
		{
			close(ctx);
		}
		catch(IOException* e)
		{
		}
		catch(InterruptedException* e)
		{
		}
	}
	File* file = (new(ctx) File(this->filePath, ctx));
	if(file->exists(ctx))
	{
		file->_delete(ctx);
	}
}
ArrayList<TableColumnMetadata>* TrxRecordCacheIndex::getColumns(ThreadContext* ctx) throw() 
{
	return this->columns;
}
IBTree* TrxRecordCacheIndex::getStorage(ThreadContext* ctx) throw() 
{
	return storage;
}
void TrxRecordCacheIndex::setPath(ThreadContext* ctx) throw() 
{
	StringBuilder* buff = (new(ctx) StringBuilder(ctx));
	buff->append(this->baseDir, ctx)->append(name, ctx)->append(ConstStr::getCNST_STR_1702(), ctx);
	__GC_MV(this, &(this->filePath), buff->toString(ctx), String);
}
void TrxRecordCacheIndex::__cleanUp(ThreadContext* ctx){
}
}}}}

