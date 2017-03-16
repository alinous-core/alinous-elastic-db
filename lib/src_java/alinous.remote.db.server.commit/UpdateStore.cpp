#include "include/global.h"


#include "alinous.remote.db.server.commit/UpdateStore.h"

namespace alinous {namespace remote {namespace db {namespace server {namespace commit {





bool UpdateStore::__init_done = __init_static_variables();
bool UpdateStore::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"UpdateStore", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 UpdateStore::UpdateStore(ThreadContext* ctx) throw()  : IObject(ctx)
{
}
void UpdateStore::__construct_impl(ThreadContext* ctx) throw() 
{
}
 UpdateStore::~UpdateStore() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void UpdateStore::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
void UpdateStore::__cleanUp(ThreadContext* ctx){
}
}}}}}

