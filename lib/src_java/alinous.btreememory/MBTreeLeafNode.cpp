#include "include/global.h"


#include "alinous.btree/BTreeException.h"
#include "alinous.buffer.storage/FileStorageEntry.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "java.lang/Comparable.h"
#include "alinous.btree/IBTreeKey.h"
#include "alinous.btree.scan/INodeIterator.h"
#include "alinous.lock/LockObject.h"
#include "alinous.lock/ConcurrentGate.h"
#include "alinous.buffer.storage/FileAccessWrapper.h"
#include "alinous.buffer.storage/FileStorageBlock.h"
#include "alinous.buffer.storage/IFileStorage.h"
#include "alinous.buffer.storage/FileStorageEntryWriter.h"
#include "alinous.buffer.storage/FileStorageEntryReader.h"
#include "alinous.buffer.storage/FileStorage.h"
#include "alinous.buffer/FifoElement.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.buffer/FifoIterator.h"
#include "alinous.buffer/FifoList.h"
#include "java.util/BitSet.h"
#include "alinous.btree/BTreeCacheArray.h"
#include "alinous.buffer/HashArrayListIterator.h"
#include "alinous.buffer/HashArrayList.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.btree/IBTreeNode.h"
#include "alinous.btree/BTreeCacheRecord.h"
#include "alinous.btree/BTreeGlobalCache.h"
#include "alinous.btree/NodeRef.h"
#include "alinous.btree/AbstractNode.h"
#include "alinous.btree/BTreeNodeHandler.h"
#include "alinous.btree/AbstractBTreeNode.h"
#include "alinous.btree/BTreeNode.h"
#include "alinous.btree/BTreeMaxNode.h"
#include "alinous.btree/AbstractBTreeLeafContainer.h"
#include "alinous.btree/BTreeLeafContainer.h"
#include "alinous.btree/BTreeMaxLeafContainer.h"
#include "alinous.btree/BTreeValues.h"
#include "alinous.btree/KeyValue.h"
#include "alinous.btree/BTreeLeafNode.h"
#include "alinous.btree/BTreeNodeLoader.h"
#include "alinous.btreememory/AbstractMemoryNode.h"
#include "alinous.btreememory/AbstractMemoryBTreeLeafContainer.h"
#include "alinous.btreememory/MBTreeLeafContainer.h"
#include "alinous.btreememory/MBTreeMaxLeafContainer.h"
#include "alinous.btreememory/AbstractMemoryBTreeNode.h"
#include "alinous.btreememory/MBTreeNode.h"
#include "alinous.btree/IBTree.h"
#include "alinous.btreememory/MBTreeLeafNode.h"
#include "alinous.btreememory/MBTreeMaxNode.h"
#include "alinous.btreememory/MemoryBTreeMachine.h"
#include "alinous.btreememory/BTreeOnMemory.h"

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
	throw (new(ctx) BTreeException(ConstStr::getCNST_STR_1023(), ctx));
}
IBTreeNode* MBTreeLeafNode::getNodeAtInsertPosition(IBTreeKey* key, ThreadContext* ctx)
{
	throw (new(ctx) BTreeException(ConstStr::getCNST_STR_1023(), ctx));
}
void MBTreeLeafNode::setNodeUsed(int nodeUsed, ThreadContext* ctx)
{
	throw (new(ctx) BTreeException(ConstStr::getCNST_STR_1023(), ctx));
}
IBTreeNode* MBTreeLeafNode::split(IBTreeNode* newNode, BTreeNodeLoader* loader, ThreadContext* ctx) throw() 
{
	return nullptr;
}
void MBTreeLeafNode::addNode(IBTreeNode* newNode, ThreadContext* ctx)
{
	throw (new(ctx) BTreeException(ConstStr::getCNST_STR_1023(), ctx));
}
INodeIterator* MBTreeLeafNode::iterator(bool endStart, ThreadContext* ctx)
{
	throw (new(ctx) BTreeException(ConstStr::getCNST_STR_1023(), ctx));
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
	buff->append(ConstStr::getCNST_STR_1656(), ctx)->append(getKey(ctx)->toString(ctx), ctx)->append(ConstStr::getCNST_STR_1657(), ctx);
}
bool MBTreeLeafNode::removeChild(IBTreeKey* key, ThreadContext* ctx)
{
	throw (new(ctx) BTreeException(ConstStr::getCNST_STR_1023(), ctx));
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
void MBTreeLeafNode::save(ThreadContext* ctx) throw() 
{
}
}}

