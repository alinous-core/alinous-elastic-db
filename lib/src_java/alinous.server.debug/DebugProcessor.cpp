#include "includes.h"


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
			binstream = (new(ctx) BinaryContentByteStream(strXml->getBytes(ConstStr::getCNST_STR_1100(), ctx), ctx));
		}
		catch(Throwable* e)
		{
			e->printStackTrace(ctx);
		}
	}
	System::out->println(ConstStr::getCNST_STR_3506(), ctx);
	System::out->println(strXml, ctx);
	return binstream;
}
}}}

