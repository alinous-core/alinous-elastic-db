#include "includes.h"


namespace alinous {namespace btreememory {





bool MemoryBTreeMachine::__init_done = __init_static_variables();
bool MemoryBTreeMachine::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"MemoryBTreeMachine", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 MemoryBTreeMachine::MemoryBTreeMachine(IBTreeNode* rootNode, BTreeOnMemory* btree, ThreadContext* ctx) : IObject(ctx), nodeStack(GCUtils<Stack<IBTreeNode> >::ins(this, (new(ctx) Stack<IBTreeNode>(ctx)), ctx, __FILEW__, __LINE__, L"")), rootNode(nullptr), btree(nullptr)
{
	push(rootNode, ctx);
	__GC_MV(this, &(this->rootNode), rootNode, IBTreeNode);
	__GC_MV(this, &(this->btree), btree, BTreeOnMemory);
}
void MemoryBTreeMachine::__construct_impl(IBTreeNode* rootNode, BTreeOnMemory* btree, ThreadContext* ctx)
{
	push(rootNode, ctx);
	__GC_MV(this, &(this->rootNode), rootNode, IBTreeNode);
	__GC_MV(this, &(this->btree), btree, BTreeOnMemory);
}
 MemoryBTreeMachine::~MemoryBTreeMachine() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void MemoryBTreeMachine::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"MemoryBTreeMachine", L"~MemoryBTreeMachine");
	__e_obj1.add(this->nodeStack, this);
	nodeStack = nullptr;
	__e_obj1.add(this->rootNode, this);
	rootNode = nullptr;
	__e_obj1.add(this->btree, this);
	btree = nullptr;
	if(!prepare){
		return;
	}
}
void MemoryBTreeMachine::removeKey(IBTreeKey* key, ThreadContext* ctx)
{
	IBTreeNode* node = this->nodeStack->peek(ctx);
	while(!node->isHasLeaf(ctx))
	{
		node = node->getNodeAtInsertPosition(key, ctx);
		push(node, ctx);
	}
	bool keyDeleted = node->removeChild(key, ctx);
	bool lastNodeEmpty = node->isEmpty(ctx);
	pop(ctx);
	Stack<IBTreeNode>* nodeStack = this->nodeStack;
	while(!nodeStack->isEmpty(ctx))
	{
		node = nodeStack->peek(ctx);
		if(keyDeleted || lastNodeEmpty)
		{
			keyDeleted = node->removeChild(key, ctx);
			lastNodeEmpty = node->isEmpty(ctx);
		}
				else 
		{
			lastNodeEmpty = false;
			keyDeleted = false;
		}
		pop(ctx);
	}
}
void MemoryBTreeMachine::insertLeaf(MBTreeLeafNode* newNode, ThreadContext* ctx)
{
	IBTreeNode* node = nodeStack->peek(ctx);
	while(!node->isHasLeaf(ctx))
	{
		node = node->getNodeAtInsertPosition(newNode->getKey(ctx), ctx);
		push(node, ctx);
	}
	if(__builtin_expect(!node->isFull(ctx), 1))
	{
		node->addLeafNode(newNode, ctx);
	}
		else 
	{
		if(__builtin_expect(node->isFull(ctx) && node == this->rootNode, 0))
		{
			splitAndInsertLeaf2Root(node, newNode, ctx);
		}
				else 
		{
			splitAndInsertLeaf(node, newNode, ctx);
		}
	}
}
void MemoryBTreeMachine::push(IBTreeNode* node, ThreadContext* ctx) throw() 
{
	this->nodeStack->push(node, ctx);
}
IBTreeNode* MemoryBTreeMachine::pop(ThreadContext* ctx) throw() 
{
	return this->nodeStack->pop(ctx);
}
void MemoryBTreeMachine::reset(ThreadContext* ctx) throw() 
{
	this->nodeStack->clear(ctx);
	push(rootNode, ctx);
}
void MemoryBTreeMachine::destroy(ThreadContext* ctx) throw() 
{
	this->nodeStack->clear(ctx);
}
void MemoryBTreeMachine::splitAndInsertLeaf2Root(IBTreeNode* root, IBTreeNode* newNode, ThreadContext* ctx)
{
	IBTreeNode* smallerNode = root->split(newNode, nullptr, ctx);
	IBTreeNode* newRoot = (new(ctx) MBTreeMaxNode(btree->getNodeCapacity(ctx), nullptr, root, ctx));
	newRoot->addNode(smallerNode, ctx);
	__GC_MV(this, &(this->rootNode), newRoot, IBTreeNode);
	btree->setRoot(newRoot, ctx);
}
void MemoryBTreeMachine::splitAndInsertLeaf(IBTreeNode* node, IBTreeNode* newNode, ThreadContext* ctx)
{
	IBTreeNode* smallerNode = node->split(newNode, nullptr, ctx);
	IBTreeNode* parent = getParent(node, ctx);
	if(__builtin_expect(parent->isFull(ctx), 0))
	{
		if(__builtin_expect(parent != this->rootNode, 1))
		{
			splitAndInsertNode(parent, smallerNode, ctx);
		}
				else 
		{
			splitAndInsertNode2Root(parent, smallerNode, ctx);
		}
	}
		else 
	{
		parent->addNode(smallerNode, ctx);
	}
}
void MemoryBTreeMachine::splitAndInsertNode2Root(IBTreeNode* root, IBTreeNode* newNode, ThreadContext* ctx)
{
	IBTreeNode* smallerNode = root->split(newNode, nullptr, ctx);
	IBTreeNode* newRoot = (new(ctx) MBTreeMaxNode(btree->getNodeCapacity(ctx), nullptr, root, ctx));
	newRoot->addNode(smallerNode, ctx);
	__GC_MV(this, &(this->rootNode), newRoot, IBTreeNode);
	btree->setRoot(newRoot, ctx);
}
void MemoryBTreeMachine::splitAndInsertNode(IBTreeNode* node, IBTreeNode* newNode, ThreadContext* ctx)
{
	IBTreeNode* smallerNode = node->split(newNode, nullptr, ctx);
	IBTreeNode* parent = getParent(node, ctx);
	if(__builtin_expect(parent->isFull(ctx), 0))
	{
		if(__builtin_expect(parent != this->rootNode, 1))
		{
			splitAndInsertNode(parent, smallerNode, ctx);
		}
				else 
		{
			splitAndInsertNode2Root(parent, smallerNode, ctx);
		}
	}
		else 
	{
		parent->addNode(smallerNode, ctx);
	}
}
IBTreeNode* MemoryBTreeMachine::getParent(IBTreeNode* node, ThreadContext* ctx) throw() 
{
	__builtin_prefetch(this->nodeStack);
	IBTreeNode* lastNode = nullptr;
	Stack<IBTreeNode>* nodeStack = this->nodeStack;
	int maxLoop = nodeStack->size(ctx);
	IBTreeNode* n = 0;
	for(int i = 0; i != maxLoop; ++i)
	{
		n = nodeStack->get(i, ctx);
		if(n == node)
		{
			return lastNode;
		}
		lastNode = n;
	}
	return nullptr;
}
}}

