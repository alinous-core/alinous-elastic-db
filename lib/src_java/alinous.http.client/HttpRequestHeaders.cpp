#include "includes.h"


namespace alinous {namespace http {namespace client {





bool HttpRequestHeaders::__init_done = __init_static_variables();
bool HttpRequestHeaders::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"HttpRequestHeaders", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 HttpRequestHeaders::~HttpRequestHeaders() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void HttpRequestHeaders::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"HttpRequestHeaders", L"~HttpRequestHeaders");
	__e_obj1.add(this->userAgent, this);
	userAgent = nullptr;
	__e_obj1.add(this->accept, this);
	accept = nullptr;
	__e_obj1.add(this->acceptLanguage, this);
	acceptLanguage = nullptr;
	__e_obj1.add(this->acceptEncoding, this);
	acceptEncoding = nullptr;
	__e_obj1.add(this->acceptCharset, this);
	acceptCharset = nullptr;
	__e_obj1.add(this->keepAlive, this);
	keepAlive = nullptr;
	__e_obj1.add(this->connection, this);
	connection = nullptr;
	__e_obj1.add(this->cookie, this);
	cookie = nullptr;
	if(!prepare){
		return;
	}
}
void HttpRequestHeaders::writeHeader(StringBuffer* buff, ThreadContext* ctx)
{
	dowrite(buff, ConstStr::getCNST_STR_1872(), this->userAgent, ctx);
	dowrite(buff, ConstStr::getCNST_STR_1873(), this->accept, ctx);
	dowrite(buff, ConstStr::getCNST_STR_1874(), this->acceptLanguage, ctx);
	dowrite(buff, ConstStr::getCNST_STR_1875(), this->acceptEncoding, ctx);
	dowrite(buff, ConstStr::getCNST_STR_1876(), this->acceptCharset, ctx);
	dowrite(buff, ConstStr::getCNST_STR_1877(), this->keepAlive, ctx);
	dowrite(buff, ConstStr::getCNST_STR_1878(), this->connection, ctx);
	dowrite(buff, ConstStr::getCNST_STR_1879(), this->cookie, ctx);
}
String* HttpRequestHeaders::getUserAgent(ThreadContext* ctx) throw() 
{
	return userAgent;
}
void HttpRequestHeaders::setUserAgent(String* userAgent, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->userAgent), userAgent, String);
}
String* HttpRequestHeaders::getAccept(ThreadContext* ctx) throw() 
{
	return accept;
}
void HttpRequestHeaders::setAccept(String* accept, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->accept), accept, String);
}
String* HttpRequestHeaders::getAcceptLanguage(ThreadContext* ctx) throw() 
{
	return acceptLanguage;
}
void HttpRequestHeaders::setAcceptLanguage(String* acceptLanguage, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->acceptLanguage), acceptLanguage, String);
}
String* HttpRequestHeaders::getAcceptEncoding(ThreadContext* ctx) throw() 
{
	return acceptEncoding;
}
void HttpRequestHeaders::setAcceptEncoding(String* acceptEncoding, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->acceptEncoding), acceptEncoding, String);
}
String* HttpRequestHeaders::getAcceptCharset(ThreadContext* ctx) throw() 
{
	return acceptCharset;
}
void HttpRequestHeaders::setAcceptCharset(String* acceptCharset, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->acceptCharset), acceptCharset, String);
}
String* HttpRequestHeaders::getKeepAlive(ThreadContext* ctx) throw() 
{
	return keepAlive;
}
void HttpRequestHeaders::setKeepAlive(String* keepAlive, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->keepAlive), keepAlive, String);
}
String* HttpRequestHeaders::getConnection(ThreadContext* ctx) throw() 
{
	return connection;
}
void HttpRequestHeaders::setConnection(String* connection, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->connection), connection, String);
}
String* HttpRequestHeaders::getCookie(ThreadContext* ctx) throw() 
{
	return cookie;
}
void HttpRequestHeaders::setCookie(String* cookie, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->cookie), cookie, String);
}
void HttpRequestHeaders::dowrite(StringBuffer* writer, String* key, String* value, ThreadContext* ctx)
{
	if(value == nullptr)
	{
		return;
	}
	writer->append(key, ctx)->append(ConstStr::getCNST_STR_1880(), ctx)->append(value, ctx)->append(ConstStr::getCNST_STR_1881(), ctx);
}
}}}

