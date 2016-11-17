#include "includes.h"


namespace alinous {namespace compile {namespace declare {





constexpr const int IClassMember::CLASS_METHOD;
constexpr const int IClassMember::CLASS_VARIABLE;
constexpr const int IClassMember::STATIC_CLASS_METHOD;
constexpr const int IClassMember::STATIC_CLASS_VARIABLE;
bool IClassMember::__init_done = __init_static_variables();
bool IClassMember::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"IClassMember", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 IClassMember::~IClassMember() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void IClassMember::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	IDeclare::__releaseRegerences(true, ctx);
}
}}}

