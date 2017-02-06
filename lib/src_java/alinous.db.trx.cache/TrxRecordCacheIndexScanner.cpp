#include "includes.h"


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
			throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1702(), e, ctx));
		}
		catch(InterruptedException* e)
		{
			throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1702(), e, ctx));
		}
		catch(VariableException* e)
		{
			throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1702(), e, ctx));
		}
		catch(BTreeException* e)
		{
			throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1702(), e, ctx));
		}
		catch(AlinousException* e)
		{
			throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1702(), e, ctx));
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
			throw (new(ctx) ScanException(ConstStr::getCNST_STR_1703(), e, ctx));
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
			throw (new(ctx) ScanException(ConstStr::getCNST_STR_1704(), e, ctx));
		}
		catch(InterruptedException* e)
		{
			throw (new(ctx) ScanException(ConstStr::getCNST_STR_1704(), e, ctx));
		}
		catch(IOException* e)
		{
			throw (new(ctx) ScanException(ConstStr::getCNST_STR_1704(), e, ctx));
		}
		catch(BTreeException* e)
		{
			throw (new(ctx) ScanException(ConstStr::getCNST_STR_1704(), e, ctx));
		}
		catch(AlinousException* e)
		{
			throw (new(ctx) ScanException(ConstStr::getCNST_STR_1704(), e, ctx));
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
			throw (new(ctx) ScanException(ConstStr::getCNST_STR_1704(), e, ctx));
		}
		catch(IOException* e)
		{
			throw (new(ctx) ScanException(ConstStr::getCNST_STR_1704(), e, ctx));
		}
		catch(InterruptedException* e)
		{
			throw (new(ctx) ScanException(ConstStr::getCNST_STR_1704(), e, ctx));
		}
		catch(BTreeException* e)
		{
			throw (new(ctx) ScanException(ConstStr::getCNST_STR_1704(), e, ctx));
		}
		catch(AlinousException* e)
		{
			throw (new(ctx) ScanException(ConstStr::getCNST_STR_1704(), e, ctx));
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
			throw (new(ctx) ScanException(ConstStr::getCNST_STR_1706(), e, ctx));
		}
		catch(IOException* e)
		{
			throw (new(ctx) ScanException(ConstStr::getCNST_STR_1706(), e, ctx));
		}
		catch(InterruptedException* e)
		{
			throw (new(ctx) ScanException(ConstStr::getCNST_STR_1706(), e, ctx));
		}
		catch(BTreeException* e)
		{
			throw (new(ctx) ScanException(ConstStr::getCNST_STR_1706(), e, ctx));
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
		throw (new(ctx) ScanException(ConstStr::getCNST_STR_1705(), ctx));
	}
	CachedRecord* record = static_cast<CachedRecord*>(values->get(0, ctx));
	ScanResultRecord* srecord = (new(ctx) ScanResultRecord(this->tableId, this->kindOfCache, record->getOid(ctx), this->trx, record, IndexScannerLockRequirement::NO_LOCK, ctx));
	return srecord;
}
}}}}

