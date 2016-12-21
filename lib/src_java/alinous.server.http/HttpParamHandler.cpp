#include "includes.h"


namespace alinous {namespace server {namespace http {





bool HttpParamHandler::__init_done = __init_static_variables();
bool HttpParamHandler::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"HttpParamHandler", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 HttpParamHandler::~HttpParamHandler() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void HttpParamHandler::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
HashMap<String,AbstractHttpParameter>* HttpParamHandler::postParams(InputStream* inStream, int contentLength, String* encode, ThreadContext* ctx)
{
	PostUrlEncodedReader* reader = (new(ctx) PostUrlEncodedReader(inStream, contentLength, ctx));
	return reader->parse(encode, ctx);
}
void HttpParamHandler::postMimeParams(InputStream* inStream, int contentLength, String* contentType, ThreadContext* ctx)
{
	int index = contentType->indexOf(ConstStr::getCNST_STR_3457(), ctx);
	String* boundary = contentType->substring(index + 9, contentType->length(ctx), ctx);
	MimeFormParameterDecoder* decoder = (new(ctx) MimeFormParameterDecoder(ctx));
	decoder->decode(inStream, boundary, contentLength, ctx);
}
}}}

