#include "include/global.h"


#include "alinous.btree/BTreeException.h"
#include "alinous.buffer.storage/FileStorageEntry.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "java.lang/Comparable.h"
#include "alinous.btree/IBTreeKey.h"
#include "alinous.btree.scan/INodeIterator.h"
#include "alinous.btree/IBTreeNode.h"
#include "alinous.btree/BTreeNodeLoader.h"
#include "alinous.btreememory.scan/MemoryLeafContainerIterator.h"
#include "alinous.btreememory/AbstractMemoryNode.h"
#include "alinous.btreememory/AbstractMemoryBTreeLeafContainer.h"
#include "alinous.btreememory/MBTreeLeafContainer.h"

namespace alinous {namespace btreememory {





bool AbstractMemoryBTreeLeafContainer::__init_done = __init_static_variables();
bool AbstractMemoryBTreeLeafContainer::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AbstractMemoryBTreeLeafContainer", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AbstractMemoryBTreeLeafContainer::AbstractMemoryBTreeLeafContainer(int numNodes, IArrayObject<IBTreeNode>* nodes, ThreadContext* ctx) throw()  : IObject(ctx), AbstractMemoryNode(ctx), length(0), nodeUsed(0), nodes(nullptr)
{
	this->length = numNodes;
	__GC_MV(this, &(this->nodes), nodes != nullptr ? nodes : ArrayAllocator<IBTreeNode>::allocate(ctx, numNodes + 1), IArrayObject<IBTreeNode>);
}
void AbstractMemoryBTreeLeafContainer::__construct_impl(int numNodes, IArrayObject<IBTreeNode>* nodes, ThreadContext* ctx) throw() 
{
	this->length = numNodes;
	__GC_MV(this, &(this->nodes), nodes != nullptr ? nodes : ArrayAllocator<IBTreeNode>::allocate(ctx, numNodes + 1), IArrayObject<IBTreeNode>);
}
 AbstractMemoryBTreeLeafContainer::~AbstractMemoryBTreeLeafContainer() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AbstractMemoryBTreeLeafContainer::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"AbstractMemoryBTreeLeafContainer", L"~AbstractMemoryBTreeLeafContainer");
	__e_obj1.add(this->nodes, this);
	nodes = nullptr;
	if(!prepare){
		return;
	}
	AbstractMemoryNode::__releaseRegerences(true, ctx);
}
bool AbstractMemoryBTreeLeafContainer::isHasLeaf(ThreadContext* ctx) throw() 
{
	return true;
}
bool AbstractMemoryBTreeLeafContainer::isFull(ThreadContext* ctx) throw() 
{
	return this->nodeUsed == this->length;
}
void AbstractMemoryBTreeLeafContainer::setNodeUsed(int nodeUsed, ThreadContext* ctx) throw() 
{
	this->nodeUsed = nodeUsed;
}
IBTreeNode* AbstractMemoryBTreeLeafContainer::addLeafNode(IBTreeNode* newNode, ThreadContext* ctx)
{
	putNode(newNode, false, false, ctx);
	return newNode;
}
IBTreeNode* AbstractMemoryBTreeLeafContainer::getNodeAtInsertPosition(IBTreeKey* key, ThreadContext* ctx)
{
	if(this->nodeUsed == 0)
	{
		return nullptr;
	}
	int pos = nodeToGoDown(key, ctx);
	return this->nodes->get(pos);
}
int AbstractMemoryBTreeLeafContainer::nodeToGoDown(IBTreeKey* key, ThreadContext* ctx) throw() 
{
	__builtin_prefetch_array_root(this->nodes, 0, 1);
	IArrayObject<IBTreeNode>* _root = this->nodes;
	int maxLoop = this->nodeUsed;
	int i = 0;
	for(i = 0; i < maxLoop; ++i)
	{
		__builtin_prefetch(_root->get(i)->getKey(ctx), 0, 1);
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
void AbstractMemoryBTreeLeafContainer::move(IBTreeNode* node, ThreadContext* ctx)
{
	putNode(node, false, true, ctx);
}
int AbstractMemoryBTreeLeafContainer::getNodeAtInsertPositionNumber(IBTreeKey* key, ThreadContext* ctx)
{
	if(this->nodeUsed == 0)
	{
		return -1;
	}
	int pos = nodeToGoDown(key, ctx);
	if(pos >= this->nodeUsed || this->nodes->get(pos) == nullptr)
	{
		return -1;
	}
	return pos;
}
IBTreeNode* AbstractMemoryBTreeLeafContainer::split(IBTreeNode* newNode, BTreeNodeLoader* loader, ThreadContext* ctx)
{
	putNode(newNode, true, false, ctx);
	IArrayObject<IBTreeNode>* nodes = this->nodes;
	int mid = this->length / 2;
	IBTreeKey* key = nodes->get(mid - 1)->getKey(ctx);
	MBTreeLeafContainer* smaller = (new(ctx) MBTreeLeafContainer(key, this->length, nullptr, ctx));
	for(int i = 0; i != mid; i ++ )
	{
		smaller->move(nodes->get(i), ctx);
	}
	smaller->setNodeUsed(mid, ctx);
	removeNode(0, mid, ctx);
	return smaller;
}
IBTreeNode* AbstractMemoryBTreeLeafContainer::getNodeAt(int index, ThreadContext* ctx) throw() 
{
	return this->nodes->get(index);
}
int AbstractMemoryBTreeLeafContainer::getNodeUsed(ThreadContext* ctx) throw() 
{
	return nodeUsed;
}
INodeIterator* AbstractMemoryBTreeLeafContainer::iterator(bool endStart, ThreadContext* ctx)
{
	return (new(ctx) MemoryLeafContainerIterator(endStart, this, ctx));
}
bool AbstractMemoryBTreeLeafContainer::putNode(IBTreeNode* btNode, bool ignoreOverflow, bool move, ThreadContext* ctx)
{
	IBTreeNode* newNode = btNode;
	__builtin_prefetch_array_root(this->nodes, 1, 1);
	int index = indexOfInsert(newNode, ctx);
	if(!ignoreOverflow && index == this->length)
	{
		return false;
	}
	IArrayObject<IBTreeNode>* nodes = this->nodes;
	for(int i = this->nodeUsed; i != index; i -- )
	{
		nodes->set(nodes->get(i - 1),i, ctx);
	}
	nodes->set(newNode,index, ctx);
	this->nodeUsed ++ ;
	setNodeUsed(this->nodeUsed, ctx);
	return true;
}
int AbstractMemoryBTreeLeafContainer::indexOfInsert(IBTreeNode* value, ThreadContext* ctx) throw() 
{
	__builtin_prefetch_array_root(this->nodes, 0, 1);
	IArrayObject<IBTreeNode>* _root = this->nodes;
	int maxLoop = this->nodeUsed;
	int i = 0;
	for(; i < maxLoop; ++i)
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
void AbstractMemoryBTreeLeafContainer::removeNode(int index, int count, ThreadContext* ctx)
{
	int copySize = this->nodeUsed - index - count;
	int src = 0;
	IArrayObject<IBTreeNode>* nodes = this->nodes;
	for(int i = 0; i != copySize; i ++ )
	{
		src = i + index + count;
		nodes->set(nodes->get(src),i + index, ctx);
		nodes->set(nullptr,src, ctx);
	}
	this->nodeUsed = this->nodeUsed - count;
	setNodeUsed(this->nodeUsed, ctx);
}
void AbstractMemoryBTreeLeafContainer::__cleanUp(ThreadContext* ctx){
}
}}

