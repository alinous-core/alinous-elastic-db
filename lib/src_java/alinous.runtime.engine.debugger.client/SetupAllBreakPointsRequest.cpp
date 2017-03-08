#include "include/global.h"


#include "alinous.runtime.engine.debugger.server/ServerBreakPoint.h"
#include "alinous.runtime.engine.debugger/AlinousScriptDebugger.h"
#include "alinous.runtime.engine.debugger/AlinousServerDebugHttpResponse.h"
#include "alinous.runtime.engine.debugger.client/IClientRequest.h"
#include "alinous.runtime.engine.debugger.client/SetupAllBreakPointsRequest.h"

namespace alinous {namespace runtime {namespace engine {namespace debugger {namespace client {





bool SetupAllBreakPointsRequest::__init_done = __init_static_variables();
bool SetupAllBreakPointsRequest::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"SetupAllBreakPointsRequest", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 SetupAllBreakPointsRequest::SetupAllBreakPointsRequest(ThreadContext* ctx) throw()  : IObject(ctx), IClientRequest(ctx), breakpoints(GCUtils<List<ServerBreakPoint> >::ins(this, (new(ctx) ArrayList<ServerBreakPoint>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
}
void SetupAllBreakPointsRequest::__construct_impl(ThreadContext* ctx) throw() 
{
}
 SetupAllBreakPointsRequest::~SetupAllBreakPointsRequest() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void SetupAllBreakPointsRequest::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"SetupAllBreakPointsRequest", L"~SetupAllBreakPointsRequest");
	__e_obj1.add(this->breakpoints, this);
	breakpoints = nullptr;
	if(!prepare){
		return;
	}
}
void SetupAllBreakPointsRequest::addBreakpoint(ServerBreakPoint* breakpoint, ThreadContext* ctx) throw() 
{
	this->breakpoints->add(breakpoint, ctx);
}
AlinousServerDebugHttpResponse* SetupAllBreakPointsRequest::executeRequest(AlinousScriptDebugger* debugManager, ThreadContext* ctx) throw() 
{
	AlinousServerDebugHttpResponse* res = (new(ctx) AlinousServerDebugHttpResponse(0, ctx));
	debugManager->clearBreakpoints(ctx);
	Iterator<ServerBreakPoint>* it = this->breakpoints->iterator(ctx);
	while(it->hasNext(ctx))
	{
		ServerBreakPoint* point = it->next(ctx);
		debugManager->addBreakPoint(point, ctx);
	}
	return res;
}
String* SetupAllBreakPointsRequest::getCommand(ThreadContext* ctx) throw() 
{
	return IClientRequest::CMD_SETUP_ALL_BREAKPOINTS;
}
Map<String,String>* SetupAllBreakPointsRequest::getParamMap(ThreadContext* ctx) throw() 
{
	Map<String,String>* m = (new(ctx) HashMap<String,String>(ctx));
	int i = 0;
	Iterator<ServerBreakPoint>* it = this->breakpoints->iterator(ctx);
	while(it->hasNext(ctx))
	{
		ServerBreakPoint* point = it->next(ctx);
		String* number = Integer::toString(i, ctx);
		i ++ ;
		m->put(number, point->toString(ctx), ctx);
	}
	return m;
}
void SetupAllBreakPointsRequest::importParams(Map<String,String>* params, ThreadContext* ctx) throw() 
{
	Iterator<String>* it = params->keySet(ctx)->iterator(ctx);
	while(it->hasNext(ctx))
	{
		String* key = it->next(ctx);
		if(key->equals(ConstStr::getCNST_STR_1176(), ctx))
		{
			break ;
		}
		String* source = params->get(key, ctx);
		IArrayObject<String>* tmp = source->split(ConstStr::getCNST_STR_1079(), ctx);
		if(tmp->length != 2)
		{
			continue;
		}
		ServerBreakPoint* point = (new(ctx) ServerBreakPoint(source, ctx));
		this->breakpoints->add(point, ctx);
	}
}
void SetupAllBreakPointsRequest::__cleanUp(ThreadContext* ctx){
}
}}}}}

