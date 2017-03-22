#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
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
#include "alinous.btree.scan/BTreeScanner.h"
#include "alinous.db/AlinousDbException.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.variant/VariantValue.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.db.table/TableColumnMetadata.h"
#include "alinous.db.table/TableMetadataUnique.h"
#include "alinous.compile.sql.analyze/ScanUnique.h"
#include "alinous.db.table/BTreeIndexKey.h"
#include "alinous.db.table/IScannableIndex.h"
#include "alinous.db.table/IDatabaseTable.h"
#include "alinous.db.table/TableIndexValue.h"
#include "alinous.lock.unique/UniqueExclusiveException.h"
#include "alinous.lock.unique/UniqueExclusiveLock.h"
#include "alinous.lock.unique/UniqueExclusiveLockManager.h"
#include "alinous.remote.region.server.schema.strategy/UniqueOpValue.h"
#include "alinous.remote.region.server.schema.strategy/UniqueCheckOperation.h"
#include "alinous.remote.db.server.trx/StorageTransaction.h"
#include "alinous.remote.db.server.trx/UniqueChecker.h"

namespace alinous {namespace remote {namespace db {namespace server {namespace trx {





bool UniqueChecker::__init_done = __init_static_variables();
bool UniqueChecker::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"UniqueChecker", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 UniqueChecker::UniqueChecker(UniqueExclusiveLockManager* uniqueLockMgr, StorageTransaction* trx, ThreadContext* ctx) throw()  : IObject(ctx), uniqueLockMgr(nullptr), trx(nullptr)
{
	__GC_MV(this, &(this->uniqueLockMgr), uniqueLockMgr, UniqueExclusiveLockManager);
	__GC_MV(this, &(this->trx), trx, StorageTransaction);
}
void UniqueChecker::__construct_impl(UniqueExclusiveLockManager* uniqueLockMgr, StorageTransaction* trx, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->uniqueLockMgr), uniqueLockMgr, UniqueExclusiveLockManager);
	__GC_MV(this, &(this->trx), trx, StorageTransaction);
}
 UniqueChecker::~UniqueChecker() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void UniqueChecker::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"UniqueChecker", L"~UniqueChecker");
	__e_obj1.add(this->uniqueLockMgr, this);
	uniqueLockMgr = nullptr;
	__e_obj1.add(this->trx, this);
	trx = nullptr;
	if(!prepare){
		return;
	}
}
void UniqueChecker::checkUnique(IDatabaseTable* table, List<UniqueCheckOperation>* uniqueCheckOps, ThreadContext* ctx)
{
	int maxLoop = uniqueCheckOps->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		UniqueCheckOperation* op = uniqueCheckOps->get(i, ctx);
		handleUniqueOp(table, op, ctx);
	}
}
void UniqueChecker::handleUniqueOp(IDatabaseTable* table, UniqueCheckOperation* op, ThreadContext* ctx)
{
	List<UniqueOpValue>* values = op->getValues(ctx);
	ScanUnique* unique = op->getUnique(ctx);
	int maxLoop = values->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		UniqueOpValue* val = values->get(i, ctx);
		String* lockString = val->getLockStr(ctx);
		{
			try
			{
				UniqueExclusiveLock* lock = this->uniqueLockMgr->lockWithCheck(unique, lockString, true, ctx);
				this->trx->addUniqueExclusiveLock(lock, ctx);
			}
			catch(UniqueExclusiveException* e)
			{
				this->trx->unlockUniqueAll(ctx);
				throw e;
			}
		}
	}
	List<TableColumnMetadata>* cols = unique->getUniqueColList(ctx);
	IScannableIndex* scanIndex = table->getTableUniqueIndexByCols(cols, ctx);
	BTree* btree = nullptr;
	bool scanAll = scanIndex == nullptr;
	if(scanAll)
	{
		scanIndex = table->getPrimaryIndex(ctx);
	}
	btree = scanIndex->getStorage(ctx);
	BTreeScanner* scanner = (new(ctx) BTreeScanner(btree, ctx));
	for(int i = 0; i != maxLoop; ++i)
	{
		UniqueOpValue* val = values->get(i, ctx);
		List<VariantValue>* valuesList = val->getValues(ctx);
		if(!scanAll)
		{
			if(findUnique(table, cols, valuesList, scanner, ctx))
			{
				throw (new(ctx) UniqueExclusiveException(ConstStr::getCNST_STR_3592(), ctx));
			}
		}
				else 
		{
			if(findUniqueScanAll(table, cols, valuesList, scanner, ctx))
			{
				throw (new(ctx) UniqueExclusiveException(ConstStr::getCNST_STR_3592(), ctx));
			}
		}
	}
}
bool UniqueChecker::findUniqueScanAll(IDatabaseTable* table, List<TableColumnMetadata>* cols, List<VariantValue>* valuesList, BTreeScanner* scanner, ThreadContext* ctx)
{
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			scanner->endScan(ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			scanner->startScan(false, ctx);
			while(scanner->hasNext(ctx))
			{
				IBTreeNode* node = scanner->next(ctx);
				ArrayList<IBTreeValue>* values = node->getValues(ctx);
				if(checkUniqueValueWithBtreeValues(values, table, cols, valuesList, ctx))
				{
					return true;
				}
			}
		}
		catch(...){throw;}
	}
	return false;
}
bool UniqueChecker::findUnique(IDatabaseTable* table, List<TableColumnMetadata>* cols, List<VariantValue>* valuesList, BTreeScanner* scanner, ThreadContext* ctx)
{
	IBTreeKey* key = (new(ctx) BTreeIndexKey(valuesList, ctx));
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			scanner->endScan(ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			scanner->startScan(key, ctx);
			while(scanner->hasNext(ctx))
			{
				IBTreeNode* node = scanner->next(ctx);
				ArrayList<IBTreeValue>* values = node->getValues(ctx);
				if(checkUniqueValueWithBtreeValues(values, table, cols, valuesList, ctx))
				{
					return true;
				}
			}
		}
		catch(...){throw;}
	}
	return false;
}
bool UniqueChecker::checkUniqueValueWithBtreeValues(ArrayList<IBTreeValue>* values, IDatabaseTable* table, List<TableColumnMetadata>* cols, List<VariantValue>* valuesList, ThreadContext* ctx)
{
	int maxLoop = values->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IBTreeValue* v = values->get(i, ctx);
		TableIndexValue* value = static_cast<TableIndexValue*>(v);
		long long position = value->getPosition(ctx);
		IDatabaseRecord* record = table->loadRecord(position, ctx);
		if(this->trx->isVisible(record, ctx))
		{
			continue;
		}
		if(checkEquals(record, cols, valuesList, ctx))
		{
			return true;
		}
	}
	return false;
}
bool UniqueChecker::checkEquals(IDatabaseRecord* record, List<TableColumnMetadata>* cols, List<VariantValue>* valuesList, ThreadContext* ctx) throw() 
{
	int maxLoop = cols->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		TableColumnMetadata* metacol = cols->get(i, ctx);
		VariantValue* recvv = record->getColumnValue(metacol->columnOrder, ctx);
		VariantValue* vv = valuesList->get(i, ctx);
		if(vv->equals(recvv, ctx))
		{
			return true;
		}
	}
	return false;
}
void UniqueChecker::__cleanUp(ThreadContext* ctx){
}
}}}}}

