#include "includes.h"


namespace alinous {namespace remote {namespace region {namespace client {





bool RemoteTableScheme::__init_done = __init_static_variables();
bool RemoteTableScheme::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"RemoteTableScheme", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 RemoteTableScheme::~RemoteTableScheme() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void RemoteTableScheme::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
IDatabaseTable* RemoteTableScheme::getTableStore(String* tableName, ThreadContext* ctx) throw() 
{
	return nullptr;
}
}}}}

