#include "includes.h"


namespace alinous {namespace btree {





bool BTreeMaxNode::__init_done = __init_static_variables();
bool BTreeMaxNode::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"BTreeMaxNode", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 BTreeMaxNode::BTreeMaxNode(int numNodes, IArrayObject<NodeRef>* nodes, long long maxFilePointer, LockObject* sync, BTreeNodeLoader* loader, FifoElement<IBTreeNode>* fifoElement, ThreadContext* ctx) throw()  : IObject(ctx), AbstractBTreeNode(numNodes, nodes, sync, loader, fifoElement, ctx), max(nullptr)
{
	__GC_MV(this, &(this->max), (new(ctx) NodeRef(maxFilePointer, ctx)), NodeRef);
}
void BTreeMaxNode::__construct_impl(int numNodes, IArrayObject<NodeRef>* nodes, long long maxFilePointer, LockObject* sync, BTreeNodeLoader* loader, FifoElement<IBTreeNode>* fifoElement, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->max), (new(ctx) NodeRef(maxFilePointer, ctx)), NodeRef);
}
 BTreeMaxNode::~BTreeMaxNode() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void BTreeMaxNode::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"BTreeMaxNode", L"~BTreeMaxNode");
	__e_obj1.add(this->max, this);
	max = nullptr;
	if(!prepare){
		return;
	}
	AbstractBTreeNode::__releaseRegerences(true, ctx);
}
NodeRef* BTreeMaxNode::getMax(ThreadContext* ctx) throw() 
{
	return max;
}
int BTreeMaxNode::getNodeAtInsertPositionNumber(IBTreeKey* key, ThreadContext* ctx)
{
	this->nodeHandler->load(ctx);
	if(this->max->node == nullptr)
	{
		__GC_MV(max, &(this->max->node), this->loader->loadBTreeNode(this->max->filePointer, ctx), IBTreeNode);
	}
	int pos = this->nodeHandler->nodeToGoDown(key, ctx);
	return pos;
}
IBTreeNode* BTreeMaxNode::getNodeAtInsertPosition(IBTreeKey* key, ThreadContext* ctx)
{
	this->nodeHandler->load(ctx);
	if(this->max->node == nullptr)
	{
		__GC_MV(max, &(this->max->node), this->loader->loadBTreeNode(this->max->filePointer, ctx), IBTreeNode);
	}
	int pos = this->nodeHandler->nodeToGoDown(key, ctx);
	IBTreeNode* node = pos == this->nodeUsed ? this->max->node : this->nodes->get(pos)->node;
	return node;
}
int BTreeMaxNode::nodeSize(ThreadContext* ctx) throw() 
{
	int total = 1 + 4 + 4 + (this->length * 8) + 8;
	return total;
}
FileStorageEntry* BTreeMaxNode::toFileStorageEntry(FileStorageEntryBuilder* builder, FileStorageEntry* entry, ThreadContext* ctx) throw() 
{
	builder->reloadBuffer(nodeSize(ctx), ctx);
	builder->putByte(IBTreeNode::BTREE_TYPE_MAX_NODE, ctx);
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
	builder->putLong(this->max->filePointer, ctx);
	return builder->toEntry(entry, this->getFilePointer(ctx), ctx);
}
IBTreeNode* BTreeMaxNode::addLeafNode(IBTreeNode* newNode, ThreadContext* ctx)
{
	throw (new(ctx) BTreeException(ConstStr::getCNST_STR_1636(), ctx));
}
IBTreeKey* BTreeMaxNode::getKey(ThreadContext* ctx) throw() 
{
	return nullptr;
}
void BTreeMaxNode::endUse(ThreadContext* ctx)
{
	AbstractBTreeNode::endUse(ctx);
}
void BTreeMaxNode::loadChildren(ThreadContext* ctx)
{
	if(this->max->node == nullptr)
	{
		__GC_MV(max, &(this->max->node), this->loader->loadBTreeNode(this->max->filePointer, ctx), IBTreeNode);
	}
	this->nodeHandler->load(ctx);
}
INodeIterator* BTreeMaxNode::iterator(bool endStart, ThreadContext* ctx)
{
	return (new(ctx) MaxNodeIterator(loader, getFilePointer(ctx), endStart, ctx));
}
char BTreeMaxNode::getNodeType(ThreadContext* ctx) throw() 
{
	return IBTreeNode::BTREE_TYPE_MAX_NODE;
}
void BTreeMaxNode::printNode(StringBuffer* buff, int level, ThreadContext* ctx)
{
	printTab(buff, level, ctx);
	buff->append(ConstStr::getCNST_STR_1637(), ctx)->append(ConstStr::getCNST_STR_1638(), ctx)->append(ConstStr::getCNST_STR_1634(), ctx);
	int nextLevel = level + 1;
	int maxLoop = this->nodeUsed;
	for(int i = 0; i != maxLoop; ++i)
	{
		NodeRef* ref = this->nodes->get(i);
		IBTreeNode* node = this->loader->loadBTreeNode(ref->filePointer, ctx);
		node->printNode(buff, nextLevel, ctx);
		node->endUse(ctx);
	}
	IBTreeNode* node = this->loader->loadBTreeNode(this->max->filePointer, ctx);
	node->printNode(buff, nextLevel, ctx);
	node->endUse(ctx);
	printTab(buff, level, ctx);
	buff->append(ConstStr::getCNST_STR_1639(), ctx);
}
bool BTreeMaxNode::removeChild(IBTreeKey* key, ThreadContext* ctx)
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
bool BTreeMaxNode::isEmpty(ThreadContext* ctx) throw() 
{
	return false;
}
void BTreeMaxNode::setKey(IBTreeKey* key, ThreadContext* ctx)
{
	throw (new(ctx) BTreeException(ConstStr::getCNST_STR_1640(), ctx));
}
bool BTreeMaxNode::hasMaxNode(ThreadContext* ctx) throw() 
{
	return true;
}
ArrayList<IBTreeValue>* BTreeMaxNode::getValues(ThreadContext* ctx) throw() 
{
	return nullptr;
}
IBTreeNode* BTreeMaxNode::fromFetcher(FileStorageEntryFetcher* fetcher, LockObject* sync, BTreeNodeLoader* loader, FifoElement<IBTreeNode>* fifoElement, ThreadContext* ctx) throw() 
{
	int numNodes = fetcher->fetchInt(ctx);
	int nodeUsed = fetcher->fetchInt(ctx);
	IArrayObject<NodeRef>* nodes = ArrayAllocator<NodeRef>::allocate(ctx, numNodes + 1);
	for(int i = 0; i != numNodes; ++i)
	{
		nodes->set((new(ctx) NodeRef(fetcher->fetchLong(ctx), ctx)),i, ctx);
	}
	long long maxFilePointer = fetcher->fetchLong(ctx);
	BTreeMaxNode* node = (new(ctx) BTreeMaxNode(numNodes, nodes, maxFilePointer, sync, loader, fifoElement, ctx));
	node->setNodeUsed(nodeUsed, ctx);
	return node;
}
}}

