#include "includes.h"


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
			__GC_MV(this, &(this->store), (new(ctx) BTree(ctx))->init((new(ctx) File(this->storagePath, ctx)), database->getBtreeCache(ctx), database->getCore(ctx)->diskCache, ctx), IBTree);
			this->store->initTreeStorage(32, IBTreeValue::TYPE_LONG, IBTreeValue::TYPE_LONG, (long long)DatatableConstants::capacity, (long long)64, ctx);
			this->store->open(ctx);
		}
		catch(IOException* e)
		{
			throw (new(ctx) AlinousException(ConstStr::getCNST_STR_1658(), e, ctx));
		}
		catch(InterruptedException* e)
		{
			throw (new(ctx) AlinousException(ConstStr::getCNST_STR_1658(), e, ctx));
		}
		catch(BTreeException* e)
		{
			throw (new(ctx) AlinousException(ConstStr::getCNST_STR_1658(), e, ctx));
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
		throw (new(ctx) BTreeException(ConstStr::getCNST_STR_1661(), ctx));
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
		if(!this->trxDir->endsWith(ConstStr::getCNST_STR_984(), ctx))
		{
			buff->append(ConstStr::getCNST_STR_984(), ctx);
		}
		buff->append(ConstStr::getCNST_STR_1659(), ctx)->append(this->serial, ctx)->append(ConstStr::getCNST_STR_1660(), ctx);
		__GC_MV(this, &(this->storagePath), buff->toString(ctx), String);
	}
	return this->storagePath;
}
}}}}

