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
#include "alinous.buffer.storage/IFileStorage.h"
#include "alinous.buffer.storage/FileStorage.h"
#include "alinous.btree/BTreeNodeLoader.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.btree/IBTreeNode.h"
#include "alinous.btreememory/AbstractMemoryNode.h"
#include "alinous.btreememory/AbstractMemoryBTreeLeafContainer.h"
#include "alinous.btreememory/MBTreeLeafContainer.h"

namespace alinous {namespace btreememory {





bool MBTreeLeafContainer::__init_done = __init_static_variables();
bool MBTreeLeafContainer::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"MBTreeLeafContainer", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 MBTreeLeafContainer::MBTreeLeafContainer(IBTreeKey* key, int numNodes, IArrayObject<IBTreeNode>* nodes, ThreadContext* ctx) throw()  : IObject(ctx), AbstractMemoryBTreeLeafContainer(numNodes, nodes, ctx), key(nullptr)
{
	__GC_MV(this, &(this->key), key, IBTreeKey);
}
void MBTreeLeafContainer::__construct_impl(IBTreeKey* key, int numNodes, IArrayObject<IBTreeNode>* nodes, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->key), key, IBTreeKey);
}
 MBTreeLeafContainer::~MBTreeLeafContainer() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void MBTreeLeafContainer::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"MBTreeLeafContainer", L"~MBTreeLeafContainer");
	__e_obj1.add(this->key, this);
	key = nullptr;
	if(!prepare){
		return;
	}
	AbstractMemoryBTreeLeafContainer::__releaseRegerences(true, ctx);
}
IBTreeKey* MBTreeLeafContainer::getKey(ThreadContext* ctx) throw() 
{
	return this->key;
}
void MBTreeLeafContainer::addNode(IBTreeNode* newNode, ThreadContext* ctx)
{
	throw (new(ctx) BTreeException(ConstStr::getCNST_STR_1023(), ctx));
}
char MBTreeLeafContainer::getNodeType(ThreadContext* ctx) throw() 
{
	return IBTreeNode::BTREE_TYPE_LEAF_CONTAINER;
}
void MBTreeLeafContainer::printNode(StringBuffer* buff, int level, ThreadContext* ctx)
{
	printTab(buff, level, ctx);
	buff->append(ConstStr::getCNST_STR_1649(), ctx)->append(getKey(ctx)->toString(ctx), ctx)->append(ConstStr::getCNST_STR_1650(), ctx);
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
	buff->append(ConstStr::getCNST_STR_1651(), ctx);
}
bool MBTreeLeafContainer::removeChild(IBTreeKey* key, ThreadContext* ctx)
{
	bool removedKey = false;
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
IBTreeNode* MBTreeLeafContainer::removeNode(IBTreeKey* key, ThreadContext* ctx)
{
	int index = indexOf(key, ctx);
	if(index < 0)
	{
		return nullptr;
	}
	IBTreeNode* node = this->nodes->get(index);
	removeNode(index, 1, ctx);
	return node;
}
int MBTreeLeafContainer::indexOf(IBTreeKey* value, ThreadContext* ctx) throw() 
{
	__builtin_prefetch_array_root(this->nodes, 0, 1);
	IArrayObject<IBTreeNode>* _root = this->nodes;
	int maxLoop = this->nodeUsed;
	int i = 0;
	for(i = 0; i < maxLoop; ++i)
	{
		__builtin_prefetch(_root->get(i)->getKey(ctx));
	}
	for(i = 0; i < maxLoop; ++i)
	{
		if(_root->get(i)->getKey(ctx)->compareTo(value, ctx) >= 0)
		{
			return i;
		}
	}
	return -1;
}
void MBTreeLeafContainer::removeNode(int index, int count, ThreadContext* ctx)
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
bool MBTreeLeafContainer::isEmpty(ThreadContext* ctx) throw() 
{
	return this->nodeUsed == 0;
}
void MBTreeLeafContainer::setKey(IBTreeKey* key, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->key), key, IBTreeKey);
}
bool MBTreeLeafContainer::hasMaxNode(ThreadContext* ctx) throw() 
{
	return false;
}
void MBTreeLeafContainer::loadChildren(ThreadContext* ctx)
{
}
ArrayList<IBTreeValue>* MBTreeLeafContainer::getValues(ThreadContext* ctx) throw() 
{
	return nullptr;
}
void MBTreeLeafContainer::unloadChildren(ThreadContext* ctx)
{
}
FileStorage* MBTreeLeafContainer::getStorage(ThreadContext* ctx) throw() 
{
	return nullptr;
}
void MBTreeLeafContainer::setStorage(FileStorage* storage, ThreadContext* ctx) throw() 
{
}
void MBTreeLeafContainer::save(ThreadContext* ctx) throw() 
{
}
void MBTreeLeafContainer::__cleanUp(ThreadContext* ctx){
}
}}

