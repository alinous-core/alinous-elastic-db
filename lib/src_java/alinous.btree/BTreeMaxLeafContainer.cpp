#include "include/global.h"


#include "alinous.buffer/FifoElement.h"
#include "alinous.buffer.storage/FileStorageEntry.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.lock/LockObject.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "java.lang/Comparable.h"
#include "alinous.btree/IBTreeKey.h"
#include "alinous.btree.scan/INodeIterator.h"
#include "alinous.buffer.storage/IFileStorage.h"
#include "alinous.buffer.storage/FileStorage.h"
#include "alinous.buffer/FifoList.h"
#include "alinous.buffer/FifoIterator.h"
#include "alinous.btree/BTreeCacheArray.h"
#include "alinous.btree/BTreeException.h"
#include "alinous.buffer/HashArrayList.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.btree/IBTreeNode.h"
#include "alinous.btree/BTreeCacheRecord.h"
#include "alinous.btree/BTreeGlobalCache.h"
#include "alinous.btree.scan/AbstractNodeIterator.h"
#include "alinous.btree.scan/NodeIterator.h"
#include "alinous.btree/AbstractNode.h"
#include "alinous.btree/BTreeNodeHandler.h"
#include "alinous.btree/AbstractBTreeNode.h"
#include "alinous.btree/BTreeNode.h"
#include "alinous.btree.scan/MaxNodeIterator.h"
#include "alinous.btree/BTreeMaxNode.h"
#include "alinous.btree/AbstractBTreeLeafContainer.h"
#include "alinous.btree/BTreeMaxLeafContainer.h"
#include "alinous.btree/BTreeValues.h"
#include "alinous.btree/KeyValue.h"
#include "alinous.btree/BTreeLeafNode.h"
#include "alinous.btree/BTreeNodeLoader.h"
#include "alinous.btree/NodeRef.h"
#include "alinous.btree/BTreeLeafContainer.h"
#include "alinous.btree/IBTree.h"
#include "alinous.btree/TimestampValue.h"
#include "alinous.btree/IntKey.h"
#include "alinous.btree/IntValue.h"
#include "alinous.btree/LongValue.h"
#include "alinous.btree/StringValue.h"
#include "alinous.btree/DoubleValue.h"
#include "alinous.btree/LongKey.h"
#include "alinous.btree/StringKey.h"
#include "alinous.btree/DoubleKey.h"
#include "alinous.btree/TimestampKey.h"
#include "alinous.btree/KeyValueFactory.h"
#include "alinous.btree/BTree.h"
#include "alinous.btree/BTreeMachine.h"

