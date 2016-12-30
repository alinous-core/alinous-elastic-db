#include "includes.h"


namespace alinous {namespace btreememory {





bool MBTreeLeafNode::__init_done = __init_static_variables();
bool MBTreeLeafNode::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"MBTreeLeafNode", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 MBTreeLeafNode::MBTreeLeafNode(IBTreeKey* key, ThreadContext* ctx) throw()  : IObject(ctx), AbstractMemoryNode(ctx), key(nullptr), values(GCUtils<ArrayList<IBTreeValue> >::ins(this, (new(ctx) ArrayList<IBTreeValue>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
	__GC_MV(this, &(this->key), key, IBTreeKey);
}
void MBTreeLeafNode::__construct_impl(IBTreeKey* key, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->key), key, IBTreeKey);
}
 MBTreeLeafNode::~MBTreeLeafNode() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void MBTreeLeafNode::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"MBTreeLeafNode", L"~MBTreeLeafNode");
	__e_obj1.add(this->key, this);
	key = nullptr;
	__e_obj1.add(this->values, this);
	values = nullptr;
	if(!prepare){
		return;
	}
	AbstractMemoryNode::__releaseRegerences(true, ctx);
}
IBTreeKey* MBTreeLeafNode::getKey(ThreadContext* ctx) throw() 
{
	return this->key;
}
ArrayList<IBTreeValue>* MBTreeLeafNode::getValues(ThreadContext* ctx) throw() 
{
	return this->values;
}
bool MBTreeLeafNode::isHasLeaf(ThreadContext* ctx) throw() 
{
	return false;
}
bool MBTreeLeafNode::isFull(ThreadContext* ctx) throw() 
{
	return true;
}
IBTreeNode* MBTreeLeafNode::addLeafNode(IBTreeNode* newNode, ThreadContext* ctx)
{
	throw (new(ctx) BTreeException(ConstStr::getCNST_STR_998(), ctx));
}
IBTreeNode* MBTreeLeafNode::getNodeAtInsertPosition(IBTreeKey* key, ThreadContext* ctx)
{
	throw (new(ctx) BTreeException(ConstStr::getCNST_STR_998(), ctx));
}
void MBTreeLeafNode::setNodeUsed(int nodeUsed, ThreadContext* ctx)
{
	throw (new(ctx) BTreeException(ConstStr::getCNST_STR_998(), ctx));
}
IBTreeNode* MBTreeLeafNode::split(IBTreeNode* newNode, BTreeNodeLoader* loader, ThreadContext* ctx) throw() 
{
	return nullptr;
}
void MBTreeLeafNode::addNode(IBTreeNode* newNode, ThreadContext* ctx)
{
	throw (new(ctx) BTreeException(ConstStr::getCNST_STR_998(), ctx));
}
INodeIterator* MBTreeLeafNode::iterator(bool endStart, ThreadContext* ctx)
{
	throw (new(ctx) BTreeException(ConstStr::getCNST_STR_998(), ctx));
}
void MBTreeLeafNode::loadChildren(ThreadContext* ctx)
{
}
char MBTreeLeafNode::getNodeType(ThreadContext* ctx) throw() 
{
	return IBTreeNode::BTREE_TYPE_LEAF;
}
void MBTreeLeafNode::printNode(StringBuffer* buff, int level, ThreadContext* ctx) throw() 
{
	printTab(buff, level, ctx);
	printTab(buff, level, ctx);
	buff->append(ConstStr::getCNST_STR_1579(), ctx)->append(getKey(ctx)->toString(ctx), ctx)->append(ConstStr::getCNST_STR_1580(), ctx);
}
bool MBTreeLeafNode::removeChild(IBTreeKey* key, ThreadContext* ctx)
{
	throw (new(ctx) BTreeException(ConstStr::getCNST_STR_998(), ctx));
}
bool MBTreeLeafNode::isEmpty(ThreadContext* ctx) throw() 
{
	return false;
}
void MBTreeLeafNode::setKey(IBTreeKey* key, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->key), key, IBTreeKey);
}
bool MBTreeLeafNode::hasMaxNode(ThreadContext* ctx) throw() 
{
	return false;
}
void MBTreeLeafNode::unloadChildren(ThreadContext* ctx)
{
}
FileStorage* MBTreeLeafNode::getStorage(ThreadContext* ctx) throw() 
{
	return nullptr;
}
void MBTreeLeafNode::setStorage(FileStorage* storage, ThreadContext* ctx) throw() 
{
}
}}

