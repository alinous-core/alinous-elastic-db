#include "includes.h"


namespace alinous {namespace btree {namespace scan {





bool LeafContainerIterator::__init_done = __init_static_variables();
bool LeafContainerIterator::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"LeafContainerIterator", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 LeafContainerIterator::LeafContainerIterator(BTreeNodeLoader* loader, long long filePointer, ThreadContext* ctx) throw()  : IObject(ctx), AbstractNodeIterator(loader, filePointer, ctx), container(nullptr), length(0), current(0)
{
}
void LeafContainerIterator::__construct_impl(BTreeNodeLoader* loader, long long filePointer, ThreadContext* ctx) throw() 
{
}
 LeafContainerIterator::~LeafContainerIterator() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void LeafContainerIterator::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"LeafContainerIterator", L"~LeafContainerIterator");
	__e_obj1.add(this->container, this);
	container = nullptr;
	if(!prepare){
		return;
	}
	AbstractNodeIterator::__releaseRegerences(true, ctx);
}
LeafContainerIterator* LeafContainerIterator::init(bool endStart, ThreadContext* ctx)
{
	__GC_MV(this, &(this->container), static_cast<AbstractBTreeLeafContainer*>(loader->loadBTreeNode(filePointer, ctx)), AbstractBTreeLeafContainer);
	this->container->loadChildren(ctx);
	if(endStart)
	{
		current = this->container->getNodeUsed(ctx) - 1;
	}
		else 
	{
		current = 0;
	}
	this->length = this->container->getNodeUsed(ctx);
	return this;
}
void LeafContainerIterator::gotoNode(IBTreeKey* key, ThreadContext* ctx)
{
	this->current = this->container->getNodeAtInsertPositionNumber(key, ctx);
}
void LeafContainerIterator::incCurrent(ThreadContext* ctx) throw() 
{
	this->current ++ ;
}
bool LeafContainerIterator::hasNext(ThreadContext* ctx) throw() 
{
	return this->current >= 0 && length != current;
}
IBTreeNode* LeafContainerIterator::next(ThreadContext* ctx)
{
	this->container->loadChildren(ctx);
	return this->container->getNodeAt(this->current++, ctx)->getNode(ctx);
}
bool LeafContainerIterator::isLeafContainer(ThreadContext* ctx) throw() 
{
	return true;
}
void LeafContainerIterator::dispose(ThreadContext* ctx)
{
	this->container->endUse(ctx);
}
int LeafContainerIterator::getType(ThreadContext* ctx) throw() 
{
	return INodeIterator::IT_LEAF_CONTAINER;
}
}}}

