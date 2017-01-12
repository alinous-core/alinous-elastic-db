#include "includes.h"


namespace alinous {namespace btreememory {





bool MBTreeNode::__init_done = __init_static_variables();
bool MBTreeNode::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"MBTreeNode", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 MBTreeNode::MBTreeNode(IBTreeKey* key, int numNodes, ThreadContext* ctx) throw()  : IObject(ctx), AbstractMemoryBTreeNode(numNodes, nullptr, ctx), key(nullptr)
{
	__GC_MV(this, &(this->key), key, IBTreeKey);
}
void MBTreeNode::__construct_impl(IBTreeKey* key, int numNodes, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->key), key, IBTreeKey);
}
 MBTreeNode::~MBTreeNode() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void MBTreeNode::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"MBTreeNode", L"~MBTreeNode");
	__e_obj1.add(this->key, this);
	key = nullptr;
	if(!prepare){
		return;
	}
	AbstractMemoryBTreeNode::__releaseRegerences(true, ctx);
}
IBTreeNode* MBTreeNode::addLeafNode(IBTreeNode* newNode, ThreadContext* ctx)
{
	throw (new(ctx) BTreeException(ConstStr::getCNST_STR_1638(), ctx));
}
IBTreeKey* MBTreeNode::getKey(ThreadContext* ctx) throw() 
{
	return this->key;
}
void MBTreeNode::move(IBTreeNode* node, ThreadContext* ctx)
{
	putNode(node, false, true, ctx);
}
char MBTreeNode::getNodeType(ThreadContext* ctx) throw() 
{
	return IBTreeNode::BTREE_TYPE_NODE;
}
void MBTreeNode::printNode(StringBuffer* buff, int level, ThreadContext* ctx)
{
	printTab(buff, level, ctx);
	buff->append(ConstStr::getCNST_STR_1639(), ctx)->append(getKey(ctx)->toString(ctx), ctx)->append(ConstStr::getCNST_STR_1625(), ctx);
	int nextLevel = level + 1;
	int maxLoop = this->nodeUsed;
	IArrayObject<IBTreeNode>* nodes = this->nodes;
	IBTreeNode* node = 0;
	for(int i = 0; i != maxLoop; ++i)
	{
		node = nodes->get(i);
		node->printNode(buff, nextLevel, ctx);
	}
	printTab(buff, level, ctx);
	buff->append(ConstStr::getCNST_STR_1640(), ctx);
}
bool MBTreeNode::removeChild(IBTreeKey* key, ThreadContext* ctx)
{
	bool removedKey = false;
	loadChildren(ctx);
	removeNode(key, ctx);
	if(this->nodeUsed == 0)
	{
		return true;
	}
	if(this->key->equals(key, ctx))
	{
		__GC_MV(this, &(this->key), this->nodes->get(this->nodeUsed - 1)->getKey(ctx), IBTreeKey);
		removedKey = true;
	}
	return removedKey;
}
bool MBTreeNode::isEmpty(ThreadContext* ctx) throw() 
{
	return this->nodeUsed == 0;
}
void MBTreeNode::setKey(IBTreeKey* key, ThreadContext* ctx)
{
	__GC_MV(this, &(this->key), key, IBTreeKey);
}
bool MBTreeNode::hasMaxNode(ThreadContext* ctx) throw() 
{
	return false;
}
void MBTreeNode::loadChildren(ThreadContext* ctx)
{
}
INodeIterator* MBTreeNode::iterator(bool endStart, ThreadContext* ctx)
{
	return (new(ctx) MemoryNodeIterator(endStart, this, ctx));
}
ArrayList<IBTreeValue>* MBTreeNode::getValues(ThreadContext* ctx) throw() 
{
	return nullptr;
}
void MBTreeNode::unloadChildren(ThreadContext* ctx)
{
}
FileStorage* MBTreeNode::getStorage(ThreadContext* ctx) throw() 
{
	return nullptr;
}
void MBTreeNode::setStorage(FileStorage* storage, ThreadContext* ctx) throw() 
{
}
}}

