#include "include/global.h"


#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.compile/IAlinousElementVisitor.h"

namespace alinous {namespace compile {




bool IAlinousElementVisitor::__init_done = __init_static_variables();
bool IAlinousElementVisitor::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"IAlinousElementVisitor", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 IAlinousElementVisitor::IAlinousElementVisitor(ThreadContext* ctx) throw()  : IObject(ctx)
{
}
void IAlinousElementVisitor::__construct_impl(ThreadContext* ctx) throw() 
{
}
 IAlinousElementVisitor::~IAlinousElementVisitor() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void IAlinousElementVisitor::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
void IAlinousElementVisitor::__cleanUp(ThreadContext* ctx){
}
}}

