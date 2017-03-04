#include "include/global.h"


#include "alinous.net/UnknownHostException.h"
#include "java.io/ByteArrayOutputStream.h"
#include "alinous.http.client/HttpRequestHeaders.h"
#include "alinous.http.client/HttpClient.h"
#include "alinous.http.client/HttpsClient.h"

namespace alinous {namespace http {namespace client {





bool HttpsClient::__init_done = __init_static_variables();
bool HttpsClient::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"HttpsClient", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 HttpsClient::~HttpsClient() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void HttpsClient::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	HttpClient::__releaseRegerences(true, ctx);
}
void HttpsClient::connect(String* host, int port, ThreadContext* ctx)
{
	__GC_MV(this, &(this->socket), AlinousSSLSocketFactory::createSocket(host, port, ctx), AlinousSocket);
}
}}}

