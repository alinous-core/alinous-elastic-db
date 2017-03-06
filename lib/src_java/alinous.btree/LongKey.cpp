#include "include/global.h"


#include "alinous.buffer/FifoElement.h"
#include "alinous.buffer.storage/FileStorageEntry.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.lock/LockObject.h"
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





constexpr const int LongKey::BASE_SIZE;
bool LongKey::__init_done = __init_static_variables();
bool LongKey::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"LongKey", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 LongKey::LongKey(long long v, ThreadContext* ctx) throw()  : IObject(ctx), IBTreeKey(ctx), value(0)
{
	this->value = v;
}
void LongKey::__construct_impl(long long v, ThreadContext* ctx) throw() 
{
	this->value = v;
}
 LongKey::~LongKey() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void LongKey::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"LongKey", L"~LongKey");
	if(!prepare){
		return;
	}
}
void LongKey::appendToEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx) throw() 
{
	builder->putInt(IBTreeKey::TYPE_LONG, ctx);
	builder->putLong(value, ctx);
}
int LongKey::size(ThreadContext* ctx) throw() 
{
	return IBTreeKey::TYPE_SIZE + BASE_SIZE;
}
int LongKey::compareTo(IBTreeKey* another, ThreadContext* ctx) throw() 
{
	long long diff = (static_cast<LongKey*>(this))->value - (static_cast<LongKey*>(another))->value;
	if(diff == (long long)0)
	{
		return 0;
	}
		else 
	{
		return diff > (long long)0 ? 1 : -1;
	}
}
bool LongKey::equals(IObject* obj, ThreadContext* ctx) throw() 
{
	return this->value == (dynamic_cast<LongKey*>(obj))->value;
}
bool LongKey::equals(LongKey* obj, ThreadContext* ctx) throw() 
{
	return this->value == obj->value;
}
String* LongKey::toString(ThreadContext* ctx) throw() 
{
	return Long::toString(value, ctx);
}
void LongKey::__cleanUp(ThreadContext* ctx){
}
int LongKey::ValueCompare::operator() (IBTreeKey* _this, IBTreeKey* another, ThreadContext* ctx) const throw()
{
	return _this->compareTo(another, ctx);
}
}}

