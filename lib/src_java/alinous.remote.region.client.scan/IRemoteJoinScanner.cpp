#include "include/global.h"


#include "alinous.system/ISystemLog.h"
#include "java.lang/Comparable.h"
#include "alinous.btree/IBTreeKey.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.db.trx.scan/ScanResultIndexKey.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.db.trx.scan/ScanResultRecord.h"
#include "alinous.db.trx.scan/ITableTargetScanner.h"
#include "alinous.remote.region.client.scan/IRemoteScanner.h"
#include "alinous.remote.region.client.scan/IRemoteJoinScanner.h"

namespace alinous {namespace remote {namespace region {namespace client {namespace scan {




bool IRemoteJoinScanner::__init_done = __init_static_variables();
bool IRemoteJoinScanner::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"IRemoteJoinScanner", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 IRemoteJoinScanner::IRemoteJoinScanner(ThreadContext* ctx) throw()  : IObject(ctx), IRemoteScanner(ctx)
{
}
void IRemoteJoinScanner::__construct_impl(ThreadContext* ctx) throw() 
{
}
 IRemoteJoinScanner::~IRemoteJoinScanner() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void IRemoteJoinScanner::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	IRemoteScanner::__releaseRegerences(true, ctx);
}
void IRemoteJoinScanner::__cleanUp(ThreadContext* ctx){
}
}}}}}

