#include "include/global.h"


#include "alinous.system/ISystemLog.h"
#include "java.lang/Comparable.h"
#include "alinous.btree/IBTreeKey.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.db.trx.scan/ScanResultIndexKey.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.db.trx.scan/ScanResultRecord.h"
#include "alinous.db.trx.scan/ITableTargetScanner.h"
#include "alinous.db.trx.scan/IJoinScanner.h"

namespace alinous {namespace db {namespace trx {namespace scan {




bool IJoinScanner::__init_done = __init_static_variables();
bool IJoinScanner::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"IJoinScanner", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 IJoinScanner::IJoinScanner(ThreadContext* ctx) throw()  : IObject(ctx), ITableTargetScanner(ctx)
{
}
void IJoinScanner::__construct_impl(ThreadContext* ctx) throw() 
{
}
 IJoinScanner::~IJoinScanner() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void IJoinScanner::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	ITableTargetScanner::__releaseRegerences(true, ctx);
}
void IJoinScanner::__cleanUp(ThreadContext* ctx){
}
}}}}

