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





bool BTreeLeafNode::__init_done = __init_static_variables();
bool BTreeLeafNode::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"BTreeLeafNode", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 BTreeLeafNode::BTreeLeafNode(KeyValue* kv, LockObject* sync, BTreeNodeLoader* loader, FifoElement<IBTreeNode>* fifoElement, ThreadContext* ctx) throw()  : IObject(ctx), AbstractNode(sync, loader, fifoElement, ctx), keyValue(nullptr)
{
	__GC_MV(this, &(this->keyValue), kv, KeyValue);
}
void BTreeLeafNode::__construct_impl(KeyValue* kv, LockObject* sync, BTreeNodeLoader* loader, FifoElement<IBTreeNode>* fifoElement, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->keyValue), kv, KeyValue);
}
 BTreeLeafNode::BTreeLeafNode(IBTreeKey* key, LockObject* sync, BTreeNodeLoader* loader, FifoElement<IBTreeNode>* fifoElement, ThreadContext* ctx) throw()  : IObject(ctx), AbstractNode(sync, loader, fifoElement, ctx), keyValue(nullptr)
{
	__GC_MV(this, &(this->keyValue), (new(ctx) KeyValue(key, ctx)), KeyValue);
}
void BTreeLeafNode::__construct_impl(IBTreeKey* key, LockObject* sync, BTreeNodeLoader* loader, FifoElement<IBTreeNode>* fifoElement, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->keyValue), (new(ctx) KeyValue(key, ctx)), KeyValue);
}
 BTreeLeafNode::~BTreeLeafNode() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void BTreeLeafNode::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"BTreeLeafNode", L"~BTreeLeafNode");
	__e_obj1.add(this->keyValue, this);
	keyValue = nullptr;
	if(!prepare){
		return;
	}
	AbstractNode::__releaseRegerences(true, ctx);
}
void BTreeLeafNode::save(ThreadContext* ctx)
{
	this->loader->saveBTreeNode(this, ctx);
}
int BTreeLeafNode::nodeSize(ThreadContext* ctx)
{
	int total = 1 + this->keyValue->keySize(ctx);
	total += this->keyValue->valueSize(ctx);
	return total;
}
FileStorageEntry* BTreeLeafNode::toFileStorageEntry(FileStorageEntry* entry, ThreadContext* ctx)
{
	FileStorageEntryBuilder* builder = (new(ctx) FileStorageEntryBuilder(nodeSize(ctx), ctx));
	return toFileStorageEntry(builder, entry, ctx);
}
FileStorageEntry* BTreeLeafNode::toFileStorageEntry(FileStorageEntryBuilder* builder, FileStorageEntry* entry, ThreadContext* ctx)
{
	builder->reloadBuffer(nodeSize(ctx), ctx);
	builder->putByte(IBTreeNode::BTREE_TYPE_LEAF, ctx);
	this->keyValue->appendToEntry(builder, ctx);
	return builder->toEntry(entry, this->getFilePointer(ctx), ctx);
}
IBTreeKey* BTreeLeafNode::getKey(ThreadContext* ctx) throw() 
{
	return this->keyValue->getKey(ctx);
}
ArrayList<IBTreeValue>* BTreeLeafNode::getValues(ThreadContext* ctx) throw() 
{
	return this->keyValue->getValues(ctx)->getValues(ctx);
}
bool BTreeLeafNode::isHasLeaf(ThreadContext* ctx) throw() 
{
	return false;
}
bool BTreeLeafNode::isFull(ThreadContext* ctx) throw() 
{
	return true;
}
IBTreeNode* BTreeLeafNode::addLeafNode(IBTreeNode* newNode, ThreadContext* ctx)
{
	throw (new(ctx) BTreeException(ConstStr::getCNST_STR_1050(), ctx));
}
IBTreeNode* BTreeLeafNode::getNodeAtInsertPosition(IBTreeKey* key, ThreadContext* ctx)
{
	throw (new(ctx) BTreeException(ConstStr::getCNST_STR_1050(), ctx));
}
void BTreeLeafNode::setNodeUsed(int nodeUsed, ThreadContext* ctx)
{
	throw (new(ctx) BTreeException(ConstStr::getCNST_STR_1050(), ctx));
}
IBTreeNode* BTreeLeafNode::split(IBTreeNode* newNode, BTreeNodeLoader* loader, ThreadContext* ctx) throw() 
{
	return nullptr;
}
void BTreeLeafNode::addNode(IBTreeNode* newNode, ThreadContext* ctx)
{
	throw (new(ctx) BTreeException(ConstStr::getCNST_STR_1050(), ctx));
}
INodeIterator* BTreeLeafNode::iterator(bool endStart, ThreadContext* ctx)
{
	throw (new(ctx) BTreeException(ConstStr::getCNST_STR_1050(), ctx));
}
void BTreeLeafNode::loadChildren(ThreadContext* ctx)
{
}
char BTreeLeafNode::getNodeType(ThreadContext* ctx) throw() 
{
	return IBTreeNode::BTREE_TYPE_LEAF;
}
void BTreeLeafNode::printNode(StringBuffer* buff, int level, ThreadContext* ctx) throw() 
{
	printTab(buff, level, ctx);
	printTab(buff, level, ctx);
	buff->append(ConstStr::getCNST_STR_1662(), ctx)->append(getKey(ctx)->toString(ctx), ctx)->append(ConstStr::getCNST_STR_1663(), ctx);
}
bool BTreeLeafNode::removeChild(IBTreeKey* key, ThreadContext* ctx)
{
	throw (new(ctx) BTreeException(ConstStr::getCNST_STR_1050(), ctx));
}
bool BTreeLeafNode::isEmpty(ThreadContext* ctx) throw() 
{
	return false;
}
void BTreeLeafNode::setKey(IBTreeKey* key, ThreadContext* ctx) throw() 
{
	this->keyValue->setKey(key, ctx);
}
bool BTreeLeafNode::hasMaxNode(ThreadContext* ctx) throw() 
{
	return false;
}
void BTreeLeafNode::unloadChildren(ThreadContext* ctx)
{
}
BTreeLeafNode* BTreeLeafNode::fromFetcher(FileStorageEntryFetcher* fetcher, LockObject* sync, BTreeNodeLoader* loader, FifoElement<IBTreeNode>* fifoElement, ThreadContext* ctx)
{
	KeyValue* kv = KeyValue::fromFetcher(fetcher, ctx);
	BTreeLeafNode* node = (new(ctx) BTreeLeafNode(kv, sync, loader, fifoElement, ctx));
	return node;
}
void BTreeLeafNode::__cleanUp(ThreadContext* ctx){
}
}}

