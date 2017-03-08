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





bool BTreeValues::__init_done = __init_static_variables();
bool BTreeValues::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"BTreeValues", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 BTreeValues::BTreeValues(ThreadContext* ctx) throw()  : IObject(ctx), values(GCUtils<ArrayList<IBTreeValue> >::ins(this, (new(ctx) ArrayList<IBTreeValue>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
}
void BTreeValues::__construct_impl(ThreadContext* ctx) throw() 
{
}
 BTreeValues::~BTreeValues() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void BTreeValues::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"BTreeValues", L"~BTreeValues");
	__e_obj1.add(this->values, this);
	values = nullptr;
	if(!prepare){
		return;
	}
}
void BTreeValues::addValue(IBTreeValue* value, ThreadContext* ctx) throw() 
{
	this->values->add(value, ctx);
}
bool BTreeValues::contains(IBTreeValue* value, ThreadContext* ctx) throw() 
{
	ArrayList<IBTreeValue>* values = this->values;
	int maxLoop = values->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		if(values->get(i, ctx)->equals(value, ctx))
		{
			return true;
		}
	}
	return false;
}
void BTreeValues::remove(IBTreeValue* value, ThreadContext* ctx) throw() 
{
	this->values->remove(value, ctx);
}
void BTreeValues::clearValues(ThreadContext* ctx) throw() 
{
	this->values->clear(ctx);
}
IBTreeValue* BTreeValues::get(int index, ThreadContext* ctx) throw() 
{
	return this->values->get(index, ctx);
}
int BTreeValues::numValues(ThreadContext* ctx) throw() 
{
	return this->values->size(ctx);
}
int BTreeValues::size(ThreadContext* ctx)
{
	int total = 4;
	Iterator<IBTreeValue>* it = this->values->iterator(ctx);
	while(it->hasNext(ctx))
	{
		IBTreeValue* val = it->next(ctx);
		total += val->diskSize(ctx);
	}
	return total;
}
void BTreeValues::appendToEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	ArrayList<IBTreeValue>* values = this->values;
	int maxLoop = values->size(ctx);
	builder->putInt(maxLoop, ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IBTreeValue* val = values->get(i, ctx);
		val->appendToEntry(builder, ctx);
	}
}
ArrayList<IBTreeValue>* BTreeValues::getValues(ThreadContext* ctx) throw() 
{
	return values;
}
void BTreeValues::__cleanUp(ThreadContext* ctx){
}
}}

