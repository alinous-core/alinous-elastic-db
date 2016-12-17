#include "includes.h"


namespace alinous {namespace remote {namespace region {namespace client {





bool RegionClientConnectionFactory::__init_done = __init_static_variables();
bool RegionClientConnectionFactory::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"RegionClientConnectionFactory", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 RegionClientConnectionFactory::RegionClientConnectionFactory(RegionConnectionInfo* info, ThreadContext* ctx) throw()  : IObject(ctx), ISocketConnectionFactory(ctx), info(nullptr)
{
	__GC_MV(this, &(this->info), info, RegionConnectionInfo);
}
void RegionClientConnectionFactory::__construct_impl(RegionConnectionInfo* info, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->info), info, RegionConnectionInfo);
}
 RegionClientConnectionFactory::~RegionClientConnectionFactory() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void RegionClientConnectionFactory::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"RegionClientConnectionFactory", L"~RegionClientConnectionFactory");
	__e_obj1.add(this->info, this);
	info = nullptr;
	if(!prepare){
		return;
	}
}
ISocketConnection* RegionClientConnectionFactory::newConnection(SocketConnectionPool* pool, ThreadContext* ctx)
{
	return (new(ctx) RegionConnection(pool, this->info, ctx));
}
}}}}

