#include "includes.h"


namespace alinous {namespace server {





bool AlinousCoreServer::__init_done = __init_static_variables();
bool AlinousCoreServer::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AlinousCoreServer", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AlinousCoreServer::AlinousCoreServer(String* home, bool debug, int debugPort, ThreadContext* ctx) : IObject(ctx), core(nullptr), httpServer(nullptr)
{
	__GC_MV(this, &(this->core), (new(ctx) AlinousCore(home, debug, ctx)), AlinousCore);
	this->core->init(debugPort, ctx);
}
void AlinousCoreServer::__construct_impl(String* home, bool debug, int debugPort, ThreadContext* ctx)
{
	__GC_MV(this, &(this->core), (new(ctx) AlinousCore(home, debug, ctx)), AlinousCore);
	this->core->init(debugPort, ctx);
}
 AlinousCoreServer::~AlinousCoreServer() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AlinousCoreServer::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"AlinousCoreServer", L"~AlinousCoreServer");
	__e_obj1.add(this->core, this);
	core = nullptr;
	__e_obj1.add(this->httpServer, this);
	httpServer = nullptr;
	if(!prepare){
		return;
	}
}
void AlinousCoreServer::startHttpServer(int maxThread, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->httpServer), (new(ctx) AlinousHttpServer(1192, this->core, maxThread, ctx)), AlinousHttpServer);
	this->httpServer->startServer(ctx);
}
void AlinousCoreServer::dispose(ThreadContext* ctx) throw() 
{
	if(this->httpServer != nullptr)
	{
		this->httpServer->stopServer(ctx);
		__GC_MV(this, &(this->httpServer), nullptr, AlinousHttpServer);
	}
	this->core->dispose(ctx);
}
}}

