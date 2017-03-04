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





bool HashArrayListIterator::__init_done = __init_static_variables();
bool HashArrayListIterator::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"HashArrayListIterator", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 HashArrayListIterator::HashArrayListIterator(IArrayObject<BTreeCacheArray>* ptr, BitSet* bitset, long long MAX_HASH, ThreadContext* ctx) throw()  : IObject(ctx), MAX_HASH(0), hashCode(0), index(0), arrays(nullptr), bitset(nullptr)
{
	this->MAX_HASH = MAX_HASH;
	this->hashCode = 0;
	this->index = 0;
	__GC_MV(this, &(this->arrays), ptr, IArrayObject<BTreeCacheArray>);
	__GC_MV(this, &(this->bitset), bitset, BitSet);
}
void HashArrayListIterator::__construct_impl(IArrayObject<BTreeCacheArray>* ptr, BitSet* bitset, long long MAX_HASH, ThreadContext* ctx) throw() 
{
	this->MAX_HASH = MAX_HASH;
	this->hashCode = 0;
	this->index = 0;
	__GC_MV(this, &(this->arrays), ptr, IArrayObject<BTreeCacheArray>);
	__GC_MV(this, &(this->bitset), bitset, BitSet);
}
 HashArrayListIterator::~HashArrayListIterator() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void HashArrayListIterator::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"HashArrayListIterator", L"~HashArrayListIterator");
	__e_obj1.add(this->arrays, this);
	arrays = nullptr;
	__e_obj1.add(this->bitset, this);
	bitset = nullptr;
	if(!prepare){
		return;
	}
}
bool HashArrayListIterator::hasNext(ThreadContext* ctx) throw() 
{
	BTreeCacheArray* current = arrays->get(hashCode);
	if(current->size(ctx) == index)
	{
		int nextHash = hashCode + 1;
		if(nextHash == (int)MAX_HASH)
		{
			return false;
		}
		int next = bitset->nextSetBit(nextHash, ctx);
		if(next < 0)
		{
			return false;
		}
		return true;
	}
	return true;
}
IBTreeNode* HashArrayListIterator::next(ThreadContext* ctx) throw() 
{
	BTreeCacheArray* current = arrays->get(hashCode);
	if(current->size(ctx) == index)
	{
		int nextHash = hashCode + 1;
		int next = bitset->nextSetBit(nextHash, ctx);
		if(nextHash == (int)MAX_HASH || next < 0)
		{
			return nullptr;
		}
		index = 0;
		hashCode = next;
	}
	current = arrays->get(hashCode);
	return current->get(index++, ctx);
}
}}

