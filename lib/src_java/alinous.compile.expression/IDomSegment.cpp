#include "includes.h"


namespace alinous {namespace compile {namespace expression {





constexpr const int IDomSegment::TYPE_NORMAL;
constexpr const int IDomSegment::TYPE_INDEX;
bool IDomSegment::__init_done = __init_static_variables();
bool IDomSegment::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"IDomSegment", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 IDomSegment::~IDomSegment() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void IDomSegment::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	IAlinousElement::__releaseRegerences(true, ctx);
}
}}}

