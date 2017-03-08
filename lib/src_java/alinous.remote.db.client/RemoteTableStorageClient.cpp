#include "include/global.h"


#include "alinous.remote.db.client/RemoteTableStorageClient.h"

namespace alinous {namespace remote {namespace db {namespace client {





bool RemoteTableStorageClient::__init_done = __init_static_variables();
bool RemoteTableStorageClient::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"RemoteTableStorageClient", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 RemoteTableStorageClient::RemoteTableStorageClient(ThreadContext* ctx) throw()  : IObject(ctx)
{
}
void RemoteTableStorageClient::__construct_impl(ThreadContext* ctx) throw() 
{
}
 RemoteTableStorageClient::~RemoteTableStorageClient() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void RemoteTableStorageClient::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
void RemoteTableStorageClient::__cleanUp(ThreadContext* ctx){
}
}}}}

