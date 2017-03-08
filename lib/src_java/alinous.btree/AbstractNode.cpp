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





bool AbstractNode::__init_done = __init_static_variables();
bool AbstractNode::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AbstractNode", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AbstractNode::AbstractNode(LockObject* sync, BTreeNodeLoader* loader, FifoElement<IBTreeNode>* fifoElement, ThreadContext* ctx) throw()  : IObject(ctx), IBTreeNode(ctx), sync(nullptr), fifoElement(nullptr), loader(nullptr), filePointer(0), useGCRefCount(0), storage(nullptr)
{
	__GC_MV(this, &(this->loader), loader, BTreeNodeLoader);
	__GC_MV(this, &(this->sync), sync, LockObject);
	GCUtils<FifoElement<IBTreeNode> >::mv(this, &(this->fifoElement), fifoElement, ctx);
	__GC_MV(fifoElement, &(fifoElement->data), static_cast<IBTreeNode*>(this), IBTreeNode);
}
void AbstractNode::__construct_impl(LockObject* sync, BTreeNodeLoader* loader, FifoElement<IBTreeNode>* fifoElement, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->loader), loader, BTreeNodeLoader);
	__GC_MV(this, &(this->sync), sync, LockObject);
	GCUtils<FifoElement<IBTreeNode> >::mv(this, &(this->fifoElement), fifoElement, ctx);
	__GC_MV(fifoElement, &(fifoElement->data), static_cast<IBTreeNode*>(this), IBTreeNode);
}
 AbstractNode::~AbstractNode() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AbstractNode::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"AbstractNode", L"~AbstractNode");
	__e_obj1.add(this->sync, this);
	sync = nullptr;
	__e_obj1.add(this->fifoElement, this);
	fifoElement = nullptr;
	__e_obj1.add(this->loader, this);
	loader = nullptr;
	__e_obj1.add(this->storage, this);
	storage = nullptr;
	if(!prepare){
		return;
	}
}
int AbstractNode::compareTo(IBTreeNode* another, ThreadContext* ctx) throw() 
{
	long long diff = this->getFilePointer(ctx) - another->getFilePointer(ctx);
	if(diff == (long long)0)
	{
		return 0;
	}
		else 
	{
		return diff > (long long)0 ? 1 : -1;
	}
}
bool AbstractNode::equals(IObject* obj, ThreadContext* ctx) throw() 
{
	return this->filePointer == (dynamic_cast<IBTreeNode*>(obj))->getFilePointer(ctx);
}
long long AbstractNode::getFilePointer(ThreadContext* ctx) throw() 
{
	return this->filePointer;
}
void AbstractNode::setFilePointer(long long position, ThreadContext* ctx) throw() 
{
	this->filePointer = position;
}
void AbstractNode::use(ThreadContext* ctx)
{
	{
		SynchronizedBlockObj __synchronized_2(this->sync, ctx);
		this->useGCRefCount ++ ;
		if(this->useGCRefCount == 1)
		{
			this->loader->moveToUsing(fifoElement, ctx);
		}
	}
}
void AbstractNode::incCount(ThreadContext* ctx) throw() 
{
	this->useGCRefCount ++ ;
}
void AbstractNode::endUse(ThreadContext* ctx)
{
	{
		SynchronizedBlockObj __synchronized_2(this->sync, ctx);
		this->useGCRefCount -- ;
		if(this->useGCRefCount == 0)
		{
			this->loader->moveToDeletable(this->fifoElement, ctx);
		}
	}
}
void AbstractNode::doEndUseWithoutLock(ThreadContext* ctx) throw() 
{
	this->useGCRefCount -- ;
	if(this->useGCRefCount == 0)
	{
		this->loader->moveToDeletable(this->fifoElement, ctx);
	}
}
bool AbstractNode::isDeletable(ThreadContext* ctx) throw() 
{
	return this->useGCRefCount == 0;
}
long long AbstractNode::getHashKey(ThreadContext* ctx) throw() 
{
	return ((int)(((unsigned long long)((this->filePointer + this->storage->hashCode) * 2654404609L))>> 32));
}
int AbstractNode::getUseGCRefCount(ThreadContext* ctx) throw() 
{
	return useGCRefCount;
}
void AbstractNode::printTab(StringBuffer* buff, int level, ThreadContext* ctx) throw() 
{
	for(int i = 0; i != level; ++i)
	{
		buff->append(ConstStr::getCNST_STR_1662(), ctx);
	}
}
FileStorage* AbstractNode::getStorage(ThreadContext* ctx) throw() 
{
	return this->storage;
}
void AbstractNode::setStorage(FileStorage* storage, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->storage), storage, FileStorage);
}
void AbstractNode::__cleanUp(ThreadContext* ctx){
}
int AbstractNode::ValueCompare::operator() (IBTreeNode* _this, IBTreeNode* another, ThreadContext* ctx) const throw()
{
	return _this->compareTo(another, ctx);
}
}}

