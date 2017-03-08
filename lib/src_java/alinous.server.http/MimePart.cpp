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





bool MimePart::__init_done = __init_static_variables();
bool MimePart::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"MimePart", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 MimePart::MimePart(ThreadContext* ctx) throw()  : IObject(ctx), rawData(nullptr), headers(GCUtils<ArrayList<MimeHeader> >::ins(this, (new(ctx) ArrayList<MimeHeader>(ctx)), ctx, __FILEW__, __LINE__, L"")), descHeader(nullptr), contentType(nullptr)
{
}
void MimePart::__construct_impl(ThreadContext* ctx) throw() 
{
}
 MimePart::~MimePart() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void MimePart::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"MimePart", L"~MimePart");
	__e_obj1.add(this->rawData, this);
	rawData = nullptr;
	__e_obj1.add(this->headers, this);
	headers = nullptr;
	__e_obj1.add(this->descHeader, this);
	descHeader = nullptr;
	__e_obj1.add(this->contentType, this);
	contentType = nullptr;
	if(!prepare){
		return;
	}
}
void MimePart::addHeader(MimeHeader* header, ThreadContext* ctx) throw() 
{
	switch(header->getHeaderType(ctx)) {
	case MimeHeader::TYPE_CONTENT_DESCRIPTION:
		__GC_MV(this, &(this->descHeader), header, MimeHeader);
		break ;
	case MimeHeader::TYPE_CONTENT_TYPE:
		__GC_MV(this, &(this->contentType), header, MimeHeader);
	default:
		break ;
	}
	this->headers->add(header, ctx);
}
bool MimePart::isFormText(ThreadContext* ctx) throw() 
{
	return this->descHeader != nullptr && this->descHeader->getFilename(ctx) == nullptr;
}
MimeHeader* MimePart::getDescHeader(ThreadContext* ctx) throw() 
{
	return descHeader;
}
MimeHeader* MimePart::getContentType(ThreadContext* ctx) throw() 
{
	return contentType;
}
void MimePart::__cleanUp(ThreadContext* ctx){
}
}}}

