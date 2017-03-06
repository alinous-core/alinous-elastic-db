#include "include/global.h"


#include "alinous.db.table/DatabaseException.h"
#include "alinous.db.trx.scan/ScanException.h"
#include "alinous.lock/LockObject.h"
#include "alinous.lock/ConcurrentGate.h"
#include "alinous.buffer.storage/FileStorageEntry.h"
#include "alinous.buffer.storage/IFileStorage.h"
#include "alinous.buffer.storage/FileStorage.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.sql.functions/SQLFunctionManager.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.html/IDomObject.h"
#include "alinous.html/DomNode.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.runtime.dom/IDomVariableContainer.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.dom/IDomVariable.h"
#include "alinous.runtime.dom.typed/ITypedVariable.h"
#include "alinous.btree/BTreeException.h"
#include "alinous.buffer/FifoElement.h"
#include "java.lang/Comparable.h"
#include "alinous.btree/IBTreeKey.h"
#include "alinous.btree/IBTreeNode.h"
#include "alinous.btree/AbstractNode.h"
#include "alinous.btree/BTreeLeafNode.h"
#include "alinous.btree/BTreeNodeLoader.h"
#include "alinous.btree/BTreeGlobalCache.h"
#include "alinous.system/ISystemLog.h"
#include "alinous.remote.db/RemoteTableStorageServer.h"
#include "alinous.remote.monitor/TransactionMonitorServer.h"
#include "alinous.remote.region/NodeRegionServer.h"
#include "alinous.system.config/AlinousConfig.h"
#include "alinous.runtime/AlinousModuleRepository.h"
#include "alinous.runtime.dbif/DataSourceManager.h"
#include "alinous.runtime.engine.debugger/AlinousScriptDebugger.h"
#include "alinous.runtime.engine/ScriptRunner.h"
#include "alinous.server.webmodule/WebModuleManager.h"
#include "alinous.system/AlinousCoreLogger.h"
#include "alinous.system/AlinousCore.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile.expression/DomVariableDescriptor.h"
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
#include "alinous.system.functions/AlinousFunctionManager.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile/Token.h"
#include "alinous.system/AlinousException.h"
#include "alinous.btree/IBTree.h"
#include "alinous.btree/BTree.h"
#include "alinous.btree/LongKey.h"
#include "alinous.btreememory/AbstractMemoryNode.h"
#include "alinous.btreememory/MBTreeLeafNode.h"
#include "alinous.btreememory/MemoryBTreeMachine.h"
#include "alinous.btreememory/BTreeOnMemory.h"
#include "alinous.compile.sql/TableAndSchema.h"
#include "alinous.compile.sql.analyze/ScanTableIdentifier.h"
#include "alinous.compile.sql.analyze/ScanTableColumnIdentifier.h"
#include "alinous.compile.sql.analyze/ScanTableMetadata.h"
#include "alinous.btree.scan/BTreeScanner.h"
#include "alinous.db.trx.scan/ScanResultIndexKey.h"
#include "alinous.db.table.scan/IndexScannerLockRequirement.h"
#include "alinous.db.trx/TrxLockContext.h"
#include "java.lang/Number.h"
#include "java.lang/Integer.h"
#include "alinous.db.trx.scan/PadddingRecord.h"
#include "alinous.db.trx.scan/ScanResultRecord.h"
#include "alinous.db.trx.scan/ITableTargetScanner.h"
#include "alinous.db.table/DatatableConstants.h"
#include "alinous.db.trx.scan/ScanResultIndex.h"
#include "alinous.db.trx/DbTransaction.h"
#include "alinous.db.table/IDatabaseTable.h"
#include "alinous.db/AlinousDatabase.h"
#include "alinous.db.table/DatabaseRecord.h"
#include "alinous.db.trx.scan/ScanResult.h"
#include "alinous.db.trx.scan/IFilterScanner.h"
#include "alinous.db.trx.scan/GroupedScanResultRecord.h"
#include "alinous.db.trx.scan/ScannedResultIndexScanner.h"
#include "alinous.db.trx.scan/JoinedRecords.h"
#include "alinous.db.trx.scan/ScannedOids.h"
#include "alinous.db.trx.scan/ScanResultScanner.h"

