#include "includes.h"


namespace alinous {namespace btreememory {namespace scan {





bool MemoryBTreeScanner::__init_done = __init_static_variables();
bool MemoryBTreeScanner::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"MemoryBTreeScanner", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 MemoryBTreeScanner::MemoryBTreeScanner(BTreeOnMemory* btree, ThreadContext* ctx) throw()  : IObject(ctx), btree(nullptr), stack(GCUtils<Stack<INodeIterator> >::ins(this, (new(ctx) Stack<INodeIterator>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
	__GC_MV(this, &(this->btree), btree, BTreeOnMemory);
}
void MemoryBTreeScanner::__construct_impl(BTreeOnMemory* btree, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->btree), btree, BTreeOnMemory);
}
 MemoryBTreeScanner::~MemoryBTreeScanner() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void MemoryBTreeScanner::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"MemoryBTreeScanner", L"~MemoryBTreeScanner");
	__e_obj1.add(this->btree, this);
	btree = nullptr;
	__e_obj1.add(this->stack, this);
	stack = nullptr;
	if(!prepare){
		return;
	}
}
void MemoryBTreeScanner::startScan(bool endStart, ThreadContext* ctx)
{
	Stack<INodeIterator>* stack = this->stack;
	BTreeOnMemory* btree = this->btree;
	if(btree->isEmpty(ctx))
	{
		return;
	}
	if(!stack->isEmpty(ctx))
	{
		endScan(ctx);
	}
	IBTreeNode* node = btree->getRootNode(ctx);
	INodeIterator* iterator = node->iterator(endStart, ctx);
	stack->push(iterator, ctx);
}
void MemoryBTreeScanner::startScan(IBTreeKey* key, ThreadContext* ctx)
{
	BTreeOnMemory* btree = this->btree;
	if(btree->isEmpty(ctx))
	{
		return;
	}
	Stack<INodeIterator>* stack = this->stack;
	if(!stack->isEmpty(ctx))
	{
		endScan(ctx);
	}
	IBTreeNode* node = btree->getRootNode(ctx);
	INodeIterator* iterator = node->iterator(false, ctx);
	iterator->gotoNode(key, ctx);
	if(iterator->getType(ctx) != INodeIterator::IT_LEAF_CONTAINER)
	{
		iterator->incCurrent(ctx);
	}
	stack->push(iterator, ctx);
	gotoKey(key, node, ctx);
}
IBTreeNode* MemoryBTreeScanner::next(ThreadContext* ctx)
{
	INodeIterator* it = this->stack->peek(ctx);
	{
		try
		{
			return static_cast<MBTreeLeafNode*>(it->next(ctx));
		}
		catch(VariableException* e)
		{
			throw (new(ctx) BTreeException(ConstStr::getCNST_STR_1654(), e, ctx));
		}
		catch(InterruptedException* e)
		{
			throw (new(ctx) BTreeException(ConstStr::getCNST_STR_1654(), e, ctx));
		}
		catch(IOException* e)
		{
			throw (new(ctx) BTreeException(ConstStr::getCNST_STR_1654(), e, ctx));
		}
		catch(AlinousException* e)
		{
			throw (new(ctx) BTreeException(ConstStr::getCNST_STR_1654(), e, ctx));
		}
	}
}
bool MemoryBTreeScanner::hasNext(ThreadContext* ctx)
{
	Stack<INodeIterator>* stack = this->stack;
	if(stack->isEmpty(ctx))
	{
		return false;
	}
	INodeIterator* it = stack->peek(ctx);
	int ittype = it->getType(ctx);
	switch(ittype) {
	case INodeIterator::IT_LEAF_CONTAINER:
		if(it->hasNext(ctx))
		{
			return true;
		}
		break ;
	default:
		if(it->hasNext(ctx))
		{
			gotoNextLeafContainer(ctx);
			return true;
		}
		break ;
	}
	it = stack->pop(ctx);
	it->dispose(ctx);
	if(stack->isEmpty(ctx))
	{
		return false;
	}
	gotoNextLeafContainer(ctx);
	if(stack->isEmpty(ctx))
	{
		return false;
	}
	it = stack->peek(ctx);
	return it->hasNext(ctx);
}
void MemoryBTreeScanner::endScan(ThreadContext* ctx)
{
	Stack<INodeIterator>* stack = this->stack;
	Iterator<INodeIterator>* it = stack->iterator(ctx);
	INodeIterator* nit = 0;
	while(it->hasNext(ctx))
	{
		nit = it->next(ctx);
		nit->dispose(ctx);
	}
	stack->clear(ctx);
}
void MemoryBTreeScanner::gotoKey(IBTreeKey* key, IBTreeNode* rootNode, ThreadContext* ctx)
{
	IBTreeNode* node = rootNode;
	Stack<INodeIterator>* stack = this->stack;
	INodeIterator* it = 0;
	while(node->getNodeType(ctx) != IBTreeNode::BTREE_TYPE_LEAF_CONTAINER && node->getNodeType(ctx) != IBTreeNode::BTREE_TYPE_MAX_LEAF_CONTAINER)
	{
		node = node->getNodeAtInsertPosition(key, ctx);
		it = node->iterator(false, ctx);
		it->gotoNode(key, ctx);
		if(it->getType(ctx) != INodeIterator::IT_LEAF_CONTAINER)
		{
			it->incCurrent(ctx);
		}
		stack->push(it, ctx);
	}
}
void MemoryBTreeScanner::gotoNextLeafContainer(ThreadContext* ctx)
{
	Stack<INodeIterator>* stack = this->stack;
	INodeIterator* it = stack->peek(ctx);
	while(!it->hasNext(ctx))
	{
		stack->pop(ctx);
		it->dispose(ctx);
		if(stack->isEmpty(ctx))
		{
			return;
		}
		it = stack->peek(ctx);
	}
	IBTreeNode* node = it->next(ctx);
	while(node->getNodeType(ctx) != IBTreeNode::BTREE_TYPE_LEAF_CONTAINER && node->getNodeType(ctx) != IBTreeNode::BTREE_TYPE_MAX_LEAF_CONTAINER)
	{
		it = node->iterator(false, ctx);
		stack->push(it, ctx);
		node = it->next(ctx);
	}
	it = node->iterator(false, ctx);
	stack->push(it, ctx);
}
}}}

