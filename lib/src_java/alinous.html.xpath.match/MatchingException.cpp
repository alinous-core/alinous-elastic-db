#include "include/global.h"


#include "alinous.html.xpath.match/MatchingException.h"

namespace alinous {namespace html {namespace xpath {namespace match {





constexpr const long long MatchingException::serialVersionUID;
bool MatchingException::__init_done = __init_static_variables();
bool MatchingException::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"MatchingException", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 MatchingException::MatchingException(String* messaString, ThreadContext* ctx) throw()  : IObject(ctx), Exception(messaString, ctx)
{
}
void MatchingException::__construct_impl(String* messaString, ThreadContext* ctx) throw() 
{
}
 MatchingException::~MatchingException() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void MatchingException::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	Exception::__releaseRegerences(true, ctx);
}
void MatchingException::__cleanUp(ThreadContext* ctx){
}
}}}}

