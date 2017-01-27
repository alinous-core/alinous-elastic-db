#include "includes.h"


namespace alinous {namespace btreememory {





bool MBTreeMaxNode::__init_done = __init_static_variables();
bool MBTreeMaxNode::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"MBTreeMaxNode", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 MBTreeMaxNode::MBTreeMaxNode(int numNodes, IArrayObject<IBTreeNode>* nodes, IBTreeNode* max, ThreadContext* ctx) throw()  : IObject(ctx), AbstractMemoryBTreeNode(numNodes, nodes, ctx), max(nullptr)
{
	__GC_MV(this, &(this->max), max, IBTreeNode);
}
void MBTreeMaxNode::__construct_impl(int numNodes, IArrayObject<IBTreeNode>* nodes, IBTreeNode* max, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->max), max, IBTreeNode);
}
 MBTreeMaxNode::~MBTreeMaxNode() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void MBTreeMaxNode::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"MBTreeMaxNode", L"~MBTreeMaxNode");
	__e_obj1.add(this->max, this);
	max = nullptr;
	if(!prepare){
		return;
	}
	AbstractMemoryBTreeNode::__releaseRegerences(true, ctx);
}
IBTreeNode* MBTreeMaxNode::getMax(ThreadContext* ctx) throw() 
{
	return max;
}
int MBTreeMaxNode::getNodeAtInsertPositionNumber(IBTreeKey* key, ThreadContext* ctx)
{
	int pos = nodeToGoDown(key, ctx);
	return pos;
}
IBTreeNode* MBTreeMaxNode::getNodeAtInsertPosition(IBTreeKey* key, ThreadContext* ctx)
{
	int pos = nodeToGoDown(key, ctx);
	IBTreeNode* node = pos == this->nodeUsed ? this->max : this->nodes->get(pos);
	return node;
}
IBTreeNode* MBTreeMaxNode::addLeafNode(IBTreeNode* newNode, ThreadContext* ctx)
{
	throw (new(ctx) BTreeException(ConstStr::getCNST_STR_1638(), ctx));
}
IBTreeKey* MBTreeMaxNode::getKey(ThreadContext* ctx) throw() 
{
	return nullptr;
}
void MBTreeMaxNode::printNode(StringBuffer* buff, int level, ThreadContext* ctx)
{
	printTab(buff, level, ctx);
	buff->append(ConstStr::getCNST_STR_1639(), ctx)->append(ConstStr::getCNST_STR_1640(), ctx)->append(ConstStr::getCNST_STR_1636(), ctx);
	int nextLevel = level + 1;
	int maxLoop = this->nodeUsed;
	IBTreeNode* node = 0;
	for(int i = 0; i != maxLoop; ++i)
	{
		node = this->nodes->get(i);
		node->printNode(buff, nextLevel, ctx);
	}
	node = this->max;
	node->printNode(buff, nextLevel, ctx);
	printTab(buff, level, ctx);
	buff->append(ConstStr::getCNST_STR_1641(), ctx);
}
bool MBTreeMaxNode::removeChild(IBTreeKey* key, ThreadContext* ctx)
{
	bool removedKey = false;
	removeNode(key, ctx);
	if(this->nodeUsed == 0)
	{
		return false;
	}
	return removedKey;
}
bool MBTreeMaxNode::isEmpty(ThreadContext* ctx) throw() 
{
	return false;
}
void MBTreeMaxNode::setKey(IBTreeKey* key, ThreadContext* ctx)
{
	throw (new(ctx) BTreeException(ConstStr::getCNST_STR_1642(), ctx));
}
bool MBTreeMaxNode::hasMaxNode(ThreadContext* ctx) throw() 
{
	return true;
}
char MBTreeMaxNode::getNodeType(ThreadContext* ctx) throw() 
{
	return IBTreeNode::BTREE_TYPE_MAX_NODE;
}
INodeIterator* MBTreeMaxNode::iterator(bool endStart, ThreadContext* ctx)
{
	return (new(ctx) MemoryMaxNodeIterator(endStart, this, ctx));
}
void MBTreeMaxNode::loadChildren(ThreadContext* ctx)
{
}
ArrayList<IBTreeValue>* MBTreeMaxNode::getValues(ThreadContext* ctx) throw() 
{
	return nullptr;
}
void MBTreeMaxNode::unloadChildren(ThreadContext* ctx)
{
}
FileStorage* MBTreeMaxNode::getStorage(ThreadContext* ctx) throw() 
{
	return nullptr;
}
void MBTreeMaxNode::setStorage(FileStorage* storage, ThreadContext* ctx) throw() 
{
}
}}

