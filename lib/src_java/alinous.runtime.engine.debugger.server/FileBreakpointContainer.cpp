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





bool FileBreakpointContainer::__init_done = __init_static_variables();
bool FileBreakpointContainer::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"FileBreakpointContainer", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 FileBreakpointContainer::FileBreakpointContainer(ThreadContext* ctx) throw()  : IObject(ctx), breakpoints(GCUtils<List<ServerBreakPoint> >::ins(this, (new(ctx) ArrayList<ServerBreakPoint>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
}
void FileBreakpointContainer::__construct_impl(ThreadContext* ctx) throw() 
{
}
 FileBreakpointContainer::~FileBreakpointContainer() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void FileBreakpointContainer::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"FileBreakpointContainer", L"~FileBreakpointContainer");
	__e_obj1.add(this->breakpoints, this);
	breakpoints = nullptr;
	if(!prepare){
		return;
	}
}
void FileBreakpointContainer::addBreakpoint(ServerBreakPoint* breakpoint, ThreadContext* ctx) throw() 
{
	this->breakpoints->add(breakpoint, ctx);
}
void FileBreakpointContainer::removeBreakpoint(int line, ThreadContext* ctx) throw() 
{
	Iterator<ServerBreakPoint>* it = this->breakpoints->iterator(ctx);
	while(it->hasNext(ctx))
	{
		ServerBreakPoint* breakPoint = it->next(ctx);
		if(breakPoint->getLine(ctx) == line)
		{
			it->remove(ctx);
		}
	}
}
Iterator<ServerBreakPoint>* FileBreakpointContainer::iterator(ThreadContext* ctx) throw() 
{
	return this->breakpoints->iterator(ctx);
}
void FileBreakpointContainer::clear(ThreadContext* ctx) throw() 
{
	this->breakpoints->clear(ctx);
}
String* FileBreakpointContainer::toString(ThreadContext* ctx) throw() 
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	Iterator<ServerBreakPoint>* it = this->breakpoints->iterator(ctx);
	while(it->hasNext(ctx))
	{
		ServerBreakPoint* p = it->next(ctx);
		buff->append(p->getFilePath(ctx), ctx);
		buff->append(ConstStr::getCNST_STR_381(), ctx);
		buff->append(p->getLine(ctx), ctx);
		buff->append(ConstStr::getCNST_STR_1214(), ctx);
	}
	return buff->toString(ctx);
}
void FileBreakpointContainer::__cleanUp(ThreadContext* ctx){
}
}}}}}

