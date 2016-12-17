#include "includes.h"


namespace alinous {namespace remote {namespace region {namespace client {





bool RegionConnectionInfo::__init_done = __init_static_variables();
bool RegionConnectionInfo::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"RegionConnectionInfo", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 RegionConnectionInfo::RegionConnectionInfo(String* host, int port, ThreadContext* ctx) throw()  : IObject(ctx), host(nullptr), port(0)
{
	__GC_MV(this, &(this->host), host, String);
	this->port = port;
}
void RegionConnectionInfo::__construct_impl(String* host, int port, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->host), host, String);
	this->port = port;
}
 RegionConnectionInfo::~RegionConnectionInfo() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void RegionConnectionInfo::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"RegionConnectionInfo", L"~RegionConnectionInfo");
	__e_obj1.add(this->host, this);
	host = nullptr;
	if(!prepare){
		return;
	}
}
String* RegionConnectionInfo::getHost(ThreadContext* ctx) throw() 
{
	return host;
}
void RegionConnectionInfo::setHost(String* host, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->host), host, String);
}
int RegionConnectionInfo::getPort(ThreadContext* ctx) throw() 
{
	return port;
}
void RegionConnectionInfo::setPort(int port, ThreadContext* ctx) throw() 
{
	this->port = port;
}
}}}}

