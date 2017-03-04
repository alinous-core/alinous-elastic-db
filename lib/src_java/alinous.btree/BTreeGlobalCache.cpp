#include "include/global.h"


#include "alinous.buffer/FifoElement.h"
#include "alinous.buffer.storage/FileStorageEntry.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.lock/LockObject.h"
#include "java.lang/Comparable.h"
#include "alinous.btree/IBTreeKey.h"
#include "alinous.btree.scan/INodeIterator.h"
#include "alinous.lock/ConcurrentGate.h"
#include "alinous.buffer.storage/FileAccessWrapper.h"
#include "alinous.buffer.storage/FileStorageBlock.h"
#include "alinous.buffer.storage/IFileStorage.h"
#include "alinous.buffer.storage/FileStorageEntryWriter.h"
#include "alinous.buffer.storage/FileStorageEntryReader.h"
#include "alinous.buffer.storage/FileStorage.h"
#include "alinous.buffer/FifoIterator.h"
#include "alinous.buffer/FifoList.h"
#include "java.util/BitSet.h"
#include "alinous.btree/BTreeCacheArray.h"
#include "alinous.btree/BTreeException.h"
#include "alinous.buffer/HashArrayListIterator.h"
#include "alinous.buffer/HashArrayList.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.btree/IBTreeNode.h"
#include "alinous.btree/BTreeCacheRecord.h"
#include "alinous.btree/BTreeGlobalCache.h"
#include "alinous.btree/AbstractNode.h"
#include "alinous.btree/BTreeNodeHandler.h"
#include "alinous.btree/AbstractBTreeNode.h"
#include "alinous.btree/BTreeNode.h"
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





bool BTreeGlobalCache::__init_done = __init_static_variables();
bool BTreeGlobalCache::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"BTreeGlobalCache", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 BTreeGlobalCache::~BTreeGlobalCache() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void BTreeGlobalCache::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"BTreeGlobalCache", L"~BTreeGlobalCache");
	__e_obj1.add(this->cache, this);
	cache = nullptr;
	__e_obj1.add(this->fifo, this);
	fifo = nullptr;
	__e_obj1.add(this->fifoDeletable, this);
	fifoDeletable = nullptr;
	__e_obj1.add(this->tmp, this);
	tmp = nullptr;
	__e_obj1.add(this->sync, this);
	sync = nullptr;
	if(!prepare){
		return;
	}
}
BTreeGlobalCache* BTreeGlobalCache::init(int maxCache, ThreadContext* ctx)
{
	this->maxCache = maxCache;
	__GC_MV(this, &(this->cache), (new(ctx) HashArrayList(maxCache, ctx)), HashArrayList);
	GCUtils<FifoList<IBTreeNode> >::mv(this, &(this->fifo), (new(ctx) FifoList<IBTreeNode>(ctx)), ctx);
	GCUtils<FifoList<IBTreeNode> >::mv(this, &(this->fifoDeletable), (new(ctx) FifoList<IBTreeNode>(ctx)), ctx);
	__GC_MV(this, &(this->sync), (new(ctx) LockObject(ctx)), LockObject);
	this->maxCache = maxCache;
	__GC_MV(this, &(this->tmp), (new(ctx) BTreeCacheRecord(256, ctx)), BTreeCacheRecord);
	return this;
}
IBTreeNode* BTreeGlobalCache::search(FileStorage* storage, long long filePointer, ThreadContext* ctx) throw() 
{
	IBTreeNode* node = 0;
	{
		SynchronizedBlockObj __synchronized_2(this->sync, ctx);
		tmp->setFilePointer(filePointer, ctx);
		tmp->setStorage(storage, ctx);
		node = static_cast<IBTreeNode*>(this->cache->search(this->tmp, ctx));
	}
	return node;
}
void BTreeGlobalCache::addCache(FifoElement<IBTreeNode>* fifoElement, FileStorage* storage, ThreadContext* ctx)
{
	IBTreeNode* node = fifoElement->data;
	node->setStorage(storage, ctx);
	{
		SynchronizedBlockObj __synchronized_2(this->sync, ctx);
		int cacheused = this->fifo->size(ctx) + this->fifoDeletable->size(ctx);
		if(cacheused > this->maxCache && !fifoDeletable->isEmpty(ctx))
		{
			IBTreeNode* del = this->fifoDeletable->remove(0, ctx);
			del->unloadChildren(ctx);
			this->cache->removeByObj(del, ctx);
		}
		this->fifo->addElement(fifoElement, ctx);
		this->cache->addElement(node, ctx);
		node->incCount(ctx);
	}
}
void BTreeGlobalCache::moveToUsing(FifoElement<IBTreeNode>* fifoElement, ThreadContext* ctx) throw() 
{
	{
		SynchronizedBlockObj __synchronized_2(this->sync, ctx);
		this->fifoDeletable->removeElement(fifoElement, ctx);
		this->fifo->addElement(fifoElement, ctx);
	}
}
void BTreeGlobalCache::moveToDeletable(FifoElement<IBTreeNode>* fifoElement, ThreadContext* ctx) throw() 
{
	{
		SynchronizedBlockObj __synchronized_2(this->sync, ctx);
		this->fifo->removeElement(fifoElement, ctx);
		this->fifoDeletable->addElement(fifoElement, ctx);
	}
}
}}

