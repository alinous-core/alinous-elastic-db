#include "include/global.h"


#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "java.lang/Comparable.h"
#include "alinous.btree/IBTreeKey.h"
#include "alinous.buffer.storage/IFileStorage.h"
#include "alinous.buffer.storage/FileStorage.h"
#include "alinous.buffer/FifoElement.h"
#include "alinous.lock/LockObject.h"
#include "alinous.btree.scan/INodeIterator.h"
#include "alinous.btree.scan/AbstractNodeIterator.h"
#include "alinous.btree.scan/NodeIterator.h"
#include "alinous.btree/NodeRef.h"
#include "alinous.btree/BTreeException.h"
#include "alinous.btree/IBTreeNode.h"
#include "alinous.btree/AbstractNode.h"
#include "alinous.btree/BTreeNodeHandler.h"
#include "alinous.btree/AbstractBTreeNode.h"
#include "alinous.btree/BTreeNode.h"
#include "alinous.btree/BTreeNodeLoader.h"
#include "alinous.btree/BTreeMaxNode.h"
#include "alinous.btree.scan/MaxNodeIterator.h"
#include "alinous.btree/IBTree.h"
#include "alinous.btree.scan/BTreeScanner.h"
#include "alinous.btree/AbstractBTreeLeafContainer.h"
#include "alinous.btree.scan/LeafContainerIterator.h"

namespace alinous {namespace btree {namespace scan {





bool BTreeScanner::__init_done = __init_static_variables();
bool BTreeScanner::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"BTreeScanner", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 BTreeScanner::BTreeScanner(IBTree* btree, ThreadContext* ctx) throw()  : IObject(ctx), btree(nullptr), stack(GCUtils<Stack<INodeIterator> >::ins(this, (new(ctx) Stack<INodeIterator>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
	__GC_MV(this, &(this->btree), btree, IBTree);
}
void BTreeScanner::__construct_impl(IBTree* btree, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->btree), btree, IBTree);
}
 BTreeScanner::~BTreeScanner() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void BTreeScanner::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"BTreeScanner", L"~BTreeScanner");
	__e_obj1.add(this->btree, this);
	btree = nullptr;
	__e_obj1.add(this->stack, this);
	stack = nullptr;
	if(!prepare){
		return;
	}
}
void BTreeScanner::startScan(bool endStart, ThreadContext* ctx)
{
	if(this->btree->isEmpty(ctx))
	{
		return;
	}
	if(!this->stack->isEmpty(ctx))
	{
		endScan(ctx);
	}
	IBTreeNode* node = this->btree->getRootNode(ctx);
	INodeIterator* iterator = node->iterator(endStart, ctx);
	this->stack->push(iterator, ctx);
	node->endUse(ctx);
}
void BTreeScanner::startScan(IBTreeKey* key, ThreadContext* ctx)
{
	if(this->btree->isEmpty(ctx))
	{
		return;
	}
	if(!this->stack->isEmpty(ctx))
	{
		endScan(ctx);
	}
	IBTreeNode* node = this->btree->getRootNode(ctx);
	INodeIterator* iterator = node->iterator(false, ctx);
	iterator->gotoNode(key, ctx);
	if(iterator->getType(ctx) != INodeIterator::IT_LEAF_CONTAINER)
	{
		iterator->incCurrent(ctx);
	}
	node->endUse(ctx);
	this->stack->push(iterator, ctx);
	gotoKey(key, node, ctx);
}
IBTreeNode* BTreeScanner::next(ThreadContext* ctx)
{
	INodeIterator* it = this->stack->peek(ctx);
	{
		try
		{
			return it->next(ctx);
		}
		catch(VariableException* e)
		{
			throw (new(ctx) BTreeException(ConstStr::getCNST_STR_1668(), e, ctx));
		}
		catch(InterruptedException* e)
		{
			throw (new(ctx) BTreeException(ConstStr::getCNST_STR_1668(), e, ctx));
		}
		catch(IOException* e)
		{
			throw (new(ctx) BTreeException(ConstStr::getCNST_STR_1668(), e, ctx));
		}
		catch(AlinousException* e)
		{
			throw (new(ctx) BTreeException(ConstStr::getCNST_STR_1668(), e, ctx));
		}
	}
}
bool BTreeScanner::hasNext(ThreadContext* ctx)
{
	if(this->stack->isEmpty(ctx))
	{
		return false;
	}
	INodeIterator* it = this->stack->peek(ctx);
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
	it = this->stack->pop(ctx);
	it->dispose(ctx);
	if(this->stack->isEmpty(ctx))
	{
		return false;
	}
	gotoNextLeafContainer(ctx);
	if(this->stack->isEmpty(ctx))
	{
		return false;
	}
	it = this->stack->peek(ctx);
	return it->hasNext(ctx);
}
void BTreeScanner::endScan(ThreadContext* ctx)
{
	Iterator<INodeIterator>* it = this->stack->iterator(ctx);
	while(it->hasNext(ctx))
	{
		INodeIterator* nit = it->next(ctx);
		nit->dispose(ctx);
	}
	this->stack->clear(ctx);
}
void BTreeScanner::gotoKey(IBTreeKey* key, IBTreeNode* rootNode, ThreadContext* ctx)
{
	IBTreeNode* node = rootNode;
	while(node->getNodeType(ctx) != IBTreeNode::BTREE_TYPE_LEAF_CONTAINER && node->getNodeType(ctx) != IBTreeNode::BTREE_TYPE_MAX_LEAF_CONTAINER)
	{
		node = node->getNodeAtInsertPosition(key, ctx);
		INodeIterator* it = node->iterator(false, ctx);
		it->gotoNode(key, ctx);
		if(it->getType(ctx) != INodeIterator::IT_LEAF_CONTAINER)
		{
			it->incCurrent(ctx);
		}
		this->stack->push(it, ctx);
	}
}
void BTreeScanner::gotoNextLeafContainer(ThreadContext* ctx)
{
	INodeIterator* it = this->stack->peek(ctx);
	while(!it->hasNext(ctx))
	{
		this->stack->pop(ctx);
		it->dispose(ctx);
		if(this->stack->isEmpty(ctx))
		{
			return;
		}
		it = this->stack->peek(ctx);
	}
	IBTreeNode* node = it->next(ctx);
	while(node->getNodeType(ctx) != IBTreeNode::BTREE_TYPE_LEAF_CONTAINER && node->getNodeType(ctx) != IBTreeNode::BTREE_TYPE_MAX_LEAF_CONTAINER)
	{
		it = node->iterator(false, ctx);
		this->stack->push(it, ctx);
		node = it->next(ctx);
	}
	it = node->iterator(false, ctx);
	this->stack->push(it, ctx);
}
void BTreeScanner::__cleanUp(ThreadContext* ctx){
}
}}}

