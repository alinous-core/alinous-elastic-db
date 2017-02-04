#include "includes.h"


namespace alinous {namespace runtime {namespace engine {namespace debugger {





String* AlinousDebugCommandSender::COMMAND = ConstStr::getCNST_STR_1171();
bool AlinousDebugCommandSender::__init_done = __init_static_variables();
bool AlinousDebugCommandSender::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AlinousDebugCommandSender", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AlinousDebugCommandSender::AlinousDebugCommandSender(String* httpHost, IHttpAccessMethod* httpAccessMethod, ThreadContext* ctx) throw()  : IObject(ctx), httpAccessMethod(nullptr), httpHost(nullptr)
{
	__GC_MV(this, &(this->httpAccessMethod), httpAccessMethod, IHttpAccessMethod);
	__GC_MV(this, &(this->httpHost), httpHost, String);
}
void AlinousDebugCommandSender::__construct_impl(String* httpHost, IHttpAccessMethod* httpAccessMethod, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->httpAccessMethod), httpAccessMethod, IHttpAccessMethod);
	__GC_MV(this, &(this->httpHost), httpHost, String);
}
 AlinousDebugCommandSender::~AlinousDebugCommandSender() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AlinousDebugCommandSender::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"AlinousDebugCommandSender", L"~AlinousDebugCommandSender");
	__e_obj1.add(this->httpAccessMethod, this);
	httpAccessMethod = nullptr;
	__e_obj1.add(this->httpHost, this);
	httpHost = nullptr;
	if(!prepare){
		return;
	}
}
bool AlinousDebugCommandSender::checkPortOpened(ThreadContext* ctx) throw() 
{
	return this->httpAccessMethod->checkHealth(this->httpHost, ctx);
}
AlinousServerDebugHttpResponse* AlinousDebugCommandSender::sendCommand(IClientRequest* request, ThreadContext* ctx)
{
	Map<String,String>* map = request->getParamMap(ctx);
	map->put(COMMAND, request->getCommand(ctx), ctx);
	return this->httpAccessMethod->httpPost(this->httpHost, map, ctx);
}
}}}}

