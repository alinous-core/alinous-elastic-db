#include "includes.h"


namespace alinous {namespace db {namespace variable {namespace util {





bool RecordStore::__init_done = __init_static_variables();
bool RecordStore::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"RecordStore", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 RecordStore::~RecordStore() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void RecordStore::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
}}}}

