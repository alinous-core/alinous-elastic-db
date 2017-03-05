#include "include/global.h"


#include "java.util/BitSet.h"
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
#include "alinous.btree/BTreeException.h"
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
#include "alinous.btree/BTreeCacheArray.h"
#include "alinous.buffer/HashArrayListIterator.h"

namespace alinous {namespace buffer {





bool HashArrayList::__init_done = __init_static_variables();
bool HashArrayList::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"HashArrayList", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 HashArrayList::HashArrayList(int MAX_HASH, ThreadContext* ctx) : IObject(ctx), MAX_HASH(0), MAX_HASH_MASK(0), arrays(nullptr), bitset(__GC_INS(this, (new(ctx) BitSet(ctx)), BitSet)), numElements(0)
{
	if((MAX_HASH & 1) != 0)
	{
		throw (new(ctx) BTreeException(ConstStr::getCNST_STR_1669(), ctx));
	}
	this->MAX_HASH = MAX_HASH;
	this->MAX_HASH_MASK = this->MAX_HASH - 1;
	__GC_MV(this, &(this->arrays), ArrayAllocator<BTreeCacheArray>::allocate(ctx, MAX_HASH), IArrayObject<BTreeCacheArray>);
	for(int i = 0; i != MAX_HASH; i ++ )
	{
		arrays->set((new(ctx) BTreeCacheArray(4, ctx)),i, ctx);
	}
}
void HashArrayList::__construct_impl(int MAX_HASH, ThreadContext* ctx)
{
	if((MAX_HASH & 1) != 0)
	{
		throw (new(ctx) BTreeException(ConstStr::getCNST_STR_1669(), ctx));
	}
	this->MAX_HASH = MAX_HASH;
	this->MAX_HASH_MASK = this->MAX_HASH - 1;
	__GC_MV(this, &(this->arrays), ArrayAllocator<BTreeCacheArray>::allocate(ctx, MAX_HASH), IArrayObject<BTreeCacheArray>);
	for(int i = 0; i != MAX_HASH; i ++ )
	{
		arrays->set((new(ctx) BTreeCacheArray(4, ctx)),i, ctx);
	}
}
 HashArrayList::~HashArrayList() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void HashArrayList::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"HashArrayList", L"~HashArrayList");
	__e_obj1.add(this->arrays, this);
	arrays = nullptr;
	__e_obj1.add(this->bitset, this);
	bitset = nullptr;
	if(!prepare){
		return;
	}
}
int HashArrayList::size(ThreadContext* ctx) throw() 
{
	return this->numElements;
}
IBTreeNode* HashArrayList::addElement(IBTreeNode* ptr, ThreadContext* ctx) throw() 
{
	int hashcode = ((int)(ptr->getHashKey(ctx) & MAX_HASH_MASK));
	arrays->get(hashcode)->add(static_cast<IBTreeNode*>(ptr), ctx);
	bitset->set(hashcode, ctx);
	++numElements;
	return ptr;
}
bool HashArrayList::removeByObj(IBTreeNode* obj, ThreadContext* ctx) throw() 
{
	int hashcode = ((int)(obj->getHashKey(ctx) & MAX_HASH_MASK));
	bool result = arrays->get(hashcode)->removeByObj(obj, ctx);
	if(result)
	{
		--numElements;
	}
	if(arrays->get(hashcode)->size(ctx) == 0)
	{
		bitset->clear(hashcode, ctx);
	}
	return result;
}
IBTreeNode* HashArrayList::search(IBTreeNode* value, ThreadContext* ctx) throw() 
{
	int hashcode = ((int)(value->getHashKey(ctx) & MAX_HASH_MASK));
	return arrays->get(hashcode)->search(value, ctx);
}
void HashArrayList::reset(ThreadContext* ctx) throw() 
{
	for(int i = 0; i != (int)MAX_HASH; i ++ )
	{
		arrays->get(i)->reset(ctx);
	}
	bitset->clear(ctx);
	numElements = 0;
}
HashArrayListIterator* HashArrayList::iterator(ThreadContext* ctx) throw() 
{
	return (new(ctx) HashArrayListIterator(arrays, bitset, MAX_HASH, ctx));
}
}}

