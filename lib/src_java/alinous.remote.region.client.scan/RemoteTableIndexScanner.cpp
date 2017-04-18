#include "include/global.h"


#include "alinous.compile.sql.analyze/ScanTableIdentifier.h"
#include "alinous.db.table/DatabaseException.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.system/ISystemLog.h"
#include "java.lang/Comparable.h"
#include "alinous.btree/IBTreeKey.h"
#include "alinous.db.trx.scan/ScanResultIndexKey.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.db.trx.scan/ScanResultRecord.h"
#include "alinous.db.trx.scan/ITableTargetScanner.h"
#include "alinous.db.trx/DbTransaction.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.db.table/TableColumnMetadata.h"
#include "alinous.db.table/IScannableIndex.h"
#include "alinous.db.table/IDatabaseTable.h"
#include "alinous.db.trx.scan/ScanException.h"
#include "alinous.remote.region.client.scan/IRemoteScanner.h"
#include "alinous.remote.region.client.scan/RemoteTableIndexScanner.h"

namespace alinous {namespace remote {namespace region {namespace client {namespace scan {





bool RemoteTableIndexScanner::__init_done = __init_static_variables();
bool RemoteTableIndexScanner::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"RemoteTableIndexScanner", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 RemoteTableIndexScanner::RemoteTableIndexScanner(ThreadContext* ctx) throw()  : IObject(ctx), IRemoteScanner(ctx), trx(nullptr), index(nullptr), lockMode(0), tableId(nullptr), tableStore(nullptr), nextresult(nullptr)
{
}
void RemoteTableIndexScanner::__construct_impl(ThreadContext* ctx) throw() 
{
}
 RemoteTableIndexScanner::~RemoteTableIndexScanner() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void RemoteTableIndexScanner::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"RemoteTableIndexScanner", L"~RemoteTableIndexScanner");
	__e_obj1.add(this->trx, this);
	trx = nullptr;
	__e_obj1.add(this->index, this);
	index = nullptr;
	__e_obj1.add(this->tableId, this);
	tableId = nullptr;
	__e_obj1.add(this->tableStore, this);
	tableStore = nullptr;
	__e_obj1.add(this->nextresult, this);
	nextresult = nullptr;
	if(!prepare){
		return;
	}
}
RemoteTableIndexScanner* RemoteTableIndexScanner::init(ScanTableIdentifier* tableId, DbTransaction* trx, IScannableIndex* index, IDatabaseTable* tableStore, int lockMode, ThreadContext* ctx)
{
	__GC_MV(this, &(this->trx), trx, DbTransaction);
	__GC_MV(this, &(this->index), index, IScannableIndex);
	__GC_MV(this, &(this->tableStore), tableStore, IDatabaseTable);
	this->lockMode = lockMode;
	__GC_MV(this, &(this->tableId), tableId, ScanTableIdentifier);
	return this;
}
void RemoteTableIndexScanner::startScan(ScanResultIndexKey* indexKeyValue, ThreadContext* ctx)
{
	ArrayList<TableColumnMetadata>* colmns = this->index->getColumns(ctx);
}
void RemoteTableIndexScanner::endScan(ThreadContext* ctx)
{
}
bool RemoteTableIndexScanner::hasNext(bool debug, ThreadContext* ctx)
{
	return false;
}
ScanResultRecord* RemoteTableIndexScanner::next(bool debug, ThreadContext* ctx)
{
	return nullptr;
}
void RemoteTableIndexScanner::dispose(ISystemLog* logger, ThreadContext* ctx)
{
}
void RemoteTableIndexScanner::__cleanUp(ThreadContext* ctx){
}
}}}}}

