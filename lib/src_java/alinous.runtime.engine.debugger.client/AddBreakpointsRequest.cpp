#include "includes.h"


namespace alinous {namespace runtime {namespace engine {namespace debugger {namespace client {





String* AddBreakpointsRequest::LINE = ConstStr::getCNST_STR_1188();
String* AddBreakpointsRequest::FILE_PATH = ConstStr::getCNST_STR_1189();
bool AddBreakpointsRequest::__init_done = __init_static_variables();
bool AddBreakpointsRequest::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AddBreakpointsRequest", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AddBreakpointsRequest::AddBreakpointsRequest(ServerBreakPoint* breakpoint, ThreadContext* ctx) throw()  : IObject(ctx), IClientRequest(ctx), breakpoint(nullptr)
{
	__GC_MV(this, &(this->breakpoint), breakpoint, ServerBreakPoint);
}
void AddBreakpointsRequest::__construct_impl(ServerBreakPoint* breakpoint, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->breakpoint), breakpoint, ServerBreakPoint);
}
 AddBreakpointsRequest::~AddBreakpointsRequest() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AddBreakpointsRequest::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"AddBreakpointsRequest", L"~AddBreakpointsRequest");
	__e_obj1.add(this->breakpoint, this);
	breakpoint = nullptr;
	if(!prepare){
		return;
	}
}
AlinousServerDebugHttpResponse* AddBreakpointsRequest::executeRequest(AlinousScriptDebugger* debugManager, ThreadContext* ctx) throw() 
{
	debugManager->addBreakPoint(this->breakpoint, ctx);
	AlinousServerDebugHttpResponse* responce = (new(ctx) AlinousServerDebugHttpResponse(0, ctx));
	return responce;
}
String* AddBreakpointsRequest::getCommand(ThreadContext* ctx) throw() 
{
	return IClientRequest::CMD_ADD_BREAKPOINTS;
}
Map<String,String>* AddBreakpointsRequest::getParamMap(ThreadContext* ctx) throw() 
{
	Map<String,String>* m = (new(ctx) HashMap<String,String>(ctx));
	m->put(LINE, Integer::toString(this->breakpoint->getLine(ctx), ctx), ctx);
	m->put(FILE_PATH, this->breakpoint->getFilePath(ctx), ctx);
	return m;
}
void AddBreakpointsRequest::importParams(Map<String,String>* params, ThreadContext* ctx) throw() 
{
	String* filePath = static_cast<String*>(params->get(FILE_PATH, ctx));
	String* strLine = static_cast<String*>(params->get(LINE, ctx));
	int line = -1;
	if(strLine != nullptr)
	{
		line = Integer::parseInt(strLine, ctx);
	}
	__GC_MV(this, &(this->breakpoint), (new(ctx) ServerBreakPoint(filePath, line, ctx)), ServerBreakPoint);
}
}}}}}

