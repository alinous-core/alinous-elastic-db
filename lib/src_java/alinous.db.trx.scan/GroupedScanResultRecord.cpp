#include "includes.h"


namespace alinous {namespace db {namespace trx {namespace scan {





bool GroupedScanResultRecord::__init_done = __init_static_variables();
bool GroupedScanResultRecord::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"GroupedScanResultRecord", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 GroupedScanResultRecord::~GroupedScanResultRecord() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void GroupedScanResultRecord::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	ScanResultRecord::__releaseRegerences(true, ctx);
}
}}}}

