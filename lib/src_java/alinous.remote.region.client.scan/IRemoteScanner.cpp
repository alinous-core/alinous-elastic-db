#include "include/global.h"


#include "alinous.system/ISystemLog.h"
#include "java.lang/Comparable.h"
#include "alinous.btree/IBTreeKey.h"
#include "alinous.db.trx.scan/ScanResultIndexKey.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.db.trx.scan/ScanResultRecord.h"
#include "alinous.db.trx.scan/ITableTargetScanner.h"
#include "alinous.remote.region.client.scan/IRemoteScanner.h"

namespace alinous {namespace remote {namespace region {namespace client {namespace scan {




bool IRemoteScanner::__init_done = __init_static_variables();
bool IRemoteScanner::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"IRemoteScanner", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 IRemoteScanner::IRemoteScanner(ThreadContext* ctx) throw()  : IObject(ctx), ITableTargetScanner(ctx)
{
}
void IRemoteScanner::__construct_impl(ThreadContext* ctx) throw() 
{
}
 IRemoteScanner::~IRemoteScanner() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void IRemoteScanner::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	ITableTargetScanner::__releaseRegerences(true, ctx);
}
void IRemoteScanner::__cleanUp(ThreadContext* ctx){
}
}}}}}

