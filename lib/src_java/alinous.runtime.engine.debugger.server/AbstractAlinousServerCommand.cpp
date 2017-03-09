#include "include/global.h"


#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.runtime.engine.debugger.server/IServerCommand.h"
#include "alinous.runtime.engine.debugger.server/ICommandSender.h"
#include "alinous.runtime.engine.debugger.server/AbstractAlinousServerCommand.h"

namespace alinous {namespace runtime {namespace engine {namespace debugger {namespace server {





bool AbstractAlinousServerCommand::__init_done = __init_static_variables();
bool AbstractAlinousServerCommand::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AbstractAlinousServerCommand", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AbstractAlinousServerCommand::AbstractAlinousServerCommand(long long threadId, ThreadContext* ctx) throw()  : IObject(ctx), IServerCommand(ctx), threadId(0)
{
	this->threadId = threadId;
}
void AbstractAlinousServerCommand::__construct_impl(long long threadId, ThreadContext* ctx) throw() 
{
	this->threadId = threadId;
}
 AbstractAlinousServerCommand::~AbstractAlinousServerCommand() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AbstractAlinousServerCommand::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"AbstractAlinousServerCommand", L"~AbstractAlinousServerCommand");
	if(!prepare){
		return;
	}
}
long long AbstractAlinousServerCommand::getThreadId(ThreadContext* ctx) throw() 
{
	return this->threadId;
}
void AbstractAlinousServerCommand::sendCommand(ICommandSender* notifier, ScriptMachine* context, ThreadContext* ctx)
{
	notifier->debugOut(ConstStr::getCNST_STR_1311()->clone(ctx)->append(this->toString(ctx), ctx), ctx);
	notifier->sendCommand(this, context, ctx);
}
bool AbstractAlinousServerCommand::containsThread(long long threadId, List<IServerCommand>* needfinish, bool remove, ThreadContext* ctx) throw() 
{
	bool retvalue = false;
	Iterator<IServerCommand>* it = needfinish->iterator(ctx);
	while(it->hasNext(ctx))
	{
		IServerCommand* cmd = it->next(ctx);
		if(cmd->getThreadId(ctx) == threadId)
		{
			if(remove)
			{
				it->remove(ctx);
			}
			retvalue = true;
		}
	}
	return retvalue;
}
void AbstractAlinousServerCommand::__cleanUp(ThreadContext* ctx){
}
}}}}}

