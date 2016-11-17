#include "includes.h"


namespace alinous {namespace compile {namespace declare {





bool VirtualTable::__init_done = __init_static_variables();
bool VirtualTable::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"VirtualTable", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 VirtualTable::~VirtualTable() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void VirtualTable::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"VirtualTable", L"~VirtualTable");
	__e_obj1.add(this->list, this);
	list = nullptr;
	if(!prepare){
		return;
	}
}
void VirtualTable::addVirtualFunction(AlinousClass* clazz, ClassMethodFunction* method, ThreadContext* ctx) throw() 
{
	VirtualTable::MethodPair* pair = (new(ctx) VirtualTable::MethodPair(clazz, method, ctx));
	this->list->add(pair, ctx);
}
ClassMethodFunction* VirtualTable::getMethod(AlinousClass* clazz, ThreadContext* ctx) throw() 
{
	int maxLoop = this->list->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		VirtualTable::MethodPair* pair = this->list->get(i, ctx);
		if(pair->clazz == clazz)
		{
			return pair->func;
		}
	}
	return nullptr;
}
}}}

namespace alinous {namespace compile {namespace declare {





bool VirtualTable::MethodPair::__init_done = __init_static_variables();
bool VirtualTable::MethodPair::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"VirtualTable::MethodPair", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 VirtualTable::MethodPair::MethodPair(AlinousClass* clazz, ClassMethodFunction* func, ThreadContext* ctx) throw()  : IObject(ctx), clazz(nullptr), func(nullptr)
{
	__GC_MV(this, &(this->clazz), clazz, AlinousClass);
	__GC_MV(this, &(this->func), func, ClassMethodFunction);
}
void VirtualTable::MethodPair::__construct_impl(AlinousClass* clazz, ClassMethodFunction* func, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->clazz), clazz, AlinousClass);
	__GC_MV(this, &(this->func), func, ClassMethodFunction);
}
 VirtualTable::MethodPair::~MethodPair() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void VirtualTable::MethodPair::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"MethodPair", L"~MethodPair");
	__e_obj1.add(this->clazz, this);
	clazz = nullptr;
	__e_obj1.add(this->func, this);
	func = nullptr;
	if(!prepare){
		return;
	}
}
}}}

