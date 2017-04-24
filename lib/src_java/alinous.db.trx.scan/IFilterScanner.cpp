#include "include/global.h"


#include "alinous.system/ISystemLog.h"
#include "java.lang/Comparable.h"
#include "alinous.btree/IBTreeKey.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.db.trx.scan/ScanResultIndexKey.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.db.trx.scan/ScanResultRecord.h"
#include "alinous.db.trx.scan/ITableTargetScanner.h"
#include "alinous.db.trx.scan/IFilterScanner.h"

namespace alinous {namespace db {namespace trx {namespace scan {




bool IFilterScanner::__init_done = __init_static_variables();
bool IFilterScanner::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"IFilterScanner", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 IFilterScanner::IFilterScanner(ThreadContext* ctx) throw()  : IObject(ctx), ITableTargetScanner(ctx)
{
}
void IFilterScanner::__construct_impl(ThreadContext* ctx) throw() 
{
}
 IFilterScanner::~IFilterScanner() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void IFilterScanner::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	ITableTargetScanner::__releaseRegerences(true, ctx);
}
void IFilterScanner::__cleanUp(ThreadContext* ctx){
}
}}}}

