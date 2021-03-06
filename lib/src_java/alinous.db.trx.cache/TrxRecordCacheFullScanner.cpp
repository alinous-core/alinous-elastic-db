#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "java.lang/Comparable.h"
#include "alinous.btree/IBTreeKey.h"
#include "alinous.btree/IBTreeNode.h"
#include "alinous.btree/BTreeException.h"
#include "alinous.btree/IBTree.h"
#include "alinous.btree/BTree.h"
#include "alinous.btree/LongKey.h"
#include "alinous.btree.scan/BTreeScanner.h"
#include "alinous.compile.sql.analyze/ScanTableMetadata.h"
#include "alinous.db.table/DatabaseException.h"
#include "alinous.db.table.scan/IndexScannerLockRequirement.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.variant/VariantValue.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.db.trx.cache/CachedRecord.h"
#include "alinous.system/ISystemLog.h"
#include "alinous.db.trx.scan/ScanResultIndexKey.h"
#include "alinous.db.trx.scan/ScanResultRecord.h"
#include "alinous.db.trx.scan/ITableTargetScanner.h"
#include "alinous.db.trx/DbTransaction.h"
#include "alinous.db.trx.scan/ScanException.h"
#include "alinous.db.trx.cache/TrxRecordCacheFullScanner.h"

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
			throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1705(), e, ctx));
		}
		catch(InterruptedException* e)
		{
			throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1705(), e, ctx));
		}
		catch(VariableException* e)
		{
			throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1705(), e, ctx));
		}
		catch(BTreeException* e)
		{
			throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1705(), e, ctx));
		}
		catch(AlinousException* e)
		{
			throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1705(), e, ctx));
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
			throw (new(ctx) ScanException(ConstStr::getCNST_STR_1706(), e, ctx));
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
			throw (new(ctx) ScanException(ConstStr::getCNST_STR_1707(), e, ctx));
		}
		catch(InterruptedException* e)
		{
			throw (new(ctx) ScanException(ConstStr::getCNST_STR_1707(), e, ctx));
		}
		catch(IOException* e)
		{
			throw (new(ctx) ScanException(ConstStr::getCNST_STR_1707(), e, ctx));
		}
		catch(BTreeException* e)
		{
			throw (new(ctx) ScanException(ConstStr::getCNST_STR_1707(), e, ctx));
		}
		catch(AlinousException* e)
		{
			throw (new(ctx) ScanException(ConstStr::getCNST_STR_1707(), e, ctx));
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
			throw (new(ctx) ScanException(ConstStr::getCNST_STR_1712(), e, ctx));
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
				throw (new(ctx) ScanException(ConstStr::getCNST_STR_1712(), e, ctx));
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
			throw (new(ctx) ScanException(ConstStr::getCNST_STR_1712(), e, ctx));
		}
		catch(IOException* e)
		{
			throw (new(ctx) ScanException(ConstStr::getCNST_STR_1712(), e, ctx));
		}
		catch(InterruptedException* e)
		{
			throw (new(ctx) ScanException(ConstStr::getCNST_STR_1712(), e, ctx));
		}
		catch(BTreeException* e)
		{
			throw (new(ctx) ScanException(ConstStr::getCNST_STR_1712(), e, ctx));
		}
		catch(AlinousException* e)
		{
			throw (new(ctx) ScanException(ConstStr::getCNST_STR_1712(), e, ctx));
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
				throw (new(ctx) ScanException(ConstStr::getCNST_STR_1712(), e, ctx));
			}
			catch(AlinousException* e)
			{
				throw (new(ctx) ScanException(ConstStr::getCNST_STR_1712(), e, ctx));
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

