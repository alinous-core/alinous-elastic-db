#include "include/global.h"


#include "alinous.runtime.engine.debugger.server/ServerBreakPoint.h"
#include "alinous.runtime.engine.debugger/AlinousScriptDebugger.h"
#include "alinous.runtime.engine.debugger/AlinousServerDebugHttpResponse.h"
#include "alinous.runtime.engine.debugger.client/IClientRequest.h"
#include "alinous.runtime.engine.debugger.client/SetupAllBreakPointsRequest.h"
#include "alinous.runtime.engine.debugger/IHttpAccessMethod.h"
#include "alinous.runtime.engine.debugger/AlinousDebugCommandSender.h"
#include "alinous.runtime.engine.debugger.client/TerminateServerRequest.h"
#include "alinous.runtime.engine.debugger.client/StatusThreadRequest.h"
#include "alinous.runtime.engine.debugger.client/ClearBreakpointsRequest.h"
#include "alinous.runtime.engine.debugger.client/AddBreakpointsRequest.h"
#include "alinous.runtime.engine.debugger.client/ResumeRequest.h"
#include "alinous.runtime.engine.debugger.client/StepOverRequest.h"
#include "alinous.runtime.engine.debugger.client/StepInRequest.h"
#include "alinous.runtime.engine.debugger.client/StepReturnRequest.h"
#include "alinous.runtime.engine.debugger.client/ClientRequestFactory.h"

namespace alinous {namespace runtime {namespace engine {namespace debugger {namespace client {





bool ClientRequestFactory::__init_done = __init_static_variables();
bool ClientRequestFactory::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ClientRequestFactory", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ClientRequestFactory::ClientRequestFactory(ThreadContext* ctx) throw()  : IObject(ctx)
{
}
void ClientRequestFactory::__construct_impl(ThreadContext* ctx) throw() 
{
}
 ClientRequestFactory::~ClientRequestFactory() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ClientRequestFactory::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
IClientRequest* ClientRequestFactory::createRequest(Map<String,String>* params, ThreadContext* ctx) throw() 
{
	String* command = params->get(AlinousDebugCommandSender::COMMAND, ctx);
	IClientRequest* retRequest = nullptr;
	if(command == nullptr)
	{
		return nullptr;
	}
		else 
	{
		if(command->equals(IClientRequest::CMD_TERMINATE, ctx))
		{
			retRequest = (new(ctx) TerminateServerRequest(ctx));
		}
				else 
		{
			if(command->equals(IClientRequest::CMD_STATUS_THREAD, ctx))
			{
				retRequest = (new(ctx) StatusThreadRequest(ctx));
			}
						else 
			{
				if(command->equals(IClientRequest::CMD_CLEAR_BREAKPOINTS, ctx))
				{
					retRequest = (new(ctx) ClearBreakpointsRequest(ctx));
				}
								else 
				{
					if(command->equals(IClientRequest::CMD_ADD_BREAKPOINTS, ctx))
					{
						retRequest = (new(ctx) AddBreakpointsRequest(ctx));
					}
										else 
					{
						if(command->equals(IClientRequest::CMD_SETUP_ALL_BREAKPOINTS, ctx))
						{
							retRequest = (new(ctx) SetupAllBreakPointsRequest(ctx));
						}
												else 
						{
							if(command->equals(IClientRequest::CMD_RESUME, ctx))
							{
								retRequest = (new(ctx) ResumeRequest(0, ctx));
							}
														else 
							{
								if(command->equals(IClientRequest::CMD_STEP_OVER, ctx))
								{
									retRequest = (new(ctx) StepOverRequest(ctx));
								}
																else 
								{
									if(command->equals(IClientRequest::CMD_STEP_IN, ctx))
									{
										retRequest = (new(ctx) StepInRequest(ctx));
									}
																		else 
									{
										if(command->equals(IClientRequest::CMD_STEP_RETURN, ctx))
										{
											retRequest = (new(ctx) StepReturnRequest(ctx));
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	if(retRequest != nullptr)
	{
		retRequest->importParams(params, ctx);
	}
	return retRequest;
}
IClientRequest* ClientRequestFactory::createDefault(ThreadContext* ctx) throw() 
{
	return (new(ctx) StatusThreadRequest(ctx));
}
void ClientRequestFactory::__cleanUp(ThreadContext* ctx){
}
}}}}}

