#include "include/global.h"


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
#include "alinous.db.trx.scan/ScanException.h"
#include "alinous.compile.sql.analyze.scan/ScanListScanner.h"

namespace alinous {namespace compile {namespace sql {namespace analyze {namespace scan {





bool ScanListScanner::__init_done = __init_static_variables();
bool ScanListScanner::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ScanListScanner", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ScanListScanner::ScanListScanner(ThreadContext* ctx) throw()  : IObject(ctx), ITableTargetScanner(ctx), scanners(GCUtils<ArrayList<ITableTargetScanner> >::ins(this, (new(ctx) ArrayList<ITableTargetScanner>(ctx)), ctx, __FILEW__, __LINE__, L"")), current(0), scanner(nullptr), indexKeyValue(nullptr)
{
}
void ScanListScanner::__construct_impl(ThreadContext* ctx) throw() 
{
}
 ScanListScanner::~ScanListScanner() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ScanListScanner::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ScanListScanner", L"~ScanListScanner");
	__e_obj1.add(this->scanners, this);
	scanners = nullptr;
	__e_obj1.add(this->scanner, this);
	scanner = nullptr;
	__e_obj1.add(this->indexKeyValue, this);
	indexKeyValue = nullptr;
	if(!prepare){
		return;
	}
}
void ScanListScanner::addScanner(ITableTargetScanner* scanner, ThreadContext* ctx) throw() 
{
	this->scanners->add(scanner, ctx);
}
void ScanListScanner::startScan(ScanResultIndexKey* indexKeyValue, ThreadContext* ctx)
{
	if(this->scanners->isEmpty(ctx))
	{
		return;
	}
	__GC_MV(this, &(this->indexKeyValue), indexKeyValue, ScanResultIndexKey);
	__GC_MV(this, &(this->scanner), this->scanners->get(0, ctx), ITableTargetScanner);
	this->scanner->startScan(indexKeyValue, ctx);
}
void ScanListScanner::endScan(ThreadContext* ctx)
{
	this->scanners->clear(ctx);
}
bool ScanListScanner::hasNext(bool debug, ThreadContext* ctx)
{
	if(this->scanners->isEmpty(ctx))
	{
		return false;
	}
	if(this->scanner->hasNext(debug, ctx))
	{
		return true;
	}
	this->current ++ ;
	if(this->scanners->size(ctx) == this->current)
	{
		return false;
	}
	__GC_MV(this, &(this->scanner), this->scanners->get(this->current, ctx), ITableTargetScanner);
	this->scanner->startScan(this->indexKeyValue, ctx);
	return this->scanner->hasNext(debug, ctx);
}
ScanResultRecord* ScanListScanner::next(bool debug, ThreadContext* ctx)
{
	return this->scanner->next(debug, ctx);
}
void ScanListScanner::dispose(ISystemLog* logger, ThreadContext* ctx)
{
	endScan(ctx);
}
void ScanListScanner::__cleanUp(ThreadContext* ctx){
}
}}}}}

