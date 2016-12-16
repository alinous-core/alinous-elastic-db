#include "includes.h"


namespace alinous {namespace remote {namespace region {





bool NodeReference::__init_done = __init_static_variables();
bool NodeReference::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"NodeReference", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 NodeReference::NodeReference(String* host, int port, ThreadContext* ctx) throw()  : IObject(ctx), host(nullptr), port(0)
{
	__GC_MV(this, &(this->host), host, String);
	this->port = port;
}
void NodeReference::__construct_impl(String* host, int port, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->host), host, String);
	this->port = port;
}
 NodeReference::~NodeReference() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void NodeReference::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"NodeReference", L"~NodeReference");
	__e_obj1.add(this->host, this);
	host = nullptr;
	if(!prepare){
		return;
	}
}
String* NodeReference::getHost(ThreadContext* ctx) throw() 
{
	return host;
}
int NodeReference::getPort(ThreadContext* ctx) throw() 
{
	return port;
}
}}}

