#include "includes.h"


namespace alinous {namespace btree {





bool BTreeMachine::__init_done = __init_static_variables();
bool BTreeMachine::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"BTreeMachine", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 BTreeMachine::BTreeMachine(IBTreeNode* rootNode, BTree* btree, ThreadContext* ctx) : IObject(ctx), nodeStack(GCUtils<Stack<IBTreeNode> >::ins(this, (new(ctx) Stack<IBTreeNode>(ctx)), ctx, __FILEW__, __LINE__, L"")), rootNode(nullptr), btree(nullptr)
{
	push(rootNode, ctx);
	__GC_MV(this, &(this->rootNode), rootNode, IBTreeNode);
	__GC_MV(this, &(this->btree), btree, BTree);
}
void BTreeMachine::__construct_impl(IBTreeNode* rootNode, BTree* btree, ThreadContext* ctx)
{
	push(rootNode, ctx);
	__GC_MV(this, &(this->rootNode), rootNode, IBTreeNode);
	__GC_MV(this, &(this->btree), btree, BTree);
}
 BTreeMachine::~BTreeMachine() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void BTreeMachine::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"BTreeMachine", L"~BTreeMachine");
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
void BTreeMachine::removeKey(IBTreeKey* key, ThreadContext* ctx)
{
	BTreeNodeLoader* loader = btree->getLoader(ctx);
	IBTreeNode* node = this->nodeStack->peek(ctx);
	while(!node->isHasLeaf(ctx))
	{
		node = node->getNodeAtInsertPosition(key, ctx);
		push(node, ctx);
	}
	bool keyDeleted = node->removeChild(key, ctx);
	bool lastNodeEmpty = node->isEmpty(ctx);
	if(lastNodeEmpty)
	{
		loader->deleteBTreeNode(node, ctx);
	}
		else 
	{
		loader->saveBTreeNode(node, ctx);
	}
	node->endUse(ctx);
	pop(ctx);
	while(!this->nodeStack->isEmpty(ctx))
	{
		node = this->nodeStack->peek(ctx);
		if(keyDeleted || lastNodeEmpty)
		{
			keyDeleted = node->removeChild(key, ctx);
			lastNodeEmpty = node->isEmpty(ctx);
			if(lastNodeEmpty)
			{
				loader->deleteBTreeNode(node, ctx);
			}
						else 
			{
				loader->saveBTreeNode(node, ctx);
			}
		}
				else 
		{
			lastNodeEmpty = false;
			keyDeleted = false;
		}
		node->endUse(ctx);
		pop(ctx);
	}
}
void BTreeMachine::insertLeaf(BTreeLeafNode* newNode, ThreadContext* ctx)
{
	IBTreeNode* node = nodeStack->peek(ctx);
	while(!node->isHasLeaf(ctx))
	{
		node = node->getNodeAtInsertPosition(newNode->getKey(ctx), ctx);
		push(node, ctx);
	}
	if(!node->isFull(ctx))
	{
		node->addLeafNode(newNode, ctx);
	}
		else 
	{
		if(node->isFull(ctx) && node->getFilePointer(ctx) == this->rootNode->getFilePointer(ctx))
		{
			splitAndInsertLeaf2Root(node, newNode, ctx);
		}
				else 
		{
			splitAndInsertLeaf(node, newNode, ctx);
		}
	}
	this->btree->saveNode(node, ctx);
}
void BTreeMachine::push(IBTreeNode* node, ThreadContext* ctx)
{
	node->use(ctx);
	this->nodeStack->push(node, ctx);
}
IBTreeNode* BTreeMachine::pop(ThreadContext* ctx) throw() 
{
	return this->nodeStack->pop(ctx);
}
void BTreeMachine::destroy(ThreadContext* ctx)
{
	Iterator<IBTreeNode>* it = this->nodeStack->iterator(ctx);
	while(it->hasNext(ctx))
	{
		IBTreeNode* node = it->next(ctx);
		node->endUse(ctx);
	}
	this->nodeStack->clear(ctx);
}
void BTreeMachine::splitAndInsertLeaf2Root(IBTreeNode* root, IBTreeNode* newNode, ThreadContext* ctx)
{
	BTreeNodeLoader* loader = btree->getLoader(ctx);
	IBTreeNode* smallerNode = root->split(newNode, loader, ctx);
	IBTreeNode* newRoot = loader->newMaxNode(btree->getNodeCapacity(ctx), root->getFilePointer(ctx), ctx);
	newRoot->addNode(smallerNode, ctx);
	__GC_MV(this, &(this->rootNode), newRoot, IBTreeNode);
	btree->setRoot(newRoot->getFilePointer(ctx), ctx);
	btree->updateMasterSection(ctx);
	loader->saveBTreeNode(newRoot, ctx);
	newRoot->endUse(ctx);
	smallerNode->endUse(ctx);
}
void BTreeMachine::splitAndInsertLeaf(IBTreeNode* node, IBTreeNode* newNode, ThreadContext* ctx)
{
	BTreeNodeLoader* loader = btree->getLoader(ctx);
	IBTreeNode* smallerNode = node->split(newNode, loader, ctx);
	IBTreeNode* parent = getParent(node, ctx);
	if(parent->isFull(ctx))
	{
		if(parent->getFilePointer(ctx) == this->rootNode->getFilePointer(ctx))
		{
			splitAndInsertNode2Root(parent, smallerNode, ctx);
		}
				else 
		{
			splitAndInsertNode(parent, smallerNode, ctx);
		}
	}
		else 
	{
		parent->addNode(smallerNode, ctx);
		loader->saveBTreeNode(parent, ctx);
	}
	smallerNode->endUse(ctx);
}
void BTreeMachine::splitAndInsertNode2Root(IBTreeNode* root, IBTreeNode* newNode, ThreadContext* ctx)
{
	BTreeNodeLoader* loader = btree->getLoader(ctx);
	IBTreeNode* smallerNode = root->split(newNode, loader, ctx);
	IBTreeNode* newRoot = loader->newMaxNode(btree->getNodeCapacity(ctx), root->getFilePointer(ctx), ctx);
	newRoot->addNode(smallerNode, ctx);
	__GC_MV(this, &(this->rootNode), newRoot, IBTreeNode);
	btree->setRoot(newRoot->getFilePointer(ctx), ctx);
	btree->updateMasterSection(ctx);
	loader->saveBTreeNode(newRoot, ctx);
	newRoot->endUse(ctx);
	smallerNode->endUse(ctx);
}
void BTreeMachine::splitAndInsertNode(IBTreeNode* node, IBTreeNode* newNode, ThreadContext* ctx)
{
	BTreeNodeLoader* loader = btree->getLoader(ctx);
	IBTreeNode* smallerNode = node->split(newNode, loader, ctx);
	IBTreeNode* parent = getParent(node, ctx);
	if(parent->isFull(ctx))
	{
		if(parent->getFilePointer(ctx) == this->rootNode->getFilePointer(ctx))
		{
			splitAndInsertNode2Root(parent, smallerNode, ctx);
		}
				else 
		{
			splitAndInsertNode(parent, smallerNode, ctx);
		}
	}
		else 
	{
		parent->addNode(smallerNode, ctx);
		loader->saveBTreeNode(parent, ctx);
	}
	smallerNode->endUse(ctx);
}
IBTreeNode* BTreeMachine::getParent(IBTreeNode* node, ThreadContext* ctx) throw() 
{
	IBTreeNode* lastNode = nullptr;
	Iterator<IBTreeNode>* it = this->nodeStack->iterator(ctx);
	while(it->hasNext(ctx))
	{
		IBTreeNode* n = it->next(ctx);
		if(n->getFilePointer(ctx) == node->getFilePointer(ctx))
		{
			return lastNode;
		}
		lastNode = n;
	}
	return nullptr;
}
}}

