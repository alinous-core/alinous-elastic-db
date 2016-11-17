#include "includes.h"


namespace alinous {namespace btree {





bool BTreeCacheArray::__init_done = __init_static_variables();
bool BTreeCacheArray::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"BTreeCacheArray", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 BTreeCacheArray::BTreeCacheArray(int i, ThreadContext* ctx) throw()  : IObject(ctx), list(GCUtils<ArrayList<IBTreeNode> >::ins(this, (new(ctx) ArrayList<IBTreeNode>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
	GCUtils<ArrayList<IBTreeNode> >::mv(this, &(list), (new(ctx) ArrayList<IBTreeNode>(i, ctx)), ctx);
}
void BTreeCacheArray::__construct_impl(int i, ThreadContext* ctx) throw() 
{
	GCUtils<ArrayList<IBTreeNode> >::mv(this, &(list), (new(ctx) ArrayList<IBTreeNode>(i, ctx)), ctx);
}
 BTreeCacheArray::~BTreeCacheArray() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void BTreeCacheArray::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"BTreeCacheArray", L"~BTreeCacheArray");
	__e_obj1.add(this->list, this);
	list = nullptr;
	if(!prepare){
		return;
	}
}
void BTreeCacheArray::add(IBTreeNode* ptr, ThreadContext* ctx) throw() 
{
	list->add(ptr, ctx);
}
bool BTreeCacheArray::removeByObj(IBTreeNode* obj, ThreadContext* ctx) throw() 
{
	bool ret = list->remove(obj, ctx);
	return ret;
}
int BTreeCacheArray::size(ThreadContext* ctx) throw() 
{
	return list->size(ctx);
}
IBTreeNode* BTreeCacheArray::search(IBTreeNode* value, ThreadContext* ctx) throw() 
{
	int maxLoop = list->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IBTreeNode* n = list->get(i, ctx);
		if(n->getStorage(ctx) == value->getStorage(ctx) && n->equals(value, ctx))
		{
			return n;
		}
	}
	return nullptr;
}
void BTreeCacheArray::reset(ThreadContext* ctx) throw() 
{
	list->clear(ctx);
}
IBTreeNode* BTreeCacheArray::get(int i, ThreadContext* ctx) throw() 
{
	return list->get(i, ctx);
}
}}

