#include "includes.h"


namespace alinous {namespace compile {namespace analyse {namespace tools {





bool FunctionCallCollector::__init_done = __init_static_variables();
bool FunctionCallCollector::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"FunctionCallCollector", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 FunctionCallCollector::~FunctionCallCollector() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void FunctionCallCollector::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"FunctionCallCollector", L"~FunctionCallCollector");
	__e_obj1.add(this->list, this);
	list = nullptr;
	if(!prepare){
		return;
	}
}
bool FunctionCallCollector::visit(AbstractSrcElement* element, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if((dynamic_cast<FunctionCallExpression*>(element) != 0))
	{
		this->list->add(static_cast<FunctionCallExpression*>(element), ctx);
	}
	return true;
}
ArrayList<FunctionCallExpression>* FunctionCallCollector::getList(ThreadContext* ctx) throw() 
{
	return list;
}
}}}}