namespace alinous {namespace btree {





bool BTreeMaxLeafContainer::__init_done = __init_static_variables();
bool BTreeMaxLeafContainer::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"BTreeMaxLeafContainer", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 BTreeMaxLeafContainer::BTreeMaxLeafContainer(int numNodes, IArrayObject<NodeRef>* nodes, LockObject* sync, BTreeNodeLoader* loader, FifoElement<IBTreeNode>* fifoElement, ThreadContext* ctx) throw()  : IObject(ctx), AbstractBTreeLeafContainer(numNodes, nodes, loader, sync, loader->getBlockSize(ctx), fifoElement, ctx)
{
}
void BTreeMaxLeafContainer::__construct_impl(int numNodes, IArrayObject<NodeRef>* nodes, LockObject* sync, BTreeNodeLoader* loader, FifoElement<IBTreeNode>* fifoElement, ThreadContext* ctx) throw() 
{
}
 BTreeMaxLeafContainer::~BTreeMaxLeafContainer() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void BTreeMaxLeafContainer::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	AbstractBTreeLeafContainer::__releaseRegerences(true, ctx);
}
int BTreeMaxLeafContainer::nodeSize(ThreadContext* ctx) throw() 
{
	int total = 1 + 4 + 4 + (this->length * 8);
	return total;
}
FileStorageEntry* BTreeMaxLeafContainer::toFileStorageEntry(FileStorageEntryBuilder* builder, FileStorageEntry* entry, ThreadContext* ctx) throw() 
{
	builder->reloadBuffer(nodeSize(ctx), ctx);
	builder->putByte(IBTreeNode::BTREE_TYPE_MAX_LEAF_CONTAINER, ctx);
	builder->putInt(length, ctx);
	builder->putInt(this->nodeUsed, ctx);
	int maxLoop = this->length;
	for(int i = 0; i != maxLoop; ++i)
	{
		if(this->nodes->get(i) != nullptr)
		{
			builder->putLong(this->nodes->get(i)->filePointer, ctx);
		}
				else 
		{
			builder->putLong((long long)0, ctx);
		}
	}
	return builder->toEntry(entry, this->getFilePointer(ctx), ctx);
}
IBTreeKey* BTreeMaxLeafContainer::getKey(ThreadContext* ctx) throw() 
{
	return nullptr;
}
void BTreeMaxLeafContainer::addNode(IBTreeNode* newNode, ThreadContext* ctx)
{
	throw (new(ctx) BTreeException(ConstStr::getCNST_STR_1050(), ctx));
}
char BTreeMaxLeafContainer::getNodeType(ThreadContext* ctx) throw() 
{
	return IBTreeNode::BTREE_TYPE_MAX_LEAF_CONTAINER;
}
void BTreeMaxLeafContainer::printNode(StringBuffer* buff, int level, ThreadContext* ctx)
{
	printTab(buff, level, ctx);
	buff->append(ConstStr::getCNST_STR_1664(), ctx)->append(ConstStr::getCNST_STR_1658(), ctx)->append(ConstStr::getCNST_STR_1654(), ctx);
	int nextLevel = level + 1;
	int maxLoop = this->nodeUsed;
	for(int i = 0; i != maxLoop; ++i)
	{
		NodeRef* ref = this->nodes->get(i);
		IBTreeNode* node = this->loader->loadBTreeNode(ref->filePointer, ctx);
		node->printNode(buff, nextLevel, ctx);
		node->endUse(ctx);
	}
	printTab(buff, level, ctx);
	buff->append(ConstStr::getCNST_STR_1665(), ctx);
}
bool BTreeMaxLeafContainer::removeChild(IBTreeKey* key, ThreadContext* ctx)
{
	bool removedKey = false;
	loadChildren(ctx);
	IBTreeNode* deletedNode = this->nodeHandler->removeNode(key, ctx);
	if(deletedNode != nullptr)
	{
		this->loader->deleteBTreeNode(deletedNode, ctx);
		deletedNode->endUse(ctx);
	}
	if(this->nodeUsed == 0)
	{
		return false;
	}
	return removedKey;
}
bool BTreeMaxLeafContainer::isEmpty(ThreadContext* ctx) throw() 
{
	return false;
}
void BTreeMaxLeafContainer::setKey(IBTreeKey* key, ThreadContext* ctx)
{
	throw (new(ctx) BTreeException(ConstStr::getCNST_STR_1660(), ctx));
}
bool BTreeMaxLeafContainer::hasMaxNode(ThreadContext* ctx) throw() 
{
	return false;
}
ArrayList<IBTreeValue>* BTreeMaxLeafContainer::getValues(ThreadContext* ctx) throw() 
{
	return nullptr;
}
void BTreeMaxLeafContainer::save(ThreadContext* ctx)
{
}
IBTreeNode* BTreeMaxLeafContainer::fromFetcher(FileStorageEntryFetcher* fetcher, LockObject* sync, BTreeNodeLoader* loader, FifoElement<IBTreeNode>* fifoElement, ThreadContext* ctx) throw() 
{
	int numNodes = fetcher->fetchInt(ctx);
	int nodeUsed = fetcher->fetchInt(ctx);
	IArrayObject<NodeRef>* nodes = ArrayAllocator<NodeRef>::allocate(ctx, numNodes);
	for(int i = 0; i != numNodes; ++i)
	{
		nodes->set((new(ctx) NodeRef(fetcher->fetchLong(ctx), ctx)),i, ctx);
	}
	BTreeMaxLeafContainer* node = (new(ctx) BTreeMaxLeafContainer(numNodes, nodes, sync, loader, fifoElement, ctx));
	node->setNodeUsed(nodeUsed, ctx);
	return node;
}
void BTreeMaxLeafContainer::__cleanUp(ThreadContext* ctx){
}
}}

