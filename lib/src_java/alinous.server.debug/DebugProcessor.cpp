#include "include/global.h"


#include "alinous.system.config/AlinousConfig.h"
#include "alinous.server.debug/DebugConfigLoader.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile/IStatement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.server.http.params/AbstractHttpParameter.h"
#include "alinous.server.http.params/HttpParameter.h"
#include "alinous.system/AlinousCore.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile/Token.h"
#include "alinous.lock/LockObject.h"
#include "alinous.runtime.engine.debugger.server/ServerBreakPoint.h"
#include "alinous.runtime.engine.debugger.server/FileBreakpointContainer.h"
#include "alinous.runtime.engine.debugger/DebugThread.h"
#include "alinous.runtime.engine.debugger.server/IDebuggerOperation.h"
#include "alinous.runtime.engine.debugger.server/ICommandSender.h"
#include "alinous.runtime.engine.debugger/AlinousDebugEventNotifier.h"
#include "java.lang/Number.h"
#include "java.lang/Comparable.h"
#include "java.lang/Long.h"
#include "alinous.runtime.engine.debugger/AlinousScriptDebugger.h"
#include "alinous.runtime.engine.debugger/AlinousServerDebugHttpResponse.h"
#include "alinous.runtime.engine.debugger.client/IClientRequest.h"
#include "alinous.runtime.engine.debugger.client/ClientRequestFactory.h"
#include "alinous.server.http/IContentByteStream.h"
#include "alinous.server/BinaryContentByteStream.h"
#include "alinous.server.http/HttpHeaderProcessor.h"
#include "alinous.server.debug/DebugProcessor.h"

namespace alinous {namespace server {namespace debug {





bool DebugProcessor::__init_done = __init_static_variables();
bool DebugProcessor::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DebugProcessor", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 DebugProcessor::DebugProcessor(ThreadContext* ctx) throw()  : IObject(ctx)
{
}
void DebugProcessor::__construct_impl(ThreadContext* ctx) throw() 
{
}
 DebugProcessor::~DebugProcessor() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void DebugProcessor::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
BinaryContentByteStream* DebugProcessor::process(AlinousCore* core, HttpHeaderProcessor* request, ThreadContext* ctx) throw() 
{
	AlinousScriptDebugger* debugManager = core->getDebugger(ctx);
	Map<String,String>* params = (new(ctx) HashMap<String,String>(ctx));
	if(request->params != nullptr)
	{
		Iterator<String>* it = request->params->keySet(ctx)->iterator(ctx);
		while(it->hasNext(ctx))
		{
			String* key = it->next(ctx);
			AbstractHttpParameter* param = request->params->get(key, ctx);
			if(param->paramType == AbstractHttpParameter::TYPE_NORMAL_PARAM)
			{
				HttpParameter* pa = static_cast<HttpParameter*>(param);
				params->put(pa->name, pa->value, ctx);
			}
		}
	}
	IClientRequest* requestCommand = ClientRequestFactory::createRequest(params, ctx);
	if(requestCommand == nullptr)
	{
		requestCommand = ClientRequestFactory::createDefault(ctx);
	}
	AlinousServerDebugHttpResponse* responce = requestCommand->executeRequest(debugManager, ctx);
	String* strXml = nullptr;
	BinaryContentByteStream* binstream = nullptr;
	{
		try
		{
			long long hotThread = core->getDebugger(ctx)->getHotThreadId(ctx);
			responce->setHotThread(hotThread, ctx);
			strXml = responce->exportAsXml(ctx);
			binstream = (new(ctx) BinaryContentByteStream(strXml->getBytes(ConstStr::getCNST_STR_1106(), ctx), ctx));
		}
		catch(Throwable* e)
		{
			e->printStackTrace(ctx);
		}
	}
	System::out->println(ConstStr::getCNST_STR_3536(), ctx);
	System::out->println(strXml, ctx);
	return binstream;
}
void DebugProcessor::__cleanUp(ThreadContext* ctx){
}
}}}

