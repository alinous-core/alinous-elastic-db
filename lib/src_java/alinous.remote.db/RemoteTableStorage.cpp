#include "includes.h"


namespace alinous {namespace remote {namespace db {





bool RemoteTableStorage::__init_done = __init_static_variables();
bool RemoteTableStorage::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"RemoteTableStorage", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 RemoteTableStorage::~RemoteTableStorage() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void RemoteTableStorage::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
}}}