namespace alinous {namespace db {namespace trx {namespace scan {





bool ScanResult::__init_done = __init_static_variables();
bool ScanResult::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ScanResult", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ScanResult::ScanResult(ScanTableMetadata* metadata, String* trxDir, int serial, TrxLockContext* lockContext, ThreadContext* ctx) : IObject(ctx), store(nullptr), serial(0), storagePath(nullptr), trxDir(nullptr), indexes(GCUtils<ArrayList<ScanResultIndex> >::ins(this, (new(ctx) ArrayList<ScanResultIndex>(ctx)), ctx, __FILEW__, __LINE__, L"")), metadata(nullptr)
{
	this->serial = serial;
	__GC_MV(this, &(this->metadata), metadata, ScanTableMetadata);
	__GC_MV(this, &(this->trxDir), trxDir, String);
	__GC_MV(this, &(this->store), (new(ctx) BTreeOnMemory(4, ctx)), IBTree);
}
void ScanResult::__construct_impl(ScanTableMetadata* metadata, String* trxDir, int serial, TrxLockContext* lockContext, ThreadContext* ctx)
{
	this->serial = serial;
	__GC_MV(this, &(this->metadata), metadata, ScanTableMetadata);
	__GC_MV(this, &(this->trxDir), trxDir, String);
	__GC_MV(this, &(this->store), (new(ctx) BTreeOnMemory(4, ctx)), IBTree);
}
 ScanResult::~ScanResult() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ScanResult::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ScanResult", L"~ScanResult");
	__e_obj1.add(this->store, this);
	store = nullptr;
	__e_obj1.add(this->storagePath, this);
	storagePath = nullptr;
	__e_obj1.add(this->trxDir, this);
	trxDir = nullptr;
	__e_obj1.add(this->indexes, this);
	indexes = nullptr;
	__e_obj1.add(this->metadata, this);
	metadata = nullptr;
	if(!prepare){
		return;
	}
}
void ScanResult::switchToDisk(AlinousDatabase* database, ThreadContext* ctx)
{
	{
		try
		{
			__GC_MV(this, &(this->storagePath), getOidIndexName(ctx), String);
			File* file = (new(ctx) File(this->storagePath, ctx));
			if(file->exists(ctx))
			{
				file->_delete(ctx);
			}
			AlinousCore* core = database->getCore(ctx);
			__GC_MV(this, &(this->store), (new(ctx) BTree(ctx))->init((new(ctx) File(this->storagePath, ctx)), database->getBtreeCache(ctx), core->diskCache, ctx), IBTree);
			this->store->initTreeStorage(32, IBTreeValue::TYPE_LONG, IBTreeValue::TYPE_LONG, (long long)DatatableConstants::capacity, (long long)64, ctx);
			this->store->open(ctx);
		}
		catch(IOException* e)
		{
			throw (new(ctx) AlinousException(ConstStr::getCNST_STR_1747(), e, ctx));
		}
		catch(InterruptedException* e)
		{
			throw (new(ctx) AlinousException(ConstStr::getCNST_STR_1747(), e, ctx));
		}
		catch(BTreeException* e)
		{
			throw (new(ctx) AlinousException(ConstStr::getCNST_STR_1747(), e, ctx));
		}
	}
}
ScanResultIndex* ScanResult::getIndex(ArrayList<ScanTableColumnIdentifier>* indexColumns, ThreadContext* ctx) throw() 
{
	int maxLoop = this->indexes->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ScanResultIndex* index = this->indexes->get(i, ctx);
		if(index->hasColumns(indexColumns, ctx))
		{
			return index;
		}
	}
	return nullptr;
}
ScanResultIndex* ScanResult::addIndex(ArrayList<ScanTableColumnIdentifier>* columns, ThreadContext* ctx)
{
	ScanResultIndex* index = (new(ctx) ScanResultIndex(this->metadata, columns, this->trxDir, this->indexes->size(ctx), ctx));
	this->indexes->add(index, ctx);
	return index;
}
ScanResultRecord* ScanResult::getRecord(long long soid, ThreadContext* ctx)
{
	IBTreeNode* node = this->store->findByKey((new(ctx) LongKey(soid, ctx)), ctx);
	ArrayList<IBTreeValue>* values = node->getValues(ctx);
	if(values->size(ctx) != 1)
	{
		throw (new(ctx) BTreeException(ConstStr::getCNST_STR_1750(), ctx));
	}
	return static_cast<ScanResultRecord*>(values->get(0, ctx));
}
void ScanResult::addGroupByRecord(ScanResultRecord* record, DbTransaction* trx, ThreadContext* ctx) throw() 
{
}
void ScanResult::addRecord(ScanResultRecord* record, DbTransaction* trx, ThreadContext* ctx)
{
	ScanResultRecord* newRecord = record->copy(trx, ctx);
	LongKey* key = (new(ctx) LongKey(newRecord->getSoid(ctx), ctx));
	this->store->putKeyValue(key, newRecord, ctx);
	int maxLoop = this->indexes->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ScanResultIndex* index = this->indexes->get(i, ctx);
		index->addIndex(newRecord, ctx);
	}
}
void ScanResult::addRecord(ScanTableIdentifier* tableId, DatabaseRecord* record, DbTransaction* trx, ThreadContext* ctx)
{
	ScanResultRecord* scanedRecord = (new(ctx) ScanResultRecord(tableId, IDatabaseRecord::NORMAL_RECORD, record->getOid(ctx), trx, record, IndexScannerLockRequirement::NO_LOCK, ctx));
	LongKey* key = (new(ctx) LongKey(scanedRecord->getSoid(ctx), ctx));
	this->store->putKeyValue(key, scanedRecord, ctx);
	int maxLoop = this->indexes->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ScanResultIndex* index = this->indexes->get(i, ctx);
		index->addIndex(scanedRecord, ctx);
	}
}
void ScanResult::addRecord(ScanTableIdentifier* tableId, DomVariable* domVariable, DbTransaction* trx, ThreadContext* ctx)
{
	ScanResultRecord* scanedRecord = (new(ctx) ScanResultRecord(tableId, -1, trx, this->metadata, domVariable, ctx));
	LongKey* key = (new(ctx) LongKey(scanedRecord->getSoid(ctx), ctx));
	this->store->putKeyValue(key, scanedRecord, ctx);
	int maxLoop = this->indexes->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ScanResultIndex* index = this->indexes->get(i, ctx);
		index->addIndex(scanedRecord, ctx);
	}
}
void ScanResult::dispose(ISystemLog* logger, ThreadContext* ctx)
{
	int maxLoop = this->indexes->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		this->indexes->get(i, ctx)->dispose(logger, ctx);
	}
	{
		try
		{
			this->store->close(ctx);
			File* file = (new(ctx) File(this->storagePath, ctx));
			if(file->exists(ctx))
			{
				file->_delete(ctx);
			}
		}
		catch(Throwable* e)
		{
			logger->logError(e, ctx);
		}
	}
}
IBTree* ScanResult::getStore(ThreadContext* ctx) throw() 
{
	return store;
}
String* ScanResult::getOidIndexName(ThreadContext* ctx) throw() 
{
	if(this->storagePath == nullptr)
	{
		StringBuilder* buff = (new(ctx) StringBuilder(ctx));
		buff->append(this->trxDir, ctx);
		if(!this->trxDir->endsWith(ConstStr::getCNST_STR_1007(), ctx))
		{
			buff->append(ConstStr::getCNST_STR_1007(), ctx);
		}
		buff->append(ConstStr::getCNST_STR_1748(), ctx)->append(this->serial, ctx)->append(ConstStr::getCNST_STR_1749(), ctx);
		__GC_MV(this, &(this->storagePath), buff->toString(ctx), String);
	}
	return this->storagePath;
}
void ScanResult::__cleanUp(ThreadContext* ctx){
}
}}}}

