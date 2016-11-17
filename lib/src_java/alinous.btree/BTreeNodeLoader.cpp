#include "includes.h"


namespace alinous {namespace btree {





bool BTreeNodeLoader::__init_done = __init_static_variables();
bool BTreeNodeLoader::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"BTreeNodeLoader", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 BTreeNodeLoader::BTreeNodeLoader(FileStorage* storage, BTreeGlobalCache* cacheEngine, ThreadContext* ctx) : IObject(ctx), cacheEngine(nullptr), storage(nullptr), sync(nullptr), buffEntry(__GC_INS(this, (new(ctx) FileStorageEntry(ctx)), FileStorageEntry)), buffBuilder(__GC_INS(this, (new(ctx) FileStorageEntryBuilder(ctx)), FileStorageEntryBuilder)), writer(nullptr), reader(nullptr)
{
	__GC_MV(this, &(this->cacheEngine), cacheEngine, BTreeGlobalCache);
	__GC_MV(this, &(this->storage), storage, FileStorage);
	__GC_MV(this, &(this->sync), (new(ctx) LockObject(ctx)), LockObject);
}
void BTreeNodeLoader::__construct_impl(FileStorage* storage, BTreeGlobalCache* cacheEngine, ThreadContext* ctx)
{
	__GC_MV(this, &(this->cacheEngine), cacheEngine, BTreeGlobalCache);
	__GC_MV(this, &(this->storage), storage, FileStorage);
	__GC_MV(this, &(this->sync), (new(ctx) LockObject(ctx)), LockObject);
}
 BTreeNodeLoader::~BTreeNodeLoader() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void BTreeNodeLoader::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"BTreeNodeLoader", L"~BTreeNodeLoader");
	__e_obj1.add(this->cacheEngine, this);
	cacheEngine = nullptr;
	__e_obj1.add(this->storage, this);
	storage = nullptr;
	__e_obj1.add(this->sync, this);
	sync = nullptr;
	__e_obj1.add(this->buffEntry, this);
	buffEntry = nullptr;
	__e_obj1.add(this->buffBuilder, this);
	buffBuilder = nullptr;
	__e_obj1.add(this->writer, this);
	writer = nullptr;
	__e_obj1.add(this->reader, this);
	reader = nullptr;
	if(!prepare){
		return;
	}
}
void BTreeNodeLoader::open(ThreadContext* ctx)
{
	__GC_MV(this, &(this->writer), this->storage->getWriter(ctx), FileStorageEntryWriter);
	__GC_MV(this, &(this->reader), this->storage->getReader(ctx), FileStorageEntryReader);
}
void BTreeNodeLoader::close(ThreadContext* ctx) throw() 
{
	this->writer->end(ctx);
	this->reader->end(ctx);
	__GC_MV(this, &(this->writer), nullptr, FileStorageEntryWriter);
	__GC_MV(this, &(this->reader), nullptr, FileStorageEntryReader);
}
BTreeNode* BTreeNodeLoader::newNode(IBTreeKey* key, int numNodes, ThreadContext* ctx)
{
	FifoElement<IBTreeNode>* fifoElement = (new(ctx) FifoElement<IBTreeNode>(ctx));
	BTreeNode* node = (new(ctx) BTreeNode(key, numNodes, sync, this, fifoElement, ctx));
	saveBTreeNode(node, ctx);
	addCache(fifoElement, ctx);
	return node;
}
BTreeMaxNode* BTreeNodeLoader::newMaxNode(int numNodes, long long maxFilePointer, ThreadContext* ctx)
{
	FifoElement<IBTreeNode>* fifoElement = (new(ctx) FifoElement<IBTreeNode>(ctx));
	BTreeMaxNode* node = (new(ctx) BTreeMaxNode(numNodes, nullptr, maxFilePointer, sync, this, fifoElement, ctx));
	saveBTreeNode(node, ctx);
	addCache(fifoElement, ctx);
	return node;
}
BTreeMaxLeafContainer* BTreeNodeLoader::newBTreeMaxLeafContainer(int numNodes, ThreadContext* ctx)
{
	FifoElement<IBTreeNode>* fifoElement = (new(ctx) FifoElement<IBTreeNode>(ctx));
	BTreeMaxLeafContainer* node = (new(ctx) BTreeMaxLeafContainer(numNodes, nullptr, sync, this, fifoElement, ctx));
	saveBTreeNode(node, ctx);
	addCache(fifoElement, ctx);
	return node;
}
BTreeLeafContainer* BTreeNodeLoader::newLeafContainerNode(IBTreeKey* key, int numNodes, ThreadContext* ctx)
{
	FifoElement<IBTreeNode>* fifoElement = (new(ctx) FifoElement<IBTreeNode>(ctx));
	BTreeLeafContainer* node = (new(ctx) BTreeLeafContainer(key, numNodes, nullptr, this->sync, this, fifoElement, ctx));
	saveBTreeNode(node, ctx);
	addCache(fifoElement, ctx);
	return node;
}
BTreeMaxLeafContainer* BTreeNodeLoader::newBTreeMaxLeafContainerNode(int numNodes, ThreadContext* ctx)
{
	FifoElement<IBTreeNode>* fifoElement = (new(ctx) FifoElement<IBTreeNode>(ctx));
	BTreeMaxLeafContainer* node = (new(ctx) BTreeMaxLeafContainer(numNodes, nullptr, this->sync, this, fifoElement, ctx));
	saveBTreeNode(node, ctx);
	addCache(fifoElement, ctx);
	return node;
}
BTreeLeafNode* BTreeNodeLoader::newLeafNode(IBTreeKey* key, ThreadContext* ctx)
{
	FifoElement<IBTreeNode>* fifoElement = (new(ctx) FifoElement<IBTreeNode>(ctx));
	BTreeLeafNode* node = (new(ctx) BTreeLeafNode(key, sync, this, fifoElement, ctx));
	saveBTreeNode(node, ctx);
	addCache(fifoElement, ctx);
	return node;
}
void BTreeNodeLoader::moveToUsing(FifoElement<IBTreeNode>* fifoElement, ThreadContext* ctx) throw() 
{
	this->cacheEngine->moveToUsing(fifoElement, ctx);
}
void BTreeNodeLoader::moveToDeletable(FifoElement<IBTreeNode>* fifoElement, ThreadContext* ctx) throw() 
{
	this->cacheEngine->moveToDeletable(fifoElement, ctx);
}
void BTreeNodeLoader::deleteBTreeNode(IBTreeNode* node, ThreadContext* ctx)
{
	FileStorageBlock* workBlock = (new(ctx) FileStorageBlock(this->storage->getFileAccess(ctx), this->storage->getBLOCK_SIZE(ctx), ctx));
	this->storage->removeEntryBlocks(node->getFilePointer(ctx), workBlock, ctx);
}
void BTreeNodeLoader::saveBTreeNode(IBTreeNode* node, ThreadContext* ctx)
{
	__GC_MV(this, &(this->buffEntry), node->toFileStorageEntry(this->buffBuilder, this->buffEntry, ctx), FileStorageEntry);
	__GC_MV(this, &(this->writer), this->storage->getWriter(ctx), FileStorageEntryWriter);
	writer->write(this->buffEntry, ctx);
	node->setFilePointer(this->buffEntry->position, ctx);
}
void BTreeNodeLoader::reloadKey(IBTreeNode* node, ThreadContext* ctx)
{
	long long filePointer = node->getFilePointer(ctx);
	FifoElement<IBTreeNode>* fifoElement = (new(ctx) FifoElement<IBTreeNode>(ctx));
	IBTreeNode* reloaded = nullptr;
	FileStorageEntryFetcher* fetcher = (new(ctx) FileStorageEntryFetcher(ctx));
	FileStorageEntry* buffEntry = (new(ctx) FileStorageEntry(ctx));
	buffEntry = reader->read(filePointer, ctx);
	fetcher->load(buffEntry, ctx);
	char nodeType = node->getNodeType(ctx);
	switch(nodeType) {
	case IBTreeNode::BTREE_TYPE_LEAF:
		reloaded = BTreeLeafNode::fromFetcher(fetcher, sync, this, fifoElement, ctx);
		node->setKey(reloaded->getKey(ctx), ctx);
		break ;
	case IBTreeNode::BTREE_TYPE_NODE:
		reloaded = BTreeNode::fromFetcher(fetcher, sync, this, fifoElement, ctx);
		node->setKey(reloaded->getKey(ctx), ctx);
		break ;
	case IBTreeNode::BTREE_TYPE_LEAF_CONTAINER:
		reloaded = BTreeLeafContainer::fromFetcher(fetcher, sync, this, fifoElement, ctx);
		node->setKey(reloaded->getKey(ctx), ctx);
		break ;
	case IBTreeNode::BTREE_TYPE_MAX_NODE:
		break ;
	case IBTreeNode::BTREE_TYPE_MAX_LEAF_CONTAINER:
		reloaded = BTreeMaxLeafContainer::fromFetcher(fetcher, sync, this, fifoElement, ctx);
		node->setKey(reloaded->getKey(ctx), ctx);
		break ;
	default:
		break ;
	}
}
IBTreeNode* BTreeNodeLoader::loadBTreeNode(long long filePointer, ThreadContext* ctx)
{
	IBTreeNode* node = this->cacheEngine->search(this->storage, filePointer, ctx);
	if(node != nullptr)
	{
		node->use(ctx);
		return node;
	}
	FifoElement<IBTreeNode>* fifoElement = (new(ctx) FifoElement<IBTreeNode>(ctx));
	FileStorageEntryReader* reader = storage->getReader(ctx);
	FileStorageEntryFetcher* fetcher = (new(ctx) FileStorageEntryFetcher(ctx));
	__GC_MV(this, &(this->buffEntry), reader->read(filePointer, ctx), FileStorageEntry);
	fetcher->load(buffEntry, ctx);
	char nodeType = fetcher->fetchByte(ctx);
	switch(nodeType) {
	case IBTreeNode::BTREE_TYPE_LEAF:
		node = BTreeLeafNode::fromFetcher(fetcher, sync, this, fifoElement, ctx);
		break ;
	case IBTreeNode::BTREE_TYPE_NODE:
		node = BTreeNode::fromFetcher(fetcher, sync, this, fifoElement, ctx);
		break ;
	case IBTreeNode::BTREE_TYPE_LEAF_CONTAINER:
		node = BTreeLeafContainer::fromFetcher(fetcher, sync, this, fifoElement, ctx);
		break ;
	case IBTreeNode::BTREE_TYPE_MAX_NODE:
		node = BTreeMaxNode::fromFetcher(fetcher, sync, this, fifoElement, ctx);
		break ;
	case IBTreeNode::BTREE_TYPE_MAX_LEAF_CONTAINER:
		node = BTreeMaxLeafContainer::fromFetcher(fetcher, sync, this, fifoElement, ctx);
		break ;
	default:
		break ;
	}
	node->setFilePointer(filePointer, ctx);
	addCache(fifoElement, ctx);
	return node;
}
int BTreeNodeLoader::getBlockSize(ThreadContext* ctx) throw() 
{
	return ((int)this->storage->getBLOCK_SIZE(ctx));
}
void BTreeNodeLoader::assertCache(ThreadContext* ctx)
{
}
void BTreeNodeLoader::addCache(FifoElement<IBTreeNode>* fifoElement, ThreadContext* ctx)
{
	this->cacheEngine->addCache(fifoElement, this->storage, ctx);
}
}}

