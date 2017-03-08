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





const DoubleValue::ValueFetcher DoubleValue:: __fetcher = (DoubleValue::ValueFetcher(nullptr));
bool DoubleValue::__init_done = __init_static_variables();
bool DoubleValue::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DoubleValue", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 DoubleValue::DoubleValue(double v, ThreadContext* ctx) throw()  : IObject(ctx), IBTreeValue(ctx), value(0)
{
	this->value = v;
}
void DoubleValue::__construct_impl(double v, ThreadContext* ctx) throw() 
{
	this->value = v;
}
 DoubleValue::~DoubleValue() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void DoubleValue::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"DoubleValue", L"~DoubleValue");
	if(!prepare){
		return;
	}
}
void DoubleValue::appendToEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx) throw() 
{
	builder->putInt(IBTreeValue::TYPE_DOUBLE, ctx);
	builder->putDouble(value, ctx);
}
int DoubleValue::diskSize(ThreadContext* ctx) throw() 
{
	return IBTreeValue::TYPE_SIZE + 8;
}
double DoubleValue::getValue(ThreadContext* ctx) throw() 
{
	return value;
}
bool DoubleValue::equals(IObject* obj, ThreadContext* ctx) throw() 
{
	return this->value == (dynamic_cast<DoubleValue*>(obj))->value;
}
IValueFetcher* DoubleValue::getFetcher(ThreadContext* ctx) throw() 
{
	return DoubleValue::fetcher;
}
void DoubleValue::__cleanUp(ThreadContext* ctx){
}
}}

namespace alinous {namespace btree {





bool DoubleValue::ValueFetcher::__init_done = __init_static_variables();
bool DoubleValue::ValueFetcher::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DoubleValue::ValueFetcher", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 DoubleValue::ValueFetcher::ValueFetcher(ThreadContext* ctx) throw()  : IObject(ctx), IValueFetcher(ctx)
{
}
void DoubleValue::ValueFetcher::__construct_impl(ThreadContext* ctx) throw() 
{
}
 DoubleValue::ValueFetcher::~ValueFetcher() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void DoubleValue::ValueFetcher::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
IBTreeValue* DoubleValue::ValueFetcher::valueFromFetcher(FileStorageEntryFetcher* fetcher, ThreadContext* ctx) throw() 
{
	IBTreeValue* value = (new(ctx) DoubleValue(fetcher->fetchDouble(ctx), ctx));
	return value;
}
void DoubleValue::ValueFetcher::__cleanUp(ThreadContext* ctx){
}
}}

