#include "include/global.h"


#include "alinous.net/UnknownHostException.h"
#include "org.alinous.charset/CharsetDecoder.h"
#include "alinous.net/URLDecoder.h"
#include "alinous.net/URLEncoder.h"

namespace alinous {namespace net {





constexpr const long long UnknownHostException::serialVersionUID;
bool UnknownHostException::__init_done = __init_static_variables();
bool UnknownHostException::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"UnknownHostException", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 UnknownHostException::UnknownHostException(ThreadContext* ctx) throw()  : IObject(ctx), IOException(ctx)
{
}
void UnknownHostException::__construct_impl(ThreadContext* ctx) throw() 
{
}
 UnknownHostException::UnknownHostException(String* detailMessage, ThreadContext* ctx) throw()  : IObject(ctx), IOException(detailMessage, ctx)
{
}
void UnknownHostException::__construct_impl(String* detailMessage, ThreadContext* ctx) throw() 
{
}
 UnknownHostException::~UnknownHostException() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void UnknownHostException::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	IOException::__releaseRegerences(true, ctx);
}
}}

