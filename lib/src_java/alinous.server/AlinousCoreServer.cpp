#include "include/global.h"


#include "alinous.system.config/IAlinousConfigElement.h"
#include "alinous.system.config/WebHandlerInfo.h"
#include "alinous.system.config/AlinousConfig.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.system/AlinousCore.h"
#include "alinous.server.http/AlinousHttpServer.h"
#include "alinous.server/AlinousCoreServer.h"

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
 AlinousCoreServer::AlinousCoreServer(String* home, bool debug, int debugPort, ThreadContext* ctx) : IObject(ctx), core(nullptr), httpServer(nullptr), webport(1192)
{
	__GC_MV(this, &(this->core), (new(ctx) AlinousCore(home, debug, ctx)), AlinousCore);
	this->core->init(debugPort, ctx);
	this->core->initDatabase(ctx);
}
void AlinousCoreServer::__construct_impl(String* home, bool debug, int debugPort, ThreadContext* ctx)
{
	__GC_MV(this, &(this->core), (new(ctx) AlinousCore(home, debug, ctx)), AlinousCore);
	this->core->init(debugPort, ctx);
	this->core->initDatabase(ctx);
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
	AlinousConfig* config = this->core->getConfig(ctx);
	WebHandlerInfo* info = config->getWebHandler(ctx);
	if(info != nullptr)
	{
	}
	__GC_MV(this, &(this->httpServer), (new(ctx) AlinousHttpServer(this->webport, this->core, maxThread, ctx)), AlinousHttpServer);
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
void AlinousCoreServer::__cleanUp(ThreadContext* ctx){
}
}}

