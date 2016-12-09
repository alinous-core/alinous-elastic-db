#include "includes.h"


namespace alinous {namespace server {namespace http {





bool HttpHeaderProcessor::__init_done = __init_static_variables();
bool HttpHeaderProcessor::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"HttpHeaderProcessor", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 HttpHeaderProcessor::HttpHeaderProcessor(InputStream* stream, ThreadContext* ctx) throw()  : IObject(ctx), params(nullptr), stream(nullptr), requestHeaders(GCUtils<HashMap<String,String> >::ins(this, (new(ctx) HashMap<String,String>(ctx)), ctx, __FILEW__, __LINE__, L"")), protocol(nullptr), path(nullptr), method(nullptr)
{
	__GC_MV(this, &(this->stream), stream, InputStream);
}
void HttpHeaderProcessor::__construct_impl(InputStream* stream, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->stream), stream, InputStream);
}
 HttpHeaderProcessor::~HttpHeaderProcessor() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void HttpHeaderProcessor::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"HttpHeaderProcessor", L"~HttpHeaderProcessor");
	__e_obj1.add(this->params, this);
	params = nullptr;
	__e_obj1.add(this->stream, this);
	stream = nullptr;
	__e_obj1.add(this->requestHeaders, this);
	requestHeaders = nullptr;
	__e_obj1.add(this->protocol, this);
	protocol = nullptr;
	__e_obj1.add(this->path, this);
	path = nullptr;
	__e_obj1.add(this->method, this);
	method = nullptr;
	if(!prepare){
		return;
	}
}
void HttpHeaderProcessor::process(ThreadContext* ctx)
{
	GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"HttpHeaderProcessor", L"process");
	String* line = readLine(this->stream, ctx);
	parseFirstLine(line, ctx);
	while(true)
	{
		line = readLine(this->stream, ctx);
		if(line->length(ctx) == 0)
		{
			break ;
		}
		parseLine(line, ctx);
	}
	if(this->method->equals(ConstStr::getCNST_STR_3442(), ctx))
	{
		parseGetParams(ctx);
	}
	String* contentLength = this->requestHeaders->get(ConstStr::getCNST_STR_1786(), ctx);
	if(contentLength == nullptr)
	{
		return;
	}
	int length = 0;
	{
		try
		{
			length = Integer::parseInt(contentLength, ctx);
		}
		catch(NumberFormatException* e)
		{
			throw (new(ctx) AlinousException(ConstStr::getCNST_STR_3443(), e, ctx));
		}
	}
	String* contentType = this->requestHeaders->get(ConstStr::getCNST_STR_3435(), ctx);
	if(contentType->startsWith(ConstStr::getCNST_STR_3444(), ctx))
	{
		HttpParamHandler::postMimeParams(this->stream, length, contentType, ctx);
	}
		else 
	{
		GCUtils<HashMap<String,AbstractHttpParameter> >::mv(this, &(this->params), HttpParamHandler::postParams(this->stream, length, ConstStr::getCNST_STR_1047(), ctx), ctx);
	}
}
HashMap<String,String>* HttpHeaderProcessor::getRequestHeaders(ThreadContext* ctx) throw() 
{
	return requestHeaders;
}
String* HttpHeaderProcessor::getProtocol(ThreadContext* ctx) throw() 
{
	return protocol;
}
String* HttpHeaderProcessor::getPath(ThreadContext* ctx) throw() 
{
	return path;
}
String* HttpHeaderProcessor::getMethod(ThreadContext* ctx) throw() 
{
	return method;
}
void HttpHeaderProcessor::parseGetParams(ThreadContext* ctx)
{
	int index = this->path->indexOf(ConstStr::getCNST_STR_525(), ctx);
	if(index < 0 || index == this->path->length(ctx) - 1)
	{
		if(index > 0)
		{
			__GC_MV(this, &(this->path), this->path->substring(0, index, ctx), String);
		}
		return;
	}
	String* paramPart = this->path->substring(index + 1, ctx);
	__GC_MV(this, &(this->path), this->path->substring(0, index, ctx), String);
	GCUtils<HashMap<String,AbstractHttpParameter> >::mv(this, &(this->params), PostUrlEncodedReader::parseString(paramPart, ConstStr::getCNST_STR_1047(), ctx), ctx);
}
void HttpHeaderProcessor::parseFirstLine(String* line, ThreadContext* ctx)
{
	int pos = line->indexOf((int)L' ', ctx);
	if(pos < 0)
	{
		throw (new(ctx) AlinousException(ConstStr::getCNST_STR_3445(), ctx));
	}
	int beginIndex = 0;
	__GC_MV(this, &(this->method), line->substring(beginIndex, pos, ctx)->toUpperCase(ctx), String);
	beginIndex = pos + 1;
	pos = line->indexOf((int)L' ', beginIndex, ctx);
	if(pos < 0)
	{
		throw (new(ctx) AlinousException(ConstStr::getCNST_STR_3446(), ctx));
	}
	__GC_MV(this, &(this->path), line->substring(beginIndex, pos, ctx), String);
	beginIndex = pos + 1;
	pos = line->length(ctx);
	if(pos <= beginIndex)
	{
		throw (new(ctx) AlinousException(ConstStr::getCNST_STR_3447(), ctx));
	}
	__GC_MV(this, &(this->protocol), line->substring(beginIndex, ctx), String);
}
void HttpHeaderProcessor::parseLine(String* line, ThreadContext* ctx)
{
	int splitter = line->indexOf((int)L':', ctx);
	if(splitter < 0)
	{
		throw (new(ctx) AlinousException(ConstStr::getCNST_STR_3448(), ctx));
	}
	String* header = line->substring(0, splitter, ctx);
	String* value = line->substring(splitter + 1, line->length(ctx), ctx)->trim(ctx);
	this->requestHeaders->put(header, value, ctx);
}
String* HttpHeaderProcessor::readLine(InputStream* inStream, ThreadContext* ctx)
{
	wchar_t ch = 0;
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	do
	{
		int value = inStream->read(ctx);
		if(value < 0)
		{
			break ;
		}
		ch = ((wchar_t)value);
		if(ch != L'\n' && ch != L'\r')
		{
			buff->append(ch, ctx);
		}
	}
	while(ch != L'\n' && ch != L'\0');
	return buff->toString(ctx);
}
}}}

