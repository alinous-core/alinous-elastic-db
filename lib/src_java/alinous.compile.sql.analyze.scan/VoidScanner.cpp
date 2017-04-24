#include "include/global.h"


#include "alinous.system/ISystemLog.h"
#include "java.lang/Comparable.h"
#include "alinous.btree/IBTreeKey.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.db.trx.scan/ScanResultIndexKey.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.db.trx.scan/ScanResultRecord.h"
#include "alinous.db.trx.scan/ITableTargetScanner.h"
#include "alinous.compile.sql.analyze.scan/VoidScanner.h"

namespace alinous {namespace compile {namespace sql {namespace analyze {namespace scan {





bool VoidScanner::__init_done = __init_static_variables();
bool VoidScanner::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"VoidScanner", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 VoidScanner::VoidScanner(ThreadContext* ctx) throw()  : IObject(ctx), ITableTargetScanner(ctx)
{
}
void VoidScanner::__construct_impl(ThreadContext* ctx) throw() 
{
}
 VoidScanner::~VoidScanner() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void VoidScanner::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
void VoidScanner::startScan(ScanResultIndexKey* indexValue, ThreadContext* ctx) throw() 
{
}
void VoidScanner::endScan(ThreadContext* ctx) throw() 
{
}
bool VoidScanner::hasNext(bool debug, ThreadContext* ctx) throw() 
{
	return false;
}
ScanResultRecord* VoidScanner::next(bool debug, ThreadContext* ctx) throw() 
{
	return nullptr;
}
void VoidScanner::dispose(ISystemLog* logger, ThreadContext* ctx) throw() 
{
}
void VoidScanner::__cleanUp(ThreadContext* ctx){
}
}}}}}

