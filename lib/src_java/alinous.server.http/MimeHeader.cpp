#include "includes.h"


namespace alinous {namespace server {namespace http {





constexpr const int MimeHeader::TYPE_CONTENT_DESCRIPTION;
constexpr const int MimeHeader::TYPE_CONTENT_TYPE;
String* MimeHeader::CONTENT_DESCRIPTION = ConstStr::getCNST_STR_3513();
String* MimeHeader::CONTENT_TYPE = ConstStr::getCNST_STR_3514();
bool MimeHeader::__init_done = __init_static_variables();
bool MimeHeader::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"MimeHeader", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 MimeHeader::~MimeHeader() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void MimeHeader::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"MimeHeader", L"~MimeHeader");
	__e_obj1.add(this->headerName, this);
	headerName = nullptr;
	__e_obj1.add(this->name, this);
	name = nullptr;
	__e_obj1.add(this->filename, this);
	filename = nullptr;
	__e_obj1.add(this->contentType, this);
	contentType = nullptr;
	if(!prepare){
		return;
	}
}
MimeHeader* MimeHeader::init(String* line, ThreadContext* ctx)
{
	int pos = line->indexOf((int)L':', ctx);
	if(pos < 0)
	{
		throw (new(ctx) IOException(ConstStr::getCNST_STR_3512(), ctx));
	}
	__GC_MV(this, &(this->headerName), line->substring(0, pos, ctx), String);
	pos ++ ;
	if(pos >= line->length(ctx))
	{
		throw (new(ctx) IOException(ConstStr::getCNST_STR_3512(), ctx));
	}
	String* value = line->substring(pos, line->length(ctx), ctx);
	if(this->headerName->equals(CONTENT_DESCRIPTION, ctx))
	{
		parseContentDescription(value, ctx);
	}
		else 
	{
		__GC_MV(this, &(this->contentType), value, String);
	}
	return this;
}
int MimeHeader::getHeaderType(ThreadContext* ctx) throw() 
{
	return headerType;
}
String* MimeHeader::getHeaderName(ThreadContext* ctx) throw() 
{
	return headerName;
}
String* MimeHeader::getName(ThreadContext* ctx) throw() 
{
	return name;
}
String* MimeHeader::getFilename(ThreadContext* ctx) throw() 
{
	return filename;
}
String* MimeHeader::getContentType(ThreadContext* ctx) throw() 
{
	return contentType;
}
void MimeHeader::parseContentDescription(String* value, ThreadContext* ctx)
{
	ArrayList<String>* fragments = split(value, L';', ctx);
	int size = fragments->size(ctx);
	if(size == 2)
	{
		__GC_MV(this, &(this->name), afterEq(fragments->get(1, ctx), ctx), String);
	}
		else 
	{
		if(size >= 3)
		{
			__GC_MV(this, &(this->name), stripQuate(afterEq(fragments->get(1, ctx), ctx), ctx), String);
			__GC_MV(this, &(this->filename), stripQuate(afterEq(fragments->get(2, ctx), ctx), ctx), String);
		}
	}
}
String* MimeHeader::stripQuate(String* value, ThreadContext* ctx) throw() 
{
	if(value->startsWith(ConstStr::getCNST_STR_1306(), ctx) && value->endsWith(ConstStr::getCNST_STR_1306(), ctx) && value->length(ctx) >= 2)
	{
		return value->substring(1, value->length(ctx) - 1, ctx);
	}
	return value;
}
String* MimeHeader::afterEq(String* value, ThreadContext* ctx)
{
	int idx = value->indexOf(ConstStr::getCNST_STR_1074(), ctx);
	if(idx < 0)
	{
		throw (new(ctx) IOException(ConstStr::getCNST_STR_3512(), ctx));
	}
	return value->substring(idx + 1, ctx);
}
ArrayList<String>* MimeHeader::split(String* str, wchar_t ch, ThreadContext* ctx) throw() 
{
	ArrayList<String>* list = (new(ctx) ArrayList<String>(ctx));
	int length = str->length(ctx);
	int beginpos = 0;
	int pos = 0;
	String* value = 0;
	do
	{
		pos = str->indexOf((int)ch, beginpos, ctx);
		if(pos < 0)
		{
			break ;
		}
		value = str->substring(beginpos, pos, ctx)->trim(ctx);
		beginpos = pos + 1;
		list->add(value, ctx);
	}
	while(beginpos < length);
	if(beginpos < length)
	{
		value = str->substring(beginpos, length, ctx)->trim(ctx);
		list->add(value, ctx);
	}
	return list;
}
}}}

