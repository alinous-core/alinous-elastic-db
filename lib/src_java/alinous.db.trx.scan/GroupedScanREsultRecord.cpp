#include "includes.h"


namespace alinous {namespace db {namespace trx {namespace scan {





bool GroupedScanREsultRecord::__init_done = __init_static_variables();
bool GroupedScanREsultRecord::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"GroupedScanREsultRecord", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 GroupedScanREsultRecord::~GroupedScanREsultRecord() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void GroupedScanREsultRecord::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	ScanResultRecord::__releaseRegerences(true, ctx);
}
}}}}

