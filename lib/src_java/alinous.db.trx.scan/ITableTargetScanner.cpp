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

namespace alinous {namespace db {namespace trx {namespace scan {




bool ITableTargetScanner::__init_done = __init_static_variables();
bool ITableTargetScanner::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ITableTargetScanner", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ITableTargetScanner::ITableTargetScanner(ThreadContext* ctx) throw()  : IObject(ctx)
{
}
void ITableTargetScanner::__construct_impl(ThreadContext* ctx) throw() 
{
}
 ITableTargetScanner::~ITableTargetScanner() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ITableTargetScanner::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
void ITableTargetScanner::__cleanUp(ThreadContext* ctx){
}
}}}}

