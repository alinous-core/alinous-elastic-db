#include "include/global.h"


#include "alinous.server.http/MimeHeader.h"
#include "alinous.server.http/MimePart.h"
#include "alinous.server.http/MimeFormParameterDecoder.h"
#include "alinous.system/AlinousException.h"
#include "alinous.http.client/HttpRequestHeaders.h"
#include "alinous.http.client/HttpClient.h"
#include "alinous.lock/LockObject.h"
#include "alinous.runtime.parallel/ThreadPool.h"
#include "alinous.runtime.parallel/IThreadAction.h"
#include "alinous.runtime.parallel/AlinousThread.h"
#include "alinous.server.http.params/AbstractHttpParameter.h"
#include "alinous.server.http/HttpHeaderProcessor.h"
#include "alinous.system/AlinousCore.h"
#include "alinous.server/AlinousWebContentProcessor.h"
#include "alinous.server.http/IContentByteStream.h"
#include "alinous.server.http/ProcessRequestAction.h"
#include "alinous.server.http/AlinousHttpServer.h"
#include "alinous.server.http.params/HttpArrayParameter.h"
#include "alinous.server.http.params/HttpParameter.h"
#include "alinous.server.http.params/ParamFactory.h"
#include "alinous.server.http/PostUrlEncodedReader.h"
#include "alinous.server.http/HttpParamHandler.h"

namespace alinous {namespace server {namespace http {





bool PostUrlEncodedReader::__init_done = __init_static_variables();
bool PostUrlEncodedReader::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"PostUrlEncodedReader", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 PostUrlEncodedReader::PostUrlEncodedReader(InputStream* inStream, int contentLength, ThreadContext* ctx) throw()  : IObject(ctx), inStream(nullptr), contentLength(0)
{
	__GC_MV(this, &(this->inStream), inStream, InputStream);
	this->contentLength = contentLength;
}
void PostUrlEncodedReader::__construct_impl(InputStream* inStream, int contentLength, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->inStream), inStream, InputStream);
	this->contentLength = contentLength;
}
 PostUrlEncodedReader::~PostUrlEncodedReader() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void PostUrlEncodedReader::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"PostUrlEncodedReader", L"~PostUrlEncodedReader");
	__e_obj1.add(this->inStream, this);
	inStream = nullptr;
	if(!prepare){
		return;
	}
}
HashMap<String,AbstractHttpParameter>* PostUrlEncodedReader::parse(String* encode, ThreadContext* ctx)
{
	IArrayObjectPrimitive<char>* buff = ArrayAllocatorPrimitive<char>::allocatep(ctx, this->contentLength);
	this->inStream->read(buff, ctx);
	String* content = (new(ctx) String(buff, ConstStr::getCNST_STR_955(), ctx));
	return parseString(content, encode, ctx);
}
HashMap<String,AbstractHttpParameter>* PostUrlEncodedReader::parseString(String* content, String* encode, ThreadContext* ctx)
{
	HashMap<String,AbstractHttpParameter>* params = (new(ctx) HashMap<String,AbstractHttpParameter>(ctx));
	ArrayList<String>* list = split(content, ConstStr::getCNST_STR_1061(), ctx);
	int maxLoop = list->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		String* kv = list->get(i, ctx);
		ArrayList<String>* kvParam = split(kv, ConstStr::getCNST_STR_1140(), ctx);
		if(kvParam->size(ctx) >= 2)
		{
			AbstractHttpParameter* p = ParamFactory::getParam(kvParam->get(0, ctx), kvParam->get(1, ctx), encode, ctx);
			putParam(params, p, ctx);
		}
				else 
		{
			AbstractHttpParameter* p = ParamFactory::getParam(kvParam->get(0, ctx), ConstStr::getCNST_STR_4(), encode, ctx);
			putParam(params, p, ctx);
		}
	}
	return params;
}
void PostUrlEncodedReader::putParam(HashMap<String,AbstractHttpParameter>* params, AbstractHttpParameter* p, ThreadContext* ctx) throw() 
{
	String* name = p->getName(ctx);
	AbstractHttpParameter* lastParam = nullptr;
	switch(p->paramType) {
	case AbstractHttpParameter::TYPE_ARRAY_PARAM:
		lastParam = params->get(name, ctx);
		if(lastParam == nullptr)
		{
			params->put(name, p, ctx);
		}
				else 
		{
			switch(lastParam->paramType) {
			case AbstractHttpParameter::TYPE_ARRAY_PARAM:
				{
					HttpArrayParameter* aparam = static_cast<HttpArrayParameter*>(lastParam);
					aparam->addParam(p, ctx);
					break ;
				}
			case AbstractHttpParameter::TYPE_NORMAL_PARAM:
			case AbstractHttpParameter::TYPE_FILE_PARAM:
				{
					HttpArrayParameter* parray = static_cast<HttpArrayParameter*>(p);
					parray->addParam(lastParam, ctx);
					params->put(name, p, ctx);
					break ;
				}
			default:
				break ;
			}
		}
		break ;
	case AbstractHttpParameter::TYPE_FILE_PARAM:
		break ;
	default:
		params->put(name, p, ctx);
		break ;
	}
}
ArrayList<String>* PostUrlEncodedReader::split(String* content, String* ch, ThreadContext* ctx) throw() 
{
	ArrayList<String>* list = (new(ctx) ArrayList<String>(ctx));
	int index = 0;
	while(true)
	{
		int pos = content->indexOf(ch, index, ctx);
		if(pos < 0)
		{
			String* param = content->substring(index, content->length(ctx), ctx);
			list->add(param, ctx);
			break ;
		}
				else 
		{
			String* param = content->substring(index, pos, ctx);
			list->add(param, ctx);
			index = pos + 1;
		}
	}
	return list;
}
void PostUrlEncodedReader::__cleanUp(ThreadContext* ctx){
}
}}}

