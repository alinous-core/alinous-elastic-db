#include "includes.h"


namespace alinous {namespace btree {





bool BTreeLeafContainer::__init_done = __init_static_variables();
bool BTreeLeafContainer::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"BTreeLeafContainer", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 BTreeLeafContainer::BTreeLeafContainer(IBTreeKey* key, int numNodes, IArrayObject<NodeRef>* nodes, LockObject* sync, BTreeNodeLoader* loader, FifoElement<IBTreeNode>* fifoElement, ThreadContext* ctx) throw()  : IObject(ctx), AbstractBTreeLeafContainer(numNodes, nodes, loader, sync, loader->getBlockSize(ctx), fifoElement, ctx), key(nullptr)
{
	__GC_MV(this, &(this->key), key, IBTreeKey);
}
void BTreeLeafContainer::__construct_impl(IBTreeKey* key, int numNodes, IArrayObject<NodeRef>* nodes, LockObject* sync, BTreeNodeLoader* loader, FifoElement<IBTreeNode>* fifoElement, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->key), key, IBTreeKey);
}
 BTreeLeafContainer::~BTreeLeafContainer() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void BTreeLeafContainer::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"BTreeLeafContainer", L"~BTreeLeafContainer");
	__e_obj1.add(this->key, this);
	key = nullptr;
	if(!prepare){
		return;
	}
	AbstractBTreeLeafContainer::__releaseRegerences(true, ctx);
}
int BTreeLeafContainer::nodeSize(ThreadContext* ctx)
{
	int total = this->key->size(ctx);
	total += 1 + 4 + 4 + (this->length * 8);
	return total;
}
FileStorageEntry* BTreeLeafContainer::toFileStorageEntry(FileStorageEntryBuilder* builder, FileStorageEntry* entry, ThreadContext* ctx)
{
	builder->reloadBuffer(nodeSize(ctx), ctx);
	builder->putByte(IBTreeNode::BTREE_TYPE_LEAF_CONTAINER, ctx);
	this->key->appendToEntry(builder, ctx);
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
IBTreeKey* BTreeLeafContainer::getKey(ThreadContext* ctx) throw() 
{
	return this->key;
}
void BTreeLeafContainer::addNode(IBTreeNode* newNode, ThreadContext* ctx)
{
	throw (new(ctx) BTreeException(ConstStr::getCNST_STR_998(), ctx));
}
char BTreeLeafContainer::getNodeType(ThreadContext* ctx) throw() 
{
	return IBTreeNode::BTREE_TYPE_LEAF_CONTAINER;
}
void BTreeLeafContainer::printNode(StringBuffer* buff, int level, ThreadContext* ctx)
{
	printTab(buff, level, ctx);
	buff->append(ConstStr::getCNST_STR_1572(), ctx)->append(getKey(ctx)->toString(ctx), ctx)->append(ConstStr::getCNST_STR_1573(), ctx);
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
	buff->append(ConstStr::getCNST_STR_1574(), ctx);
}
bool BTreeLeafContainer::removeChild(IBTreeKey* key, ThreadContext* ctx)
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
		return true;
	}
	if(this->key->equals(key, ctx))
	{
		__GC_MV(this, &(this->key), this->nodes->get(this->nodeUsed - 1)->node->getKey(ctx), IBTreeKey);
		removedKey = true;
	}
	return removedKey;
}
bool BTreeLeafContainer::isEmpty(ThreadContext* ctx) throw() 
{
	return this->nodeUsed == 0;
}
void BTreeLeafContainer::setKey(IBTreeKey* key, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->key), key, IBTreeKey);
}
bool BTreeLeafContainer::hasMaxNode(ThreadContext* ctx) throw() 
{
	return false;
}
ArrayList<IBTreeValue>* BTreeLeafContainer::getValues(ThreadContext* ctx) throw() 
{
	return nullptr;
}
IBTreeNode* BTreeLeafContainer::fromFetcher(FileStorageEntryFetcher* fetcher, LockObject* sync, BTreeNodeLoader* loader, FifoElement<IBTreeNode>* fifoElement, ThreadContext* ctx)
{
	IBTreeKey* key = KeyValueFactory::keyFromFetcher(fetcher, ctx);
	int numNodes = fetcher->fetchInt(ctx);
	int nodeUsed = fetcher->fetchInt(ctx);
	IArrayObject<NodeRef>* nodes = ArrayAllocator<NodeRef>::allocate(ctx, numNodes + 1);
	for(int i = 0; i != numNodes; ++i)
	{
		nodes->set((new(ctx) NodeRef(fetcher->fetchLong(ctx), ctx)),i, ctx);
	}
	BTreeLeafContainer* node = (new(ctx) BTreeLeafContainer(key, numNodes, nodes, sync, loader, fifoElement, ctx));
	node->setNodeUsed(nodeUsed, ctx);
	return node;
}
}}

