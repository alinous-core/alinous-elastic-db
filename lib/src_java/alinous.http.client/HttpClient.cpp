#include "includes.h"


namespace alinous {namespace http {namespace client {





bool HttpClient::__init_done = __init_static_variables();
bool HttpClient::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"HttpClient", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 HttpClient::HttpClient(ThreadContext* ctx) throw()  : IObject(ctx), socket(nullptr), responseHeader(GCUtils<HashMap<String,String> >::ins(this, (new(ctx) HashMap<String,String>(ctx)), ctx, __FILEW__, __LINE__, L"")), chunkSize(0), buf(nullptr), resultStream(nullptr)
{
	__GC_MV(this, &(this->buf), ArrayAllocatorPrimitive<char>::allocatep(ctx, 1024), IArrayObjectPrimitive<char>);
}
void HttpClient::__construct_impl(ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->buf), ArrayAllocatorPrimitive<char>::allocatep(ctx, 1024), IArrayObjectPrimitive<char>);
}
 HttpClient::~HttpClient() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void HttpClient::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"HttpClient", L"~HttpClient");
	__e_obj1.add(this->socket, this);
	socket = nullptr;
	__e_obj1.add(this->responseHeader, this);
	responseHeader = nullptr;
	__e_obj1.add(this->buf, this);
	buf = nullptr;
	__e_obj1.add(this->resultStream, this);
	resultStream = nullptr;
	if(!prepare){
		return;
	}
}
void HttpClient::get(String* host, int port, String* path, HttpRequestHeaders* headers, ThreadContext* ctx)
{
	connect(host, port, ctx);
	OutputStream* out = socket->getOutputStream(ctx);
	OutputStreamWriter* writer = (new(ctx) OutputStreamWriter(out, ConstStr::getCNST_STR_1101(), ctx));
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	buff->append(ConstStr::getCNST_STR_1862(), ctx)->append(path, ctx)->append(ConstStr::getCNST_STR_1863(), ctx);
	writer->write(buff->toString(ctx), ctx);
	buff->setLength(0, ctx);
	buff->append(ConstStr::getCNST_STR_1864(), ctx)->append(host, ctx)->append(ConstStr::getCNST_STR_1860(), ctx);
	writer->write(buff->toString(ctx), ctx);
	buff->setLength(0, ctx);
	headers->writeHeader(buff, ctx);
	writer->write(buff->toString(ctx), ctx);
	writer->append(ConstStr::getCNST_STR_1860(), ctx)->flush(ctx);
	InputStream* inStream = this->socket->getInputStream(ctx);
	parseHeader(inStream, ctx);
	__GC_MV(this, &(this->resultStream), (new(ctx) ByteArrayOutputStream(2048, ctx)), ByteArrayOutputStream);
	String* transferEncoding = this->responseHeader->get(ConstStr::getCNST_STR_1865(), ctx);
	String* contentLength = this->responseHeader->get(ConstStr::getCNST_STR_1866(), ctx);
	if(transferEncoding != nullptr && transferEncoding->equals(ConstStr::getCNST_STR_1867(), ctx))
	{
		readChunkedContent(inStream, ctx);
	}
		else 
	{
		if(contentLength != nullptr)
		{
			readByContentLength(contentLength, inStream, ctx);
		}
	}
}
void HttpClient::dispose(ThreadContext* ctx) throw() 
{
	{
		try
		{
			this->resultStream->close(ctx);
		}
		catch(IOException* e1)
		{
			e1->printStackTrace(ctx);
		}
	}
	{
		try
		{
			this->socket->close(ctx);
			__GC_MV(this, &(this->socket), nullptr, AlinousSocket);
		}
		catch(IOException* e)
		{
			e->printStackTrace(ctx);
		}
	}
}
HashMap<String,String>* HttpClient::getResponseHeader(ThreadContext* ctx) throw() 
{
	return responseHeader;
}
ByteArrayOutputStream* HttpClient::getResultStream(ThreadContext* ctx) throw() 
{
	return resultStream;
}
void HttpClient::connect(String* host, int port, ThreadContext* ctx)
{
	__GC_MV(this, &(this->socket), (new(ctx) AlinousSocket(host, port, ctx))->init(ctx), AlinousSocket);
}
void HttpClient::readByContentLength(String* contentLength, InputStream* inStream, ThreadContext* ctx)
{
	{
		try
		{
			this->chunkSize = Integer::valueOf(contentLength, 10, ctx)->intValue(ctx);
			if(this->chunkSize == 0)
			{
				return;
			}
			readWhileChunkSize(inStream, ctx);
		}
		catch(NumberFormatException* e)
		{
			throw (new(ctx) AlinousException(ConstStr::getCNST_STR_1868(), e, ctx));
		}
	}
}
void HttpClient::readChunkedContent(InputStream* inStream, ThreadContext* ctx)
{
	do
	{
		String* chunckSizeStr = readLine(inStream, ctx);
		{
			try
			{
				this->chunkSize = Integer::valueOf(chunckSizeStr, 16, ctx)->intValue(ctx);
				if(this->chunkSize == 0)
				{
					break ;
				}
				readWhileChunkSize(inStream, ctx);
				readLine(inStream, ctx);
			}
			catch(NumberFormatException* e)
			{
				throw (new(ctx) AlinousException(ConstStr::getCNST_STR_1868(), e, ctx));
			}
		}
	}
	while(this->chunkSize > 0);
}
void HttpClient::readWhileChunkSize(InputStream* inStream, ThreadContext* ctx)
{
	int nread = 0;
	int total = 0;
	do
	{
		int remain = this->chunkSize - total;
		remain = remain > this->buf->length ? this->buf->length : remain;
		nread = inStream->read(this->buf, 0, remain, ctx);
		if(nread < 0)
		{
			break ;
		}
		this->resultStream->write(this->buf, 0, nread, ctx);
		total += nread;
	}
	while(total < this->chunkSize);
}
void HttpClient::parseHeader(InputStream* inStream, ThreadContext* ctx)
{
	String* line = 0;
	do
	{
		line = readLine(inStream, ctx);
		if(line->length(ctx) == 0)
		{
			break ;
		}
				else 
		{
			analyseHeaderLine(line, ctx);
		}
	}
	while(true);
}
void HttpClient::analyseHeaderLine(String* line, ThreadContext* ctx)
{
	int splitter = line->indexOf((int)L':', ctx);
	if(splitter < 0)
	{
		IArrayObject<String>* codes = line->split(ConstStr::getCNST_STR_380(), ctx);
		if(codes->length < 3)
		{
			throw (new(ctx) AlinousException(ConstStr::getCNST_STR_1869(), ctx));
		}
		return;
	}
	String* header = line->substring(0, splitter, ctx);
	String* value = line->substring(splitter + 1, line->length(ctx), ctx)->trim(ctx);
	this->responseHeader->put(header, value, ctx);
}
String* HttpClient::readLine(InputStream* inStream, ThreadContext* ctx)
{
	wchar_t ch = 0;
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	do
	{
		int ivalue = inStream->read(ctx);
		if(ivalue < 0)
		{
			break ;
		}
		ch = ((wchar_t)ivalue);
		if(ch != L'\n' && ch != L'\r')
		{
			buff->append(ch, ctx);
		}
	}
	while(ch != L'\n' && ch != L'\0');
	return buff->toString(ctx);
}
}}}

