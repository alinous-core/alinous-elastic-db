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
#include "alinous.server.http/PostUrlEncodedReader.h"
#include "alinous.server.http/HttpParamHandler.h"

namespace alinous {namespace server {namespace http {





bool MimeFormParameterDecoder::__init_done = __init_static_variables();
bool MimeFormParameterDecoder::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"MimeFormParameterDecoder", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 MimeFormParameterDecoder::MimeFormParameterDecoder(ThreadContext* ctx) throw()  : IObject(ctx), contentLength(0), boundary(nullptr), boundaryEnd(nullptr), readBytes(0), inStream(nullptr), parts(GCUtils<ArrayList<MimePart> >::ins(this, (new(ctx) ArrayList<MimePart>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
}
void MimeFormParameterDecoder::__construct_impl(ThreadContext* ctx) throw() 
{
}
 MimeFormParameterDecoder::~MimeFormParameterDecoder() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void MimeFormParameterDecoder::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"MimeFormParameterDecoder", L"~MimeFormParameterDecoder");
	__e_obj1.add(this->boundary, this);
	boundary = nullptr;
	__e_obj1.add(this->boundaryEnd, this);
	boundaryEnd = nullptr;
	__e_obj1.add(this->inStream, this);
	inStream = nullptr;
	__e_obj1.add(this->parts, this);
	parts = nullptr;
	if(!prepare){
		return;
	}
}
void MimeFormParameterDecoder::decode(InputStream* inStream, String* boundary, int contentLength, ThreadContext* ctx)
{
	__GC_MV(this, &(this->inStream), inStream, InputStream);
	this->contentLength = contentLength;
	__GC_MV(this, &(this->boundary), ConstStr::getCNST_STR_1784()->clone(ctx)->append(boundary, ctx), String);
	__GC_MV(this, &(this->boundaryEnd), boundary->clone(ctx)->append(ConstStr::getCNST_STR_1784(), ctx), String);
	this->readBytes = 0;
	String* line = readHeaderLine(ctx);
	if(!line->equals(this->boundary, ctx))
	{
		throw (new(ctx) IOException(ConstStr::getCNST_STR_3545(), ctx));
	}
	do
	{
		handleMimePart(ctx);
	}
	while(!isEof(ctx));
}
ArrayList<MimePart>* MimeFormParameterDecoder::getParts(ThreadContext* ctx) throw() 
{
	return parts;
}
void MimeFormParameterDecoder::handleMimePart(ThreadContext* ctx)
{
	MimePart* part = (new(ctx) MimePart(ctx));
	String* line = nullptr;
	do
	{
		line = readHeaderLine(ctx);
		if(line->length(ctx) > 0)
		{
			MimeHeader* header = (new(ctx) MimeHeader(ctx))->init(line, ctx);
			part->addHeader(header, ctx);
		}
				else 
		{
			break ;
		}
	}
	while(!isEof(ctx));
	if(!part->isFormText(ctx))
	{
		readBinaryFileData(part, ctx);
		return;
	}
	StringBuilder* buff = (new(ctx) StringBuilder(ctx));
	do
	{
		line = readHeaderLine(ctx);
		if(line->equals(this->boundary, ctx) || line->equals(this->boundaryEnd, ctx))
		{
			break ;
		}
		buff->append(line, ctx);
	}
	while(!isEof(ctx));
	__GC_MV(part, &(part->rawData), buff->toString(ctx), String);
	this->parts->add(part, ctx);
}
void MimeFormParameterDecoder::readBinaryFileData(MimePart* part, ThreadContext* ctx)
{
	char b = 0;
	do
	{
		int ivalue = this->inStream->read(ctx);
		if(ivalue < 0)
		{
			break ;
		}
		b = ((char)ivalue);
		this->readBytes ++ ;
		if(b == ((char)L'\n'))
		{
			break ;
		}
	}
	while(!isEof(ctx));
}
String* MimeFormParameterDecoder::readHeaderLine(ThreadContext* ctx)
{
	wchar_t ch = 0;
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	do
	{
		int ivalue = this->inStream->read(ctx);
		if(ivalue < 0)
		{
			break ;
		}
		ch = ((wchar_t)ivalue);
		this->readBytes ++ ;
		if(ch != L'\n' && ch != L'\r')
		{
			buff->append(ch, ctx);
		}
	}
	while(ch != L'\n' && ch != L'\0' && !isEof(ctx));
	return buff->toString(ctx);
}
bool MimeFormParameterDecoder::isEof(ThreadContext* ctx) throw() 
{
	return readBytes >= this->contentLength;
}
void MimeFormParameterDecoder::__cleanUp(ThreadContext* ctx){
}
}}}

