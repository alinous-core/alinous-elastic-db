#include "includes.h"


namespace alinous {namespace compile {namespace sql {namespace select {namespace join {





bool AbstractJoinTarget::__init_done = __init_static_variables();
bool AbstractJoinTarget::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AbstractJoinTarget", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AbstractJoinTarget::~AbstractJoinTarget() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AbstractJoinTarget::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	IJoinTarget::__releaseRegerences(true, ctx);
}
int AbstractJoinTarget::getLine(ThreadContext* ctx) throw() 
{
	return IJoinTarget::getLine(ctx);
}
int AbstractJoinTarget::getStartPosition(ThreadContext* ctx) throw() 
{
	return IJoinTarget::getStartPosition(ctx);
}
int AbstractJoinTarget::getEndLine(ThreadContext* ctx) throw() 
{
	return IJoinTarget::getEndLine(ctx);
}
int AbstractJoinTarget::getEndPosition(ThreadContext* ctx) throw() 
{
	return IJoinTarget::getEndPosition(ctx);
}
AbstractSrcElement* AbstractJoinTarget::getParent(ThreadContext* ctx) throw() 
{
	return IJoinTarget::getParent(ctx);
}
void AbstractJoinTarget::setParent(AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	IJoinTarget::setParent(parent, ctx);
}
}}}}}

