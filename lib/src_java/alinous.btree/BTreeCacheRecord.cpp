#include "include/global.h"


#include "alinous.buffer/FifoElement.h"
#include "alinous.buffer.storage/FileStorageEntry.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.lock/LockObject.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
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
#include "alinous.btree/AbstractNode.h"
#include "alinous.btree/BTreeNodeHandler.h"
#include "alinous.btree/AbstractBTreeNode.h"
#include "alinous.btree/BTreeNode.h"
#include "alinous.btree/BTreeMaxNode.h"
#include "alinous.btree.scan/AbstractNodeIterator.h"
#include "alinous.btree.scan/LeafContainerIterator.h"
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





bool BTreeCacheRecord::__init_done = __init_static_variables();
bool BTreeCacheRecord::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"BTreeCacheRecord", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 BTreeCacheRecord::BTreeCacheRecord(long long BLOCK_SIZE, ThreadContext* ctx) throw()  : IObject(ctx), IBTreeNode(ctx), storage(nullptr), filePointer(0)
{
	this->filePointer = 0;
}
void BTreeCacheRecord::__construct_impl(long long BLOCK_SIZE, ThreadContext* ctx) throw() 
{
	this->filePointer = 0;
}
 BTreeCacheRecord::~BTreeCacheRecord() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void BTreeCacheRecord::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"BTreeCacheRecord", L"~BTreeCacheRecord");
	__e_obj1.add(this->storage, this);
	storage = nullptr;
	if(!prepare){
		return;
	}
}
void BTreeCacheRecord::setFilePointer(long long position, ThreadContext* ctx) throw() 
{
	this->filePointer = position;
}
long long BTreeCacheRecord::getHashKey(ThreadContext* ctx) throw() 
{
	return ((int)(((unsigned long long)((this->filePointer + this->storage->hashCode) * 2654404609L))>> 32));
}
int BTreeCacheRecord::compareTo(IBTreeNode* another, ThreadContext* ctx) throw() 
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
bool BTreeCacheRecord::isHasLeaf(ThreadContext* ctx) throw() 
{
	return false;
}
long long BTreeCacheRecord::getFilePointer(ThreadContext* ctx) throw() 
{
	return this->filePointer;
}
int BTreeCacheRecord::nodeSize(ThreadContext* ctx) throw() 
{
	return 0;
}
void BTreeCacheRecord::endUse(ThreadContext* ctx)
{
}
FileStorageEntry* BTreeCacheRecord::toFileStorageEntry(FileStorageEntryBuilder* buffBuilder, FileStorageEntry* buffEntry, ThreadContext* ctx) throw() 
{
	return nullptr;
}
void BTreeCacheRecord::use(ThreadContext* ctx) throw() 
{
}
bool BTreeCacheRecord::isFull(ThreadContext* ctx) throw() 
{
	return false;
}
IBTreeNode* BTreeCacheRecord::addLeafNode(IBTreeNode* newNode, ThreadContext* ctx)
{
	return nullptr;
}
IBTreeKey* BTreeCacheRecord::getKey(ThreadContext* ctx) throw() 
{
	return nullptr;
}
IBTreeNode* BTreeCacheRecord::getNodeAtInsertPosition(IBTreeKey* key, ThreadContext* ctx)
{
	return nullptr;
}
bool BTreeCacheRecord::isDeletable(ThreadContext* ctx) throw() 
{
	return true;
}
void BTreeCacheRecord::setNodeUsed(int nodeUsed, ThreadContext* ctx)
{
}
IBTreeNode* BTreeCacheRecord::split(IBTreeNode* newNode, BTreeNodeLoader* loader, ThreadContext* ctx) throw() 
{
	return nullptr;
}
void BTreeCacheRecord::addNode(IBTreeNode* newNode, ThreadContext* ctx)
{
	throw (new(ctx) BTreeException(ConstStr::getCNST_STR_1023(), ctx));
}
void BTreeCacheRecord::incCount(ThreadContext* ctx) throw() 
{
}
int BTreeCacheRecord::getUseGCRefCount(ThreadContext* ctx) throw() 
{
	return 0;
}
INodeIterator* BTreeCacheRecord::iterator(bool endStart, ThreadContext* ctx) throw() 
{
	return nullptr;
}
void BTreeCacheRecord::loadChildren(ThreadContext* ctx) throw() 
{
}
char BTreeCacheRecord::getNodeType(ThreadContext* ctx) throw() 
{
	return -1;
}
void BTreeCacheRecord::printNode(StringBuffer* buff, int level, ThreadContext* ctx) throw() 
{
}
bool BTreeCacheRecord::removeChild(IBTreeKey* key, ThreadContext* ctx) throw() 
{
	return false;
}
bool BTreeCacheRecord::isEmpty(ThreadContext* ctx) throw() 
{
	return false;
}
void BTreeCacheRecord::setKey(IBTreeKey* key, ThreadContext* ctx) throw() 
{
}
bool BTreeCacheRecord::hasMaxNode(ThreadContext* ctx) throw() 
{
	return false;
}
ArrayList<IBTreeValue>* BTreeCacheRecord::getValues(ThreadContext* ctx) throw() 
{
	return nullptr;
}
void BTreeCacheRecord::unloadChildren(ThreadContext* ctx) throw() 
{
}
FileStorage* BTreeCacheRecord::getStorage(ThreadContext* ctx) throw() 
{
	return this->storage;
}
void BTreeCacheRecord::setStorage(FileStorage* storage, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->storage), storage, FileStorage);
}
void BTreeCacheRecord::save(ThreadContext* ctx)
{
}
void BTreeCacheRecord::__cleanUp(ThreadContext* ctx){
}
int BTreeCacheRecord::ValueCompare::operator() (IBTreeNode* _this, IBTreeNode* another, ThreadContext* ctx) const throw()
{
	return _this->compareTo(another, ctx);
}
}}

