#include "includes.h"


namespace alinous {namespace server {namespace webmodule {





bool WebModuleHashList::__init_done = __init_static_variables();
bool WebModuleHashList::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"WebModuleHashList", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 WebModuleHashList::~WebModuleHashList() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void WebModuleHashList::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"WebModuleHashList", L"~WebModuleHashList");
	__e_obj1.add(this->arrays, this);
	arrays = nullptr;
	__e_obj1.add(this->bitset, this);
	bitset = nullptr;
	if(!prepare){
		return;
	}
}
WebModuleHashList* WebModuleHashList::init(int MAX_HASH, ThreadContext* ctx)
{
	if((MAX_HASH & 1) != 0)
	{
		throw (new(ctx) AlinousException(ConstStr::getCNST_STR_1647(), ctx));
	}
	this->MAX_HASH = MAX_HASH;
	this->MAX_HASH_MASK = MAX_HASH - 1;
	__GC_MV(this, &(this->arrays), ArrayAllocator<WebModuleList>::allocate(ctx, MAX_HASH), IArrayObject<WebModuleList>);
	for(int i = 0; i != MAX_HASH; i ++ )
	{
		arrays->set((new(ctx) WebModuleList(ctx)),i, ctx);
	}
	return this;
}
int WebModuleHashList::size(ThreadContext* ctx) throw() 
{
	return this->numElements;
}
void WebModuleHashList::add(FifoElement<AbstractWebModule>* module, ThreadContext* ctx) throw() 
{
	AbstractWebModule* data = module->data;
	int hashcode = ((int)(data->getHashKey(ctx) & MAX_HASH_MASK));
	arrays->get(hashcode)->add(module, ctx);
	bitset->set(hashcode, ctx);
	++numElements;
}
FifoElement<AbstractWebModule>* WebModuleHashList::find(String* path, ThreadContext* ctx) throw() 
{
	int hashcode = ((int)(path->hashCode(ctx) & MAX_HASH_MASK));
	return arrays->get(hashcode)->find(path, ctx);
}
void WebModuleHashList::remove(String* path, ThreadContext* ctx) throw() 
{
	int hashcode = ((int)(path->hashCode(ctx) & MAX_HASH_MASK));
	arrays->get(hashcode)->removeElement(path, ctx);
}
}}}

