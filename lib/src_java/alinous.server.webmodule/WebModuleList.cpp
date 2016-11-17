#include "includes.h"


namespace alinous {namespace server {namespace webmodule {





bool WebModuleList::__init_done = __init_static_variables();
bool WebModuleList::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"WebModuleList", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 WebModuleList::~WebModuleList() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void WebModuleList::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"WebModuleList", L"~WebModuleList");
	__e_obj1.add(this->list, this);
	list = nullptr;
	if(!prepare){
		return;
	}
}
void WebModuleList::add(FifoElement<AbstractWebModule>* module, ThreadContext* ctx) throw() 
{
	this->list->add(module, ctx);
}
FifoElement<AbstractWebModule>* WebModuleList::find(String* path, ThreadContext* ctx) throw() 
{
	ArrayList<FifoElement<AbstractWebModule>>* list = this->list;
	int maxLoop = list->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		FifoElement<AbstractWebModule>* element = list->get(i, ctx);
		AbstractWebModule* data = element->data;
		if(data->path->equals(path, ctx))
		{
			return element;
		}
	}
	return nullptr;
}
void WebModuleList::removeElement(String* path, ThreadContext* ctx) throw() 
{
	ArrayList<FifoElement<AbstractWebModule>>* list = this->list;
	int maxLoop = list->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		FifoElement<AbstractWebModule>* element = list->get(i, ctx);
		AbstractWebModule* data = element->data;
		if(data->path->equals(path, ctx))
		{
			list->remove(i, ctx);
			return;
		}
	}
}
}}}

