#include "includes.h"


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
	__GC_MV(this, &(this->boundary), ConstStr::getCNST_STR_1726()->clone(ctx)->append(boundary, ctx), String);
	__GC_MV(this, &(this->boundaryEnd), boundary->clone(ctx)->append(ConstStr::getCNST_STR_1726(), ctx), String);
	this->readBytes = 0;
	String* line = readHeaderLine(ctx);
	if(!line->equals(this->boundary, ctx))
	{
		throw (new(ctx) IOException(ConstStr::getCNST_STR_3504(), ctx));
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
}}}

