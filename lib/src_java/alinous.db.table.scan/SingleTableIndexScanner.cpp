#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile.sql.analyze/ScanTableIdentifier.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile/Token.h"
#include "alinous.db.table/DatabaseException.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.variant/VariantValue.h"
#include "alinous.db/AlinousDbException.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.db.table/TableMetadata.h"
#include "java.lang/Comparable.h"
#include "alinous.btree/IBTreeKey.h"
#include "alinous.db.table/IBtreeTableIndex.h"
#include "alinous.db.trx.cache/TrxRecordCacheIndex.h"
#include "alinous.db.trx.cache/TrxRecordsCache.h"
#include "alinous.system/ISystemLog.h"
#include "alinous.db.trx.cache/TrxStorageManager.h"
#include "alinous.db.trx.scan/ScanResultIndexKey.h"
#include "alinous.db.trx.scan/ITableTargetScanner.h"
#include "alinous.db.trx/DbTransaction.h"
#include "alinous.db.table/IScannableIndex.h"
#include "alinous.db.table/IDatabaseTable.h"
#include "alinous.db.trx.scan/ScanResultRecord.h"
#include "alinous.compile.sql.expression/ISQLExpression.h"
#include "alinous.db.trx.scan/ScanException.h"
#include "alinous.db.trx.cache/TrxRecordCacheIndexScanner.h"
#include "alinous.db.trx.scan/IFilterScanner.h"
#include "alinous.db.table.scan/SingleTableIndexScanner.h"

namespace alinous {namespace db {namespace table {namespace scan {





bool SingleTableIndexScanner::__init_done = __init_static_variables();
bool SingleTableIndexScanner::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"SingleTableIndexScanner", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 SingleTableIndexScanner::SingleTableIndexScanner(ThreadContext* ctx) throw()  : IObject(ctx), IFilterScanner(ctx), trx(nullptr), scanner(nullptr), insertScanner(nullptr), updateScanner(nullptr), result(nullptr)
{
}
void SingleTableIndexScanner::__construct_impl(ThreadContext* ctx) throw() 
{
}
 SingleTableIndexScanner::~SingleTableIndexScanner() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void SingleTableIndexScanner::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"SingleTableIndexScanner", L"~SingleTableIndexScanner");
	__e_obj1.add(this->trx, this);
	trx = nullptr;
	__e_obj1.add(this->scanner, this);
	scanner = nullptr;
	__e_obj1.add(this->insertScanner, this);
	insertScanner = nullptr;
	__e_obj1.add(this->updateScanner, this);
	updateScanner = nullptr;
	__e_obj1.add(this->result, this);
	result = nullptr;
	if(!prepare){
		return;
	}
}
SingleTableIndexScanner* SingleTableIndexScanner::init(ScanTableIdentifier* tableId, DbTransaction* trx, IScannableIndex* index, IDatabaseTable* tableStore, TrxRecordCacheIndex* insertCacheindex, TrxRecordCacheIndex* updateCacheindex, int lockMode, ThreadContext* ctx)
{
	__GC_MV(this, &(this->trx), trx, DbTransaction);
	TableMetadata* tableMeta = tableStore->getMetadata(ctx);
	TrxStorageManager* storageManager = this->trx->getTrxStorageManager(ctx);
	TrxRecordsCache* insertCache = storageManager->getInsertCache(tableMeta->getSchema(ctx), tableMeta->getTableName(ctx), ctx);
	TrxRecordsCache* updateCache = storageManager->getUpdateCache(tableMeta->getSchema(ctx), tableMeta->getTableName(ctx), ctx);
	__GC_MV(this, &(this->scanner), ScannerFactory::getTableIndexScanner(tableId, trx, index, tableStore, lockMode, ctx), ITableTargetScanner);
	if(insertCacheindex != nullptr && insertCache != nullptr)
	{
		__GC_MV(this, &(this->insertScanner), (new(ctx) TrxRecordCacheIndexScanner(tableId, trx, insertCacheindex, insertCache, IDatabaseRecord::TRX_CACHE, ctx)), TrxRecordCacheIndexScanner);
	}
	if(updateCacheindex != nullptr && updateCache != nullptr)
	{
		__GC_MV(this, &(this->updateScanner), (new(ctx) TrxRecordCacheIndexScanner(tableId, trx, updateCacheindex, updateCache, IDatabaseRecord::TRX_CACHE, ctx)), TrxRecordCacheIndexScanner);
	}
	return this;
}
bool SingleTableIndexScanner::hasNext(bool debug, ThreadContext* ctx)
{
	if(this->result != nullptr)
	{
		return true;
	}
	if(this->updateScanner != nullptr && this->updateScanner->hasNext(debug, ctx))
	{
		return true;
	}
	if(this->insertScanner != nullptr && this->insertScanner->hasNext(debug, ctx))
	{
		__GC_MV(this, &(this->result), this->insertScanner->next(debug, ctx), ScanResultRecord);
		return true;
	}
	if(this->scanner->hasNext(debug, ctx))
	{
		__GC_MV(this, &(this->result), this->scanner->next(debug, ctx), ScanResultRecord);
		return true;
	}
	return false;
}
ScanResultRecord* SingleTableIndexScanner::next(bool debug, ThreadContext* ctx)
{
	ScanResultRecord* retresult = this->result;
	__GC_MV(this, &(this->result), nullptr, ScanResultRecord);
	return retresult;
}
void SingleTableIndexScanner::startScan(ScanResultIndexKey* indexKeyValue, ThreadContext* ctx)
{
	__GC_MV(this, &(this->result), nullptr, ScanResultRecord);
	if(indexKeyValue != nullptr)
	{
		startsWithKey(indexKeyValue, ctx);
		return;
	}
	this->scanner->startScan(nullptr, ctx);
	if(this->insertScanner != nullptr)
	{
		this->insertScanner->startScan(nullptr, ctx);
	}
	if(this->updateScanner != nullptr)
	{
		this->updateScanner->startScan(nullptr, ctx);
	}
}
void SingleTableIndexScanner::endScan(ThreadContext* ctx)
{
	this->scanner->endScan(ctx);
	if(this->insertScanner != nullptr)
	{
		this->insertScanner->endScan(ctx);
	}
	if(this->updateScanner != nullptr)
	{
		this->updateScanner->endScan(ctx);
	}
}
void SingleTableIndexScanner::dispose(ISystemLog* logger, ThreadContext* ctx)
{
	this->scanner->dispose(logger, ctx);
	if(this->insertScanner != nullptr)
	{
		this->insertScanner->dispose(logger, ctx);
	}
	if(this->updateScanner != nullptr)
	{
		this->updateScanner->dispose(logger, ctx);
	}
}
void SingleTableIndexScanner::startsWithKey(ScanResultIndexKey* indexKeyValue, ThreadContext* ctx)
{
	ScanResultIndexKey* key = (new(ctx) ScanResultIndexKey(ctx));
	int maxLoop = indexKeyValue->getNumCols(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		key->addKeyValue(indexKeyValue->get(i, ctx), ctx);
	}
	this->scanner->startScan(key, ctx);
	if(this->insertScanner != nullptr)
	{
		this->insertScanner->startScan(key, ctx);
	}
	if(this->updateScanner != nullptr)
	{
		this->updateScanner->startScan(key, ctx);
	}
}
void SingleTableIndexScanner::includes(ISQLExpression* arg0, ThreadContext* ctx) throw() 
{
}
void SingleTableIndexScanner::__cleanUp(ThreadContext* ctx){
}
}}}}

