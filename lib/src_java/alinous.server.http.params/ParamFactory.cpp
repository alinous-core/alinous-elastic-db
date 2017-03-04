#include "include/global.h"


#include "alinous.server.http.params/AbstractHttpParameter.h"
#include "alinous.server.http.params/HttpArrayParameter.h"
#include "alinous.server.http.params/HttpUploadParameter.h"
#include "org.alinous.charset/CharsetDecoder.h"
#include "alinous.net/URLDecoder.h"
#include "alinous.server.http.params/HttpParameter.h"
#include "alinous.server.http.params/ParamFactory.h"

namespace alinous {namespace server {namespace http {namespace params {





bool ParamFactory::__init_done = __init_static_variables();
bool ParamFactory::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ParamFactory", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ParamFactory::~ParamFactory() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ParamFactory::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
AbstractHttpParameter* ParamFactory::getParam(String* enckey, String* encvalue, String* encode, ThreadContext* ctx)
{
	String* key = URLDecoder::decode(enckey, encode, ctx);
	int index = key->indexOf(ConstStr::getCNST_STR_1000(), ctx);
	if(key->endsWith(ConstStr::getCNST_STR_564(), ctx) && index > 0)
	{
		String* name = key->substring(0, index, ctx);
		ArrayList<String>* values = split(encvalue, ConstStr::getCNST_STR_888(), encode, ctx);
		return (new(ctx) HttpArrayParameter(name, values, ctx));
	}
	String* value = URLDecoder::decode(encvalue, encode, ctx);
	return (new(ctx) HttpParameter(key, value, ctx));
}
ArrayList<String>* ParamFactory::split(String* content, String* ch, String* encode, ThreadContext* ctx)
{
	ArrayList<String>* list = (new(ctx) ArrayList<String>(ctx));
	int index = 0;
	while(true)
	{
		int pos = content->indexOf(ch, ctx);
		if(pos < 0)
		{
			String* param = content->substring(index, content->length(ctx), ctx);
			param = URLDecoder::decode(param, encode, ctx);
			list->add(param, ctx);
			break ;
		}
				else 
		{
			String* param = content->substring(index, pos, ctx);
			param = URLDecoder::decode(param, encode, ctx);
			list->add(param, ctx);
			index = pos + 1;
		}
	}
	return list;
}
}}}}

