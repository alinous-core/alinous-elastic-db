#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntry.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "java.lang/Comparable.h"
#include "alinous.btree/IBTreeKey.h"
#include "alinous.btree.scan/INodeIterator.h"
#include "alinous.btree/BTreeNodeLoader.h"
#include "alinous.btree/IBTreeNode.h"
#include "alinous.btreememory.scan/MemoryNodeIterator.h"
#include "alinous.btreememory/AbstractMemoryNode.h"
#include "alinous.btreememory/AbstractMemoryBTreeNode.h"
#include "alinous.btreememory/MBTreeNode.h"
#include "alinous.btreememory/MBTreeMaxNode.h"
#include "alinous.btreememory.scan/MemoryMaxNodeIterator.h"
#include "alinous.btree/IBTree.h"
#include "alinous.btreememory/BTreeOnMemory.h"
#include "alinous.btreememory.scan/MemoryBTreeScanner.h"
#include "alinous.btreememory/AbstractMemoryBTreeLeafContainer.h"
#include "alinous.btreememory.scan/MemoryLeafContainerIterator.h"

namespace alinous {namespace btreememory {namespace scan {





bool MemoryLeafContainerIterator::__init_done = __init_static_variables();
bool MemoryLeafContainerIterator::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"MemoryLeafContainerIterator", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 MemoryLeafContainerIterator::MemoryLeafContainerIterator(bool endStart, AbstractMemoryBTreeLeafContainer* container, ThreadContext* ctx) throw()  : IObject(ctx), INodeIterator(ctx), current(0), length(0), container(nullptr)
{
	__GC_MV(this, &(this->container), container, AbstractMemoryBTreeLeafContainer);
	current = !endStart ? 0 : container->getNodeUsed(ctx) - 1;
	this->length = container->getNodeUsed(ctx);
}
void MemoryLeafContainerIterator::__construct_impl(bool endStart, AbstractMemoryBTreeLeafContainer* container, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->container), container, AbstractMemoryBTreeLeafContainer);
	current = !endStart ? 0 : container->getNodeUsed(ctx) - 1;
	this->length = container->getNodeUsed(ctx);
}
 MemoryLeafContainerIterator::~MemoryLeafContainerIterator() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void MemoryLeafContainerIterator::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"MemoryLeafContainerIterator", L"~MemoryLeafContainerIterator");
	__e_obj1.add(this->container, this);
	container = nullptr;
	if(!prepare){
		return;
	}
}
void MemoryLeafContainerIterator::gotoNode(IBTreeKey* key, ThreadContext* ctx)
{
	this->current = this->container->getNodeAtInsertPositionNumber(key, ctx);
}
void MemoryLeafContainerIterator::incCurrent(ThreadContext* ctx) throw() 
{
	this->current ++ ;
}
bool MemoryLeafContainerIterator::hasNext(ThreadContext* ctx) throw() 
{
	return this->current >= 0 && length != current;
}
IBTreeNode* MemoryLeafContainerIterator::next(ThreadContext* ctx) throw() 
{
	return this->container->getNodeAt(this->current++, ctx);
}
bool MemoryLeafContainerIterator::isLeafContainer(ThreadContext* ctx) throw() 
{
	return true;
}
void MemoryLeafContainerIterator::dispose(ThreadContext* ctx)
{
}
int MemoryLeafContainerIterator::getType(ThreadContext* ctx) throw() 
{
	return INodeIterator::IT_LEAF_CONTAINER;
}
void MemoryLeafContainerIterator::__cleanUp(ThreadContext* ctx){
}
}}}

