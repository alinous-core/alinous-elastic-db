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





constexpr const int DoubleKey::BASE_SIZE;
bool DoubleKey::__init_done = __init_static_variables();
bool DoubleKey::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DoubleKey", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 DoubleKey::DoubleKey(double v, ThreadContext* ctx) throw()  : IObject(ctx), IBTreeKey(ctx), value(0)
{
	this->value = v;
}
void DoubleKey::__construct_impl(double v, ThreadContext* ctx) throw() 
{
	this->value = v;
}
 DoubleKey::~DoubleKey() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void DoubleKey::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"DoubleKey", L"~DoubleKey");
	if(!prepare){
		return;
	}
}
int DoubleKey::compareTo(IBTreeKey* another, ThreadContext* ctx) throw() 
{
	return ((int)((static_cast<DoubleKey*>(this))->value - (static_cast<DoubleKey*>(another))->value));
}
bool DoubleKey::equals(IObject* obj, ThreadContext* ctx) throw() 
{
	return this->value == (dynamic_cast<DoubleKey*>(obj))->value;
}
bool DoubleKey::equals(DoubleKey* obj, ThreadContext* ctx) throw() 
{
	return this->value == obj->value;
}
void DoubleKey::appendToEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx) throw() 
{
	builder->putInt(IBTreeKey::TYPE_DOUBLE, ctx);
	builder->putDouble(this->value, ctx);
}
int DoubleKey::size(ThreadContext* ctx) throw() 
{
	return IBTreeKey::TYPE_SIZE + BASE_SIZE;
}
void DoubleKey::__cleanUp(ThreadContext* ctx){
}
int DoubleKey::ValueCompare::operator() (IBTreeKey* _this, IBTreeKey* another, ThreadContext* ctx) const throw()
{
	return _this->compareTo(another, ctx);
}
}}

