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
#include "alinous.db.table/DatabaseException.h"
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




bool IContentByteStream::__init_done = __init_static_variables();
bool IContentByteStream::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"IContentByteStream", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 IContentByteStream::IContentByteStream(ThreadContext* ctx) throw()  : IObject(ctx)
{
}
void IContentByteStream::__construct_impl(ThreadContext* ctx) throw() 
{
}
 IContentByteStream::~IContentByteStream() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void IContentByteStream::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
void IContentByteStream::__cleanUp(ThreadContext* ctx){
}
}}}

