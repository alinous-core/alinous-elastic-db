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
#include "alinous.btreememory/MBTreeMaxLeafContainer.h"

namespace alinous {namespace btreememory {





bool MBTreeMaxLeafContainer::__init_done = __init_static_variables();
bool MBTreeMaxLeafContainer::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"MBTreeMaxLeafContainer", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 MBTreeMaxLeafContainer::MBTreeMaxLeafContainer(int numNodes, IArrayObject<IBTreeNode>* nodes, ThreadContext* ctx) throw()  : IObject(ctx), AbstractMemoryBTreeLeafContainer(numNodes, nodes, ctx)
{
}
void MBTreeMaxLeafContainer::__construct_impl(int numNodes, IArrayObject<IBTreeNode>* nodes, ThreadContext* ctx) throw() 
{
}
 MBTreeMaxLeafContainer::~MBTreeMaxLeafContainer() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void MBTreeMaxLeafContainer::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	AbstractMemoryBTreeLeafContainer::__releaseRegerences(true, ctx);
}
IBTreeKey* MBTreeMaxLeafContainer::getKey(ThreadContext* ctx) throw() 
{
	return nullptr;
}
void MBTreeMaxLeafContainer::addNode(IBTreeNode* newNode, ThreadContext* ctx)
{
	throw (new(ctx) BTreeException(ConstStr::getCNST_STR_1050(), ctx));
}
char MBTreeMaxLeafContainer::getNodeType(ThreadContext* ctx) throw() 
{
	return IBTreeNode::BTREE_TYPE_MAX_LEAF_CONTAINER;
}
bool MBTreeMaxLeafContainer::removeChild(IBTreeKey* key, ThreadContext* ctx)
{
	bool removedKey = false;
	removeNode(key, ctx);
	if(this->nodeUsed == 0)
	{
		return false;
	}
	return removedKey;
}
IBTreeNode* MBTreeMaxLeafContainer::removeNode(IBTreeKey* key, ThreadContext* ctx)
{
	int index = indexOf(key, ctx);
	if(index < 0)
	{
		return nullptr;
	}
	removeNode(index, 1, ctx);
	return this->nodes->get(index);
}
int MBTreeMaxLeafContainer::indexOf(IBTreeKey* value, ThreadContext* ctx) throw() 
{
	IArrayObject<IBTreeNode>* _root = this->nodes;
	int maxLoop = this->nodeUsed;
	int i = 0;
	__builtin_prefetch(_root);
	for(; i < maxLoop; ++i)
	{
		__builtin_prefetch(_root->get(i)->getKey(ctx));
	}
	i = 0;
	for(; i < maxLoop; ++i)
	{
		if(_root->get(i)->getKey(ctx)->compareTo(value, ctx) >= 0)
		{
			return i;
		}
	}
	return -1;
}
void MBTreeMaxLeafContainer::removeNode(int index, int count, ThreadContext* ctx)
{
	__builtin_prefetch_array_root(this->nodes, 1, 1);
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
}
void MBTreeMaxLeafContainer::printNode(StringBuffer* buff, int level, ThreadContext* ctx)
{
	printTab(buff, level, ctx);
	buff->append(ConstStr::getCNST_STR_1664(), ctx)->append(ConstStr::getCNST_STR_1658(), ctx)->append(ConstStr::getCNST_STR_1654(), ctx);
	int nextLevel = level + 1;
	int maxLoop = this->nodeUsed;
	IBTreeNode* node = 0;
	for(int i = 0; i != maxLoop; ++i)
	{
		node = this->nodes->get(i);
		node->printNode(buff, nextLevel, ctx);
	}
	printTab(buff, level, ctx);
	buff->append(ConstStr::getCNST_STR_1665(), ctx);
}
bool MBTreeMaxLeafContainer::isEmpty(ThreadContext* ctx) throw() 
{
	return false;
}
void MBTreeMaxLeafContainer::setKey(IBTreeKey* key, ThreadContext* ctx)
{
	throw (new(ctx) BTreeException(ConstStr::getCNST_STR_1660(), ctx));
}
bool MBTreeMaxLeafContainer::hasMaxNode(ThreadContext* ctx) throw() 
{
	return false;
}
void MBTreeMaxLeafContainer::loadChildren(ThreadContext* ctx)
{
}
ArrayList<IBTreeValue>* MBTreeMaxLeafContainer::getValues(ThreadContext* ctx) throw() 
{
	return nullptr;
}
void MBTreeMaxLeafContainer::unloadChildren(ThreadContext* ctx)
{
}
FileStorage* MBTreeMaxLeafContainer::getStorage(ThreadContext* ctx) throw() 
{
	return nullptr;
}
void MBTreeMaxLeafContainer::setStorage(FileStorage* storage, ThreadContext* ctx) throw() 
{
}
void MBTreeMaxLeafContainer::save(ThreadContext* ctx) throw() 
{
}
void MBTreeMaxLeafContainer::__cleanUp(ThreadContext* ctx){
}
}}

