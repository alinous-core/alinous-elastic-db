#include "includes.h"


namespace alinous {namespace compile {namespace sql {namespace select {namespace join {





bool RightJoin::__init_done = __init_static_variables();
bool RightJoin::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"RightJoin", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 RightJoin::~RightJoin() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void RightJoin::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	LeftJoin::__releaseRegerences(true, ctx);
}
void RightJoin::setLeft(IJoin* left, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->right), left, IJoin);
}
void RightJoin::setRight(IJoin* right, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->left), right, IJoin);
}
}}}}}

