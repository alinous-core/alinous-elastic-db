#include "include/global.h"


#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.db/AlinousDbException.h"
#include "alinous.db.table/DatabaseException.h"
#include "alinous.system/ISystemLog.h"
#include "java.lang/Comparable.h"
#include "alinous.btree/IBTreeKey.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.db.trx.scan/ScanResultIndexKey.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.db.trx.scan/ScanResultRecord.h"
#include "alinous.db.trx.scan/ITableTargetScanner.h"
#include "alinous.db.trx.scan/ScanException.h"
#include "alinous.db.trx.scan/ScannedOids.h"
#include "alinous.compile.sql.select.join.scan/JoinedCollectionScanner.h"

namespace alinous {namespace compile {namespace sql {namespace select {namespace join {namespace scan {





bool JoinedCollectionScanner::__init_done = __init_static_variables();
bool JoinedCollectionScanner::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"JoinedCollectionScanner", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 JoinedCollectionScanner::JoinedCollectionScanner(ArrayList<ITableTargetScanner>* scanners, ThreadContext* ctx) throw()  : IObject(ctx), ITableTargetScanner(ctx), scanners(nullptr), scannedoids(nullptr), current(0), currentScanner(nullptr), nextResult(nullptr)
{
	GCUtils<ArrayList<ITableTargetScanner> >::mv(this, &(this->scanners), scanners, ctx);
	__GC_MV(this, &(this->scannedoids), (new(ctx) ScannedOids(ctx)), ScannedOids);
}
void JoinedCollectionScanner::__construct_impl(ArrayList<ITableTargetScanner>* scanners, ThreadContext* ctx) throw() 
{
	GCUtils<ArrayList<ITableTargetScanner> >::mv(this, &(this->scanners), scanners, ctx);
	__GC_MV(this, &(this->scannedoids), (new(ctx) ScannedOids(ctx)), ScannedOids);
}
 JoinedCollectionScanner::~JoinedCollectionScanner() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void JoinedCollectionScanner::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"JoinedCollectionScanner", L"~JoinedCollectionScanner");
	__e_obj1.add(this->scanners, this);
	scanners = nullptr;
	__e_obj1.add(this->scannedoids, this);
	scannedoids = nullptr;
	__e_obj1.add(this->currentScanner, this);
	currentScanner = nullptr;
	__e_obj1.add(this->nextResult, this);
	nextResult = nullptr;
	if(!prepare){
		return;
	}
}
void JoinedCollectionScanner::startScan(ScanResultIndexKey* indexKeyValue, ThreadContext* ctx)
{
	this->current = 0;
	__GC_MV(this, &(this->currentScanner), this->scanners->get(this->current++, ctx), ITableTargetScanner);
	this->currentScanner->startScan(nullptr, ctx);
}
void JoinedCollectionScanner::endScan(ThreadContext* ctx)
{
	this->currentScanner->endScan(ctx);
	__GC_MV(this, &(this->currentScanner), nullptr, ITableTargetScanner);
}
bool JoinedCollectionScanner::hasNext(bool debug, ThreadContext* ctx)
{
	while(this->nextResult == nullptr)
	{
		if(!this->currentScanner->hasNext(debug, ctx))
		{
			this->currentScanner->endScan(ctx);
			if(this->current == this->scanners->size(ctx))
			{
				return false;
			}
			__GC_MV(this, &(this->currentScanner), this->scanners->get(this->current++, ctx), ITableTargetScanner);
			this->currentScanner->startScan(nullptr, ctx);
		}
		ScanResultRecord* rec = this->currentScanner->next(debug, ctx);
		if(this->scannedoids->contains(rec, ctx))
		{
			continue;
		}
		__GC_MV(this, &(this->nextResult), rec, ScanResultRecord);
		this->scannedoids->addOid(rec, ctx);
		break ;
	}
	return true;
}
ScanResultRecord* JoinedCollectionScanner::next(bool debug, ThreadContext* ctx)
{
	ScanResultRecord* ret = this->nextResult;
	__GC_MV(this, &(this->nextResult), nullptr, ScanResultRecord);
	return ret;
}
void JoinedCollectionScanner::dispose(ISystemLog* logger, ThreadContext* ctx)
{
	int maxLoop = this->scanners->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		ITableTargetScanner* scanner = this->scanners->get(i, ctx);
		scanner->dispose(logger, ctx);
	}
	this->scanners->clear(ctx);
	this->scannedoids->dispose(ctx);
}
void JoinedCollectionScanner::__cleanUp(ThreadContext* ctx){
}
}}}}}}

