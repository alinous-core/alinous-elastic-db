#include "includes.h"


namespace alinous {namespace compile {namespace sql {namespace analyze {





bool ScanUnique::__init_done = __init_static_variables();
bool ScanUnique::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ScanUnique", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ScanUnique::~ScanUnique() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ScanUnique::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	TableMetadataUnique::__releaseRegerences(true, ctx);
}
}}}}

