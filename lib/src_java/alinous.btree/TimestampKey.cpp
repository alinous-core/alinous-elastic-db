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





constexpr const int TimestampKey::BASE_SIZE;
bool TimestampKey::__init_done = __init_static_variables();
bool TimestampKey::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"TimestampKey", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 TimestampKey::TimestampKey(long long mills, ThreadContext* ctx) throw()  : IObject(ctx), IBTreeKey(ctx), value(0)
{
	this->value = mills;
}
void TimestampKey::__construct_impl(long long mills, ThreadContext* ctx) throw() 
{
	this->value = mills;
}
 TimestampKey::~TimestampKey() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void TimestampKey::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"TimestampKey", L"~TimestampKey");
	if(!prepare){
		return;
	}
}
int TimestampKey::compareTo(IBTreeKey* another, ThreadContext* ctx) throw() 
{
	long long diff = (static_cast<TimestampKey*>(this))->value - (static_cast<TimestampKey*>(another))->value;
	if(diff == (long long)0)
	{
		return 0;
	}
		else 
	{
		return diff > (long long)0 ? 1 : -1;
	}
}
bool TimestampKey::equals(IObject* obj, ThreadContext* ctx) throw() 
{
	return this->value == (dynamic_cast<TimestampKey*>(obj))->value;
}
bool TimestampKey::equals(TimestampKey* obj, ThreadContext* ctx) throw() 
{
	return this->value == obj->value;
}
void TimestampKey::appendToEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx) throw() 
{
	builder->putInt(IBTreeKey::TYPE_TIMESTAMP, ctx);
	builder->putLong(value, ctx);
}
int TimestampKey::size(ThreadContext* ctx) throw() 
{
	return IBTreeKey::TYPE_SIZE + BASE_SIZE;
}
String* TimestampKey::toString(ThreadContext* ctx) throw() 
{
	return Long::toString(value, ctx);
}
void TimestampKey::__cleanUp(ThreadContext* ctx){
}
int TimestampKey::ValueCompare::operator() (IBTreeKey* _this, IBTreeKey* another, ThreadContext* ctx) const throw()
{
	return _this->compareTo(another, ctx);
}
}}

