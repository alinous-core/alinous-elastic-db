#include "includes.h"


namespace alinous {namespace btreememory {





bool AbstractMemoryBTreeNode::__init_done = __init_static_variables();
bool AbstractMemoryBTreeNode::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AbstractMemoryBTreeNode", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AbstractMemoryBTreeNode::AbstractMemoryBTreeNode(int numNodes, IArrayObject<IBTreeNode>* nodes, ThreadContext* ctx) throw()  : IObject(ctx), AbstractMemoryNode(ctx), length(0), nodeUsed(0), nodes(nullptr)
{
	this->length = numNodes;
	__GC_MV(this, &(this->nodes), nodes != nullptr ? nodes : ArrayAllocator<IBTreeNode>::allocate(ctx, numNodes + 2), IArrayObject<IBTreeNode>);
}
void AbstractMemoryBTreeNode::__construct_impl(int numNodes, IArrayObject<IBTreeNode>* nodes, ThreadContext* ctx) throw() 
{
	this->length = numNodes;
	__GC_MV(this, &(this->nodes), nodes != nullptr ? nodes : ArrayAllocator<IBTreeNode>::allocate(ctx, numNodes + 2), IArrayObject<IBTreeNode>);
}
 AbstractMemoryBTreeNode::~AbstractMemoryBTreeNode() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AbstractMemoryBTreeNode::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"AbstractMemoryBTreeNode", L"~AbstractMemoryBTreeNode");
	__e_obj1.add(this->nodes, this);
	nodes = nullptr;
	if(!prepare){
		return;
	}
	AbstractMemoryNode::__releaseRegerences(true, ctx);
}
void AbstractMemoryBTreeNode::setNode(IBTreeNode* ref, int index, ThreadContext* ctx) throw() 
{
	this->nodes->set(ref,index, ctx);
}
bool AbstractMemoryBTreeNode::isHasLeaf(ThreadContext* ctx) throw() 
{
	return false;
}
IBTreeNode* AbstractMemoryBTreeNode::getNodeAtInsertPosition(IBTreeKey* key, ThreadContext* ctx)
{
	return this->nodes->get(nodeToGoDown(key, ctx));
}
int AbstractMemoryBTreeNode::getNodeAtInsertPositionNumber(IBTreeKey* key, ThreadContext* ctx)
{
	return nodeToGoDown(key, ctx);
}
IBTreeNode* AbstractMemoryBTreeNode::get(int index, ThreadContext* ctx) throw() 
{
	return this->nodes->get(index);
}
int AbstractMemoryBTreeNode::getNodeUsed(ThreadContext* ctx) throw() 
{
	return nodeUsed;
}
void AbstractMemoryBTreeNode::setNodeUsed(int nodeUsed, ThreadContext* ctx) throw() 
{
	this->nodeUsed = nodeUsed;
}
bool AbstractMemoryBTreeNode::isFull(ThreadContext* ctx) throw() 
{
	return this->nodeUsed == this->length;
}
IBTreeNode* AbstractMemoryBTreeNode::split(IBTreeNode* newNode, BTreeNodeLoader* loader, ThreadContext* ctx)
{
	putNode(newNode, true, false, ctx);
	int mid = this->length / 2;
	IBTreeKey* key = this->nodes->get(mid - 1)->getKey(ctx);
	MBTreeNode* smaller = (new(ctx) MBTreeNode(key, this->length, ctx));
	IArrayObject<IBTreeNode>* nodes = this->nodes;
	for(int i = 0; i != mid; i ++ )
	{
		smaller->move(nodes->get(i), ctx);
	}
	smaller->setNodeUsed(mid, ctx);
	removeNode(0, mid, ctx);
	return smaller;
}
void AbstractMemoryBTreeNode::addNode(IBTreeNode* newNode, ThreadContext* ctx)
{
	putNode(newNode, false, false, ctx);
}
IBTreeNode* AbstractMemoryBTreeNode::removeNode(IBTreeKey* key, ThreadContext* ctx)
{
	int index = indexOf(key, ctx);
	if(index < 0)
	{
		return nullptr;
	}
	removeNode(index, 1, ctx);
	return this->nodes->get(index);
}
void AbstractMemoryBTreeNode::removeNode(int index, int count, ThreadContext* ctx)
{
	__builtin_prefetch_array_root(this->nodes, 1, 1);
	int copySize = this->nodeUsed - index - count;
	IArrayObject<IBTreeNode>* nodes = this->nodes;
	int src = 0;
	for(int i = 0; i != copySize; i ++ )
	{
		src = i + index + count;
		nodes->set(nodes->get(src),i + index, ctx);
		nodes->set(nullptr,src, ctx);
	}
	this->nodeUsed = this->nodeUsed - count;
}
bool AbstractMemoryBTreeNode::putNode(IBTreeNode* newNode, bool ignoreOverflow, bool move, ThreadContext* ctx)
{
	int index = indexOfInsert(newNode, ctx);
	if(!ignoreOverflow && index == this->length)
	{
		return false;
	}
	IArrayObject<IBTreeNode>* nodes = this->nodes;
	for(int i = this->nodeUsed; i != index; i -- )
	{
		__builtin_prefetch(nodes->get(i), 1);
	}
	for(int i = this->nodeUsed; i != index; i -- )
	{
		nodes->set(nodes->get(i - 1),i, ctx);
	}
	nodes->set(newNode,index, ctx);
	this->nodeUsed ++ ;
	setNodeUsed(this->nodeUsed, ctx);
	return true;
}
int AbstractMemoryBTreeNode::indexOfInsert(IBTreeNode* value, ThreadContext* ctx) throw() 
{
	__builtin_prefetch_array_root(this->nodes, 1, 1);
	IArrayObject<IBTreeNode>* _root = this->nodes;
	int maxLoop = this->nodeUsed;
	int i = 0;
	for(i = 0; i < maxLoop; ++i)
	{
		__builtin_prefetch(_root->get(i)->getKey(ctx));
	}
	i = 0;
	for(; i < maxLoop; ++i)
	{
		if(_root->get(i)->compareTo(value, ctx) >= 0)
		{
			return i;
		}
	}
	return i;
}
int AbstractMemoryBTreeNode::indexOf(IBTreeKey* value, ThreadContext* ctx) throw() 
{
	__builtin_prefetch_array_root(this->nodes, 1, 1);
	IArrayObject<IBTreeNode>* _root = this->nodes;
	int maxLoop = this->nodeUsed;
	int i = 0;
	for(i = 0; i < maxLoop; ++i)
	{
		__builtin_prefetch(_root->get(i)->getKey(ctx));
	}
	i = 0;
	for(; i < maxLoop; ++i)
	{
		if(_root->get(i)->getKey(ctx)->compareTo(value, ctx) >= 0)
		{
			return i;
		}
	}
	return -1;
}
int AbstractMemoryBTreeNode::nodeToGoDown(IBTreeKey* key, ThreadContext* ctx) throw() 
{
	__builtin_prefetch_array_root(this->nodes, 1, 1);
	IArrayObject<IBTreeNode>* _root = this->nodes;
	int maxLoop = this->nodeUsed;
	int i = 0;
	for(i = 0; i < maxLoop; ++i)
	{
		__builtin_prefetch(_root->get(i)->getKey(ctx));
	}
	for(i = 0; i < maxLoop; ++i)
	{
		if(_root->get(i)->getKey(ctx)->compareTo(key, ctx) >= 0)
		{
			return i;
		}
	}
	return i;
}
}}

