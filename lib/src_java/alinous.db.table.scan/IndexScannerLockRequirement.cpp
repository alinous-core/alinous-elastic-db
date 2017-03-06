#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "java.lang/Comparable.h"
#include "alinous.btree/IBTreeKey.h"
#include "alinous.btree/IBTree.h"
#include "alinous.btree/BTree.h"
#include "alinous.btree.scan/BTreeScanner.h"
#include "alinous.compile.sql.analyze/ScanTableIdentifier.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.system/ISystemLog.h"
#include "alinous.db.trx.scan/ScanResultIndexKey.h"
#include "alinous.db.table.scan/IndexScannerLockRequirement.h"
#include "alinous.db.trx/TrxLockContext.h"
#include "alinous.db.trx.scan/ScanResultRecord.h"
#include "alinous.db.trx.scan/ITableTargetScanner.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.db.trx/DbTransaction.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.db.table/TableColumnMetadata.h"
#include "alinous.db.table/DatabaseRecord.h"
#include "alinous.db.table/IScannableIndex.h"
#include "alinous.db.table/IDatabaseTable.h"
#include "alinous.db.trx.scan/IFilterScanner.h"
#include "alinous.db.table.scan/TableIndexScanner.h"
#include "alinous.db.table.scan/IndexListScannerParam.h"
#include "alinous.db.table.scan/UpdateHistoryValuesIterator.h"
#include "alinous.db.table/IBtreeTableIndex.h"
#include "alinous.db.trx.cache/TrxRecordCacheIndex.h"
#include "alinous.db.trx.cache/TrxRecordCacheIndexScanner.h"
#include "alinous.db.table.scan/SingleTableIndexScanner.h"
#include "alinous.compile.sql.analyze/InnerNecessaryCondition.h"
#include "alinous.db.table.scan/IndexRangeScannerParam.h"
#include "alinous.db.table.scan/IndexRangeScanner.h"
#include "alinous.db.table.scan/IndexEqScanner.h"
#include "alinous.db.table.scan/IndexListScanner.h"
#include "alinous.db.table.scan/UpdateHistoryBTreeIndexScanner.h"
#include "alinous.db.table.scan/TableFullScanner.h"

namespace alinous {namespace db {namespace table {namespace scan {




constexpr const int IndexScannerLockRequirement::NO_LOCK;
constexpr const int IndexScannerLockRequirement::INSTANT_SHARE;
constexpr const int IndexScannerLockRequirement::EXPLICIT_SHARE;
constexpr const int IndexScannerLockRequirement::INSTANT_UPDATE;
constexpr const int IndexScannerLockRequirement::EXPLICIT_UPDATE;
bool IndexScannerLockRequirement::__init_done = __init_static_variables();
bool IndexScannerLockRequirement::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"IndexScannerLockRequirement", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 IndexScannerLockRequirement::IndexScannerLockRequirement(ThreadContext* ctx) throw()  : IObject(ctx)
{
}
void IndexScannerLockRequirement::__construct_impl(ThreadContext* ctx) throw() 
{
}
 IndexScannerLockRequirement::~IndexScannerLockRequirement() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void IndexScannerLockRequirement::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
void IndexScannerLockRequirement::__cleanUp(ThreadContext* ctx){
}
}}}}

