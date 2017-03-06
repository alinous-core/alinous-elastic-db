#include "include/global.h"


#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.runtime.engine.debugger.server/ServerBreakPoint.h"
#include "alinous.runtime.engine.debugger.server/FileBreakpointContainer.h"
#include "alinous.runtime.engine.debugger.server/IServerCommand.h"
#include "alinous.runtime.engine.debugger.server/AbstractAlinousServerCommand.h"
#include "alinous.runtime.engine.debugger.server/NotifyHitBreakpoint.h"
#include "alinous.runtime.engine.debugger.server/IDebuggerOperation.h"
#include "alinous.runtime.engine.debugger.server/AbstractDebuggerOperation.h"
#include "alinous.runtime.engine.debugger.server/RunningOperation.h"
#include "alinous.runtime.engine.debugger/DebugThread.h"
#include "alinous.runtime.engine.debugger/AlinousDebugEvent.h"
#include "alinous.runtime.engine.debugger.server/NotifyThreadEndedCommand.h"
#include "alinous.runtime.engine.debugger.server/NotifyThreadStartCommand.h"
#include "alinous.runtime.engine.debugger/AlinousScriptDebugger.h"
#include "alinous.runtime.engine.debugger.server/ICommandSender.h"
#include "alinous.runtime.engine.debugger.server/NotifyStepOverFinishedCommand.h"
#include "alinous.runtime.engine.debugger.server/NotifyTerminatedCommand.h"
#include "alinous.runtime.engine.debugger.server/NotifyResumeComand.h"
#include "alinous.runtime.engine.debugger.server/NotifyExceptionThrownCommand.h"
#include "alinous.runtime.engine.debugger.server/NotifyStepInFinishedCommand.h"
#include "alinous.runtime.engine.debugger.server/StepOverOperation.h"
#include "alinous.runtime.engine.debugger.server/NotifyStepReturnFinishedCommand.h"
#include "alinous.runtime.engine.debugger.server/StepInOperation.h"
#include "alinous.runtime.engine.debugger.server/StepReturnOperation.h"
#include "alinous.runtime.engine.debugger.server/NotifyStartCommand.h"

namespace alinous {namespace runtime {namespace engine {namespace debugger {namespace server {





bool ServerBreakPoint::__init_done = __init_static_variables();
bool ServerBreakPoint::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ServerBreakPoint", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ServerBreakPoint::ServerBreakPoint(String* filePath, int line, ThreadContext* ctx) throw()  : IObject(ctx), filePath(nullptr), line(0)
{
	__GC_MV(this, &(this->filePath), filePath, String);
	this->line = line;
}
void ServerBreakPoint::__construct_impl(String* filePath, int line, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->filePath), filePath, String);
	this->line = line;
}
 ServerBreakPoint::ServerBreakPoint(String* source, ThreadContext* ctx) throw()  : IObject(ctx), filePath(nullptr), line(0)
{
	setupFromString(source, ctx);
}
void ServerBreakPoint::__construct_impl(String* source, ThreadContext* ctx) throw() 
{
	setupFromString(source, ctx);
}
 ServerBreakPoint::~ServerBreakPoint() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ServerBreakPoint::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ServerBreakPoint", L"~ServerBreakPoint");
	__e_obj1.add(this->filePath, this);
	filePath = nullptr;
	if(!prepare){
		return;
	}
}
String* ServerBreakPoint::getFilePath(ThreadContext* ctx) throw() 
{
	return filePath;
}
int ServerBreakPoint::getLine(ThreadContext* ctx) throw() 
{
	return line;
}
String* ServerBreakPoint::toString(ThreadContext* ctx) throw() 
{
	return this->filePath->clone(ctx)->append(ConstStr::getCNST_STR_1079(), ctx)->append(Integer::toString(this->line, ctx), ctx);
}
void ServerBreakPoint::setupFromString(String* source, ThreadContext* ctx) throw() 
{
	IArrayObject<String>* elements = source->split(ConstStr::getCNST_STR_1079(), ctx);
	__GC_MV(this, &(this->filePath), elements->get(0), String);
	this->line = Integer::parseInt(elements->get(1), ctx);
}
void ServerBreakPoint::__cleanUp(ThreadContext* ctx){
}
}}}}}

